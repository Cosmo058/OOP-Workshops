#include <iostream>
#include "String.h"
#include "process.h"

using namespace std;

int INITIAL = 3;

int main(int argc, char *argv[]) {
	cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i];
		cout << " ";
	}
	cout << endl;

	if (argc <= 1) {
		cout << "***Insufficient number of arguments***";
		return 1;
	}else {
		for (int i = 1; i < argc; i++) {
			sict::process(argv[i]);
		}
	}
	
	return 0;
}
