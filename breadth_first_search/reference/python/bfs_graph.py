from collections import deque 

graph = dict() 
graph['s'] = ['a', 'b']
graph['a'] = ['s', 'c'] 
graph['b'] = ['s', 'c', 'd'] 
graph['c'] = ['a', 'b', 'd', 'e'] 
graph['d'] = ['b', 'c', 'e'] 
graph['e'] = ['c', 'd'] 


def breadth_first_search(graph, root): 
        visited_vertices = list() 
        graph_queue = deque([root]) 
        visited_vertices.append(root) 
        node = root 

        while len(graph_queue) > 0: 
            node = graph_queue.popleft() 
            adj_nodes = graph[node] 

            remaining_elements = set(adj_nodes).difference(set(visited_vertices)) 
            if len(remaining_elements) > 0: 
                for elem in sorted(remaining_elements): 
                    visited_vertices.append(elem) 
                    graph_queue.append(elem) 

        return visited_vertices 


print(breadth_first_search(graph, 's'))
