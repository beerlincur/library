#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class String
{
	char* data_;
	unsigned length_;
		
public:
	String ();
	String(char cr);
	String(const char* cPtr);
	String(const String& str);

	int to_int();
	bool empty();
	unsigned len() const;//длина
	int index(char c) const;//индекс элемента
	char& operator[] (unsigned j);
	String substr(const unsigned first);
	char  operator[] (unsigned j) const;
	String& operator= (const String& str);//присваивание
	String& operator+= (const String& str);//+=
	void upcase(unsigned first, unsigned last);//к верхнему
	void downcase(unsigned first, unsigned last);//к нижнему
	void togglecase(unsigned first, unsigned last);//туда сюда
	String substr(const unsigned first, const unsigned last);

	friend ostream& operator<< (ostream& so, const String& str);//вывод
	friend istream& operator>> (istream& so, const String& str);//ввод

	friend String operator+ (const String& left, const String& right);//сложение
	friend String operator+ (const String& left, char          right);
	friend String operator+ (const String& left, const char*   right);
	friend String operator+ (char          left, const String& right);
	friend String operator+ (const char*   left, const String& right);

	friend bool operator==  (const String& left, const String& right);//равно
	friend bool operator==  (const String& left, char          right);
	friend bool operator==  (const String& left, const char*   right);
	friend bool operator==  (char          left, const String& right);
	friend bool operator==  (const char*   left, const String& right);

	friend bool operator>   (const String& left, const String& right);//больше
	friend bool operator>   (const String& left, char          right);
	friend bool operator>   (const String& left, const char*   right);
	friend bool operator>   (char          left, const String& right);
	friend bool operator>   (const char*   left, const String& right);

	friend bool operator!=  (const String& left, const String& right);//не равно
	friend bool operator!=  (const String& left, char          right);
	friend bool operator!=  (const String& left, const char*   right);
	friend bool operator!=  (char          left, const String& right);
	friend bool operator!=  (const char*   left, const String& right);

	friend bool operator<   (const String& left, const String& right);//меньше
	friend bool operator<   (const String& left, char          right);
	friend bool operator<   (const String& left, const char*   right);
	friend bool operator<   (char          left, const String& right);
	friend bool operator<   (const char*   left, const String& right);

	friend bool operator<=  (const String& left, const String& right);//меньше либо равно
	friend bool operator<=  (const String& left, char          right);
	friend bool operator<=  (const String& left, const char*   right);
	friend bool operator<=  (char          left, const String& right);
	friend bool operator<=  (const char*   left, const String& right);

	friend bool operator>=  (const String& left, const String& right);//больше либо равно
	friend bool operator>=  (const String& left, char          right);
	friend bool operator>=  (const String& left, const char*   right);
	friend bool operator>=  (char          left, const String& right);
	friend bool operator>=  (const char*   left, const String& right);

	friend class Book;

	~String();

};

