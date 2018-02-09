/**
 * Joint Assignement : C++ - DSA II
 * Student : Pierrette Sotty
 * Student number : C00223825
 */
#include "stdafx.h"
#include "Tree.h"

/// creates the root of the tree
Tree::Tree()
{
	/// first node doesn't contain any Candidate *
	root = new Node(nullptr);
}


Tree::~Tree()
{
}

/**
 * fill(vector<BallotPaper*> votes, int nbCdt)
 * @param vector<BallotPaper*> votes : liste of ballots
 * @param int nbCdt : number of candidate
 * fill the tree with the content of ballots
 */
void Tree::fill(vector<BallotPaper*> votes, int nbCdt)
{
	Node* current;
	for (int i = 0; i < votes.size(); i++)
	{
		current = root;
		for (int pref = 1; pref < nbCdt + 1; pref++)
		{
			current = current->addFollower(votes[i]->getPreference(pref));
		}
	}
}

/**
 * eject c from the tree
 * call the function eject(Candidate * c) of the Node* root
 * @param Candidate * c : pointer on the rejected candidate
 */
void Tree::ejectCandidate(Candidate * c)
{
	this->root->eject(c);
}

/**
 * Names a loser from the tree
 * @return the loser designated by the root's function getLooser
 */
Node * Tree::getLoser()
{
	return root->getLoser();
}

/**
 * Names a winner from the tree :
 * While the root has more than 1 followers, one is eliminated
 * The last candidate standing as root follower is the winner
 * @return the winner of the election
 */
Candidate * Tree::getWinner()
{
	int tour = 1;
	while (this->root->getFollowers().size() > 1)
	{
		cout << "Round #" << tour << " :\n";
		for (int numCdt = 0; numCdt < this->root->getFollowers().size(); numCdt++)
		{
			cout << " - " << this->root->getFollowers()[numCdt]->toString() << "\n";
		}
		Node * looser = this->getLoser();
		cout << " -> " << looser->getCdt()->toString() << " is eliminated.\n";
		//looser->getCdt()->toString();
		this->ejectCandidate(looser->getCdt());
		tour++;
	}

	Node * winner = root->getFollowers()[0];
	cout << "Round #" << tour << " :\n";
	cout << " ==> " << winner->getCdt()->toString() << " is the winner.\n";
	return winner->getCdt();
}

/// displays the tree in the console
void Tree::print()
{
	cout << "Root\n";
	this->root->print();
}
