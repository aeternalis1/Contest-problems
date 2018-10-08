#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  int sx,sy,ex,ey;
  int T,a,b,c,d;
  int ind1,ind2;
  for (int _=0;_<10;_++){
    scanf("%d %d",&N,&M);
    scanf("%d %d",&sy,&sx);
    scanf("%d %d",&ey,&ex);
    scanf("%d",&T);
    bool grid[N][M];
    bool checked[N][M];
    memset(grid,false,sizeof grid);
    memset(checked,false,sizeof checked);
    unordered_map<int,pair<int,int>> tele;
    tele.clear();
    queue<pair<int,int>> q;
    pair<int,int> curr;
    q.push({sy,sx});
    for (int i=0;i<T;i++){
      scanf("%d %d %d %d",&a,&b,&c,&d);
      grid[a][b] = true;
      grid[c][d] = true;
      ind1 = a*N+b;
      ind2 = c*N+d;
      tele[ind1] = {c,d};
      tele[ind2] = {a,b};
    }
    int ans = 0;
    bool found = false;
    checked[sy][sx] = true;
    if (grid[sy][sx]){
      q.push(tele[sy*N+sx]);
      checked[tele[sy*N+sx].first][tele[sy*N+sx].second] = true;
    }
    while (!q.empty()){
      int cur = q.size();
      for (int i=0;i<cur;i++){
        curr = q.front();
        q.pop();
        a = curr.first;
        b = curr.second;
        if (a==ey&&b==ex){
          found = true;
          break;
        }
        if (a>0){
          if (!checked[a-1][b]){
            checked[a-1][b] = true;
            q.push({a-1,b});
            if (grid[a-1][b]){
              if (!checked[tele[(a-1)*N+b].first][tele[(a-1)*N+b].second]){
                checked[tele[(a-1)*N+b].first][tele[(a-1)*N+b].second] = true;
                q.push(tele[(a-1)*N+b]);
              }
            }
          }
        }
        if (a<N-1){
          if (!checked[a+1][b]){
            checked[a+1][b] = true;
            q.push({a+1,b});
            if (grid[a+1][b]){
              if (!checked[tele[(a+1)*N+b].first][tele[(a+1)*N+b].second]){
                checked[tele[(a+1)*N+b].first][tele[(a+1)*N+b].second] = true;
                q.push(tele[(a+1)*N+b]);
              }
            }
          }
        }
        if (b>0){
          if (!checked[a][b-1]){
            checked[a][b-1] = true;
            q.push({a,b-1});
            if (grid[a][b-1]){
              if (!checked[tele[a*N+b-1].first][tele[a*N+b-1].second]){
                checked[tele[a*N+b-1].first][tele[a*N+b-1].second] = true;
                q.push(tele[a*N+b-1]);
              }
            }
          }
        }
        if (b<M-1){
          if (!checked[a][b+1]){
            checked[a][b+1] = true;
            q.push({a,b+1});
            if (grid[a][b+1]){
              if (!checked[tele[a*N+b+1].first][tele[a*N+b+1].second]){
                checked[tele[a*N+b+1].first][tele[a*N+b+1].second] = true;
                q.push(tele[a*N+b+1]);
              }
            }
          }
        }
      }
      if (found) break;
      ans++;
    }
    printf("%d\n",ans);
  }
}
