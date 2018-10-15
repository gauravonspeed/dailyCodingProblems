#include <iostream>
using namespace std;

int arr[6] ={2,-1,6,2,5,15};
int maxSum1[6]={0,0,0,0,0,0};
int maxSum(int pos, int length)
{
    if(pos>= length)
        return 0;
    if(maxSum1[pos]!=0)
    return maxSum1[pos];
    
	int temp = pos;
    cout<<"pos="<<pos<<endl;
    int sum1 =0,sum2 =0;
    if(arr[temp]<=0)
    while(arr[temp]<=0 && temp<length-1)
        temp++;
    if(arr[temp]>0)
    sum1 =arr[temp]+maxSum(temp+2,length);

    sum2 = maxSum(temp+1,length);

    cout<<"sum1="<<sum1<<" and sum2 ="<<sum2<<endl;
    return maxSum1[pos]=sum1>sum2?sum1:sum2;
}

int main() {
	
	cout<<"max sum ="<<maxSum(0,6)<<endl;
	return 0;
}
