#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  multiset <int> bags;
  vector< pair <int,int> > gems;
  int m,v;
  for (int i=0; i<N; i++){
    scanf("%d %d",&m,&v);
    gems.push_back (make_pair(v,m));
  }
  for (int i=0; i<K; i++){
    scanf("%d",&m);
    bags.insert(m);
  }
  sort(gems.begin(), gems.end());
  long long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (bags.lower_bound(gems[i].second) != bags.end()) {
      ans += gems[i].first;
      bags.erase(bags.lower_bound(gems[i].second));
    }
  }
  printf("%lld\n",ans);
  return 0;
}
