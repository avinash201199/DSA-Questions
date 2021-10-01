    // https://codeforces.com/contest/1461/problem/B
    
    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define vi vector<int>
    #define vvi vector < vi >
    #define FOR(i,k,n) for ( int i=k; i<n; i++ )
    #define ROF(i,k,n) for ( int i=k; i>n; i-- )
    #define ll long long
     
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    vvi a;
    int n,m;
     
    bool isValid(int i,int j)
    {
        if ( i>n-1 || j<0 || j>m-1 )
                return 0;
        return 1;
    }
     
    int recur(int i,int j)
    {
        int mxpd = a[i][j];
        int level = 1;
     
        while(mxpd)
        {
            if ( !isValid(i+level,j-level) || !isValid(i+level,j+level) )
                break;
            mxpd = min(mxpd-1,a[i+level][j-level]);
            mxpd = min(mxpd,a[i+level][j+level]);
            if ( mxpd!=0 )
                level++;
        }
        return level;
    }
     
    void fnc()
    {
        cin>>n>>m;
        a.assign(n,vi(m));
        
        FOR(i,0,n)
            FOR(j,0,m)
            {
                char x;
                cin>>x;
                a[i][j] = x=='*';
            }
        
        ROF(i,n-2,-1)
            FOR(j,0,m)
                if ( a[i][j]==1 )
                    a[i][j]+=a[i+1][j];
     
     
        ll ans=0;
     
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if ( a[i][j]==0 )
                    continue;
                int base = recur(i,j);
                ans+= base;
            }
        }
        cout<<ans;
    }
     
    int main(){
        int n;
        cin>>n;
        FOR(i,0,n)
        {
            fnc();
            cout<<"\n";
        }
    }