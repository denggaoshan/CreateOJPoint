/* ���б�ǩ */

#include "Mark.h"
#include <string>

using namespace std;

class MarkBR:public Mark
{

public:
	MarkBR();
	MarkBR(string text);	//�Զ�����ı�

	virtual string toString();
};