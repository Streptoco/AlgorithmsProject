#include "GraphNode.h"

void GraphNode::addVertexToSecondaryList(short i_VertexToSecondary, GraphNode* getMutualPointerForVertex)
{
	FREE GraphNode* secondaryNodeToPush = new GraphNode(i_VertexToSecondary);
	secondaryNodeToPush->setMutualPointerForVertex(getMutualPointerForVertex);
	m_secondaryList.push_back(secondaryNodeToPush);
}

void GraphNode::printSecondaryNodes()
{
	list<GraphNode*>::iterator secondaryListItr;
	if (!m_secondaryList.empty())
	{
		for (secondaryListItr = m_secondaryList.begin() ; secondaryListItr != m_secondaryList.end(); ++secondaryListItr)
		{
			cout << "Current secondary vertex: " << (*secondaryListItr)->getVertexNumber() << "\n";
		}
	}
}