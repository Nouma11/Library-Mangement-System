#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include"clsString.h"
#include"clsDate.h"
#include<string>
#include"clsBook.h"
#include"clsMember.h"
const string TranscationFileName = "Transcation.txt";
class clsTranscation
{
private:
	 short _TranscationID;
	short _BookID;
	short _MemberID;
	string _IssueDate;
	string _ReturnDate;

	static  vector <clsTranscation> _LoadTranscationsDataFromFile()
	{

		vector <clsTranscation> vTranscations;

		fstream MyFile;
		MyFile.open(TranscationFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsTranscation Transcation = _ConvertLineToTranscationObject(Line);

				vTranscations.push_back(Transcation);
			}

			MyFile.close();

		}

		return vTranscations;

	}
	static void _SaveTranscationDataToFile(vector <clsTranscation> vTranscations)
	{

		fstream MyFile;
		MyFile.open(TranscationFileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsTranscation C : vTranscations)
			{

				DataLine = _ConverTranscationObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}
	static clsTranscation _ConvertLineToTranscationObject(string Line, string Seprator = "|") {
		vector<string>Transcation;
		Transcation = clsString::Split(Line, Seprator);
		return clsTranscation(stoi(Transcation[0]), stoi(Transcation[1]), stoi(Transcation[2]), Transcation[3], Transcation[4]);
	}
	static  vector <clsTranscation> _LoadBooksDataFromFile()
	{

		vector <clsTranscation> vTranscations;

		fstream MyFile;
		MyFile.open(TranscationFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsTranscation Transcation = _ConvertLineToTranscationObject(Line);

				vTranscations.push_back(Transcation);
			}

			MyFile.close();

		}

		return vTranscations;

	}
	static void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open(TranscationFileName , ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	static string _ConverTranscationObjectToLine(clsTranscation Transcation, string Seperator = "|")
	{

		string stTranscationRecord = "";
		stTranscationRecord += to_string(Transcation.TranscationID()) + Seperator;
		stTranscationRecord += to_string(Transcation.BookID()) + Seperator;
		stTranscationRecord += to_string(Transcation.MemberID()) + Seperator;
		stTranscationRecord += Transcation.IssueDate + Seperator;
		stTranscationRecord += Transcation.ReturnDate;
		return stTranscationRecord;

	}
public:
	clsTranscation(short TranscationID, short BookID, short MemberID, string IssueDate, string ReturnDate=" ") {
		_TranscationID = TranscationID;
		_BookID = BookID;
		_MemberID = MemberID;
		_IssueDate = IssueDate;
		_ReturnDate = ReturnDate;
	}

	void SetIssueDate(string IssueDate) {
		_IssueDate = IssueDate;
	}
	string GetIssueDate() {
		return _IssueDate;
	}
	_declspec(property(put = SetIssueDate, get = GetIssueDate))string  IssueDate;

	void SetReturnDate(string ReturnDate) {
		_ReturnDate = ReturnDate;
	}
	string GetReturnDate() {
		return _ReturnDate;
	}
	_declspec(property(put = SetReturnDate, get = GetReturnDate))string ReturnDate;
	short BookID() {
		return _BookID;
	}
	
	short MemberID() {
		return _MemberID;
	}

	short TranscationID() {
		return _TranscationID;
	}

	static void AddTranscaction(clsTranscation Transcation) {
		_AddDataLineToFile(_ConverTranscationObjectToLine(Transcation));
	}

	static clsTranscation Find(short ID)
	{


		fstream MyFile;
		MyFile.open(TranscationFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsTranscation Transcation = _ConvertLineToTranscationObject(Line);
				if (Transcation.BookID() == ID)
				{
					MyFile.close();
					return Transcation;
				}

			}

			MyFile.close();

		}

		return clsTranscation(NULL,NULL,NULL, "", "");
	}

	static void ReturnBook(clsTranscation Transcation,string ReturnDate) {
		vector<clsTranscation>vTranscations = _LoadTranscationsDataFromFile();
		for (clsTranscation& C : vTranscations) {
			if (Transcation.TranscationID() == C.TranscationID()) {
				
					C.ReturnDate = ReturnDate;
				
				
			}
		}
		_SaveTranscationDataToFile(vTranscations);

	}
};

