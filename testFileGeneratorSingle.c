#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(){
	
	
	srand((unsigned)time(NULL));
	
	FILE *pTest,*pAns;
	char fileName[60];
	char ans[150];
	unsigned int testNum,testBase,hold,counter,realc,realk,testLength,badtest,badcode=0;
	
	void changeLine(){
		counter++;
		if(counter%10==0){
			fprintf(pTest,"%c",'\n');
		}else{
			fprintf(pTest,"%s"," ");
		}
	}
	
	printf("%s","Enter the test file name you want(NOT included .txt): ");
	scanf("%s",&fileName);
	printf("%s","\nEnter the test number you need: ");
	scanf("%d",&testLength);
	printf("%s","\nDo you need random wrong in code? 1/0 for yes/no.\n");
	scanf("%d",&badtest);
	
	if(badtest!=0){
		badcode=rand()%
	}
	
	pTest= fopen((strcat(fileName,".txt")),"w+");
	pAns= fopen((strcat(fileName,"Ans.txt")),"w+");
	
	
	for(int x=0; x<testLength; x++){
		counter=0;
		testNum=rand()%21+1;
		testBase=rand()%100+1;
		
		fprintf(pTest,"%d",(testNum+2)*6+11);
		fprintf(pTest,"%c",'\n');
	
		fprintf(pTest,"%d",testBase);
		changeLine();
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
	
		for(int y=0; y<testNum; y++){
			hold= rand()%11;
			ans[y]=hold;
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
			}
		
			fprintf(pTest,"%d",testBase);
			changeLine();
		}
	
		realc=0;
		for(int i=1; i<=testNum; i++){
			realc+=((testNum-i)%10+1)*ans[i-1];
		}
		realc%=11;
	
		ans[testNum]=realc;
	
		realk=0;
		for(int i=1; i<=testNum+1;i++){
			realk+=((testNum-i+1)%9+1)*ans[i-1];
		}
		realk=realk%11;

		switch(realc){
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
		}
	
		fprintf(pTest,"%d",testBase);
		changeLine();
	
		switch(realk){
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
		}
	
	
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
		fprintf(pTest,"%d",testBase);
	
		fprintf(pTest,"%c",'\n');
		fprintf(pTest,"%c",'\n');
		
		switch(badcode){
			
		}
	
		for(int x=0; x<testNum; x++){
			if(ans[x]==10){
				fprintf(pAns,"%s","-");
			}else{
				fprintf(pAns,"%d",ans[x]);
			}
		}
		fprintf(pAns," %d %d\n",realc,realk);
	}
	fprintf(pTest,"%d",0);
	fclose(pTest);
	fclose(pAns);
	system("pause");
}