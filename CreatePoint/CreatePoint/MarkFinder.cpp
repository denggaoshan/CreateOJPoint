#include "MarkFinder.h"

MarkFinder::MarkFinder()
{
}

MarkType MarkFinder::findOneMark(string text,int &begin,int& end)
{
	int begin;
	
	begin = text.find("<POINT");
	if (begin != text.end)
	{
		end = text.find("</POINT>",begin) ;//TO DO
		return MARK_POINT;
	}

	begin = text.find("<INT");
	if (begin != text.end)
	{
		end = text.find("</INT>",begin);
		return MARK_INT;
	}

	begin = text.find("<BR>");
	if(begin != text.end)
	{
		end = text.find("</BR>");
		return MARK_BR;
	}

	return MARK_ERROR;
}