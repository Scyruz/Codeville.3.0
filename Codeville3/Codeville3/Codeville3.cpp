#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

fstream file;
float score[100];
float scoreBe[100];
string token[100];


int i = 0;
int n = 0;


int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;
	if (*x > * y)
		return -1;
	else if (*x < *y)
		return 1;
	return 0;
}

bool validateFile() {

	file.open("Results.txt");
	return 1;
}

void readFile() {

	string line;
	string cs[100] = {};


	while (getline(file, line))
	{
		cs[i] = line;

		i++;
		n++;
	}

	file.close();

	string s[100];
	string delimiter;

	for (int i = 0; i < n; i++) {
		s[i] = cs[i];
		delimiter = " ";
		token[i] = s[i].substr(0, s[i].find(delimiter));
		s[i].erase(0, s[i].find(delimiter));
		score[i] = stof(s[i]);
	}
}

void sortList() {

	for (i = 0; i < n; i++)
	{
		scoreBe[i] = score[i];
	}

	const int num = n;
	qsort(score, num, sizeof(int), compare);
}

void selectWinners() {
	cout << "Winners:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (score[i] == scoreBe[j]) {
				cout << i + 1 << " - " << token[j] << endl;
			}
		}
	}
}

int main()
{
	if (validateFile()) {
		readFile();
		sortList();
		selectWinners();
	}
	else {
		cout << "File error";
	}	
}


