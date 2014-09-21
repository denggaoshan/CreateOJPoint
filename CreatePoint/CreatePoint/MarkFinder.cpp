#include "MarkFinder.h"

#include "MarkINT.h"
#include "MarkREPEAT.h"
#include "MarkBK.h"
#include "MarkBR.h"

MarkFinder::MarkFinder()
{
}

MarkType MarkFinder::findOneMark(string text,int &begin,int& end)
{
	MarkType ret = MARK_ERROR ;

	int beginret = INT_MAX;  //为了找出第一个标签

	begin = text.find("<REPEAT");
	if (string::npos != begin)
	{
		if(begin < beginret)
		{
		ret = MARK_REPEAT;
		beginret = begin ;
		end = text.find("</REPEAT>",begin) + 9;
		}
	}

	begin = text.find("<INT");
	if (string::npos != begin)
	{
		if(begin < beginret)
		{
		ret =  MARK_INT;
		beginret = begin ;
		end = text.find("</INT>",begin) + 6;
		}
	}

	begin = text.find("<BR>");
	if(string::npos != begin)
	{
		if(begin < beginret)
		{
		ret = MARK_BR;
		beginret = begin ;
		end = begin + 4;
		}
	}

	begin = text.find("<BK>");
	if(string::npos != begin)
	{
		if(begin < beginret)
		{
		ret = MARK_BK;
		beginret = begin ;
		end = begin + 4;
		}
	}

	begin = beginret;
	
	return ret;
}

Mark* MarkFinder::createMarkByType(MarkType type,string text)
{
	Mark * ret = NULL;

	switch (type)
	{
	case MARK_ERROR:
		break;
	case MARK_REPEAT:
		ret = new MarkREPEAT(text);
		break;
	case MARK_INT:
		ret = new MarkINT(text);
		break;
	case MARK_BR:
		ret = new MarkBR(text);
		break;
	case MARK_BK:
		ret = new MarkBK(text);
	default:
		break;
	}

	return ret;
}