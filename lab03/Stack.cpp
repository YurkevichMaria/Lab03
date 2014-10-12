#include "Stack.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

#define MAX_BUFFER 1024

Stack::Stack(int s = 10)
        {
            this->siz = s;
            arr = new char[s];
            top = arr;
        }

Stack::Stack(const Stack& s)
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

Stack::~Stack()
        {
            delete[] arr;
        }

int Stack::constParser(char *instr, char *outstr, int start, int end)
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

int Stack::isOper(char ch)
        {
            if (ch == '+' ||
                ch == '-' ||
                ch == '*' ||
                ch == '/' ||
                ch == '^')
                return 1;

            return 0;
        }

int Stack::isOBkt(char ch)
        {
            if (ch == '(')
                return 1;

            return 0;
        }

int Stack::isCBkt(char ch)
        {
            if (ch == ')')
                return 1;

            return 0;
        }

int Stack::priority(char ch)
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

int Stack::verify(char *exp, char *err, int *errpos)
        {
            int key;
            int i, j;

            for (i = 0, j = 0, key = 0; i < strlen(exp) - 1; i++)
                if (exp[i] != ' ' && exp[i] != '.' &&
                    isOper(exp[i]) == 0 && isOBkt(exp[i]) == 0 &&
                    isCBkt(exp[i]) == 0 && isdigit(exp[i]) == 0)
                {
                    err[j] = exp[i];
                    errpos[j++] = i;
                    key = 1;
                }

            err[++j] = '\0';

            return key;
        }

void Stack::toRPN(char *exp, char *rpn)
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

