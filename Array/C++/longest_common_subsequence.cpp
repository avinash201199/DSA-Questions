class Solution {
public:
    int longestCommonSubsequence(string t, string s) {
        int tn=t.size(),sn=s.size();
        if(tn>sn){
            swap(tn,sn);
            swap(t,s);
        }
        vector<int> v(tn+1);
        auto x=v;
        int ans=0;
        for(int i=0 ; i<sn ; i++){
            for(int j=0 ; j<tn ; j++){
                if(s[i]==t[j]){
                    v[j+1]=x[j]+1;
                }
                else{
                    v[j+1]=max(v[j],x[j+1]);
                }
            }
            swap(x,v);
            v.clear();
            v.resize(tn+1);
        }
        return x[tn];
    }
};
