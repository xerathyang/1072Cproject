#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	FILE *pFile;
	pFile= fopen("test.txt","w");
	
	seed = (unsigned)time(NULL);
	srand(seed);
	
	int testNum,testBase,hold=0;
	char testContent[600];
	
	for(int x=1; x<=10; x++){
	
		testNum=rand()%150+1;
		testBase=rand()%200+1;
		
		sprintf(testContent[0],"%d",testNum);
		sprintf(testContent[1],"\n");
	
		for(int y=2; y<testNum; y+=5){
			hold= rand()%11;
			switch(hold){
				case 0:
					sprintf(testContent[y],"%d",testBase*2);
					sprintf(testContent[y+1],"%d",);
			
			
		}
	
	}
	
	fclose(pFile);
	
}