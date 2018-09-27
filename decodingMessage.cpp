#include <iostream>
#include <string>
using namespace std;
void methodResolve(int msg, string res)
{
    if(msg ==0)
    {
        cout<<"decoded:"<<res<<endl;
        return;
        }
    int temp = msg%10;
    if(temp != 0)
    {
        res = (char)(temp+(int)'a'-1) + res;
        methodResolve(msg/10,res);
        }
    res.erase(res.begin());
    temp = msg%100;
    if(temp<=26 && temp>=10)
    {
        res = (char)((int)'a'+temp-1)+ res;
        methodResolve(msg/100,res);
        }
    
    }
int main()
{
  std::string res;
  int msg = 11198477;
  methodResolve(msg,res);
}
