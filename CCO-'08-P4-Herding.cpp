#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  char grid[n][m];
  int checked[n][m];
  memset(checked,0,sizeof checked);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> grid[i][j];
    }
  }
  int ans = 0;
  int cnt = 1;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (!checked[i][j]){
        int x = j;
        int y = i;
        while (true){
          if (checked[y][x] == cnt){
            ans++;
            break;
          }
          if (checked[y][x]) break;
          checked[y][x] = cnt;
          if (grid[y][x]=='S') y++;
          else if (grid[y][x]=='N') y--;
          else if (grid[y][x]=='W') x--;
          else if (grid[y][x]=='E') x++;
        }
      }
      cnt++;
    }
  }
  printf("%d",ans);
}
