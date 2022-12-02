from breadth_first_search import breadth_first_search 

def test():
    graph = dict() 
    graph['A'] = ['B', 'G', 'D'] 
    graph['B'] = ['A', 'F', 'E'] 
    graph['C'] = ['F', 'H'] 
    graph['D'] = ['F', 'A'] 
    graph['E'] = ['B', 'G'] 
    graph['F'] = ['B', 'D', 'C'] 
    graph['G'] = ['A', 'E'] 
    graph['H'] = ['C'] 
    
    print(breadth_first_search(graph, 'A'))

if __name__ == "__main__":
    test()
