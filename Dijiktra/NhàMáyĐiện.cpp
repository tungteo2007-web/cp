// Cho n địa điểm nối với nhau bới m con đường 1 km , có k dự án xây nhà máy điện với dự án i xây ở địa điểm pos_i có năng lượng p_i 
//                                                    năng lượng p_i giúp cung cấp điện cho tất cả địa điểm trong bán kính p_i

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
using namespace std;
const ll INF = 1e18 + 9;
const int maxn = 2e5+9;
struct Edge{
    ll power;
    int v;

};
struct cmp{
    bool operator()( Edge &a , Edge &b ){
           return a.power < b.power;
    }
};
bool check[maxn];
void dijiktra( int n, const vector<vector<int>> &E, vector<ll> &P){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    FOR(i,1,n) if( P[i] != INF) pq.push({P[i],i}); // CHo tât cả địa điểm có điện ban đầu vào pq
    while(!pq.empty()){
        auto [du,u] = pq.top();
        pq.pop();

        if(P[u] != du ) continue;
        for(auto v : E[u]){
            if(P[v] < du - 1 ){
                P[v] = du- 1;
                pq.push({P[v],v});
            }
        }
}
}
int n,m,k;
ll w,b;
vector<vector<int>> E;
vector<ll> P; //  P[i] == k tức là trụ điện gần nhất cách i k km
ll s,p;
void solve(){
    cin >> n >> m >> k;
    E.assign(maxn, {});
    P.assign(maxn,-1);

    FOR(i,1,m){
    int u ,v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
    }

    FOR(i,1,k){
    ll s, p;
    cin >> s >> p;
    P[s] = max(P[s] , p); // nếu cùng 1 địa điểm thì lấy cái có độ phủ lớn hơn
    }

    dijiktra(n, E, P);
//    FOR(i,1,n) cout << P[i] << " ";
    FOR(i,1,n){
    if(P[i] < 0) cout << 0; 
    else cout << 1;
    }
}
int main(){
    solve();
}
