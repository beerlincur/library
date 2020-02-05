#pragma once
#include "String.h"
#include <iostream>

using std::ostream;
using std::endl;

class DisciplineCount
{
public:	
	DisciplineCount() : discipline_(""), count_(1) {};
	DisciplineCount(String discipline, size_t count) : discipline_(discipline), count_(count) {};

	String getDiscipline();
	size_t getCount();
	void setDiscipline(const String discipline);
	void setCount(const size_t count);

	friend int operator++ (DisciplineCount& dis);

	friend ostream& operator<< (ostream& out, const DisciplineCount& dis);

	~DisciplineCount() {};
private:
	String discipline_;
	unsigned int count_;
};

