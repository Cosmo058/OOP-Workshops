#include "Sale.h"
#include<vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

#include "Product.h"
extern int FW;

namespace sict {
	Sale::Sale(const char* file_name) {
		std::ifstream in_file(file_name);
		iProduct *p;
		
		if (!in_file) {
			throw "Error opening the file";
		}
		else {
			while (in_file) {
				p = readRecord(in_file);

				if (in_file) {
					products.push_back(p);
				}
			}
		}
	}

	void Sale::display(std::ostream& os) const {
		os << std::setw(FW) << std::endl;
		os << "Product No" << std::setw(FW) << "Cost" << std::endl;
		double total = 0;

		for (auto i : products) {
			os << *i;
			total = total + i->price();
		}
		os << std::setw(FW) << "Total" << std::fixed << std::setprecision(2) << std::setw(FW) << total << std::endl;
	}
}