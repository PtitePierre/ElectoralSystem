#include "stdafx.h"
#include "BallotPaper.h"


BallotPaper::BallotPaper()
{
}


BallotPaper::~BallotPaper()
{
}

void BallotPaper::setPreference(int n, Candidate* c)
{
	this->order[n] = c;
}

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

