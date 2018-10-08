#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,num;
  scanf("%d",&n);
  set<int> nums;
  unordered_map<int,int> rem;
  scanf("%d",&num);
  rem[num] = 2;
  nums.insert(num);
  bool res = true;
  for (int i=0;i<n-1;i++){
    scanf("%d",&num);
    auto a = nums.upper_bound(num);
    if (a != nums.begin()){
      a--;
    }
    if (*a > num){
      res = false;
      break;
    }
    nums.insert(num);
    rem[num] = 2;
    rem[*a]--;
    if (rem[*a]==0){
      nums.erase(*a);
    }
  }
  if (res) printf("YES");
  else printf("NO");
}
