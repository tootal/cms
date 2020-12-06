#include "contact.h"
using namespace std;
contact::contact(int id,
				 string name,
				 string tel,
				 string email,
				 string address,
				 string title,
				 string note){
	setId(id);
	setName(name);
	setTel(tel);
	setEmail(email);
	setAddress(address);
	setTitle(title);
	setNote(note);
}

string contact::get(int x) const{
	switch(x){
		case 0:return to_string(id);
		case 1:return name;
		case 2:return tel;
		case 3:return email;
		case 4:return address;
		case 5:return title;
		case 6:return note;
		default:return "";
	}
}

int contact::getId() const{
	return id;
}

string contact::getName() const{
	return name;
}

string contact::getTel() const{
	return tel;
}

string contact::getEmail() const{
	return email;
}

string contact::getAddress() const{
	return address;
}

string contact::getTitle() const{
	return title;
}

string contact::getNote() const{
	return note;
}

bool contact::set(int x,string s){
	switch(x){
		case 0:return setId(stoi(s));
		case 1:return setName(s);
		case 2:return setTel(s);
		case 3:return setEmail(s);
		case 4:return setAddress(s);
		case 5:return setTitle(s);
		case 6:return setNote(s);
		default:return true;
	}
}

bool contact::setId(int id){
	this->id=id;
	return true;
}

bool contact::setName(string name){
	// 正则匹配：中文、英文字母、下划线、数字(1~125个字符)(暂时取消)
	// if(regex_match(name,regex("^[\u4e00-\u9fa5_a-zA-Z0-9]{1,125}$"))){
		this->name=name;
		return true;
	// }else return false;
}

bool contact::setTel(string tel){
	// 正则匹配：11位数字(暂时取消11位)
	// if(regex_match(tel,regex("^\\d{11}$"))){
		this->tel=tel;
		return true;
	// }else return false;
}

bool contact::setEmail(string email){
	//设定邮箱为非必需项
	if(email=="")return true;
	// 正则匹配：不以_-.开头
	if(regex_match(email,regex("^[A-Za-z\\d]+([-_.][A-Za-z\\d]+)*@([A-Za-z\\d]+[-.])+[A-Za-z\\d]{2,4}$"))){
		this->email=email;
		return true;
	}else return false;
}

bool contact::setAddress(string address){
	this->address=address;
	return true;
}

bool contact::setTitle(string title){
	this->title=title;
	return true;
}

bool contact::setNote(string note){
	this->note=note;
	return true;
}
