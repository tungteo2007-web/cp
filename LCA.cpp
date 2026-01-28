#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
#define se second
#define fi first
#define pb push_back
#define BIT(i)  (1 << (i))
using namespace std;
const int N = 1e5+9;
const int LOG = 19;
int n;
int p[N][LOG+1],high[N],sz[N];
vector<int> adj[N];

void dfs(int u, int par){
    for(auto v: adj[u]) if(v!= par){
        high[v]  = high[u] + 1;
        p[v][0] = u;
        dfs(v,u);
        sz[u] += sz[v];
    }
}
void prepare(){

    for(int j = 1; j <= LOG; j++) for(int i = 1; i <= n; i++){
        p[i][j] = p[p[i][j-1]][j-1];
    }
}
int lca(int u , int v){
    if(high[u] < high[v]) return lca(v,u);
    for(int i = LOG; i >= 0; i--){
        if(high[p[u][i]] >= high[v]) u = p[u][i];
    }
    if(u == v) return u;
    for(int i = LOG; i >= 0; i--){
        int u1 = p[u][i];
        int v1 = p[v][i];
        if(u1 != v1){
            u = u1;
            v = v1;
        }
    }
    return p[u][0];
}
int jumping(int v , int k){
    int temp = v;
    for(int i = LOG; i >= 0; i-- ){
        if(k& (1 << i)) temp = p[temp][i];
    }
    return temp;
}
void process(){
    cin >> n;
    FOR(i,1,n-1){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    FOR(i,1,n) sz[i] = 1;
    high[1] = 0;
    high[0] = -1;
    dfs(1,-1);
    prepare();

    int k; cin >> k;
    while(k--){
        int a,b; cin >> a >> b;
        if( a ==  b){
            cout << n << '\n';
            continue;
        }
        int LCA = lca(a,b);
//       cout << high[a] << " " <<high[b] << "**********" << endl;
        if( a == LCA || b == LCA){
            if(high[a] > high[b]) swap(a,b);

            if((high[b] - high[a]) % 2 == 1){
                cout << 0 << '\n';
                continue;
            }
            int half = (high[b] - high[a])/2;
            int mid = jumping(b,half);
            int to = jumping(b,half- 1);

            cout << sz[mid] - sz[to] << '\n';
            continue;
        }
        else{
            if(high[a] == high[b]){
                    //cout << LCA <<'\n';
                    int dist = high[a] - high[LCA];
                    int to1 = jumping(a,dist-1);
                    int to2 = jumping(b,dist-1);
//                    cout << sz[to1] << endl;
//                    cout << sz[to2] << endl;
                cout << n - sz[to1] - sz[to2] << '\n';
                continue;
            }
            if(high[a] > high[b] ) swap(a,b);
            if((high[a] - high[LCA] + high[b] - high[LCA]) % 2 == 1){
                cout << 0 << '\n';
                continue;
            }
            int half = (high[a] + high[b] - 2*high[LCA])/2;
            int mid = jumping(b,half);
            int to = jumping(b,half - 1);
            cout << sz[mid] - sz[to] << '\n';
        }
    }
}
/* 6
    1 2
    1 3
    1 4
    1 5
    1 6
    3
    1 2
    2 3
    4 5
     */


int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
}
