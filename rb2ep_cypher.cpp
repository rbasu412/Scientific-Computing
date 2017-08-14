// Rukmini Basu
// rb2ep
// HW13
// Problem 1
// rb2ep_cypher.cpp
// An example of a Vernam cypher
//usage: cypher password input output

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  main(int argc, char *argv[]) {

  char *pw = argv[1];
  int pw_len = strlen(argv[1]);
  int inp_len, j;
  FILE *infile;
  FILE *outfile;
  int i = 0;
  
  if(argc < 4){
    printf("Error. Usage: cypher password input.txt output.txt");
    return -1;
  }
  
  infile = fopen(argv[2],"rb");
  if( infile == NULL){
    printf("Error opening file");
    return -1;
  }
  fseek(infile, 0, SEEK_END);
  inp_len = ftell(infile);
  fclose(infile);

  char message[inp_len];
  char encrypted[inp_len];

  infile = fopen(argv[2],"r");
  while(1){
    char c = (char) fgetc(infile);
    if(feof(infile)) break; //If we've hit the end of file, quit reading
    message[i] = c;
    i++;
  }
  //printf("%d",inp_len);

  //  printf("%s\n", message);
  if(strcmp(argv[3],"-")==0){
    outfile = NULL;
    for(j = 0; j < inp_len; j++){
      encrypted[j] = message[j]^pw[j%pw_len];
      printf("%c",encrypted[j]);
   } 
    //printf("\n");

  }
  else{
    outfile = fopen(argv[3], "wb");

    for(j = 0; j < inp_len; j++){
      encrypted[j] = message[j]^pw[j%pw_len];
      fputc(encrypted[j],outfile);
    }
  fclose(outfile);
  }
  //fprintf(outfile,"%s", encrypted);

  fclose(infile);
  
  return 0;
}
