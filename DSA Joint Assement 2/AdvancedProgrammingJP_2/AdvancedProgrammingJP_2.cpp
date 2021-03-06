#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Candidate {
public:
	void setName(string name);
	string getName();
	void setParty(string CandidateParty);
	string getParty();
	void setNumber(int CandidateNum);
	int getNumber();

	Candidate();

private:
	string CandidateName;
	string CandidateParty;
	int CandidateNumber;
};
Candidate::Candidate()
{
	cout << "Candidate is being created" << endl;
}
void Candidate::setName(string name)
{
	CandidateName = name;
}
string Candidate::getName()
{
	return CandidateName;
}
void Candidate::setNumber(int CandidateNum)
{
	CandidateNumber = CandidateNum;
}
int Candidate::getNumber()
{
	return CandidateNumber;
}
void Candidate::setParty(string party)
{
	CandidateParty = party;
}
string Candidate::getParty()
{
	return CandidateParty;
}
class BallotPaper {
public:
	void setPreference(int Pref, int num);
	int getPreference(int n);

	BallotPaper(int size); // This is the constructor
private:
	vector<int> CandidateBallotPreference;
	int CandidateBallotPref;
};

BallotPaper::BallotPaper(int size)
{
	CandidateBallotPreference.resize(size);
}
void BallotPaper::setPreference(int Pref, int num)
{
	CandidateBallotPreference[Pref - 1] = num;
}
int BallotPaper::getPreference(int n)
{
	return CandidateBallotPreference[n];
}
class VoteCounter {
public:
	string getName();
	string getParty();
	vector<BallotPaper> BallotVector;
	vector<Candidate> CandidateVector;

	void setCount(int Votecount);
	int getCount();

	VoteCounter(vector<Candidate> CandidateVector, vector<BallotPaper> BallotVector);

private:
	int VoteCount;
	int CandidateVoteCount;
	string CandidateName;
	string CandidateParty;
};
VoteCounter::VoteCounter(vector<Candidate> CandidateVector, vector<BallotPaper> BallotVector)
{
	this->BallotVector = BallotVector;
	this->CandidateVector = CandidateVector;
}

string VoteCounter::getName()
{
	return CandidateName;
}
string VoteCounter::getParty()
{
	return CandidateParty;
}
void VoteCounter::setCount(int Votecount)
{
	CandidateVoteCount = Votecount;
}
int VoteCounter::getCount()
{
	return CandidateVoteCount;
}
void CountVotes(vector<Candidate> CandidateVector, vector<BallotPaper> BallotVector)
{
	vector<vector<BallotPaper> > count;
	int smallest = 0;
	int size = (int)CandidateVector.size();
	vector<bool> boolarr;
	boolarr.resize(size);
	count.resize(CandidateVector.size());
	for (int x = 0; x < (int)BallotVector.size(); x++) {
		count[BallotVector[x].getPreference(1)].push_back(BallotVector[x]);
	}
	for (int k = 0; k < CandidateVector.size(); k++) {
		boolarr[k] = true;
	}
	for (int y = 0; y < (int)CandidateVector.size() - 1; y++) 
	{
		bool boolCheck = false;
		for (int t = 0; t < (int)CandidateVector.size(); t++) {
			if (boolarr[t] && !boolCheck) {
				boolCheck = true;
				smallest = t;
			}
			else if (count[t].size() < count[smallest].size() && boolarr[t]) {
				smallest = t;
			}
		}
		int votesCandOne = count[y].size();
		//cout << votesCandOne << endl;
		//cout << smallest << count[smallest].size()<< endl;
		cout << "Total Votes " << count[smallest].size() << endl;
		boolarr[smallest] = false;
		for (int z = 0; z < (int)count[smallest].size(); z++) {
			for (int i = 0; i < CandidateVector.size(); i++) {
				if (boolarr[count[smallest][z].getPreference(i)]) {
					count[count[smallest][z].getPreference(i)].push_back(count[smallest][z]);
				}
			}
		}
	}
	for (int p = 0; p < CandidateVector.size(); p++) {
		if (boolarr[p]) {
			cout << " " << CandidateVector[p].getName() << "  Wins the election with: " << count[smallest].size() << " votes." << endl;
		}
	}
}
int main()
{
	ifstream myReadFile;
	myReadFile.open("Candidates.txt");
	string line;
	int CandidateBallotNumber = 1;
	vector<Candidate> CandidateVector;
	//Read candiadates
	while (getline(myReadFile, line) && line != "#") {
		Candidate candidate;
		string name, party;

		size_t positionofmarker = line.find('|');
		name = line.substr(0, positionofmarker);
		candidate.setName(name);
		candidate.setNumber(CandidateBallotNumber);
		CandidateBallotNumber += 1;
		// read in the party
		party = line.substr(positionofmarker + 1, line.size() - 1);
		candidate.setParty(party);
		// out the name party and number
		cout << "The candidates ballot number is: " << candidate.getNumber() << endl;
		cout << "Candidate name is: "<< name <<" The candidates Party is: "<< party<< endl;
		CandidateVector.push_back(candidate);
	}
	// Read votes
	vector<BallotPaper> BallotVector;
	int hold, split;
	while (getline(myReadFile, line)) {
		BallotPaper newBallot((int)CandidateVector.size());
		for (int j = 0; j < (int)CandidateVector.size(); j++) {
			stringstream(line) >> hold;
			split = line.find(",");
			newBallot.setPreference(hold, j);
			line = line.substr(split + 1);
		}
		BallotVector.push_back(newBallot);
	}
	VoteCounter VoteCounter(CandidateVector, BallotVector);
	CountVotes(CandidateVector, BallotVector);
	system("pause");
	return 0;
}