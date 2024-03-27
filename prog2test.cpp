#include <iostream>
#include <fstream>
#include <vector>
#include "MyGraph.h"

#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

/* 
There are four houses
• For each house (1, 2, 3, 4), the cost of installing a satellite at that house is (21.5 10.5 11.5 16)
respectively.
      I dont think I can get around this cost, disregarding weight of links, each house still needs to be connected
• There are five cables that can be build.
• Between house 1 and 4, building a cable cost 5
• Between house 2 and 3, building a cable cost 4,5
• Next three lines are similar.
(Notice that one cannot build a cable between house 3 and 4)
*/

main()
{
   std::set<Link> F;

   ifstream ifile("/users7/cse/chirschbrich/CS3353/prog2/test2_1.txt");
   int n = 0;
   vector<float> satcost;

   ifile >> n;

   satcost.push_back(0.0);
   for (int i = 0; i < n; i++)
	{
	   float q = 0;
           ifile >> q;
	   satcost.push_back(q);
	}

   int e = 0;
   vector<Link> l;
   ifile >> e;
   int sat_conn;
   for (int i = 0; i < e; i++)
	{
	   Link s;
	   ifile >> s.v1 >> s.v2 >> s.w;
	   l.push_back(s);
	}
   cout << "Total # of houses " << n << endl;
   cout << "Links : ";
   for (int i = 0; i < l.size(); i++)
	cout << l[i] << " | ";
   cout << endl;
 
   pair<vector<Link>, vector<int> > res = Prog2(satcost, l, sat_conn);

   cout << "\n----------\n\n";
   cout << "Satellite connected to house " << sat_conn << endl;
   cout << "Links : "; 
   for (int i = 0; i < res.first.size(); i++)
	{
	   cout << res.first[i] << " ";
	}
   cout << " | ";
   for (int i = 0; i < res.second.size(); i++)
	{
	   cout << res.second[i] << " ";
	}
   cout << "\n";
   
   cout << "Path to house 1 : ";
   for (int i =0; i < res.second.size(); i++)
	{
	   cout << res.second[i] << " ";
	}
   cout << endl;
   
   MyGraph graph(n); //create graph with n nodes
   for (int i = 0; i < n; i++) { //iterate through the n nodes
      graph.addEdge(l[i].v1, l[i].v2, l[i].w); //add the edge
   }

//


   ofstream os("output.csv");
   if(!os.is_open()) {
      os.open("output.csv");
   }
   graph.output(os);

   //graph.Prim(n, W, F);
}