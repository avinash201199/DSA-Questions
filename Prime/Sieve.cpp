#include<iostream>
#include<vector>
#include<climits>
#include<cstddef>
#include<string>
#include<cmath>
#include<map>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef map<ll,bool> mllb;
typedef unordered_set<char> ucst;
typedef unordered_map<ll,bool> umllb;
#define PI 3.1415926535897932384626
#define pb push_back
#define mp make_pair
const ll mod=10e9+7;

class Sieve
{
    private:
        void genPrime()
        {
            for(ll i=0;i<n+1;i++)
                Prime.push_back(true);
            Prime.at(0)=false;
            Prime.at(1)=false;
            for(ll i=2;i*i<=n;i++)
                if(Prime[i])
                    for(ll j=i*i;j<=n;j+=i)
                        Prime[j]=false;
        }

    public:
        ll n;
        vector<bool> Prime;

        void printPrime()
        {
            for(ll i=0;i<=n;i++)
                if(Prime[i])
                    cout<<i<<" ";
            cout<<endl;
        }

        ll countPrime(ll l,ll h)
        {
            ll count=0;
            for(ll i=l;i<=h;i++)
                if(Prime[i])
                    count++;
            return count;
        }
    
        bool isPrime(ll x)
        {
            if(x>=0 && x<=n)
            {
                if(Prime.at(x))
                    return true;
            }
            return false;
        }

        Sieve(ll n)
        {
            this->n=n;
            genPrime();
        }
};

int main()
{
    int RANGE=1000001;
    Sieve* sieve=new Sieve(RANGE);
    ll lowerBound,upperBound;
    cout<<"Enter lower bound: ";
    cin>>lowerBound;
    cout<<"Enter upper bound: ";
    cin>>upperBound;
    for(ll i=lowerBound;i<=upperBound;i++)
    {
        if(sieve->isPrime(i))
            cout<<i<<endl;
    }
    
    return 0;
}