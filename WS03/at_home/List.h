// Workshop 3
// List.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict {
	template <typename T, int N>
	class List {
		T a[N];
		size_t elements_saved {0u};

	public:
		size_t size() const {
			return elements_saved;
		}

		const T& operator[](size_t i) const {
			return a[i];
		}

		void operator+=(const T& t) {
			if (elements_saved < N) {
				a[elements_saved] = t;
				elements_saved++;
			}
		}
	};

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			SummableLVPair<L, V> temp;
			V result = temp.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
				temp = ((List<T, N>&)*this)[i];
				result = temp.sum(label, result);
			}
			return result;
		}
	};
}
#endif // !SICT_LIST_H