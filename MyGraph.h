#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Link {

public:

   int v1, v2;
   float w;
};

ostream& operator<<(ostream&, const Link&);

class MyGraph {
private:
   int numVertices;
   std::vector<std::vector<Link>> adjList; //will take in the node and destination
public:
   MyGraph(int);
   MyGraph(const MyGraph&);

   bool addEdge(int a, int b, float w);
   void output(ostream& os);
   pair<vector<pair<int, int> >, float > MST();

   void Prim(int n, const std::vector<std::vector<float>>& W, std::set<Link> F);
   //Prim’s algorithm on graph with n vertices;
   //W[i][j] store the weight of edge (i,j) or inf it does not exist
   //F stores the edge of the MST found


};

pair<vector<Link>, vector<int> > Prog2(vector<float> satcost, vector<Link> linkcost, int& sat_conn);

