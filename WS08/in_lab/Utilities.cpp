// Workshop 8
// Utilities.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 20/Mar/2019

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {

	/*
	Function name: mergeRaw
	Goal/purpose: comprare desc and price list, mathcing the elements that have the same product code, and merge that information in one single user-friendly list call priceList
	Intputs:
		List<Description> desc: A list that contains product codes and descriptions for those products
		List<Price> price: A list that contains product codes and prices for those products

	Output:
		List<Product> priceList: A merged list with product descriptions and prices
	*/
		
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {
					Product* product = new Product(desc[i].desc, price[j].price);
					product->validate();
					priceList += product;

					delete product;
					product = nullptr;
				}
			}
		}

		return priceList;
	}
}