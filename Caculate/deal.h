#ifndef DEAL_H
#define DEAL_H


class deal
{
public:
    deal();
    virtual int dealIt(int N1,int N2) = 0;
};

class plus : public deal
{
    int dealIt(int N1, int N2){return N1+N2;}
};

class decrease : public deal
{
    int dealIt(int N1, int N2){return N1-N2;}
};
class multiply : public deal
{
    int dealIt(int N1, int N2){return N1*N2;}
};
class devison : public deal
{
    int dealIt(int N1, int N2){return N1/N2;}
};
enum OR{
    PL,
    DE,
    ML,
    DS
};
class factory
{
public:
    factory() {}
    deal *doperator(OR tr)
    {
        switch(tr)
        {
        case PL:
            return new plus();
            break;
        case DE:
            return new decrease();
            break;
        case ML:
            return new multiply();
            break;
        case DS:
            return new devison();
            break;
        default:
            return nullptr;
            break;
        }
    }
};
#endif // DEAL_H
