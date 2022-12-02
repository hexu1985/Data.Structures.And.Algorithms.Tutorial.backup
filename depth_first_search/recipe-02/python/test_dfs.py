from depth_first_search import depth_first_search

def test():
    graph = dict() 
    graph['A'] = ['B', 'S'] 
    graph['B'] = ['A'] 
    graph['S'] = ['A','G','C'] 
    graph['D'] = ['C'] 
    graph['G'] = ['S','F','H'] 
    graph['H'] = ['G','E'] 
    graph['E'] = ['C','H'] 
    graph['F'] = ['C','G'] 
    graph['C'] = ['D','S','E','F'] 

    print(depth_first_search(graph, 'A'))

if __name__ == "__main__":
    test()
