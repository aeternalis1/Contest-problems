#include <bits/stdc++.h>
using namespace std;

#define MAXN 1501
#define block 40
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int rows[MAXN][block];
int cols[MAXN][block];
int N;

int main() {
  int y,x,a,b,start,l,r;
  int ans,res;
  ans = 0;
  pair<int,int> cur;
  queue<pair<int,int>> q;
  scan(N);
  int sqr = N*N;
  scan(y);
  scan(x);
  y--;x--;
  pair<int,int> arr[sqr];
  int arr2[MAXN][MAXN];
  int cnt = 0;
  memset(rows,0,sizeof rows);
  memset(cols,0,sizeof cols);
  memset(arr2,0,sizeof arr2);
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      scan(arr[cnt].first);
      arr[cnt].second = cnt;
      cnt++;
    }
  }
  start = arr[y*N+x].first;
  arr2[y][x] = 1;
  rows[y][x/block] = 1;
  cols[x][y/block] = 1;
  sort(arr,arr+sqr);
  for (int i=0;i<sqr;i++){
    if (arr[i].first<=start) continue;
    if (arr[i].first != arr[i-1].first){
      while (!q.empty()){
        cur = q.front();
        q.pop();
        y = cur.second/N;
        x = cur.second%N;
        arr2[y][x] = cur.first;
        rows[y][x/block] = max(rows[y][x/block],cur.first);
        cols[x][y/block] = max(cols[x][y/block],cur.first);
      }
    }
    y = arr[i].second/N;
    x = arr[i].second%N;
    res = 0;
    if (y>0){
      l = 0;
      r = x-2;
      while (l+block <= r&&l/block < block){
        res = max(res,rows[y-1][l/block]);
        l += block;
      }
      while (l <= r){
        res = max(res,arr2[y-1][l]);
        l++;
      }
      l = x+2;
      r = (N/block+1)*block;
      while (l<N&&l%block){
        res = max(res,arr2[y-1][l]);
        l++;
      }
      while (l+block <= r&&l/block < block){
        res = max(res,rows[y-1][l/block]);
        l += block;
      }
    }
    if (y<N-1){
      l = 0;
      r = x-2;
      while (l+block <= r&&l/block < block){
        res = max(res,rows[y+1][l/block]);
        l += block;
      }
      while (l <= r){
        res = max(res,arr2[y+1][l]);
        l++;
      }
      l = x+2;
      r = (N/block+1)*block;
      while (l<N&&l%block){
        res = max(res,arr2[y+1][l]);
        l++;
      }
      while (l+block <= r&&l/block < block){
        res = max(res,rows[y+1][l/block]);
        l += block;
      }
    }
    if (x>0){
      l = 0;
      r = y-2;
      while (l+block <= r&&l/block < block){
        res = max(res,cols[x-1][l/block]);
        l += block;
      }
      while (l <= r){
        res = max(res,arr2[l][x-1]);
        l++;
      }
      l = y+2;
      r = (N/block+1)*block;
      while (l<N&&l%block){
        res = max(res,arr2[l][x-1]);
        l++;
      }
      while (l+block <= r&&l/block < block){
        res = max(res,cols[x-1][l/block]);
        l += block;
      }
    }
    if (x<N-1){
      l = 0;
      r = y-2;
      while (l+block <= r&&l/block < block){
        res = max(res,cols[x+1][l/block]);
        l += block;
      }
      while (l <= r){
        res = max(res,arr2[l][x+1]);
        l++;
      }
      l = y+2;
      r = (N/block+1)*block;
      while (l<N&&l%block){
        res = max(res,arr2[l][x+1]);
        l++;
      }
      while (l+block <= r&&l/block < block){
        res = max(res,cols[x+1][l/block]);
        l += block;
      }
    }
    if (res) q.push({res+1,arr[i].second});
    ans = max(ans,res);
  }
  printf("%d\n",ans+1);
}
