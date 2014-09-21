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
	return "";
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
	int fBeg=-1;
	int fEnd;

	while(true)
	{
		bool flag = false;	//老规矩，为了结束循环

		fBeg = text.find("times");
		if(string::npos != fBeg)
		{
			int fBeg2 = fBeg + 6;
			fEnd = text.find(" ",fBeg2);
			strstream ss;
			ss<<text.substr(fBeg2,fEnd-fBeg2);
			ss>>this->times;
			text.erase(fBeg,fEnd-fBeg);
			flag = true;
		}

		fBeg = text.find("format");
		if(string::npos != fBeg)
		{
			int fBeg2 = text.find("\"",fBeg);
			fEnd = text.find("\"",fBeg2+1); 
			string tmp ;
			tmp = text.substr(fBeg2+1,fEnd-fBeg2-1);
			this->format = judgeType(tmp);
			text.erase(fBeg,fEnd-fBeg);
			flag = true;
		}
		if(flag == false)
		break;
	}

	//读取 body 部分
	fBeg = text.find(">");
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

	return true;
}


bool MarkREPEAT::getValue()
{
	return true;
}