#include<iostream>
#include <stdlib.h>

using namespace std;

class Voter{
	public:
		Voter();
		Voter(	string uid, 
			string pd, 
			string nameLst, 
			string nameFst, 
			string ageStr, 
			string stName, 
			string stNumStr, 
			string twn, 
			string zpC, 
			string amtDt);
		void New();
		void Load(string uid, 
			string pd, 
			string nameLst, 
			string nameFst, 
			string ageStr, 
			string stName, 
			string stNumStr, 
			string twn, 
			string zpC, 
			string amtDt);//param
		void menu();
		void Update();
		void View();
		void Donate();
		void Report();
		bool checkPassword(string& x);
		string getAllInfo();
		float roundPenny(float& num);
		string getUserid();
		//string getPassword(); //Remove??
		string getNameLast();
		string getNameFirst();
		string getStreetName();
		string getTown();
		string getZipCode();
		int getAge();
		int getStreetNumber();
		float getAmountDonated();
		void setUserid(string x);
		void setPassword(string x);
		void setNameLast(string x);
		void setNameFirst(string x);
		void setAge(int x);
		void setStreetName(string x);
		void setStreetNumber(int x);
		void setTown(string x);
		void setZipCode(string x);
		void setAmountDonated(float x);
	private:
		void inputUserid();
		void inputPassword();
		void inputNameLast();
		void inputNameFirst();
		void inputAge();
		void inputStreetName();
		void inputStreetNumber();
		void inputTown();
		void inputZipCode();
		string nameLast;
		string nameFirst;
		string streetName;
		string town;
		string zipCode;
		string userid;
		string password = "";
		int age;
		int streetNumber;
		float amountDonated;
		string TERMINAL = "Quit";	
		string LOGOUT = "Logout";
		string LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string SPACE = " ";
		string DIGITS = "0123456789";
		string NUMLET = LETTERS + DIGITS;
};
