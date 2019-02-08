#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;
#define f first
#define s second

vector<int> pos[26];

int getnum(int l, int r, char c){
    return lower_bound(pos[c-'A'].begin(),pos[c-'A'].end(),r)-lower_bound(pos[c-'A'].begin(),pos[c-'A'].end(),l);
}

int main(){
    ll M;
    int Q;
    scanf("%lld",&M);
    char s[MAXN];
    scanf("%s",s);
    int N = strlen(s);
    for (int i=0;i<N;i++){
        pos[s[i]-'A'].push_back(i);
    }
    scanf("%d",&Q);
    ll a, cur;
    char c;
    ll ans;
    for (int i=0;i<Q;i++){
        scanf("%lld %c",&a,&c);
        if (a%2){
            cur = ((a%N)*(((a-1)/2)%N))%N;
        }else{
            cur = (((a/2)%N)*((a-1)%N))%N;
        }
        ans = 0;
        if (a>=N-cur){
            ans += getnum(cur,N,c);
            a -= N-cur;
            ans += (a/N)*pos[c-'A'].size();
            a %= N;
            ans += getnum(0,a,c);
        }else{
            ans += getnum(cur,cur+a,c);
        }
        printf("%lld\n",ans);
    }
}
