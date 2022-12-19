DISTANCE = 0 
PREVIOUS_NODE = 1 
INFINITY = float('inf')  

def get_shortest_distance(table, vertex):
    shortest_distance = table[vertex][DISTANCE] 
    return shortest_distance 

def set_shortest_distance(table, vertex, new_distance): 
    table[vertex][DISTANCE] = new_distance 
        
def set_previous_node(table, vertex, previous_node): 
    table[vertex][PREVIOUS_NODE] = previous_node 

def has_edge(graph, from_vertex, to_vertex):
    return to_vertex in graph[from_vertex]

def edge_length(graph, from_vertex, to_vertex): 
    return graph[from_vertex][to_vertex] 
        
def get_shortest_unincluded_vertex(table, included_vertices): 
    unincluded_vertices = list(set(table.keys()).difference(set(included_vertices))) 
    assumed_min = table[unincluded_vertices[0]][DISTANCE] 
    min_vertex = unincluded_vertices[0] 
    for node in unincluded_vertices: 
        if table[node][DISTANCE] < assumed_min: 
            assumed_min = table[node][DISTANCE] 
            min_vertex = node 
    return min_vertex 

def initialize_shortest_distacne_table(graph, table, origin):
    for vertex in graph.keys():
        if vertex == origin:
            table[vertex] = [0, None]
        elif has_edge(graph, origin, vertex):
            table[vertex] = [edge_length(graph, origin, vertex), origin]
        else:
            table[vertex] = [float('inf'), None]
    return table

def find_shortest_path(graph, table, origin): 
    included_vertices = [origin]
    initialize_shortest_distacne_table(graph, table, origin)
    while len(included_vertices) < len(table.keys()):
        current_node = get_shortest_unincluded_vertex(table, included_vertices)
        included_vertices.append(current_node)
        adjacent_nodes = graph[current_node]
        for vertex in set(adjacent_nodes).difference(set(included_vertices)):
            current_distance = get_shortest_distance(table, vertex) 
            new_distance = get_shortest_distance(table, 
                            current_node) + edge_length(graph, current_node, vertex) 
            if new_distance < current_distance:
                set_shortest_distance(table, vertex, new_distance)
                set_previous_node(table, vertex, current_node)
    return table

