#include <bits/stdc++.h>
using namespace std;

int N,M,a,b,c;
int limit;
int initial;
int ans = -1;
pair<int,int> moves[8] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int pow(int a, int b){
  if (b==0) return 1;
  if (b==1) return a;
  if (b%2) return a*pow(a*a,b/2);
  return pow(a*a,b/2);
}

int convert2(int num){
  int arr[M+2][N+2];
  int arr2[M][N];
  memset(arr,0,sizeof arr);
  int res = 0;
  for (int i=1;i<=M;i++){
    for (int j=1;j<=N;j++){
      arr[i][j] = (num%2);
      num /= 2;
    }
  }
  for (int i=1;i<=M;i++){
    for (int j=1;j<=N;j++){
      res = 0;
      if (arr[i][j]){ //currently alive
        for (pair<int,int> k: moves){
          res += arr[i+k.first][j+k.second];
        }
        if (res<a) arr2[i-1][j-1] = 0;
        else if (res>b) arr2[i-1][j-1] = 0;
        else arr2[i-1][j-1] = 1;
      }else{
        for (pair<int,int> k: moves){
          res += arr[i+k.first][j+k.second];
        }
        if (res>c) arr2[i-1][j-1] = 1;
        else arr2[i-1][j-1] = 0;
      }
    }
  }
  res = 0;
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      if (arr2[i][j]){
        res += pow(2,i*N+j);
      }
    }
  }
  return res;
}

void solve(int curr){
  int arr[M+2][N+2];
  int arr2[M+2][N+2];
  memset(arr,0,sizeof arr);
  memset(arr2,0,sizeof arr2);
  int res = 0;
  for (int i=1;i<=M;i++){
    for (int j=1;j<=N;j++){
      arr[i][j] = (curr%2);
      curr /= 2;
    }
  }
  for (int l=0;l<limit;l++){
    for (int i=1;i<=M;i++){
      for (int j=1;j<=N;j++){
        res = 0;
        if (arr[i][j]){ //currently alive
          for (pair<int,int> k: moves){
            res += arr[i+k.first][j+k.second];
          }
          if (res<a) arr2[i][j] = 0;
          else if (res>b) arr2[i][j] = 0;
          else arr2[i][j] = 1;
        }else{
          for (pair<int,int> k: moves){
            res += arr[i+k.first][j+k.second];
          }
          if (res>c) arr2[i][j] = 1;
        }
      }
    }
    int res = 0;
    for (int i=0;i<=M+1;i++){
      for (int j=0;j<=N+1;j++){
        if (arr[i][j]){
          res += pow(2,(i-1)*N+(j-1));
        }
        arr[i][j] = arr2[i][j];
      }
    }
    if (res==initial){
      ans = l;
      limit = l;
      return;
    }
  }
}

int main(){
  scanf("%d %d %d %d %d",&M,&N,&a,&b,&c);
  char ch;
  bool states[pow(2,N*M)+1];
  memset(states,false,sizeof states);
  limit = 50;
  initial = 0;
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      scanf(" %c",&ch);
      if (ch=='*'){
        initial += pow(2,i*N+j);
      }
    }
  }
  int res = 0;
  for (int i=0;i<pow(2,N*M);i++){
    res = convert2(i);
    states[res] = true; //convert2(i) is not eden.
  }
  res = 0;
  for (int i=0;i<pow(2,N*M);i++){
    if (!states[i]){ //if state is eden
      solve(i);
    }
  }
  printf("%d",ans);
}
