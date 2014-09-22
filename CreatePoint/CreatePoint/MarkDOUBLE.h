#include "Mark.h"


class MarkDOUBLE:public Mark
{

public:
	MarkDOUBLE();
	MarkDOUBLE(string text);

	string toString();

private:
	string name;
	double from;
	double to;
	int precision;

	bool trans(string text);
	bool getValue();
};