#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    FILE *filePtr;
    unsigned int codeLength=1;
    int smallest =150;
    int reverse,encodeLength,hold;
	int realc,realk=0;

    //check file and get length
    if((filePtr=fopen("test2.txt","r"))==NULL){
        puts("Couldnt find file.");
        exit(0);
    }
	
	fscanf(filePtr,"%d",&codeLength);
	
	while(codeLength!=0){
		
		int codeContent[codeLength];
		encodeLength= (codeLength-11)/6;
		int encodeContent[encodeLength];
		
		printf("%d",encodeLength);
		puts("");
		
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
		
		for(int u=1; u <=codeLength;u++){
			printf("%d ",codeContent[u-1]);
			if(u%10 ==0)
				puts("");
		}
		
		puts("");
		
		//check it whether is reverse or not
		if(codeContent[0]==0&&codeContent[1]==0&&codeContent[2]==1&&codeContent[3]==1&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==1&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==0&&codeContent[codeLength-5]==0){
			puts("normal");
		}else if(codeContent[0]==0&&codeContent[1]==1&&codeContent[2]==1&&codeContent[3]==0&&codeContent[4]==0&&codeContent[codeLength-1]==0&&codeContent[codeLength-2]==0&&codeContent[codeLength-3]==1&&codeContent[codeLength-4]==1&&codeContent[codeLength-5]==0){
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
		
		for(int u=1; u <=codeLength;u++){
			printf("%d ",codeContent[u-1]);
			if(u%10 ==0)
				puts("");
		}
		
		puts("");
		printf("testpoint");
		puts("");
		
		for(int y=1; y<encodeLength-2;y++){
			if(codeContent[6*y]==1){//1XXXX
				if(codeContent[6*y+1]==1){//11000
					//printf("5");
					encodeContent[y-1]=5;
				}else if(codeContent[6*y+2]==1){//10100
					//printf("3");
					encodeContent[y-1]=3;
				}else if(codeContent[6*y+3]==1){//10010
					//printf("1");
					encodeContent[y-1]=1;
				}else if(codeContent[6*y+4]==1){//10001
					//printf("8");
					encodeContent[y-1]=8;
				}else{//10000
					//printf("0");
					encodeContent[y-1]=0;
				}
			}else{//0XXXX
				if(codeContent[6*y+1]==0){//00XXX
					if(codeContent[6*y+2]==0){//000XX
						if(codeContent[6*y+3]==0){//0000X
							//printf("9");
							encodeContent[y-1]=9;
						}else{//0001X
							//printf("2");
							encodeContent[y-1]=2;
						}
					}else{//001XX
						if(codeContent[6*y+3]==1){//0011X
							printf("bad code(start code wrong place)");
							exit(0);
						}else if(codeContent[6*y+4]==1){//00
							//printf("6");
							encodeContent[y-1]=6;
						}else{
							//printf("-");
							encodeContent[y-1]=10;
						}
					}
				}else if(codeContent[6*y+2]==1){
					//printf("4");
					encodeContent[y-1]=4;
				}else{
					//printf("7");
					encodeContent[y-1]=7;
				}
			}
		}
		for(int w=encodeLength-1; w<=encodeLength; w++){
			if(codeContent[6*w]==1){//1XXXX
				if(codeContent[6*w+1]==1){//11000
					if(w==encodeLength){
						encodeContent[w-1]=5;
					}else{
						encodeContent[w-2]=5;
					}
				}else if(codeContent[6*w+2]==1){//10100
					if(w==encodeLength){
						encodeContent[w-1]=3;
					}else{
						encodeContent[w-2]=3;
					}
				}else if(codeContent[6*w+3]==1){//10010
					if(w==encodeLength){
						encodeContent[w-1]=1;
					}else{
						encodeContent[w-2]=1;
					}
				}else if(codeContent[6*w+4]==1){//10001
					if(w==encodeLength){
						encodeContent[w-1]=8;
					}else{
						encodeContent[w-2]=8;
					}
				}else{//10000
					if(w==encodeLength){
						encodeContent[w-1]=0;
					}else{
						encodeContent[w-2]=0;
					}
				}
			}else{//0XXXX
				if(codeContent[6*w+1]==0){//00XXX
					if(codeContent[6*w+2]==0){//000XX
						if(codeContent[6*w+3]==0){//0000X
							if(w==encodeLength){
								encodeContent[w-1]=9;
							}else{
								encodeContent[w-2]=9;
							}
						}else{//0001X
							if(w==encodeLength){
								encodeContent[w-1]=2;
							}else{
								encodeContent[w-2]=2;
							}
						}
					}else{//001XX
						if(codeContent[6*w+3]==1){//0011X
							printf("bad code(start code wrong place)");
							exit(0);
						}else if(codeContent[6*w+4]==1){//00
							if(w==encodeLength){
								encodeContent[w-1]=6;
							}else{
								encodeContent[w-2]=6;
							}
						}else{
							if(w==encodeLength){
								encodeContent[w-1]=10;
							}else{
								encodeContent[w-2]=10;
							}
						}
					}
				}else if(codeContent[6*w+2]==1){
					if(w==encodeLength){
						encodeContent[w-1]=4;
					}else{
						encodeContent[w-2]=4;
					}
				}else{
					if(w==encodeLength){
						encodeContent[w-1]=7;
					}else{
						encodeContent[w-2]=7;
					}
				}
			}
		}
		
		puts("");
		
		for(int q=1; q<=encodeLength; q++){
			realc+=((encodeLength-q)%10+1)*encodeContent[q-1];
			realc%=11;
		}
		
		for(int r=0; r<encodeLength-2; r++){
			if(encodeContent[r]!=10){
				printf("%d",encodeContent[r]);
			}else{
				printf("-");
			}
		}
		printf("c=%d",realc);
		fscanf(filePtr,"%d",&codeLength);
		
	}
	system("pause");
}
