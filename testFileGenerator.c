#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	FILE *pFile;
	pFile= fopen("test.txt","w");
	
	srand((unsigned)time(NULL));
	
	unsigned int testNum,testBase,hold,counter1,counter2=0;
	char testContent[2000];
	
	void changeLine(){
		counter1++;
		counter2++;
		if(counter1%10==0){
			snprintf(testContent,1,"%c",'\n');
		}else{
			snprintf(testContent,1,"%c",'\0');
		}
	}
	
	for(int x=1; x<=10; x++){
		
		counter1=0;
		testNum=rand()%150+1;
		testBase=rand()%100+1;
		
		snprintf(testContent,sizeof(testNum),"%d",testNum);
		snprintf(testContent,1,"%c",'\n');
	
		for(int y=0; y<testNum; y++){
			hold= rand()%11;
			switch(hold){
				case 0:
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				case 1:
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				case 2:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					break;
				case 3:
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				case 4:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				case 5:
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				case 6:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					break;
				case 7:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					break;
				case 8:
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					break;
				case 9:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					break;
				case 10:
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase*2);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					snprintf(testContent,3,"%d",testBase);
					changeLine();
					break;
				default:
					puts("wrong");
					system("pause");
					exit(0);
			}
			
		}
	
	}
	fwrite(testContent,1,sizeof(testContent),pFile);
	
	fclose(pFile);
	
}