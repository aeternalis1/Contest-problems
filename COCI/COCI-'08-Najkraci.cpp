#include <bits/stdc++.h>
using namespace std;

struct edge{
  int a,b,c;
};

#define MAXN 1501
#define MAXM 5001

edge edges[MAXM];
vector<int> paths[MAXN];
long long ans[MAXM];
int vals[MAXN];
int pars[MAXN];
bool visit[MAXN];
long long checked[MAXN];
int indeg[MAXN];
queue<int> q;

int dfs(int c){
  if (vals[c]) return vals[c];
  int temp = 1;
  for (int i: paths[c]){
    if (checked[c]+edges[i].c==checked[edges[i].b]){
      temp += dfs(edges[i].b);
    }
  }
  return vals[c] = temp;
}

int main() {
  int N,M,a,b,c;
  scanf("%d %d",&N,&M);
  for (int i=0;i<M;i++){
    scanf("%d %d %d",&a,&b,&c);
    a--;
    b--;
    paths[a].push_back(i);
    edges[i] = {a,b,c};
  }
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      checked[j] = 99999999999;
      vals[j] = 0;
      pars[j] = 0;
      visit[j] = 0;
      indeg[j] = 0;
    }
    q.push(i);
    checked[i] = 0;
    pars[i] = 1;
    while (!q.empty()){
      c = q.front();
      q.pop();
      visit[c] = false;
      for (int j:paths[c]){
        if (checked[edges[j].b]>edges[j].c+checked[c]){
          checked[edges[j].b]=edges[j].c+checked[c]; 
          indeg[edges[j].b]=1;
          if (!visit[edges[j].b]){
            q.push(edges[j].b);
            visit[edges[j].b] = true;
          }
        }else if(checked[edges[j].b]==checked[c]+edges[j].c){
          indeg[edges[j].b]++;
        }
      }
    }
    dfs(i);
    q.push(i);
    while (!q.empty()){
      c = q.front();
      q.pop();
      for (int j:paths[c]){
        if (checked[c]+edges[j].c==checked[edges[j].b]){
          indeg[edges[j].b]--;
          pars[edges[j].b] += pars[c];
          if (!indeg[edges[j].b]) q.push(edges[j].b);
        }
      }
    }
    for (int j=0;j<M;j++){
      if (checked[edges[j].b]-checked[edges[j].a]==edges[j].c) ans[j] = (ans[j]+pars[edges[j].a]*vals[edges[j].b])%1000000007;
    }
  }
  for (int i=0;i<M;i++) printf("%lld\n",ans[i]);
}
