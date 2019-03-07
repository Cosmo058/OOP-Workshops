#include "Sale.h"
#include<vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Product.h"

namespace sict {
	Sale::Sale(const char* file_name) {
		std::ifstream in_file;
		std::vector<iProduct> records;

		in_file.open(file_name);
		
		if (!in_file.is_open) {
			throw "Error opening the file";
		}
		else {
			records.push_back();
		}
	}
}