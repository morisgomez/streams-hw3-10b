/*
PIC 10B Homework 3, reverse_words.cpp
Author: Moris Gomez
UID: 705089833
Discussion Section: 1B
Date: 02/03/2023
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string filename;
    string outfilename;
    cout << "Please enter the input data file name: ";
    cin >> filename;
    cout << "Please enter the output data file name: ";
    cin >> outfilename;

    //reading file:
    fstream fin;
    fin.open(filename, ios::in);

    vector<string> vect; //vector to store data

    if (fin.is_open()) {
        string word;
        while (fin >> word)
        {
            vect.push_back(word);
        }
    } else {
        cout << "input file could not be opened!" << endl;
    }
    fin.close();


    //now let's write to output.txt:
    fstream fout;
    fout.open(outfilename, ios::out);

    if (fout.is_open()) //checks if the file has been opened. if not, we cannot write data on it.
    {
       for (int i = vect.size() - 1; i >= 0; i--)
        {
           fout << vect[i] << " ";
        }
    }
    else
    {
        cout << "output file could not be opened" << endl;
    }
    return 0;
}