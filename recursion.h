#include "String.h"
#include <iostream>

using std::cout;
using std::endl;

bool isDigit(const char digit)//<цифра> ::= 0 | 1 | 2 | 3 | 4 |  5 | 6 |7 | 8 | 9
{
	return ('0' <= digit && digit <= '9');//проверка на цифру
}

bool isInteger(String& integers)//<целое без знака> ::= <цифра> | <цифра> <целое без знака>
{
	if (integers.len() == 1)//условия остановки рекурсии
	{
		return isDigit(integers[0]);
	}
	String next = integers.substr(1);
	return (isDigit(integers[0]) && isInteger(next));//проверка на целые числа в строке
}

bool isCapital(const char firstLetter)//65-A, 90-Z
{
	return (65 <= firstLetter && firstLetter <= 90);
}

bool isLetter(const char letter)
{
	return (97 <= letter && letter <= 122);
}

bool isLowers(String& letters)
{
	int length = letters.len();
	if (length == 1)
	{
		return isLetter(letters[0]);
	}
	String next = letters.substr(1, length);
	return (isLetter(letters[0]) && isLowers(next));
}

int searchUnder(String& fullString) //рекурсивный поиск символа '_'
{
	if (fullString.empty())//пустая строка
	{
		return 0;
	}
	if (fullString.len() == 1)//длина строки == 1
	{
		return fullString[0] != '_';
	}
	if (fullString[0] == '_')//первый символ это '_'
	{
		return 0;
	}
	String next = fullString.substr(1);
	return 1 + searchUnder(next);//вовзрат номера элемента после '_'
}

bool isFullStop(const char c)
{
	return (c == '.');
}

bool isAuth(String& authIn)
{
	int idUnder = searchUnder(authIn);
	if (idUnder == authIn.len())
	{
		return false;
	}
	
	authIn[idUnder] = ' ';

	String secondName = authIn.substr(0, idUnder);
	String firstName = authIn.substr(idUnder + 1);

	String low = secondName.substr(1);

	return (isCapital(secondName[0]) && isLowers(low) && isCapital(firstName[0]) && isFullStop(firstName[1]));
}

bool isYear(const int yearIn)
{
	return (1574 <= yearIn && yearIn <= 2019);
}

bool isDiscipline(String& dis)
{
	String low = dis.substr(1);
	return (isCapital(dis[0]) && isLowers(low));
}

bool isAmount(const int amo)
{
	return (0 <= amo && amo <= 5000);
}

bool isName(String& nameIn)
{
	int idUnder = searchUnder(nameIn);

	if (idUnder == nameIn.len())
	{
		return false;
	}

	String left = nameIn.substr(0, idUnder);
	
	String rigth = nameIn.substr(idUnder + 1);

	String lowL = left.substr(1);
	String lowR = left.substr(1);
	return (isCapital(left[0]) && isLowers(lowL) && isLowers(lowR) && (isCapital(rigth[0]) || isLetter(rigth[0])));
}