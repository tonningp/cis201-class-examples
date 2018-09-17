#include <string>
#include <iostream>
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
   Converts a string to a floating-point value, e.g. "3.14" -> 3.14.
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
   Converts a string to an integer, e.g. "314" -> 314.
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
   Obtains a product from a DOM element.
   @param e a <product> element
   @return the product described by the given element
*/
Product get_product(DOMNode* e)
{
   DOMNodeList* children = e->getChildNodes();

   DOMText* textNode
      = dynamic_cast<DOMText*>(children->item(0)->getFirstChild());
   string name = XMLCh_to_string(textNode->getData());

   textNode
      = dynamic_cast<DOMText*>(children->item(1)->getFirstChild());
   string price_text = XMLCh_to_string(textNode->getData());
   double price = string_to_double(price_text);

   return Product(name, price);
}

/**
   Obtains an item from a DOM element.
   @param e an <item> element
   @return the item described by the given element
*/
Item get_item(DOMNode* e)
{
   DOMNodeList* children = e->getChildNodes();
   Product p = get_product(children->item(0));

   DOMText* textNode = dynamic_cast<DOMText*>(
      children->item(1)->getFirstChild());
   string quantity_text = XMLCh_to_string(textNode->getData());
   int quantity = string_to_int(quantity_text);

   return Item(p, quantity);
}

/**
   Obtains an array list of items from a DOM element.
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
      Item c = get_item(children->item(i));
      items.push_back(c);
   }
   return items;
}

class SimpleErrorHandler : public DOMErrorHandler
{
public:
   bool handleError(const DOMError& error);
};

bool SimpleErrorHandler::handleError(const DOMError& error)
{
   cout << XMLCh_to_string(error.getLocation()->getURI())
      << ", line " << error.getLocation()->getLineNumber()
      << ", char " << error.getLocation()->getColumnNumber()
      << ": " << XMLCh_to_string(error.getMessage()) << "\n";
   return error.getSeverity() != DOMError::DOM_SEVERITY_FATAL_ERROR;
}

int main()
{
   XMLPlatformUtils::Initialize();

   DOMImplementation* implementation
      = DOMImplementation::getImplementation();
   DOMBuilder* parser = implementation->createDOMBuilder(
      DOMImplementationLS::MODE_SYNCHRONOUS, NULL);
   DOMErrorHandler* handler = new SimpleErrorHandler();
   parser->setErrorHandler(handler);
   parser->setFeature(XMLUni::fgDOMValidation, true);
   parser->setFeature(XMLUni::fgDOMWhitespaceInElementContent, false);
   DOMDocument* doc = parser->parseURI("items2.xml");
   DOMNode* root = doc->getDocumentElement();
   vector<Item> items = get_items(root);

   for (int i = 0; i < items.size(); i++)
      items[i].print();

   parser->release();
   delete handler;

   return 0;
}
