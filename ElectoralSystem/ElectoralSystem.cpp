/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
// ElectoralSystem.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "VoteCounter.h"
#include <iostream>

using namespace std;


int main()
{
	VoteCounter* vc = new VoteCounter();
	//vc->printCandidates();
	//vc->printBallots();
	vc->printTree();
	vc->getWinner();
	//vc->printTree();

	int num;
	cin >> num;
    return 0;
}

