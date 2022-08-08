#include "KeywordsRepository.h"
#include "TokenRepository.h"
#include <string>
#include "SymbolTable.h"


ReservedKeywordsRepository::ReservedKeywordsRepository() {
	TokenRepository tokenRepository;
	insertToRepository("while",to_string(tokenRepository.T_while));
	insertToRepository("for",to_string(tokenRepository.T_for));
	insertToRepository("int",to_string(tokenRepository.T_int));
	insertToRepository("double",to_string(tokenRepository.T_double));
	insertToRepository("float",to_string(tokenRepository.T_float));
	insertToRepository("bool",to_string(tokenRepository.T_bool));
	insertToRepository("void",to_string(tokenRepository.T_void));
	insertToRepository("main",to_string(tokenRepository.T_main));
	insertToRepository("then",to_string(tokenRepository.T_then));
	insertToRepository("char",to_string(tokenRepository.T_char));
}




void ReservedKeywordsRepository::insertToRepository(string keyword,string token) {

	KeywordsLinkedList* newKeyword = new KeywordsLinkedList;
	KeywordsLinkedList* iterator = new KeywordsLinkedList;


	newKeyword->data = { {"token", token},{"keyword", keyword } };

	

	if (first == NULL) {
		first = newKeyword;
		return;
	}
	else {
		iterator = first;

		while (iterator->next != NULL)
			iterator = iterator->next;

		iterator->next = newKeyword;


	}

}


string ReservedKeywordsRepository::checkKeywordIsExistInRepository(string keyword) {
	
	KeywordsLinkedList* iterator = new KeywordsLinkedList;
	iterator = first;
	map<string, string>::iterator itr;
	
	string token ;

	if (first == NULL) {
		cout << "\n\n ------------Keyword Repository is empty------------ \n\n";
		return "0";
	}


	if (iterator->next == NULL) {

		if (iterator->data["keyword"] == keyword) {
			token = iterator->data["token"];
			return token;
		}

		return "0";
	}
	while (iterator->next != NULL) {
		if (iterator->data["keyword"] == keyword) {
			token = iterator->data["token"];
			return token;
		}
		iterator = iterator->next;
	}

	if (iterator->data["keyword"] == keyword) {
		token = iterator->data["token"];
		return token;
	}
	return "0";
}
