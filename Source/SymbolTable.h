#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class SymbolsLinkedList {
public:
	map<string, string> data;
	SymbolsLinkedList* next;
};


#pragma once
class SymbolTable
{
public:

	SymbolsLinkedList* first = NULL;

	void insertToTable(string word, string token,string address, string type);

	void printTable();
	
};


