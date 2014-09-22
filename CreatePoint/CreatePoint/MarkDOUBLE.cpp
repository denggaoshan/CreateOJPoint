#include "MarkDOUBLE.h"

#include <strstream>
#include <iomanip>

MarkDOUBLE::MarkDOUBLE()
{
}


MarkDOUBLE::MarkDOUBLE(string text)
{
	this->origin = text;
	this->from = 0.0;
	this->to = 100.0;
	this->precision = 5;
	trans(text);
}

bool MarkDOUBLE::trans(string text)
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
		bool flag = false; //检测下这一次搜索有没有搜索到东西

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

		ss.clear();
		fBeg = text.find("<PRECISION>");
		if(string::npos != fBeg)
		{
			int fBeg2 = fBeg + 11;
			fEnd = text.find("<",fBeg2);
			string tmp =text.substr(fBeg2,fEnd-fBeg2);
			int tmp2;
			ss<<text.substr(fBeg2,fEnd-fBeg2);
			ss>>tmp2;
			this->precision = tmp2 ;
			text.erase(fBeg,fEnd-fBeg);
			
			flag=true;
		}


		if(flag == false )
			break;
	}
	return true;

}
	
bool MarkDOUBLE::getValue()
{
	double range = to - from ;
	double temp = (double)rand()/RAND_MAX ;
	temp = temp * range;
	double val = from + temp;

	strstream ss;
	ss<<std::fixed;
	ss<<setprecision(this->precision);
	ss<<val;
	ss>>this->ret;

	return true;
}


string MarkDOUBLE::toString()
{
	getValue();
	return ret;
}