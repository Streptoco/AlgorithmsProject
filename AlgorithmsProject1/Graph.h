#include "GraphNode.h"

class DirectedGraph {
private:
	short m_NumberOfVertex;
	short m_NumberOfEdges;
	vector<GraphNode*> m_mainVector;
public:
	DirectedGraph(int i_NumberOfVertex = 0, int i_NumberOfEdges = 0);
	~DirectedGraph();
	virtual void addEdgeToGraph(short currentHoldingNumber, short vertexToConnect);
	void insertEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect);
	void printGraph();
	list<GraphNode*> findCircuit(GraphNode* i_startingVertex);


	//Getter's
	short getNumberOfVertex() { return m_NumberOfVertex; }
	short getNumberOfEdges() { return m_NumberOfEdges; }
	short getBackValueOfMainList() { return m_mainVector.back()->getVertexNumber(); }
	GraphNode* getFirstVector() { return m_mainVector[0]; }
};

class UndirectedGraph : public DirectedGraph {
public:
	UndirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges) : DirectedGraph(i_NumberOfVertex, i_NumberOfEdges) {}
	~UndirectedGraph() {}
	virtual void addEdgeToGraph(short i_firstVertex, short i_secondVertex) override
	{
		insertEdgeToGraph(i_firstVertex, i_secondVertex);
		insertEdgeToGraph(i_secondVertex, i_firstVertex);
	}
};