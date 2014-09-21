#include <iostream>
#include <fstream>
#include <time.h>
#include <strstream>

#include "MarkINT.h"
#include "MarkREPEAT.h"

int main()
{
	srand(time(0));
	fstream file;


	file.open("example.txt",ios::in);
	string text;

	while(true)
	{
		char ch = file.get();
		if(file.eof())
		{
			break;
		}
		if(ch=='\n'||ch=='\t')
			continue;
		text += ch;
	}
	

	MarkREPEAT mk(text);
	cout<<mk.toString();
	
}