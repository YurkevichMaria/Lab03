#ifndef DERIVED_H
#define DERIVED_H


class Derived: public Stack
{
    public:
        void show(char *a, char *b);
    private:
        virtual void sh(char *a, char *b);
};

#endif // DERIVED_H
