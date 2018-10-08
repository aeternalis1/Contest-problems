#include <bits/stdc++.h>
using namespace std;

int n;
double bonds[20][20];
double dp[1<<20];

double solve(int depth, int bit){
  if (depth==n) return 1.0d;
  if (dp[bit] != -1) return dp[bit];
  double res = 0.0;
  for (int i=0;i<n;i++){
    if (bit&(1<<i)) res = max(res,solve(depth+1,bit^(1<<i))*bonds[depth][i]);
  }
  return dp[bit] = res;
}

int main(){
  double num;
  scanf("%d",&n);
  for (int i=0;i<(1<<20);i++){
    dp[i] = -1;
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> num;
      bonds[i][j] = num/100;
    }
  }
  printf("%f",solve(0,(1<<n)-1)*100);
}
