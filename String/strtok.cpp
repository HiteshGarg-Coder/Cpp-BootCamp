#include<bits/stdc++.h>
using namespace std;

char *mystrtok(char str[], char delim)
{
	static char* input = NULL;
	if(str != NULL)
	{
		input = str;
	}
	
	if(input == NULL)
	{
		return NULL;
	}
	
	char * output = new char[strlen(input) +1];
	int i = 0;
	
	for(i = 0;input[i] != '\0';i++)
	{
		if(input[i] != delim)
		{
			//Do some work
			output[i] = input[i];
		}
		else
		{
			//at delim
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}
	
	//Return last word even if delim isnot there
	output[i] = '\0';
	input = NULL;
	return output;
}

int main()
{
	char str[] = "Hi I am Hitesh";
	char *ptr;
	ptr = mystrtok(str,' ');
	cout<<ptr<<endl;
	
	while(ptr != NULL)
	{
		ptr = mystrtok(NULL,' ');
	    cout<<ptr<<endl;
	}
	
	
}
