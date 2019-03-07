// Workshop 6
// Sale.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 06/Mar/2019

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include<iostream>

namespace sict {
	class Sale {
	public:
		Sale(const char*);
		void display(std::ostream& os) const;
	};
}

#endif // !SICT_SALE_H