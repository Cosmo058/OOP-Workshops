#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include<iostream>

namespace sict {
	template <typename L, typename V>
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

		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L,V> {
		V initial_value;
		size_t min_width = 0;

		SummableLVPair(){
			initial_value {};
			size_t {};
		}

		SummableLVPair(const L& label, const V& v):LVPair(label,v) {
			if (min_width < label.size()) {
				min_width = label.size();
			}
		}

		const V& getInitialValue() {
			return initial_value;
		}

		V append(const L& label, const V& value) const {

		}
	};
}

#endif // !SICT_LVPAIR_H
