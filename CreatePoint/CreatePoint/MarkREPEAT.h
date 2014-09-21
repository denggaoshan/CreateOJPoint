#pragma once
#include <string>
#include "Mark.h"

using namespace std;

//数据之间的格式
enum Format{SPACE,		//每2个之间夹一个空格
			NEWLINE,	//每2个之间夹一个换行
			CONTINUOUS	//每个数据都是连续的
};


class MarkREPEAT:public Mark
{
public:
	MarkREPEAT();
	MarkREPEAT(string text);
	
	string toString();
private:

	int times;
	Format format;
	string body;

	bool trans(string text);
	string getValue(string body);

	Format judgeType(string type);
	string getFormatString();
};