// Example program
#include <iostream>
#include <string>

int main()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  int* ans = new int[10];
  int left[10];
  int right[10];
  int p =1;
  for(int i =0;i<10;i++)
  {
      ans[i]=p;
      p *=a[i];
      }
      p =1;
  for(int i =9;i>=0;i--)
  {
      ans[i]*=p;
      p *=a[i];
      }
      
      //for(int i =0;i<10;i++)
      //ans[i]=left[i]*right[i];
      
      for(int i =0;i<10;i++)
      {
          std::cout<<ans[i]<<"\t";
          }
          std::cout<<std::endl;
  
}
