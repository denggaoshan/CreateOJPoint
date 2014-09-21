#include "MarkREPEAT.h"
#include "MarkFinder.h"
#include <strstream>

#define FORMATSIZE 3

string strFormat[FORMATSIZE]={"space","newline","continuous"};

MarkREPEAT::MarkREPEAT()
{
	this->times = 1;
	this->format = SPACE;
}

MarkREPEAT::MarkREPEAT(string text)
{
	this->times = 1;
	this->format = SPACE;
	trans(text);
}


string MarkREPEAT::toString()
{
	return ret;
}

Format MarkREPEAT::judgeType(string type)
{
	for(int i=0;i<FORMATSIZE;i++)
	{
		if(strFormat[i]==type)
		{
			return (Format)i;
		}
	}
}

bool MarkREPEAT::trans(string text)
{
	int fBeg=0;
	int fEnd;

	string head ;//解析它的头部的属性

	fEnd = text.find(">");
	head = text.substr(fBeg,fEnd-fBeg+1);

	text.erase(fBeg,fEnd-fBeg+1);

	while(true)
	{
		bool flag = false;	//老规矩，为了结束循环

		fBeg = head.find("times");
		if(string::npos != fBeg)
		{
			int fBeg2 = fBeg + 6;
			fEnd = head.find(" ",fBeg2);
			strstream ss;
			ss<<head.substr(fBeg2,fEnd-fBeg2);
			ss>>this->times;
			head.erase(fBeg,fEnd-fBeg);
			flag = true;
		}

		fBeg = head.find("format");
		if(string::npos != fBeg)
		{
			int fBeg2 = head.find("\"",fBeg);
			fEnd = head.find("\"",fBeg2+1); 
			string tmp ;
			tmp = head.substr(fBeg2+1,fEnd-fBeg2-1);
			this->format = judgeType(tmp);
			head.erase(fBeg,fEnd-fBeg);
			flag = true;
		}
		if(flag == false)
		break;
	}

	//读取 body 部分
/*	fBeg = text.find(">");
	fEnd = text.find("</REPEAT>");
	string tmpbody = text.substr(fBeg+1,fEnd-fBeg-1);
	
	while(true)
	{
		bool flag = false;
		fBeg = tmpbody.find('\n');
		if(string::npos != fBeg)
		{
			tmpbody.erase(fBeg,1);
			flag = true;
		}
		fBeg = tmpbody.find('\t');
		if(string::npos != fBeg)
		{
			tmpbody.erase(fBeg,1);
			flag = true;
		}
		if(flag == false)
			break;
	}
	this->body = tmpbody;
*/
	ret += getValue(text);

	return true;
}

string MarkREPEAT::getFormatString()
{
	if(format == Format::SPACE)
	{
		return " ";
	}
	if(format == Format::NEWLINE)
	{
		return "\n";
	}
	return "";
}


string MarkREPEAT::getValue(string body)
{
	string str = "";
	MarkType type;
	bool flag=false; //保证输出格式正确

	int timetmp = times;

	while(timetmp--)
	{
		int begin,end;
		
		if(flag == true)
		{
				str.append(getFormatString());
		}
		flag = true;

		string bodytmp = body;

		while(type = MarkFinder::findOneMark(bodytmp,begin,end))
		{
			if(type == MarkType::MARK_ERROR)
				break;
			Mark *mark;
			mark = MarkFinder::createMarkByType(type,bodytmp.substr(begin,end-begin));
			string strtmp = mark->toString();
			str += strtmp;
			bodytmp.erase(begin,end-begin);
		}
	}
	return str;
}

