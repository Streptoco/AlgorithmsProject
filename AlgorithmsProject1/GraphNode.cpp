#include "GraphNode.h"

void GraphNode::addVertexToSecondaryList(GraphNode* i_VertexToSecondary)
{
	m_secondaryList.push_back(i_VertexToSecondary);
}

void GraphNode::printSecondaryNodes()
{
	list<GraphNode*>::iterator secondaryListItr;
	for (secondaryListItr = m_secondaryList.begin(); secondaryListItr != m_secondaryList.end(); ++secondaryListItr)
	{
		cout << "Current secondary vertex: " << (*secondaryListItr)->getVertexNumber() << "\n";
	}
}