#include "GraphNode.h"

class DirectedGraph {
private:
	short m_NumberOfVertex;	
	short m_NumberOfEdges;
	list<GraphNode*> m_mainList;
public:
	DirectedGraph(int i_NumberOfVertex = 0, int i_NumberOfEdges = 0)
	{
		m_NumberOfVertex = i_NumberOfVertex;
		m_NumberOfEdges = i_NumberOfEdges;
	}
	bool insertEdgeIntoGraph(unsigned short REF vertexA, unsigned short REF vertexB);
	short getNumberOfVertex() { return m_NumberOfVertex; }
	short getNumberOfEdges() { return m_NumberOfEdges; }
	short getBackValueOfMainList() { return m_mainList.back()->getVertexNumber(); }
	void addEdgeToGraph(GraphNode * i_MainListNode, GraphNode * i_SecondaryListNode);
};

class UndirectedGraph : public DirectedGraph {
private:
	short m_numberOfVertex;
	short m_numberOfEdges;
	list<GraphNode> m_mainList;
public:
	UndirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges)
	{
		m_numberOfVertex = i_NumberOfVertex;
		m_numberOfEdges = i_NumberOfEdges;
	}
};