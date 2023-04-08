#include <vector>
#include <list>
#include <iostream>
using namespace std;
#define REF
#define VAL

class GraphNode {
private:
	short m_vertexNumber = 0;
	short m_numberOfEdgesAvailable;
	list<GraphNode> m_secondaryList;
public:
	GraphNode(unsigned short vertexA)
	{
		m_vertexNumber = vertexA;
	}
	short getVertexNumber() { return m_vertexNumber; }
};

class DirectedGraphNode : public GraphNode {
private:

public:
	
};