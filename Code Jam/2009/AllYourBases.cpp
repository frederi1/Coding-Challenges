#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>

using namespace std;


char input[100];

int value[256], valused;

int main() {
	int T;

	ifstream in("A-large-practice.in");

	ofstream out("output.txt");

	in >> T;

	for (int test = 1; test <= T;test++) {

		in >> input;

		for (char c = 'a'; c <= 'z'; c++) {
			value[c] = 0;
		}
		for (char c = '0'; c <= '9'; c++) {
			value[c] = 0;
		}
		
		valused = 0;
		
		for (int i = 0; i < strlen(input); i++) {
			if (value[input[i]] == 0) {
				value[input[i]] = ++valused;
			}
		}
		if (valused <= 1) {
			valused = 2;
		}
		long long ans = 0;

		for (int i = 0; i < strlen(input); i++) {
			long long tmp = value[input[i]];
			if (tmp == 1) {
			} else if (tmp == 2) {
				tmp = 0;
			} else {
				tmp--;
			}
			ans = ans*valused + tmp;
		}

		cout << "Case #" << test << ": "<< ans << endl;
		out << "Case #" << test << ": "<< ans << endl;
	}
	
	in.close();

	out.close();
}