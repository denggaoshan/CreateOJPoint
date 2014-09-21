#pragma once
#include <string>
#include "Mark.h"

using namespace std;

//����֮��ĸ�ʽ
enum Format{SPACE,		//ÿ2��֮���һ���ո�
			NEWLINE,	//ÿ2��֮���һ������
			CONTINUOUS	//ÿ�����ݶ���������
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
	bool getValue();

	Format judgeType(string type);
};