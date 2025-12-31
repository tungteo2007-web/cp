#include<bits/stdc++.h>
#define ll  long long
#define FOR(i,a,b)  for(int i = a, _b = (b); i <= _b; i++)
#define fi first
#define se second
using namespace std;
const int maxn = 5e5+9;
int a[maxn];
int freq[maxn];
pair<int ,int> st[4*maxn]; // pos , freq
pair<int,int> Merge(pair<int,int> &a, pair<int ,int > &b){
    if(a.se != b.se) return (a.se < b.se ? a: b);
    else return (a.fi < b.fi ? a : b);

}
void build(int idx, int l , int r ){
    if( l ==  r){
        st[idx].fi = l;
        st[idx].se = freq[a[l]];
        return;
    }
    int m =(l +  r)/2;
    build(2*idx, l ,m);
    build(2*idx+1,m+1,r);
    //st[idx].se = min(st[2*idx].se, st[2*idx+1].se);
   st[idx] = Merge(st[2*idx], st[2*idx + 1]);
}

void update(int idx, int l , int r , int pos, int val){
    if(l == r){
        st[idx].fi = pos;
        st[idx].se = freq[val];
        return;
    }
    int m = (l + r)/2;
    if(pos <= m) update(2*idx,1,m,pos, val);
    else update(2*idx+1,m+1,r,pos,val);
//    st[idx] = min(st[2*idx], st[2*idx+1]);
   st[idx] = Merge(st[2*idx], st[2*idx + 1]);
}
pair<int,int> query(int idx, int l , int r , int i , int j){
    if( l > j || r < i) return {0, maxn + 9};
    if(i <= l && r <= j) return {st[idx].fi, st[idx].se};
    int m = (l+r)/2;
    auto [x1,y1] = query(2*idx, l, m, i,j);
    auto [x2,y2] = query(2*idx + 1, m + 1, r,i,j);
    if(y1 <= y2) return {x1,y1};
    else return {x2,y2};
}
void solve(){
    int n,m,k; cin >> n >> m >> k;
    FOR(i,1,n){
        cin >> a[i];
        freq[a[i]]++;
    }
//    FOR(j,n+1,n+k) a[i] = m;
    build(1,1,n);

//    auto [x,y] = query(1,1,n,1,n);
//    cout << x << " " << y;

//    FOR(i,1,k){
//        int x; cin >> x;
//        cout << query(1,1,n,1,n);
}

int main(){
    solve();

}
