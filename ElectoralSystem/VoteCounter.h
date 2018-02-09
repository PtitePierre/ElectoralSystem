/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#pragma once
#include "BallotPaper.h"
#include "Candidate.h"
#include "Node.h"
#include "Tree.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class VoteCounter
{
public:
	VoteCounter();
	~VoteCounter();
	void extract(string file_path);
	Candidate * getWinner();

	void printCandidates();
	void printBallots();
	void printTree();

private:
	const string FILE_PATH = "../votes.txt";
	vector<BallotPaper*> ballots;
	vector<Candidate*> order;
	Tree results;
};

