#include <iostream>
#include <string>
#include <list>
#include<array>
#include<vector>
using namespace std;
unsigned int lineLength = 16;
bool isWordsAddValid(string word, string temp)
{
   if((word.length())+(temp.length())<=lineLength){
        return true;
        }
        else
            return false;
    }

void distributeSpaces(string &temp,int count)
{
    unsigned int i =1;
    int offset = lineLength - temp.length();
    int extra = offset%(count-1);
    int dis = offset/(count-1);
    while(offset && i<temp.length())
    {
        if(temp[i] == ' ')
        {
            int addi = dis;
            if(extra>0)
            { 
            addi = addi+1;
            extra--;
            }
            offset -=addi;
            temp.insert(++i,dis+1,' ');
            extra--;
        }
        else
            ++i;
        };
        
    }
    
    
int main()
{
vector<string> arr={"little","lazy","fox","jumps","over","the","dog"};
list<string> words(arr.begin(),arr.end());
list<string>::iterator it;
it = words.begin();
list<string> result;
string temp;
int count =0;
cout<<"wordsSize="<<words.size()<<endl;
for(;it != words.end();)
{
    bool res =isWordsAddValid(*it,temp);
    if(res){
        temp += *it;
        if(temp.length()<lineLength){
           temp += ' '; 
            }
            count++;
            it++;
        }
        else if(temp.length()<lineLength)
        {
            distributeSpaces(temp,count);
            result.push_back(temp);
                temp.clear();
                count =0;
            }
            else
            {
                result.push_back(temp);
                temp.clear();
                count =0;
            }
            
    if(it == words.end())
    {
        temp.insert(temp.end(),lineLength-temp.length(),' ');
        result.push_back(temp);
    }
    
    }
    cout<<"resultSize="<<result.size()<<endl;
    for(it = result.begin();it!= result.end();++it)
    {
        cout<<*it<<endl;
        }
}
