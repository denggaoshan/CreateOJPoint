/* �ո��ǩ*/

#include "Mark.h"
#include <string>

using namespace std;

class MarkBK:public Mark
{

public:
	MarkBK();
	MarkBK(string text);	//�Զ�����ı�

	virtual string toString();
};