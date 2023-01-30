#include <iostream>
#include<string>
#include <fstream>
#include<stack>
#include<vector>
using namespace std;
const string EQUAL_TO = "=";
const string SEMICOLON = ";";
const string COMMA = ",";
bool isSemicolon(string pTok){
	if (pTok == SEMICOLON)
		return true;
	else
		return false;
}
bool isSpecialChar(char pTok){
	bool check = false;
	vector<char> specialChar = { '~', '!', '@', '#', '%', '^', '&', '*', '<', '>', '?', '`', '.', ',', ':', '"' };
	for (auto c : specialChar){
		if (c == pTok){
			check = true;
			break;
		}
	}
	return check;
}

bool isSelection(string ptok){
	if (ptok == "if" || ptok == "else")
	{
		return true;
	}
	return false;
}
bool isLoop(string ptok){
	if (ptok == "while" || ptok == "do")
	{
		return true;
	}
	return false;
}
bool isSBO(string ptok){
	if (ptok == "(")
	{
		return true;
	}
	return false;
}

bool isSBC(string ptok){
	if (ptok == ")")
	{
		return true;
	}
	return false;
}

bool isCBO(string ptok){
	if (ptok == "{")
	{
		return true;
	}
	return false;
}
bool isCBC(string ptok){
	if (ptok == "}")
	{
		return true;
	}
	return false;
}



bool isOperator(string pTok)
{
	if (pTok == "+" || pTok == "-" || pTok == "/" || pTok == "%" || pTok == "++" || pTok == "--" || pTok == "/=" || pTok == "=" || pTok == "-=" || pTok == "==" || pTok == ">=" || pTok == "<=" || pTok == ">" || pTok == "<")
	{
		return true;
	}
	return false;
}
bool isDataType(string pTok){
	vector<string> dataTypes{ "double", "int", "long", "char", "char*", "float", "void", "bool" };
	for (int i = 0; i < dataTypes.size(); i++)
	{
		if (pTok == dataTypes[i])
		{
			return true;
		}
	}
	return false;
}
bool isKeyWord(string pTok)
{
	vector<string> keywords{ "auto", "struct", "break", "else", "long",
		"switch", "case", "enum", "register", "typedef",
		"extern", "return", "union", "const", "short",
		"unsigned", "continue", "for", "signed", "default",
		"goto", "sizeof", "voltile", "do", "if", "static", "while", "class", "false", "true"
};
	for (int i = 0; i < keywords.size(); i++)
	{
		if (pTok == keywords[i])
		{
			return true;
		}
	}
	return false;
}
bool isDigit(string pTok) {

	for (auto x : pTok) {
		if (x >= 48 && x <= 57)
			return true;
		else
		{
			return false;
			break;
		}
	}
	return false;
}
bool isDigit(char pTok) {
	return pTok >= 48 && pTok <= 57;
}
bool isAlpha(string pTok){
	for (auto x : pTok) {
		if (x >= 65 && x <= 90 || x >= 97 && x <= 122)
			return true;
	}
	return false;
}
bool isAlpha(char pTok){
	return pTok >= 65 && pTok <= 90 || pTok >= 97 && pTok <= 122;
}
bool isConstant(string pTok)
{
	int i = 0;
	while (i < pTok.length())
	{
		if (isdigit(pTok[i]))
		{
			if (i == pTok.length() - 1)
			{
				return true;
			}
		}
		i++;
	}
	return false;
}
bool isIdentifier(string pTok){
	if (pTok[0] == '$' || pTok[0] == '_' || isAlpha(pTok[0])){
		for (int i = 0; i < pTok.length(); i++){
			string temp(1, pTok[i]);
			if (isSpecialChar(pTok[i]) || isOperator(temp)){
				return false;
			}
			else if (i == pTok.length()){
				return true;
			}
		}
		return true;
	}
	return false;
}
void writeToFile(string fileName){
	ofstream file;
	file.open(fileName, ios::out);
	if (file.is_open()){
		
		//file << "int a ;";
		//file << "int a = 5 ;";
		//file << "int a ;\n";
		file << "if ( x <= y ) { dsgsdb }\n";
		file << "else { hello }\n";
		file << "else if ( x == y ) { }\n";
		file << "do { shehroz ashraf khan } while ( x <= 10 )\n";
		file << "while ( r <= z ) { shehroz ashraf khan }\n";
	    file << "if ( x <= y ) { shehroz ashraf khan }";
		/*file << "int a ;\n";
		file << "int a = 5 ;\n";
		file << "bool var = 10 ;\n";
		file << "if ( x <= y ) { dsgsdb }\n";
		file << "else { hello }\n";
		file << "else if ( x == y ) { }\n";
		file << "do { shehroz ashraf khan } while ( x <= 10 )\n";
		file << "while ( r <= z ) { khgdfihgfiuhsifunb }\n";
		file << "int sum = 50 ; ";*/


		file.close();
	}
	else{
		cout << "File is not opened!\n";
	}

}
string removeSpaces(string line){
	string line2 = "";
	int i = 0;
	if (line == "")
	{
		return "";
	}
	while (line[i] == ' ' || line[i] == '\t'){
		i++;

	}
	/*while (line[i] != ';' && i < line.length()){
	line2 += line[i];
	i++;
	}*/
	for (i; i < line.length(); i++)
	{
		line2 += line[i];
	}
	//line2 += line[i];
	return line2;
}
class Token {
	string mToken;
	bool mValid;
public:
	Token(){
		mToken = "";
		mValid = false;
	}
	Token(string pTok, bool pV){
		mToken = pTok;
		mValid = pV;
	}void setVal(string value)
	{
		mToken = value;
	}
	string getToken(){ return mToken; }
	bool isValid(){ return mValid; }
	void setValid(bool pV){ mValid = pV; }
};
vector<Token> tokenizeInstruction(string pIns) {
	vector<Token> tokens;
	string token = "";
	for (auto x : pIns)
	{
		if (x == ' ')
		{
			Token t = Token(token, false);
			tokens.push_back(t);
			token = "";
		}
		else {
			token = token + x;
		}
	}
	Token t = Token(token, false);
	tokens.push_back(t);
	return tokens;
}

class Node {
	string dataType, identifier, value,KeyWord1,identifier1,operator1;
	int lineNo;
	Node* reference;
public:
	Node* next;
	Node()
	{
		dataType = identifier = value = KeyWord1=identifier1=operator1= "";
		lineNo = 0;
		next = NULL;
		reference = NULL;
	}
	string Identifier1(){
		return identifier1;
	}
	string Keyword1(){
		return KeyWord1;
	}
	int getLine()
	{
		return lineNo;
	}
	string Identifier()
	{
		return identifier;
	}
	string Operator()
	{
		return operator1;
	}
	
	void setVal(string val)
	{
		value = val;
	}
	Node(string dat, string id, string val, int line, Node* ref)
	{
		dataType = dat;
		identifier = id;
		value = val;
		lineNo = line;
		reference = ref;
	}

	//for Selection Statement
	Node(string key, string id, string op, string id1, int line, Node* ref)
	{
		KeyWord1 = key;
		identifier = id;
		operator1 = op;
		identifier1 = id1;
		//value = val;
		lineNo = line;
		reference = ref;
	}

	void Print()
	{
		cout << dataType << "\t\t|" << identifier << "\t\t|" << value << "\t|" << lineNo << "\t|" << reference << endl;
	}

	void PrintSelection()
	{
		cout << KeyWord1 << "\t\t|" << identifier << "\t\t|" << operator1 << "\t\t|" << identifier1 << "\t\t|" << lineNo << "\t|" << reference << endl;
	}

};

class ST
{
	Node* head;
public:
	ST()
	{
		head = NULL;
	}

	void insertSelection(string key, string id, string op, string id1, int line, Node* ref)
	{
		Node* node = new Node(key, id, op,id1, line, ref);
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
	}

	void insert(string dat, string id, string val, int line, Node* ref)
	{
		Node* node = new Node(dat, id, val, line, ref);
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
	}
	bool search(string id)
	{

		if (head == NULL)
		{
			return false;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				if (temp->Identifier() == id)
				{
					return true;
				}
				temp = temp->next;
			}
			if (temp->Identifier() == id)
			{
				return true;
			}
			return false;
		}
	}
	bool searchUpdate(string id, string val)
	{
		if (head == NULL)
		{
			return false;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				if (temp->Identifier() == id)
				{
					temp->setVal(val);
					return true;
				}
				temp = temp->next;
			}
			if (temp->Identifier() == id)
			{
				temp->setVal(val);
				return true;
			}
			return false;
		}
	}
	void showTable()
	{
		cout << "dataType\tIdentifier\tvalue\tlineno\treference" << endl;
		Node* node = head;
		while (node != NULL)
		{
			node->Print();
			node = node->next;
		}
	}

	void showTableSelection()
	{
		cout << "Keyword\t\tIdentifier\tOperator\tIdentifier1\tlineno\treference" << endl;
		Node* node = head;
		while (node != NULL)
		{
			node->PrintSelection();
			node = node->next;
		}
	}

	Node* returnNode(string id)
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				if (temp->Identifier() == id)
				{
					return temp;

				}
				temp = temp->next;
			}
			if (temp->Identifier() == id)
			{
				return temp;
			}
			return 0;
		}
	}
};

class Semantic{
	vector<string> mInstruction;
	ST obj;
public:
	Semantic(){ mInstruction = {}; }
	Semantic(vector<string> pIns){ mInstruction = pIns; }
	void semanticAnalysis(){

		for (auto ins : mInstruction){
			if (isDeclaration(ins)){
				cout << "Declaration: " << ins << endl;

			}
			else if (isSelectionStatementELSE_IF(ins)){
				cout << "Selection statement ELSE_IF: " << ins << endl;
			}
			else if (isSelectionStatementIF(ins)){
				cout << "Selection statement IF: " << ins << endl;
			}
			else if (isSelectionStatementELSE(ins)){
				cout << "Selection statement ELSE: " << ins << endl;
			}

			else if (isWhileLoop(ins)){
				cout << "WHILE LOOP: " << ins << endl;
			}
			else if (isDoWhileLoop(ins)){
				cout << "DO WHILE LOOP: " << ins << endl;
			}
			else if (isDefinition(ins)){
				cout << "Definition: " << ins << endl;

			}
			else if (isDefinition_Declaration(ins)){
				cout << "Declaration_Definition: " << ins << endl;

			}
			else if (isManupulation(ins)){
				cout << "Manupulation: " << ins << endl;

			}

			else{
				cout << "Something else: " << ins << endl;

			}
		}
	}



	ST SymbolTable(vector<string>pInst)
	{
		int line = 1;
		for (auto x : pInst)
		{
			if (isDeclaration(x))
			{
				vector<Token>token = tokenizeInstruction(x);
				string dt = token[0].getToken();
				for (int i = 0; i < token.size(); i++)
				{
					if (i % 2 != 0)
					{
						if (!obj.search(token[i].getToken()))
						{
							obj.insert(dt, token[i].getToken(), "", line, NULL);
						}
					}
				}
				line++;
			}




	if (isSelectionStatementIF(x))
			{
		
				vector<Token>token = tokenizeInstruction(x);
				string key =token[0].getToken(),id="",op="",id1="";
				//obj.insertSelection(key, id, op, id1, line, NULL);
				for (int i = 0; i < token.size(); i++)
				{
					
				 		
						if (i == 2)
						{
							id = token[i].getToken();
						}

						else if (i==3)
						{
							op= token[i].getToken();
						}
						else if (i==4)
						{
							id1= token[i].getToken();
						}
					

				}
				obj.insertSelection(key, id, op, id1, line, NULL);
		
	}

    



	if (isSelectionStatementELSE_IF(x))
	{
		int dfa = 0;
		vector<Token>token = tokenizeInstruction(x);
		string key ="", key1 ="", id = "", op = "", id1 = "";
		//string key = token[0].getToken(), key1 = token[1].getToken(), id = "", op = "", id1 = "";
		for (auto x:token)
		{
			if (dfa==0&&x.getToken()=="else")
			{
				key =x.getToken();
				dfa = 1;
			}
			else if (dfa == 1 && x.getToken() == "if")
			{
				key1 = x.getToken();
				dfa = 2;
			}

		 	else if (dfa==2&&isIdentifier(x.getToken()))
			{
				dfa = 3;
				id = x.getToken();
			}

			else if (dfa == 3 && isOperator(x.getToken()))
			{
				dfa = 4;
				op = x.getToken();
			}


			else if (dfa==4&&isIdentifier(x.getToken()))
			{
				id1 = x.getToken();
			}


		}
		obj.insertSelection(key + " " + key1, id, op, id1, line, NULL);

	}



	if (isWhileLoop(x))
	{

		vector<Token>token = tokenizeInstruction(x);
		string key = token[0].getToken(), id = "", op = "", id1 = "";
		//obj.insertSelection(key, id, op, id1, line, NULL);
		for (int i = 0; i < token.size(); i++)
		{


			if (i == 2)
			{
				id = token[i].getToken();
			}

			else if (i == 3)
			{
				op = token[i].getToken();
			}
			else if (i == 4)
			{
				id1 = token[i].getToken();
			}


		}
		obj.insertSelection(key, id, op, id1, line, NULL);

	}




	//if (isDoWhileLoop(x))
	//{
	//	int dfa = 0;
	//	vector<Token>token = tokenizeInstruction(x);
	//	string key ="",key1="", id = "", op = "", id1 = "";
	//	//obj.insertSelection(key, id, op, id1, line, NULL);
	//	for (auto x : token)
	//	{
	//		if (dfa==0&&isLoop(x.getToken()))
	//		{
	//			dfa = 1;
	//			key = x.getToken();
	//		}
	//		else if (dfa==1&&isLoop(x.getToken()))
	//		{
	//			dfa = 2;
	//			key1 = x.getToken();
	//		}
	//		else if (dfa==2&&isIdentifier(x.getToken()))
	//		{
	//			dfa = 3;
	//			id = x.getToken();
	//		}
	//		else if (dfa==3&&isOperator(x.getToken()))
	//		{
	//			dfa = 4;
	//			op = x.getToken();
	//		}
	//		else if (dfa==4&&isIdentifier(x.getToken()))
	//		{
	//			id1 = x.getToken();
	//		}
	//	}
	//	obj.insertSelection(key+"-"+key1, id, op, id1, line, NULL);

	//}




			else if (isDefinition_Declaration(x))
			{
				vector<Token>token = tokenizeInstruction(x);
				string dt = token[0].getToken();
				string id, val;
				for (int i = 0; i < token.size(); i++)
				{
					if (i % 2 != 0)
					{
						if (isIdentifier(token[i].getToken()))
						{
							id = token[i].getToken();
						}
						else if (isDigit(token[i].getToken()))
						{
							val = token[i].getToken();
						}
					}
					if (token[i].getToken() == COMMA || token[i].getToken() == ";")
					{
						if (!obj.search(id))
						{
							obj.insert(dt, id, val, line, NULL);
						}
					}
				}
			}
			else if (isDefinition(x))
			{
				vector<Token>t = tokenizeInstruction(x);
				string id, val;
				for (int i = 0; i < t.size(); i++)
				{
					if (i % 2 == 0)
					{
						if (isIdentifier(t[i].getToken()))
						{
							id = t[i].getToken();
						}
						else if (isDigit(t[i].getToken()))
						{
							val = t[i].getToken();
						}
					}
					else
					{
						if (t[i].getToken() == COMMA || t[i].getToken() == ";")
						{
							Node* L = obj.returnNode(id);
							if (L != NULL)
							{
								obj.insert("", L->Identifier(), val, line, L);
							}
							else if (L == NULL)
							{
								cout << "Identifier is not declared::" << id << endl;
							}

						}
					}
				}
			}
			line++;
		}
		return obj;
	}





	bool isDeclaration(string pInst){
		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isDataType(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isIdentifier(x.getToken())) {
				DFA = 2;
			}
			else if (DFA == 2) {
				if (isSemicolon(x.getToken())) {
					DFA = 0;
					return true;
				}
				else if (x.getToken() == COMMA) {
					DFA = 4;
				}
				else {
					DFA = 0;
					return false;
				}
			}
			else if (DFA == 4 && isIdentifier(x.getToken())) {
				DFA = 2;
			}
			else {
				DFA = 0;
				return false;
			}
		}
		return false;
	}

	bool isSelectionStatementIF(string pInst){
		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		int dfa = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isSelection(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isSBO(x.getToken()))
			{
				DFA = 2;
			}
			else if (DFA == 2)
			{
				if (dfa == 0 && isIdentifier(x.getToken())
					|| isDigit(x.getToken()))
				{
					dfa = 1;
				}
				else if (dfa == 1 && isOperator(x.getToken()))
				{
					dfa = 2;
				}
				else if (dfa == 2 && isIdentifier(x.getToken())
					|| isDigit(x.getToken()))
				{
					DFA = 3;
					dfa = 0;
				}
				else
				{
					return false;
				}
			}
			else if (DFA == 3 && isSBC(x.getToken()))
			{
				DFA = 4;
			}
			else if (DFA == 4 && isCBO(x.getToken()))
			{
				DFA = 5;
			}
			else if (DFA == 5)
			{
				if (x.getToken() != "}")
				{
					continue;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}


	bool isSelectionStatementELSE(string pInst){
		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;

		for (auto x : mTokens) {
			if (DFA == 0 && isSelection(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isCBO(x.getToken()))
			{
				DFA = 2;

			}
			else if (DFA == 2){
				if (x.getToken() != "}")
				{
					continue;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}


	bool isSelectionStatementELSE_IF(string pInst){
		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isSelection(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isSelection(x.getToken())) {
				DFA = 2;
			}
			else if (DFA == 2 && isSBO(x.getToken()))
			{
				DFA = 3;
			}
			else if (DFA == 3 && isIdentifier(x.getToken()) || isDigit(x.getToken()))
			{
				DFA = 4;

			}
			else if (DFA == 4 && isOperator(x.getToken()))
			{
				DFA = 5;
			}
			else if (DFA == 5 && isDigit(x.getToken()) || isIdentifier(x.getToken()))
			{
				DFA = 6;
			}
			else if (DFA == 6 && isSBC(x.getToken()))
			{
				DFA = 7;


			}
			else if (DFA == 7 && isCBO(x.getToken()))
			{
				DFA = 8;
			}
			else if (DFA == 8)
			{
				if (x.getToken() != "}")
				{
					continue;
				}

				else {
					return true;
				}
			}

		}
		return false;
	}



	bool isWhileLoop(string st)
	{
		vector<Token>tok = tokenizeInstruction(st);
		int DFA = 0;
		int sDFA = 0;
		for (auto x : tok)
		{
			if (DFA == 0 && x.getToken() == "while")
			{
				DFA = 1;
			}
			else if (DFA == 1 && x.getToken() == "(")
			{
				DFA = 2;
			}
			else if (DFA == 2)
			{
				if (sDFA == 0 && isIdentifier(x.getToken()))
				{
					sDFA = 1;
				}
				else if (sDFA == 1 && isOperator(x.getToken()))
				{
					sDFA = 2;
				}
				else if (sDFA == 2 && isIdentifier(x.getToken()))
				{
					DFA = 3;
					sDFA = 0;
				}
				else
				{
					return false;
				}
			}
			else if (DFA == 3 && x.getToken() == ")")
			{
				DFA = 4;
			}
			else if (DFA == 4 && x.getToken() == "{")
			{
				DFA = 5;
			}
			else if (DFA == 5)
			{
				if (x.getToken() != "}")
				{
					continue;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}



	bool isDoWhileLoop(string pInst){
		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		int dfa = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isLoop(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isCBO(x.getToken()))
			{
				DFA = 2;
			}
			else if (DFA == 2)
			{
				if (x.getToken() != "}"){
					continue;
					DFA = 3;
				}
				else
				{
					return true;
				}

			}
			else if (DFA == 3 && isCBC(x.getToken()))
			{
				DFA = 4;
			}
			else if (DFA == 4 && isLoop(x.getToken()))
			{
				DFA = 5;
			}
			else if (DFA == 5 && isSBO(x.getToken()))
			{
				DFA = 6;
			}
			else if (DFA == 6)
			{
				if (dfa == 0 && isIdentifier(x.getToken()) || isDigit(x.getToken()) || isAlpha(x.getToken()))
				{
					dfa = 1;
				}
				else if (dfa == 1 && isOperator(x.getToken()))
				{
					dfa = 2;
				}
				else if (dfa == 2 && isIdentifier(x.getToken()) || isDigit(x.getToken()) || isAlpha(x.getToken()))
				{
					DFA = 7;
					dfa = 0;
				}

			}
			else if (DFA == 7 && isSBC(x.getToken()))
			{
				return true;
			}

		}
		return false;
	}

	bool isDefinition_Declaration(string pInst){

		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isDataType(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && isIdentifier(x.getToken())) {
				DFA = 2;
			}
			else if (DFA == 2 && x.getToken() == EQUAL_TO) {
				DFA = 3;
			}
			else if (DFA == 3 && (isConstant(x.getToken()) ||
				isIdentifier(x.getToken()))) {
				DFA = 4;
			}
			else if (DFA == 4) {
				if (isSemicolon(x.getToken())) {
					DFA = 5;
					return true;
				}
				else if (x.getToken() == COMMA) {
					DFA = 1;
				}
				else if (x.getToken() == EQUAL_TO) {
					DFA = 3;
				}
				else
					return false;
			}
			else {
				DFA = 0;
				return false;
			}
		}
		return false;
	}
	bool isDefinition(string pInst){

		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isIdentifier(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && x.getToken() == EQUAL_TO) {
				DFA = 2;
			}
			else if (DFA == 2 && (isIdentifier(x.getToken()) ||
				isConstant(x.getToken()))) {
				DFA = 3;
			}
			else if (DFA == 3) {
				if (isSemicolon(x.getToken())) {
					DFA = 4;
					return true;
				}
				else if (x.getToken() == COMMA) {
					DFA = 0;
				}
				else if (x.getToken() == EQUAL_TO) {
					DFA = 2;
				}
				else
					return false;
			}
			else {
				DFA = 0;
				return false;
			}
		}
		return false;
	}
	bool isManupulation(string pInst){

		vector<Token>mTokens = tokenizeInstruction(pInst);
		int DFA = 0;
		for (auto x : mTokens) {
			if (DFA == 0 && isIdentifier(x.getToken())) {
				DFA = 1;
			}
			else if (DFA == 1 && x.getToken() == EQUAL_TO) {
				DFA = 2;
			}
			else if (DFA == 2 && (isIdentifier(x.getToken()) ||
				isConstant(x.getToken()))) {
				DFA = 3;
			}
			else if (DFA == 3 && isOperator(x.getToken())) {
				DFA = 4;
			}
			else if (DFA == 4 && (isIdentifier(x.getToken()) ||
				isConstant(x.getToken()))) {
				DFA = 5;
			}
			else if (DFA == 5) {
				if (isSemicolon(x.getToken())) {
					DFA = 0;
					return true;
				}
				else if (isOperator(x.getToken())) {
					DFA = 4;
				}
				else {
					DFA = 0;
					return false;
				}
			}
			else {
				DFA = 0;
				return false;
			}
		}
		return false;

	}
};
class Lexer{
	vector<string> mInstructions;
public:
	Lexer(){
		mInstructions = {};

	}
	Lexer(vector<string> pInstructions){
		mInstructions = pInstructions;
	}
	bool validateToken(Token pTok){

		string tok = pTok.getToken();
		if (isDataType(tok)){
			cout << "Data Type: " << tok << endl;
			pTok.setValid(true);
			return true;
		}

		else if (isSBO(tok)){
			cout << "Small Bracket Open : " << tok << endl;
			pTok.setValid(true);
			return true;
		}

		else if (isLoop(tok)){
			cout << "Loop statement : " << tok << endl;
			pTok.setValid(true);
			return true;
		}


		else if (isSBC(tok)){
			cout << "Small Bracket Close : " << tok << endl;
			pTok.setValid(true);
			return true;
		}

		else if (isCBO(tok)){
			cout << "Curely Bracket Open : " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isCBC(tok)){
			cout << "Curely Bracket Close : " << tok << endl;
			pTok.setValid(true);
			return true;
		}


		else if (isOperator(tok)){
			cout << "Operator: " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isDigit(tok)){
			cout << "Digit: " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isSemicolon(tok)){
			cout << "Semicolon: " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isSelection(tok)){
			cout << "Selection : " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isIdentifier(tok)){
			cout << "Identifier: " << tok << endl;
			pTok.setValid(true);
			return true;
		}
		else if (isKeyWord(tok)){
			cout << "Keyword: " << tok << endl;
			pTok.setValid(true);
			return true;
		}

		else
			return false;
	}
	vector<string> lexicalAnalysis(){
		bool check = false;
		vector<string> lexResultIns;
		for (auto ins : mInstructions){
			vector<Token>tokens = tokenizeInstruction(ins);
			for (auto t : tokens){
				if (validateToken(t)){
					check = true;
				}
				else{
					check = false;
					break;
				}
			}
			if (check)
				lexResultIns.push_back(ins);
		}
		return lexResultIns;
	}
};

vector<string> removeComments(vector<string> pInstructions){
	vector<string> instructions;
	for (int i = 0; i < pInstructions.size(); i++){
		string inst = pInstructions[i];
		bool comment = false, multiComment = false;
		if (inst[0] == '/') {
			if (inst[1] == '/') {
				comment = true;
			}
			else if (inst[1] == '*')
			{
				/*


				*/
				multiComment = true;
				int size = inst.size();
				while (inst[size - 3] != '*' && inst[size - 2] != '/' && i < pInstructions.size())
				{
					i++;
					inst = pInstructions[i];
					size = inst.size();
				}
			}
		}
		if (!comment && !multiComment)
		{

			instructions.push_back(inst);
		}
	}
	return instructions;
}
vector<string> readFromFile(string fileName){
	vector<string> mInstruction;
	ifstream file;
	file.open(fileName, ios::in);
	if (file.is_open()){

		string line, newString;
		while (!file.eof()){
			getline(file, line);
			if (line.size() > 0){
				line = removeSpaces(line);
				mInstruction.push_back(line);
			}
		}
		file.close();

	}
	else{
		cout << "File is not opened for reading!\n";
	}
	mInstruction = removeComments(mInstruction);
	return mInstruction;
}

class TAC {
	Token operand1;
	Token operand2;
	Token op;
public:
	TAC(){	}
	TAC(Token oper1, Token oper2, Token opP)
	{
		operand1 = oper1;
		operand2 = oper2;
		op = opP;
	}
	void displayTAC()
	{
		cout << operand1.getToken() << " " << op.getToken() << " " << operand2.getToken();
	}

};
int Precedence(Token tok)
{
	if (tok.getToken() == "+" || tok.getToken() == "-")
	{
		return 1;
	}
	else if (tok.getToken() == "*" || tok.getToken() == "/")
	{
		return 2;
	}
	else if (tok.getToken() == "^")
	{
		return 3;
	}
	else if (tok.getToken() == "=")
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int Precedence1(string tok)
{
	if (tok == "+" || tok == "-")
	{
		return 1;
	}
	else if (tok == "*" || tok == "/")
	{
		return 2;
	}
	else if (tok == "^")
	{
		return 3;
	}
	else if (tok == "=")
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

string infixToPostfix(string infx)
{
	stack<string> st;
	vector<Token>mtokens = tokenizeInstruction(infx);
	string postfix = "";
	for (auto x : mtokens)
	{
		if (isIdentifier(x.getToken()))
		{
			postfix += x.getToken() + " ";
		}
		else if (x.getToken() == "(")
		{
			st.push(x.getToken());
		}
		else if (isOperator(x.getToken()))
		{
			while (!st.empty() && Precedence1(st.top()) >= Precedence1(x.getToken()))
			{
				postfix += st.top() + " ";
				st.pop();
			}
			st.push(x.getToken());
		}
		else if (x.getToken() == ")")
		{
			while (!st.empty() && st.top() != "(")
			{
				postfix += st.top() + " ";
				st.pop();
			}
			st.pop();
		}

	}
	return postfix;
}


Token retToken(string s, string s1, string op)
{
	Token res;
	string x = s + op + s1;
	res.setVal(x);
	return res;
}
vector<TAC> EXTRACTpostFix(string postfix)
{
	vector<Token> tokens = tokenizeInstruction(postfix);
	Token operand1 = tokens[0];
	Token operand2 = tokens[1];
	Token oper = tokens[2];
	stack<Token> st1;
	vector <TAC> list;

	for (auto x : tokens)
	{


		if (isIdentifier(x.getToken()))
		{
			st1.push(x);

		}
		else if (isOperator(x.getToken()))
		{
			Token a, b, c;
			Token res;
			a = st1.top();
			st1.pop();

			b = st1.top();
			st1.pop();
			TAC ob(b, a, x);
			res = retToken(b.getToken(), a.getToken(), x.getToken());
			st1.push(res);
			list.push_back(ob);
		}
	}
	return list;
}

int main() {
	//cout << "\a";
	//system("color 02");
	//string fileName = "newFile.txt";
	//writeToFile(fileName);
	//vector<string>instructions = readFromFile(fileName);
	//Lexer lex(instructions);
	//vector<string> lexResultIns = lex.lexicalAnalysis();
	//cout << "Lex Result Ins size: " << lexResultIns.size() << endl;
	//Semantic sem(lexResultIns);
	//sem.semanticAnalysis();
	//ST b = sem.SymbolTable(instructions);
	////b.showTable();
	//b.showTableSelection();

	//system("pause");
	vector<string>read;
	string fileName = "newFile.txt";
	writeToFile(fileName);
	//writeToFile("test.txt", "int a ;\na = 5 ;\nint b = 10 ;");
	read = readFromFile(fileName);
	Lexer lex(read);

	vector<string>resultLex;
	resultLex = lex.lexicalAnalysis();
	Semantic sem(resultLex);
	sem.semanticAnalysis();
	ST b = sem.SymbolTable(read);
	b.showTable();
	string test1 = infixToPostfix("( a * b + c - c )");

	cout << test1;
	cout << endl;
	vector<TAC>listTAC = EXTRACTpostFix(test1);
	cout << "\t\tTHREE ADDRESS CODE" << endl;
	for (auto x : listTAC)
	{
		x.displayTAC();
		cout << endl;
	}
	system("pause");
	return 0;

}