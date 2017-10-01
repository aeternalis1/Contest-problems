#include <bits/stdc++.h>
using namespace std;

struct triple{
  int a;
  int t;
  int h;
};

int main(){
  int K,N,M;
  int a,b,c,d;
  scanf("%d %d %d",&K,&N,&M);
  vector <triple> paths[N+1];
  int dp[N+1][K+1];
  bool checked[N+1];
  for (int i=0;i<=N;i++){
    checked[i] = false;
    for (int j=0;j<=K;j++){
      if (i==0){
        dp[i][j] = 0;
      }
      else{
        dp[i][j] = 10000;
      }
    }
  }
  for (int i=0;i<M;i++){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    paths[a].push_back({b,c,d});
    paths[b].push_back({a,c,d});
  }
  queue <int> q;
  q.push(0);
  while (!q.empty()){
    c = q.front();
    q.pop();
    checked[c] = false;
    for (int i=0;i<paths[c].size();i++){
      if (paths[c][i].h == 1){
        for (int j=0;j<=K-paths[c][i].t;j++){
          if (dp[c][j]+paths[c][i].t<dp[paths[c][i].a][j+paths[c][i].t]){
            dp[paths[c][i].a][j+paths[c][i].t] = dp[c][j]+paths[c][i].t;
            if (!checked[paths[c][i].a]){
              q.push(paths[c][i].a);
              checked[paths[c][i].a] = true;
            }
          }
        }
      }
      else {
        for (int j=0; j<=K; j++){
          if (dp[c][j]+paths[c][i].t<dp[paths[c][i].a][j]){
            dp[paths[c][i].a][j] = dp[c][j]+paths[c][i].t;
            if (!checked[paths[c][i].a]){
              q.push(paths[c][i].a);
              checked[paths[c][i].a] = true;
            }
          }
        }
      }
    }
  }
  if (dp[N-1][K] != 10000){
    cout << dp[N-1][K];
  }
  else {
    cout << -1;
  }
  return 0;
}
