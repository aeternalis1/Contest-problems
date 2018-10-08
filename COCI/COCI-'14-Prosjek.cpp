#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  int nums[N];
  for (int i=0;i<N;i++){
    scanf("%d",&nums[i]);
  }
  double lo = 0;
  double hi = 1000000;
  double mid;
  bool found;
  double arr[N+1];
  double low = 0;
  arr[0] = 0;
  while (abs(lo-hi)>0.0000001){
    mid = (lo+hi)/2;
    found = false;
    for (int i=1;i<=N;i++){
      arr[i] = nums[i-1]+arr[i-1]-mid;
    }
    low = 0;
    for (int i=K;i<=N;i++){
      if (arr[i]>low){
        found = true;
      }
      low = min(low,arr[i-K+1]);
    }
    if (found) lo = mid;
    else hi = mid;
  }
  printf("%f",lo);
}
