/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#pragma once
#include "Node.h"
#include "Candidate.h"
#include "BallotPaper.h"
#include <vector>

using namespace std;

class Tree
{
public:
	Tree();
	~Tree();
	void fill(vector<BallotPaper*> votes, int nbCdt);
	void ejectCandidate(Candidate* c);
	Node* getLoser();
	Candidate * getWinner();
	void print();

private:
	Node * root;
};

