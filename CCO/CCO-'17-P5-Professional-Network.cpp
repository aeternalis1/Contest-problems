#include "bits/stdc++.h"
using namespace std;

bool op(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
  int N;
  vector<pair<int,int>> cons;
  scanf("%d",&N);
  int ans = 0;
  int bought = 0;
  int a,b;
  for (int i=0;i<N;i++) {
    scanf("%d %d",&a,&b);
    if(a <= bought || b == 0) bought++;
    else cons.push_back({a,b});
  }
  sort(cons.begin(), cons.end(), op);
  int num = cons.size();
  priority_queue<int, vector<int>, greater<int>> nums;
  for(int i=num-1;i>=0;i--){
    nums.push(cons[i].second);
    if(cons[i].first > i + bought){
      bought++;
      ans += nums.top();
      nums.pop();
    }
  }
  printf("%d",ans);
}

/*
sort connections from greatest to least according to number of other connections necessary, then least to greatest according to price

choose connections to buy greedily: only buy the cheapest connection that requires equal to or more connections than the current

credit to Benjamin Li : https://github.com/BenjaminBLi/
*/
