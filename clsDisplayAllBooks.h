#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"
#include <iomanip>

class clsDisplayAllBooks:protected clsScreen
{
private:

	static void _PrintBooks(clsBook Book) {
		cout << " " << Book.ID() <<"     ";
		cout << "| " <<setw(25) << left << Book.Title ;
		cout << "| " << setw(20) << left << Book.Author;
		cout << "| " << setw(15) << left << Book.Genre;
		cout << "| " << setw(10) << left << Book.Status;
	
	}

public:
	static void DisplayAllBooks() {
		DrawScreen("Display Book Screen");
		vector<clsBook>vBooks = clsBook::GetBooksList();
		 
		cout << " Book ID ";
		cout << "| " << left << setw(25) << "Title";
		cout << "| " << left << setw(20) << "Autor";
		cout << "| " << left << setw(15) << "Genre";
		cout << "| " << "Availabilty\n";

		if (vBooks.size() == 0)
			cout << "\t\t\t\tNo Books Available In the System!";
		else

			for (clsBook Book : vBooks)
			{

				_PrintBooks(Book);
				cout << endl;
			}
	}
};

