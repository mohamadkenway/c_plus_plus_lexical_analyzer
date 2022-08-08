#include "LexEngine.h"
#include <regex>
#include<string> 
#include "SymbolTable.h"
#include "TokenRepository.h"
#include "KeywordsRepository.h"
using namespace std;


struct Utility {
	int startPointer = 0;
	int endPointer = 0;
	int line = 0; // yet not implemented line counter  
	string temp = "";
};

Utility util;
SymbolTable symbolTable;
TokenRepository tokenRepository;
ReservedKeywordsRepository keywordsRepository;



void LexEngine::runAnalysis(string buffer) {
	

	for (int i = 0; i < buffer.size(); i++) {
		//cout << buffer[i] << endl;
		
		if (buffer[i] == ' ') { util.startPointer++; util.endPointer++; continue; } // skip space

		util.temp += buffer[i];

		
		
		if (regex_match(util.temp, regex("[a-zA-Z]+"))) {

			//detect start place
			if(i != 0)
			if (buffer[i - 1] == ' ' || buffer[i - 1] == '+' || buffer[i - 1] == '-' ||
				buffer[i - 1] == '*' || buffer[i - 1] == '/' || buffer[i - 1] == '[' ||
				buffer[i - 1] == ']' || buffer[i - 1] == '{' || buffer[i - 1] == '}' ||
				buffer[i - 1] == '(' || buffer[i - 1] == ')' || buffer[i - 1] == '=' ||
				buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {
				if (util.startPointer == 0) util.startPointer = 1;
				else util.startPointer = i;
			}

			if (buffer[i + 1] == ' ' || buffer[i + 1] == '+' || buffer[i + 1] == '-' ||
				buffer[i + 1] == '*' || buffer[i + 1] == '/' || buffer[i + 1] == '[' ||
				buffer[i + 1] == ']' || buffer[i + 1] == '{' || buffer[i + 1] == '}' ||
				buffer[i + 1] == '(' || buffer[i + 1] == ')' || buffer[i + 1] == '=' ||
				buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {

				util.endPointer = i;

				if (keywordsRepository.checkKeywordIsExistInRepository(util.temp) == "0") {
					symbolTable.insertToTable(
						util.temp,
						to_string(tokenRepository.T_identifier),
						"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
						""
					);
				}

				else if (keywordsRepository.checkKeywordIsExistInRepository(util.temp) != "0") {
					symbolTable.insertToTable(
						util.temp,
						keywordsRepository.checkKeywordIsExistInRepository(util.temp),
						"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
						""
					);
				}

				

				util.startPointer = util.endPointer = i + 1;

				util.temp = "";
				continue; // continue make COMPILER fast because not checking other conditions
			}
			else {
				continue;
			}
		}


		// int constant
		if (regex_match(util.temp, regex("[0-9]+"))) {

			//detect start place
			if (i != 0)
				if (buffer[i - 1] == ' ' || buffer[i - 1] == '+' || buffer[i - 1] == '-' ||
					buffer[i - 1] == '*' || buffer[i - 1] == '/' || buffer[i - 1] == '[' ||
					buffer[i - 1] == ']' || buffer[i - 1] == '{' || buffer[i - 1] == '}' ||
					buffer[i - 1] == '(' || buffer[i - 1] == ')' || buffer[i - 1] == '=' ||
					buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {
					if (util.startPointer == 0) util.startPointer = 1;
					else util.startPointer = i;
				}

			if (buffer[i + 1] == ' ' || buffer[i + 1] == '+' || buffer[i + 1] == '-' ||
				buffer[i + 1] == '*' || buffer[i + 1] == '/' || buffer[i + 1] == '[' ||
				buffer[i + 1] == ']' || buffer[i + 1] == '{' || buffer[i + 1] == '}' ||
				buffer[i + 1] == '(' || buffer[i + 1] == ')' || buffer[i + 1] == '=' ||
				buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {

				util.endPointer = i;
				symbolTable.insertToTable(
					util.temp,
					to_string(tokenRepository.T_intConstant),
					"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
					""
				);


				util.startPointer = util.endPointer = i + 1;

				util.temp = "";
				continue; // continue make COMPILER fast because not checking other conditions
			}
			else {
				continue;
			}
		}

		// double constant
		if (regex_match(to_string(buffer[i - 1]), regex("[0-9]+")) && regex_match(to_string(buffer[i + 1]), regex("[0-9]+")) && buffer[i] == '.') {
			continue;
		}
		if (regex_match(util.temp, regex("[0-9]+(\\.[0-9]+)"))) {

			//detect start place
			if (i != 0)
				if (buffer[i - 1] == ' ' || buffer[i - 1] == '+' || buffer[i - 1] == '-' ||
					buffer[i - 1] == '*' || buffer[i - 1] == '/' || buffer[i - 1] == '[' ||
					buffer[i - 1] == ']' || buffer[i - 1] == '{' || buffer[i - 1] == '}' ||
					buffer[i - 1] == '(' || buffer[i - 1] == ')' || buffer[i - 1] == '=' ||
					buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {
					if (util.startPointer == 0) util.startPointer = 1;
					else util.startPointer = i;
				}

			if (buffer[i + 1] == ' ' || buffer[i + 1] == '+' || buffer[i + 1] == '-' ||
				buffer[i + 1] == '*' || buffer[i + 1] == '/' || buffer[i + 1] == '[' ||
				buffer[i + 1] == ']' || buffer[i + 1] == '{' || buffer[i + 1] == '}' ||
				buffer[i + 1] == '(' || buffer[i + 1] == ')' || buffer[i + 1] == '=' ||
				buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {

				util.endPointer = i;
				symbolTable.insertToTable(
					util.temp,
					to_string(tokenRepository.T_doubleConstant),
					"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
					""
				);


				util.startPointer = util.endPointer = i + 1;

				util.temp = "";
				continue; // continue make COMPILER fast because not checking other conditions
			}
			else {
				continue;
			}
		}


		// power constant
		if (regex_match(to_string(buffer[i - 1]), regex("[0-9]+")) && regex_match(to_string(buffer[i + 1]), regex("[0-9]+")) &&
			(buffer[i] == 'E' || buffer[i] == 'e')) {
			continue; //
		}
		if (regex_match(util.temp, regex("[0-9]+(\\e[0-9]+)")) || regex_match(util.temp, regex("[0-9]+(\\E[0-9]+)"))) {

			//detect start place
			if (i != 0)
				if (buffer[i - 1] == ' ' || buffer[i - 1] == '+' || buffer[i - 1] == '-' ||
					buffer[i - 1] == '*' || buffer[i - 1] == '/' || buffer[i - 1] == '[' ||
					buffer[i - 1] == ']' || buffer[i - 1] == '{' || buffer[i - 1] == '}' ||
					buffer[i - 1] == '(' || buffer[i - 1] == ')' || buffer[i - 1] == '=' ||
					buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {
					if (util.startPointer == 0) util.startPointer = 1;
					else util.startPointer = i;
				}

			if (buffer[i + 1] == ' ' || buffer[i + 1] == '+' || buffer[i + 1] == '-' ||
				buffer[i + 1] == '*' || buffer[i + 1] == '/' || buffer[i + 1] == '[' ||
				buffer[i + 1] == ']' || buffer[i + 1] == '{' || buffer[i + 1] == '}' ||
				buffer[i + 1] == '(' || buffer[i + 1] == ')' || buffer[i + 1] == '=' ||
				buffer[i + 1] == ';' || buffer[i + 1] == '<' || buffer[i + 1] == '>') {

				util.endPointer = i;
				symbolTable.insertToTable(
					util.temp,
					to_string(tokenRepository.T_powerConstant),
					"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
					""
				);


				util.startPointer = util.endPointer = i + 1;

				util.temp = "";
				continue; // continue make COMPILER fast because not checking other conditions
			}
			else {
				continue;
			}
		}



		if (buffer[i] == ';') {
			symbolTable.insertToTable(
				";",
				to_string(tokenRepository.T_semicolon),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}
		
		if (buffer[i] == '{') {
			symbolTable.insertToTable(
				"{",
				to_string(tokenRepository.T_open_brace),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '}') {
			symbolTable.insertToTable(
				"}",
				to_string(tokenRepository.T_close_brace),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '(') {
			symbolTable.insertToTable(
				"(",
				to_string(tokenRepository.T_open_paran),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == ')') {
			symbolTable.insertToTable(
				")",
				to_string(tokenRepository.T_close_paran),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}
		
		if (buffer[i] == '<') {
			symbolTable.insertToTable(
				"<",
				to_string(tokenRepository.T_smaller),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '>') {
			symbolTable.insertToTable(
				">",
				to_string(tokenRepository.T_larger),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '*') {
			symbolTable.insertToTable(
				"*",
				to_string(tokenRepository.T_multiplication),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '/') {
			symbolTable.insertToTable(
				"/",
				to_string(tokenRepository.T_division),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == '[') {
			symbolTable.insertToTable(
				"[",
				to_string(tokenRepository.T_open_bracket),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		if (buffer[i] == ']') {
			symbolTable.insertToTable(
				"]",
				to_string(tokenRepository.T_close_bracket),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		// ++
		if (buffer[i] == '+' && buffer[i + 1] == '+') {
			symbolTable.insertToTable(
				"++",
				to_string(tokenRepository.T_plus_plus),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer += 2;
			util.endPointer += 2;
			util.temp = "";
			continue;
		}
		// +
		if (buffer[i] == '+' && buffer[i-1] != '+') {
			symbolTable.insertToTable(
				"+",
				to_string(tokenRepository.T_plus),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}

		// ==
		if (buffer[i] == '=' && buffer[i + 1] == '=') {
			symbolTable.insertToTable(
				"==",
				to_string(tokenRepository.T_equal_equal),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer += 2;
			util.endPointer += 2;
			util.temp = "";
			continue;
		}
		// =
		if (buffer[i] == '=' && buffer[i - 1] != '=') {
			symbolTable.insertToTable(
				"=",
				to_string(tokenRepository.T_equal),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}


		// --
		if (buffer[i] == '-' && buffer[i + 1] == '-') {
			symbolTable.insertToTable(
				"--",
				to_string(tokenRepository.T_minus_minus),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer += 2;
			util.endPointer += 2;
			util.temp = "";
			continue;
		}
		// -
		if (buffer[i] == '-' && buffer[i - 1] != '-') {
			symbolTable.insertToTable(
				"-",
				to_string(tokenRepository.T_minus),
				"start : " + to_string(util.startPointer) + " " + "end : " + to_string(util.endPointer),
				""
			);
			util.startPointer++;
			util.endPointer++;
			util.temp = "";
			continue;
		}


	}

	symbolTable.printTable();

	
}