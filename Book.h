#pragma once
#include "String.h"

class Book
{
public:
	Book() : author_(""), name_(""), year_(0), discipline_(""), amount_(0) {};
	Book(const String bAuthor, const String bName, const int bYear, const String bDiscipline, const int bAmount) :
		author_(bAuthor), name_(bName), year_(bYear), discipline_(bDiscipline), amount_(bAmount) {};
	Book(const Book& ob) : author_(ob.author_), name_(ob.name_), year_(ob.year_), discipline_(ob.discipline_), amount_(ob.amount_) {};
	
	void setAuthor(String author);
	void setName(String bName);
	void setYear(unsigned short int year);
	void setDiscpline(String discipline);
	void setAmount(unsigned short int amount);

	friend class String;
	
	String getAuthor() const;
	String getName() const;
	int getYear() const;
	String getDiscipline() const;
	int getAmount() const;

	Book& operator= (const Book& book);
	size_t operator= (size_t amount);

	friend bool operator>  (const  Book&  book1,  const Book&  book2);
	friend bool operator>  (const  Book&  book1,  const int    amount);
	friend bool operator>  (const  int    amount, const Book&  book2);

	friend bool operator<  (const  Book&  book1,  const Book&  book2);
	friend bool operator<  (const  Book&  book1,  const int    amount);
	friend bool operator<  (const  int    amount, const Book&  book2);

	friend bool operator== (const  Book&  book1,  const Book&  book2);
	friend bool operator== (const  Book&  book1,  const int    amount);
	friend bool operator== (const  int    amount, const Book&  book2);

	friend bool operator!= (const  Book&  book1,  const Book&  book2);
	friend bool operator!= (const  Book&  book1,  const int    amount);
	friend bool operator!= (const  int    amount, const Book&  book2);

	friend ostream& operator<< (ostream& out, const Book& book);

	Book operator++ ();
	Book operator-- ();

	~Book() {};

private:
	String author_;
	String name_;
	unsigned short int year_;
	String discipline_;
	unsigned short int amount_;
};

