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
public:
	GraphNode(unsigned short i_VertexNumber)
	{
		m_vertexNumber = i_VertexNumber;
	}
	short getVertexNumber() { return m_vertexNumber; }
	void addVertexToSecondaryList(GraphNode* i_VertexToSecondary);
	void printSecondaryNodes();
};

class DirectedGraphNode : public GraphNode {
private:

public:
	
};