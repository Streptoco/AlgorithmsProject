#include "Graph.h"


class DriverProgram
{
private:
	int m_NumberOfVertexes = 0, m_NumberOfEdges = 0;
	DirectedGraph* graph = nullptr; // the graph is polymorphic (undirected derives from directed), and is determined later in the program
public:
	void printMenu();
	bool handleDirectedGraph();
	bool handleUndirectedGraph();
	bool unifiedHandlerForFirstCase();
	bool getInputForEdgesFromUser();
	void printGraph();
	void printList(list<GraphNode*> resultList);
	~DriverProgram() { delete graph; }
};