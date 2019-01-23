#ifndef SICT_STRING_H
#define SICT_STRING_H

#include <iostream>

namespace sict {
	const int MAX = 3;

	class String {
		char strng[MAX+1];

	public:
		String(const char*);
		void display(std::ostream&);
	};

	std::ostream& operator<<(std::ostream&, String);
}

#endif // !SICT_STRING_H
