#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> class BinarySearch  {

private:

	const vector <T>& searchingSpace;
	
	void checkOrdered() const throw() {

		for (int i = 1; i < searchingSpace.size(); ++i) {
			if (searchingSpace[i - 1] > searchingSpace[i])throw exception("The array must be sorted in asccending order");
		}

	}

	bool __bsSearch(int startIndex, int endIndex, const T& value) const {

		if (startIndex <= endIndex) {

			int mij = (startIndex + endIndex) >> 1;

			if (searchingSpace[mij] == value)return true;

			return value < searchingSpace[mij] ? __bsSearch(startIndex, mij - 1, value) : __bsSearch(mij + 1, endIndex, value);

		}

		
		return false;

	}

public:

	explicit BinarySearch(const vector<T>&searchingSpace) :searchingSpace{ searchingSpace } {
		checkOrdered();
	}

	bool operator () (const T& searchedValue) const {

		return __bsSearch(0, searchingSpace.size() - 1, searchedValue);
		
	}

};

int main(){

	vector<int> v{ 1,2,3,4,56};

	BinarySearch<int>bs {v};

	cout << boolalpha << bs(3) << '\n';;

    return 0;
}
