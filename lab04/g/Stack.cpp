#include "Stack.h"
#include "Implementation.h"

Stack::Stack():
        pimpl(nullptr)
        {
           pimpl=new Implementation();
        }

Stack::Stack(const Stack &orig):
        pimpl(nullptr)
        {
            pimpl=new Implementation(*orig.pimpl);
        }

Stack::~Stack()
        {
            delete[] pimpl;
        }

void Stack::toRPN(char *exp, char *rpn)
        {
            pimpl->toRPN(exp, rpn);
        }
