#include <iostream>
#include <utility>
#include "graph.h"
#include "shortest_path.h"

using namespace std;

int main(){
  // Create a graph with 10 vertices (for A to J)
  Graph g(10);
  
  // Add edges as per the matrix you provided
  g.addEdge(0, 1, 84);  // A to B
  g.addEdge(0, 2, 118); // A to C
  g.addEdge(0, 3, 58);  // A to D
  g.addEdge(1, 5, 186); // B to F
  g.addEdge(1, 7, 61);  // B to H
  g.addEdge(1, 8, 143); // B to I
  g.addEdge(1, 9, 188); // B to J
  g.addEdge(2, 0, 142); // C to A
  g.addEdge(2, 4, 190); // C to E
  g.addEdge(3, 0, 88);  // D to A
  g.addEdge(3, 2, 173); // D to C
  g.addEdge(3, 6, 119); // D to G
  g.addEdge(3, 7, 30);  // D to H
  g.addEdge(3, 8, 53);  // D to I
  g.addEdge(4, 9, 120); // E to J
  g.addEdge(5, 2, 134); // F to C
  g.addEdge(5, 3, 105); // F to D
  g.addEdge(5, 7, 43);  // F to H
  g.addEdge(5, 8, 56);  // F to I
  g.addEdge(6, 9, 183); // G to J
  g.addEdge(8, 2, 110); // I to C
  g.addEdge(9, 5, 124); // J to F
  g.addEdge(9, 6, 87);  // J to G
  g.addEdge(9, 7, 86);  // J to H
  g.addEdge(9, 8, 139); // J to I

  // Source: B (index 1), Destination: C (index 2)
  int source = 1; // B
  int destination = 2; // C
  
  // Find shortest path from B to C
  Path result = shortestPath(g, source, destination);

  // Output the results
  std::cout << "从 B 到 C 的最短路径时间为: " << result.total_distance() << " 分钟" << std::endl;
  std::cout << "路径为: { ";
  for (int i = 0; i < result.path().size(); i++) {
    char node = 'A' + result.path()[i]; // Convert index to corresponding letter
    std::cout << node;
    if (i != result.path().size() - 1) std::cout << " -> ";
  }
  std::cout << " }" << endl;

  return 0;
}