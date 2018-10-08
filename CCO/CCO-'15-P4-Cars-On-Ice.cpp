#include <bits/stdc++.h>
using namespace std;

#define MAXN 2001

struct car{
  char c;
  int a,b;
};

char cha;
int ans = 0;
int cnt = 0;
int N,M;
deque<car> hori[MAXN];
deque<car> vert[MAXN];
bool checked[MAXN][MAXN];

int main(){
  scanf("%d %d",&N,&M);
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      scanf(" %c",&cha);
      //cout << cha << endl;
      if (cha != '.'){
        cnt++;
        hori[i].push_back((car){cha,i,j});
        vert[j].push_back((car){cha,i,j});
      }
    }
  }
  while (ans<cnt){
    for (int i=0;i<N;i++){ //checking if any cars on far outside (on left or right) can drive away
      if (hori[i].empty()) continue;
      while (!hori[i].empty()){
        if (checked[hori[i].front().a][hori[i].front().b]){
          hori[i].pop_front();
        }else if (hori[i].front().c=='W'){
          ans++;
          printf("(%d,%d)\n",hori[i].front().a,hori[i].front().b);
          checked[hori[i].front().a][hori[i].front().b] = true;
          hori[i].pop_front();
        }else break;
      }
      while (!hori[i].empty()){
        if (checked[hori[i].back().a][hori[i].back().b]){
          hori[i].pop_back();
        }else if (hori[i].back().c=='E'){
          ans++;
          printf("(%d,%d)\n",hori[i].back().a,hori[i].back().b);
          checked[hori[i].back().a][hori[i].back().b] = true;
          hori[i].pop_back();
        }else break;
      }
    }
    for (int i=0;i<M;i++){ //checking if any cars on far outside (on top or bottom) can drive away
      if (vert[i].empty()) continue;
      while (!vert[i].empty()){
        if (checked[vert[i].front().a][vert[i].front().b]){
          vert[i].pop_front();
        }else if (vert[i].front().c=='N'){
          ans++;
          printf("(%d,%d)\n",vert[i].front().a,vert[i].front().b);
          checked[vert[i].front().a][vert[i].front().b] = true;
          vert[i].pop_front();
        }else break;
      }
      while (!vert[i].empty()){
        if (checked[vert[i].back().a][vert[i].back().b]){
          vert[i].pop_back();
        }else if (vert[i].back().c=='S'){
          ans++;
          printf("(%d,%d)\n",vert[i].back().a,vert[i].back().b);
          checked[vert[i].back().a][vert[i].back().b] = true;
          vert[i].pop_back();
        }else break;
      }
    }
  }
}
