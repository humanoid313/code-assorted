#include <iostream>
// What gets printed by cout<<cout and why?
// Answer: http://stackoverflow.com/questions/7489069/whats-the-difference-between-coutcout-and-coutcout-in-c
//cout << cout is equivalent to cout << cout.operator void *(). This is the idiom used before C++11 to determine if an iostream is in a failure state, and is implemented in std::ios_base; it usually returns the address of static_cast<std::ios_base *>(&cout). 

//cout << &cout prints out the address of cout.

//Since std::ios_base is a virtual base class of cout, it may not necessarily be contiguous with cout. That is why it prints a different address.
// More about void *(): http://www.cplusplus.com/reference/iostream/ios/operator_voidpt/

using namespace std;
void fun(){
    int a = 0;
    char d = 0;
}
class test{
    public:
        void t(void);
};
int main(){
    test T;
    cout<<cout<<endl;
    cout<<&cout<<endl;
    cout<<fun<<endl;
    cout<<&fun<<endl;
	return 0;
}
