#include "wComparer.h"

int wGetNumber(wchar_t **pointer)
{
    int z = 1;
    int number = 0;

    while (**pointer != 0 && iswdigit(**pointer))
    {
        number = z * number + (**pointer - 48);
        (*pointer)++;
        z *= 10;
    }
    return number;
}

int wCompare(wstring x, wstring y)
{
    auto xPointer = &x[0];
    auto yPointer = &y[0];
    auto xEndPointer = &x[x.length() - 1];
    auto yEndPointer = &y[y.length() - 1];

    while (*xPointer != 0)
    {
        if (yPointer == 0)
            return 1;
        if (iswdigit(*xPointer) && iswdigit(*yPointer))
        {
                auto xNum = wGetNumber(&xPointer);
                auto yNum = wGetNumber(&yPointer);
                if (xNum != yNum)
                    return xNum > yNum ? 1 : -1;
        }
        if (*xPointer != *yPointer)
            return *xPointer > *yPointer ? 1 : -1;
        yPointer++;
        xPointer++;
    }
    return yPointer == 0 ? 0 : -1;
}