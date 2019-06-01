#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	FILE *filePtr;
	unsigned int codeLength,encodeLength,count=1;
	unsigned int smallest=150;
	unsigned int realc,realk,badcode,hold=0;
	char codeContent[602];
	int encodeContent[34]={0};
	char rowdef[1]={'\n'};
	char rowcheck='1';
	
	if((filePtr=fopen("test1.txt","r"))==NULL){
		puts("Couldnt find file.");
		system("pause");
        exit(0);
	}
	puts("1");
	while(rowcheck!='\n'){
		rowcheck=getc(filePtr);
		printf("%c",rowcheck);
		system("pause");
	}
	puts("complete");
}