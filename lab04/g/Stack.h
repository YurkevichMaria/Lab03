#ifndef STACK_H
#define STACK_H


class Stack
{
    private:
        class Implementation *pimpl;
     public:
        Stack();
        Stack(const Stack& s);
        ~Stack();
        void toRPN(char *exp, char *rpn);
};

#endif // STACK_H
