// Workshop 7
// DataTable.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 13/Mar/2019

#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>

extern int FW;


namespace sict {
	template< typename T>
	class DataTable {
		struct Coordinates{
			T x{ 0 };
			T y{ 0 };
		};
		std::vector<Coordinates> points;

	public:
		DataTable(std::ifstream& file) {
			Coordinates tmp;
			while (file) {
				file >> tmp.x >> tmp.y;
				points.push_back(tmp);
			}
		}

		void displayData(std::ostream& os) const {
			for (auto i : points) {
				os << i.x << " " << i.y <<std::endl;
			}
		}

		void displayStatistics(std::ostream& os) const {

		}
	};
}

#endif // !SICT_DATATABLE_H
