#include "Comparer.h"

int GetNumber(char** pointer)
{
	int z = 1;
	int number = 0;
	while (**pointer != 0 && isdigit(**pointer))
	{
		number = z * number + (**pointer - 48);
		(*pointer)++;
		z *= 10;
	}
	return number;
}

int Compare(string x, string y)
{
	auto xPointer = &x[0];
	auto yPointer = &y[0];

	while (*xPointer != 0)
	{
		if (*yPointer == 0)
			return 1;
		if (isdigit(*xPointer) && isdigit(*yPointer))
		{
			auto xNum = GetNumber(&xPointer);
			auto yNum = GetNumber(&yPointer);
			if (xNum != yNum)
				return xNum > yNum ? 1 : -1;
		}
		if (*xPointer != *yPointer)
			return *xPointer > * yPointer ? 1 : -1;
		yPointer++;
		xPointer++;
	}
	return yPointer == 0 ? 0 : -1;
}

int Compare(char* x, char* y)
{
	return Compare(string(x), string(y));
}
