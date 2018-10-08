#include <bits/stdc++.h>
using namespace std;

#define MAXN 400001
#define ll long long

vector<int> paths[MAXN];
int N,a,b;

pair<ll,ll> dfs(int cur, int par){
  ll len = 0;
  ll cnt = 0;
  bool got = 0;
  pair<ll,ll> res;
  for (int i:paths[cur]){
    if (i != par){
      got = true;
      res = dfs(i,cur);
      if (res.first>len){
        len = res.first;
        cnt = res.second;
      }else if (res.first==len){
        cnt += res.second;
      }
    }
  }
  if (got) return {len+1,cnt};
  else return {1,1};
}

pair<ll,ll> solve(int cur){
  ll len = 0;
  ll len2 = 0;
  ll cnt = 1;
  ll cnt3 = 0;
  ll cnt2 = 0;
  pair<ll,ll> res;
  ll ones = 0;
  ll tops = 0;
  vector<ll> temp;
  for (int i:paths[cur]){
    res = dfs(i,cur);
    if (res.first>len){
      temp.clear();
      tops = 1;
      len2 = len;
      cnt2 = cnt3;
      len = res.first;
      if (res.second>1){
        cnt = res.second;
        temp.push_back(res.second);
      }else{
        cnt = 1;
        ones = 1;
      }
      cnt3 = res.second;
    }else if (res.first==len){
      tops++;
      if (res.second>1){
        cnt *= res.second;
        cnt3 += res.second;
        temp.push_back(res.second);
      }else ones++;
    }else if (res.first > len2){
      len2 = res.first;
      cnt2 = res.second;
    }else if (res.first==len2){
      cnt2 += res.second;
    }
  }
  ll ans = 0;
  for (int i=0;i<temp.size();i++)
    for (int j=i+1;j<temp.size();j++)
      ans += temp[i]*temp[j];
  if (tops>1){
    if (cnt>1&&ones) return {len*2,ans+(cnt*ones)+(ones*(ones-1)/2)};
    else if (cnt>1){
      return {len*2,ans};
    }
    else return {len*2,(ones*(ones-1)/2)};
  }else{
      return {len+len2,cnt*cnt2};
  }
}

int main() {
  scanf("%d",&N);
  bool checked[N];
  int indeg[N];
  memset(indeg,0,sizeof indeg);
  memset(checked,0,sizeof checked);
  queue<int> q;
  for (int i=0;i<N-1;i++){
    scanf("%d %d",&a,&b);
    paths[--a].push_back(--b);
    paths[b].push_back(a);
    indeg[a]++;
    indeg[b]++;
  }
  for (int i=0;i<N;i++){
    if (paths[i].size()==1){
      q.push(i);
      checked[i] = true;
    }
  }
  while (!q.empty()){
    a = q.front();
    q.pop();
    for (int i:paths[a]){
      indeg[i]--;
      if (!checked[i]&&indeg[i]==1){
        checked[i] = true;
        q.push(i);
      }
    }
  }
  pair<ll,ll> res = solve(a);
  printf("%lld %lld",res.first+1,res.second);
}

/*
9
1 4
2 4
3 4
4 5
5 6
6 8
6 7
6 9

5 10
10 11
10 12
10 13
*/

//get centroid of tree, then dfs across all sides. Each dfs returns a pair of integers: the longest path in that subtree, and the number of that path
