void UpdateMySeg(vector<ll>& arr,vector<ll>& seg,ll start,ll end,ll treenode,ll idx,ll value){
 
    if(start==end){
        arr[idx] += value;
        seg[treenode] += value;
        return;
    }
 
    ll mid = (start+end)/2;
    if(idx>mid){
        //Go Right
        UpdateMySeg(arr,seg,mid+1,end,2*treenode + 1,idx,value);
    }
    else{
        // Go Left
        UpdateMySeg(arr,seg,start,mid,2*treenode,idx,value);
    }
 
    seg[treenode] = seg[2*treenode] + seg[2*treenode + 1];
 
}
 
ll QueryMySeg(vector<ll>& seg,ll start,ll end,ll treenode,ll left,ll right){
 
    //Three cases
    //1. Completely outside given range
    // Return 0
 
    if(start>right || end<left){
        return 0;
    }
 
    //2. Completely inside given range
    // Return tree[treenode]
 
    if(start>=left && end<=right){
        return seg[treenode];
    }
 
    //3. Partially Inside and Partially Outside
    // Calculate for left half and right half
 
    ll mid = (start+end)/2;
    ll leftHalfTreeAnswer = QueryMySeg(seg,start,mid,2*treenode,left,right);
    ll rightHalfTreeAnswer = QueryMySeg(seg,mid+1,end,2*treenode + 1,left,right);
 
    return leftHalfTreeAnswer + rightHalfTreeAnswer;
 
}
 
//Problem Name: String Reversal Codeforces
void solve(ll tc){
    ll n;
    cin>>n;
 
    string s;
    cin>>s;
 
    string temp = s;
    reverse(temp.begin(),temp.end());
 
    set<ll> se[35];
 
    for(ll i=0;i<n;i++){
        se[temp[i]-'a'].insert(i);
    }
 
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        arr.pb(*se[s[i]-'a'].begin());
        se[s[i]-'a'].erase(se[s[i]-'a'].begin());
    }
 
    // for(auto e:arr){
    //     cout<<e<<" ";
    // }
 
    ll ans = 0;
 
    vector<ll> seg(4*n);
    vector<ll> freq(n+1);
 
    for(ll i=arr.size()-1;i>=0;i--){
        UpdateMySeg(freq,seg,0,n,1,arr[i],1);
 
        ll before = QueryMySeg(seg,0,n,1,0,arr[i]-1);
 
        ans += before;
    }
 
    cout<<ans<<endl;
}
 
int main() {
 
    FIO;
    //seiveFill();
    //factorialFill();
    // ll tt;
    // cin>>tt;
    // for(ll i=1;i<=tt;i++){
        solve(1);
    // }
 
    return 0;
}
