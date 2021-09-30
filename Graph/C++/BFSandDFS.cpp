#include<iostream>
#include<set>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T,list<pair<T,int>>> adjList;
    void addEdge(T u,T v,int dist,bool bidirec=1){
          adjList[u].push_back(make_pair(v,dist));
          if(bidirec!=0)
          {
              adjList[v].push_back(make_pair(u,dist));
          }
    }
    void print_adj()
    {
        for(auto x:adjList)
        {
          cout<<x.first<<" ";    
        for(auto a:x.second)
        {
            cout<<"("<<a.first<<","<<a.second<<")";
        }
        cout<<"\n";
        }
    }
};
int main()
{   Graph<int> g;
     int n;
     cin>>n;
    for(int i=0;i<n;++i)
    {
        g.addEdge(i,i+1,0);
        g.print_adj();
    }
    return 0;
}