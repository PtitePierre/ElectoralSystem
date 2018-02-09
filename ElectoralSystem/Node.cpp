/*
* Joint Assignement : C++ - DSA II
* Student : Pierrette Sotty
* Student number : C00223825
*/
#include "stdafx.h"
#include "Node.h"
#include "Candidate.h"
#include <string>

/**
 * Initializes the Node containing c
 * voteCount starts from 0
 * @param Candidate * c : pointer on the candidate represented by this node
 */
Node::Node(Candidate * c)
{
	this->voteCount = 0;
	this->cdt = c;
}


Node::~Node()
{
}

/**
 * add a follower candidate to the current node
 * @param Candidate * c : the follower to add
 * @return : the node containing the added follower
 */
Node * Node::addFollower(Candidate * c)
{
	Node* follower;
	int pos = this->posFollower(c);
	if (pos == -1)	// if no follower recorded
	{
		follower = new Node(c);
		this->followers.push_back(follower);
	}
	else
	{
		follower = this->followers[pos];
	}
	follower->increment();
	return follower;
}

/**
 * get the position of c in the followers vector of the current node
 * if c is not in followers it returns -1
 * @param Candidate * c : candidate whose the position is wanted
 * @return : position of c
 */
int Node::posFollower(Candidate * c)
{
	int pos = -1;
	for (int i = 0; i < this->followers.size(); i++)
	{
		if (this->followers[i]->cdt == c)
		{
			pos = i;
		}
	}
	return pos;
}

/// increment voteCount
void Node::increment()
{
	this->voteCount++;
}

/**
 * 
 * @param Node * added : node to sum
 * for each follower in followers of added
 *		get the pos of the follower in this.followers 
 *		that contains the same candidate as added.followers[i]
 *		this.followers[pos].voteCount += follower.voteCount
 *		this.sumBanches(added.followers[i])
 */
void Node::addBranche(Node * added)
{
	for (int i = 0; i < added->followers.size(); i++)
	{
		int pos = this->posFollower(added->followers[i]->getCdt());
		if (pos != -1)
		{
			this->followers[pos]->voteCount += added->followers[i]->getVoteCount();
			this->followers[pos]->addBranche(added->followers[i]);
		}
		else
		{
			this->followers.push_back(added->followers[i]);
		}
	}
}

/**
 * gets the followers of c in followers
 * adds them to the current followers
 * ejects c from the followers of the current followers
 * delete c from the current followers
 * @param Candidate * c : candidate that has to be ejected
 */
void Node::eject(Candidate * c)
{
	int pos = this->posFollower(c);
	if (pos != -1)
	{
		this->addBranche(this->followers[pos]);
		this->followers.erase(this->followers.begin()+pos);
	}
	for (int i = 0; i < this->followers.size(); i++)
	{
		followers[i]->eject(c);
	}
}

/**
 * names the loser candidate with the lowest voteCount in followers
 * @return loser
 */
Node * Node::getLoser()
{
	Node * loser = followers[0];
	for (int i = 0; i < this->followers.size(); i++)
	{
		if (followers[i]->getVoteCount() < loser->getVoteCount())
			loser = followers[i];
	}
	return loser;
}


Candidate * Node::getCdt()
{
	return this->cdt;
}


int Node::getVoteCount()
{
	return this->voteCount;
}


vector<Node*> Node::getFollowers()
{
	return this->followers;
}


string Node::toString()
{
	string str = this->cdt->toString() + " got " + to_string(this->voteCount) + " vote(s).";
	return str;
}

void Node::print()
{
	/*
	if (this->cdt != nullptr)
	{
		cout << "- " << this->voteCount << " : " ;
		this->cdt->print();
	}
	for (int i = 0; i < this->followers.size(); i++)
	{
		followers[i]->print();
	}
	*/
	cout << this->nodeString(0);
}

string Node::nodeString(int rank)
{
	string str = "";
	if (this->cdt != nullptr)
	{
		for (int i = 0; i < rank; i++)
		{
			str += "|   ";
		}
		str += "+   " + this->cdt->getName() + " : " + to_string(this->voteCount) + "\n";
	}
	for (int i = 0; i < this->followers.size(); i++)
	{
		for (int i = 0; i < rank; i++)
		{
			str += "|   ";
		}
		str += followers[i]->nodeString(rank+1);
	}
	return str;
}
