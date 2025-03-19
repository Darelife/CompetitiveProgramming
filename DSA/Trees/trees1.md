# Trees

- It's a connected graph, which is acyclic

### Diameter of a tree
- diameter of a tree = max distance between any two nodes of a tree
- to calculate diameter of a tree, we can run two dfs
- first dfs to find the farthest node from a random node
- 2nd dfs to find the farthest node from the farthest node found in the first dfs
- the distance between the two farthest nodes is the diameter of the tree

### Sum of Degrees
- sum of degrees of all nodes in a tree = 2 * (number of nodes - 1)
- sum of degrees of all nodes in a tree = 2 * (number of edges)

### Number of Edges
- number of edges in a tree = number of nodes - 1

### Number of Leaf Nodes
- number of leaf nodes in a tree = number of nodes with degree 1
- Minimum number of leaf nodes in a tree = 2 (unless it's a single node tree)

### Ancestor and Descendant
- In a tree, if node A is an ancestor of node B, then node B is a descendant of node A

### Subtree
- Subtree(x) = x + all descendants of x

### Level of a Node
- Level of a node = distance of the node from the root node
- Level of the root node = 0
- Level of a node = level of parent node + 1
- Level of a node = height of the node

### Lowest Common Ancestor (LCA)
- LCA of two nodes A and B is the node which is the ancestor of both A and B and is farthest from the root node
- We can find LCA of two nodes A and B by finding the path from root to A and root to B
- The last common node in the two paths is the LCA of A and B
- LCA of A and B = LCA of B and A
- We can find LCA of two nodes A and B in O(log(n)) time using binary lifting, segment tree or sparse table

### Bipartite Coloring
- Each node of a tree can be coloured with just 2 colours such that no two adjacent nodes have the same colour
- A tree is always bipartite
- Bipartite means we can divide the nodes of the tree into two sets such that no two nodes in the same set are adjacent
- You can color each hight level with one color and the other with another color
- Height 0: Red
- Height 1: Blue
- Height 2: Red
- ...and so on...

# DFS on Trees
- Visit a node, and then visit all its children
- While coming up, if we find another node that is not visited, we visit it, and its children
- We can implement DFS using recursion or by using a stack


## Storing in a Tree
### Only in Rooted Trees
- Store the parent for each node (-1 if root node)
### Works in both Rooted and Unrooted Trees
- Store the neighbours of each node (adjacency list)
- map {int -> vector<int>} tree
- vector<vector<int>> tree
- We'll basically store, 2*|E| + |V| = 2*(|V|-1) + |V| = 3|V| - 2

## DFS Traversal
```
[
  1: [2, 3, 6],
  2: [1, 9, 8],
  3: [1, 4, 5],
  4: [3],
  5: [3],
  6: [1, 7],
  7: [6],
  8: [2],
  9: [2]
]
```
- If we start from 1,
- 1 -> 2 -> 9 -> 8 -> 3 -> 4 -> 5 -> 6 -> 7

```cpp
void dfs(int currentNode, vector<vector<int>>& adj, int parent, vector<int>&ans, vector<bool>&vis) {
  ans.push_back(currentNode);
  vis[currentNode] = true;
  for (int neighbour : adj[currentNode]) {
    if (neightbour != parent && !vis[neighbour]) {
      dfs(neighbour, adj, currentNode, ans, vis);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i<n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root = 0;
  vector<int> dfs_traversal;
  vector<bool> vis(n, false);
  dfs(root, adj, -1, dfs_traversal, vis);
}
```