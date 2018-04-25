#include <bits/stdc++.h>
using namespace std;

#define MAXN 512

int dp[MAXN][MAXN][10];
int opt[MAXN][MAXN][10];
int ans[MAXN][MAXN];
int arr[MAXN+1][MAXN+1];
int grid[MAXN][MAXN];
int moves[12][4] = {{0, 1, 2, 2}, {0, 2, 1, 2}, {0, 2, 2, 1}, {1, 0, 2, 2}, {1, 2, 0, 2}, {1, 2, 2, 0}, {2, 0, 1, 2}, {2, 0, 2, 1}, {2, 1, 0, 2}, {2, 1, 2, 0}, {2, 2, 0, 1}, {2, 2, 1, 0}};

int solve(int y, int x, int dep){
  if (dp[y][x][dep]!=-1) return dp[y][x][dep];
  if (!dep) return 0;
  dep--;
  int ans = 9999999;
  int x1,x2,y1,y2;
  for (int i=0;i<12;i++){
    int cur = 0;
    x1 = x;
    x2 = x+pow(2,dep);
    y1 = y;
    y2 = y+pow(2,dep);
    if (!moves[i][0]) cur += arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1];
    else if (moves[i][0]==1) cur += pow(2,dep*2)-(arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1]);
    else cur += solve(y1,x1,dep);
    x1 = x+pow(2,dep);
    x2 = x+pow(2,dep+1);
    y1 = y;
    y2 = y+pow(2,dep);
    if (!moves[i][1]) cur += arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1];
    else if (moves[i][1]==1) cur += pow(2,dep*2)-(arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1]);
    else cur += solve(y1,x1,dep);
    x1 = x;
    x2 = x+pow(2,dep);
    y1 = y+pow(2,dep);
    y2 = y+pow(2,dep+1);
    if (!moves[i][2]) cur += arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1];
    else if (moves[i][2]==1) cur += pow(2,dep*2)-(arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1]);
    else cur += solve(y1,x1,dep);
    x1 = x+pow(2,dep);
    x2 = x+pow(2,dep+1);
    y1 = y+pow(2,dep);
    y2 = y+pow(2,dep+1);
    if (!moves[i][3]) cur += arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1];
    else if (moves[i][3]==1) cur += pow(2,dep*2)-(arr[y2][x2]-arr[y1][x2]-arr[y2][x1]+arr[y1][x1]);
    else cur += solve(y1,x1,dep);
    if (cur<ans){
      ans = cur;
      opt[y][x][dep+1] = i;
    }
  }
  return dp[y][x][dep+1] = ans;
}

void fill(int y, int x, int dep){
  if (!dep){
    ans[y][x] = grid[y][x];
    return;
  }
  int i = opt[y][x][dep];
  int x1,x2,y1,y2;
  dep--;
  x1 = x;
  x2 = x+pow(2,dep);
  y1 = y;
  y2 = y+pow(2,dep);
  if (!moves[i][0]) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 0;
  else if (moves[i][0]==1) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 1;
  else fill(y1,x1,dep);
  x1 = x+pow(2,dep);
  x2 = x+pow(2,dep+1);
  y1 = y;
  y2 = y+pow(2,dep);
  if (!moves[i][1]) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 0;
  else if (moves[i][1]==1) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 1;
  else fill(y1,x1,dep);
  x1 = x;
  x2 = x+pow(2,dep);
  y1 = y+pow(2,dep);
  y2 = y+pow(2,dep+1);
  if (!moves[i][2]) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 0;
  else if (moves[i][2]==1) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 1;
  else fill(y1,x1,dep);
  x1 = x+pow(2,dep);
  x2 = x+pow(2,dep+1);
  y1 = y+pow(2,dep);
  y2 = y+pow(2,dep+1);
  if (!moves[i][3]) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 0;
  else if (moves[i][3]==1) for (int j=y1;j<y2;j++) for (int k=x1;k<x2;k++) ans[j][k] = 1;
  else fill(y1,x1,dep);
}

int main() {
  int N;
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      scanf(" %c",&grid[i][j]);
      grid[i][j] -= '0';
    }
  }
  for (int i=1;i<=N;i++){
    for (int j=1;j<=N;j++){
      arr[i][j] += arr[i-1][j]+grid[i-1][j-1];
    }
  }
  for (int i=1;i<=N;i++){
    for (int j=1;j<=N;j++){
      arr[i][j] += arr[i][j-1];
    }
  }
  memset(dp,-1,sizeof dp);
  memset(opt,0,sizeof opt);
  printf("%d\n",solve(0,0,(int)log2(N)));
  fill(0,0,(int)log2(N));
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      printf("%d",ans[i][j]);
    }
    printf("\n");
  }
}
