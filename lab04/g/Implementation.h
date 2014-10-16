#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H


class Implementation
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
    public:
        Implementation();
        Implementation(int );
        Implementation(const Implementation& s);
        ~Implementation();
        int constParser(char *instr, char *outstr, int start, int end);
        int isOper(char );
        int isOBkt(char );
        int isCBkt(char );
        int priority(char );
        void toRPN(char *exp, char *rpn);

};

#endif // IMPLEMENTATION_H
