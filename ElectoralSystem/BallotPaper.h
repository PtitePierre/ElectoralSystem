/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#pragma once
#include "Candidate.h"
#include <map>

using namespace std;

class BallotPaper
{
public:
	BallotPaper();
	~BallotPaper();

	void setPreference(int n, Candidate * c);
	Candidate * getPreference(int n);
	string toString();
	void print();

private:
	map<int, Candidate*> order;	// with int preference from 1 to n
};

