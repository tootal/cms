// 此文件用来测试通讯录类
#include <iostream>
#include "app.h"
using namespace std;
int main(int argv,char *argc[]){
	//cout<<"hello world!\n";
	//cout<<"你好！\n";
	//cout<<"test:"<<test(-1)<<"\n";
	app cms(argv,argc);
	cms.show();
	return cms.exec();
}
