#pragma once
#include <string>
#include "Mark.h"

using namespace std;

class MarkINT:public Mark
{
	string name;
	int	from;
	int to;

public:
	MarkINT();
	MarkINT(string text);	//�Զ�����ı�

	virtual string toString();

private:
	bool getValue();
	bool trans(string text);//����INT��ǩ
};