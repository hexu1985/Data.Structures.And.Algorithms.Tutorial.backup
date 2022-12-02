from dijkstra import find_shortest_path

graph = dict() 
graph['s'] = {'v': 1, 'w': 4} 
graph['v'] = {'w': 2, 't': 6} 
graph['w'] = {'t': 3} 
graph['t'] = dict()

table = dict() 
table = { 
        's': [0, None], 
        'v': [float("inf"), None], 
        'w': [float("inf"), None], 
        't': [float("inf"), None], 
}


shortest_distance_table = find_shortest_path(graph, table, 's') 


for k in sorted(shortest_distance_table): 
    print("{} - {}".format(k,shortest_distance_table[k])) 

