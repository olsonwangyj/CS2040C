#include "graph.h"
#include "shortest_path.h"
#include <vector>
#include "heap.hpp"

const int INF = 2147483646;

Path shortestPath(const Graph& g, int source, int dest) {
  if (source < 0 || source >= g.num_vertices()) {
    throw std::invalid_argument("Source vertex is out of bounds");
  }
  if (dest < 0 || dest >= g.num_vertices()) {
    throw std::invalid_argument("Destination vertex is out of bounds");
  }

  int V = g.num_vertices();
  if (V == 0) {
    throw std::logic_error("Graph is empty");
  }

  vector<int> distTo(V, INF);  
  vector<int> edgeTo(V, -1); 
  vector<bool> visited(V, false); 
  Heap<pair<int, int>> maxHeap;


  distTo[source] = 0;

  
  maxHeap.insert(make_pair(0, source));
  
  while (!maxHeap.empty()) {
    int v = maxHeap.extractMax().second;
    if (visited[v]) {
      continue;
    }
    visited[v] = true;
    if (v == dest) break;

    
    
    for (GraphEdge e : g.edges_from(v)) {
      int w = e.dest();
      if (distTo[w] > distTo[v] + e.weight()) {
        distTo[w] = distTo[v] + e.weight();
        edgeTo[w] = v;
       
        maxHeap.insert(make_pair(-distTo[w], w));
      }
    }
  }

  if (distTo[dest] == INF) {
    throw std::runtime_error("No path exists between source and destination");
  }

  vector<int> path;
  int cur = dest;
  while (cur != -1) {
      path.push_back(cur);
      cur = edgeTo[cur];
  }
  reverse(path.begin(), path.end());

  return Path(distTo[dest], path);
}