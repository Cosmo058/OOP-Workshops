// Workshop 2
// Timekeeper.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 23/Jan/2019

#include "Timekeeper.h"
 
namespace sict {
	Timekeeper::Timekeeper() {

	}

	void Timekeeper::start() {
		start_time = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		stop_time = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* msg) {
		auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop_time - start_time);

		if (records_stored < MAX_RECORDS) {
			this->record[records_stored].message = msg;
			this->record[records_stored].units = " seconds";
			this->record[records_stored].duration = elapsed_time;
			records_stored++;
		}
	}

	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:\n";
		for (int i = 0; i < records_stored; i++) {
			os  << record[i].message << ' ' << std::setw(5)
				<< record[i].duration.count() / 1000000
				<< record[i].units << std::endl;
		}
	}
}