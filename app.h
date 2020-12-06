#ifndef _APP_H_
#define _APP_H_

#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <sstream>
#include <regex>
#include <cctype>
#include "contact.h"
#include "contactbook.h"
#include "table.h"
using namespace std;

#define __CMSVERSION__ "1.1"      
#define __TIPS__ "(cms) "
class app{
private:
	contactbook book;
public:
	app(int argv,char *argc[]);
	void show();
	int exec();
	void delete_();
	void help_();
	void add_();
	void list_();
	void import_();
	void export_();
	void config_();
};

#endif //_APP_H_
