#include <bits/stdc++.h>
using namespace std;

struct edge{
  int d,a,b;
  bool operator<(const edge&e)const{
    return d < e.d;
  }
};

int main(){
  int N,a,b;
  scanf("%d",&N);
  vector<pair<int,int>> nodes;
  vector<edge> paths;
  nodes.push_back({0,0});
  int ans[N+1];
  int ans2[N+1];
  int dist[N+1];
  for (int i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    nodes.push_back({a,b});
  }
  for (int i=0;i<=N;i++){
    ans[i] = 0;
    ans2[i] = 0;
    dist[i] = 0;
    for (int j=i+1;j<=N;j++){
      a = nodes[i].first-nodes[j].first;
      b = nodes[i].second-nodes[j].second;
      paths.push_back({a*a+b*b,i,j});
    }
  }
  sort(paths.begin(),paths.end());
  for (edge i:paths){
    if (i.d != dist[i.a]){
      dist[i.a] = i.d;
      ans2[i.a] = ans[i.a];
    }
    if (i.d != dist[i.b]){
      dist[i.b] = i.d;
      ans2[i.b] = ans[i.b];
    }
    if (i.a == 0){
      ans[i.a] = max(ans[i.a],ans2[i.b]);
    }
    else{
      ans[i.a] = max(ans[i.a],ans2[i.b]+1);
      ans[i.b] = max(ans[i.b],ans2[i.a]+1);
    }
  }
  printf("%d",ans[0]+1);
}
