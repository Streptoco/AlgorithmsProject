#include "Graph.h"


class DriverProgram
{
private:
	int m_NumberOfVertexes, m_NumberOfEdges;
	DirectedGraph* graph = nullptr;
public:
	void printMenu();
	bool handleDirectedGraph();
	bool handleUndirectedGraph();
	bool unifiedHandlerForFirstCase();
	bool getInputForEdgesFromUser();
	void printGraph();
	void printList(list<GraphNode*> resultList);
	//~DriverProgram() { delete[] graph; }
};