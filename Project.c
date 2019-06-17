#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *filePtr;
    unsigned int codeLength,count=1;
    int smallest =150;
    int encodeLength,hold,i,x,y,z;
    unsigned int badcode,realc,realk,errpos=0;
    int codeContent[200]={0};
    int encodeContent[34]={0};
	char fileName[50];

	printf("%s","Enter the file name(included .txt):");
	scanf("%s",fileName);

    //check file and get file pointer
    if((filePtr=fopen(fileName,"r"))==NULL){
        puts("Couldnt find file.");
		system("pause");
        exit(0);
    }

	//get length
	fscanf(filePtr,"%d",&codeLength);

	//detect length to decide continue
	while(codeLength!=0){

		puts("");
		printf("Case %d: ",count);
		count++;
		badcode=0;
		smallest=150;

		//get content
		for( i=0; i <codeLength;i++){
			fscanf(filePtr,"%d",&codeContent[i]);
		}

		//find smallest
		for( x=0; x <codeLength;x++){
			if(codeContent[x]==0){
				badcode=1;
				break;
			}
			if(codeContent[x]<smallest)
				smallest= codeContent[x];
		}
		//convert content to binary and look for wrong content
		for( i=0; i<codeLength; i++){
			if(badcode==1)
				break;
			if((float)codeContent[i]/smallest<2.2105263157894736842105263157895&&(float)codeContent[i]/smallest>1.8095238095238095238095238095238){
				codeContent[i]=(int)round((float)codeContent[i]/smallest)-1;
			}else if((float)codeContent[i]/smallest<1.1052631578947368421052631578947&&(float)codeContent[i]/smallest>0.9047619047619047619047619047619){
				codeContent[i]=(int)round((float)codeContent[i]/smallest)-1;
			}else{
				badcode=1;
				errpos=i;
				break;
			}
		}
		
		if(badcode==1){
			printf("bad code(code content has wrong: %d)\n",errpos);
			fscanf(filePtr,"%d",&codeLength);
			if(codeLength==0)
				break;
			continue;
		}
		
		//check code length
		if((codeLength-11)%6==0){
			encodeLength= (codeLength-11)/6;
		}else{
			puts("bad code(wrong code length)");
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}

		//check the start code and whether it is reverse or not
		if(codeContent[0]==0&&codeContent[1]==0&&codeContent[2]==1&&codeContent[3]==1&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==1&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==0&&codeContent[codeLength-5]==0){

		}else if(codeContent[0]==0&&codeContent[1]==1&&codeContent[2]==1&&codeContent[3]==0&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==0&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==1&&codeContent[codeLength-5]==0){
			for( z=0;z<=codeLength/2;z++){
				hold=codeContent[z];
				codeContent[z]=codeContent[codeLength-z-1];
				codeContent[codeLength-z-1]=hold;
			}
		}else{
			puts("bad code(start code lost)");
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}

		//for test
		//puts("");
		//for( i=0; i<codeLength; i++){
		//	printf("%d ",codeContent[i]);
		//	if((i+1)%10==0)
		//		puts("");
		//}

		//detect code and decode
		for( y=0; y<encodeLength;y++){
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
			//00001
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==0&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==1){
				encodeContent[y]=9;
			//00100
			}else if(codeContent[6*(y+1)]==0&&codeContent[6*(y+1)+1]==0&&codeContent[6*(y+1)+2]==1&&codeContent[6*(y+1)+3]==0&&codeContent[6*(y+1)+4]==0){
				encodeContent[y]=10;
			}else{
				//make sure c and k has number to compare
				if(y==encodeLength-2||y==encodeLength-1){
					encodeContent[y]=11;
				}else{
					puts("bad code(encoding code not find)");
					fscanf(filePtr,"%d",&codeLength);
					continue;
				}
			}
		}

		//C Check
		realc=0;
		for( i=1; i<=encodeLength-2; i++){
			realc+=((encodeLength-2-i)%10+1)*encodeContent[i-1];
		}
		realc=realc%11;
		//printf("%d",realc);
		if(realc!=encodeContent[encodeLength-2]){
			puts("bad C");
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}

		//K Check
		realk=0;
		for( i=1; i<=encodeLength-1;i++){
			realk+=((encodeLength-1-i)%9+1)*encodeContent[i-1];
		}
		realk=realk%11;
		//printf("%d",realk);
		if(realk!=encodeContent[encodeLength-1]){
			puts("bad K");
			fscanf(filePtr,"%d",&codeLength);
			continue;
		}

		//print the encode content
		for( r=0; r<encodeLength-2; r++){
			if(encodeContent[r]!=10){
				printf("%d",encodeContent[r]);
			}else{
				printf("-");
			}
		}

		puts("");
		fscanf(filePtr,"%d",&codeLength);
	}
	fclose(filePtr);
	system("pause");
}
