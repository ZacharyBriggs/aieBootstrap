#pragma once
template<class Type>
struct NodeType
{
	Type info;
	NodeType<Type> *link;
};
