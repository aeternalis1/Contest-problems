#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  vector<int> paths[N];
  int num;
  int a,b;
  bool states[N];
  memset(states,false,sizeof states);
  for (int i=0;i<5;i++){
    scanf("%d",&num);
    for (int j=0;j<num;j++){
      scanf("%d %d",&a,&b);
      a--;
      b--;
      paths[a].push_back(b);
      paths[b].push_back(a);
    }
  }
  bool cont = true;
  while (cont){
    cont = false;
    for (int i=0;i<N;i++){
      int cnt = 0;
      for (int j=0;j<paths[i].size();j++){
        if (states[i]==states[paths[i][j]]){
          cnt++;
        }
      }
      if (cnt>2){
        states[i]^=1;
        cont = true;
      }
    }
  }
  for (int i=0;i<N;i++){
    if (states[i]){
      printf("A");
    }
    else{
      printf("B");
    }
  }
}
