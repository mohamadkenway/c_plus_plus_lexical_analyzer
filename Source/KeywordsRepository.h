#include<iostream>
#include<map>
using namespace std;


class KeywordsLinkedList {
public:
	map<string, string> data;
	KeywordsLinkedList* next;
};


#pragma once
class ReservedKeywordsRepository
{
public:
	KeywordsLinkedList* first = NULL;
	
	ReservedKeywordsRepository();

	void insertToRepository(string keyword,string token);

	string checkKeywordIsExistInRepository(string keyword);
};

