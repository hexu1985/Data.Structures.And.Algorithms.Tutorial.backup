DISTANCE = 0 
PREVIOUS = 1 

def get_distance(table, vertex):
    return table[vertex][DISTANCE] 

def set_distance(table, vertex, new_distance): 
    table[vertex][DISTANCE] = new_distance 
        
def set_previous(table, vertex, previous_node): 
    table[vertex][PREVIOUS] = previous_node 

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

def initialize_distance_table(table, origin):
    for vertex in table.keys():
        if vertex == origin:
            table[vertex] = [0, None]
        else:
            table[vertex] = [float('inf'), None]
    return table

def dijkstra(graph, table, origin): 
    initialize_distance_table(table, origin)
    included_vertices = list()
    while len(included_vertices) < len(table.keys()):
        current_node = get_shortest_unincluded_vertex(table, included_vertices)
        included_vertices.append(current_node)
        adjacent_nodes = graph[current_node]
        for vertex in set(adjacent_nodes).difference(set(included_vertices)):
            current_distance = get_distance(table, vertex)
            new_distance = get_distance(table, current_node) + edge_length(graph, current_node, vertex) 
            if new_distance < current_distance:
                set_distance(table, vertex, new_distance)
                set_previous(table, vertex, current_node)
    return table

graph = dict() 
graph['s'] = {'t': 10, 'y': 5} 
graph['t'] = {'x': 1, 'y': 2} 
graph['x'] = {'z': 4} 
graph['y'] = {'t': 3, 'x': 9, 'z': 2} 
graph['z'] = {'s': 7, 'x': 6} 

table = dict() 
table = { 
        's': [float("inf"), None], 
        't': [float("inf"), None], 
        'x': [float("inf"), None], 
        'y': [float("inf"), None], 
        'z': [float("inf"), None], 
}

shortest_distance_table = dijkstra(graph, table, 's') 

for k in sorted(shortest_distance_table): 
    print("{} - {}".format(k,shortest_distance_table[k])) 

