#pragma once
#include <iostream>
using namespace std;
#define V 5
 
class Graph
{
public:
	int graph[V][V];

	Graph();
	void PrintArray(int dist[][V]);
	void median(int dist[][V]);
	void floydWarshall(int graph[][V]);
	void addEdge(int x, int y,bool direction);
	void removeEdge(int x, int y,bool direction);
	void clearGraph(int graph[][V]);
	
};

