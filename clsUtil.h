#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsDate.h"
#include<vector>
using namespace std;
class clsUtil
{
public:

	static int ReadRangedNumber(int From, int To) {
		int Number = 0;
		do
		{
			cout << "Enter Number Between " << From;
			cout << " And " << To << endl;
			cin >> Number;
			while (cin.fail())
			{
				// user didn't input a number
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Number, Enter a valid one:" << endl;
				cin >> Number;
			}
		} while (Number <From || Number>To);
		return Number;
	}
	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	static int SumOfDigits(int Number)
	{
		int Sum = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}
		return Sum;
	}
	static int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}
	static bool isPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return Number == Sum;
	}
	static bool CheckPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return false;
		}
		return true;
	}
	static void ReadArrayElement(int arr[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Enter arr[" << i + 1 << "] : ";
			cin >> arr[i];
		}
	}
	static void PrintArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	static void FillArrayWith1toN(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = i + 1;
	}
	static int SumArray(int arr[], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}
	static bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix1[i][j] != Matrix2[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	static int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
	{
		int Sum = 0;
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Sum += Matrix1[i][j];
			}
		}
		return Sum;
	}
	static bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
	{
		return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows,
			Cols));
	}
	static bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		// Check Diagonal elements are 1 and rest elements are 0
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				// check for diagonals element
				if (i == j && Matrix[i][j] != 1)
				{
					return false;
				}
				// check for rest elements
				else if (i != j && Matrix[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	static bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		int FirstDiagElement = Matrix[0][0];
		// Check Diagonal elements are 1 and rest elements are 0
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				// check for diagonals element
				if (i == j && Matrix[i][j] != FirstDiagElement)
				{
					return false;
				}
				// check for rest elements
				else if (i != j && Matrix[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	static void PrintMatrix(int arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				cout << setw(3) << arr[i][j] << " ";
				//printf(" %0*d ", 2, arr[i][j]);
			}
			cout << "\n";
		}
	}
	static short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
	{
		short NumberCount = 0;
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] == Number)
					NumberCount++;
			}
		}
		return NumberCount;
	}
	static short IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		short MatrixSize = Rows * Cols;
		return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));
	}
	static bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] == Number)
					return true;
			}
		}
		return false;
	}
	static void PrintIntersectedNumbers(int Matrix1[3][3], int	Matrix2[3][3], short Rows, short Cols)
	{
		int Number;
		for (short i = 0; i <= Rows - 1; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Number = Matrix1[i][j];
				if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
				{
					cout << setw(3) << Number << " ";
				}
			}
		}
	}
	static int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		int Min = Matrix[0][0];
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] < Min)
					Min = Matrix[i][j];
			}
		}
		return Min;
	}
	static int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		int Max = Matrix[0][0];
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] > Max)
					Max = Matrix[i][j];
			}
		}
		return Max;
	}
	static bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{

			for (short j = 0; j < Cols / 2; j++)
			{
				if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
					return false;
			}
		}
		return true;
	}
	static void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
	{
		int FebNumber = 0;
		if (Number > 0)
		{
			FebNumber = Prev2 + Prev1;
			Prev2 = Prev1;
			Prev1 = FebNumber;
			cout << FebNumber << " ";
			PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
		}
	}
	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		cout << "\n First letters of this string :\n";
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	static string UpeerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	enum enCharType {
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void  Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}



	static char GetRandomCharacter(enCharType CharType)
	{

		//updated this method to accept mixchars
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}

		switch (CharType)
		{

		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
	defualt:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		}
	}

	static  string GenerateWord(enCharType CharType, short Length)

	{
		string Word;

		for (int i = 1; i <= Length; i++)

		{

			Word = Word + GetRandomCharacter(CharType);

		}
		return Word;
	}

	static string  GenerateKey(enCharType CharType = CapitalLetter)
	{

		string Key = "";


		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);


		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{

		for (int i = 1; i <= NumberOfKeys; i++)

		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);

	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string  EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}





    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }



};
