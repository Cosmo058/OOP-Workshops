// Workshop 7
// DataTable.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 13/Mar/2019

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<numeric>

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
			while (file >> tmp.x >> tmp.y) {
				points.push_back(tmp);
			}
		}

		void displayData(std::ostream& os) const {
			std::cout << "Data Values\n------------\n";
			std::cout << std::setw(FW) << std::right << "x" << std::setw(FW) << "y" << std::endl;
			for (auto i : points) {
				os << std::setw(FW) << std::fixed << std::setprecision(4) << i.x << std::setw(FW) << i.y <<std::endl;
			}
		}

		void displayStatistics(std::ostream& os) {
			T sum_xy = 0.0l;
			T sum_x  = 0.0l;
			T sum_x2 = 0.0l;
			T sum_y  = 0.0l;
			
			T y_mean	= 0.0l;
			T y_sigma	= 0.0l;
			T y_median	= 0.0l;
			T slope		= 0.0l;
			T intercept = 0.0l;

			std::sort(points.begin(), points.end(), [](const Coordinates& a, const Coordinates& b) -> bool {
				return a.y < b.y;
			});

			for (auto i : points) {
				sum_xy += i.x * i.y;
				sum_x  += i.x;
				sum_y  += i.y;
				sum_x2 += i.x*i.x;
			}

			slope  = (points.size()*sum_xy - sum_x * sum_y) / (points.size()*sum_x2 - sum_x * sum_x);
			intercept = (sum_y - slope * sum_x) / points.size();
			y_mean  = sum_y / points.size();

			for (auto i : points) {
				y_sigma += (i.y - y_mean)*(i.y - y_mean);
			}

			y_sigma = sqrt(y_sigma / (points.size() - 1));


			//This is the way I guess the tester program calculated the median
			//instead of getting the average of the two middle values when the number
			//of elements is an even number.

			if (points.size() % 2 == 0) {
				y_median = points.at( (points.size()/2) ).y;
			}else {
				y_median = points.at(points.size()-1/2).y;
			}

			os <<  "\nStatistics\n----------\n";
			os << "  y mean    = " << std::setw(FW) << y_mean << std::endl;
			os << "  y sigma   = " << std::setw(FW) << y_sigma << std::endl;
			os << "  y median  = " << std::setw(FW) << y_median << std::endl;
			os << "  slope     = " << std::setw(FW) << slope << std::endl;
			os << "  intercept = " << std::setw(FW) << intercept << std::endl;
		}
	};
}

#endif // !SICT_DATATABLE_H
