#include <iostream>
#include "LexEngine.h"
#include "SymbolTable.h"
#include <fstream>
#include "KeywordsRepository.h"

using namespace std;


void main() {
	LexEngine lex;


	string output;
	string buffer;

	ifstream MyReadFile("C:/Users/Kenway/Desktop/input.txt");
	while (getline(MyReadFile, output)) {
		buffer += output;
	}

	lex.runAnalysis(buffer);
	
	MyReadFile.close();

	system("pause");
}


//#include<conio.h>
//#include<windows.h>
//
//
//void setColor(int color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}

/*string str = "";

	for (;;) {
		char ch;
		ch = _getch();
		cout << ch;
		str += ch;
		if (ch == ' ') str = "";
		if (str == "while") {
			cout << "\nI detected 'while' keyword but here i cant change color\n";
			str = "";
		}
		if (str == "for") {
			cout << "\nI detected 'for' keyword but here i cant change color\n";
			str = "";
		}
		if (str == "int") {
			cout << "\nI detected 'int' keyword but here i cant change color\n";
			str = "";
		}
	}

	system("pause");*/