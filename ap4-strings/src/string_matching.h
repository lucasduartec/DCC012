
#ifndef StringMaching_h__
#define StringMaching_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int validateInput(int optionRange);

string lerArquivo(const string &nomeArquivo);

std::vector<int> StringMatching(string text, string pattern, int metodo);

void StringMatching(int metodo);

std::vector<int> NaiveStringMatcher(std::string text, std::string pattern);

std::vector<int> KMPStrMatcher(std::string text, std::string pattern);

std::vector<int> BoyerMooreStrMatcher(std::string text, std::string pattern);

std::vector<int> RabinKarpStrMatcher(std::string text, std::string pattern);

#endif