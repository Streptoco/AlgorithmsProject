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
	list<GraphNode*> m_secondaryList;
	bool m_isVisited = false;
public:
	GraphNode(unsigned short i_VertexNumber = 0)
	{
		m_vertexNumber = i_VertexNumber;
	}
	short getVertexNumber() { return m_vertexNumber; }
	void addVertexToSecondaryList(short i_VertexToSecondary);
	void printSecondaryNodes();
	bool isSecondaryListEmpty() { return m_secondaryList.empty(); }
	void visitVertex() { m_isVisited = true; m_numberOfEdgesAvailable--; }
	bool isVisited() { return m_isVisited; }
	void setVertexNumber(int i_VertexNumber) { m_vertexNumber = i_VertexNumber; }
	void setNumberOfAvailableEdges() { m_numberOfEdgesAvailable++; }
	list<GraphNode*>::iterator getHeadOfSecondaryList() { return m_secondaryList.begin(); }
};

class DirectedGraphNode : public GraphNode {
private:

public:

};