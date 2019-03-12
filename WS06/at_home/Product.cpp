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
		char tax;

		file >> num >> price;
		tax = file.get();

		if (tax == '\n') {
			ptr = new Product(num, price);
		}else {
			file >> tax;
			ptr = new TaxableProduct(num, price, tax);
		}

		return ptr;
	}

	TaxableProduct::TaxableProduct(int pn, double pbt, char t) : Product(pn, pbt) {
		tax = t;
	}

	double TaxableProduct::price() const {
		if (tax == 'H') {
			return Product::price() * (1 + taxRate[taxList::HST]);
		}
		else if (tax == 'P') {
			return Product::price() * (1 + taxRate[taxList::PST]);
		}
		else {
			return Product::price();
		}
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		if (tax == 'H') {
			os << " HST"; 
		}
		if(tax == 'P') {
			os << " PST";
		}
	}
}