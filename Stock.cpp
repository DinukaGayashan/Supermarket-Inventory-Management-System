#include "Stock.h"


Stock::Stock(string itm_nme, string msr_unt , string brnd_nme , string spply_type , int nmbr_itms , double rprc , int dscnt )
:item_name(itm_nme), measure_unit(msr_unt), brand_name(brnd_nme), supply_type(spply_type), number_of_items(nmbr_itms), retail_price(rprc), discount(dscnt)
{
}


void Stock::show_data()
{
	
}

