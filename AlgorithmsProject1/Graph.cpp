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
	m_mainVector[i_currentHoldingNumber]->addVertexToSecondaryList(i_vertexToConnect);
}



void DirectedGraph::printGraph()
{
	vector<GraphNode*>::iterator listItr;
	for (listItr = m_mainVector.begin(); listItr != m_mainVector.end(); ++listItr)
	{
		cout << "Main list node: " << (*listItr)->getVertexNumber() << "\n";
		(*listItr)->printSecondaryNodes();
	}
}

/*list<GraphNode*> DirectedGraph::findCircuit(GraphNode* i_startingVertex)
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
}*/