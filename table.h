#ifndef _TABLE_H_
#define _TABLE_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string signalChar[]={" ","┌","┬","┐","├","┼","┤","└","┴","┘","─","│"};
//const string signalChar[]={" ","+","+","+","+","+","+","+","+","+","-","|"};
class table{
public:
	table(int row=0,int col=0);
	void set(int x,int y,string s);
	friend ostream& operator<<(ostream &out,table &x);

private:
	vector<vector<string> > data;
	vector<int> width;
	int row,col;
};

#endif //_TABLE_H_
