// Workshop 9
// SecureData.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 27/Mar/2019

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace sict {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs) {
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		//Define a number of threads to execute the code
		const int num_threads = 8;

		//Calculating chunks of data to process (vectorization)
		int split = nbytes / num_threads;

		//Declarin the threads
		std::thread threads[num_threads];

		//Use the bind funtion to pass diferent arguments to the convert function depending on which thread we are using
		for (int i = 0; i < num_threads; i++) {
			threads[i] = std::thread( std::bind(converter, text + i*split, key, i + 1 < num_threads ? split : (nbytes - i * split), Cryptor()) );
		}

		//Wait for all the threads to finish
		for (int i = 0; i < num_threads; i++) {
			threads[i].join();
		}

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else{
			//Opening file for writing in binary mode
			std::ofstream f(file, std::ios::binary);

			//Write data storage in memory to file
			f.write(text, nbytes);
			f.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		//Opening binary file for reading
		std::ifstream f(file, std::ios::binary);
		if (!f) {
			throw std::string("\n***Failed to open file ") + std::string(file) + std::string(" ***\n");
		}


		//Allocating memory here for the file content
		nbytes = 0;
		f >> std::noskipws;
		while (f.good()) {
			char c;
			f >> c;
			nbytes++;
		}
		nbytes--;
		f.clear();
		f.seekg(0, std::ios::beg);

		text = new char[nbytes + 1];


		//Reading the content of the binary file
		int i = 0;
		while (f.good()) {
			f >> text[i++];
		}

		text[--i] = '\0';


		*ofs << "\n" << nbytes << " bytes copied from binary file "
			 << file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
