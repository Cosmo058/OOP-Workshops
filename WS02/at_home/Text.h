// Workshop 2
// Text.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include<iostream>
#include<fstream>
#include<string>

namespace sict {
	class Text {
		std::string* str;
		size_t total_strings;

	public:
		Text();
		Text(std::string);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};
}

#endif // !SICT_TEXT_H
