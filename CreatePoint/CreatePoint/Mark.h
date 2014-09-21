#pragma once
/*标签类*/

#include <string>

using namespace std;

class Mark
{

protected:
	string origin;	//原始的文本
	string ret;		//解释以后的文本

public:
	virtual string toString();
};