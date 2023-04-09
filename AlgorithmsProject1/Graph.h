#include "GraphNode.h"

class DirectedGraph {
private:
	short m_NumberOfVertex;	
	short m_NumberOfEdges;
	vector<GraphNode> m_vertexVector;
public:
	DirectedGraph(int i_NumberOfVertex = 0, int i_NumberOfEdges = 0)
	{
		m_NumberOfVertex = i_NumberOfVertex;
		m_NumberOfEdges = i_NumberOfEdges;
		GraphNode* tempGraphNode;
		for (int i = 1; i <= m_NumberOfVertex; i++)
		{
			tempGraphNode = new GraphNode((unsigned short)i);
			m_vertexVector.push_back(*tempGraphNode);
			delete tempGraphNode;
		}
	}
	short getNumberOfVertex() { return m_NumberOfVertex; }
	short getNumberOfEdges() { return m_NumberOfEdges; }
	short getBackValueOfMainList() { return m_vertexVector.back().getVertexNumber(); }
	void addEdgeToGraph(short currentHoldingNumber, short vertexToConnect);
	void printGraph();
	list<GraphNode> findCircuit(GraphNode* i_startingVertex);
};

class UndirectedGraph : public DirectedGraph {
public:
	UndirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges) : DirectedGraph(i_NumberOfVertex, i_NumberOfEdges) {}
	
};