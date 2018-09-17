#include <string>
#include <sstream>
#include <vector>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "item.h"

using namespace std;
using namespace xercesc;

/*
  Converts a sequence of XMLCh characters to a string.
  @param in the sequence of XMLCh characters
  @return the transcoded string
*/
string XMLCh_to_string(const XMLCh* in)
{
   char* s = XMLString::transcode(in);
   string r(s);
   XMLString::release(&s);
   return r;
}

/**
   Converts a string to a floating-point value, e.g., "3.14" -> 3.14.
   @param s a string representing a floating-point value
   @return the equivalent floating-point value
*/
double string_to_double(string s)
{
   istringstream instr(s);
   double x;
   instr >> x;
   return x;
}

/**
   Converts a string to an integer, e.g., "314" -> 314.
   @param s a string representing an integer
   @return the equivalent integer
*/
int string_to_int(string s)
{
   istringstream instr(s);
   int x;
   instr >> x;
   return x;
}

/**
   Obtains a product from a DOM node.
   @param e a <product> element
   @return the product described by the given node
*/
Product get_product(DOMNode* e)
{
   DOMNodeList* children = e->getChildNodes();
   string name = "";
   double price = 0;
   for (int i = 0; i < children->getLength(); i++)
   {
      DOMNode* child_node = children->item(i);
      DOMElement* child_element
         = dynamic_cast<DOMElement*>(child_node);
      if (child_element != NULL)
      {
         string tagName = XMLCh_to_string(child_element->getTagName());
         DOMText* textNode
            = dynamic_cast<DOMText*>(child_element->getFirstChild());

         if (tagName == "description")
            name = XMLCh_to_string(textNode->getData());
         else if (tagName == "price")
         {
            string price_text = XMLCh_to_string(textNode->getData());
            price = string_to_double(price_text);
         }
      }
   }
   return Product(name, price);
}

/**
   Obtains an item from a DOM node.
   @param e an <item> element
   @return the item described by the given node
*/
Item get_item(DOMNode* e)
{
   DOMNodeList* children = e->getChildNodes();
   Product p;
   int quantity = 0;
   for (int i = 0; i < children->getLength(); i++)
   {
      DOMNode* child_node = children->item(i);
      DOMElement* child_element
         = dynamic_cast<DOMElement*>(child_node);
      if (child_element != NULL)
      {
         string tagName = XMLCh_to_string(child_element->getTagName());
         if (tagName == "product")
            p = get_product(child_element);
         else if (tagName == "quantity")
         {
            DOMText* textNode = dynamic_cast<DOMText*>(
               child_element->getFirstChild());
            string quantity_text
               = XMLCh_to_string(textNode->getData());
            quantity = string_to_int(quantity_text);
         }
      }
   }
   return Item(p, quantity);
}

/**
   Obtains an array list of items from a DOM node.
   @param e an <items> element
   @return a vector of all <item> children of e
*/
vector<Item> get_items(DOMNode* e)
{
   vector<Item> items;

   // Get the <item> children

   DOMNodeList* children = e->getChildNodes();
   for (int i = 0; i < children->getLength(); i++)
   {
      DOMNode* child_node = children->item(i);
      DOMElement* child_element
         = dynamic_cast<DOMElement*>(child_node);
      if (child_element != NULL)
      {
         string tagName = XMLCh_to_string(child_element->getTagName());
         if (tagName == "item")
         {
            Item c = get_item(child_element);
            items.push_back(c);
         }
      }
   }
   return items;
}

int main()
{
   XMLPlatformUtils::Initialize();

   DOMImplementation* implementation
      = DOMImplementation::getImplementation();
   DOMBuilder* parser = implementation->createDOMBuilder(
      DOMImplementationLS::MODE_SYNCHRONOUS, NULL);
   DOMDocument* doc = parser->parseURI("items.xml");

   DOMNode* root = doc->getDocumentElement();
   vector<Item> items = get_items(root);

   for (int i = 0; i < items.size(); i++)
      items[i].print();
   parser->release();

   return 0;
}
