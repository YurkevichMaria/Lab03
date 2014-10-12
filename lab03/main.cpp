#include "Stack.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

#define MAX_BUFFER 1024

/*Реализовать стек на списках и с помощью его вычислить обрат-
ную польскую запись.*/

int main(int argc, char **argv)
{
    Stack stak;
    char exp[MAX_BUFFER];
    char rpn[MAX_BUFFER];
    char err[MAX_BUFFER];
    int errpos[MAX_BUFFER];
    int i;

    while (1)
    {
        cout<<"Enter an expression: ";
        cin>>exp;

        if (exp[0] == '\n')
            break;

       if (stak.verify(exp, err, errpos) != 0)
            for (i = 0; i < strlen(err); i++)
                printf("Invalid symbol \"%c\" at position %d\n.", err[i], errpos[i]);
        stak.toRPN(exp, rpn);
        cout<<"Simplified expression: "<< exp;
        cout<<"\nReverse Polish notation: "<< rpn;
        cout<<endl<<endl;
    }

    return 0;
}
