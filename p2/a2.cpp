////////////////////////////////////////////////////////////////////////////////
// File Name:      a2.cpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The source file for a2.
//
// IMPORTANT NOTE: THIS IS THE ONLY FILE THAT YOU SHOULD MODIFY FOR A2.
//                 You SHOULD NOT MODIFY any of the following:
//                   1. Name of the functions/methods.
//                   2. The number and type of parameters of the functions.
//                   3. Return type of the functions.
////////////////////////////////////////////////////////////////////////////////

#include "a2.hpp"
#include "trim.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
void cleanData(std::ifstream &inFile, std::ofstream &outFile,
               std::unordered_set<std::string> &stopwords) {
    // TODO: Implement this method.
    // # of lines of code in Gerald's implementation: 13
    // Do the following operations on each review before
    // storing it to the output file:
    //   1. Replace hyphens with spaces.
    //   2. Split the line of text into individual words.
    //   3. Remove the punctuation marks from the words.
    //   4. Remove the trailing and the leading whitespaces in each word.
    //   5. Remove the empty words.
    //   6. Remove words with just one character in them. You should NOT remove
    //      numbers in this step because if you do so, you'll lose the ratings.
    //   7. Remove stopwords.

/*     string punc = "!@#$%^&*(),./;'{}|[]-\\\""; //string containing all chars that should be removed
    string delim = " ";
    string word; 
    for(string line; getline(inFile, line); ) {
      cout << line << endl; 
      for(int i = 0; i < line.length(); ++i) {
        if(punc.find(line[i]) != string::npos)
          line.replace(i, 1, " "); //replaces all unwanted chars with spaces
      }
     stringstream ssline(line);
      while(getline(ssline, word, ' ')) {
        //checks for valid words and writes to outFile
        if(stopwords.find(word) != stopwords.end() || word.length() > 1 || (word.length() == 1 && isdigit(word[0])) )
          //CONTINUE
          //write to file
      }
      cout << line <<endl;
      cout <<endl;
    }
*/

vector<string> vec, vec2;
string str = "Hi-me-youi second third'fourth   fifth!   manoto+";
cout << str << endl;

    replaceHyphensWithSpaces(str);
    splitLine(str, vec);
    removePunctuation(vec, vec2);
    removeWhiteSpaces(vec2);
    removeEmptyWords(vec2);
    removeSingleLetterWords(vec2);
cout << "punctuations, whitespaces, empty, single:" << endl;
for(auto p : vec2)
  cout << p << endl;
cout << endl;


}

void fillDictionary(std::ifstream &newInFile,
                    std::unordered_map<std::string, std::pair<long, long>> &dict) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 20
}


void fillStopWords(std::ifstream &inFile,
                   std::unordered_set<std::string> &stopwords) {
  
  // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    for(string word; getline(inFile, word); ){
      stopwords.insert(word);
    }
}

void rateReviews(std::ifstream &testFile,
                 std::unordered_map<std::string, std::pair<long, long>> &dict,
                 std::ofstream &ratingsFile) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 20
}

void removeEmptyWords(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    for (vector<string>::iterator it= tokens.begin(); it != tokens.end();) {
      if( (*it).length() == 0) {
        it = tokens.erase(it);
      } else {
      ++it;
      }
    }
}

void removePunctuation(std::vector<std::string> &inTokens,
                       std::vector<std::string> &outTokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 10
    string punc = ".,?!:;-_'\"\n\t\v"; //string containing all chars that should be removed
    for(string word: inTokens ) {
      string newWord = "";
      for(int i = 0; i < word.length(); ++i) {
        if(punc.find(word[i]) == string::npos)
          newWord.push_back(word[i]);
      }
        outTokens.push_back(newWord);
    }
}

void removeSingleLetterWords(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    for (vector<string>::iterator it= tokens.begin(); it != tokens.end(); ++it) {
      if( (*it).length() == 1 && isalpha((*it)[0]) )
        tokens.erase(it);
    }    
}

void removeStopWords(std::vector<std::string> &tokens,
                     std::unordered_set<std::string> &stopwords) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    for (vector<string>::iterator it= tokens.begin(); it != tokens.end(); ++it) {
      if(stopwords.find(*it) != stopwords.end())
        tokens.erase(it);
    }   
}

void removeWhiteSpaces(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    // You may want to use the trim() method from the trim.*pp files in a2.
    for (string& word: tokens) {
      word = trim(word);
    }

}

void replaceHyphensWithSpaces(std::string &line) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    char punc = '-'; //string containing all chars that should be removed
      for(int i = 0; i < line.length(); ++i) {
        if(line[i]  == punc)
          line.replace(i, 1, " "); //replaces all unwanted chars with spaces
      }  
}

void splitLine(std::string &line, std::vector<std::string> &words) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 10
    string word;
    stringstream ssline(line);
    while(getline(ssline, word, ' ')) {
      words.push_back(word);
    }
}

