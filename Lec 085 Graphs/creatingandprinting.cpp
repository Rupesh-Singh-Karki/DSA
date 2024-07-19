#include<iostream>
#include<vector>
using namespace std;
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        for (int j = 0; j < ans[i].size(); j++) {
          adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

/*
This code constructs an adjacency list representation of an undirected graph from given edges and then returns it. Let's break down the code step by step and perform a dry run with a simple example.

### Code Explanation

1. **Initialization**:
   ```cpp
   vector<int> ans[n];
   ```
   - `ans` is an array of vectors, where each vector corresponds to a vertex and will store its adjacent vertices.

2. **Building the Adjacency List**:
   ```cpp
   for(int i=0; i<m; i++){
       int u = edges[i][0];
       int v = edges[i][1];

       ans[u].push_back(v);
       ans[v].push_back(u);
   }
   ```
   - Loop through each edge and update the adjacency list. For each edge `(u, v)`, add `v` to the list of `u` and add `u` to the list of `v` since the graph is undirected.

3. **Preparing the Output**:
   ```cpp
   vector<vector<int>> adj(n);
   for(int i=0; i<n; i++){
       adj[i].push_back(i);

       for (int j = 0; j < ans[i].size(); j++) {
           adj[i].push_back(ans[i][j]);
       }
   }
   ```
   - Create the `adj` vector of vectors. For each vertex `i`, the first element in `adj[i]` is the vertex `i` itself, followed by all its adjacent vertices stored in `ans[i]`.

### Dry Run with Example

#### Example Input
- Number of vertices, `n = 4`
- Number of edges, `m = 3`
- Edges: `[[0, 1], [0, 2], [1, 3]]`

#### Steps

1. **Initialization**:
   - `ans` is an array of 4 vectors: `[[], [], [], []]`.

2. **Building the Adjacency List**:
   - For edge `(0, 1)`:
     - `ans[0].push_back(1)` → `ans` becomes `[[1], [], [], []]`
     - `ans[1].push_back(0)` → `ans` becomes `[[1], [0], [], []]`
   - For edge `(0, 2)`:
     - `ans[0].push_back(2)` → `ans` becomes `[[1, 2], [0], [], []]`
     - `ans[2].push_back(0)` → `ans` becomes `[[1, 2], [0], [0], []]`
   - For edge `(1, 3)`:
     - `ans[1].push_back(3)` → `ans` becomes `[[1, 2], [0, 3], [0], []]`
     - `ans[3].push_back(1)` → `ans` becomes `[[1, 2], [0, 3], [0], [1]]`

3. **Preparing the Output**:
   - For vertex `0`:
     - Start with `adj[0] = [0]`
     - Append elements from `ans[0]` → `adj[0]` becomes `[0, 1, 2]`
   - For vertex `1`:
     - Start with `adj[1] = [1]`
     - Append elements from `ans[1]` → `adj[1]` becomes `[1, 0, 3]`
   - For vertex `2`:
     - Start with `adj[2] = [2]`
     - Append elements from `ans[2]` → `adj[2]` becomes `[2, 0]`
   - For vertex `3`:
     - Start with `adj[3] = [3]`
     - Append elements from `ans[3]` → `adj[3]` becomes `[3, 1]`

#### Final Output
- The adjacency list in the format required:
  ```cpp
  [[0, 1, 2], [1, 0, 3], [2, 0], [3, 1]]
  ```

### Explanation of the Output
- `0` is connected to `1` and `2`
- `1` is connected to `0` and `3`
- `2` is connected to `0`
- `3` is connected to `1`

This matches the input edges and correctly represents the adjacency list of the graph.
*/