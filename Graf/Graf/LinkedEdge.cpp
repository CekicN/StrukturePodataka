#include "LinkedEdge.h"

LinkedEdge::LinkedEdge()
	:dest(),link(), weight()
{
}

LinkedEdge::LinkedEdge(LinkedNode* d, LinkedEdge* l)
	: dest(d), link(l), weight()
{
}

LinkedEdge::LinkedEdge(LinkedNode* d, LinkedEdge* l, double w)
	:dest(d), link(l), weight(w)
{
}
