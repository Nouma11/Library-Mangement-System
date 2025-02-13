#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include"clsString.h"
#include<string>
const string MemberFileName = "Member.txt";
using namespace std;
class clsMember
{
	  
private:
	
	short _ID;
	string _Name;
	string _ContactInfo;
	string _BookID;

	static void _SaveMembersDataToFile(vector <clsMember> vMembers)
	{

		fstream MyFile;
		MyFile.open(MemberFileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsMember C : vMembers)
			{

				DataLine = _ConverMemberObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}
	static clsMember _ConvertLineToMemberObject(string Line, string Seprator = "|") {
		vector<string>Member;
		Member = clsString::Split(Line, Seprator);
		return clsMember(stoi(Member[0]), Member[1], Member[2],Member[3]);
	}
	static  vector <clsMember> _LoadMembersDataFromFile()
	{

		vector <clsMember> vMembers;

		fstream MyFile;
		MyFile.open(MemberFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsMember Member = _ConvertLineToMemberObject(Line);

				vMembers.push_back(Member);
			}

			MyFile.close();

		}

		return vMembers;

	}
	static void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open(MemberFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	static string _ConverMemberObjectToLine(clsMember Member, string Seperator = "|")
	{

		string stBookRecord = "";
		stBookRecord += to_string(Member.ID()) + Seperator;
		stBookRecord += Member.Name + Seperator;
		stBookRecord += Member.ContactInfo+Seperator  ;
		stBookRecord += Member._BookID;
		return stBookRecord;

	}


public:

	clsMember(short ID, string Name, string ContactInfo,string BookID=" ") {
		_ID = ID;
		_Name = Name;
		_ContactInfo = ContactInfo;
		_BookID = BookID;
	}
	short ID() {
		return _ID;
	}

	void SetName(string Name) {
		_Name = Name;
	}
	string GetName() {
		return _Name;
	}
	_declspec(property(put = SetName, get = GetName))string Name;

	void SetContactInfo(string ContactInfo) {
		_ContactInfo = ContactInfo;
	}
	string GetContactInfo() {
		return _ContactInfo;
	}
	_declspec(property(put = SetContactInfo, get = GetContactInfo))string ContactInfo;
	string GetBookID() {
		return _BookID;
	}
	void setBookID(string BookID) {
		_BookID = BookID;
	}
	_declspec(property(put = setBookID, get = GetBookID))string BookID;
	static bool IsMemberExist(short ID) {
		fstream File;
		File.open(MemberFileName, ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsMember Member = _ConvertLineToMemberObject(Line, "|");
				if (Member.ID() == ID)return true;

			}
			File.close();
		}
		return false;
	}
	static void AddNewMember(clsMember Member) {
		_AddDataLineToFile(_ConverMemberObjectToLine(Member));
	}

	static clsMember Find(short ID)
	{


		fstream MyFile;
		MyFile.open(MemberFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsMember Member = _ConvertLineToMemberObject(Line);
				if (Member.ID() == ID)
				{
					MyFile.close();
					return Member;
				}

			}

			MyFile.close();

		}

		return clsMember(ID, "", "");
	}


	static void UpdateBookForMember(short MemberID,short BookID) {
		vector<clsMember>vMembers = _LoadMembersDataFromFile();
		for (clsMember& C : vMembers) {
			if (MemberID == C.ID()) {
				if (C.BookID == " ") {
					C.BookID = to_string(BookID);
				}
				else {
					C.BookID = " ";
				}
			}
		}
		_SaveMembersDataToFile(vMembers);
	
	}

	static vector <clsMember> GetMembersList()
	{
		return _LoadMembersDataFromFile();
	}
};

