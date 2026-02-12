#include <thread>
#include "MinimumSpanningTree.h"

int main()
{	
	CreateGraph();

	std::vector<CostEdge> selected;
	int cost = Kruskal(selected);
}
