# Graphs and Transport Networks: Algorithm Implementations

## Description
This repository contains implementations of various algorithms on graphs and transport networks.

## 1. Depth-First Search (DFS) and Breadth-First Search (BFS)
DFS and BFS are fundamental graph traversal algorithms. BFS explores the graph level by level, visiting all neighbors of a vertex before moving to the next level. On the other hand, DFS explores the graph as deeply as possible before backtracking. Both algorithms help us understand the structure of the graph and are crucial for many graph-related tasks.

### BFS Animation
![BFS Animation](https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif)

### DFS Animation
![DFS Animation](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

## 2. Kruskal's Algorithm
Kruskal's algorithm finds the Minimum Spanning Tree (MST) in a weighted connected graph. The MST is a subset of edges that connect all vertices with the minimum possible total edge weight. This algorithm is widely used in optimization problems and network design.

![Kruskal's Algorithm](https://media.proglib.io/posts/2020/09/08/574ff16387ff1b2ec365db1c75fa7ce4.gif)

## 3. Kosaraju's Algorithm
Kosaraju's algorithm identifies Strongly Connected Components (SCCs) in a directed graph. SCCs are groups of vertices where each vertex can reach any other vertex within the same group. This algorithm is valuable in tasks involving cycles and connectivity in directed graphs.

![Kosaraju's Algorithm](https://media.proglib.io/wp-uploads/-000//1/597791923c2e0_UvC39m2.gif)

## 4. Dinic's Algorithm
Dinic's algorithm is an efficient method for computing the Maximum Flow in a network with directed edges and capacities. It is an improvement over the classic Edmonds-Karp algorithm and employs multiple passes of flow through the shortest paths in a layered network.

![Dinic's Algorithm](https://media.proglib.io/posts/2020/09/08/06c0a8bbb4502b55e1b4707e397bc7f4.gif)

## 5. Hungarian Algorithm
The Hungarian algorithm solves the Assignment Problem, a special case of the maximum matching problem in a weighted bipartite graph. It efficiently finds the optimal assignment between elements of two sets with the minimum total cost.

![Hungarian Algorithm](https://media.proglib.io/posts/2020/09/08/93919687e795c90c971bdf641d0cfb0a.gif)

## 6. Dijkstra's Algorithm
Dijkstra's algorithm computes the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights. This classic algorithm is widely used in network routing, transportation planning, and other applications requiring optimal pathfinding.

![Dijkstra's Algorithm](https://du-blog.ru/media/Dijkstra_Animation.gif)

## 7. Floyd-Warshall Algorithm
The Floyd-Warshall algorithm calculates the shortest paths between all pairs of vertices in a weighted directed or undirected graph. It is capable of handling graphs with negative edge weights and is commonly used in all-pairs shortest path problems.

