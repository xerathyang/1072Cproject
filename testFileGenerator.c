#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	FILE *pFile;
	pFile= fopen("test.txt","w");
	
	srand((unsigned)time(NULL));
	
	unsigned int testNum,testBase,hold,counter=0;
	char testContent[600];
	
	void changeLine(){
		counter++;
		if(counter%10==0){
			snprintf(testContent,1,'\n');
		}else{
			snprintf(testContent,1,'\0');
		}
	}
	
	for(int x=1; x<=10; x++){
	
		testNum=rand()%150+1;
		testBase=rand()%100+1;
		
		sprintf(testContent,"%d",testNum);
		sprintf(testContent,'\n');
	
		for(int y=0; y<testNum; y++){
			hold= rand()%11;
			switch(hold){
				case 0:
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				case 1:
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				case 2:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					break;
				case 3:
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				case 4:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				case 5:
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				case 6:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					break;
				case 7:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					break;
				case 8:
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					break;
				case 9:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					break;
				case 10:
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase*2);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					sprintf(testContent,"%d",testBase);
					changeLine();
					break;
				default:
					puts("wrong");
			}
			
		}
	
	}
	
	fclose(pFile);
	
}