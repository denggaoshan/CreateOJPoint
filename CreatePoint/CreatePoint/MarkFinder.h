/*
* �������������һ����ǩ
*/

#include <string>

using namespace std;

enum MarkType
{
	MARK_ERROR,	//�޴˱�ǩ����Ѱ��ʱ����

	MARK_POINT, //POINT��ǩ
	MARK_INT,	//INT��ǩ
	
	MARK_BR		//���ű�ǩ
};

class MarkFinder
{
public:
	MarkFinder();
	/*��һ���ַ������ҳ���һ����ǩ�����ر�ǩ������,�Լ���ԭ���ַ����е���ĩλ��*/
	static MarkType findOneMark(string text,int &begin,int& end);	
	
};