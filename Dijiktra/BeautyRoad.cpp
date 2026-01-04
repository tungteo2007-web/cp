// Cho n thành phố , m con đường, mỗi con đường có chiều dài và độ đẹp đẽ. Yêu câu cout số lượng độ dài đường 
//ngắn nhất với độ đẹp lớn nhất

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
using namespace std;
const ll INF = 1e18 + 9;
const int maxn = 2e5+9;
struct Edge{
     ll w;
     ll beau;
    int v;

};
struct cmp{
    bool operator()( Edge &a , Edge &b ){
           return a.w > b.w; // Nếu a.w > b.w thì a kém ưu tiên hơn b;
           if(a.w == b.w) return a.beau < b.beau; //  nếu a.beau < b.beau => a kém ưu tiên hơn
    }
};

void dijiktra( int n, int s, const vector<vector<Edge>> &E, vector<ll> &D, vector<ll> &B ){
    D.assign(maxn,INF);
    B.assign(maxn, {});
    //trace.assign(n,-1);
    using P = pair<ll,int>;
    priority_queue<Edge, vector<Edge>, cmp> pq;
    D[s] = 0;
    B[s] = 0;
    pq.push({0,0,s});
    while(!pq.empty()){
        auto [du,bu,u] = pq.top();
        pq.pop();

        if(D[u] != du) continue;
        if(D[u] == du && B[u] != bu) continue;

        for(auto e : E[u]){
            int v = e.v;
            ll w = e.w;
            ll b = e.beau;
            if(D[v] > D[u] + w){
                D[v] = D[u] + w;
                B[v] = B[u] + b;
                //trace[v] = u;
                pq.push({D[v],B[v],v});
            }
        }
    }
}
int n,m;
ll w,b;
vector<vector<Edge>> E;
vector<ll> D;
vector<ll> B;

void solve(){
    cin >> n >> m;
    E.assign(maxn, {});
    FOR(i,1,m){
    int u ,v;
    ll w,b;
    cin >> u >> v >> w>>b;
    E[u].push_back({w,b,v});
    E[v].push_back({w,b,u});
    }

    dijiktra(n,1,E,D,B);
    if(D[n] == INF) cout << -1;
    else cout << D[n] << " " << B[n];
}
int main(){
    solve();

}
