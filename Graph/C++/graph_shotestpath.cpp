#include<bits/stdc++.h>
using namespace std;

vector<int> g[8];

void addedge(int a , int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}


void shortestpath(int s)
{
//start vertex is s
int l=1;

queue<int> q;
q.push(s);

vector<bool> visited(8,false);

while(q.empty()==false)
{ 

    int v = q.front();
    q.pop();

    visited[v]=true;
    cout<<v<<" ";
    

    for(int i=0;i<g[v].size();i++)
    {
        if(visited[g[v][i]]==false)
        {   
            //cout<<l<<" ";
            //visited[g[v][i]] = true;
            q.push(g[v][i]);
        }
    }
    
}


}

int main()
{

addedge(1,2);
addedge(2,3);
addedge(3,4);
addedge(1,5);
addedge(5,6);
addedge(6,7);

shortestpath(1);





    return 0;
}