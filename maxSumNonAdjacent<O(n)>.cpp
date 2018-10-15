#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[4] ={3,2,7,10};
	int exc=0,inc=0;
	for(int i =0;i<4;i++)
	{
	    int temp = inc;
	    inc = exc + arr[i];
	    exc = temp>exc?temp:exc;    
	    }
	    
	    int max = exc>inc?exc:inc;
	    cout<<max;
	return 0;
}
