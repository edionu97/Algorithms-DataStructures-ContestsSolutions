#include "stdafx.h"
#include <vector>
#include <functional>
#include <iostream>

using namespace std;


template <typename T> class QuickSorter {
private:


	function < bool(const T&, const T&) > comp;

	int sortedElement(int li, int ls,vector <T>& elements) {

		bool increase = true;

		while (li < ls) {
			if (!comp(elements[li], elements[ls])) {
				swap(elements[li], elements[ls]);
				increase = !increase;
			}

			increase ? ++li : --ls;
		}

		return li;
	}


	void quickSort(int li,int ls,vector <T>& elements) {
		if (li > ls) return; 
		
		int poz = sortedElement(li, ls, elements);
		quickSort(li, poz - 1, elements);
		quickSort(poz + 1, ls, elements);

	}


public:

	QuickSorter(function <bool(const T&, const T&)>  cmp) :comp{ cmp } {}
	
	
	void operator()(vector <T>& toSort) {
		quickSort(0, toSort.size() - 1, toSort);
	}
};


int main(){


	QuickSorter<int> sorter{ 
		[](const int& a,const int& b) {
			return  a < b;
		}
	};

	vector < int > vect{ 1,2,1,2,3,4,1,3,45,6,1,2,7,5,1,3,2,0,1 };

	
	sorter(vect);

	for (int value : vect)cout << value << ' ';

	cout << '\n';

    return 0;
}