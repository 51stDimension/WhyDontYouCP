struct item {
    ll val;
};

struct segtree{

    ll sze;

    vector<item> seg;
    vector<item> lazy;

    item merge(item a, item b) {
        return {a.val + b.val};
    }
    item single(ll v){
        return {v};
    }
    void init(ll n) {
        sze = 4*n + 1;
        seg.resize(2 * sze);
        lazy.resize(2 * sze);
    }

    void BuildMySeg(vector<ll>& arr,ll start,ll end,ll treenode){

        if(start==end){
            lazy[treenode] = single(0);
            seg[treenode] = single(arr[start]);
            return;
        }

        ll mid = (start+end)/2;
        BuildMySeg(arr,start,mid,2*treenode);
        BuildMySeg(arr,mid+1,end,2*treenode + 1);

        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);
        
        lazy[treenode] = single(0);
    }

    void build(vector<ll>& arr){
        BuildMySeg(arr,0,(ll)arr.size()-1,1);
    }

    void UpdateMySeg(vector<ll>& arr,ll start,ll end,ll treenode,ll left,ll right,ll value){

        if (lazy[treenode].val != 0)
        {   
            seg[treenode].val += (end-start+1)*(lazy[treenode].val);   

            if (start != end)
            {
                lazy[treenode*2 + 1].val   += lazy[treenode].val;
                lazy[treenode*2].val   += lazy[treenode].val;
            }
            lazy[treenode] = single(0);
        }

        if(start>right || end<left){
            return;
        }

        if(start>=left && end<=right){
            seg[treenode].val += (end-start+1)*value;

            if(start != end){
                lazy[treenode*2 + 1].val   += value;
                lazy[treenode*2].val   += value;
            }
            return;
        }

        ll mid = (start+end)/2;

        UpdateMySeg(arr,mid+1,end,2*treenode + 1,left,right,value);
        UpdateMySeg(arr,start,mid,2*treenode,left,right,value);
        
        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);

    }

    void update(vector<ll>& arr,ll left,ll right,ll val){
        UpdateMySeg(arr,0,(ll)arr.size()-1,1,left,right,val);
    }

    item QueryMySeg(ll start,ll end,ll treenode,ll left,ll right){

        if (lazy[treenode].val != 0)
        {
            seg[treenode].val += (end-start+1)*(lazy[treenode].val);     
            if (start != end)
            {
                lazy[treenode*2 + 1].val   += lazy[treenode].val;
                lazy[treenode*2].val   += lazy[treenode].val;
            }
            lazy[treenode] = single(0);
        }

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
