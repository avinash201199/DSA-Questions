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
void bfs(T u)
{
   queue<T> q;
           q.push(u);
        map<T,bool> visited;
        
        while(!q.empty())
        {  T front_element=q.front();
            q.pop();
            if(!visited[front_element])  
            {
                cout<<front_element<<"->";
                visited[front_element]=true; 
            }
            for(auto x:adjList[front_element])
            {
                if(!visited[front_element])   
                {
                    q.push(x.first);           
                }
            }
        }
}
void dfs_utility(T src)
    {
        map<T,bool> visited;               //use a map to decide whether a node has been visited or not
        dfs_helper(src,visited);          //the src node is the first node that is input into the graph.
    }
    void dfs_helper(T src,map<T,bool> visited)
    {
        visited[src]=true;              //As the first node(src node) is where the dfs starts,consider it is already visited(true) 
        for(auto x:adjList)            //traverse over the pairs present in the adjacency list
        {
            if(visited[x.first]==false) //if the node (u) has not been visited
            {
                dfs_helper(x.first,visited); //take the unvisited node as the source node and pass the visited map
            }
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
        g.bfs(i);
    }
   
    return 0;
}