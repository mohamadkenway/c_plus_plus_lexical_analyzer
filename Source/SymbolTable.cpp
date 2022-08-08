#include "SymbolTable.h"





void SymbolTable::insertToTable(string word, string token,string address, string type) {

	// 'first' defined in the class

	SymbolsLinkedList* newSymbol = new SymbolsLinkedList;
	SymbolsLinkedList* iterator = new SymbolsLinkedList;

	newSymbol->data = { {"word", word},{"token", token},{"address", address},{"type", type} };
	

	if (first == NULL) {
		first = newSymbol;
		return;
	}
	else {
		iterator = first;

		while (iterator->next != NULL)
			iterator = iterator -> next;

		iterator -> next = newSymbol;

		
	}

}




void SymbolTable::printTable() {

	SymbolsLinkedList* iterator = new SymbolsLinkedList;
	iterator = first;
	if (first == NULL) {
		cout << "\n\n ------------Table is empty------------ \n\n";
		return;
	}
	if (iterator->next == NULL) {
		
		cout << '\t' << "word" << " : " << iterator->data["word"];
		cout << '\t' << "token" << " : " << iterator->data["token"];
		cout << '\t' << "address" << " : " << iterator->data["address"];
		cout << '\t' << "type" << " : " << iterator->data["type"];
		cout << endl << "---------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

		return;
	}
	while (iterator->next != NULL) {
		cout << '\t' << "word" << " : " << iterator->data["word"];
		cout << '\t' << "token" << " : " << iterator->data["token"];
		cout << '\t' << "address" << " : " << iterator->data["address"];
		cout << '\t' << "type" << " : " << iterator->data["type"];
		cout << endl << "---------------------------------------------------------------------------------------------------------" << endl;
		iterator = iterator->next;
	}
	cout << '\t' << "word" << " : " << iterator->data["word"];
	cout << '\t' << "token" << " : " << iterator->data["token"];
	cout << '\t' << "address" << " : " << iterator->data["address"];
	cout << '\t' << "type" << " : " << iterator->data["type"];
	cout << endl << "---------------------------------------------------------------------------------------------------------"<<endl;
}