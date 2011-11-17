#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <typename elemtype>
elemtype doConv(elemtype& sig1, elemtype& sig2){
	
	int size1 = sig1.size(); 	//cout<<sig1.size()<<endl;
	int size2 = sig2.size(); 	//cout<<sig1.size()<<endl;
	
	if(size1>size2){			// Swap sig1 and sig2
		elemtype temp;
		temp = sig1;
		sig1 = sig2;
		sig2 = temp;		
	}
	size1 = sig1.size();
	size2 = sig2.size();
	cout<<size1<<endl;
	cout<<size2<<endl;
	// Zero-pad Sig2:
	vector<int>::iterator itr_sig2 = sig2.end();
	sig2.insert(itr_sig2, size1 - 1, 0);
	itr_sig2 = sig2.begin();
	sig2.insert(itr_sig2, size1 - 1, 0);
	
	printSignal(sig1);
	// Initialise reverse iterator for filter
	vector<int>::reverse_iterator ritr_sig1 = sig1.rbegin();
	int n, indx, sum = 0;						//Time index
	elemtype calc (size1 +size2 -1);
	for(n = 0; n < size1+size2-1; n++){
		sum = 0;

		for(indx = 0; indx < size1; indx++){
			sum += (*( itr_sig2 + indx )) * ( *( ritr_sig1 + indx ));
			cout<< *( itr_sig2 + indx ) << ' '<< *( ritr_sig1 + indx )<<endl;
			
		}
		
		++itr_sig2;
		calc[n] = sum;
	}
	return calc;
}

template <typename prnt_type>
void printSignal(prnt_type var){
	int indx;
	for(indx = 0; indx < var.size(); indx++){
		cout<<var[indx]<<' ';
	}
	cout<<endl;
}

int main (int argc, char const* argv[])
{
	int i1 = 2, i2 = 3;
	vector <int> res;
	vector <int> ivec1;
	vector <int> ivec2;
	ifstream in1("sig1.txt");
	ifstream in2("sig2.txt");
	
	if(!in1 || !in2){
		cout<<"Error: File not found"<<endl;
	}
	int indata;
	while(in1>>indata){
		ivec1.push_back( indata);
	}
	while(in2>>indata){
		ivec2.push_back( indata);
	}
	printSignal(ivec1);
	printSignal(ivec2);

	
	res = doConv(ivec1, ivec2);
	printSignal(ivec1);
	printSignal(ivec2);
	printSignal(res);
	return 0;
}

