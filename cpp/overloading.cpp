#include <iostream>

using namespace std;

class Test1 {
    int y;
};

class Test2 {
    int x;
    Test1 t1;
public:
    operator Test1() { return t1; }
    operator int() { return x; }
};

void fun ( int x)  { cout<<&x<<" "<<x<<endl;};
//void fun ( Test1 t ) { };
/* Compiler error:
    when called as fun(t) two steps take place : Test2 object t is implicitly
     cast to return a Test1 object, hence matching the second signature.
     Integer casting is also possible and thus first function call matches
*/


int main() {
    Test2 t;
    fun(t);
    return 0;
}



/* Clearer example from IBM:

The compiler can use only one user-defined conversion (either a conversion
constructor or a conversion function) when implicitly converting a single
value. The following example demonstrates this:

class A {
  int x;
public:
  operator int() { return x; };
};

class B {
  A y;
public:
  operator A() { return y; };
};

int main () {
  B b_obj;
//  int i = b_obj;
  int j = A(b_obj);
}

The compiler would not allow the statement int i = b_obj. The compiler would
have to implicitly convert b_obj into an object of type A (with B::operator
A()), then implicitly convert that object to an integer
(with A::operator int()). The statement int j = A(b_obj) explicitly converts
b_obj into an object of type A, then implicitly converts that object to an integer.
*/
