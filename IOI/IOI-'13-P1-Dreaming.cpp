#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

vector<pair<int,int>> paths[MAXN];
vector<int> radii;
vector<int> diams;
bool visit[MAXN];
int checked[MAXN];
int checked2[MAXN];
int checked3[MAXN];

int furthest(int a, int N){
  queue<int> q;
  q.push(a);
  checked3[a] = 0;
  int ans = 0;
  int res = a;
  while (!q.empty()){
    int c = q.front();
    q.pop();
    for (pair<int,int> i:paths[c]){
      if (checked3[i.first]!=-1) continue;
      checked3[i.first] = checked3[c]+i.second;
      if (checked3[i.first]>ans){
        ans = checked3[i.first];
        res = i.first;
      }
      q.push(i.first);
    }
  }
  return res;
}

int diam(int a, int N){
  int b = furthest(a,N);
  queue<int> q;
  q.push(b);
  checked[b] = 0;
  int ans = 0;
  int res = b;
  while (!q.empty()){
    int c = q.front();
    visit[c] = true;
    q.pop();
    for (pair<int,int> i:paths[c]){
      if (checked[i.first]!=-1) continue;
      checked[i.first] = checked[c]+i.second;
      if (checked[i.first]>ans){
        ans = checked[i.first];
        res = i.first;
      }
      q.push(i.first);
    }
  }
  diams.push_back(ans);
  ans = 99999999999;
  q.push(res);
  checked2[res] = 0;
  res = 0;
  while (!q.empty()){
    int c = q.front();
    q.pop();
    for (pair<int,int> i:paths[c]){
      if (checked2[i.first]!=-1) continue;
      checked2[i.first] = checked2[c]+i.second;
      if (abs(checked2[i.first]-checked[i.first])<ans){
        ans = abs(checked2[i.first]-checked[i.first]);
        res = max(checked2[i.first],checked[i.first]);
      }else if (abs(checked2[i.first]-checked[i.first]==ans)){
        res = min(res,max(checked2[i.first],checked[i.first]));
      }
      q.push(i.first);
    }
  }
  radii.push_back(res);
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
  memset(visit,0,sizeof visit);
  memset(checked,-1,sizeof checked);
  memset(checked2,-1,sizeof checked);
  memset(checked3,-1,sizeof checked3);
  for (int i=0;i<M;i++){
    paths[A[i]].push_back({B[i],T[i]});
    paths[B[i]].push_back({A[i],T[i]});
  }
  for (int i=0;i<N;i++){
    if (!visit[i]) diam(i,N);
  }
  if (N-1==M){
    return diams[0];
  }
  sort(radii.begin(),radii.end());
  int ans = radii[radii.size()-1]+radii[radii.size()-2]+L;
  if (radii.size()>2){
    ans = max(ans,radii[radii.size()-2]+radii[radii.size()-3]+2*L);
  }
  for (int i: diams){
    if (i>ans) ans = i;
  }
  return ans;
}

//ans is either largest diameter or the two largest radii + L
