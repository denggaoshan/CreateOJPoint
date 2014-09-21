#include "MarkINT.h"
#include <time.h>
#include <strstream>

MarkINT::MarkINT()
{
	from = 0;
	to = 10000;
	name = "";
}

MarkINT::MarkINT(string text)
{
	from = 0;
	to = 10000;
	name = "";
	trans(text);
}

string MarkINT::toString()
{
	getValue();
	return ret;
}


//试图解析这个标签 成功返回true
bool MarkINT::trans(string text)
{
	
	int fBeg = text.find(">");
	if(string::npos == fBeg)
		return false;
	
	int fEnd = text.find("<",fBeg+1);

	if(fBeg+1 != fEnd) //有给变量取名字的话
	this->name = text.substr(fBeg+1,fEnd-fBeg-1);

	strstream ss;

	while(true)
	{
		int flag = false; //检测下这一次搜索有没有搜索到东西

		fBeg = text.find("<FROM>");
		if(string::npos != fBeg)
		{
			int fBeg2 = fBeg + 6;
			fEnd = text.find("<",fBeg2);
			ss<<text.substr(fBeg2,fEnd-fBeg2);
			ss>>this->from;
			text.erase(fBeg,fEnd-fBeg);
			
			flag=true;
		}

		ss.clear();
		fBeg = text.find("<TO>");
		if(string::npos != fBeg)
		{
			int fBeg2 = fBeg + 4;
			fEnd = text.find("<",fBeg2);
			ss<<text.substr(fBeg2,fEnd-fBeg2);
			ss>>this->to;
			text.erase(fBeg,fEnd-fBeg);

			flag=true;
		}

		if(flag == false )
			break;
	}
	return true;
}

bool MarkINT::getValue()
{
	int range = to - from + 1 ;
	int rad = rand()%range;
	int val = from + rad;

	strstream ss;
	ss<<val;
	ss>>ret;

	return true;
}



