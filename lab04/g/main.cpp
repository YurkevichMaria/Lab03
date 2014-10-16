#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

#define MAX_BUFFER 1024

int main(int argc, char **argv)
{
    PrettyDerived stak;
    char a[MAX_BUFFER];
    char b[MAX_BUFFER];

    while (1)
    {
        cout<<"Enter an expression: ";
        cin>>a;

        if (a[0] == '\n')
            break;

        cout<<"Simplified expression: "<< a<<endl;
        stak.show(a, b);
        cout<<endl<<endl;
    }

    return 0;
}
