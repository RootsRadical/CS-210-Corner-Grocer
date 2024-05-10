#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class CornerGrocer {

private:
    map<string, int> frequencyOfItem;
    string nameOFInpFile;
    string nameOFOutFile;

public:
    //Defining constrcutor to initialize the input & output file 
    CornerGrocer(const string& nameOFInpFile, const string& nameOFOutFile) {
        this->nameOFInpFile = nameOFInpFile;
        this->nameOFOutFile = nameOFOutFile;
    }
    //Define the function "readDataOFinpFile()" to read the input and validate the input file 
    void readDataOFinpFile() {
        ifstream inpFile(nameOFInpFile);
        if (!inpFile) {
            cout << "Error opening input file." << endl;
            return;
        }
        //Reading the items form input
        string groceryItem;
        while (inpFile >> groceryItem) {
            frequencyOfItem[groceryItem]++;
        }
        //Closing input file
        inpFile.close();
    }
    //Defining obtainFrequency function to get the frequency of a particular item
    int obtainFrequency(const string& groceryItem) {
        return frequencyOfItem[groceryItem];
    }
    //Defining displayFrequency function to display items and how many times
    void displayFrequency() {
        for (const auto& itemPair : frequencyOfItem) {
            cout << itemPair.first << " " << itemPair.second << endl;
        }
    }
    //Defining displayHistogram function to display the histogram 
    void displayHistogram() {
        for (const auto& itemPair : frequencyOfItem) {
            cout << itemPair.first << " ";
            for (int i = 0; i < itemPair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    //Defining createoutFile() function to create output file for backing up file
    void createoutFile() {
        ofstream outFile(nameOFOutFile);
        if (!outFile) {
            cout << "Error creating output file." << endl;
            return;
        }

        for (const auto& itemPair : frequencyOfItem) {
            outFile << itemPair.first << " " << itemPair.second << endl;
        }

        outFile.close();
        cout << "Output file created." << endl;
    }
};

int main() {
	string nameOFInpFile = "CS210_Project_Three_Input_File.txt";
	string nameOFOutFile = "frequency.dat";

	CornerGrocer grocer(nameOFInpFile, nameOFOutFile);

	//Call function readDataOFinpFile() to read data from input file
	grocer.readDataOFinpFile();

	//Call function createoutFile() to create output file
	grocer.createoutFile();

	int userInput;
	//Printing Menu to user
	do {
		cout << "Menu:" << endl;
		cout << "1. Obtain the frequency of a particular item" << endl;
		cout << "2. Print frequency of all items" << endl;
		cout << "3. Print histogram of item frequency" << endl;
		cout << "4. Exit" << endl;
		cout << "Select a option: ";
		cin >> userInput;

		switch (userInput) {
		case 1: {
			string item;
			cout << "Enter the item you want to see: ";
			cin >> item;
			cout << "Frequency of " << item << ": " << grocer.obtainFrequency(item) << endl;
			break;
		}
		case 2:
			grocer.displayFrequency();
			break;
		case 3:
			grocer.displayHistogram();
			break;
		case 4:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid. Try Again." << endl;
		}
		cout << endl;
	}

	while (userInput != 4);

	return 0;
}
