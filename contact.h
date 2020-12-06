#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>
#include <regex>
using namespace std;
const int contactItemCount=7;
const string contactItem[contactItemCount]={"id","name","tel","email","address","title","note"};
const string contactItem_zh[contactItemCount]={"编号","姓名","电话","邮箱","地址","标题","备注"};

class contact{
public:
	contact(int id=0,
			string name="",
			string tel="",
			string email="",
			string address="",
			string title="",
			string note="");

	string get(int x) const;
	int getId() const;
	string getName() const;
	string getTel() const;
	string getEmail() const;
	string getAddress() const;
	string getTitle() const;
	string getNote() const;

	bool set(int x,string s);
	bool setId(int id);
	bool setName(string name);
	bool setTel(string tel);
	bool setEmail(string email);
	bool setAddress(string address);
	bool setTitle(string title);
	bool setNote(string note);

protected:
	int id;
	string name;
	string tel;
	string email;
	string address;
	string title;
	string note;
};

#endif //_CONTACT_H_
