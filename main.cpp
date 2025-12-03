#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isAlphaOrUnderscore(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_');
}


bool isAlphaNumericOrUnderscore(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_');
}


bool isValidIdentifier(const string& input) {
    if (input.empty() || !isAlphaOrUnderscore(input[0])) {
        return false;
    }

    for (int i = 1; i < input.length(); i++) {
        if (!isAlphaNumericOrUnderscore(input[i])) {
            return false;
        }
    }

    return true;
}


void checkIdentifier() {
    string filename = "identifiers.txt";
    ifstream inputFile(filename);


    string line;
    while (getline(inputFile, line)) {
        if (isValidIdentifier(line)) {
            cout << "\"" << line << "\" is a valid identifier." << endl;
        } else {
            cout << "\"" << line << "\" is NOT a valid identifier." << endl;
        }
    }

    inputFile.close();
    cout << endl;
}

