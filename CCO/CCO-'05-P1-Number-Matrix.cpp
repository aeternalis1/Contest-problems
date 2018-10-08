#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,y,x;
  scanf("%d %d",&M,&N);
  int grid[N][M];
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      scanf("%d",&grid[i][j]);
    }
  }
  queue<pair<int,int>> q;
  pair<int,int> cur;
  bool checked[N][M];
  for (int i=0;i<10;i++){
    for (int j=i;j<10;j++){
      for (int k=j;k<10;k++){
        for (int l=0;l<N;l++){
          for (int m=0;m<M;m++){
            checked[l][m] = 0;
          }
        }
        for (int l=0;l<M;l++){
          if (grid[0][l]==i||grid[0][l]==j||grid[0][l]==k){
            q.push({0,l});
            checked[0][l] = true;
          }
        }
        while (!q.empty()){
          cur = q.front();
          q.pop();
          y = cur.first;
          x = cur.second;
          if (y==N-1){
            printf("%d %d %d\n",i,j,k);
            return 0;
          }
          if (y>0&&(grid[y-1][x]==i||grid[y-1][x]==j||grid[y-1][x]==k)&&!checked[y-1][x]){
            checked[y-1][x] = true;
            q.push({y-1,x});
          }
          if (y<N-1&&(grid[y+1][x]==i||grid[y+1][x]==j||grid[y+1][x]==k)&&!checked[y+1][x]){
            checked[y+1][x] = true;
            q.push({y+1,x});
          }
          if (x>0&&(grid[y][x-1]==i||grid[y][x-1]==j||grid[y][x-1]==k)&&!checked[y][x-1]){
            checked[y][x-1] = true;
            q.push({y,x-1});
          }
          if (x<M-1&&(grid[y][x+1]==i||grid[y][x+1]==j||grid[y][x+1]==k)&&!checked[y][x+1]){
            checked[y][x+1] = true;
            q.push({y,x+1});
          }
        }
      }
    }
  }
  printf("-1 -1 -1\n");
}
