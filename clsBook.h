#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include"clsString.h"
const string FileName = "Book.txt";
class clsBook
{
private:
	 
	short _ID;
	string _Title;
	string _Author;
	string _Genre;
	string _Status;
	static void _SaveBooksDataToFile(vector <clsBook> vBooks)
	{

		fstream MyFile;
		MyFile.open(FileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBook C : vBooks)
			{
				 
					DataLine = _ConverBookObjectToLine(C);
					MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}
	static clsBook _ConvertLineToBookObject(string Line,string Seprator="|") {
		vector<string>Book;
		Book= clsString::Split(Line,Seprator);
		return clsBook(stoi(Book[0]),Book[1], Book[2], Book[3],Book[4]);
	}
	static  vector <clsBook> _LoadBooksDataFromFile()
	{

		vector <clsBook> vBooks;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBook Book = _ConvertLineToBookObject(Line);

				vBooks.push_back(Book);
			}

			MyFile.close();

		}

		return vBooks;

	}
	static void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	static string _ConverBookObjectToLine(clsBook Book, string Seperator = "|")
	{

		string stBookRecord = "";
		stBookRecord += to_string(Book.ID()) + Seperator;
		stBookRecord += Book.Title + Seperator;
		stBookRecord += Book.Author + Seperator;
		stBookRecord += Book.Genre + Seperator;
		stBookRecord += Book._Status  ;
		return stBookRecord;

	}

	
public:
	
	clsBook(short ID, string Title, string Author, string Genre,string Status="Available") {
		_ID = ID;
		_Title = Title;
		_Author = Author;
		_Genre = Genre;
		_Status = Status;
	}
	short ID() {
		return _ID;
	}

	void SetTilte(string Title) {
		_Title = Title;
	}
	string GetTitle(){
		return _Title;
}
	_declspec(property(put = SetTilte, get = GetTitle))string Title;

	void SetAuthore(string Author) {
		_Author = Author;
	}
	string GetAuthor() {
		return _Author;
	}
	_declspec(property(put = SetAuthore, get = GetAuthor))string Author;

	void SetGenre(string Genre) {
		_Genre = Genre;
	}
	string GetGenre() {
		return _Genre;
	}
	_declspec(property(put = SetGenre, get = GetGenre))string  Genre;

	void SetStatus(string Status) {
		_Status = Status;
	}
	string GetStatus() {
		return _Status;
	}
	_declspec(property(put = SetStatus, get = GetStatus))string  Status;

	static bool IsBookExist(short ID) {
		fstream File;
		File.open(FileName, ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBook Book = _ConvertLineToBookObject(Line, "|");
				if (Book.ID() == ID)return true;
				
			}
			File.close();
		}
		return false;
	}
	static void AddNewBook(clsBook Book) {
		_AddDataLineToFile(_ConverBookObjectToLine(Book));
	}

	static clsBook Find(short ID)
	{


		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBook Book = _ConvertLineToBookObject(Line);
				if (Book.ID() == ID )
				{
					MyFile.close();
					return Book;
				}

			}

			MyFile.close();

		}

		return clsBook(ID, "", "", "");
	}

	static void UpdateIssueBook(clsBook Book) {
		vector<clsBook>vbooks = _LoadBooksDataFromFile();
		for (clsBook& C : vbooks) {
			if (Book.ID() == C.ID()) {
				if (Book.Status == "Available") {
					C.Status = "Issued";
				}
				else {
					C.Status = "Available";
				}
			}
		}
		_SaveBooksDataToFile(vbooks);
	 }

	static vector <clsBook> GetBooksList()
	{
		return _LoadBooksDataFromFile();
	}
};

