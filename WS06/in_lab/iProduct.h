// Workshop 6
// iProduct.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 06/Mar/2019

#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include<iostream>

namespace sict {
	class iProduct {
		double price_before_tax{ 0 };
		int product_num{ 0 };

	public:
		double price() const;
		void display(std::ostream& os) const;
	};

	void operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif // !SICT_IPRODUCT_H
