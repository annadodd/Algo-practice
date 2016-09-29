//
//  graphPath.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/28/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector> 
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
// Given pairs like (A,B) where project A is dependent upon B, finds
// a workflow of projects that satisfies constraints and prints it

struct Project {
	string name;
	string dependency;
};
struct Node {
	string name;
};
struct Graph {
	unordered_map<string, list<Node>> edges;
	// Just access edges[node.name] to get adjacent vertices
	int numNodes;
};

Node findPoint(const unordered_map<string, int>& numIn,
			   const unordered_map<string, int>& numOut) {
	Node startNode;
	for (auto x: numOut) {
		auto in = numIn.find(x.first);
		if (in == numOut.end() && x.second > 0) {
			startNode.name = x.first;
			return startNode;
		}
	}
	return startNode;
}

Node findEnd(const Graph& graph) {
	// If no other projects depend on this
	Node endNode;
	for (auto x: graph.edges) {
		if (x.second.empty()) {
			cout << "found it" << endl;
			endNode.name = x.first;
			return endNode;
		}
	}
	return endNode;
}

// Given a graph, traverses in DFS and prints the traversal
void printDFSTraversal(Graph& graph, const Node& start, const Node& end) {

	unordered_map<string, list<Node>> unvisited = graph.edges;
	deque<Node> path;
	path.push_back(start);
	bool pathFound = false;

	while (!pathFound && !path.empty()) {
		Node current = path.back();
		// We have reached end node
		if (current.name == end.name) {
			// We have traversed all nodes on our way
			if (path.size() == graph.numNodes) {
				pathFound = true;
			}
			// We have not traveresed all nodes on our way
			else {
				path.pop_back();
			}
		}
		else {
			// No children left to visit
			if (unvisited[current.name].empty()) {
				// Reset children to unvisited (if any exist)
				unvisited[current.name] = graph.edges[current.name];
				path.pop_back();
			}
			// Children left to visit
			else {
				Node child = unvisited[current.name].back();
				unvisited[current.name].pop_back();
				path.push_back(child);
			}
		}
	}
	if (pathFound) {
		for (auto it = path.begin(); it != path.end(); ++it) {
			cout << it->name << " ";
		}
	}
	else {
		cout << "Path not found";
	}
	cout << endl;
}

void findWorkflow(vector<Project> projects) {
	Graph graph;

	unordered_map<string, int> numIn;
	unordered_map<string, int> numOut;

	// Create graph, load up edges, create hash of inEdges for each
	for (int i = 0; i < projects.size(); ++i) {
		Node currNode;
		currNode.name = projects[i].name;

		graph.edges[projects[i].dependency].push_back(currNode);

		numIn[projects[i].name]++;
		numOut[projects[i].dependency]++;
	}

	// Find start and end project

	Node start = findPoint(numIn, numOut);
	Node end = findPoint(numOut, numIn);

	graph.numNodes = (int)graph.edges.size() + 1;
	printDFSTraversal(graph, start, end);
}

int main() {

	// Test 1
	Project E;
	E.name = "E";
	E.dependency = "A";

	Project F;
	F.name = "F";
	F.dependency = "E";

	Project C;
	C.name = "C";
	C.dependency = "D";

	Project D;
	D.name = "D";
	D.dependency = "F";

	vector<Project> projects1;

	projects1.push_back(E);
	projects1.push_back(F);
	projects1.push_back(C);
	projects1.push_back(D);

	findWorkflow(projects1);

	// Test 2
	Project B_1;
	B_1.name = "B";
	B_1.dependency = "A";

	Project B_2;
	B_2.name = "B";
	B_2.dependency = "C";

	Project C_1;
	C_1.name = "C";
	C_1.dependency = "A";

	Project D_1;
	D_1.name = "D";
	D_1.dependency = "C";

	Project D_2;
	D_2.name = "D";
	D_2.dependency = "A";

	Project D_3;
	D_3.name = "D";
	D_3.dependency = "B";

	vector<Project> projects2;

	projects2.push_back(B_1);
	projects2.push_back(B_2);
	projects2.push_back(C_1);
	projects2.push_back(D_1);
	projects2.push_back(D_2);
	projects2.push_back(D_3);

	findWorkflow(projects2);

	return 0;
}



