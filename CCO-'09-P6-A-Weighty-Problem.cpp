#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200001

int main(){
  int C,D,K;
  scanf("%d %d %d",&C,&D,&K);
  pair<int,float> arr[D];
  int opt[K], temp;
  float dp[MAXN], start=0, res, ans=9999999;
  for (int i=0;i<MAXN;i++) dp[i] = -1;
  dp[0] = 0;
  for (int i=0;i<D;i++){
    scanf("%d %f",&arr[i].first,&arr[i].second);
  }
  for (int i=0;i<K;i++){
    scanf("%d",&opt[i]);
    opt[i]--;
    start += arr[opt[i]].second;
  }
  for (int i:opt){
    for (int j=MAXN-arr[i].first-1;j>=0;j--){
      if (dp[j]!=-1){
        if (dp[j]+arr[i].second>dp[j+arr[i].first]){
          dp[j+arr[i].first] = dp[j]+arr[i].second;
        }
      }
    }
  }
  sort(arr,arr+D);
  reverse(arr,arr+D);
  bool found = 0;
  for (int i=C;i<MAXN;i++){
    if (dp[i]!=-1){
      found = 1;
      res = start-dp[i];
      temp = i-C;
      for (pair<int,float> j:arr){
        res += temp/j.first*j.second;
        temp %= j.first;
      }
      if (res<ans) ans = res;
    }
  }
  if (!found) printf("too poor\n");
  else printf("%.2f\n",ans);
}
