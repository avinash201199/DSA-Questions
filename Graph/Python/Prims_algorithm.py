# Prim's algorithm
# Pass a Graph Matrix

import sys

# Find the vertices with minimum weight
def selectMin(setMST, weight, vertices_total):
    minimum = sys.maxsize
    vertex_min = 0
    
    for i in range(vertices_total):
        if setMST[i] == False and weight[i] < minimum:
            minimum = weight[i]
            vertex_min = i
            
    return vertex_min
    

def prim_MST(graph):
    """
    Prints the Minimun spanning tree in Graph
    """
    # number of vertices
    vertices_total = len(graph)
    
    # this list will store parent of the the vertice
    parent = [None] * vertices_total
    
    # this list will store weight of vertices
    weight = [sys.maxsize] * vertices_total
    
    # this list will know what vertice have already been visited
    setMst = [False] * vertices_total
    
    # Initializing for source vertice
    
    # as source vertice doesn't have any parent node, so we will assign -1 as its parent
    parent[0] = -1
    # weight of source vertice is zero
    weight[0] = 0
    
    for i in range(vertices_total):
        
        # Here we will get the vertice with smallest weight which has not been visited yet
        startin_vertex = selectMin(setMst, weight, vertices_total)
        
        # as we have now visited the "starting_vertex" vertice, so we will mark it as True in setMst
        setMst[startin_vertex] = True
        
        
        # finding all adjacent vertices of "starting_vertex"
        for j in range(vertices_total):
            
            # finding the vertex which is adjacent and s not already visited
            if graph[startin_vertex][j] != 0 and setMst[j] == False and graph[startin_vertex][j] < weight[j]:
                
                weight[j] = graph[startin_vertex][j]
                parent[j] = startin_vertex
    
    # print the MST
    for i in range(1, vertices_total):
        print(f"{parent[i]}->{i}, weight = {graph[parent[i]][i]}")
        
if __name__ == "__main__":

    # Example Matrix
    graph = [[0,4,3,0,0,0,1,0],
            [4,0,0,0,3,0,0,0],
            [3,0,0,8,0,5,0,0],
            [0,0,8,0,0,0,5,0],
            [0,3,0,0,0,0,6,0],
            [0,0,5,0,0,0,2,7],
            [1,0,0,0,6,2,0,0],
            [0,0,0,5,0,7,0,0]]
            
    # Calling the function
    prim_MST(graph)    