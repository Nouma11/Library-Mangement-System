#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBook.h"
#include <iomanip>
class clsFindbookScreen:protected clsScreen
{
private:
	static void _PrintBooks(clsBook Book) {
		cout << "\n Book ID       : " << Book.ID();
		cout << "\n Book title    : " << Book.Title;
		cout << "\n Book Author   : " << Book.Author;
		cout << "\n Genre         : " << Book.Genre;
		cout << "\n Availability  : "<< Book.Status;
		cout << "\n";

	}
public:
	static void FindBook() {
		DrawScreen("Find Book Screen");
		cout << "Enter Book ID: ";
		short BookID = clsInputValidation::ReadNumber("Echec Try Again");
		while (!clsBook::IsBookExist(BookID))
		{
			cout << "\nThis ID not Exsits ,Enter Book ID: ";
			BookID = clsInputValidation::ReadNumber("Echec Try Again");
		}
		clsBook Book = clsBook::Find(BookID);
		system("cls");
		DrawScreen("Find Book Screen");
		_PrintBooks(Book);
	}
};

