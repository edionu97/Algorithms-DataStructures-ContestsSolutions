// Tuplu(convrntional types).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;


class Index_Out_Of_Range_Exception : public exception {
private:
	string __mesage;
public:
	explicit Index_Out_Of_Range_Exception(const string &msg):__mesage(msg){}
	const char * what() const  {
		return __mesage.data();
	}
};

class PythonList {///elementary types
private:

	struct __node {
		void *info;
		__node *next;
	};


	__node *startPoint,*aux,*head;
	int size;

	template <typename T>void Add(const T val) {
		aux = (__node*)malloc(sizeof(__node));
		aux->info = (T*)malloc(sizeof(void*));
		*(T*)aux->info = val;
		++size;
		if (size == 1) {
			head = startPoint = aux;
			head->next = nullptr;
			return;
		}
		aux->next = nullptr;
		startPoint->next = aux;
		startPoint = aux;
	}

	template <> void Add(char const *val) {//specialization when type is char const *
		aux = (__node*)malloc(sizeof(__node));
		aux->info = (char*)malloc(sizeof(void*));
		strcpy((char *)aux->info,val);
		++size;
		if (size == 1) {
			head = startPoint = aux;
			head->next = nullptr;
			return;
		}
		aux->next = nullptr;
		startPoint->next = aux;
		startPoint = aux;

	}

	vector <int> Types;

	template <typename T> T DaValoare(__node *p) {
		return *(T*)p->info;
	}

	template <> char const * DaValoare(__node *p) {
		return (char*)p->info;
	}

     void Parcurge(__node *head) {

		for (auto val : Types) {

			switch (val) {
				case 1:cout << DaValoare<char>(head); break;
				case 0:cout << DaValoare<int>(head); break;
				case 2:cout << DaValoare<double>(head); break;
				case 3:cout << DaValoare<long long>(head); break;
				case 4:cout << DaValoare<const char *>(head); break;
				case 5:cout << DaValoare<float>(head); break;
			}

			cout << '\n';
			head = head->next;
		}
	}

public:

	explicit PythonList() {
		startPoint = (__node*)malloc(sizeof(__node));
		size = 0;
	}

	inline void Adauga(const int &val) {
		Add <int>(val);
		Types.push_back(0);
	}

	inline void Adauga(const char &val) {
		Add <char>(val);
		Types.push_back(1);
	}
	
	inline void Adauga(const double &val) {
		Add <double>(val);
		Types.push_back(2);
	}

	inline void Adauga(const long long&val) {
		Add <long long>(val);
		Types.push_back(3);
	}

	inline void Adauga(const string &val) {
		Add < char const *>(val.data());
		Types.push_back(4);
	}

	inline void Adauga(const float &val) {
		Add <float>(val);
		Types.push_back(5);
	}

	inline void Afiseaza() {
		Parcurge(head);
	}

	template <typename T = int> inline T element(const int &i) {//if you do not specify the template parametre then I supose that it's int
		int poz = 1;
		__node *__head = head;
		if (i > size)throw Index_Out_Of_Range_Exception("Out of range !!!!");
		while (poz != i)__head = __head->next, ++poz;
		return *(T*)__head->info;
	}

	template <> inline string element(const int &i) {
		int poz = 1;
		__node *__head = head;
		if (i > size)throw Index_Out_Of_Range_Exception("Out of range !!!!");
		while (poz != i)__head = __head->next, ++poz;
		return string((char*)__head->info);
	}

	int Size() {
		return size;
	}
};

int main(){
	
	PythonList P;

	int a = 10;

	P.Adauga(10);

	double b = 13.04;

	P.Adauga(b);

	char c = 'c';

	P.Adauga(c);

	string s("ana"s);
	P.Adauga(s);

	float d = 154.55;
	P.Adauga(d);

	long long e = 1541545454545 ;
	P.Adauga(e);

	for (int i = 1; i <= 10; ++i)P.Adauga(i);

	cout << P.element(1) << '\n' << P.element<double>(2) << '\n' << P.element<char>(3) << '\n' << P.element <string>(4) << '\n' << P.element<float>(5) << '\n' << P.element <long long>(6)<<'\n';
	
	for (int i = 7; i <= P.Size(); ++i)cout << P.element(i) << '\n';

    return 0;
}

