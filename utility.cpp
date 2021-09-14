#include "utility.h"

using namespace std;

// remove trailing spaces in string
string &Utility::removeTrailing(string &str, const string &chars) {
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

// remove leading spaces in string
string &Utility::removeLeading(string &str, const string &chars) {
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

// combine two strings(trim)
string &Utility::combine(string &str, const string &chars) {
  return removeLeading(removeTrailing(str, chars), chars);
}

// split string
vector<string> Utility::splitString(const string &s, char iden) {
  vector<string> vec;
  string v;
  istringstream ve(s);
  while (getline(ve, v, iden)) {
    vec.push_back(v);
  }
  return vec;
}