#include "Edge.h"
#include <iostream>

using namespace std;

/**************************************************************************************************
 * Defining the Edge's methods
**************************************************************************************************/

// Constructor
Edge::Edge(int target_id)
{

    this->target_id = target_id;
    this->next_edge = nullptr;
    this->weight = 0;
}

Edge::Edge(int id, int target_id, float weight)
{
    this->target_id = target_id;
    this->origin_id = id;
    this->next_edge = nullptr;
    this->weight = weight;
}

// Destructor
Edge::~Edge()
{

    if (this->next_edge != nullptr)
    {
        delete this->next_edge;
        this->next_edge = nullptr;
    }
}

// Getters
int Edge::getTargetId()
{
    return this->target_id;
}

int Edge::getOriginId()
{
    return this->origin_id;
}

Edge *Edge::getNextEdge()
{
    return this->next_edge;
}

float Edge::getWeight()
{
    return this->weight;
}

// Setters
void Edge::setNextEdge(Edge *edge)
{
    this->next_edge = edge;
}

void Edge::setWeight(float weight)
{
    this->weight = weight;
}