#include <iostream>
#define TESTVAL 1

using namespace std;
#ifdef DEBUG
int main(){
    cout<<"Place 1"<<endl;
	return 0;
}
#endif
#ifndef DEBUG
int main(){
    cout<<"PLace 2"<<endl;
	return 0;
}
#endif

#ifdef TESTVAL == 1
#elif TESTVAL == 2
#else
#endif
