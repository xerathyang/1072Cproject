#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


int main(){
	
	
	srand((unsigned)time(NULL));
	
	FILE *pTest,*pAns;
	char fileName[60];
	char ans[150];
	unsigned int testNum,testBase,hold,counter,realc,realk,testLength,badtest,badcode,contentMis=0;
	
	void changeLine(){
		counter++;
		if(counter%10==0){
			fprintf(pTest,"%c",'\n');
		}else{
			fprintf(pTest,"%s"," ");
		}
	}
	
	int baseFloat(int testBase, int multi){
		switch(rand()%11){
			case 0:
				return testBase*multi;
				break;
			case 1:
				if((int)round((float)testBase*1.01*multi)>testBase*2*1.05){
					return testBase*2*1.05;
					break;
				}
				return (int)((float)testBase*1.01*multi);
				break;
			case 2:
				if((int)round((float)testBase*1.02*multi)>testBase*2*1.05){
					return testBase*2*1.05;
					break;
				}
				return (int)((float)testBase*1.02*multi);
				break;
			case 3:
				if((int)round((float)testBase*1.03*multi)>testBase*2*1.05){
					return testBase*2*1.05;
					break;
				}
				return (int)((float)testBase*1.03*multi);
				break;
			case 4:
				if((int)round((float)testBase*1.04*multi)>testBase*2*1.05){
					return testBase*2*1.05;
					break;
				}
				return (int)((float)testBase*1.04*multi);
				break;
			case 5:
				if((int)round((float)testBase*1.05*multi)>testBase*2*1.05){
					return testBase*2*1.05;
					break;
				}
				return (int)((float)testBase*1.05*multi);
				break;
			case 6:
				return (int)ceil((float)testBase*0.99*multi);
				break;
			case 7:
				return (int)ceil((float)testBase*0.98*multi);
				break;
			case 8:
				return (int)ceil((float)testBase*0.97*multi);
				break;
			case 9:
				return (int)ceil((float)testBase*0.96*multi);
				break;
			case 10:
				return (int)ceil((float)testBase*0.95*multi);
				break;
		}
	}
	
	printf("%s","Enter the test file name you want(NOT included .txt): ");
	scanf("%s",&fileName);
	printf("%s","\nEnter the test number you need: ");
	scanf("%d",&testLength);
	printf("%s","\nDo you need random wrong in code? 1/0 for yes/no: ");
	scanf("%d",&badtest);
	
	
	
	pTest= fopen((strcat(fileName,".txt")),"w+");
	pAns= fopen((strcat(fileName,"Ans.txt")),"w+");
	
	
	for(int x=0; x<testLength; x++){
		
		if(badtest!=0){
			badcode=rand()%6+1;
		}
		
		counter=0;
		testNum=rand()%21+1;
		testBase=rand()%100+1;
		
		if(badcode==1)
			contentMis=rand()%testNum;
		
		if(badcode==2){
			fprintf(pTest,"%d\n",(testNum+2)*6+12);
			fprintf(pTest,"%d",testBase);
			changeLine();
		}else{
			fprintf(pTest,"%d\n",(testNum+2)*6+11);
		}
		
		//fprintf(pTest,"%c",'\n');
	
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,2));
		changeLine();
		
		if(badcode==3){
			fprintf(pTest,"%d",baseFloat(testBase,1));
		}else{
			fprintf(pTest,"%d",baseFloat(testBase,2));
		}
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
	
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
	
		for(int y=0; y<testNum; y++){
			hold= rand()%11;
			ans[y]=hold;
			
			if(contentMis==y&&badcode==1){
				fprintf(pTest,"%d",0);
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				continue;
			}
			
			switch(hold){
				case 0:
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				case 1:
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				case 2:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					break;
				case 3:
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				case 4:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				case 5:
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				case 6:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					break;
				case 7:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					break;
				case 8:
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					break;
				case 9:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					break;
				case 10:
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,2));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					fprintf(pTest,"%d",baseFloat(testBase,1));
					changeLine();
					break;
				default:
					puts("wrong");
			}
		
			fprintf(pTest,"%d",baseFloat(testBase,1));
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
		
		if(badcode==5){
			while(realc==ans[testNum]){
				realc=rand()%11;
			}
		}else if(badcode==6){
			hold=realk;
			while(realk==hold){
				realk=rand()%11;
			}
		}

		switch(realc){
			case 0:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 1:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 2:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 3:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 4:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 5:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 6:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 7:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 8:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 9:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 10:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			default:
				puts("wrong");
		}
	
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
	
		switch(realk){
			case 0:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 1:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 2:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 3:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 4:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 5:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			case 6:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 7:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 8:
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 9:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				break;
			case 10:
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,2));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				fprintf(pTest,"%d",baseFloat(testBase,1));
				changeLine();
				break;
			default:
				puts("wrong");
				system("pause");
		}
	
	
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();	
	
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,1));
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,2));
		changeLine();
		if(badcode==4){
			fprintf(pTest,"%d",baseFloat(testBase,1));
		}else{
			fprintf(pTest,"%d",baseFloat(testBase,2));
		}
		changeLine();
		fprintf(pTest,"%d",baseFloat(testBase,1));
	
		fprintf(pTest,"%c",'\n');
		fprintf(pTest,"%c",'\n');
		
		fprintf(pAns,"%s%d%s","Case ",x+1,": ");
		
		if(badcode!=0){
			fprintf(pAns,"%s%d\n","badcode: ",badcode);
		}else{
			for(int x=0; x<testNum; x++){
				if(ans[x]==10){
					fprintf(pAns,"%s","-");
				}else{
					fprintf(pAns,"%d",ans[x]);
				}
			}
			fprintf(pAns," %d %d %d\n",realc,realk,testBase);
		}
	
		
	}
	fprintf(pTest,"%d",0);
	fprintf(pAns,"%s","1: content, 2: length, 3&4: startcode,\n5: bad C, 6: bad K");
	fclose(pTest);
	fclose(pAns);
	system("pause");
}