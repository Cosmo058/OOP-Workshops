#include<iostream>
#include<iomanip>
#include<fstream>
#include "Product.h"
extern int FW;

namespace sict {
	Product::Product(int pn, double pbt) {
		product_num = pn;
		price_before_tax = pbt;
	}

	double Product::price() const{
		return price_before_tax;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(FW) << std::right << product_num
		   << std::setw(FW) << std::fixed << std::setprecision(2) << price_before_tax;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		os << std::endl;
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* ptr = nullptr;
		int num;
		double price;

		file >> num >> price;

		ptr = new Product(num, price);

		return ptr;
	}
}