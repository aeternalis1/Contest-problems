#include <bits/stdc++.h>
using namespace std;

#define MAXN 150001

int arr[MAXN];
int line[MAXN];
int spot[MAXN];
int blocks[400];
vector<int> lines[MAXN];
pair<int,int> inds[400][MAXN]; //first and last index for each line in each block
int ops[MAXN]; //keep track of how many times each line has been operated, to get individual queries

int main() {
  int N,M,Q,cur,q,l,r,res;
  scanf("%d %d %d",&N,&M,&Q);
  int block = sqrt(N);
  memset(inds,-1,sizeof inds);
  memset(ops,0,sizeof ops);
  memset(line,0,sizeof line);
  memset(spot,0,sizeof spot);
  memset(blocks,0,sizeof blocks);
  for (int i=0;i<N;i++){
    scanf("%d",&cur);
    cur--;
    spot[i] = lines[cur].size();
    line[i] = cur;
    lines[cur].push_back(i);
    if (inds[i/block][cur].first==-1) inds[i/block][cur] = {lines[cur].size()-1,lines[cur].size()-1};
    else inds[i/block][cur].second = lines[cur].size()-1;
  }
  for (int i=0;i<N;i++){
    scanf("%d",&arr[i]);
    blocks[i/block] += arr[i];
  }
  for (int i=0;i<Q;i++){
    scanf("%d",&q);
    if (q==1){
      res = 0;
      scanf("%d %d",&l,&r);
      l--;
      r--;
      while (l%block&&l<=r){
        cur = (int)((int)lines[line[l]].size()-ops[line[l]]+spot[l])%(int)lines[line[l]].size();
        while (cur<0) cur += lines[line[l]].size();
        res += arr[lines[line[l]][cur]];
        l++;
      }
      while (l+block<=r){
        res += blocks[l/block];
        l += block;
      }
      while (l<=r){
        cur = (int)((int)lines[line[l]].size()-ops[line[l]]+spot[l])%(int)lines[line[l]].size();
        while (cur<0) cur += lines[line[l]].size();
        res += arr[lines[line[l]][cur]];
        l++;
      }
      printf("%d\n",res);
    }else{
      scanf("%d",&l);
      l--;
      cur = lines[l].size();
      ops[l]++;
      for (int j=0;j<400;j++){
        if (inds[j][l].first==-1) continue; //no stations for this line in this block
        if (inds[j][l].first==0){
          inds[j][l].first = cur-1;
          blocks[j] += arr[lines[l][inds[j][l].first]];
          blocks[j] -= arr[lines[l][inds[j][l].second]];
          if (inds[j][l].second==0){
            inds[j][l].second = cur-1;
          }else{
            inds[j][l].second--;
          }
        }else{
          inds[j][l].first--;
          blocks[j] += arr[lines[l][inds[j][l].first]];
          blocks[j] -= arr[lines[l][inds[j][l].second]];
          inds[j][l].second--;
        }
        if (inds[j][l].second<0) inds[j][l].second = cur-1;
      }
    }
  }
}
