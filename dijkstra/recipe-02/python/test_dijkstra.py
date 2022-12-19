from dijkstra import find_shortest_path

graph = dict() 
graph['A'] = {'B': 5, 'D': 9, 'E': 2} 
graph['B'] = {'A': 5, 'C': 2} 
graph['C'] = {'B': 2, 'D': 3} 
graph['D'] = {'A': 9, 'F': 2, 'C': 3} 
graph['E'] = {'A': 2, 'F': 3} 
graph['F'] = {'E': 3, 'D': 2} 

shortest_distance_table = find_shortest_path(graph, 'A') 

for k in sorted(shortest_distance_table): 
    print("{} - {}".format(k,shortest_distance_table[k])) 

