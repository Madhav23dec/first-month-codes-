#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    vector<int> zeroes;
    vector<int> temp;
    int n=nums.size();
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==0)
        {
            zeroes.push_back(nums[i]);
            cnt1++;
        }
        else
        temp.push_back(nums[i]);
    }

    int i=0;
    while(i<=n-cnt1)
    {
        nums[i]=temp[i];
      i++;
    }
    while(i<n)
    {
        nums[i]=zeroes[i];
        i++;
    }


}

int main()
{
  vector<int> v= { 1,0,2,0,3,4,5,6,0,8,0,9};
  int n=12;
  moveZeroes(v);
  for(int i=0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
}
