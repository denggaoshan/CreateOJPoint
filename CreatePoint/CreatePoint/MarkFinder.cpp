#include "MarkFinder.h"
#include "MarkINT.h"
#include "MarkREPEAT.h"

MarkFinder::MarkFinder()
{
}

MarkType MarkFinder::findOneMark(string text,int &begin,int& end)
{
	
	begin = text.find("<REPEAT");
	if (string::npos != begin)
	{
		end = text.find("</REPEAT>",begin) + 9; 
		return MARK_REPEAT;
	}

	begin = text.find("<INT");
	if (string::npos != begin)
	{
		end = text.find("</INT>",begin) + 6;
		return MARK_INT;
	}

	begin = text.find("<BR>");
	if(string::npos != begin)
	{
		end = text.find("</BR>") + 5;
		return MARK_BR;
	}

	return MARK_ERROR;
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
		break;
	default:
		break;
	}

	return ret;
}