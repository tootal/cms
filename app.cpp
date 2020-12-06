#include "app.h"
using namespace std;
app::app(int argv,char *argc[]){

}

void app::show(){
	cout<<"欢迎使用通讯录管理系统 v"<<__CMSVERSION__<<"\n";
	cout<<"输入 \"help\" 查看更多信息\n";
	cout<<"1.添加 (add)\n";
	cout<<"2.查看 (list)\n";
	cout<<"3.删除 (delete)\n";
	cout<<"4.导入 (import)\n";
	cout<<"5.导出 (export)\n";
	//cout<<"6.设置 (config)\n";
	cout<<"0.退出 (quit)\n\n";
}

void app::help_(){
	cout<<"通讯录管理系统 v"<<__CMSVERSION__<<" x";
	cout<<8*sizeof(void*)<<".\n";
	cout<<"构建于 ";
	cout<<__DATE__<<" "<<__TIME__<<"\n";
	cout<<"以下命令在软件内部定义,输入 \"help\" 可以查看此列表.\n";
	cout<<"\nhelp   [h] 查看帮助\n";
	cout<<"\t命令不区分大小写,可以输入数字序号提示、缩写来执行命令.\n";
	cout<<"\t直接按回车键可以重复上一次命令.\n";
	cout<<"\nadd    [a] 添加联系人\n";
	cout<<"\t所有项均可为空,其中若邮箱项不为空,则会检查其格式是否正确.\n";
	cout<<"\nlist   [l] 查看联系人\n";
	cout<<"\t以表格的形式展示所有的信息.\n";
	cout<<"\ndel    [d] 删除联系人\n";
	cout<<"\t输入编号删除对应的联系人.\n";
	cout<<"\nimport [i] 导入联系人\n";
	cout<<"\t输入文件名,目前仅支持导入csv文件.\n";
	cout<<"\nexport [e] 导出联系人\n";
	cout<<"\t输入文件名,目前仅支持导出csv文件.\n";
	cout<<"\n命令模式 [:] 执行系统命令\n";
	cout<<"\t在输入的命令前加上 : 将被识别为系统命令.\n";
	cout<<"\nquit [q] 退出通讯录\n";
}

int app::exec(){
	string in,copy;
	while(true){
		cout<<__TIPS__;
		getline(cin,in);
		if(in==""){
			if(copy=="")continue;
			else in=copy;
		}else if(in[0]==':'){//系统命令执行
			system(string(in.begin()+1,in.end()).c_str());
			continue;
		}
		copy=in;
		//转换为小写
		transform(in.begin(),in.end(),in.begin(),::tolower);
		//去除首尾空格
		if(!in.empty()){
			auto in_begin=in.begin(),in_end=in.end();
			while(in_begin!=in_end&&(*in_begin==' '))in_begin++;
			while((in_end-1)!=in_begin&&(*(in_end-1)==' '))in_end--;
			in=string(in_begin,in_end);
		}
		// cerr<<"in="<<in<<",copy="<<copy<<"\n";
		if(in=="0"||in=="q"||in=="quit")return 0;
		if(in=="1"||in=="a"||in=="add"){
			add_();
		}else if(in=="2"||in=="l"||in=="list"){
			list_();
		}else if(in=="3"||in=="d"||in=="delete"){
			delete_();
		}else if(in=="h"||in=="help"){
			help_();
		}else if(in=="4"||in=="i"||in=="import"){
			import_();
		}else if(in=="5"||in=="e"||in=="export"){
			export_();
		//}else if(in=="6"||in=="c"||in=="config"){
			//config_();
		}else{
			cout<<"没有找到命令: \""<<copy<<"\".尝试输入 \"help\".\n";
		}
	}
}

inline void app::delete_(){
	if(book.size()==0){
		cout<<"没有联系人.\n";
		return ;
	}else if(book.size()==1){
		book.del();
		cout<<"已删除所有联系人.\n";
		return ;
	}
	cout<<"请输入联系人编号:";
	string id;
	while(true){
		getline(cin,id);
		if(regex_match(id,regex("^[0-9]{1,8}$"))){
			if(book.del(stoi(id))){
				cout<<"成功删除编号为"<<id<<"的联系人.\n";
			}else{
				cout<<"删除联系人失败.\n";
			}
			break;
		}else{
			cout<<"输入错误,请重新输入联系人编号:";
		}
	}
}

inline void app::add_(){
	cout<<"添加联系人信息(输入 # 可以取消添加).\n";
	string item[7];
	contact you;
	you.setId(book.getNum()+1);
	for(int i=1;i<7;i++){
		while(true){
			cout<<"("<<contactItem_zh[i]<<"?) ";
			getline(cin,item[i]);
			if(item[i][0]=='#'){
				cout<<"取消添加联系人.\n";
				return ;
			}
			if(you.set(i,item[i]))break;
			else cout<<contactItem_zh[i]<<"的输入格式错误,请重新输入.\n";
		}
	}
	book.add(you);
	cout<<"添加联系人成功.\n";
}

inline void app::list_(){
	if(book.size()>0){
		int cnt=book.list();
		cout<<"\n\n(共 "<<cnt<<" 位联系人)\n";
	}else{
		cout<<"没有联系人.\n";
	}
}

inline void app::import_(){
	cout<<"请输入导入文件名:";
	string path;
	getline(cin,path);
	if(!regex_match(path,regex("^.*\\.csv$"))){
		path+=".csv";
	}
	if(book.size()){
		cout<<"导入联系人将会和已有联系人合并.\n";
	}
	int cnt=book.importFromCSV(path.c_str());
	if(cnt)cout<<"已导入"<<cnt<<"位联系人,";
	cout<<"目前共有"<<book.size()<<"位联系人.\n";
}

inline void app::export_(){
	cout<<"请输入导出文件名:";
	string path;
	getline(cin,path);
	if(!regex_match(path,regex("^.*\\.csv$"))){
		path+=".csv";
	}
	bool flag=book.exportToCSV(path.c_str());
	if(flag){
		cout<<"导出联系人成功.\n";
	}else{
		cout<<"导出联系人失败.\n";
	}
}

inline void app::config_(){
}

