#include<iostream>
#include<cstring>
using namespace std;

char *myStrtok(char *str,char delimeter){
	static char*input=NULL;
	if(str!=NULL){
		//first call
		input=str;
	}
	//check here-basecase after the final token has been returned
	if(input==NULL){
		return NULL;
	}

	//start extracting tokens and store them in a array

	char *output=new char[strlen(input)+1];
	int i=0;
	for(;input[i]!='\0';i++){
		if(input[i]!=delimeter){
			output[i]=input[i];
		}

		else{
			output[i]='\0';
			input=input+i+1;
			return output;
		}
	}

	output[i]='\0';
	input=NULL;

	return output;
}

int main(){

char s[100]="Today is a rainy day";
char *ptr =myStrtok(s,' ');
cout<<ptr<<endl;

while(ptr!=NULL){
	ptr=myStrtok(NULL,' ');
	cout<<ptr<<endl;
}

return 0;
}