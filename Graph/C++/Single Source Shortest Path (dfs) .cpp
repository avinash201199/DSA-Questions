#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define lli             long long int
#define ll              long long
#define pb              push_back
#define pob             pop_back
#define pii             pair<int,int>
#define vpii            vector<pair<int,int>>
#define vi              vector<int>
#define vll             vector <ll>
#define mii             map<int,int>
#define mod             1000000007
#define inf1            1e9
#define inf2            1e18
#define N               200005
#define input           int n;cin>>n; int a[n]; loop(i,0,n){ cin>>a[i]; }
#define loop(i,a,b)     for (int i=a;i<b;i++)
#define rloop(i,a,b)    for (int i=a;i>b;i--)
#define PI              3.14159265358979323846
#define np              next_permutation
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(tc)           int tc; cin>>tc; while(tc--)
#define sort(a)         sort(a.begin(),a.end())
#define endl            "\n"

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */
void bhagg_bsdk() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// ******************************************************************************
int n;
// vi adj[n] ; int vis[n] , dist[n];
vi adj[10001] ; int vis[10001] , dist[10001];

void dfs (int x , int d) {
	vis[x] = 1; dist[x] = d;
	for (auto it : adj[x]) {
		if (vis[it] == 0) {
			dfs(it , d + 1);
		}
	}
}

int32_t main() {
	bhagg_bsdk();
	int  m ; cin >> n >> m;
	int a , b ;
	loop(i, 0, m) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	loop(i, 1, n + 1) { cout << dist[i] << " "; }



	return 0;
}