#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b;
  int total = 0;
  vector<pair<int,int>> candy;
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    candy.push_back({a,b});
    total += a*b;
  }
  int goal = floor(total/2);
  bool ans[goal+1];
  memset(ans,false,sizeof ans);
  ans[0] = true;
  vector<int> nums; //current numbers for consideration (to be added to)
  nums.push_back(0);
  for (pair<int,int> i:candy){
    int cnt[goal];
    memset(cnt,0,sizeof cnt);
    for (int j=0;j<nums.size();j++){
      if (i.second+nums[j] <= goal && !ans[i.second+nums[j]] && cnt[nums[j]] < i.first){
        cnt[nums[j]+i.second] = cnt[nums[j]] + 1;
        ans[nums[j]+i.second] = true;
        nums.push_back(nums[j]+i.second);
      }
    }
  }
  for (int i=goal;i>=0;i--){
    if (ans[i]){
      printf("%d",total-i*2);
      return 0;
    }
  }
}
