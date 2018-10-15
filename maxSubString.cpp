// Example program
#include <iostream>
#include <string>
#include<map>
using namespace std;


bool isValidSubString(int k , string var)
{
    std::map<char,int> mapper;
    std::map<char,int>::iterator it;
    for(int i =0;i<var.length();i++)
    {
        it = mapper.find(var[i]);
        if(it == mapper.end())
        {
            mapper.insert(std::pair<char,int>(var[i],1));
            if(k<mapper.size())
            {
                return false;
                }
            }
        }
		return true;
    }
string findSub(string src, int k)
{
    string result="";
    int max_len = 0;
    for(int i =0;i<src.length();i++)
    {
        string temp="";
        for(int j=i;j<src.length();j++)
        {
            temp+=src[j];
            bool rply = isValidSubString(k,temp);
            if(rply)
            {
                if(max_len <temp.length())
                {
                    max_len = temp.length();
                    result = temp;
                    }
                }
            }
        }
        
        return result;
    }
    

int main()
{
  std::string name ="abbccccd";
  int k =2;
  string res = findSub(name,k);
  cout<<"sub string is= "<<res<<endl;
  return 0;
  }
