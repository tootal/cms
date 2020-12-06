#ifndef _CONTACTBOOK_H_
#define _CONTACTBOOK_H_

#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include "contact.h"
#include "table.h"
using namespace std;

class contactbook{
public:
	contactbook();
	void add(contact you);
	void del();
	bool del(int id);
	int list();
	int size() const;
	int getNum() const;

	int importFromCSV(const char *path);
	bool exportToCSV(const char *path);
private:
	std::list<contact> contacts;
	int num;	//id编号
	int sz;	//contacts大小
};

#endif //_CONTACTBOOK_H_
