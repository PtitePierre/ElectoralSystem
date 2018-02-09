/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#include "stdafx.h"
#include "VoteCounter.h"


VoteCounter::VoteCounter()
{
	this->extract(FILE_PATH);
	this->results.fill(this->ballots, this->order.size());
}


VoteCounter::~VoteCounter()
{
}

void VoteCounter::extract(string file_path)
{
	string line;
	ifstream myfile(file_path);
	if (myfile.is_open())
	{
		// get the 1st line
		getline(myfile, line);
		int i;
		int num = 0;
		string nom;
		// this line contains the candidates and their party
		while (line.find(";") != -1)
		{
			i = line.find(";");
			nom = line.substr(0, i);
			line = line.substr(i + 1);
			Candidate* c = new Candidate(nom);
			order.push_back(c);
			num++;
		}
		// last candidate
		nom = line;
		Candidate* c = new Candidate(nom);
		order.push_back(c);

		// get ballots
		while (getline(myfile, line))
		{
			BallotPaper* ballot = new BallotPaper();
			int cdt = 0;
			int choice;
			while (line.find(",") != -1)
			{
				i = line.find(",");
				choice = stoi(line.substr(0, i));
				ballot->setPreference(choice, order[cdt]);

				line = line.substr(i + 1);
				cdt++;
			}
			ballot->setPreference(stoi(line), order[cdt]);
			//ballot->toString();
			//cout << '\n';
			ballots.push_back(ballot);
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}

Candidate * VoteCounter::getWinner()
{
	cout << "Number of voters : " << this->ballots.size() << "\n";
	Candidate * winner = this->results.getWinner();
	return winner;
}

void VoteCounter::printCandidates()
{
	int len = order.size();
	for (int i = 0; i < len; i++) {
		cout << "Candidate #" << i << " : \n";
		cout << order.at(i)->toString();
		cout << "\n";
	}
	cout << "\n";
}

void VoteCounter::printBallots()
{
	for (int i = 0; i < ballots.size(); i++)
	{
		cout << "Ballot #" << i << " : \n";
		cout << ballots.at(i)->toString();
		cout << "\n";
	}
}

void VoteCounter::printTree()
{
	this->results.print();
}
