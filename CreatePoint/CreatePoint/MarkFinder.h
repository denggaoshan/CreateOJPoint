/*
* �������������һ����ǩ
*/
#include <string>

#include "Mark.h"

using namespace std;

enum MarkType
{
	MARK_ERROR,	//�޴˱�ǩ����Ѱ��ʱ����

	MARK_REPEAT, //POINT��ǩ
	MARK_INT,	//INT��ǩ
	
	MARK_BR,	//���ű�ǩ
	MARK_BK 	//�ո��ǩ
};

class MarkFinder
{
public:
	MarkFinder();
	/*��һ���ַ������ҳ���һ����ǩ�����ر�ǩ������,�Լ���ԭ���ַ����е���ĩλ��*/
	static MarkType findOneMark(string text,int &begin,int& end);	
	
	/*�������ʹ���һ��Mark����*/
	static Mark* createMarkByType(MarkType type,string text);
	
};