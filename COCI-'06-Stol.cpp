#include <bits/stdc++.h>
using namespace std;

int histo(int r[], int C){
  stack<int> s;
  int peri = 0;
  int s_top;
  int top_peri;
  int i = 0;
  while (i < C){
    if (s.empty() || r[s.top()] <= r[i]){
      s.push(i++);
    }
    else{
      s_top = s.top();
      s.pop();
      top_peri = (r[s_top] + (s.empty() ? i : i - s.top() - 1))*2;
      if (top_peri!=r[s_top]*2 && r[s_top] != 0){
        peri = max(peri,top_peri);
      }
    }
  }
  while (!s.empty()){
    s_top = s.top();
    s.pop();
    top_peri = (r[s_top] + (s.empty() ? i : i - s.top() - 1))*2;
    if (top_peri!=r[s_top]*2 && r[s_top] != 0){
      peri = max(peri,top_peri);
    }
  }
  return peri;
}

int main(){
  int R,C;
  scanf("%d %d",&R,&C);
  int row[C];
  int lastrow[C];
  int gridrow[C];
  for (int j=0;j<C;j++){
    lastrow[j] = 0;
  }
  vector <int> stack;
  char c;
  int peri = 0;
  for (int j=0;j<R;j++){
    for (int l=0;l<=C;l++){
      if (l<C){
        cin >> c;
        gridrow[l] = c;
      }
      else{
        c = 'X';
      }
      if (c=='.'){
        stack.push_back(l);
      }
      else{
        int stacksize = stack.size();
        for (int k=0;k<stacksize;k++){
          row[stack[k]] = 1;
          if (lastrow[stack[k]] != 0){
            row[stack[k]] += lastrow[stack[k]];
          }
        }
        stack.clear();
      }
    }
    for (int k=0;k<C;k++){
      if (gridrow[k] == 'X'){
        row[k] = 0;
      }
    }
    peri = max(peri,histo(row,C));
    for (int k=0;k<C;k++){
      lastrow[k] = row[k];
    }
  }
  cout << peri-1 << endl;
  return 0;
}
