#include <stdio.h>
#include <math.h>

int main(){

    File *filePtr;

    if((filePtr=fopen("test1.txt","r"))==NULL){
        puts("0");
    }
    else{
        puts("1");
    }

}
