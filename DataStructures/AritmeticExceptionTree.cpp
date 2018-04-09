// Calculator lab 2 oop variant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <memory>

#define NMAX 102

using namespace std;

/*	
	expresion should not have spaces between number or any characher excepting +-/^*() and numbers figures [0-9] and numbers of course
*/

class File_Not_Found_Error : public exception {
private:
	string message;
public:
	explicit File_Not_Found_Error(const string &mesage) : message{ mesage } {}
	const char *what() const {
		return message.data();
	}
};

namespace Expresion {

	char buffer[NMAX];

	void ReadVector() {
		FILE *fin = fopen("val.in", "r");
		if (!fin)throw File_Not_Found_Error("File val.in do not exist\n");
		fgets(buffer, NMAX - 1, fin); 
		cout << "Exception processed :"; cout << buffer << '\n';
		fclose(fin);
	}

	vector < pair <char, int> >Operator;

	vector <int>Number;

	inline void Process(const char &val, int &increase) {
		switch (val) {
			case '(':increase += 3; break;
			case ')':increase -= 3; break;
			case '+':Operator.push_back({ val, 0 + increase }); break;
			case '-':Operator.push_back({ val, 0 + increase }); break;
			case '*':Operator.push_back({ val, 1 + increase }); break;
			case '/':Operator.push_back({ val, 1 + increase }); break;
			case '^':Operator.push_back({ val, 2 + increase }); break;
		}
	}

	inline void ProcessPtr(const char *p) {
		Number.push_back(atoi(p));
	}

	void GetNumbers() {
		char *__p = strtok(buffer, "^/*-+()");
		while (__p) {
			ProcessPtr(__p);
			__p = strtok(NULL, "^/*-+()");
		}
	}

	void ParseString() {
		int dim = strlen(buffer), increase = 0;
		for (auto index = 0; index < dim - 1; ++index)
			if (!(buffer[index] >= '0' && buffer[index] <= '9'))Process(buffer[index], increase);
		GetNumbers();
	}
};


using namespace Expresion;

class ExpTree {
private:

	struct __tree {

		pair <char, int>op;
		int Number;
		unique_ptr <__tree>st, dr;

		__tree() {
			op.first = op.second = 0;
			Number = -1;
		}

	};

	unique_ptr < __tree > root;
	int index1, index2;

	void __makeNode(unique_ptr < __tree > &root) {
		//make a node for ExpArb(the leaf is the number and dad is the operator (+-)
		root->op = Operator[index1++];
		root->st = make_unique<__tree>();
		root->st->Number = Number[index2++];
	}

	void __insert(unique_ptr <__tree > &root) {
		
		if (index1 < Operator.size() && root->op.second < Operator[index1].second) {
			root->dr = make_unique <__tree>();
			__makeNode(root->dr);
			__insert(root->dr);
		}else {
				root->dr = make_unique<__tree>();
				root->dr->Number = Number[index2++];
		};

		if (index1 < Operator.size() && root->op.second < Operator[index1].second) {
			auto q = move(root->dr);
			root->dr = make_unique<__tree>();
			root->dr->op = Operator[index1++];
			root->dr->st = move(q);
			__insert(root->dr);
		}
	}

	void __srd(__tree * p) {
		if (p) {
			__srd(p->st.get());
			if (p->Number == -1)cout << p->op.first << ' ';
			else
				cout << p->Number << ' ';
			__srd(p->dr.get());
		}
	}

	void __caluculateExp(__tree *p, double &elm) {

		if (!p)return;

		if (p->Number >= 0) {
			elm = p->Number;
			return;
		}

		double  st, dr;

		__caluculateExp(p->st.get(),st);
		__caluculateExp(p->dr.get(), dr);

		switch (p->op.first) {
			case '+':elm = st + dr; break;
			case '-':elm = st - dr; break;
			case '*':elm = st * dr; break;
			case '/':elm = st / dr; break;
			case '^':elm = pow(st,dr); break;
		}	
}

public:

	ExpTree() {
		index1 = index2 = 0;
		root = make_unique <__tree>();
	}

	void InsertTree() {

		__makeNode(root);
		__insert(root);

		while (index1 < Operator.size()) {

			///there are two situations :the first one is when the new operation has a lower or equal priority than the root,and the second when the new op has the same priority that the right node 
	
			if (Operator[index1].second <= root->op.second) {
				auto q = make_unique<__tree>();
				q->op = Operator[index1++];
				q->st = move(root);
				root = move(q);
				__insert(root);
				continue;
			}
			
			auto q = make_unique<__tree>();
			q->op = Operator[index1++];
			q->st = move(root->dr);
			root->dr = move(q);
			__insert(root->dr);
			
		}
	}

	inline void SRD() {
		__srd(root.get());
	}

	inline double GetResult(){
		double Rez;
		__caluculateExp(root.get(), Rez);
		return Rez;
	}
};


int main(){
	try {
		Expresion::ReadVector();
		Expresion::ParseString();
		Expresion::GetNumbers();

		ExpTree Tr;
		Tr.InsertTree();

		cout << "Rezultatul expresiei este:";
		cout << fixed << setprecision(6) << Tr.GetResult() << '\n';
	}
	catch (exception &e) {
		cout << e.what() << '\n';
	}
    return 0;
}

