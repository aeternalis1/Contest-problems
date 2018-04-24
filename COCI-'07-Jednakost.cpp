#include <bits/stdc++.h>
using namespace std;

int main() {
  int S = 0,cur,cur2,N=0,last;
  char inp[6001];
  char A[1001];
  bool ans[1001];
  char c;
  A[0] = '0';
  scanf("%s",&inp);
  while (inp[N]!='='){
    A[N+1] = inp[N];
    N++;
  }
  for (int i=N+1;i<strlen(inp);i++){
    S *= 10;
    S += inp[i]-'0';
  }
  vector<int> paths[1001];
  short steps[1001][5001];
  pair<int,int> par[1001][5001];
  paths[0].push_back(0);
  for (int i=0;i<=N;i++){
    for (int j=0;j<=S;j++){
      par[i][j] = {0,0};
      steps[i][j] = 9999;
    }
    ans[i] = 0;
  }
  steps[0][0] = 0;
  for (int i=1;i<=N;i++){
    cur = 0;
    for (int j=i;j<=N;j++){
      cur *= 10;
      cur += A[j]-'0';
      if (cur>S) break;
      for (int k:paths[i-1]){
        if (k+cur>S) continue;
        if (steps[i-1][k]<steps[j][k+cur]){
          par[j][k+cur] = {i-1,k};
          if (steps[j][k+cur]==9999) paths[j].push_back(k+cur);
          steps[j][k+cur] = steps[i-1][k]+1;
        }
      }
    }
  }
  cur = N;
  cur2 = S;
  while (1){
    pair<int,int> t = par[cur][cur2];
    cur = t.first;
    cur2 = t.second;
    if (cur==0) break;
    ans[cur] = 1;
  }
  for (int i=1;i<=N;i++){
    printf("%c",A[i]);
    if (ans[i]) printf("+");
  }
  printf("=");
  printf("%d\n",S);
}
