#include <bits/stdc++.h>
using namespace std;

#define MAXN 1050000

int nums[MAXN];
pair<int,int> tree[MAXN*4];
unordered_map<int,int> inds;

void build(int i, int s, int e){
  if (s==e){
    tree[i].first = nums[s];
    tree[i].second = s;
    inds[s] = i;
    return;
  }
  int mid = (s+e)/2;
  build(i*2,s,mid);
  build(i*2+1,mid+1,e);
  if (tree[i*2].first > tree[i*2+1].first){
    tree[i] = {tree[i*2].first,tree[i*2].second};
  }
  else{
    tree[i] = {tree[i*2+1].first,tree[i*2+1].second};
  }
}

void update(int i){
  i /= 2;
  if (tree[i*2].first > tree[i*2+1].first){
    tree[i] = {tree[i*2].first,tree[i*2].second};
  }
  else{
    tree[i] = {tree[i*2+1].first,tree[i*2+1].second};
  }
  if (i != 1){
    update(i);
  }
}

int query(int i, int s){
  i /= 2;
  if (tree[i].second==s){
    if (i==1) return 1;
    return query(i,s)+1;
  }
  return 0;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  char q;
  int a,b;
  cin >> N >> M;
  N = pow(2,N);
  for (int i=0;i<N;i++){
    cin >> nums[i];
  }
  build(1,0,N-1);
  for (int i=0;i<M;i++){
    cin >> q;
    if (q=='R'){
      cin >> a >> b;
      tree[inds[a-1]] = {b,a-1};
      update(inds[a-1]);
    }
    else if (q=='W'){
      printf("%d\n",tree[1].second+1);
    }
    else{
      cin >> a;
      printf("%d\n",query(inds[a-1],a-1));
    }
  }
  return 0;
}
