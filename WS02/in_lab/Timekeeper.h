// Workshop 2
// Timekeeper.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <iomanip>
#include <chrono>

namespace sict {
	const int MAX_RECORDS = 10;

	class Timekeeper {
		int records_stored { 0 };
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point stop_time;
		struct{
			const char* message;
			const char* units;
			std::chrono::steady_clock::duration duration;
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