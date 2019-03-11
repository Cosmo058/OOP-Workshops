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
	protected:
		double price_before_tax{ 0 };
		int product_num{ 0 };

	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readRecord(std::ifstream&);
}

#endif // !SICT_IPRODUCT_H
