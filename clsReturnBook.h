#pragma once
#include<iostream>
#include<iomanip>
#include"clsBook.h"
#include"clsMember.h"
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsTranscation.h"
class clsReturnBook:clsScreen
{


public:
	static void ReturnBook() {
		DrawScreen("Return Book Screen");
		cout << "Enter Book ID: ";
		short BookID = clsInputValidation::ReadNumber("Echec Try Again");
		while (!clsBook::IsBookExist(BookID))
		{
			cout << "\nThis ID not Exsits ,Enter Book ID: ";
			BookID = clsInputValidation::ReadNumber("Echec Try Again");
		}
		clsBook Book = clsBook::Find(BookID);
		clsTranscation Transcation = clsTranscation::Find(BookID);
		string ReturnDate = clsDate::DateToString(clsDate());
		if (Transcation.ReturnDate == " ") {
			clsTranscation::ReturnBook(Transcation, ReturnDate);
				clsBook::UpdateIssueBook(Book);
					clsMember::UpdateBookForMember(Transcation.MemberID(), BookID);
				cout << Book.Title << " Returned Succeffuly ..";
		}
		else {
			cout << "\nAlready returend...";
		}
		
	}
};

