#include "DisciplineCount.h"

String DisciplineCount::getDiscipline() { return discipline_; }
size_t DisciplineCount::getCount() { return count_; }
void DisciplineCount::setDiscipline(const String discipline) { discipline_ = discipline; }
void DisciplineCount::setCount(const size_t count) { count_ = count; }

int operator++ (DisciplineCount& dis) { return (++dis.count_); }
ostream& operator<< (ostream& out, const DisciplineCount& dis)
{
	out << "Discipline is: " << dis.discipline_ << " and it has " << dis.count_ << " books" << endl;
	return out;
}
