#include "Book.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

void Book::setAuthor(String author) { author_ = author; }
void Book::setName(String name) { name_ = name; }
void Book::setYear(unsigned short int year) { year_ = year; }
void Book::setDiscpline(String discipline) { discipline_ = discipline; }
void Book::setAmount(unsigned short int amount) { amount_ = amount; }
//=========================================================
String Book::getAuthor() const { return author_; }
String Book::getName() const { return name_; }
int Book::getYear() const { return year_; }
String Book::getDiscipline() const { return discipline_; }
int Book::getAmount() const { return amount_; }
//=========================================================
Book& Book::operator= (const Book& book)
{
	author_ = book.author_;
	name_ = book.name_;
	year_ = book.year_;
	discipline_ = book.discipline_;
	amount_ = book.amount_;
	return *this;
}

size_t Book::operator= (size_t amount)
{
	return amount_;
	
}
//==========================================================
bool operator> (const Book& book1, const Book& book2)
{
	return book1.amount_ > book2.amount_;
}


bool operator> (const Book& book1, const int amount)
{
	return book1.amount_ > amount;
}

bool operator> (const int amount, const Book& book2)
{
	return amount > book2.amount_;
}
//============================================================
bool operator< (const Book& book1, const Book& book2)
{
	return book1.amount_ < book2.amount_;
}

bool operator< (const Book& book1, const int amount)
{
	return book1.amount_ < amount;
}
bool operator< (const int amount, const Book& book2)
{
	return amount < book2.amount_;
}
//============================================================
bool operator== (const Book& book1, const Book& book2)
{
	return book1.amount_ == book2.amount_;
}


bool operator== (const Book& book1, const int amount)
{
	return book1.amount_ == amount;
}
bool operator== (const int amount, const Book& book2)
{
	return amount == book2.amount_;
}
//=============================================================
bool operator!= (const Book& book1, const Book& book2)
{
	return !(book1.amount_ == book2.amount_);
}

bool operator!= (const Book& book1, const int amount)
{
	return !(book1.amount_ == amount);
}
bool operator!= (const int amount, const Book& book2)
{
	return !(amount == book2.amount_);
}
//===============================================================
ostream& operator<< (ostream& out, const Book& book)
{
	out << "Author of the book is: " << book.author_ << endl;
	out << "Name of the book is: " << book.name_ << endl;
	out << "Year of publishing is: " << book.year_ << endl;
	out << "Book discipline is: " << book.discipline_ << endl;
	out << "Amount of books in library: " << book.amount_ << endl;
	return out;
}


Book Book::operator++()
{
	amount_++;
	return *this;
}

Book Book::operator--()
{
	amount_--;
	return *this;
}