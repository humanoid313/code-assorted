#include <iostream>
#include <set>

using namespace std;

class SquareDigits{
    public:
        int smallestResult(int param0);
        int sumofsquares(int n);
        bool srhelper(int guess, int n);
};

inline int SquareDigits::sumofsquares(int n){
    int x, mplier = 10, sumofsquares=0;
    while(n){
        x = n%10;
        n = n/10;
        sumofsquares += x*x;
    }
    return sumofsquares;
}

bool SquareDigits::srhelper(int guess, int n){
    set <int> t;
    set <int>::iterator it;

    while(1){
        guess = sumofsquares(guess);
        it = t.find(guess);
        if (it == t.end()){ // Not in list
            t.insert(guess);
        }
        else{
            break;
        }
    }
    return (t.find(n) == t.end())?false:true;
}

int SquareDigits::smallestResult(int n){
    int x=0;
    while((!srhelper(x,n)) && (x >= 0)){
        cout<<"Now testing :"<<x<<endl;
        x++;
    }
    return x;
}


int main(){
    SquareDigits sq;
    int res = sq.smallestResult(4);
    cout<<res<<endl;
	return 0;
}
