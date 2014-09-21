/*
* 这个类用来解析一个标签
*/
#include <string>

#include "Mark.h"

using namespace std;

enum MarkType
{
	MARK_ERROR,	//无此标签或者寻找时出错

	MARK_REPEAT, //POINT标签
	MARK_INT,	//INT标签
	
	MARK_BR,	//换号标签
	MARK_BK 	//空格标签
};

class MarkFinder
{
public:
	MarkFinder();
	/*从一个字符串中找出第一个标签，返回标签的种类,以及在原来字符串中的首末位置*/
	static MarkType findOneMark(string text,int &begin,int& end);	
	
	/*根据类型创建一个Mark对象*/
	static Mark* createMarkByType(MarkType type,string text);
	
};