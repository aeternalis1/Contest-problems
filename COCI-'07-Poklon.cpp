#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

int tree[MAXN];

void update(int y, int v){
  for (;y<MAXN;y+=y&-y){
    tree[y] = max(tree[y],v);
  }
}

int query(int y){
  int ans = 0;
  for (;y>0;y-=y&-y){
    ans = max(ans,tree[y]);
  }
  return ans;
}

struct val{
  int a,b,c; // beginning of interval, end, index
  bool operator<(const val& v){
    if (v.a == a) return v.b>b;
    return v.a<a;
  }
};

int main(){
  int N,a,b;
  scanf("%d",&N);
  vector<val> vals;
  unordered_map<int,pair<int,int>> answers;
  unordered_map<int,int> answers2;
  unordered_map<int,pair<int,int>> original;
  answers[0] = {-1,-1};
  for (int i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    vals.push_back({a,b,i});
    original[i] = {a,b};
  }
  sort(vals.begin(),vals.end());
  int x,y,ind,ans;
  ans = 0;
  for (int i=0;i<N;i++){
    x = vals[i].a;
    y = vals[i].b;
    ind = vals[i].c;
    int temp = query(y)+1;
    answers[temp] = {ind,answers[temp-1].first};
    answers2[ind] = answers[temp].second;
    update(y,temp);
    if (temp>ans){
      ans = temp;
    }
  }
  printf("%d\n",ans);
  int curr = answers[ans].first;
  while (curr != -1){
    printf("%d %d\n",original[curr].first,original[curr].second);
    curr = answers2[curr];
  }
}
