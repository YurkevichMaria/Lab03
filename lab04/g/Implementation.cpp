#include "Implementation.h"

#define MAX_BUFFER 1024

Implementation::Implementation()
        {
            arr = 0;
        }

Implementation::Implementation(int s = 10)
        {
            this->siz = s;
            arr = new char[s];
            top = arr;
        }

Implementation::Implementation(const Implementation& s)
        {
            this->siz = s.siz;
            this->arr = new char[s.siz];
            this->top = arr;
            char* p = s.arr;
            while (p < s.top)
            {
                *top++ = *p++;
            }
        }

Implementation::~Implementation()
        {
            delete[] arr;
        }


int Implementation::constParser(char *instr, char *outstr, int start, int end)
        {
            int ret;
            int i, j, k;

            k = 0;
            ret = 0;

            if (instr[start] == '_')
            {
                outstr[k++] = '-';
            }
            else
            {
                if (instr[start] == '=')
                {
                    start++;
                    ret = 1;
                }
            }

            for (i = k, j = k; i < end - start + 1; i++)
                outstr[j++] = instr[i + start];

            return ret;
        }

int Implementation::isOper(char ch)
        {
            if (ch == '+' ||
                ch == '-' ||
                ch == '*' ||
                ch == '/' ||
                ch == '^')
                return 1;

            return 0;
        }

int Implementation::isOBkt(char ch)
        {
            if (ch == '(')
                return 1;

            return 0;
        }

int Implementation::isCBkt(char ch)
        {
            if (ch == ')')
                return 1;

            return 0;
        }

int Implementation::priority(char ch)
        {
            if (ch == '^')
            {
                return 4;
            }
            else
            {
                if (ch == '*' || ch == '/')
                {
                    return 3;
                }
                else
                {
                    if (ch == '+' || ch == '-')
                    {
                        return 2;
                    }
                    else
                    {
                        if (ch == '(')
                            return 1;
                    }
                }
            }

            return 0;
        }


void Implementation::toRPN(char *exp, char *rpn)
        {
            int p;
            int k, l;
            int i;

            char stack[MAX_BUFFER];
            int top;

            char temp[32];

            for (k = 0, p = 0, top = -1; k < strlen(exp); k++)
            {
                if (isdigit(exp[k]) != 0 || exp[k] == '_' || exp[k] == '=')
                {
                    l = k;

                    while (isdigit(exp[l + 1]) != 0 || exp[l + 1] == '.')
                        l++;

                    if (constParser(exp, temp, k, l) == 1)
                        k++;

                    for (i = 0; i < l - k + 1; i++)
                        rpn[p++] = temp[i];

                    rpn[p++] = ' ';

                    k = l;
                }
                else
                {
                    if (isOper(exp[k]) != 0)
                    {
                        if (exp[k] == '^')
                        {
                            if (top == -1 || priority(stack[top]) <= priority(exp[k]))
                            {
                                stack[++top] = exp[k];
                            }
                            else
                            {
                                while (priority(stack[top]) > priority(exp[k]) && top != -1)
                                {
                                    rpn[p++] = stack[top--];
                                    rpn[p++] = ' ';
                                }

                                stack[++top] = exp[k];
                            }
                        }
                        else
                        {
                            if (top == -1 || priority(stack[top]) < priority(exp[k]))
                            {
                                stack[++top] = exp[k];
                            }
                            else
                            {
                                while (priority(stack[top]) >= priority(exp[k]) && top != -1)
                                {
                                    rpn[p++] = stack[top--];
                                    rpn[p++] = ' ';
                                }

                                stack[++top] = exp[k];
                            }
                        }
                    }
                    else
                    {
                        if (isOBkt(exp[k]) != 0)
                        {
                            stack[++top] = exp[k];
                        }
                        else
                        {
                            if (isCBkt(exp[k]) != 0)
                            {
                                while (priority(stack[top]) != 1)
                                {
                                    rpn[p++] = stack[top--];
                                    rpn[p++] = ' ';
                                }

                                top--;
                            }
                        }
                    }
                }
            }

            while (top != -1)
            {
                rpn[p++] = stack[top--];
                rpn[p++] = ' ';
            }

            rpn[--p] = '\0';
        }
