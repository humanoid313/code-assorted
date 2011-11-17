#include<iostream>

using namespace std;

class Base
{
public:
    virtual int fun()
    {
        cout<<"Base::fun() called";
    }
    virtual int fun(int i)
    {
        cout<<"Base::fun(int i) called";
    }
};

class Derived: public Base
{
public:
    virtual int fun()
    {
        cout<<"Derived::fun() called";
    }
};

int main()
{
    Base *bptr;
    bptr = new Derived();
    bptr->fun(2.0);
    bptr->fun();
}
