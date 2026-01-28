// Đây là 1 ví dụ của spare table lưu 2 phần tử lớn nhất trong 1 đoạn l , r 
ll d[2*N],h[2*N];
struct quadra{
    ll M1, M2;
    ll idx1,idx2;
};
quadra maxR[2*N][LOGN], maxL[2*N][LOGN];
 
quadra merge( quadra t1, quadra t2){
    // vector<ll> ss;
    // ss.pb(t1.fi); ss.pb(t1.se); ss.pb(t2.fi); ss.pb(t2.se);
    // sort(ss.begin(), ss.end(), greater<ll>());
    // return mp(ss[0], ss[1]);
    ll ar[4] = {t1.M1, t1.M2,t2.M1,t2.M2};
    ll pos[4] = {t1.idx1, t1.idx2, t2.idx1, t2.idx2};
    ll ma1 = -oo,  ma2 = -oo;
    ll midx1 = -1; int midx2 = -1;
    FOR(i,0,3){
        ll val =  ar[i];
        int idx = pos[i];
        if(idx == -1);
        if(idx == midx1 || idx == midx2) continue;
        if(ar[i] > ma1){
            ma2 = ma1;
            midx2 = midx1;
            ma1 = val;
            midx1 = idx;
        }
        else if(ar[i] > ma2){
            ma2 = val;
            midx2 = idx;
        }
    }
    return {ma1, ma2, midx1, midx2};
}
 
void RMQ(quadra maxA[][LOGN]){
    FOR(j,1,LOGN-1) FOR(i,1, 2*n - (1<<j) + 1 ){
        maxA[i][j] = merge(maxA[i][j-1] ,  maxA[i+(1 << (j-1)) ][j-1]);
    }
}
 
quadra getMAX(ll l , ll r, quadra maxA[][LOGN]){
    int k  = 31 - __builtin_clz(r - l + 1);
    return merge(maxA[l][k], maxA[r - (1<< k) + 1][k]);
}
