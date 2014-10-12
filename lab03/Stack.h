#ifndef STACK_H
#define STACK_H


class Stack
{
    private:
        char* arr;
        char* top;
        int siz;
        char *instr;
        char ch;
        char *outstr;
        int start;
        int end;
        char *rpn;
        char *exp;
        char *err;
        int *errpos;

    public:
        Stack(int );
        Stack(const Stack& s);
        ~Stack();
        int constParser(char *instr, char *outstr, int start, int end);
        int isOper(char );
        int isOBkt(char );
        int isCBkt(char );
        int priority(char );
        int verify(char *exp, char *err, int *errpos);
        void toRPN(char *exp, char *rpn);
};

#endif // STACK_H
