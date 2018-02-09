#include "stdafx.h"
#include "BallotPaper.h"


BallotPaper::BallotPaper()
{
}


BallotPaper::~BallotPaper()
{
}

/**
 * set the candidate at the n-th place of the ballot's array
 * @param int n : preference for c
 * @param Candidate * c : the candidate to add in the ballot
 */
void BallotPaper::setPreference(int n, Candidate* c)
{
	this->order[n] = c;
}

/**
 * get the candidate who has the n-th preference
 * @param int n : preference of the wanted candidate
 */
Candidate* BallotPaper::getPreference(int n)
{
	return this->order[n];
}

string BallotPaper::toString()
{
	string str = "";
	for (int i = 1; i < order.size() + 1; i++)
	{
		str += to_string(i) + " _ " + order[i]->toString() + "\n";
	}
	return str;
}

void BallotPaper::print()
{
	for (int i = 1; i < order.size() + 1; i++)
	{
		cout << i << " _ ";
		order[i]->print();
	}
}

