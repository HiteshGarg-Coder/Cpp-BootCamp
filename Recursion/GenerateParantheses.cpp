// GenerateParantheses
#include <iostream>
using namespace std;

void GenerateParantheses(int n,int i,char* a,int open,int close){
	if(i == 2*n){
		a[i] = '\0';
		cout<<a<<endl;
		return;
	}

	if(open<n){
		// Add '('
		a[i] = '(';
		GenerateParantheses(n,i+1,a,open+1,close);
	}
	if(close<open){
		a[i] = ')';
		GenerateParantheses(n,i+1,a,open,close+1);
	}

}

int main(){
	int n;
	cin>>n;
	char a[100];
	GenerateParantheses(n,0,a,0,0);


	cout<<endl;
	return 0;
}
