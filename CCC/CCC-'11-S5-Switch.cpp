#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,c,cnt,last,cur=0;
  scanf("%d",&N);
  bool checked[1<<N];
  queue<int> q;
  memset(checked,0,sizeof checked);
  for (int i=0;i<N;i++){
    cur *= 2;
    scanf("%d",&c);
    cur += c;
  }
  checked[cur] = 1;
  q.push(cur);
  int ans = 0;
  while (!q.empty()){
    int num = q.size();
    for (int _=0;_<num;_++){
      c = q.front();
      if (!c){
        printf("%d\n",ans);
        return 0;
      }
      q.pop();
      for (int i=0;i<N;i++){
        if (c&(1<<i)) continue;
        cur = c|(1<<i);
        if (!checked[cur]){
          last = cur;
          checked[cur] = 1;
          cnt = 0;
          for (int j=0;j<N;j++){
            if (cur&(1<<j)) cnt++;
            else cnt = 0;
            if (cnt==4){
              for (int k=j;k>j-4;k--){
                cur ^= (1<<k);
              }
            }else if (cnt>4){
              cur ^= (1<<j);
            }
          }
          if (!checked[cur]){
            checked[cur] = 1;
            q.push(cur);
          }else if (cur==last) q.push(cur);
        }
      }
    }
    ans++;
  }
}
