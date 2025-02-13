#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsMember.h"

using namespace std;
class clsAddMemberScreen :clsScreen
{

private:

	static void _ReadBookInfo(clsMember& Member) {
		cout << "Enter Member Name: ";
		Member.Name = clsInputValidation::ReadString();
		cout << "Enter Member Contact Info: ";
		Member.ContactInfo = clsInputValidation::ReadString();

	}
public:
	static void AddMember() {
		DrawScreen("Add Member Screen");
		cout << "Enter Member ID: ";
		short ID = clsInputValidation::ReadNumber("Echec Try Again");
		while (clsMember::IsMemberExist(ID))
		{
			cout << "\nThis ID already Exsits ,Enter Member ID: ";
			ID = clsInputValidation::ReadNumber("Echec Try Again");
		}
		clsMember Member(ID, "", "");
		_ReadBookInfo(Member);
		clsMember::AddNewMember(Member);
		cout << "\nMember added successfully!";
	}
};
