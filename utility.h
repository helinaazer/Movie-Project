#ifndef utility_h
#define utility_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Utility {
public:
    //remove trailing spaces in string
    static string& removeTrailing(string& str, const string& chars = "\t\n\v\f\r ");
    //remove leading spaces in string
    static string& removeLeading(string& str, const string& chars = "\t\n\v\f\r ");
    //combine two strings(trim)
    static string& combine(string& str, const string& chars = "\t\n\v\f\r ");
    //split string
    static vector<string> splitString(const string& s, char iden);
};
#endif