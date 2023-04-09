#include "GraphNode.h"

void GraphNode::addVertexToSecondaryList(short i_vertexToConnect)
{
	GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);
	m_secondaryList.push_back(*secondaryListNode);
	delete secondaryListNode;
}

void GraphNode::printSecondaryNodes()
{
	list<GraphNode>::iterator secondaryListItr;
	for (secondaryListItr = m_secondaryList.begin(); secondaryListItr != m_secondaryList.end(); ++secondaryListItr)
	{
		cout << "Current secondary vertex: " << (*secondaryListItr).getVertexNumber() << "\n";
	}
}