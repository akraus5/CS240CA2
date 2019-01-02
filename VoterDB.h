#include<iostream>
#include <stdlib.h>
#include "Voter.h"

using namespace std;

class VoterDB{
	public:
		VoterDB(int& maxV);
		void Login();
		void New();
		void Report();
//		void Save();
//		void Load();
	private:
		Voter * Voters;
		int MAXVOTERS;
		const int HARDMAX = 1000;
		int currentVoterAmt = 0;
		bool arrayFull = false;
		const string TERMINAL = "Quit";
		string popComma(string& str);
};
