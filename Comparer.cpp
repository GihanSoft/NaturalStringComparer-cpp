#include "Comparer.h"

int GetNumber(char **pointer, char *endPointer)
{
    int z = 1;
    int number = 0;
    for (; *pointer <= endPointer && isdigit(**pointer); z *= 10)
    {
        number = z * number + (**pointer - 48);
        (*pointer)++;
    }
    return number;
}

int Compare(string x, string y)
{
    auto xPointer = &x[0];
    auto yPointer = &y[0];
    auto xEndPointer = &x[x.length() - 1];
    auto yEndPointer = &y[y.length() - 1];

    while (xPointer <= xEndPointer)
    {
        if (yPointer > yEndPointer)
            return 1;
        if (isdigit(*xPointer) && isdigit(*yPointer))
        {
                auto xNum = GetNumber(&xPointer, xEndPointer);
                auto yNum = GetNumber(&yPointer, yEndPointer);
                if (xNum != yNum)
                    return xNum > yNum ? 1 : -1;
        }
        if (*xPointer != *yPointer)
            return *xPointer > *yPointer ? 1 : -1;
        yPointer++;
        xPointer++;
    }
    return yPointer > yEndPointer ? 0 : -1;
}