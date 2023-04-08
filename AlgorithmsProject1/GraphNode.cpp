#include "GraphNode.h"

void GraphNode::addVertexToSecondaryList(GraphNode* i_VertexToSecondary)
{
	m_secondaryList.push_back(i_VertexToSecondary);
}