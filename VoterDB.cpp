#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "VoterDB.h"

using namespace std;

VoterDB::VoterDB(int& maxV){
	while (maxV > HARDMAX || maxV < 1){
		cout << "Enter smaller Maximum number, Must be a Whole number less than "
		     << HARDMAX << ".\n-> ";
		cin >> maxV;
	}
	MAXVOTERS = maxV;

	Voters = new Voter[MAXVOTERS];
}

void VoterDB::Login() {				//DEBUG
	string pswd = "";
	string uid = "";
	bool correctUser = false;

	while (uid != TERMINAL){
		cout << "Enter userid or 'Quit': ";
		cin >> uid;

		while ((uid != TERMINAL) ){
			for (int i = 0; (i <= currentVoterAmt) && !(correctUser); i++){
				correctUser = Voters[i].getUserid() == uid;
				while (correctUser && pswd != TERMINAL){
					cout << "Enter password: ";
					cin >>pswd;
					if (Voters[i].checkPassword(pswd))
						Voters[i].menu();
					else if (pswd != TERMINAL)
						cout << "Incorrect password, Re-enter password or enter " << TERMINAL << endl;
				}
			}
			if ((!correctUser)){
				cout << "There is no username of " << uid <<
					". Re-enter user id or Quit\n-> ";
				cin >> uid;
			}
		}
	}
}

void VoterDB::New(){				//DEBUG
	if (arrayFull) cout << "Voter Database Full, Cannot create new Voter\n";
	else{
		Voters[currentVoterAmt] = Voter();
		currentVoterAmt++;
		arrayFull = (currentVoterAmt >= MAXVOTERS);
	}
}


void VoterDB::Report(){				//DEBUG
	float totalDonationAmt = 0;
	for (int i= 0;i < currentVoterAmt; i++){
		totalDonationAmt += Voters[i].getAmountDonated();
	}
	cout << "Total Voter Ammount: " << currentVoterAmt << endl <<
		"Total Ammount Donated: $" << Voters[0].roundPenny(totalDonationAmt) << endl;
}
/*
void VoterDB::Save(){				//TODO
	fstream myfile;
	string filename;
	string fileData = "";
	string line;

	for (int i = 0; i < currentVoterAmt; i++){
		fileData += Voters[i].getAllInfo();
	}
	cout << "Enter name of .csv file, (leaving out .csv)\n"
	     << "-> ";
	cin >>  filename;			//TODO check if filename is present
	filename += ".csv";

	if(!myfile.is_open()){			//ERROR??
		myfile << fileData;
	}else {
		remove
		myfile << fileData;
		myfile.close();
	}
}

void VoterDB::Load(){				//TODO

	string useridT;
	string passwordT;
	string nameLastT;
	string nameFirstT;
	string ageT;
	string streetNameT;
	string streetNumberT;
	string townT;
	string zipCodeT;
	string amountDonatedT;

	fstream myfile;
	string filename;
	string line;

	cout << "Enter name of .csv file, (leaving out .csv)\n"
	     << "-> ";
	cin >>  filename;
	filename += ".csv";		//when loading and setting all voters to array, input true to avoid output troubles

	myfile.open(filename);			//ERROR??
	if (!myfile.is_open())				//ERROR??
		cout << "Cannot find file of name "<< filename << endl;
	else {
		int i = 0;
		while(getline(myfile, line)){
			useridT = popComma(line);
			passwordT = popComma(line);
			nameLastT = popComma(line);
			nameFirstT = popComma(line);
			ageT = popComma(line);
			streetNameT = popComma(line);
			streetNumberT = popComma(line);
			townT = popComma(line);
			zipCodeT = popComma(line);
			amountDonatedT = popComma(line);

			Voters[i] = Voter(useridT,
						passwordT,
						nameLastT,
						nameFirstT,
						ageT,
						streetNameT,
						streetNumberT,
						townT,
						zipCodeT,
						amountDonatedT);
			i++;
			}
		myfile.close();
	}

}
*/
string popComma(string& str){
	string retVal;
	int x;

	x = str.find_first_of(",");
	if (x != -1){
		retVal = str.substr(0,x);
		str = str.substr(x, str.length() - x);
		return retVal;
	}else return str.substr(0,str.length() -2);
}
