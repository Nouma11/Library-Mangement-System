#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMember.h"
#include <iomanip>

class clsDisplayAllMembers :protected clsScreen
{
private:

	static void _PrintMembers(clsMember Member) {
		cout << " " << Member.ID() << "       ";
		cout << "| " << setw(15) << left << Member.Name;
		cout << "| " << setw(25) << left << Member.ContactInfo;
		cout << "| " << setw(5) << left << Member.BookID;
		  

	}

public:
	static void DisplayAllMembers() {
		DrawScreen("Display Member Screen");
		vector<clsMember>vMembers = clsMember::GetMembersList();

		cout << " Member ID ";
		cout << "| " << left << setw(15) << "Name";
		cout << "| " << left << setw(25) << "Contact Info";
		cout << "| " << left << setw(5) << "Book ID\n";

		if (vMembers.size() == 0)
			cout << "\t\t\t\tNo Members Available In the System!";
		else

			for (clsMember Member : vMembers)
			{

				_PrintMembers(Member);
				cout << endl;
			}
	}
};

