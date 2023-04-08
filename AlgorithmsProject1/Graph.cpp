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

void DirectedGraph::addEdgeToGraph(GraphNode* i_MainListNode, GraphNode* i_SecondaryListNode)
{
	if (i_MainListNode->getVertexNumber() == m_mainList.back()->getVertexNumber())
	{
		// get secondary list addition
	}
	else
	{
		// make a new list node and add the secondary list to it.
		m_mainList.push_back(i_MainListNode);
	}
	
}