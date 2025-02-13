#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsAddBookScreen.h"
#include"clsAddMemberScreen.h"
#include"clsInputValidation.h"
#include"clsIssueBook.h"
#include"clsReturnBook.h"
#include"clsDisplayAllBooks.h"
#include"clsDisplayAllMembers.h"
#include"clsFindbookScreen.h"
class clsMainScreen:protected clsScreen
{
private:
	enum _enMainMenueScreen {
		eAddBook = 1, eAddMemeber = 2, eIssueBook = 3, eReturnBook = 4,
		eDisplayBooks = 5, eDispalyMemeber = 6, eSearchBook = 7, eExit = 8
	};

	static short MakeChoice() {
		cout << "Enter your Choice :";
		return clsInputValidation::ReadNumberBetwen(1, 8, "Echec Try Again");
	}

	static void _GoBackToMainMenue() {
		cout << "\nGo Back to Main Menue ...";
		system("pause>0");
		MainScreen();
	}

	static void _AddBookScreen() {
		clsAddBookScreen::AddBook();
	}

	static void _AddMemeberScreen() {
		clsAddMemberScreen::AddMember();
	}

	static void IssueBookScreen() {
		clsIssueBook::IssueBook();
	}

	static void _ReturnBookScreen() {
		clsReturnBook::ReturnBook();
	}

	static void _DisplayAllBooks() {
		clsDisplayAllBooks::DisplayAllBooks();
	}

	static void _DisplayAllMembers() {
		clsDisplayAllMembers::DisplayAllMembers();
	}

	static void _FindBookScreen(){
		clsFindbookScreen::FindBook();
	}

	static void _PerfomMainMenue(_enMainMenueScreen MainMenue) {
		switch (MainMenue)
		{
		case clsMainScreen::eAddBook:
			system("cls");
			_AddBookScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eAddMemeber:
			system("cls");
			_AddMemeberScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eIssueBook:
			system("cls");
			IssueBookScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eReturnBook:
			system("cls");
			_ReturnBookScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDisplayBooks:
			system("cls");
			_DisplayAllBooks();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDispalyMemeber:
			system("cls");
			_DisplayAllMembers();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eSearchBook:
			system("cls");
			_FindBookScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eExit:
			break;
		default:
			break;
		}
	}

public:
	static void MainScreen() {
		system("cls");
		DrawScreen("Library Mangement System");
		cout << "1. Add a Book\n";
		cout << "2. Add a Memeber\n";
		cout << "3. Issue a Book\n";
		cout << "4. Return a Book\n";
		cout << "5. Display All Books\n";
		cout << "6. Display All Members\n";
		cout << "7. Search for a Book\n";
		cout << "8. Exit\n";
		_PerfomMainMenue(_enMainMenueScreen(MakeChoice()));
	}
};

