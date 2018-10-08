#include <bits/stdc++.h>
using namespace std;

long long memo[10000001];
unordered_map<int,long long> memo2;

long long solve(int cur){
  if (cur<=10000000&&memo[cur]) return memo[cur];
  else if (cur > 10000000&&memo2[cur]) return memo2[cur];
  long long res = 0;
  int temp = 1;
  int branches = cur;
  while (temp < cur){
    int cnt = cur/temp-cur/(temp+1);
    res += solve(temp)*cnt;
    branches -= cnt;
    temp = cur/(branches);
  }
  if (cur <= 10000000) return memo[cur]=res;
  else return memo2[cur] = res;
}

int main(){
  int N;
  memo[1] = memo[2] = 1;
  scanf("%d",&N);
  printf("%lld",solve(N));
}
