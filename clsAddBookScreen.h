#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsBook.h"

using namespace std;
class clsAddBookScreen:clsScreen
{

private:
	
	static void _ReadBookInfo(clsBook& Book) {
		cout << "Enter Book Title: ";
		Book.Title = clsInputValidation::ReadString();
		cout << "Enter Book Author: ";
		Book.Author = clsInputValidation::ReadString();
		cout << "Enter Book Genre: ";
		Book.Genre = clsInputValidation::ReadString();

	}
public:
	static void AddBook() {
		DrawScreen("Add Book Screen");
		cout << "Enter Book ID: ";
		short ID=clsInputValidation::ReadNumber("Echec Try Again");
		while (clsBook::IsBookExist(ID))
		{
			cout << "\nThis ID already Exsits ,Enter Book ID: ";
			 ID = clsInputValidation::ReadNumber("Echec Try Again");
		}
		clsBook Book(ID, "", "", "");
		_ReadBookInfo(Book);
		clsBook::AddNewBook(Book);
		cout << "\nBook added successfully!";
	}
};

