#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  for (int l=0;l<10;l++){
    cin >> s;
    int length = s.size()*2+1;
    char str[length];
    for (int i=0;i<length;i++){
      str[i] = '|';
    }
    for (int i=1;i<length;i+=2){
      str[i] = s[i/2];
    }
    int vals[length];
    long inds[length+1];
    long inds2[length+1];
    int ans = 0;
    int a=0;
    int b=0;
    int c;
    for (int i=0;i<=length;i++){
      inds[i] = 0;
      inds2[i] = 0;
    }
    for (int i=1;i<length;i++){
      c = (a-(i-a));
      vals[i] = b > i ? min(b-i,vals[c]) : 0;
      while (i+1+vals[i]<length&&i-1-vals[i]>=0&&str[i+1+vals[i]]==str[i-1-vals[i]]){
        vals[i]++;
      }
      if (i+vals[i]>b){
        b=i+vals[i];
        a = i;
      }
    }
    for (int i=0;i<length;i++){
      if (min(length-i-1,i)==vals[i]){
        ans = max(vals[i],ans);
      }
    }
    cout << s.size()-ans << endl;
  }
}
