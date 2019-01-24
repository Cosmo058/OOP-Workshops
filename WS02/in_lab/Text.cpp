// Workshop 2
// Text.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#include "Text.h"

namespace sict {
	Text::Text() {
		str = nullptr;
		total_strings = 0;
	}

	Text::Text(std::string s) {
		str = nullptr;
		total_strings = 0;

		if (!s.empty()) {
			std::ifstream file(s);
			std::string s_tmp1, s_tmp2;
			int num_records_file = 0;
			int index = 0;

			while (getline(file, s_tmp1)) {
				num_records_file++;
			}

			total_strings = num_records_file;

			str = new std::string[num_records_file];

			while (getline(file, s_tmp2)) {
				str[index] = s_tmp2;
				index++;
			}
		}
	}

	Text::Text(const Text& src) {
		*this = src;
	}

	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			total_strings = src.total_strings;
			delete[] str;
			str = new std::string[total_strings];
			for (size_t i = 0; i < total_strings; i++) {
				str[i] = src.str[i];
			}
		}

		return *this;
	}

	Text::~Text() {
		delete[] str;
		str = nullptr;
	}

	size_t Text::size() const {
		return total_strings;
	}
}