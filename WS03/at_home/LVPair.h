// Workshop 3
// LVPair.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include<iostream>
#include<iomanip>
#include<string>

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L label;
		V value;

	public:
		LVPair() {}

		LVPair(const L& l, const V& v) {
			label = l;
			value = v;
		}

		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}

		const L& getLabel() const {
			return label;
		}

		const V& getValue() const {
			return value;
		}
	};

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L,V> {
		static V initial_value;
		static size_t min_width;

	public:
		SummableLVPair(){}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (min_width < label.size()) {
				min_width = label.size();
			}
		}

		const V& getInitialValue() {
			return initial_value;
		}

		V sum(const L& label, const V& sum) const {
			V result = sum;
			if (label == LVPair<L, V>::getLabel())
				result = LVPair<L, V>::getValue() + sum;
			return result;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(min_width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template <>
	int SummableLVPair<std::string, int>::initial_value = 0; 

	template<>
	std::string SummableLVPair<std::string, std::string>::initial_value = "";

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::min_width = 0;

	template<>
	SummableLVPair<std::string, std::string>::SummableLVPair(const std::string& label, const std::string& v) : LVPair<std::string, std::string>::LVPair(label, v) {
		if (min_width < label.size())
			min_width = label.size();
	}

	template<>
	SummableLVPair<std::string, int>::SummableLVPair(const std::string& label, const int& v) : LVPair<std::string, int>::LVPair(label, v) {
		if (min_width < label.size())
			min_width = label.size();
	}

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		std::string res = sum;

		if (label == LVPair<std::string, std::string>::getLabel())
			res = sum + ' ' + LVPair<std::string, std::string>::getValue();
		return res;
	}
}

#endif // !SICT_LVPAIR_H
