#include "Graph.h"

bool DirectedGraph::insertEdgeIntoGraph(unsigned short vertexA, unsigned short vertexB)
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
}