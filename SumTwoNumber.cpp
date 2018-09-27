#include <iostream>
#include <string>
#include<vector>
#include <map>

using namespace std;

std::vector<int> solution(std::vector<int> nums, int target)
{
   // bool found = false;
    std::vector<int> result;
    
    std::map<int,int> targetMap;
    std::map<int,int>::iterator it;
    
    for(int i =0;i<nums.size();i++)
    {
        it = targetMap.find(target-nums[i]);
        if(it == targetMap.end())
        {
            targetMap.insert(std::pair<int,int>(nums[i],i));
            }
            else
            {
                result.push_back(i);
                result.push_back(it->second);
                }
        }
    /*for(int i =0;i<nums.size();i++)
    {
        if(found)
        {
            cout<<"found"<<endl;
        break;
        }
        int search = target - nums[i];
        for(int j =i+1;j<nums.size();j++)
        {
            if(search == nums[j])
            {
                result.push_back(i);
                result.push_back(j);
                found = true;
                break;
                }
            }
        }
      */  
        cout<<"result[0]="<<result[0]<<"and result[1]="<<result[1]<<endl;
        return result;
    }

int main()
{
  std::vector<int> nums;
  for(int i =0;i<7;i++)
  nums.push_back(i+2);
  std::vector<int> result = solution(nums,5);
  cout<<result[0]<<" and "<<result[1]<<endl;
}
