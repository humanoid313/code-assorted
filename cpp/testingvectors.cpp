#include <iostream>
#include <vector>

using namespace std;
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
	vector <int> ivec1;
	int i;
	for(i=0; i<5; i++) 
		ivec1.push_back(i);
	cout<<"Given:"<<endl;
	printSignal(ivec1);
	vector <int> &rvec1 = ivec1;
	cout<<"Reference:"<<endl;
	printSignal(rvec1);
	vector <int> ivec2;
	ivec2 = rvec1;
	cout<<"Copy"<<endl;
	printSignal(ivec2);
	ivec2[2] = 100;
	cout<<"Given:"<<endl;
	printSignal(ivec1);
	cout<<"Copy"<<endl;
	printSignal(ivec2);		
	
	// Testing iterators:
	vector<int>::iterator itr = ivec1.begin();
	ivec1.insert(itr, 4, 444);
	itr = ivec1.end();
	ivec1.insert(itr, 4, 555);
	cout<<"After adding:"<<endl;
	printSignal(ivec1);
	return 0;
}
