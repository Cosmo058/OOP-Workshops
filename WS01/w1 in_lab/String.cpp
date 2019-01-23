#include <iostream>
#include <cstring>
#include "String.h"


namespace sict {
	String::String(const char* string_recived) {
		if (string_recived != nullptr) {
			strncpy(strng, string_recived, MAX);
			strng[MAX] = '\n';
		}else {
			strng[0] = '\n';
		}
	}

	void String::display(std::ostream& out) {
		out << strng;
		out << "deb";
	}

	std::ostream& operator<<(std::ostream& out, String s){
		static int counter = MAX;
		out << counter << ": ";
		s.display(out);
		counter++;
		return out;
	}
}
