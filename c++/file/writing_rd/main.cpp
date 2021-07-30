#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile;
    ifstream inFile;

    string outputFileName = "text.txt";
    string inFileName = "text.txt";

    outFile.open(outputFileName);

    if (outFile.is_open())
    {
        outFile << "hello" << endl;
        outFile << 123 << endl;
        outFile.close();
    }
    else
    {
        cout << "Not create file: " << outputFileName << endl;
    }

    inFile.open(inFileName);

    if (inFile.is_open())
    {
        string line;

        while (inFile)
        {
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();
    }

    return 0;
}