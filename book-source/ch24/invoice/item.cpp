#include "item.h"

double Item::get_total_price() const
{
   return get_quantity() * get_unit_price();
}

Item::~Item() {}
