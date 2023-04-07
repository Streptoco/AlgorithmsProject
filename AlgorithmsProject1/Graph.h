#include "GraphNode.h"

class DirectedGraph {
private:
	short m_numberOfVertex;	
	short m_numberOfEdges;
	list<GraphNode> m_mainList;
public:
	bool insertEdgeIntoGraph(unsigned short vertexA, unsigned short vertexB);

};

class UndirectedGraph : public DirectedGraph {
private:

public:

};