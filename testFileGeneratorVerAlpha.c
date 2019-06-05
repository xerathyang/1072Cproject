#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	FILE *pFile;
	pFile= fopen("test.txt","w");
	
	srand((unsigned)time(NULL));
	
	unsigned int testNum,testBase,hold,counter=0;
	
	void changeLine(){
		counter++;
		if(counter%10==0){
			sprintf(pFile,'\n');
		}else{
			sprintf(pFile,'\0');
		}
	}
	
	for(int x=1; x<=10; x++){
		
		counter=0;	
		testNum=rand()%150+1;
		testBase=rand()%100+1;
		
		sprintf(pFile,"%d",testNum);
		sprintf(pFile,'\n');
	
		for(int y=0; y<testNum; y++){
			hold= rand()%11;
			switch(hold){
				case 0:
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				case 1:
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				case 2:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					break;
				case 3:
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				case 4:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				case 5:
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				case 6:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					break;
				case 7:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					break;
				case 8:
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					break;
				case 9:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					break;
				case 10:
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase*2);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					sprintf(pFile,"%d",testBase);
					changeLine();
					break;
				default:
					puts("wrong");
			}
			
		}
	
	}
	
	fclose(pFile);
	
}