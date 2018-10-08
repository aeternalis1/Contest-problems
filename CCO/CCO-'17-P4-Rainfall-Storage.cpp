#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MAXN 25001

bool checked[51];
bool dp[2][MAXN];

int main(){
  int N;
  scanf("%d",&N);
  int arr[N];
  for (int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  sort(arr,arr+N);
  vector<int> taken;
  bool cur = 0;
  dp[0][0] = 1;
  for (int i=N-2;i>=0;i--){
    for (int j=0;j<MAXN;j++){
      if (dp[cur][j]) dp[cur^1][j] = 1;
      else continue;
      for (int k:taken){
        if (k-arr[i]+j<MAXN) dp[cur^1][k-arr[i]+j] = 1;
      }
    }
    if (!checked[arr[i]]){
      checked[arr[i]] = 1;
      taken.push_back(arr[i]);
    }
    cur ^= 1;
  }
  for (int i=0;i<MAXN;i++){
    if (dp[cur][i]) printf("%d ",i);
  }
}
