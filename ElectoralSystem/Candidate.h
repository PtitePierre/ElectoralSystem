/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Candidate
{
public:
	Candidate();
	Candidate(string nameAndParty);
	~Candidate();

	void setName(string name);
	void setParty(string party);
	string getName();
	string getParty();
	string toString();
	void print();

private:
	string name;
	string party;
};

