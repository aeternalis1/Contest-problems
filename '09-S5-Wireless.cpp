#include <bits/stdc++.h>
using namespace std;

int M,N,K;
int arr[30001][1001];
int x,y,r,b;
int ans = 0;
int ans2 = 0;
  
int main(){
  scanf("%d",&M);
  scanf("%d",&N);
  scanf("%d",&K);
  for (int i=0;i<K;i++){
    scanf("%d %d %d %d",&x,&y,&r,&b);
    x--;
    y--;
    for (int j=max(0,x-r);j<min(N,x+r+1);j++){
      int lo = y-(int)(pow(r*r-(x-j)*(x-j),0.5));
      int hi = min(M-1,y+abs(y-lo));
      lo = max(0,lo);
      arr[lo][j] += b;
      arr[hi+1][j] -= b;
    }
  }
  for (int i=0;i<N;i++){
    int curr = 0;
    for (int j=0;j<M;j++){
      curr += arr[j][i];
      if (curr>ans){
        ans = curr;
        ans2 = 1;
      }
      else if (curr == ans){
        ans2 += 1;
      }
    }
  }
  printf("%d\n%d",ans,ans2);
}
