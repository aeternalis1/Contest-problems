#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b,c;
  scanf("%d",&N);
  queue<int> q;
  vector<int> paths[N+1];
  vector<pair<int,int>> edges;
  unordered_map<int,bool> dir[N+1];
  int checked[N+1];
  memset(checked,0,sizeof checked);
  for (int i=0;i<N-1;i++){
    scanf("%d %d",&a,&b);
    paths[a].push_back(b);
    paths[b].push_back(a);
    dir[a][b] = false;
    dir[b][a] = false;
    edges.push_back({a,b});
  }
  for (int i=1;i<=N;i++){
    if (paths[i].size()==1){
      q.push(i);
      break;
    }
  }
  checked[q.front()] = 1;
  while (!q.empty()){
    c = q.front();
    q.pop();
    for (int i:paths[c]){
      if (!checked[i]){
        if (checked[c]==1){
          dir[c][i] = true;
          checked[i] = 2;
        }else{
          dir[i][c] = true;
          checked[i] = 1;
        }
        q.push(i);
      }
    }
  }
  for (int i=0;i<N-1;i++){
    if (dir[edges[i].first][edges[i].second]) printf("1\n");
    else printf("0\n");
  }
}
