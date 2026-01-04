// Cho 1 đoạn thẳng n điểm, điểm thứ i có màu C_i. Muốn di chuyển sang trái tốn L thời gian
//                                                               sang phải tốn R thời gian 
//                                                               từ điểm i đến j( C_i = C_j) tốn C thời gian
// Tính quãng đường nhỏ nhất từ điểm sta đến end 

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
    D.assign(maxn,INF);
    //trace.assign(n,-1);
    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    D[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        auto [du,u] = pq.top();
        pq.pop();

        if(D[u] != du) continue;

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
int n,R,L,C,sta,en;
vector<vector<Edge>> E;
vector<ll> D;
//vector<vector<Edge>> temp;
int a[maxn];
void solve(){
    cin >> n >> L >> R >> C;
    cin >> sta >> en;
    FOR(i,1,n) cin >> a[i];
    E.assign(maxn, {});
    FOR(i,1,n-1) E[i].push_back({R,i+1});
    for(int i = n; i >= 2; i--) E[i].push_back({L,i-1});
    FOR(i,1,n){
                E[i].push_back({0,a[i] + n});
                E[a[i] + n].push_back({C,i});
    }
    dijiktra(n,sta,E,D);
    cout << D[en];
}
int main(){
    solve();
}
