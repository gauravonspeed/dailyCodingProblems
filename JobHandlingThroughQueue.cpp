#include <iostream>
#include <string>
#include <functional>
#include <map>
using namespace std;

class B{
    std::function<void(string)>g = NULL;
    public:
    
        void realCaller()
        {
            return g("monkey");
            }
            
		void receivedCall(std::function<void(string)>f){
		        g = f;
		        //realCaller();
                return f("cow");
		}  
        
}; 

class test{
    public:
    test()
    {
        cout<<"in test class"<<endl;
        }
        void invokeFun(string queueid)
        {
            cout<<"queueID= "<<queueid<<endl;
            }
    };
            
class A{
    int data;
    public:
    A(){
        data =5;
    }
        
    void callbackFunction(string res){
        cout<<"result received: "<<res<<endl;
    }
        
    void caller(){
       cout<<"In caller"<<endl;
       auto instance = B();
	   auto callback = std::bind(&A::callbackFunction,this,std::placeholders::_1);
	   instance.receivedCall(callback);
	   instance.realCaller();
    }
};

int main()
{
    std::map<std::string,test>queObj;
    bool usecase =true;
    while(usecase)
    {
        string input;
        cout<<"enter the string to search in map"<<endl;
        cin>>input;
    std::map<std::string,test>::iterator it;
    it =queObj.find(input);
    if(it != queObj.end())
    {
        it->second.invokeFun(it->first);
    }
    else
    {
        test obj= test();
        queObj.insert(std::make_pair(input,obj));
        }
    cout<<"want to end the usecase?"<<endl;
    cin>>usecase;
    cout<<"usecase"<<usecase<<endl;
    };
  auto obj = A();
  obj.caller();
}
