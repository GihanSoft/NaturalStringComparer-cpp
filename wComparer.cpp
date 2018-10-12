#include "wComparer.h"

int wGetNumber(wchar_t **pointer, wchar_t *endPointer)
{
    int z = 1;
    int number = 0;
    for (; *pointer <= endPointer && iswdigit(**pointer); z *= 10)
    {
        number = z * number + (**pointer - 48);
        (*pointer)++;
    }
    return number;
}

int wCompare(wstring x, wstring y)
{
    auto xPointer = &x[0];
    auto yPointer = &y[0];
    auto xEndPointer = &x[x.length() - 1];
    auto yEndPointer = &y[y.length() - 1];

    while (xPointer <= xEndPointer)
    {
        if (yPointer > yEndPointer)
            return 1;
        if (iswdigit(*xPointer))
        {
            if (iswdigit(*yPointer))
            {
                auto xNum = wGetNumber(&xPointer, xEndPointer);
                auto yNum = wGetNumber(&yPointer, yEndPointer);
                if (xNum != yNum)
                    return xNum > yNum ? 1 : -1;
            }
        }
        if (*xPointer != *yPointer)
            return *xPointer > *yPointer ? 1 : -1;
        yPointer++;
        xPointer++;
    }
    return yPointer > yEndPointer ? 0 : -1;
}