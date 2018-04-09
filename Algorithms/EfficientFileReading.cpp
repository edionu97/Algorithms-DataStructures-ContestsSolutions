// EfficientFileReading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#define NMAX 2001
#define NRMAX 2000000001
#define NCHAR 1000002

template <typename T> class InputReader {//T numeric type

private:

	FILE *in;
	char buffer[NCHAR];
	int PozInBuffer, endoffile;

	void Advance() {
		if (PozInBuffer + 1 == NCHAR) {
			PozInBuffer = -1;
			fread(buffer, 1, NCHAR, in);
			endoffile = feof(in);
		}
		++PozInBuffer;
	}

	inline bool IsFigure(char val) {
		return (val >= '0' && val <= '9');
	}

public:

	InputReader(char *p, char* type) {
		in = fopen(p, type);
		fread(buffer, 1, NCHAR, in);
		PozInBuffer = endoffile = 0;
	}

	InputReader &operator >> (T &number) {

		number = 0;
		
		while (!IsFigure(buffer[PozInBuffer]))Advance();


		while (IsFigure(buffer[PozInBuffer])) {
			number = number * 10 + buffer[PozInBuffer] - '0';
			Advance();
		}

		return *this;
	}

	bool eof() const {
		return endoffile;
	}

};


int main(){

	InputReader <long> fin{ "file_name","opening_mode" };

	long x;
	
	fin >> x;

	std::cout << x;

    return 0;
}

