#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Voter.h"

using namespace std;

Voter::Voter(){
	New();
}

Voter::Voter(	string uid, 
		string pd, 
		string nameLst, 
		string nameFst, 
		string ageStr, 
		string stName, 
		string stNumStr, 
		string twn,		
		string zpC, 
		string amtDt){		//CONSTRUCTOR FOR LOADING NEED PARAM DEBUG
	Load(	uid, 
		pd, 
		nameLst, 
		nameFst, 
		ageStr, 
		stName, 
		stNumStr, 
		twn,
		zpC, 
		amtDt);
}

void Voter::inputPassword(){
	string x = "";
	if (password != ""){
		cout << "Enter old password to change, or enter " << TERMINAL << endl
			 << "-> \n";
		cin >> x;
		while (x != "Quit" || x!= password){
			cout << "Incorrect:" <<
				"Enter old password to change, or enter " << TERMINAL << 
				"\n-> ";
			cin >> x;
		
		}
	}
	if (x != "Quit"){
		cout << "password must be atleast 6 characters,\n" <<
			"containing at least 1 digit and 1 non-letter/non-digit, cannot have ','\n" <<
			"-> ";
		cin >> x;
		while ((x.length() < 6) || (x.find_first_of(DIGITS) == -1) || (x.find_first_of(NUMLET) == -1) || (x.find_first_of(",") != -1)){
			cout << "Incorrect:"
				<< "password must be atleast 6 characters,\n" 
				<< "containing at least 1 digit and 1 non-letter/non-digit, cannot have ','\n"
				<< "password: ";
			cin >> x;
		}
		password = x;
	}
}

void Voter::inputNameLast(){
	string x;
	cout << "Enter Last Name: ";
	cin >> x;
	while (x.find_first_not_of(LETTERS) != -1) {
		cout << "Can only contain letters, Reenter\n->";
		cin >> x;
	}
	nameLast = x;
}
void Voter::inputNameFirst() {	
	string x;
	cout << "Enter First Name: ";
	cin >> x;
	while (x.find_first_not_of(LETTERS) != -1) {
		cout << "Can only contain letters, Reenter\n->";
		cin >> x;
	}
	nameFirst = x;
}
void Voter::inputAge() {
	int y;
	cout << "Enter Age: ";
	cin >> y;
	while (y < 0){
		cout << "Enter Non-negative Age: ";
		cin >> y;
	}
	age = y;
}
void Voter::inputStreetName() { //multiple words
	string x;
	cout << "Enter Street Name: ";
	getline (cin, x);
	while (x.find_first_not_of(NUMLET + SPACE) != -1) {
		cout << "Can only contain letters and spaces, Reenter\n->";
		cin >> x;
	}
}
void Voter::inputStreetNumber() {
	cout << "Enter Street Number: ";
	cin >> streetNumber;
}
void Voter::inputTown() {
	cout << "Enter Town: "; //multiple words
	getline (cin, town);
	
}
void Voter::inputZipCode(){
	string x;
	while ((x.length() != 5) || (x.find_first_not_of(DIGITS) != -1)){
		cout << "Re-enter 5 digit Zip Code: ";
		cin >> x;
	}
	zipCode = x;
}


void Voter::setUserid(string x){
	userid = x;
}
void Voter::setPassword(string x){
	password = x;
}
void Voter::setNameLast(string x){
	nameLast = x;
}
void Voter::setNameFirst(string x){
	nameFirst = x;
}
void Voter::setAge(int x){
	age = x;
}
void Voter::setStreetName(string x){
	streetName = x;
}
void Voter::setStreetNumber(int x){
	streetNumber = x;
}
void Voter::setTown(string x){
	town = x;
}
void Voter::setZipCode(string x){
	zipCode = x;
}

void Voter::setAmountDonated(float x){
	amountDonated = x;
}

string Voter::getAllInfo(){
	string cSp = ",";
	return userid + cSp + password + cSp + nameLast + cSp + nameFirst + cSp + to_string(age) + cSp + streetName + cSp + to_string(streetNumber) + cSp + zipCode + cSp + to_string(amountDonated) + "\n";
}
string Voter::getUserid(){
	return userid;
}	
//string Voter::getPassword(){ //Remove??
//	return password;
//}
string Voter::getNameLast(){
	return nameLast;
}
string Voter::getNameFirst(){
	return nameFirst;
}
int Voter::getAge(){
	return age;
}
string Voter::getStreetName(){
	return streetName;
}
int Voter::getStreetNumber(){
	return streetNumber;
}
string Voter::getTown(){
	return town;
}
string Voter::getZipCode(){
	return zipCode;
}

bool Voter::checkPassword(string& x){
	return (x == password);
}

float Voter::getAmountDonated(){
	return amountDonated;
}

float Voter::roundPenny(float& num){
	return floor((num * 100) +.5) / 100;
}

void Voter::Load(string uid, 
		string pd, 
		string nameLst, 
		string nameFst, 
		string ageStr, 
		string stName, 
		string stNumStr, 
		string twn, 
		string zpC, 
		string amtDt){		//TODO add parameters
	setUserid(uid);
	setPassword(pd);
	setNameLast(nameLst);
	setNameFirst(nameFst);
	setAge(stoi(ageStr));
	setStreetName(stName);
	setStreetNumber(stoi(stNumStr));
	setTown(twn);
	setZipCode(zpC);
	setAmountDonated(stof(amtDt));
}
void Voter::New() {
	inputUserid();
	inputPassword();
	inputNameLast();
	inputNameFirst();
	inputAge();
	inputStreetNumber();
	inputStreetName();
	inputTown();
	inputZipCode();
}

void Voter::menu(){

	string instruction = "0";
	
	cout << "\nEnter Instruction, Options are: " << endl
	     << "Update, Password, View, Donate, Report, "<< TERMINAL << endl;

	while (instruction != TERMINAL){
		cout << "-> ";
		cin >> instruction;
		if (instruction == "Update")
			Update();
		else if (instruction == "Password")
			inputPassword();
		else if (instruction == "View")
			View();
		else if (instruction == "Donate")
			Donate();
		else if (instruction == "Report")
			Report();
		else if (instruction != TERMINAL)
			cout << "Incorrect Instruction\n";
	}
}

void Voter::Update() {
	string UInstruction;	//multiple words

	cout 	<< "\nEnter the name of the instruction you want to update\n"
	     	<< "Options are:\n"
	     	<< "LastName, FirstName, Age, StreetName,\n"
	     	<< "StreetNumber, Town, ZipCode\n"
	     	<< "Enter 'Quit' to end Update\n";
	while (UInstruction != TERMINAL){
		cout << "-> ";
		getline(cin,UInstruction);
		if (UInstruction == "Last Name")
			inputNameLast();
		else if (UInstruction == "First Name")
			inputNameFirst();
		else if (UInstruction == "Age")
			inputAge();
		else if (UInstruction == "Street Number")
			inputStreetNumber();
		else if (UInstruction == "Street Name")
			inputStreetName();
		else if (UInstruction == "Town")
			inputTown();
		else if (UInstruction == "Zip Code")
			inputZipCode();
		else if (UInstruction != TERMINAL)
			cout << "Incorrect Instruction\n";
	}
}

void Voter::View() {
	cout<< "Donor Info:\n"
	    << nameFirst<< " " << nameLast << ": age " << age << endl
	    << streetNumber << " " << streetName << endl
	    << town << " " << zipCode << endl
	    << "Current Amount Donated: $" << roundPenny(amountDonated) << endl;
}

void Voter::Donate() {
	float newDonation;
	cout << "Current Amount Donated: " << amountDonated << "$\n";
	cout << "Added Amount: ";
	cin >> newDonation;
	while (newDonation < 0){
		cout << "Error, Enter a non-negative number\n"
		     << "Added Amount: ";
		cin >> newDonation;
	}
	while (newDonation + amountDonated > 2700){
		cout << "Error, total donation amount must not exceed $2,700.\n"
		     << "Smaller Amount (or 0): ";
		cin >> newDonation;
		while (newDonation < 0){
			cout << "Error, Enter a non-negative number\n"
			     << "Added Amount: ";
			cin >> newDonation;
		}
	}
	amountDonated += newDonation;
}


void Voter::Report() {
	cout << nameLast << " $" << roundPenny(amountDonated) << endl;
}


void Voter::inputUserid(){
	string x;
	cout << "userid must be between 5 and 10 characters,\n" 
	     << "containing only letters and digits\n"
	     << "userid: ";
	cin >> x;
	while ( ((x.length() < 5) || (x.length() > 10)) ||(x.find_first_not_of(NUMLET) != -1)){
		cout << "Incorrect:"
			 << "userid must be between 5 and 10 characters,\n" 
			 << "containing only letters and digits\n"
			 << "userid: ";
		cin >> x;	
	}
	
	userid = x;
}
