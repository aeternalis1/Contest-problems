#include <bits/stdc++.h>
using namespace std;

#define MAXN 250001
#define root 500

int arr[MAXN];
int blocks[root][10];
int shifts[root]; //number of shifts a block has been shifted

int main() {
  int N,M,a,b,cnt = -1,res;
  scanf("%d %d",&N,&M);
  char c[N];
  scanf("%s",c);
  for (int i=0;i<N;i++){
    arr[i] = c[i]-'0';
    if (i%root==0) cnt++;
    blocks[cnt][arr[i]]++;
  }
  for (int i=0;i<M;i++){
    scanf("%d %d",&a,&b);
    a--;
    b--;
    res = 0;
    while (a%root&&a<=b){
      res += (arr[a]+shifts[a/root])%10;
      blocks[a/root][(arr[a]+shifts[a/root])%10]--;
      blocks[a/root][(arr[a]+shifts[a/root]+1)%10]++;
      arr[a] = (arr[a]+1)%10;
      a++;
    }
    while (a+root<=b){
      for (int j=0;j<10;j++){
        res += blocks[a/root][j]*j;
      }
      int temp = blocks[a/root][9];
      for (int j=9;j>0;j--){
        blocks[a/root][j] = blocks[a/root][j-1];
      }
      blocks[a/root][0] = temp;
      shifts[a/root]++;
      a += root;
    }
    while (a<=b){
      res += (arr[a]+shifts[a/root])%10;
      blocks[a/root][(arr[a]+shifts[a/root])%10]--;
      blocks[a/root][(arr[a]+shifts[a/root]+1)%10]++;
      arr[a] = (arr[a]+1)%10;
      a++;
    }
    printf("%d\n",res);
  }
}
