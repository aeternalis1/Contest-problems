#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,y,x,sy,sx,ey,ex;
  scanf("%d %d",&N,&M);
  char grid[N][M];
  int arr[N][M];
  bool checked[N][M];
  bool visit[N][M];
  pair<int,int> moves[4] = {{0,1},{0,-1},{1,0},{-1,0}};
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      scanf(" %c",&grid[i][j]);
      arr[i][j] = 9999999;
      checked[i][j] = 0;
      visit[i][j] = 0;
      if (grid[i][j]=='V'){
        sy = i;
        sx = j;
      }else if(grid[i][j]=='J'){
        ey = i;
        ex = j;
      }
    }
  }
  queue<pair<int,int>> q;
  pair<int,int> cur;
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      if (grid[i][j]=='+'){
        q.push({i,j});
        arr[i][j] = 0;
        while (!q.empty()){
          cur = q.front();
          q.pop();
          for (pair<int,int> k:moves){
            y = cur.first+k.first;
            x = cur.second+k.second;
            if (y<0||y>=N||x<0||x>=M) continue;
            if (abs(y-i)+abs(x-j)<arr[y][x]&&grid[y][x]!='+'){
              arr[y][x] = abs(y-i)+abs(x-j);
              q.push({y,x});
            }
          }
        }
      }
    }
  }
  int ans[N][M];
  pair<int,int> par[N][M];
  for (int i=0;i<N;i++) for (int j=0;j<M;j++) ans[i][j] = arr[i][j];
  q.push({sy,sx});
  visit[sy][sx] = 1;
  while (!q.empty()){
    cur = q.front();
    q.pop();
    checked[cur.first][cur.second] = 0;
    for (pair<int,int> k:moves){
      y = cur.first+k.first;
      x = cur.second+k.second;
      if (y<0||y>=N||x<0||x>=M) continue;
      if (!visit[y][x]){
        ans[y][x] = min(ans[cur.first][cur.second],arr[y][x]);
        par[y][x] = {cur.first,cur.second};
        visit[y][x] = 1;
        q.push({y,x});
      }else if (ans[cur.first][cur.second]>ans[y][x]){
        ans[y][x] = min(ans[cur.first][cur.second],arr[y][x]);
        par[y][x] = {cur.first,cur.second};
        visit[y][x] = 1;
        if (!checked[y][x]){
          q.push({y,x});
          checked[y][x] = 1;
        }
      }
    }
  }
  printf("%d\n",ans[ey][ex]);
}
