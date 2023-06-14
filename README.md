# ford_fulkerson algorithm
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Ford-Fulkerson algorithm is a greedy approach for calculating the maximum possible flow in a network or a graph.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
The following is simple idea of Ford-Fulkerson algorithm:
1. Start with initial flow as 0.
2. While there exists an augmenting path from the source to the sink:  
	Find an augmenting path using any path-finding algorithm, such as breadth-first search or depth-first search.
	Determine the amount of flow that can be sent along the augmenting path, which is the minimum residual capacity along the edges of the path.
	Increase the flow along the augmenting path by the determined amount.
3.Return the maximum flow.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time Complexity : O(|V| * E^2) ,where E is the number of edges and V is the number of vertices.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Space Complexity :O(V) , as we created queue.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
