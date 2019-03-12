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

	class TaxableProduct : public Product {
		enum taxList { HST, PST};
		double taxRate[2] = { 0.13, 0.08 };
		char tax;
	public:
		TaxableProduct(int, double, char);
		double price() const;
		void display(std::ostream& os) const;
		iProduct* readRecord(std::ifstream& file);
	};
}

#endif // !SICT_PRODUCT_H