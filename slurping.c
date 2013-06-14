#include <stdio.h>
#include <stdlib.h>

unsigned char* slurp_file1(unsigned char *filename){
	FILE * fp;
	unsigned char* result = NULL;
	long size,csize;
	fp = fopen (filename,"r");
	if (fp==NULL) 
		perror ("Error opening file");
	else{
    		fseek (fp, 0, SEEK_END);
    		size = ftell (fp);
    		result = (unsigned char*)malloc(size*sizeof(char));
		rewind(fp);	
  		if (result == NULL)
			perror("Error when allocating memory");
  		csize = fread (result,1,size,fp);
  		if (csize != size) 
			perror("Error when copying from the file");
		fclose(fp);
		return result;
  	}
}

unsigned char* slurp_file2(unsigned char* filename){
	FILE * fp;
	unsigned char* result = (unsigned char*)malloc(1*sizeof(char));
	long size=1,csize=0,psize=0;
	int c;
	fp = fopen (filename,"r");
	if (fp==NULL) 
		perror ("Error opening file");
	else{
		while((c=fgetc(fp)) != EOF){
			csize++;
			if(csize>psize){
				result = (unsigned char*)realloc(result,size*sizeof(char));
				psize += size;
				size*=2;
			}
			result[csize-1] = (char)c;
			printf("%s\n",result);			
		}
		result[csize] = '\0';
		return result;
	}
}
