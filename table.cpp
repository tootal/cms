#include "table.h"
using namespace std;

table::table(int row,int col){
	this->row=row;
	this->col=col;
	data.resize(row);
	for(int i=0;i<row;i++){
		data[i].resize(col);
	}
	width.resize(col,0);
}

void table::set(int x,int y,string s){
	data[x][y]=s;
	int len=s.length();
	if(len>width[y])width[y]=len;
}

ostream& operator<<(ostream &out,table &x){
	//首行
	string line1=signalChar[1];
	for(int i=0;i<x.col;i++){
		for(int j=0;j<x.width[i];j++)line1+=signalChar[10];
		if(i<x.col-1)line1+=signalChar[2];
	}
	line1+=signalChar[3];
	//中间行
	string line2=signalChar[4];
	for(int i=0;i<x.col;i++){
		for(int j=0;j<x.width[i];j++)line2+=signalChar[10];
		if(i<x.col-1)line2+=signalChar[5];
	}
	line2+=signalChar[6];
	//尾行
	string line3=signalChar[7];
	for(int i=0;i<x.col;i++){
		for(int j=0;j<x.width[i];j++)line3+=signalChar[10];
		if(i<x.col-1)line3+=signalChar[8];
	}
	line3+=signalChar[9];
	
	//输出表格
	cout<<line1<<"\n";
	for(int i=0;i<x.row;i++){
		cout<<signalChar[11];
		for(int j=0;j<x.col;j++){
			int fill=x.width[j]-x.data[i][j].length();
			//右对齐,空格填充
			for(int k=0;k<fill;k++)
				cout<<signalChar[0];
			cout<<x.data[i][j];
			cout<<signalChar[11];
		}
		cout<<"\n";
		if(i<x.row-1)cout<<line2<<"\n";
	}
	cout<<line3<<"\n";
	return out;
}

