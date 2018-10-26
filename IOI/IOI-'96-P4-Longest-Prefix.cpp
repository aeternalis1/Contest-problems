#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;
#define f first
#define s second

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<string> arr;
    vector<int> lens;
    string cur;
    int N=0;
    while (1){
        cin >> cur;
        if (cur==".") break;
        arr.push_back(cur);
        lens.push_back(cur.length());
        N++;
    }
    string s;
    while (cin>>cur) s += cur;
    int can[s.length()], f;
    int M = s.length();
    memset(can,0,sizeof can);
    for (int i=0;i<M;i++){
        if (!i||can[i-1]){
            for (int j=0;j<N;j++){
                f = 1;
                for (int k=0;k<lens[j];k++){
                    if (i+k>=M){
                        f = 0;
                        break;
                    }
                    if (s[i+k]!=arr[j][k]){
                        f = 0;
                        break;
                    }
                }
                if (f) can[i+lens[j]-1] = 1;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<M;i++){
        if (can[i]) ans = i+1;
    }
    printf("%d\n",ans);
}
