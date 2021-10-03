#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define lli             long long int
#define ll              long long
#define pb              push_back
#define pob             pop_back
#define pii             pair<int,int>
#define vi              vector<int>
#define vll             vector <ll>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define mod             1000000007
#define inf1            1e9
#define inf2            1e18
#define N               200009
#define loop(i,a,b)     for (int i=a;i<b;i++)
#define PI              3.14159265358979323846
#define np              next_permutation
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(tc)            int tc; cin>>tc; while(tc--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void methoding()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// ******************************************************************************
vi adj[2001] ; int  vis[2001];

void dfs ( int n ) {
	vis[n] = 1;
	for ( int i = 0; i < adj[n].size(); i++) {
		int c = adj[n][i];
		if (vis[c] == 0)
			dfs(c);
	}

}

int32_t main() {
	methoding();
	w(tc) {

		int n , m ; cin >> n >> m;
		memset(adj , 0, sizeof(adj)); memset(vis , 0, sizeof(vis));
		while (m--) {
			int x , y; cin >> x >> y;
			adj[x].pb(y) ; adj[y].pb(x);
		}
		int c = 0;

		loop(i, 1, n + 1) {
			if (vis[i] == 0) {dfs(i); c++;}
		}
		cout << "Connected Components :: " << c << endl;

	}

	return 0;
}