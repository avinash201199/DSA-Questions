#Python Program to perform DFS(Depth First Search)
#Python dictionary to acreate an adjacency list
g = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

# Keeping track of visited nodes.
visited = set() 

#DFS FUNCTION
def dfs(visited, g, node):  
  if node not in visited:
    print (node)
    visited.add(node)
    for neighbour in g[node]:
      dfs(visited, g, neighbour)

print("DFS traversal is:")
dfs(visited, g, '5')
