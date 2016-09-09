#include<iostream>
#include<fstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	
	char again = 'y';
	
	while (again == 'y' || again == 'Y') 
	{
	
	string choice = "Would you like to 1. write to or 2. read a file? ";
	int choiceInput;
	cout << choice;
	cin >> choiceInput;
	
	if (choiceInput == 1) {
	char outFile[80];
	ofstream outStream;
	string append;
	cout << "Please enter a filename: ";
	cin >> outFile;
	cout << "Please enter text you wish to append to the file(use underscores as spaces): ";
	cin >> append;
	std::replace(append.begin(), append.end(), '_', ' ');
	outStream.open(outFile, ios::out | ios::trunc);
	if(!outStream) {
		cout << "Error";
		return 1;
	}
	outStream<<append.c_str();
	cout<<"Completed, ";
	cout<<"";
	}
	
else if (choiceInput == 2){
  string line;
  string cond;
  std::string fn = ("Enter a filename: ");
  cout << fn;
  cin >> cond;
  
  ifstream myfile (cond.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }
  else cout << "Unable to open file";  
}

  else {
	  cout << choiceInput;
	  cout << " is not a valid input. ";
	} 
	cout << "Restart? (y/n): ";
	cin >> again;
	}
}