#include <bits/stdc++.h>
using namespace std;

int seen[500];

void play(){
    int cnt = 0;
    for (int i=1;i<=50;i++){
        int a = faceup(i)-'A';
        if (seen[a]){
            int b = faceup(seen[a])-'A';
            cnt++;
        }else{
            seen[a] = i;
            int b = faceup(i+1)-'A';
            if (b==a){
                cnt++;
            }else{
                if (seen[b]){
                    faceup(i+1);
                    faceup(seen[b]);
                }else seen[b] = i+1;
            }
            i++;
        }
        if (cnt==25) return;
    }
}
