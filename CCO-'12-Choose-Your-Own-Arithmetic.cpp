#include <bits/stdc++.h>
using namespace std;

int W,D,T;
vector<int> digs;
bool dp[8][5000001];

void solve(int curr, int depth){
  if (dp[depth][curr]) return;
  if (depth==W+1) return;
  dp[depth][curr] = true;
  for (int i=0;i<D;i++){
    if (curr+digs[i]<=5000000) solve(curr+digs[i],depth+1);
    if (curr*digs[i]<=5000000) solve(curr*digs[i],depth+1);
  }
}

int main(){
  scanf("%d",&W);
  scanf("%d",&D);
  int a;
  for (int i=0;i<D;i++){
    scanf("%d",&a);
    digs.push_back(a);
  }
  for (int j=0;j<6;j++){
    for (int k=0;k<5000001;k++){
      dp[j][k] = false;
    }
  }
  for (int j=0;j<D;j++){
    solve(digs[j],0);
  }
  int V;
  scanf("%d",&V);
  for (int i=0;i<V;i++){
    scanf("%d",&T);
    if (dp[W][T]) printf("Y\n");
    else printf("N\n");
  }
}
