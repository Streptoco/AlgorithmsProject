#include "GraphNode.h"

class DirectedGraph {
private:
	
	short m_NumberOfVertex;
	short m_NumberOfEdges;
	vector<GraphNode*> m_mainVector;
	GraphNode* _nodesArr;
public:
	DirectedGraph(int i_NumberOfVertex = 0, int i_NumberOfEdges = 0);
	virtual ~DirectedGraph();
	virtual void addEdgeToGraph(short currentHoldingNumber, short vertexToConnect);
	void insertEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect);
	void printGraph();
	list<GraphNode*> findCircuit(GraphNode* i_startingVertex); 
	list<GraphNode*> euler();
	


	//Getters

	short getNumberOfVertex() { return m_NumberOfVertex; }
	short getNumberOfEdges() { return m_NumberOfEdges; }
	short getBackValueOfMainList() { return m_mainVector.back()->getVertexNumber(); }
	GraphNode* getFirstVector() { return m_mainVector[0]; }
	
	
};

class UndirectedGraph : public DirectedGraph {
public:
	UndirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges) : DirectedGraph(i_NumberOfVertex, i_NumberOfEdges) {}
	virtual ~UndirectedGraph() = default;
	void markTheOppositeEdge(GraphNode* i_currentVertex, GraphNode* i_visitedVertex)
	{
		short vertexToMarkNumber = i_currentVertex->getVertexNumber();
		list<GraphNode*> neighborList = i_visitedVertex->getNeighborList();
		for(auto vertex : neighborList)
		{
			if (vertex->getVertexNumber() == vertexToMarkNumber)
			{
				vertex->visitVertex();
				//vertex->getMutualPointerForMainVertex()->substractNumberOfAvailableEdges();
				i_visitedVertex->substractNumberOfAvailableEdges();
				break;
			}
		}
	}
	virtual void addEdgeToGraph(short i_firstVertex, short i_secondVertex) override
	{
		insertEdgeToGraph(i_firstVertex, i_secondVertex);
		insertEdgeToGraph(i_secondVertex, i_firstVertex);
	}
};