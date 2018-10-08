#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,C,D,a,b;
  scanf("%d %d",&R,&C);
  int grid[R][C];
  int grid2[R][2];
  long long psum[R][C+1];
  long long rows[R];
  long long lens[R][R];
  long long lens2[R][R];
  long long lens3[R][R];
  long long ans[R][2];
  bool checked[R][2];
  int y,x;
  pair<int,int> cur;
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
  memset(checked,0,sizeof checked);
  memset(rows,0,sizeof rows);
  memset(psum,0,sizeof psum);
  memset(lens,999999999,sizeof lens);
  memset(lens2,999999999,sizeof lens2);
  memset(lens3,999999999,sizeof lens3);
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      scanf("%d",&grid[i][j]);
    }
    for (int j=1;j<C-1;j++){
      rows[i] += grid[i][j];
    }
    for (int j=1;j<=C;j++){
      psum[i][j] += grid[i][j-1]+psum[i][j-1];
    }
    grid2[i][0] = grid[i][0];
    grid2[i][1] = grid[i][C-1];
  }
  for (int i=0;i<R;i++){
    q.push({-grid[i][0],i*2});
    for (int j=0;j<R;j++){
      ans[j][0] = 999999999;
      ans[j][1] = 999999999;
      checked[j][0] = 0;
      checked[j][1] = 0;
    }
    ans[i][0] = -grid[i][0];
    while (!q.empty()){
      cur = q.top();
      q.pop();
      y = cur.second/2;
      x = cur.second%2;
      checked[y][x] = true;
      if (y>0&&ans[y-1][x]>ans[y][x]+grid2[y][x]){
        ans[y-1][x] = ans[y][x]+grid2[y][x];
        if (!checked[y-1][x]){
          q.push({ans[y-1][x],(y-1)*2+x});
        }
      }
      if (y<R-1&&ans[y+1][x]>ans[y][x]+grid2[y][x]){
        ans[y+1][x] = ans[y][x]+grid2[y][x];
        if (!checked[y+1][x]){
          q.push({ans[y+1][x],(y+1)*2+x});
        }
      }
      if (C>1&&ans[y][x]+rows[y]+grid2[y][x]<ans[y][x^1]){
        ans[y][x^1] = ans[y][x]+rows[y]+grid2[y][x];
        if (!checked[y][x^1]){
          q.push({ans[y][x^1],y*2+(x^1)});
        }
      }
    }
    for (int j=0;j<R;j++){
      lens[i][j] = ans[j][1];
      lens2[i][j] = ans[j][0];
    }
    q.push({-grid2[i][1],i*2+1});
    for (int j=0;j<R;j++){
      ans[j][0] = 999999999;
      ans[j][1] = 999999999;
      checked[j][0] = 0;
      checked[j][1] = 0;
    }
    ans[i][1] = -grid2[i][1];
    while (!q.empty()){
      cur = q.top();
      q.pop();
      y = cur.second/2;
      x = cur.second%2;
      checked[y][x] = true;
      if (y>0&&ans[y-1][x]>ans[y][x]+grid2[y][x]){
        ans[y-1][x] = ans[y][x]+grid2[y][x];
        if (!checked[y-1][x]){
          q.push({ans[y-1][x],(y-1)*2+x});
        }
      }
      if (y<R-1&&ans[y+1][x]>ans[y][x]+grid2[y][x]){
        ans[y+1][x] = ans[y][x]+grid2[y][x];
        if (!checked[y+1][x]){
          q.push({ans[y+1][x],(y+1)*2+x});
        }
      }
      if (C>1&&ans[y][x]+rows[y]+grid2[y][x]<ans[y][x^1]){
        ans[y][x^1] = ans[y][x]+rows[y]+grid2[y][x];
        if (!checked[y][x^1]){
          q.push({ans[y][x^1],y*2+(x^1)});
        }
      }
    }
    for (int j=0;j<R;j++){
      lens3[i][j] = ans[j][1];
    }
  }
  scanf("%d",&D);
  y = 0;
  x = 0;
  long long res = grid[y][x];
  long long temp = 0;
  for (int i=0;i<D;i++){
    scanf("%d %d",&a,&b);
    a--;
    b--;
    if (y==a){
      if (x>b) temp = psum[y][x]-psum[y][b];
      else temp = psum[y][b+1]-psum[y][x+1];
      temp = min(temp,psum[y][x]+lens[y][y]+psum[y][C]-psum[y][b]);
      temp = min(temp,psum[y][C]-psum[y][x+1]+lens[y][y]+psum[y][b+1]);
    }else{
      if (y>a){
        temp = psum[y][x]+lens2[y][a]+psum[a][b+1];
        temp = min(temp,psum[y][C]-psum[y][x+1]+lens3[y][a]+psum[a][C]-psum[a][b]);
      }else{
        temp = psum[y][x]+lens2[a][y]+psum[a][b+1];
        temp = min(temp,psum[y][C]-psum[y][x+1]+lens3[a][y]+psum[a][C]-psum[a][b]);
      }
      temp = min(temp,psum[y][x]+lens[y][a]+psum[a][C]-psum[a][b]);
      temp = min(temp,psum[y][C]-psum[y][x+1]+lens[a][y]+psum[a][b+1]);
    }
    res += temp;
    y = a;
    x = b;
  }
  printf("%lld\n",res);
}
