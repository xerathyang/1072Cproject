#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
	
	char fileName[60];
	FILE *pTest,*pAns;
	unsigned int testNum,testBase,hold,counter1,counter2,testLength=0;

	printf("%s","Enter the test file name you want(NOT included .txt): ");
	scanf("%s",&fileName);
	printf("%s","\nEnter the test number you need: ");
	scanf("%d",&testLength);
	
	pTest= fopen((strcat(fileName,".txt")),"w+");
	pAns= fopen((strcat(fileName,"Ans.txt")),"w+");
	
	srand((unsigned)time(NULL));
	
	void changeLine(){
		counter1++;
		counter2++;
		if(counter1%10==0){
			fprintf(pTest,"%c",'\n');
		}else{
			fprintf(pTest,"%c",'\0');
		}
	}
	
	for(int x=1; x<=testLength; x++){
		
		counter1=0;
		testNum=rand()%150+1;
		testBase=rand()%100+1;
		
		fprintf(pTest,"%d",testNum);
		fprintf(pTest,"%c",'\n');
	
		for(int y=1; y<=testNum; y++){
			hold= rand()%11;
			switch(hold){
				case 0:
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				case 1:
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				case 2:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					break;
				case 3:
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				case 4:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				case 5:
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				case 6:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					break;
				case 7:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					break;
				case 8:
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					break;
				case 9:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					break;
				case 10:
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase*2);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					fprintf(pTest,"%d",testBase);
					changeLine();
					break;
				default:
					puts("wrong");
					system("pause");
					exit(0);
			}
			
		}
	
	}
	
	fclose(pTest);
	fclose(pAns);
	
}