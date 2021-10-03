//KAHN'S ALGORITHM TO FIND TOPOLOGICAL SORT OF DAG

//Input Parameters : 
//  N -> no of vertices
//  adj -> adjacency list representation of DAG

//Return : 
// vector of one of possible topological sort 

vector<int> topoSort(int N, vector<int> adj[]){
  queue<int> q;
  vector<int> inDegree(N,0), topoOrder;
  
  for(int i = 0; i < N; i++){
    for(auto node : adj[i]){
      inDegree[node]++;
    }    
  }

  for(int i = 0; i< N; i++){
    if(inDegree[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int tp = q.front();
    q.pop();
    for(auto node : adj[tp] ){
      inDegree[node]--;
      if(inDegree[node] == 0){
        q.push(node);
      }
    }
    topoOrder.push_back(tp);
  }

  return topoOrder;

}