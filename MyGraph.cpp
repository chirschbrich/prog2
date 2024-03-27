#include <iostream>
#include "MyGraph.h"

#include <limits>
#include <fstream>

ostream& operator<<(ostream& os, const Link& l)
{
   os << l.v1 << " " << l.v2 << " " << l.w;
   return os;
}

MyGraph::MyGraph(int n)
{
   //Create a graph with n vertices. The vertices are labelled 1..n
   numVertices = n;
   adjList.resize(n);


}

MyGraph::MyGraph(const MyGraph& g)
{
   //Construct a new graph that is a copy of g
   numVertices = g.numVertices;
   adjList.resize(numVertices);
   for (int i = 0; i < numVertices; ++i) {
      adjList[i] = g.adjList[i];
   }
}

bool MyGraph::addEdge(int a, int b, float w) 
{
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   //SEGMENTATION FAULT PLEASE FIX RIGHT HERE
   /* 
   Add an edge between vertex a and b, with weight w.
   If the edge already exists or a vertex is not on the graph, do nothing and return false.
   Otherwise (addition is successful) return true.
   */
   


   // Check if vertices are valid and weight is positive
   if (a > 0 && b > 0 && w > 0.0) {
      for (const Link& link : adjList[a]) { // Check if edge already exists
         if (link.v1 == b) {
            return false; // Edge already exists
         }
      }
        
      // Edge does not exist, add it
      Link link = {a, b, w};
      adjList[a].push_back(link);
        
      return true;
   }
    
    return false; // vertices or weight not on graph
}

void MyGraph::output(ostream& os)
{
   /*
   Output the graph to the ostream& specified. Your output
   should have the following format:
   * The first line print the number of vertices.
   * Each subsequent line prints an edge. It should print three numbers: the two
   vertices associated with the edge (print the vertex with the smaller number
   first), and the weight of the edge. You should have one space character between
   the numbers, and no space at the end. You can order the edges whatever way
   you want.

   * You must follow the format strictly. Otherwise points will be taken off and you
   are not eligible for extra credit
   */
   os << numVertices;
   os << adjList[1][1];

}

pair<vector<pair<int, int> >, float > MST()
{
   /*
   This function return the MST of the current tree. The output should be a pair:
   * The first object is a vector of pairs, each pair represent an edge, where the two
   numbers show the vertices of the edge. You should represent each edge such
   that the first number is smaller than the second one
   * The second floating point number is the total weight of the MST
   */
   vector<pair<int, int>> res1;
   return make_pair(res1, 0.0);
}

void Prim(int n, const std::vector<std::vector<float>>& W, std::set<Link> F) {
   // Distance: for each vertex in V-Y, store the minimum weight of the edges from that vertex to any vertex in Y
   // Nearest: store that vertex 
   std::vector<int> minNbr(n + 1);
   std::vector<float> minWt(n + 1);
   std::vector<bool> selected(n + 1);

   //assumed starting at Y = {v1}
   for (int i = 2; i <= n; i++) {
      minNbr[i] = 1;
      minWt[i] = W[1][i];
      selected[i] = false;
   }

   for (int count = 1; count <= n - 1; count++) {
      float min = std::numeric_limits<float>::infinity();
      int minindex = -1;
      for (int i = 2; i <= n; i++) {
         if (!selected[i] && (minWt[i] < min)) {
            min = minWt[i];
            minindex = i;
         }
      }
      //F.insert(std::pair<minNbr[minindex], minindex>);
      selected[minindex] = true;
      for (int i = 2; i <= n; i++) {
         if (W[minindex][i] < minWt[i]) {
               minWt[i] = W[minindex][i];
               minNbr[i] = minindex;
         }
      }
   }
}

pair<vector<Link> , vector<int> > Prog2(vector<float> satcost, vector<Link> linkcost, int& sat_conn)
{
   // a lot of stuff to do here go to prog2 assignment
    sat_conn = 3;
    vector<Link> res1;
    vector<int> res2;

    return make_pair(res1, res2);
}

