def depth_first_search_recurve(graph, node, visited_vertices): 
    visited_vertices.append(node);

    adj_nodes = sorted(graph[node])     # sort to ensure visiting ordered confirmed 
    for elem in adj_nodes:
        if elem not in visited_vertices:
            depth_first_search_recurve(graph, elem, visited_vertices)

def depth_first_search(graph, root):
    visited_vertices = list()
    depth_first_search_recurve(graph, root, visited_vertices)
    return visited_vertices 
