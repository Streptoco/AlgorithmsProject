#include "GraphNode.h"

void GraphNode::addVertexToSecondaryList(short i_VertexToSecondary, GraphNode* getMutualPointerForVertex)
{
	FREE GraphNode* secondaryNodeToPush = new GraphNode(i_VertexToSecondary);
	secondaryNodeToPush->setMutualPointerForVertex(getMutualPointerForVertex); // after its inception, we add the newly created vertex to the residency list
	m_secondaryList.push_back(secondaryNodeToPush);
}

void GraphNode::printSecondaryNodes()
{
	list<GraphNode*>::iterator secondaryListItr;
	if (!m_secondaryList.empty())
	{
		for (secondaryListItr = m_secondaryList.begin(); secondaryListItr != m_secondaryList.end(); ++secondaryListItr)
		{
			cout << "Current secondary vertex: " << (*secondaryListItr)->getVertexNumber() << "\n";
		}
	}
}

list<GraphNode*>::iterator GraphNode::getNextAvailableVertexInList()
{
	list<GraphNode*>::iterator listItr = m_secondaryList.begin();
	for (; listItr != m_secondaryList.end(); ++listItr)
	{
		if (!(*listItr)->isVisited())
		{
			return listItr;
		}
	}
}

GraphNode::~GraphNode()
{
	
	for(auto v : m_secondaryList)
	{
#ifdef DEBUG 
		cout << "In GraphNode D'tor " << v->getVertexNumber();
		if (v->getMutualPointerForMainVertex() == nullptr)
		{
			cout << " from mainVector" << endl;
		}
		else
		{
			cout << endl;
			
		}
#endif

		delete v;
	}

}