struct CMP_PRIORITY{
    bool operator()(const cow &a , const cow& b)const {
        return a.idx >= b.idx;
    }
};
priority_queue<cow, vector<cow> , CMP_PRIORITY> pq;
