#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
#define se second
#define fi first
#define pb push_back
#define BIT(i)  (1 << (i))
using namespace std;
const ll INF = 1e18 + 9;
const ll MOD = 1e9+7;
const int maxn = 1e5+9;
const int maxp = 9;
struct cow{
    ll h,w,s;
};
int n;
ll cao[BIT(20)], nang[BIT(20)], dp[BIT(20)];
cow a[maxn];

void solve(){
    int n,p,k;
    cin >> n >> k;
    FOR(i,0,n-1) cin >> a[i].h >> a[i].w >> a[i].s;
    // tinh tong cua 1 subset
    cao[0] = 0;
    nang[0] = 0;
    FOR(i,0,n-1){
        cao[BIT(i)] = a[i].h;
        nang[BIT(i)] =  a[i].w;
    }
    FOR(mask,0,BIT(n)- 1) if(__builtin_popcount(mask) >= 2){
        int temp = mask&-mask;
        cao[mask] = cao[temp] + cao[mask^temp];
        nang[mask] = nang[temp] + nang[mask^temp];
    }
    memset(dp,-1, sizeof dp);
    ll ans = -1;
    dp[0] = INF;
    FOR(mask,0,BIT(n) - 1){
        //if(cao[mask] < k) continue;
        FOR(i,0,n-1) if(BIT(i) & mask){
            int rest = mask^BIT(i);
            if(a[i].s >= nang[rest] && dp[rest] != -1) dp[mask] = max(dp[mask], min(dp[rest], a[i].s - nang[rest]));
        }
        if(cao[mask] >= k && dp[mask] != -1) ans = max(ans,dp[mask]);
    }
    if( ans == -1) cout << "Mark is too tall";
    else cout << ans;
}
int main(){
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    solve();
}

