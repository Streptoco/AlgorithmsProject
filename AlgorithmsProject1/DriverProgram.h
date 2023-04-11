#include "Graph.h"


class DriverProgram
{
private:
	unsigned short m_NumberOfVertexes, m_NumberOfEdges;
	DirectedGraph* graph = nullptr;
public:
	void printMenu();
	void handleDirectedGraph();
	void handleUndirectedGraph();
	void unifiedHandlerForFirstCase();
	void getInputForEdgesFromUser();
	void printGraph();
	void printList(list<GraphNode*> resultList);
	//~DriverProgram() { delete[] graph; }
};