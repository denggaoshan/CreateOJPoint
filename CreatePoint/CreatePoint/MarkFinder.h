/*
* 这个类用来解析一个标签
*/

#include <string>

using namespace std;

enum MarkType
{
	MARK_ERROR,	//无此标签或者寻找时出错

	MARK_POINT, //POINT标签
	MARK_INT,	//INT标签
	
	MARK_BR		//换号标签
};

class MarkFinder
{
public:
	MarkFinder();
	/*从一个字符串中找出第一个标签，返回标签的种类,以及在原来字符串中的首末位置*/
	static MarkType findOneMark(string text,int &begin,int& end);	
	
};