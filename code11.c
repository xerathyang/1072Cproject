#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    FILE *filePtr;
    unsigned int codeLength,count=1;
    int smallest =150;
    int reverse,encodeLength,hold,badcode;
	int realc,realk=0;
	int codeContent[200];
	int encodeContent[34];

    //check file and get length
    if((filePtr=fopen("test1.txt","r"))==NULL){
        puts("Couldnt find file.");
		system("pause");
        exit(0);
    }
	
	fscanf(filePtr,"%d",&codeLength);
	
	while(codeLength!=0){
		
		encodeLength= (codeLength-11)/6;
		
		printf("Case %d: ",count);
		
		//get content
		for(int i=0; i <codeLength;i++){
			fscanf(filePtr,"%d",&codeContent[i]);
		}

		//find smallest and convert content to binary
		for(int x=0; x <codeLength;x++){
			if(codeContent[x]<smallest)
				smallest= codeContent[x];
        codeContent[x]=(int)round((float)codeContent[x]/smallest)-1;
		}
		
		//check it whether is reverse or not
		if(codeContent[0]==0&&codeContent[1]==0&&codeContent[2]==1&&codeContent[3]==1&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==1&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==0&&codeContent[codeLength-5]==0){
			
		}else if(codeContent[0]==0&&codeContent[1]==1&&codeContent[2]==1&&codeContent[3]==0&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==0&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==1&&codeContent[codeLength-5]==0){
			for(int z=0;z<=codeLength/2;z++){
				hold=codeContent[z];
				codeContent[z]=codeContent[codeLength-z-1];
				codeContent[codeLength-z-1]=hold;
			}
		}else{
			badcode=1;
		}
		
		//for test
		//puts("");
		//for(int i=0; i<codeLength; i++){
		//	printf("%d ",codeContent[i]);
		//	if((i+1)%10==0)
		//		puts("");
		//}
		
		for(int y=0; y<encodeLength;y++){
			//10000
			if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=0;
			//10010
			}else if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==1&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=1;
			//00011
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==1&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=2;
			//10100
			}else if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==1&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=3;
			//01100
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==1&&codeContent[6*(y+1)+2]==1&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=4;
			//11000
			}else if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==1&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=5;
			//00101
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==1&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=6;
			//01001
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==1&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=7;
			//10001
			}else if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=8;
			//10001
			}else if(codeContent[6*(y+1)]==1&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=9;
			//00110
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==1&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=10;
			}else{
				badcode=2;
			}
			
		}
		
		if(badcode==1){
			puts("badcode(start code lost)");
			system("pause");
			continue;
		}else if(badcode==2){
			puts("bad code(encoding code not find)");
			system("pause");
			continue;
		}
		
		
		for(int r=0; r<encodeLength-2; r++){
			if(encodeContent[r]!=10){
				printf("%d",encodeContent[r]);
			}else{
				printf("-");
			}
		}
		
		puts("");
		
		//C Check
		realc=0;
		for(int i=1; i<=encodeLength-2; i++){
			realc+=((encodeLength-2-i)%10+1)*encodeContent[i-1];
		}
		realc=realc%11;
		if(realc!=encodeContent[encodeLength-2]){
			puts("bad C");
			continue;
		}
		
		//K Check
		realk=0;
		for(int i=1; i<=encodeLength-1;i++){
			realk+=((encodeLength-1-i)%9+1)*encodeContent[i-1];
		}
		realk=realk%9;
		if(realk!=encodeContent[encodeLength-1]){
			puts("bad K");
			continue;
		}
		fscanf(filePtr,"%d",&codeLength);
		count++;
		puts("");
	}
	fclose(filePtr);
	system("pause");
}
