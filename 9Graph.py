class Graph:
    def __init__(self, num_of_nodes, directed=True):
        self.m_num_of_nodes = num_of_nodes
        self.m_directed = directed

    m_list_of_edges = []


    def addEdge(self, N1, N2, weight=1):
        self.m_list_of_edges.append([N1, N2, weight])

        if not self.m_directed:
            self.m_list_of_edges.append([N1, N2, weight])


    def Display_edge_list(self):
        num_of_edges = len(self.m_list_of_edges)
        for i in range(num_of_edges):
            print("edge ", i + 1, ": ", self.m_list_of_edges[i])


graph = Graph(5)

graph.addEdge(0, 0, 25)
graph.addEdge(0, 1, 5)
graph.addEdge(0, 2, 3)
graph.addEdge(1, 3, 1)
graph.addEdge(1, 4, 15)
graph.addEdge(4, 2, 7)
graph.addEdge(4, 3, 11)

graph.Display_edge_list()