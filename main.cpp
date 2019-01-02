#include <iostream>
#include <stdlib.h>
#include "VoterDB.h"
//#include "Voter.h"


using namespace std;

int main(int argc,char** argv){
	int maxVoters = atoi(argv[1]);
	string instruction = "";
	const string TERMINAL = "Quit";

	if (atoi(argv[1]) == 1){
		cout << "Input max voters"
		     << "-> ";
		cin >> maxVoters;
	}

	VoterDB dataBase(maxVoters);

	//if (argv[2].exists()){	//TODO set up load and save file
	//	dataBase.Load(str(argv[2]));
	//}

	while (instruction != TERMINAL)
	{
		cout << "INSTRUCTIONS: Login,New,Report,Save,Load,Quit\n";
		cout << "-> ";
		cin >> instruction;

		if (instruction == "Login")
			dataBase.Login();
		else if (instruction == "New")
			dataBase.New();
		else if (instruction == "Report")
			dataBase.Report();
//		else if (instruction == "Save")
//			dataBase.Save();
//		else if (instruction == "Load")
//			dataBase.Load();
		else if (instruction != TERMINAL)
			cout << "Incorrect Instruction\n";
	}

//	delete(dataBase);
	cout << "Program End\n";
	return 0;
}
