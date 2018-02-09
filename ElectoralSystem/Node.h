/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#pragma once
#include "Candidate.h"
#include <vector>

using namespace std;

class Node
{
public:
	Node(Candidate * c);
	~Node();
	Node * addFollower(Candidate* c);
	int posFollower(Candidate* c);
	void increment();
	void addBranche(Node * added);
	void eject(Candidate * c);

	Node * getLoser();
	Candidate * getCdt();
	int getVoteCount();
	vector<Node*> getFollowers();

	string toString();
	string nodeString(int rank);
	void print();

private:
	Candidate * cdt;
	int voteCount;
	vector<Node*> followers;
};

