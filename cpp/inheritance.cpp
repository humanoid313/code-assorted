#include <iostream>

using namespace std;

class Base{
    public:
        virtual int test(){
            cout<<"In Base"<<endl;
        }
};

class Derived: public Base{
    public:
        virtual int test(){
            cout<<"In derived"<<endl;
        }
};

int main(){
    Base *b = new Derived();
    b->test();
	return 0;
}
