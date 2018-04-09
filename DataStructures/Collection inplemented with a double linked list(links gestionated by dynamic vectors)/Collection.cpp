// proiectSDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "multiset.h"
#include <iostream>
#include <string>
#include <windows.h>
#define HOW_TO_IGNORE 255

using std::string;
using std::istream;
using std::ostream;
using std::getline;
using std::cin;
using std::exception;

struct book {

	string autor, titlu;
	int nrPagini;

	book() = default;

	book(const string& autor, const string& titlu, int nrPagini) : autor{autor},titlu{titlu},nrPagini{nrPagini}{}

	friend bool operator == (const book& __this, const book& other) {
		return __this.autor == other.autor && __this.titlu == other.titlu && __this.nrPagini == other.nrPagini;
	}

	friend ostream& operator << (ostream& out, const book & carte) {
		out << "autor: " << carte.autor << " titlu: " << carte.titlu << " pagini: " << carte.nrPagini << '\n';
		return out;
	}
};



class ui {
private:
	multiset < book > repository;

	inline void showMenu() {
		cout << "1->Adaugare carte\n2->Elimina o aparitie carte\n3->Verifica daca o carte e in biblioteca\n4->Verifica daca biblioteca a depasit nr de carti\n5->Numarul de carti cu un anumit titlu\n6->View All\n7->Exit\n";
	}

	template <typename T> T read() {
		T value;

		do {
			cin >> value;

			if (cin.fail()) {
				cin.clear(),cin.ignore(HOW_TO_IGNORE, '\n');
				cout << "Reincercati!\n";
				continue;
			}

			return value;

		} while (true);
	}

	void readOption();

	void deleteOption();

	void verifyOption();

	void getAllWithTitle();

	void moreThanOption();

	void viewAll();

public:

	void run();
		
};


int main(){
	ui u;
	u.run();
    return 0;
}








void ui::readOption() {
	book a;
	cin.get();
	cout << "Dati autorul:"; getline(cin, a.autor);
	cout << "Dati titlul:"; getline(cin, a.titlu);
	cout << "Dati nr. pagini:"; a.nrPagini = read<int>();
	repository.insert(a);
	system("cls");
}

void ui::deleteOption() {
	book a;
	cin.get();
	cout << "Dati autorul:"; getline(cin, a.autor);
	cout << "Dati titlul:"; getline(cin, a.titlu);
	cout << "Dati nr. pagini:"; a.nrPagini = read<int>();

	try {
		repository.erase(a);
		cout << "Book deleted!\n";
		Sleep(1000);
	}
	catch (exception& e) {
		cout << e.what() << '\n';
		Sleep(1000);
	}
	system("cls");
}

void ui::verifyOption() {
	book a;
	cin.get();
	cout << "Dati autorul:"; getline(cin, a.autor);
	cout << "Dati titlul:"; getline(cin, a.titlu);
	cout << "Dati nr. pagini:"; a.nrPagini = read<int>();

	cout << (repository.find(a) ? "The book is in library :))\n" : "The book is not in library:((\n");

	Sleep(1000);

	system("cls");
}
void ui::getAllWithTitle() {

	string title;

	cin.get();
	cout << "Dati titlul:"; getline(cin, title);

	int number = 0;

	for (const auto& book : repository) if (book.titlu == title)++number;


	cout << "In library are " << number << " books with title " << title << '\n';

	Sleep(1500);

	system("cls");
}

void ui::moreThanOption() {
	int number;

	cout << "Dati numarul:"; number = read <int>();

	cout << (repository.size() > number ? "Biblioteca are mai mult de " : (repository.size() == number) ? "Biblioteca are exact " : "Biblioteca are mai putin de ") << number << " carti" << '\n';


	Sleep(1500);

	system("cls");
}

void ui::viewAll() {
	for (const auto& book : repository)cout << book;
	if (!repository.empty())Sleep(2000);
	system("cls");
}

void ui::run() {
	int option;

	while (true) {
		showMenu();

		cout << "Dati optiunea:"; option = read<int>();

		switch (option) {
			case 1:readOption(); break;
			case 2:deleteOption(); break;
			case 3:verifyOption(); break;
			case 4:moreThanOption(); break;
			case 5:getAllWithTitle(); break;
			case 6:viewAll(); break;
			case 7: return;
			default:cout << "Wrong option\n"; break;
		}
	}
}
