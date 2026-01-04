// Tóm tắt đề bài, có n đỉnh , m cạnh có trọng số.
// Với mỗi đỉnh i, tính quãng đường ngắn nhất đi từ đỉnh 1 đến đỉnh i rồi quay về đỉnh 1

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
using namespace std;
const ll INF = 1e18 + 9;
const int maxn = 2e5+9;
struct Edge{
     ll w;
    int v;
};

void dijiktra( int n, int s, const vector<vector<Edge>> &E, vector<ll> &D ){
    D.assign(n+1,INF);
    //trace.assign(n,-1);
    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    D[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        auto [du,u] = pq.top();
        pq.pop();

        if(D[u] != du) continue;    // du lúc này là độ dài nhỏ nhất của đến đỉnh u

        for(auto e : E[u]){
            int v = e.v;
            ll w = e.w;
            if(D[v] > D[u] + w){
                D[v] = D[u] + w;
                //trace[v] = u;
                pq.push({D[v], v});
            }
        }
    }
}
int n,m;
vector<vector<Edge>> E1;
vector<vector<Edge>> E2;
long long ans[maxn];
void solve(){
    cin >> n >> m;
    vector<ll> D1(n+1);
    vector<ll> D2(n+1);
    E1.assign(n+1,{});
    E2.assign(n+1,{});
    FOR(i,1,m){
    int x,y; ll w;
    cin >> x >> y >> w;
    E1[x].push_back({w,y});
    E2[y].push_back({w,x});
    }
    dijiktra(n,1,E1,D1);
    dijiktra(n,1,E2,D2);
    FOR(i,2,n){
    if(D1[i] == INF || D2[i] == INF) ans[i] = -1;
    else ans[i] = D1[i] + D2[i];

    }
    FOR(i,2,n) cout << ans[i] << '\n';
}
int main(){
    solve();
}
