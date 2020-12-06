#include "contactbook.h"
using namespace std;

contactbook::contactbook(){
	num=0;
	sz=0;
}

void contactbook::add(contact you){
	contacts.push_back(you);
	num++;sz++;
}

void contactbook::del(){
	contacts.clear();
	sz=0;
}

bool contactbook::del(int id){
	auto prev=remove_if(contacts.begin(),contacts.end(),
		[id](contact you){return you.getId()==id;});
	contacts.erase(prev,contacts.end());
	int newSz=contacts.size();
	if(newSz==sz)return false;
	sz=newSz;
	return true;
}

int contactbook::list(){
	table view(sz+1,contactItemCount);
	for(int i=0;i<contactItemCount;i++){
		view.set(0,i,contactItem[i]);
	}
	int i=1;
	for(auto item:contacts){
		for(int j=0;j<contactItemCount;j++){
			view.set(i,j,item.get(j));
		}
		i++;
	}
	cout<<view;
	return sz;
}

int contactbook::size() const{
	return sz;
}

int contactbook::getNum() const{
	return num;
}

int contactbook::importFromCSV(const char *path){
	ifstream in(path);
	if(in.is_open()){
		char ch;
		string you;
		getline(in,you);
		int cnt=0;
		while(getline(in,you)){
			string info;
			istringstream line(you);
			contact me;
			for(int i=0;i<5;i++){
				getline(line,info,',');
				me.set(i+1,info);
			}
			line>>info>>ch;
			me.set(5,info);
			me.setId(num+1);
			add(me);
			cnt++;
		}
		return cnt;
	}
	return 0;
}

bool contactbook::exportToCSV(const char *path){
	ofstream out(path);
	if(!out.is_open())return false;

	for(int i=1;i<contactItemCount;i++){
		if(i>1)out<<",";
		out<<contactItem_zh[i];
	}
	out<<"\n";
	for(auto item:contacts){
		for(int j=1;j<contactItemCount;j++){
			if(j>1)out<<",";
			out<<item.get(j);
		}
		out<<"\n";
	}
	return true;
}
