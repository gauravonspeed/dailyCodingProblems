// Example program
#include <iostream>
#include <string>
#include<map>
using namespace std;

int findMin(int res1,int res2,int res3,int res4)
{
    int result= -1;
    int comp1 = -1;
    int comp2 = -1;
    if (res1 != -1 && res2 !=-1)
        comp1 = res1<res2?res1:res2;
        
        if(comp1 == -1)
        {
            if(res1 == -1)
            {
                comp1 = res2;
                }
                else
                comp1 = res1;
            }
    if(res3 != -1 && res4 != -1)
        comp2 = res3<res4?res3:res4;   
    if(comp2 == -1)
        {
            if(res3 == -1)
            {
                comp2 = res4;
                }
                else
                comp2 = res3;
            }
    
    result = comp1<comp2?comp1:comp2;
    
    if(result ==-1)
    {
        if(comp1 ==-1)
        return comp2;
        else
        return comp1;
        }
    //result = result>res4?result:res4;
    
    return result;
    }

int calMinSteps(int a[][5],int endi,int endj,int curi,int curj,map<string,int> mapper){
    
    string key = to_string(curi)+to_string(curj);
    if(mapper.end() != mapper.find(key))
        return -1;
    else
        mapper.insert(make_pair(key,1));
        
    //cout<<"current i ="<<curi<<"and current j ="<<curj<<endl;    
    int count =-1;
    if(endj == curj && endi == curi)
        return ++count;
    int res1=-1,res2=-1,res3=-1,res4=-1;    
    if(curj+1<5 && a[curi][curj+1] == 0)
    {
        res1 = calMinSteps(a,endi,endj,curi,curj+1,mapper);
        }
        
    if(curj-1>=0 && a[curi][curj-1] == 0)
    {
        res2 = calMinSteps(a,endi,endj,curi,curj-1,mapper);
        }
        
    if(curi+1<5 && a[curi+1][curj] == 0)
    {
        res3 = calMinSteps(a,endi,endj,curi+1,curj,mapper);
        }
        
    if(curi-1>=0 && a[curi-1][curj] == 0)
    {
        res4 = calMinSteps(a,endi,endj,curi-1,curj,mapper);
        }
        
    count = findMin(res1,res2,res3,res4);
    if(count == -1)
    return -1;
    
    return ++count;
}

int main()
{
    int a[5][5] ={{0,0,0,0,0},{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{1,0,1,1,0}};
    
   /* for(int i =0;i<5;i++)
    {
        for(int j =0;j<5;j++){
        
            a[i][j] = (i+j+1)%2;
        }
        
        }
     */   
    for(int i =0;i<5;i++)
    {
        for(int j =0;j<5;j++){
        
           cout<<a[i][j]<<"\t";
        }
        cout<<endl;
        
        }
        
    int starti = 3, startj =3;
    int endi =3, endj =3;
    std::map<string,int> mapper;
    int result = calMinSteps(a,endi,endj,starti,startj,mapper);
    if(result == -1)
    cout<<"no path"<<endl;
    else
    cout<<"steps="<<result<<endl;
}
