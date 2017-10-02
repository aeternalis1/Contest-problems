#include <iostream>
#include <cstring>
using namespace std;

const int N = 1050;
int tree[N+1][N+1];

void update(int x, int y, int v)
{
    for (; x < N; x+=(x & -x))
    {
        for (int y1 = y; y1 < N; y1 += (y1 & -y1))
            tree[x][y1] += v;
    }
}
  
long long getsum(int x,int y)
{
    int sum = 0;
    for (; x > 0; x-=(x & -x))
    {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += tree[x][y1];
    }
    return sum;
}

int Q;
int x,y,v;
int x1,x2,y1,y2;
int fodder,fodder2;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> fodder >> fodder2;
  for (int i=0;i<=N;i++){
    for (int j=0;j<=N;j++){
      tree[i][j] = 0;
    }
  }
  while (1==1){
    cin >> Q;
    if (Q==1){
      cin >> x >> y >> v;
      update(x+1,y+1,v);
    }
    else if (Q==2){
      cin >> x1 >> y1 >> x2 >> y2;
      cout << getsum(x2+1,y2+1)-getsum(x1,y2+1)-getsum(x2+1,y1)+getsum(x1,y1)<<"\n";
    }
    else{
      break;
    }
  }
  return 0;
}
