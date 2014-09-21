/* 换行标签 */

#include "Mark.h"
#include <string>

using namespace std;

class MarkBR:public Mark
{

public:
	MarkBR();
	MarkBR(string text);	//自动译解文本

	virtual string toString();
};