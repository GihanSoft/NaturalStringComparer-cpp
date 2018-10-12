#include <string>
#include <iostream>
#include "Comparer.h"
#include "wComparer.h"

using namespace std;

main(int argc, char const *argv[])
{
    bool isW = false;
    for(size_t i = 0; i < argc; i++)
    {
        if(argv[i]=="-w"||argv[i]=="-W")
        isW = true;
    }
if(isW){
    wstring x, y;
    wcin >> x >> y;
    cout << wCompare(x, y);
}
else{
    string x,y;
    cin >> x >> y;
    cout << Compare(x,y);
}
    return 0;
}