#include <vector>
#include <list>
#include <iostream>
using namespace std;
#define REF
#define VAL
#define FREE

class GraphNode {
private:
	short m_vertexNumber = 0;
	short m_numberOfEdgesAvailable = 0;
	list<GraphNode*> m_secondaryList; // the residency list for each main vertex
	GraphNode* m_mutualPointerToFriend = nullptr; // include, for each graph vertex, it's mutual pointer in the main vertex vector
	bool m_isVisited = false; // to check if the edge exists
public:
	GraphNode(unsigned short i_VertexNumber = 0)
	{
		m_vertexNumber = i_VertexNumber;
	}
	~GraphNode();
	short getVertexNumber() { return m_vertexNumber; }
	short getNumberOfAvailableEdges() { return m_numberOfEdgesAvailable; }
	void addVertexToSecondaryList(short i_VertexToSecondary, GraphNode* getMutualPointerForVertex);
	void printSecondaryNodes();
	bool isSecondaryListEmpty() { return m_secondaryList.empty(); }
	void visitVertex() { m_isVisited = true; }
	bool isVisited() { return m_isVisited; }
	void setVertexNumber(int i_VertexNumber) { m_vertexNumber = i_VertexNumber; }
	void setNumberOfAvailableEdges() { m_numberOfEdgesAvailable++; }
	void substractNumberOfAvailableEdges() { m_numberOfEdgesAvailable--; }
	void setMutualPointerForVertex(GraphNode* mutualPointer) { m_mutualPointerToFriend = mutualPointer; }
	GraphNode* getMutualPointerForMainVertex() { return m_mutualPointerToFriend; }
	list<GraphNode*>::iterator getNextAvailableVertexInList();
	list<GraphNode*> getNeighborList() { return m_secondaryList; }

};
