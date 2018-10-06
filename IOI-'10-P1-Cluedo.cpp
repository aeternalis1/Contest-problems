#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;

bool a[6];
bool b[10];
bool c[6];

void Solve(){
    for (int i=0;i<6;i++){
        a[i] = c[i] = 0;
    }
    for (int i=0;i<10;i++){
        b[i] = 0;
    }
    while (1){
        for (int i=0;i<6;i++){
            for (int j=0;j<10;j++){
                for (int k=0;k<6;k++){
                    if (!a[i]&&!b[j]&&!c[k]){
                        int res = Theory(i+1,j+1,k+1);
                        if (res==1) a[i] = 1;
                        else if (res==2) b[j] = 1;
                        else if (res==3) c[k] = 1;
                        else return;
                    }
                }
            }
        }
    }
}
