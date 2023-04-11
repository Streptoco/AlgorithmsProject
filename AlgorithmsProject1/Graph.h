#include "GraphNode.h"

class DirectedGraph {
private:
	short m_NumberOfVertex;	
	short m_NumberOfEdges;
	vector<GraphNode*> m_mainVector;
public:
	DirectedGraph(int i_NumberOfVertex = 0, int i_NumberOfEdges = 0)
	{
		m_NumberOfVertex = i_NumberOfVertex;
		m_NumberOfEdges = i_NumberOfEdges;
		FREE GraphNode* nodeArr = new GraphNode[m_NumberOfVertex];
		for (int i = 0; i < i_NumberOfVertex; i++)
		{
			nodeArr[i].setVertexNumber(i+1);
			m_mainVector.push_back(&nodeArr[i]);
		}
	}
	short getNumberOfVertex() { return m_NumberOfVertex; }
	short getNumberOfEdges() { return m_NumberOfEdges; }
	short getBackValueOfMainList() { return m_mainVector.back()->getVertexNumber(); }
	void addEdgeToGraph(short currentHoldingNumber, short vertexToConnect);
	void printGraph();
	GraphNode* returnFirstVector() { return m_mainVector[0]; }
	list<GraphNode*> findCircuit(GraphNode* i_startingVertex);
	list<GraphNode*> euler();
};

class UndirectedGraph : public DirectedGraph {
private:
	short m_numberOfVertex;
	short m_numberOfEdges;
	list<GraphNode> m_mainVector;
public:
	UndirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges)
	{
		m_numberOfVertex = i_NumberOfVertex;
		m_numberOfEdges = i_NumberOfEdges;
	}
};