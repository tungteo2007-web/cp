#include<bits/stdc++.h>
#define ll  long long
#define FOR(i,a,b)  for(int i = a, _b = (b); i <= _b; i++)
using namespace std;
const int maxn = 2e5+9;
const long long MOD = 5e6;

int bit[maxn];
int n,k;

void update(int x, int val){
    while(x <= n){
        bit[x] += val;
        x += x&-x;
    }
}

int find_k(int p){
    int step = 1;
    int idx = 0;
    while((step << 1) <= n) step<<= 1;
    for(int pw = step; pw > 0; pw >>= 1){
        int nxt = idx + pw;
        if( nxt <= n && bit[nxt] < p){
            idx =  nxt;
            p -= bit[nxt];
        }
    }
    return idx+1;
}

int a[maxn];

void solve(){
     cin >> n;
    FOR(i,1,n){
        cin >> a[i]; 
        update(i,1); 
    }
    FOR(i,1,n)
    {
       int p; cin >> p;
       int pos = find_k(p);
       cout << a[pos] << " ";
       update(pos,-1);
    }
}
int main(){
solve();
}
