#include "Derived.h"
#include "Stack.h"
#include "Implementation.h"


void Derived::show(char *a, char *b)
        {
            toRPN(a, b);
            sh(a, b);
        }

void Derived::sh(char *a, char *b)
        {
            cout<<"RPN: "<<b<<endl;
        }
