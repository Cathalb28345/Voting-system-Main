
class Candidate
{
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include<fstream>
#include <map>
#include <cassert>
#include <vector>;
	using std::vector; // to 
	using namespace std;

private:

	string Name;
	string PartyName;
	string setName;
	string getName;
	string setParty;
	string getParty;
	vector<string> Candidate;
	Candidate.reserve(CandidateCount); // optional, but speeds things up a bit

	for (i = 0; i <= CandidateCount; i++)
	{
		string CandidateName = CandidateName = line.substr(0, positionofmarker);
		CandidateName.push_back(Name(CandidateName));
		cout << CandidateName;

	}

public:
	string setName(string tempName)
	{
		Name = tempName;
	}
	string getName(string tempName)
	{
		return Name;
	}
	void setParty(string Partytemp)
	{
		PartyName = Partytemp;
	}
	string getParty(string Partytemp)
	{
		return PartyName;
	}
};


/*
Candidate.push_back("Michael D. Higgins");
Candidate.push_back("Leo Varadkar");
Candidate.push_back("Simon Coveney");
Candidate.push_back("Thomas Coll");
Candidate.push_back("Alex Matthews");
Candidate.push_back("Finnian Fanning");*/#pragma once
