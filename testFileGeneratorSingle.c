#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	
	srand((unsigned)time(NULL));
	
	unsigned int testNum,testBase,hold,counter,realc,realk,need=0;
	unsigned int ans[2000]={0};
	
	void changeLine(){
		counter++;
		if(counter%10==0){
			printf("%c",'\n');
		}else{
			printf("%c",'\0');
		}
	}
	
	scanf("%d",&need);
	
	
for(int x=0; x<need; x++){
	
	
	counter=0;
	testNum=rand()%23+1;
	testBase=rand()%100+1;
		
	printf("%d",(testNum+2)*6+11);
	printf("%c",'\n');
	
	printf("%d",testBase);
	changeLine();
	printf("%d",testBase);
	changeLine();
	printf("%d",testBase*2);
	changeLine();
	printf("%d",testBase*2);
	changeLine();
	printf("%d",testBase);
	changeLine();
	
	printf("%d",testBase);
	changeLine();
	
	for(int y=0; y<testNum; y++){
		hold= rand()%11;
		ans[y]=hold;
		switch(hold){
			case 0:
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			case 1:
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			case 2:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				break;
			case 3:
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			case 4:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			case 5:
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			case 6:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				break;
			case 7:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				break;
			case 8:
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				break;
			case 9:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				break;
			case 10:
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase*2);
				changeLine();
				printf("%d",testBase);
				changeLine();
				printf("%d",testBase);
				changeLine();
				break;
			default:
				puts("wrong");
		}
		
		printf("%d",testBase);
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
	realk=realk%9;

	switch(realc){
		case 0:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 1:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 2:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 3:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 4:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 5:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 6:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 7:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 8:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 9:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 10:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		default:
			puts("wrong");
	}
	
	printf("%d",testBase);
	changeLine();
	
	switch(realk){
		case 0:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 1:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 2:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 3:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 4:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 5:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		case 6:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 7:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 8:
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 9:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			break;
		case 10:
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase*2);
			changeLine();
			printf("%d",testBase);
			changeLine();
			printf("%d",testBase);
			changeLine();
			break;
		default:
			puts("wrong");
	}
	
	
	printf("%d",testBase);
	changeLine();	
	
	printf("%d",testBase);
	changeLine();
	printf("%d",testBase);
	changeLine();
	printf("%d",testBase*2);
	changeLine();
	printf("%d",testBase*2);
	changeLine();
	printf("%d",testBase);
	
	puts("");
	puts("");
	
	for(int x=0; x<testNum; x++){
		if(ans[x]==10){
			printf("%s","-");
		}else{
			printf("%d",ans[x]);
		}
	}
	printf(" %d %d",realc,realk);
	
	puts("");
	puts("");
}
system("pause");
}