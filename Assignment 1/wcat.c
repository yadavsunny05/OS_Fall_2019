#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    int i;
    if(argc <1){
	return(0);}
    int BS = 4096;
    char buffer[BS];
    
    for (i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        exit(1);}

    while(fgets(buffer, BS, fp) != NULL){
	
        printf("%s",buffer);
    }

    fclose(fp);
    }

    return 0;
}
