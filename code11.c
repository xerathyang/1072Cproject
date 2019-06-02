#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *filePtr;
    unsigned int codeLength,count=1;
    int smallest =150;
    int encodeLength,hold;
    unsigned int badcode,realc,realk,rowcounter=0;
    int codeContent[200];
    int encodeContent[34];
    char rowcheck1,rowcheck2;
	
	void ptrMove(FILE *pFile){
		//find next section
			for(int j=0,rowcheck1='1',rowcheck2='1';j<2;){
				rowcheck1=getc(pFile);
				if(rowcheck1=='\n'){
					j++;
				}
				rowcheck2=getc(pFile);
				if(rowcheck2=='\n'){
					break;
				}else{
					j=0;
					rowcheck2=rowcheck1;
				}
			}
	}

    //check file and get file pointer
    if((filePtr=fopen("badtest.txt","r"))==NULL){
        puts("Couldnt find file.");
		system("pause");
        exit(0);
    }
	
	//get length
	fscanf(filePtr,"%d",&codeLength);
	
	//detect length to decide continue
	while(codeLength!=0){
		
		printf("Case %d: ",count);
		count++;
		
		//check code length
		if((codeLength-11)%6==0){
			encodeLength= (codeLength-11)/6;
		}else{
			puts("bad code(wrong code length)");
			
			ptrMove(filePtr);
			
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}
		
		//get content
		for(int i=0; i <codeLength;i++){
			fscanf(filePtr,"%d",&codeContent[i]);
			//check content amount
			if(getc(filePtr)=='\n'){
				if(getc(filePtr)=='\n'){
					badcode=3;
					fseek(filePtr,-2,SEEK_CUR);
					break;
				}
				fseek(filePtr,-1,SEEK_CUR);
			}
			fseek(filePtr,-1,SEEK_CUR);
		}
		
		if(badcode==3){
			puts("bad code(content amounts wrong)");
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}

		//find smallest ,convert content to binary and look for wrong content
		for(int x=0; x <codeLength;x++){
			if(codeContent[x]==0){
				badcode=4;
				break;
			}
			if(codeContent[x]<smallest)
				smallest= codeContent[x];
			codeContent[x]=(int)round((float)codeContent[x]/smallest)-1;
		}
		
		for(int i=0; i<codeLength; i++){
			if(codeContent[i]!=0&&codeContent[i]!=1)
				badcode=4;
		}
		
		if(badcode==4){
			puts("badcode(code content has wrong)");
			
			ptrMove(filePtr);
			
			fscanf(filePtr,"%d",&codeLength);
			continue;
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
		
		//detect code and decode
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
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}else if(badcode==2){
			puts("bad code(encoding code not find)");
			system("pause");
			fscanf(filePtr,"%d",&codeLength);
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
			fscanf(filePtr,"%d",&codeLength);
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
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}
		//fscanf(filePtr,"%d",&codeLength);
		fscanf(filePtr,"%d",&codeLength);
		puts("");
	}
	fclose(filePtr);
	system("pause");
}