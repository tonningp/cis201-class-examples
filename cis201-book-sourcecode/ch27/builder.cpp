#include <string>
#include <sstream>
#include <vector>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>

#include "item.h"

using namespace std;
using namespace xercesc;

/**
   Creates a DOM element with a given name.
   @param doc the document that creates the element
   @param name the element name
   @return an element with the given name
*/
DOMElement* create_element(DOMDocument* doc, string name)
{
   XMLCh* xname = new XMLCh[name.length() + 1];
   XMLString::transcode(name.c_str(), xname, name.length());
   DOMElement* r = doc->createElement(xname);
   delete xname;
   return r;
}

/**
   Creates a DOM element containing a text node.
   @param doc the document that creates the element
   @param name the element name
   @param text the text for the text node
   @return an element with the given name and a child that is a
   text node with the given text
*/
DOMElement* create_text_element(DOMDocument* doc,
   string name, string text)
{
   XMLCh* xtext = new XMLCh[text.length() + 1];
   XMLString::transcode(text.c_str(), xtext, text.length());
   DOMText* textNode = doc->createTextNode(xtext);
   delete xtext;

   DOMElement* r = create_element(doc, name);
   r->appendChild(textNode);

   return r;
}

/**
   Converts an floating-point value to a string, e.g., 3.14 -> "3.14".
   @param n a floating-point value
   @return the equivalent string
*/
string double_to_string(double n)
{
   ostringstream outstr;
   outstr << n;
   return outstr.str();
}

/**
   Builds a DOM element for a product.
   @param p the product
   @return a DOM element describing the product
*/
DOMElement* create_product(DOMDocument* doc, const Product& p)
{
   DOMElement* description_element = create_text_element(doc,
      "description", p.get_description());
   DOMElement* price_element = create_text_element(doc,
      "price", double_to_string(p.get_price()));

   DOMElement* product_element = create_element(doc, "product");
   product_element->appendChild(description_element);
   product_element->appendChild(price_element);

   return product_element;
}

/**
   Builds a DOM element for an item.
   @param anItem the item
   @return a DOM element describing the item
*/
DOMElement* create_item(DOMDocument* doc, const Item& anItem)
{
   DOMElement* product_element
      = create_product(doc, anItem.get_product());
   DOMElement* quantity_element = create_text_element(doc,
      "quantity", double_to_string(anItem.get_quantity()));

   DOMElement* item_element = create_element(doc, "item");
   item_element->appendChild(product_element);
   item_element->appendChild(quantity_element);

   return item_element;
}

/**
   Builds a DOM element for an array list of items.
   @param items the items
   @return a DOM element describing the items
*/
DOMElement* create_item_list(DOMDocument* doc,
   const vector<Item>& items)
{
   DOMElement* items_element = create_element(doc, "items");
   for (int i = 0; i < items.size(); i++)
   {
      DOMElement* item_element = create_item(doc, items[i]);
      items_element->appendChild(item_element);
   }
   return items_element;
}

int main()
{
   XMLPlatformUtils::Initialize();

   // Populate vector of items
   vector<Item> items;
   items.push_back(Item(Product("Toaster", 29.95), 3));
   items.push_back(Item(Product("Hair dryer", 24.95), 1));

   // Build the DOM document
   DOMImplementation* implementation
      = DOMImplementation::getImplementation();
   DOMDocument* doc = implementation->createDocument();
   doc->setStandalone(true);

   DOMElement* root = create_item_list(doc, items);
   doc->appendChild(root);

   // Print the DOM document

   DOMWriter* writer = implementation->createDOMWriter();
   writer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);
   XMLFormatTarget* out = new StdOutFormatTarget();
   writer->writeNode(out, *doc);

   writer->release();
   doc->release();

   return 0;
}
