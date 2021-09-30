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
        {  T front_element=q.front();//record/store the first element
            q.pop(); //pop the front element
            if(!visited[front_element])//visited[front_element]==0 or false  
            {
                cout<<front_element<<"->";
                visited[front_element]=true; //if visited map does not have the front_element,make it true
            }
            for(auto x:adjList[front_element])//traverse over the pairs in the list corresponding to front_element
            {
                if(!visited[front_element])   //if front_element is not present in visited(as it is false)
                {
                    q.push(x.first);          //add the element(u) not traversed yet in the graph inside the queue 
                }
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