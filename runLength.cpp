#include <iostream>
#include <string>
using namespace std;

string runEncode(string val)
{
    string res;
    int count =1;
    for(unsigned int i =0;i<val.length();i++)
    {
        if(val[i] == val[i+1])
        {
            count++;
        }
        else{
            res +=to_string(count)+val[i];
            count =1;
            }
    }
    return res;
}

string runDecode(string decode)
{
    string res;
    for(unsigned int i =0;i<decode.length();i+=2)
    {
        res.insert(res.end(),(int)(decode[i])-'0',decode[i+1]);
    }
    return res;
}
int main()
{
    string val ="AAABBBBCCCDDDFFE";
    string encoded = runEncode(val);
    string decode = runDecode(encoded);
    
    cout<<"encoded="<<encoded<<"and decoded ="<<decode<<endl;
}
