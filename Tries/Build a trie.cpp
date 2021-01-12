// Tries
#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
	char ch;
	bool isTerminal;
	unordered_map<char,node*> h;
	
	node(char c){
		ch = c;
		isTerminal = false;
	}
};

class Trie{
public:
	node* root;
	Trie(){
		root = new node('\0');
	}

	void addWord(char *word){
		node * temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->h.count(ch) == 0){
				// Node does not exists
				temp->h[ch] = new node(ch);
				temp = temp->h[ch];
			}
			else{
				// Node exists
				temp = temp->h[ch];
			}
		}
		temp->isTerminal = true;
	}

	bool searchWord(char *word){
		node* temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->h.count(ch) == 0){
				return false;
			}
			else{
				temp = temp->h[ch];
			}
		}
		return temp->isTerminal;
	}
};


int main(){
	
	Trie t;
	t.addWord("Hell");
	t.addWord("Hello");
	t.addWord("Code");
	t.addWord("Coding");

	while(1){
		char word[100];
		cin>>word;

		if(t.searchWord(word)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}


	cout<<endl;
	return 0;
}
