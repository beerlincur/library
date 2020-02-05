#include "Book.h"
#include <fstream>
#include <iostream>
#include "List.h"
#include "Array.h"
#include "recursion.h"
#include "maxAndMin.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

const String WRONG_AUTHOR = "Wrong author's name in the following: ";
const String WRONG_BOOK_NAME = "Wrong book name in the following: ";
const String WRONG_YEAR = "Wrong year of publishing in the followwing: ";
const String WRONG_DIS = "Wrong recommended discipline in the following: ";
const String WRONG_AMO = "Wrong amount of book in the following: ";

char *getline(istream& in)
{
	const int BUF_LEN = 50;

	int len = BUF_LEN;
	int i = 0;

	char * str = (char*)malloc(BUF_LEN * sizeof(char)), c;

	while (in.get(c) && c != '\n')
	{
		if (i == len)
		{
			str = (char*)realloc(str, len += BUF_LEN);
		}
		str[i++] = c;
	}

	char * rez = new char[i + 1];
	for (int j = 0; j < i; ++j)
	{
		rez[j] = str[j];
	}
	rez[i] = 0;

	free(str);
	return rez;
}

Book split(String& str)
{
	String author;
	String name;
	String year;
	String discipline;
	String amount;
	size_t j = 0;
	size_t LAST_SPACE = 0;
	size_t length = str.len();
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			switch (j)
			{
			case 0: author = str.substr(0, i); break;
			case 1: name = str.substr(LAST_SPACE + 1, i); break;
			case 2: year = str.substr(LAST_SPACE + 1, i); break;
			case 3: discipline = str.substr(LAST_SPACE + 1, i); break;
			}
			j++;
			LAST_SPACE = i;
		}
	}

	amount = str.substr(LAST_SPACE + 1, length);

	if (!isAuth(author))
	{
		throw WRONG_AUTHOR + " " + str;
	}

	if (!isName(name))
	{
		throw WRONG_BOOK_NAME + " " + str;
	}

	size_t nameLen = name.len();
	for (size_t i = 0; i < nameLen; i++)
	{
		if (name[i] == '_')
		{
			name[i] = ' ';
		}
	}
	
	int yearInt = year.to_int();

	if (!isYear(yearInt))
	{
		throw WRONG_YEAR + " " + str;
	}

	if (!isDiscipline(discipline))
	{
		throw WRONG_DIS + " " + str;
	}

	int amountInt = amount.to_int();

	if (!isAmount(amountInt))
	{
		throw WRONG_AMO + " " + str;
	}

	Book tempBook(author, name, yearInt, discipline, amountInt);

	return tempBook;
}

struct maxAndMin maxMin(const Array<Book>& myArray, const size_t size)
{
	Book maxBook = myArray[0];
	Book minBook = myArray[0];

	for (size_t i = 1; i < size; i++)
	{
		Book tempBook = myArray[i];
		if (tempBook > maxBook)
		{
			maxBook = tempBook; 
		}
		if (tempBook < minBook)
		{
			minBook = tempBook;
		}
	}
	struct maxAndMin toReturn = { maxBook, minBook };
	return toReturn;
}



