#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    FILE *filePtr;
    unsigned int codeLength=1;
    int smallest =150;
    int reverse,encodeLength,hold,count;

    //check file and get length
    if((filePtr=fopen("test2.txt","r"))==NULL){
        puts("Couldnt find file.");
        exit(0);
    }
	
	fscanf(filePtr,"%d",&codeLength);
	
	while(codeLength!=0){
		
		int codeContent[codeLength];
		encodeLength= (codeLength-23)/6;
		
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
		
		for(int u=0; u <codeLength;u++){
			printf("%d ",codeContent[u]);
			count++;
			if(count%10 ==0)
				puts("");
		}
		
		//check it whether is reverse or not
		if(codeContent[0]==0&&codeContent[1]==0&&codeContent[2]==1&&codeContent[3]==1&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==1&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==0&&codeContent[codeLength-5]==0){
			reverse=0;
		}else if(codeContent[0]==0&&codeContent[1]==1&&codeContent[2]==1&&codeContent[3]==0&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==0&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==1&&codeContent[codeLength-5]==0){
			reverse=1;
			puts("reverse");
			for(int z=0;z<=codeLength/2;z++){
				hold=codeContent[z];
				codeContent[z]=codeContent[codeLength-z-1];
				codeContent[codeLength-z-1]=hold;
			}
		}else{
			puts("bad code(start code lost)");
			system("pause");
		}
		puts("");
		
		for(int y=1; y<=encodeLength+2;y++){
			if(codeContent[5*y+2]==1){
				if(codeContent[5*y+3]==1){
					printf("5");
				}else if(codeContent[5*y+4]==1){
					printf("3");
				}else if(codeContent[5*y+5]==1){
					printf("1");
				}else if(codeContent[5*y+6]==1){
					printf("8");
				}else{
					printf("0");
				}
			}else{
				if(codeContent[5*y+3]==0){
					if(codeContent[5*y+4]==0){
						if(codeContent[5*y+5]==0){
							printf("9");
						}else{
							printf("2");
						}
					}else if(codeContent[5*y+5]==1){
						printf("S");
					}else if(codeContent[5*y+6]==1){
						printf("6");
					}else{
						printf("-");
					}
				}else if(codeContent[5*y+4]==1){
					printf("4");
				}else{
					printf("7");
				}
			}
				
		}
		
		fscanf(filePtr,"%d",&codeLength);
		
	}
	system("pause");
}
