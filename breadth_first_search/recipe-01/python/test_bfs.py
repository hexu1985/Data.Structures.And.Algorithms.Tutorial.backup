from breadth_first_search import breadth_first_search 

def test():
    graph = dict() 
    graph['s'] = ['a', 'b']
    graph['a'] = ['s', 'c'] 
    graph['b'] = ['s', 'c', 'd'] 
    graph['c'] = ['a', 'b', 'd', 'e'] 
    graph['d'] = ['b', 'c', 'e'] 
    graph['e'] = ['c', 'd'] 
    
    print(breadth_first_search(graph, 's'))

if __name__ == "__main__":
    test()
