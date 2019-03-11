// Workshop 6
// Product.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 06/Mar/2019

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include "iProduct.h"

namespace sict {
	class Product : public iProduct {
	public:
		Product(int,double);
		double price() const;
		void display(std::ostream& os) const;
	};
}

#endif // !SICT_PRODUCT_H