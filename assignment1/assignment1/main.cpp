//RecycledBin rewrite of assignment 1 using c++ only version 2 bois
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string copy(const string source, int lengthToCopy);
string reverseCopy(const string source, int lengthToCopy);
string caseChangeCopy(const string source, int lengthToCopy); 
string replaceCopy(const string source, char target, char replace, int lengthToCopy); 
string read(); 

int main()
{
	const int WORD_SIZE = 15;
	string words[WORD_SIZE] = { "sprightful", "reason to row", "New York", "Bolton", "Frida", "" };
	string word;

	//testing the copy function
	cout << "Copy sprightful, should see sprightful" << endl;
	word = copy(words[0], strlen(words[0].c_str()));
	cout << word << endl << endl;

	// Testing the copy function to copy a certain number of characters from a string instead of the whole string. copying the first 5 characters in this instance.
	cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
	word = copy("Supercalifragilisticexpialidocious", 5);
	cout << word << endl << endl;

	//test the replace copy function
	cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
	word = replaceCopy(words[1], 'r', 's', strlen(words[1].c_str()));
	cout << word << endl << endl;

	// Test the replace copy function to copy a certain number of characters from a string instead of the whole string. copying the first 5 characters in this instance while replacing target characters
	cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
	word = replaceCopy("Supercalifragilistic", 'S', 'd', 5);
	cout << word << endl << endl;

	// Test the caseChangeCopy function
	cout << "Case change \"New York\", should see \"nEW yORK\".\n";
	word = caseChangeCopy(words[2], strlen(words[2].c_str()));
	cout << word << endl << endl;

	// Test the limit on the caseChangeCopy function
	cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
	word = caseChangeCopy("Supercalifragilistic", 5);
	cout << word << endl << endl;

	// Test the reverseCopy function
	cout << "Reverse \"Bolton\", should see \"notloB\"\n";
	word = reverseCopy(words[3], strlen(words[3].c_str()));
	cout << word << endl << endl;

	// Test the limit on the reverseCopy function
	cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
	word = reverseCopy("cytogeneticists", strlen("cytogeneticists") - 1);
	cout << word << endl << endl;

	cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
	word = replaceCopy(caseChangeCopy(reverseCopy(words[4], strlen(words[4].c_str())), strlen(words[4].c_str())), 'D', 'Z', strlen(words[4].c_str()));
	cout << word << endl << endl;

	cout << "Enter your entire name: ";
	words[5] = read();
	cout << words[5] << endl << endl;

	cout << "Reverse your name and change case.\n";
	cout << caseChangeCopy(reverseCopy(words[5], strlen(words[5].c_str())), strlen(words[5].c_str())) << endl;

	int wait;
	cin >> wait;
	return 0;
}

string copy(const string source, int lengthToCopy)
{
	string destination;
	for (int i = 0; i < lengthToCopy; i++)
	{
		destination += source[i];
	}
	return destination;
}

string replaceCopy(const string source, char target, char replace, int lengthToCopy)
{
	string destination;
	for (int i = 0; i < lengthToCopy; i++)
	{
		destination += source[i];
		if (source[i] == target)
		{
			destination[i] = replace;
		}
	}
	return destination;
}

string caseChangeCopy(const string source, int lengthToCopy)
{
	string destination;
	for (int i = 0; i < lengthToCopy; i++)
	{
		destination += source[i];
		if (islower(source[i]))
			destination[i] = toupper(source[i]);
		else if (isupper(source[i]))
			destination[i] = tolower(source[i]);
	}
	return destination;
}
string reverseCopy(const string source, int lengthToCopy)
{
	string destination;
	for (int i = 0; i < lengthToCopy; i++)
	{
		destination += source[lengthToCopy - i - 1];
	}
	return destination;
}

string read()
{
	string input;
	std::getline(cin, input);
	return input;
}