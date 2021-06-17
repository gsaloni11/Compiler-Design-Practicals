#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){
    char keywords[37][10] =
    {"auto","break","case","char","const","continue","cout","cin","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","main","namespace","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","using","void","volatile","while"};
    int i, flag = 0;

    for(i = 0; i < 37; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
	vector<char> resO;
	vector<string> resI;
	vector<string> resK;
	ifstream fin("code.txt");
	int i,j=0;
	
	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
	
	while(!fin.eof()){
   		ch = fin.get();
   		
		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				resO.push_back(ch);
   		}
   		
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(isKeyword(buffer) == 1)
   					resK.push_back(buffer);
   				else
   					resI.push_back(buffer);
   		}
   		
	}
	
	fin.close();
	cout<<"Operator: ";
	for(int i=0;i<resO.size();i++)
	{
		cout<<resO[i]<<", ";
	}
	cout<<"\n";
	cout<<"Keywords: ";
	for(int i=0;i<resK.size();i++)
	{
		cout<<resK[i]<<", ";
	}
	cout<<"\n";
	cout<<"Identifiers: ";
	for(int i=0;i<resI.size();i++)
	{
		cout<<resI[i]<<", ";
	}
	
	return 0;
}
