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
	MarkINT(string text);	//自动译解文本

	virtual string toString();

private:
	bool getValue();
	bool trans(string text);//解释INT标签
};