#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main (int argc, char const* argv[])
{
	ifstream in1("sig1.txt");
	int tdata;
	vector <int> ivec1;
	while( in1>>tdata ){
		ivec1.push_back(tdata);
	}
	for (vector<int>::iterator itr = ivec1.begin(); itr!=ivec1.end(); ++itr){
		cout<< *itr<< ' ';
	}
	cout<<endl;
	int i;
	for (vector<int>::reverse_iterator bitr = ivec1.rbegin(); bitr<ivec1.rend(); ++bitr){
		cout<< *bitr<< ' ';
	}
	cout<<endl;
	
	return 0;
}
