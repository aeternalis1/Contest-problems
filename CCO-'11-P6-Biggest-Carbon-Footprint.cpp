#include <bits/stdc++.h>
using namespace std;

const int MAXC = 20001;

int row[MAXC];

int histo(int C){
  stack<int> s;
  int area = 0;
  int s_top;
  int top_area;
  int i = 0;
  int t1,t2;
  while (i < C){
    if (s.empty() || row[s.top()] <= row[i]){
      s.push(i++);
    }
    else{
      s_top = s.top();
      s.pop();
      t1 = row[s_top];
      t2 = (s.empty() ? i : i - s.top() - 1);
      top_area = (t1-(t1>>1))*(t2-(t2>>1));
      area = max(area,top_area);
    }
  }
  while (!s.empty()){
    s_top = s.top();
    s.pop();
    t1 = row[s_top];
    t2 = (s.empty() ? i : i - s.top() - 1);
    top_area = (t1-(t1>>1))*(t2-(t2>>1));
    area = max(area,top_area);
  }
  return area;
}

int main(){
  int R,C,T;
  scanf("%d %d %d",&C,&R,&T);
  R = R*2+1;
  C = C*2+1;
  bitset<MAXC> grid[R];
  int x,y;
  for (int i=0;i<T;i++){
    scanf("%d %d",&x,&y);
    grid[y<<1][x<<1] = true;
  }
  int lastrow[C];
  bool gridrow[C];
  for (int j=0;j<C;j++){
    lastrow[j] = 0;
  }
  for (int i=0;i<C;i++){
    grid[0][i] = grid[R-1][i] = 1;
  }
  for (int i=0;i<R;i++){
    grid[i][0] = grid[i][C-1] = 1;
  }
  bool c;
  int area = 0;
  int stack[MAXC];
  for (int j=0;j<R;j++){
    int ind = 0;
    for (int l=0;l<=C;l++){
      if (l<C){
        c = grid[j][l];
        gridrow[l] = grid[j][l];
      }else{
        c = 1;
      }
      if (!c){
        stack[ind++] = l;
      }
      else{
        for (int k=0;k<ind;k++){
          row[stack[k]] = 1;
          if (lastrow[stack[k]] != 0){
            row[stack[k]] += lastrow[stack[k]];
          }
        }
      }
    }
    for (int k=0;k<C;k++){
      if (gridrow[k]){
        row[k] = 0;
      }
    }
    area = max(area,histo(C));
    for (int k=0;k<C;k++){
      lastrow[k] = row[k];
    }
  }
  printf("%d",area);
}
