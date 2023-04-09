#include "Graph.h"

/*bool DirectedGraph::insertEdgeIntoGraph(unsigned short vertexA, unsigned short vertexB)
{
	GraphNode temporaryNodeToCheck = m_vertexVector.back();
	if (temporaryNodeToCheck.getVertexNumber() == vertexA)
	{
		// HANDLE CASE WHERE WE DONT ADD
	}
	else
	{
		GraphNode newNodeToPush(vertexA);
		m_vertexVector.push_back(newNodeToPush);
	}
}*/

void DirectedGraph::addEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{

	//FREE GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);  ALLOCATION IS SHOULD BE MADE INSIDE THE CLASS
	m_vertexVector[i_currentHoldingNumber - 1].addVertexToSecondaryList(i_vertexToConnect);

				//No need to split for cases

	//if (m_vertexVector.empty() || i_currentHoldingNumber != m_vertexVector.back().getVertexNumber())
	//{
	//	//FREE GraphNode* mainListNode = new GraphNode(i_currentHoldingNumber);
	//	FREE GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);
	//	//m_vertexVector.push_back(*mainListNode);
	//	m_vertexVector[i_currentHoldingNumber - 1].addVertexToSecondaryList(secondaryListNode);
	//}
	//else
	//{
	//	// get secondary list addition
	//	FREE GraphNode* secondaryListNode = new GraphNode(i_vertexToConnect);
	//	m_vertexVector[i_currentHoldingNumber - 1].addVertexToSecondaryList(secondaryListNode);
	//}
}

void DirectedGraph::printGraph()
{
	vector<GraphNode>::iterator vectorItr;
	for (vectorItr = m_vertexVector.begin(); vectorItr != m_vertexVector.end(); ++vectorItr)
	{
		cout << "Main list node: " << (*vectorItr).getVertexNumber() << "\n";
		(*vectorItr).printSecondaryNodes();
	}
}

list<GraphNode> DirectedGraph::findCircuit(GraphNode* i_startingVertex)
{
	GraphNode* currentVertex = i_startingVertex;
	list<GraphNode> resultList;
	list<GraphNode>::iterator secondaryListItr = currentVertex->getHeadOfSecondaryList();
	resultList.push_back(*currentVertex);
	while (currentVertex->isSecondaryListEmpty())
	{
		if ((*secondaryListItr).isVisited() == false)
		{
			(*secondaryListItr).visitVertex();
			resultList.push_back((*secondaryListItr));
			 
		}
	}
	return resultList;
}