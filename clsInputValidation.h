#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidation
{
public :
	static int ReadPositiveNumber(string Msj) {
		int Number = 0;
		do
		{
			
			cin >> Number;
			while (cin.fail())
			{
				// user didn't input a number
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << Msj << endl;
				cin >> Number;
			}
		} while (Number <= 0);
		return Number;
	}
	static int ReadNumber(string Msj) {
		int Number = 0;
		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Msj << endl;
			cin >> Number;
		}
		return Number;
	}
	static int ReadNumberBetwen(int From, int To,string Msj) {
		int Number = 0;
		do
		{
			
			cin >> Number;
			while (cin.fail())
			{
				// user didn't input a number
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << Msj << endl;
				cin >> Number;
			}
		} while (Number <From || Number>To);
		return Number;
	}
	static int ReadDBNumberBetwen(int From, int To, string Msj) {
		double Number = 0;
		do
		{
			
			cin >> Number;
			while (cin.fail())
			{
				// user didn't input a number
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << Msj << endl;
				cin >> Number;
			}
		} while (Number <From || Number>To);
		return Number;
	}
	static double ReadDBNumber(string Msj) {
		double Number = 0;
		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Msj << endl;
			cin >> Number;
		}
		return Number;
	}
	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static bool ISNumberBetwen(int Number, int From, int To) {
		return (Number <= To && Number >= From);
	}
	static bool ISNumberBetwen(double Number, double From, double To) {
		return (Number <= To && Number >= From);
	}
	static bool ISDateBetwen(clsDate Date, clsDate Date1, clsDate Date2) {
		if (clsDate::IsDate1AfterDate2(Date1, Date2)) {
			clsDate::SwapDates(Date1, Date2);
		}
		return clsDate::IsDate1BeforeDate2(Date, Date2) && clsDate::IsDate1AfterDate2(Date, Date1);

	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

