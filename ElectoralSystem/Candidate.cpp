/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#include "stdafx.h"
#include "Candidate.h"


Candidate::Candidate()
{
}

/**
 * initialize the candidate from nameAndParty
 * 
 * @param string nameAndParty : represents the candidate
 * nameAndParty contains the name and the party of the candidate
 * they are (must be) separated by this character : ","
 */
Candidate::Candidate(string nameAndParty)
{
	int pos = nameAndParty.find(",");
	if (pos != -1)
	{
		this->setName(nameAndParty.substr(0, pos));
		this->setParty(nameAndParty.substr(pos + 1));
	}
	else {
		this->setName(nameAndParty);
		this->setParty("Unknown");
	}
}

Candidate::~Candidate()
{
}

void Candidate::setName(string name)
{
	this->name = name;
}

string Candidate::getName()
{
	return this->name;
}

void Candidate::setParty(string party)
{
	this->party = party;
}

string Candidate::getParty()
{
	return this->party;
}


string Candidate::toString()
{
	return this->getName() + " : " + this->getParty();
}

void Candidate::print()
{
	cout << this->toString() << "\n";
}