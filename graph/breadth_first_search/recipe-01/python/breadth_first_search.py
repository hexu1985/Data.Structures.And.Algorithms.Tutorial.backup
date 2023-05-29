from collections import deque 

def breadth_first_search(graph, root): 
    visited_vertices = [root]
    graph_queue = deque([root]) 
    node = root 
    
    while len(graph_queue) > 0: 
        node = graph_queue.popleft() 
        adj_nodes = sorted(graph[node])     # sort to ensure visiting ordered confirmed 
    
        for elem in adj_nodes:
            if elem not in visited_vertices:
                visited_vertices.append(elem)
                graph_queue.append(elem)
    
    return visited_vertices 

