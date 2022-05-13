#include <iostream>
#include <conio.h>
// #include "./hfiles/xyz.h"

using namespace std;
//    .\a.exe in powershell to run
int main() {
	srand(time(NULL));
	cout << "multiplying, enter a number\n";
	int numA;
	cin >> numA;
	cout << "enter another number\n";
	int numB;
	cin >> numB;
	cout << "product = " << numA * numB << "\n";

	cout << "\nProgram is finished.\n";
	getchar();
	getchar();
	return 0;
}