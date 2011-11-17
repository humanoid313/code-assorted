#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main (int argc, char const* argv[])
{
	int a[] = {1, 12, 30, 41, 56, 67, 73, 91, 108};
	int count = 9;
	bool found = false;
	int start = 0, end = count -1;
	int desired = 72;
	int steps = 0;
	
	for(start = 0, end = count-1; start<end;steps++){
		if((a[start]+a[end]) == desired){
			found = true;
			break;
		}
		else if ((a[start] + a[end]) < desired){
			start++;
		}
		else{
			end--;
		}
		
	}
	if (found){
		cout<<"Found : "<<a[start]<<" "<<a[end]<<endl;
	}
	else{
		cout<<"Not found"<<" "<<steps<<endl;
	}
	return 0;
}
