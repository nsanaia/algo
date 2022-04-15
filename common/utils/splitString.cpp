#include <bits/stdc++.h>
using namespace std;

void split(string path, vector<string>& tokens) {
	istringstream ss(path);
	string token;
	
	while (getline(ss, token, '/'))
		tokens.push_back(token);
}