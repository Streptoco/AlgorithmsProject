#include "Graph.h"


class DriverProgram
{
private:
	int m_NumberOfVertexes = 0, m_NumberOfEdges = 0;
	DirectedGraph* graph = nullptr;
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