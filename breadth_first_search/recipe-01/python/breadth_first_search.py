from collections import deque 

def breadth_first_search(graph, root): 
        visited_vertices = list() 
        graph_queue = deque([root]) 
        visited_vertices.append(root) 
        node = root 

        while len(graph_queue) > 0: 
            node = graph_queue.popleft() 
            adj_nodes = graph[node]

            for elem in sorted(adj_nodes):
                if elem in visited_vertices:
                    continue
                visited_vertices.append(elem)
                graph_queue.append(elem)

        return visited_vertices 

