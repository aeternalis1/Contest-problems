#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  int A,B,K,G;
  scanf("%d %d %d %d",&A,&B,&K,&G);
  A--;B--;
  int a,b,c;
  vector<int>taken;
  vector<int>paths[N];
  int adj[N][N][2];
  int checked[N][2];
  bool checked2[N];
  for (int i=0;i<N;i++){
    checked[i][0] = 9999999;
    checked2[i] = checked[i][1] = 0;
    for (int j=0;j<N;j++){
      adj[i][j][1] = -1;
    }
  }
  for (int i=0;i<G;i++){
    scanf("%d",&a);
    taken.push_back(a-1);
  }
  for (int i=0;i<M;i++){
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;
    paths[a].push_back(b);
    paths[b].push_back(a);
    adj[a][b][0] = adj[b][a][0] = c;
  }
  for (int i=1;i<G;i++){
    checked[taken[i]][1] = checked[taken[i-1]][1]+adj[taken[i]][taken[i-1]][0];
    adj[taken[i]][taken[i-1]][1] = adj[taken[i-1]][taken[i]][1] = checked[taken[i-1]][1];
  }
  queue<int> q;
  checked[A][0] = K;
  q.push(A);
  while (!q.empty()){
    int cur = q.front();
    q.pop();
    checked2[cur] = false;
    for (int i:paths[cur]){
      if (adj[cur][i][1] != -1){
        if (checked[cur][0] < adj[cur][i][1]){
          if (checked[i][0] > checked[cur][0]+adj[cur][i][0]){
            checked[i][0] = checked[cur][0] + adj[cur][i][0];
            if (!checked2[i]){
              q.push(i);
              checked2[i] = true;
            }
          }
        }else{
          if (checked[i][0] > max(adj[cur][i][1]+adj[cur][i][0],checked[cur][0])+adj[cur][i][0]){
            checked[i][0] = max(adj[cur][i][1]+adj[cur][i][0],checked[cur][0])+adj[cur][i][0];
            if (!checked2[i]){
              q.push(i);
              checked2[i] = true;
            }
          }
        }
      }else{
        if (checked[cur][0]+adj[cur][i][0]<checked[i][0]){
          checked[i][0] = checked[cur][0]+adj[cur][i][0];
          if (!checked2[i]){
            q.push(i);
            checked2[i] = true;
          }
        }
      }
    }
  }
  printf("%d",checked[B][0]-K);
}
