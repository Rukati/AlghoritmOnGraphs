# Графы и транспортные сети: Реализации алгоритмов

## Описание
Данный репозиторий содержит реализации различных алгоритмов на графах и транспортных сетях.

# 1. Поиск в глубину и ширину
BFS — это алгоритм, который начинает обходить граф или дерево с выбранной вершины и идет на всех доступных соседей данной вершины. Затем он переходит к соседям соседей, пока не обойдет все вершины в текущем уровне. Затем он переходит на следующий уровень и продолжает обход на всех вершинах этого уровня. Этот процесс продолжается до тех пор, пока не будут посещены все вершины.

DFS — это алгоритм, который начинает обходить граф или дерево с выбранной вершины и идет вглубь структуры, как можно дальше, пока не достигнет конечной вершины или не обойдет все доступные вершины. Когда алгоритм достигает вершины, у которой нет необойденных соседей, он возвращается назад и продолжает обход от предыдущей вершины до тех пор, пока не будут посещены все вершины.

## BFS
![BFS Animation](https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif)

## DFS
![DFS Animation](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

# 2. Алгоритм Краскала
Алгоритм Краскала — это алгоритм для нахождения минимального остовного дерева (МОД) во взвешенном связном графе. Минимальное остовное дерево — это подмножество ребер графа, которое содержит все его вершины и обладает минимальной возможной суммой весов ребер.

![Алгоритм Краскала](https://media.proglib.io/posts/2020/09/08/574ff16387ff1b2ec365db1c75fa7ce4.gif)

# 3. Алгоритм Косараджу
Косараджу — это алгоритм, который используется для нахождения компонент сильной связности в ориентированном графе. Компоненты сильной связности — это максимальные подмножества вершин графа, в которых каждая вершина может быть достигнута из любой другой вершины в этом подмножестве.

![Алгоритм Косараджу](https://media.proglib.io/wp-uploads/-000//1/597791923c2e0_UvC39m2.gif)

# 4. Алгоритм Диница
Алгоритм Диница — это эффективный алгоритм для нахождения максимального потока в сети с ориентированными ребрами и емкостями на ребрах. Он является усовершенствованным вариантом алгоритма Эдмондса-Карпа, и его основной идеей является использование многократных пропусков потока через кратчайшие возможные пути в слоистой сети.

![Алгоритм Диница](https://media.proglib.io/posts/2020/09/08/06c0a8bbb4502b55e1b4707e397bc7f4.gif)

# 5. Венгерский Алгоритм
Венгерский алгоритм — это оптимальный комбинаторный алгоритм, используемый для решения задачи о назначениях, которая является одной из разновидностей задачи о максимальном паросочетании во взвешенном двудольном графе. Он разработан для нахождения наилучшего соответствия между элементами двух наборов с минимальными затратами.

![Алгоритм Венгерский](https://media.proglib.io/posts/2020/09/08/93919687e795c90c971bdf641d0cfb0a.gif)

# 6. Алгоритм Дейкстры
Алгоритм Дейкстры — это алгоритм для нахождения кратчайшего пути от одной вершины графа до всех остальных вершин с неотрицательными весами ребер. Он является одним из классических алгоритмов на графах и применяется во многих областях, таких как маршрутизация в компьютерных сетях, планирование маршрутов в транспортных системах и других задачах, где требуется найти оптимальный путь.

![Алгоритм Дейкстры](https://du-blog.ru/media/Dijkstra_Animation.gif)

# 6. Алгоритм Флойда-Уоршелла
Алгоритм Флойда-Уоршелла — это алгоритм для нахождения кратчайших путей между всеми парами вершин во взвешенном ориентированном или неориентированном графе. Он может использоваться для нахождения кратчайших расстояний между всеми вершинами в графе, даже если граф содержит ребра с отрицательными весами.

# P.s. Весь код сделан в обучающих целях
Я не являюсь профессиональным разработчиком, данные программы сделаны в целях обучения, я никого не призываю использовать данный код как профессиональный.

# Graphs and transport networks: Implementations of algorithms

## Description
This repository contains implementations of various algorithms on graphs and transport networks.

# 1. Search in depth and width
BFS is an algorithm that starts traversing a graph or tree from a selected vertex and goes to all available neighbors of that vertex. It then moves on to the neighbors' neighbors until it has bypassed all the vertices in the current level. Then it goes to the next level and continues its traversal at all vertices of this level. This process continues until all vertices have been visited.

DFS is an algorithm that starts traversing a graph or tree from a selected vertex and goes deep into the structure, as far as possible, until it reaches the final vertex or bypasses all available vertices. When the algorithm reaches a vertex that has no untraversed neighbors, it goes back and continues traversing from the previous vertex until all vertices have been visited.

## BFS
![BFS Animation](https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif)

## DFS
![DFS Animation](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

# 2. Kruskal's algorithm
Kruskal's algorithm is an algorithm for finding the minimum spanning tree (MST) in a weighted connected graph. A minimum spanning tree is a subset of the edges of a graph that contains all of its vertices and has the smallest possible sum of edge weights.

![Kruskal's algorithm](https://media.proglib.io/posts/2020/09/08/574ff16387ff1b2ec365db1c75fa7ce4.gif)

# 3. Kosaraju's algorithm
Kosaraju is an algorithm that is used to find strongly connected components in a directed graph. Strongly connected components are the maximum subsets of graph vertices in which each vertex can be reached from any other vertex in that subset.

![Kosaraju's algorithm](https://media.proglib.io/wp-uploads/-000//1/597791923c2e0_UvC39m2.gif)

# 4. Dinit's algorithm
Dinit's algorithm is an efficient algorithm for finding the maximum flow in a network with directed edges and capacitances on the edges. It is an advanced version of the Edmonds-Karp algorithm, and its main idea is to use multiple passes of the flow through the shortest possible paths in a layered network.

![Dinit's algorithm](https://media.proglib.io/posts/2020/09/08/06c0a8bbb4502b55e1b4707e397bc7f4.gif)

# 5. Hungarian Algorithm
The Hungarian Algorithm is an optimal combinatorial algorithm used to solve the assignment problem, which is a variation of the maximum matching problem in a weighted bipartite graph. It is designed to find the best match between the elements of two sets at minimum cost.

![Hungarian algorithm](https://media.proglib.io/posts/2020/09/08/93919687e795c90c971bdf641d0cfb0a.gif)

#6 Dijkstra's Algorithm
Dijkstra's algorithm is an algorithm for finding the shortest path from one vertex of a graph to all other vertices with non-negative edge weights. It is one of the classic graph algorithms and is used in many areas, such as routing in computer networks, route planning in transport systems, and other tasks where it is required to find the optimal path.

![Dijkstra's algorithm](https://du-blog.ru/media/Dijkstra_Animation.gif)

# 6. Floyd-Warshall algorithm
The Floyd-Warshall algorithm is an algorithm for finding the shortest paths between all pairs of vertices in a weighted directed or undirected graph. It can be used to find the shortest distances between all vertices in a graph, even if the graph contains edges with negative weights.

# P.s. All code is for educational purposes.
I am not a professional developer, these programs are made for educational purposes, I do not urge anyone to use this code as a professional one.
