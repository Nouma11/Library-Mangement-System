#pragma once
#include<iostream>
#include<iomanip>
#include"clsBook.h"
#include"clsMember.h"
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsTranscation.h"

class clsIssueBook:protected clsScreen
{
 
public:
	static void IssueBook() {
		DrawScreen("Issue Book Screen");
		cout << "Enter Book ID: ";
		short BookID = clsInputValidation::ReadNumber("Echec Try Again");
		while (!clsBook::IsBookExist(BookID))
		{
			cout << "\nThis ID not Exsits ,Enter Book ID: ";
			BookID = clsInputValidation::ReadNumber("Echec Try Again");
		}

		cout << "Enter Member ID: ";
		short MemberID = clsInputValidation::ReadNumber("Echec Try Again");
		while (!clsMember::IsMemberExist(MemberID))
		{
			cout << "\nThis ID not Exsits ,Enter Member ID: ";
			MemberID = clsInputValidation::ReadNumber("Echec Try Again");
		}
		short TranscactionID = (BookID + MemberID) * 2;
		clsBook Book = clsBook::Find(BookID);
		clsMember Member = clsMember::Find(MemberID);
		string IssueDate = clsDate::DateToString(clsDate());
		clsTranscation Transcation(TranscactionID, BookID, MemberID, IssueDate, " ");
		clsTranscation::AddTranscaction(Transcation);
		if (Member.BookID == to_string(BookID)) {
			cout << Member.Name << " Has already the Book " << Book.Title;
		}
		else {
			clsBook::UpdateIssueBook(Book);
			clsMember::UpdateBookForMember(MemberID, BookID);

			cout << "\nBook " << Book.Title << " Issued To " << Member.Name << " Succeffuly...";
		}
	}
};

