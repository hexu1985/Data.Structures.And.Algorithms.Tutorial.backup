def depth_first_search(graph, root): 
    visited_vertices = list() 
    graph_stack = list([root]) 
    node = root 
    while len(graph_stack) > 0: 
        node = graph_stack.pop()
        if node not in visited_vertices: 
            visited_vertices.append(node) 
            adj_nodes = reversed(sorted(graph[node]))     # sort to ensure visiting ordered confirmed 

            for elem in adj_nodes:
                graph_stack.append(elem)

    return visited_vertices 


