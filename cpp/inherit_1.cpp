#include <iostream>
using namespace std;
class P{
	public:
	int x ;
	P(){
		x = 1234;
	}
};

class C: public P{
	public:
	int y ;
	C(){
		x = 345;
		y =  789;	
	}
};
int main(){
	P* p;

	p = new C();
	cout<<	p->x  << endl;	// Outputs 345
//	cout<<	p->y  << endl; 	// Error: Pointer of type P doesn't contain the member y
	return 0;
}

/*
Notes:
Therefore, any code that manipulates the fields of a P object can manipulate the P fields inside the C object without
having to consider anything about the definition of C's fields.
*/
