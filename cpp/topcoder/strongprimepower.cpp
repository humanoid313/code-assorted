#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

class StrongPrimePower{
    public:
        vector <int> baseAndExponent(string n);
        bool isPrime(double guess);
};

bool StrongPrimePower::isPrime(double guess){
    bool flag= true;
    double num;
    if(guess == 3.0){
        return true;
    }
    for(num = 3.0; num < sqrt(guess); num+= 2){
        if(fmod(guess, num) == 0.0){
            flag= false;
            return flag;
        }
    }
    return flag;
}

vector <int> StrongPrimePower::baseAndExponent(string n){
    vector <int> result;
    bitset <60> repr;
    double n0 = 0, n1 = 1, guess=2, fracpart;
    int len = n.length();
    int count;
    if (len > 18){
        cerr<<"Out of range: Range is 0:10^18"<<endl;
        return result;
    }
    for(int i = len-1; i >=0; i--){
        n0 += (n[i] - '0')*n1;
        n1*=10;
    }
    // test for divisibility by 2
    if (fmod(n0, 2) == 0.0){
        n1 = log2(n0);
        if((n1 - (int)(n1)) == 0.0){
            result.push_back(2);
            result.push_back((int)(n1));
        }
        return result;
    }
    // If odd check for prime powers
    for (guess=3; guess <= sqrt(n0); guess += 1){
        if (isPrime(guess)){
            n1 = n0; fracpart = 0.0; count = 1;
            while((fmod(n1,guess)== 0.0) && (fracpart == 0.0) && (n1 > guess) ){
                n1 /= guess;
                fracpart = modf(n1, &n1);
                count++;
            }
            if (n1 == guess){
                result.push_back(count);
                result.push_back((int) guess);
                return result;
            }
        }
    }

    return result;
}

int main(){
    StrongPrimePower spp;
    vector<int> result;
    result = spp.baseAndExponent("3721");
	if(!result.empty()){
        cout<<result[0]<<endl;
        cout<<result[1]<<endl;
	}
	return 0;
}
