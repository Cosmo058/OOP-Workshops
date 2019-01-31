#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict {
	template <typename T, int N>
	class List {
		T a[N];
		size_t elements_saved = 0;

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
}
#endif // !SICT_LIST_H
