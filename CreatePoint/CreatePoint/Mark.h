#pragma once
/*��ǩ��*/

#include <string>

using namespace std;

class Mark
{

protected:
	string origin;	//ԭʼ���ı�
	string ret;		//�����Ժ���ı�

public:
	virtual string toString();
};