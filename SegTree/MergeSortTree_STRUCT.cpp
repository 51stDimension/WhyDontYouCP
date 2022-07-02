struct item {
    vector<int> val;
};

struct segtree{
    int sze;
    vector<item> seg;

    item merge(item a, item b) {
        vector<int> v3;
        auto v1 = a.val;
        auto v2 = b.val;
        int i = 0;
        int j = 0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<=v2[j]){
                v3.pb(v1[i]);
                i++;
            }   
            else{
                v3.pb(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            v3.pb(v1[i]);
            i++;
        }
        while(j<v2.size()){
            v3.pb(v2[j]);
            j++;
        }
        return {v3};
    }

    item single(int v){
        return {{v}};
    }

    void init(int n) {
        seg.resize(5*n);
    }

    void BuildMySeg(vector<int>& arr,int start,int end,int treenode){

        if(start==end){
            seg[treenode] = single(arr[start]);
            return;
        }
        int mid = (start+end)/2;
        BuildMySeg(arr,start,mid,2*treenode);
        BuildMySeg(arr,mid+1,end,2*treenode + 1);
        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);
    }

    void build(vector<int>& arr){
        BuildMySeg(arr,0,(int)arr.size()-1,1);
    }

    int QueryMySeg(int start,int end,int treenode,int left,int right,int k){
        if(start>right || end<left){
            return 0;
        }

        if(start>=left && end<=right){
            int count = upper_bound(seg[treenode].val.begin(),seg[treenode].val.end(),k-1) - seg[treenode].val.begin(); 
            return count;
        }

        int mid = (start+end)/2;
        int leftHalfTreeAnswer = QueryMySeg(start,mid,2*treenode,left,right,k);
        int rightHalfTreeAnswer = QueryMySeg(mid+1,end,2*treenode + 1,left,right,k);

        return leftHalfTreeAnswer+rightHalfTreeAnswer;
    }

    int query(vector<int>& arr,int left,int right,int k){
        return QueryMySeg(0,(int)arr.size()-1,1,left,right,k);
    }
};
