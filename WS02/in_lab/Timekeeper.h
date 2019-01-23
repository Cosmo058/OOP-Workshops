#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict {
	const int MAX_RECORDS = 10;

	class Timekeeper {
		int records_stored;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point stop_time;
		struct{
			char* msg;
			char* units;
			std::chrono::steady_clock::time_point duration;
		}record[MAX_RECORDS];

	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		void report(std::ostream&) const;
	};
}

#endif