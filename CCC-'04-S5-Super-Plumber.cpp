#include <bits/stdc++.h>
using namespace std;

int max1(int a, int b, int c){
  int res = a;
  if (b > res){
    res = b;
  }
  if (c > res){
    res = c;
  }
  return res;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  while (true){
    cin >> m >> n;
    if (m==0&&n==0){
      break;
    }
    char grid[m][n];
    int ans[m][n][3];
    bool checked[m][n];
    memset(ans,-1,sizeof ans);
    memset(checked,false,sizeof checked);
    for (int i=m-1;i>=0;i--){
      for (int j=0;j<n;j++){
        cin >> grid[i][j];
      }
    }
    if (grid[0][0] != '*' && grid[0][0] != '.'){
      ans[0][0][0] = grid[0][0]-'0';
      ans[0][0][1] = grid[0][0]-'0';
      ans[0][0][2] = grid[0][0]-'0';
    }
    else{
      ans[0][0][0] = 0;
      ans[0][0][1] = 0;
      ans[0][0][2] = 0;
    }
    queue<pair<int,int>>q;
    q.push(make_pair(0,0));
    int x,y;
    while (!q.empty()){
      x = q.front().first;
      y = q.front().second;
      q.pop();
      checked[y][x] = false;
      if (x<n-1){
        if (grid[y][x+1] != '*'){
          if (grid[y][x+1] != '.'){
            if ((grid[y][x+1]-'0') + max1(ans[y][x][0],ans[y][x][1],ans[y][x][2]) > ans[y][x+1][0] && max1(ans[y][x][0],ans[y][x][1],ans[y][x][2]) != -1){
              ans[y][x+1][0] = max1(ans[y][x][0],ans[y][x][1],ans[y][x][2])+(grid[y][x+1]-'0');
              if (!checked[y][x+1]){
                q.push(make_pair(x+1,y));
                checked[y][x+1] = true;
              }
            }
          }
          else{
            if (max1(ans[y][x][0],ans[y][x][1],ans[y][x][2])>ans[y][x+1][0]){
              ans[y][x+1][0] = max1(ans[y][x][0],ans[y][x][1],ans[y][x][2]);
              if (!checked[y][x+1]){
                q.push(make_pair(x+1,y));
                checked[y][x+1] = true;
              }
            }
          }
        }
      }
      if (y<m-1){
        if (grid[y+1][x] != '*'){
          if (grid[y+1][x] != '.'){
            if ((grid[y+1][x]-'0') + max(ans[y][x][1],ans[y][x][0]) > ans[y+1][x][1] && max(ans[y][x][1],ans[y][x][0]) != -1){
              ans[y+1][x][1] = max(ans[y][x][1],ans[y][x][0])+(grid[y+1][x]-'0');
              if (!checked[y+1][x]){
                q.push(make_pair(x,y+1));
                checked[y+1][x] = true;
              }
            }
          }
          else{
            if (max(ans[y][x][1],ans[y][x][0])>ans[y+1][x][1]){
              ans[y+1][x][1] = max(ans[y][x][0],ans[y][x][1]);
              if (!checked[y+1][x]){
                q.push(make_pair(x,y+1));
                checked[y+1][x] = true;
              }
            }
          }
        }
      }
      if (y>0){
        if (grid[y-1][x] != '*'){
          if (grid[y-1][x] != '.'){
            if ((grid[y-1][x]-'0') + max(ans[y][x][2],ans[y][x][0]) > ans[y-1][x][2] && max(ans[y][x][2],ans[y][x][0]) != -1){
              ans[y-1][x][2] = max(ans[y][x][2],ans[y][x][0])+(grid[y-1][x]-'0');
              if (!checked[y-1][x]){
                q.push(make_pair(x,y-1));
                checked[y-1][x] = true;
              }
            }
          }
          else{
            if (max(ans[y][x][2],ans[y][x][0])>ans[y-1][x][2]){
              ans[y-1][x][2] = max(ans[y][x][0],ans[y][x][2]);
              if (!checked[y-1][x]){
                q.push(make_pair(x,y-1));
                checked[y-1][x] = true;
              }
            }
          }
        }
      }
    }
    cout << max1(ans[0][n-1][0],ans[0][n-1][1],ans[0][n-1][2]) << endl;
  }
  return 0;
}
