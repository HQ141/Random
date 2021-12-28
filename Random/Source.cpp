#include<iostream>
#include"ggraph.h"
int main(){
	Graph<int> alpha;
	alpha.insertVertice(0);
	alpha.insertVertice(1);
	alpha.insertVertice(2);
	alpha.insertVertice(3);
	alpha.insertVertice(4);
	alpha.insertVertice(5);
	alpha.UInsertEdges(0, 1);
	alpha.UInsertEdges(0, 5);
	alpha.UInsertEdges(0, 2);
	alpha.UInsertEdges(2, 1);
	alpha.UInsertEdges(4, 2);
	alpha.UInsertEdges(2, 3);
	alpha.UInsertEdges(5, 3);
	alpha.UInsertEdges(4, 3);
	alpha.resetvist();
	alpha.Bfs();
}