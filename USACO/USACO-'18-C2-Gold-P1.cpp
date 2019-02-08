#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
typedef long long ll;
#define f first
#define s second
const ll mod = 1e9+7;

ll pow(ll a, ll b){
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2) return (a*pow((a*a)%mod,b/2))%mod;
    return pow((a*a)%mod,b/2)%mod;
}

int main(){
    freopen("poetry.in","r",stdin);
    freopen("poetry.out","w",stdout);
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    int arr[N][2];
    for (int i=0;i<N;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    ll dp[K+1];
    ll fin[N+1]; // # of ways to get length of K with rhyme class of [i]
    ll cnt[26];
    memset(cnt,0,sizeof cnt);
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    memset(fin,0,sizeof fin);
    for (int i=0;i<K;i++){
        for (int j=0;j<N;j++){
            if (i+arr[j][0]<K){
                dp[i+arr[j][0]] += dp[i];
                dp[i+arr[j][0]] %= mod;
            }else if (i+arr[j][0]==K){
                fin[arr[j][1]] += dp[i];
                fin[arr[j][1]] %= mod;
            }
        }
    }
    char s[M];
    for (int i=0;i<M;i++){
        scanf(" %c",&s[i]);
        cnt[s[i]-'A']++;
    }
    ll ans = 1;
    for (int i=0;i<26;i++){
        if (cnt[i]){
            ll res = 0;
            for (int j=0;j<=N;j++){
                if (fin[j]){
                    res += pow(fin[j],cnt[i]);
                    res %= mod;
                }
            }
            ans *= res;
            ans %= mod;
        }
    }
    printf("%lld\n",ans);
}
