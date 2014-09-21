/* 空格标签*/

#include "Mark.h"
#include <string>

using namespace std;

class MarkBK:public Mark
{

public:
	MarkBK();
	MarkBK(string text);	//自动译解文本

	virtual string toString();
};