def dfs(graph, start):
    """
    Performs Depth-First Search (DFS) on a graph starting from a given vertex.

    Args:
        graph: A dictionary representing the graph as an adjacency list.
        start: The starting vertex for the DFS traversal.

    Returns:
        A list containing the visited vertices in DFS order.
    """

    visited = set()
    stack = [start]

    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(neighbor for neighbor in graph[vertex] if neighbor not in visited)

    return visited

# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

start_vertex = 'A'
visited_vertices = dfs(graph, start_vertex)
print("Visited vertices:", visited_vertices)