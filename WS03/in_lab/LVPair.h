#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include<iostream>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L label;
		V value;
	public:
		LVPair() {
		}

		LVPair(const L& l, const V& v) {
			label = l;
			value = v;
		}

		void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif // !SICT_LVPAIR_H
