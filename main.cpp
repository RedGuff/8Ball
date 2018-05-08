#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    srand(time(NULL)); // No need for better init.
    // Draw 8Ball.
    string I8 =  "I8.txt"; // Read file.
    ifstream file1(I8.c_str(), ios::in);  // Open to read.
    {
        if(!file1) // No file...
        {
            cout << "" << endl;
            cerr << "     _______" << endl;
            cerr << "    /  ___  \\" << endl;
            cerr << "   /  /   \\  \\" << endl;
            cerr << "  |  |  8  |  | " << endl;
            cerr << "   \\  \\___/  /" << endl;
            cerr << "    \\_______/" << endl;

            cout << "" << endl;
        }
        else
        {
            string line1;
            while(getline(file1, line1))  // While the line is readable...
            {
                cout << line1 << endl;
            }
        }
    }
    file1.close();
// Draw "?".
    string IP =  "IP.txt";
    ifstream file2(IP.c_str(), ios::in);
    {
        if(!file2)
        {
            string line2;
            while(getline(file2, line2))
            {
                cout << line2 << endl;
            }
            cout << "" << endl;
        }
        else
        {
            cerr << "   __" << endl;
            cerr << "  /   \\" << endl;
            cerr << "       |" << endl;
            cerr << "      /" << endl;
            cerr << "     /" << endl;
            cerr << "    |" << endl;
            cerr << "" << endl;
            cerr << "    o" << endl;
            cout << "" << endl;
        }
    }
    file2.close();

    // Read file for language.
    string lgg = "";  // Language.
    vector<string> lineReaded(1,""); // Optimization is possible.
    string lineReadedNow="";
    ifstream fileLgg("8Ball.cfg", ios::in);  // What language?
    if(!fileLgg) // No file.
    {
        lgg = "EN.lgg";
    }
    else
    {
        while (lgg == "")
        {
            getline(fileLgg, lgg);
        }
        fileLgg.close();
        if (lgg == "") // Empty file...
        {
            lgg = "EN.lgg";
        }
    }
// clog << lgg  << endl; // Test ok.
// clog <<  lgg.size() << endl; // Test ok. // One letter too much (eol).

    ifstream fileStr1(lgg.c_str(), ios::in);  // What language?
    // ifstream fileStr("FR-fr.lgg", ios::in);  // Test ok. // One letter too much (eol) in lgg.c_str().
    if(!fileStr1) // No file found...
    {
        lgg = lgg.substr(0,lgg.size()-1); // One letter too much (eol).
// clog << lgg  << endl; // Test ok.
// clog <<  lgg.size() << endl; // Test ok.
    }
    fileStr1.close();
    // Now, you can read.
    // Read file for number of strings (?).
    int numberOfLineReaded = 0;
    ifstream fileStr(lgg.c_str(), ios::in);  // What language?
    if(!fileStr) // No file...
    {
        cerr << "I am stupid." << endl; // No file of sentences.
    }
    else
    {
        while (!fileStr.eof())
        {
            getline(fileStr, lineReadedNow);  // Read line in.
           // lineReaded.push_back(lineReadedNow);
          //  if (lineReaded[numberOfLineReaded] != "")
            if (lineReadedNow != "")  // Eol not needed: test ok.
            {
                numberOfLineReaded++;
            }
           // clog << lineReaded[numberOfLineReaded] << endl; // Test ok.

    // if (lineReaded[numberOfLineReaded] == "")
            {
                // cerr << "/!\\ 2" << "   " << lgg << endl; // Test raté (caractère de fdl non nul?)
            }

        }

    }
    fileStr.close();

    // clog << numberOfLineReaded << endl; // Test ok.
// Random string.
    int numberOfLine= rand() % numberOfLineReaded + 1;
    // clog << numberOfLine << endl; // Test ok.
    // Read file for strings.
    // Not optimized, I know.


 ifstream fileStrFinal(lgg.c_str(), ios::in);  // What language?
    if(!fileStrFinal) // No file...
    {
     // Done.
    }
    else
    {
       // for (int lineCountedNow=0;lineCountedNow>rand() % numberOfLineReaded + 1;;lineCountedNow++) // rand each time: stupid! Do NOT do it! (I didn't!)
        for (int lineCountedNow=0;lineCountedNow<numberOfLine;lineCountedNow++)
        {
getline(fileStrFinal, lineReadedNow);  // Read line in.
        }
    }
// Display.
     cout << lineReadedNow << endl;
    return 0;
}
