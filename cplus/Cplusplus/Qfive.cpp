#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("Example.txt");
    ofstream outFile("Example.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }else {
        string line;

    cout << "Enter lines of text (press Enter on an empty line to finish):\n";

    while (true) {
        getline(cin, line);

        // Check if the line is empty (just a newline character)
        if (line.empty()) {
            break;
        }

        // Write the line to the file
        outFile << line << endl;
    }
    }

    cout << "Contents of Example.txt:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
