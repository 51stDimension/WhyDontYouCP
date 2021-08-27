struct item {
    ll val;
};

struct segtree{
    ll sze;
    vector<item> seg;

    item merge(item a, item b) {
        return {a.val + b.val};
    }

    item single(ll v){
        return {v};
    }

    void init(ll n) {
        sze = 4*n + 1;
        seg.resize(2 * sze);
    }

    void BuildMySeg(vector<ll>& arr,ll start,ll end,ll treenode){

        if(start==end){
            seg[treenode] = single(arr[start]);
            return;
        }
        ll mid = (start+end)/2;
        BuildMySeg(arr,start,mid,2*treenode);
        BuildMySeg(arr,mid+1,end,2*treenode + 1);
        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);
    }

    void build(vector<ll>& arr){
        BuildMySeg(arr,0,(ll)arr.size()-1,1);
    }

    void UpdateMySeg(vector<ll>& arr,ll start,ll end,ll treenode,ll idx,ll value){

        if(start==end){
            arr[idx] = value;
            seg[treenode] = single(value);
            return;
        }
        ll mid = (start+end)/2;
        if(idx>mid){
            UpdateMySeg(arr,mid+1,end,2*treenode + 1,idx,value);
        }
        else{
            UpdateMySeg(arr,start,mid,2*treenode,idx,value);
        }
        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);

    }

    void update(vector<ll>& arr,ll idx,ll val){
        UpdateMySeg(arr,0,(ll)arr.size()-1,1,idx,val);
    }

    item QueryMySeg(ll start,ll end,ll treenode,ll left,ll right){
        if(start>right || end<left){
            return {0};
        }

        if(start>=left && end<=right){
            return seg[treenode];
        }

        ll mid = (start+end)/2;
        item leftHalfTreeAnswer = QueryMySeg(start,mid,2*treenode,left,right);
        item rightHalfTreeAnswer = QueryMySeg(mid+1,end,2*treenode + 1,left,right);

        return merge(leftHalfTreeAnswer,rightHalfTreeAnswer);
    }

    item query(vector<ll>& arr,ll left,ll right){
        return QueryMySeg(0,(ll)arr.size()-1,1,left,right);
    }
};
