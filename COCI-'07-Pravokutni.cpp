#include <bits/stdc++.h>
using namespace std;

bool right(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long,long long> p3){
  long long len1 = (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
  long long len2 = (p1.first-p3.first)*(p1.first-p3.first)+(p1.second-p3.second)*(p1.second-p3.second);
  long long len3 = (p2.first-p3.first)*(p2.first-p3.first)+(p2.second-p3.second)*(p2.second-p3.second);
  if (len1+len2==len3||len3+len2==len1||len1+len3==len2) return true;
  return false;
}

int main() {
  int N,ans=0;
  scanf("%d",&N);
  pair<long long,long long> pts[N];
  for (int i=0;i<N;i++){
    scanf("%lld %lld",&pts[i].first,&pts[i].second);
  }
  for (int i=0;i<N;i++){
    for (int j=i+1;j<N;j++){
      for (int k=j+1;k<N;k++){
        if (right(pts[i],pts[j],pts[k])) ans++;
      }
    }
  }
  printf("%d",ans);
}
