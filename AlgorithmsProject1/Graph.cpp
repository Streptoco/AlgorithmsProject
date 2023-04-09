#include "Graph.h"

/*bool DirectedGraph::insertEdgeIntoGraph(unsigned short vertexA, unsigned short vertexB)
{
	GraphNode temporaryNodeToCheck = m_mainList.back();
	if (temporaryNodeToCheck.getVertexNumber() == vertexA)
	{
		// HANDLE CASE WHERE WE DONT ADD
	}
	else
	{
		GraphNode newNodeToPush(vertexA);
		m_mainList.push_back(newNodeToPush);
	}
}*/

void DirectedGraph::addEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{



	if (m_mainList.empty() || i_currentHoldingNumber != m_mainList.back()->getVertexNumber())
	{
		FREE GraphNode* mainListNode = new GraphNode(i_currentHoldingNumber);
		FREE GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);
		m_mainList.push_back(mainListNode);
		m_mainList.back()->addVertexToSecondaryList(secondaryListNode);
	}
	else
	{
		// get secondary list addition
		FREE GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);
		m_mainList.back()->addVertexToSecondaryList(secondaryListNode);
	}
}



void DirectedGraph::printGraph()
{
	list<GraphNode*>::iterator listItr;
	for (listItr = m_mainList.begin(); listItr != m_mainList.end(); ++listItr)
	{
		cout << "Main list node: " << (*listItr)->getVertexNumber() << "\n";
		(*listItr)->printSecondaryNodes();
	}
}

list<GraphNode*> DirectedGraph::findCircuit(GraphNode* i_startingVertex)
{
	GraphNode* currentVertex = i_startingVertex;
	list<GraphNode*> resultList;
	list<GraphNode*>::iterator secondaryListItr = currentVertex->getHeadOfSecondaryList();
	resultList.push_back(currentVertex);
	while (currentVertex->isSecondaryListEmpty())
	{
		if ((*secondaryListItr)->isVisited() == false)
		{
			(*secondaryListItr)->visitVertex();
			resultList.push_back((*secondaryListItr));
			 
		}
	}
}