#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

struct query{
  char q;
  int a,b;
};

query queries[MAXN];
int tree[MAXN]; //tree for ratings
int ids[MAXN];
int ids2[MAXN];
unordered_map<int,int> nums; //old rating, new compressed rating
int rating[MAXN];
int temp[MAXN];

int query(int i){
  int temp = 0;
  for (;i>0;i-=i&-i) temp += tree[i];
  return temp;
}

void update(int a, int b){
  for (;a<MAXN;a+=a&-a) tree[a] += b;
}

int main() {
  int N,a,b,c,cnt=0;
  scan(N);
  for (int i=0;i<N;i++){
    scanf(" %c",&queries[i].q);
    if (queries[i].q=='N'||queries[i].q=='M'){
      scan(queries[i].a);
      scan(queries[i].b);
      rating[cnt] = queries[i].b;
      temp[cnt] = queries[i].b;
      cnt++;
    }else scan(queries[i].a);
  }
  sort(temp,temp+cnt);
  for (int i=0;i<cnt;i++){
    nums[rating[i]] = lower_bound(temp,temp+cnt,rating[i])-temp+1;
  }
  cnt = 0;
  for (int i=0;i<N;i++){
    if (queries[i].q=='N'){
      b = nums[queries[i].b];
      cnt++;
      ids[b] = queries[i].a;
      ids2[queries[i].a] = b;
      update(b,1);
    }else if (queries[i].q=='M'){
      b = nums[queries[i].b]; //new rating
      a = ids2[queries[i].a]; //old rating
      ids2[queries[i].a] = b;
      ids[b] = queries[i].a;
      update(a,-1);
      update(b,1);
    }else{
      a = queries[i].a;
      a--;
      int lo = 0, hi = MAXN;
      while (lo < hi){
        int mid = (lo+hi)/2;
        c = cnt-query(mid);
        if (c > a) lo = mid+1;
        else if (c <= a) hi = mid;
      }
      printf("%d\n",ids[lo]);
    }
  }
}

//keep track of one BIT for inversions, use binary search to find the rating with K inversions
//looks like coordinate compression will be necessary
