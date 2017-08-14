// Rukmini Basu
// Rb2ep
// Hw 9
// Problem 1
// Compile with: g++ -O -Wall rb2ep_wordstats.cpp -o word -I$P2660LIB -L$P2660LIB -lp2660

// Produces two histograms - one for the frequency per letter in Alice in Wonderland
// The other is the frequency of the most common 50 words in Alice in Wonderland



#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hist.hpp"

int main(){

  FILE *inp;
  int c,i,j,k;

  int counter[27];
  int word_counter[50];
  char line[500];
  h1 letter_stat, word_stat;

 for(i = 0; i<27; i++){
    counter[i] = 0;
  }

 for(j = 0; j<50; j++){
   word_counter[j] = 0;
 }

  inp = fopen("alice.txt", "r");

  if(inp == NULL){
    printf("Input file does not exist.Exiting. \n");
    return 1;
  }

  while(fgets(line, 300, inp)){
    if(strstr(line,"the")||strstr(line, "The")){
	     word_counter[0]++;
	  }
	   if(strstr(line, "be") || strstr(line, "Be")|| strstr(line,"am") ||strstr(line, "Am")|| strstr(line, "is") || strstr(line, "Is")|| strstr(line, "are") || strstr(line, "Are")|| strstr(line, "being")||strstr(line, "Being") || strstr(line, "was") || strstr(line, "Was")|| strstr(line, "were") ||strstr(line, "Were") || strstr(line, "been") || strstr(line, "Been")){
	    word_counter[1]++;
	}
	  if(strstr(line, "to")||strstr(line, "To")){
	    word_counter[2]++;
	      }
	  if(strstr(line, "of")||strstr(line, "Of")){
	    word_counter[3]++;
       }
	  if(strstr(line, "and")||strstr(line, "And")){
	    word_counter[4]++;
	  }
	  if(strstr(line,"a")||strstr(line, "A")){
	    word_counter[5]++;
	  }
	  if(strstr(line,"in")||strstr(line, "In")){
	    word_counter[6]++;
	  }
	  if(strstr(line,"that")||strstr(line, "That")){
	    word_counter[7]++;
	  }
	  if(strstr(line,"have")||strstr(line, "Have")|| strstr(line, "Has")||strstr(line, "has")||strstr(line, "Hast")||strstr(line, "hast")||strstr(line, "Had")||strstr(line, "had")||strstr(line, "hath")||strstr(line, "Hath")||strstr(line, "having")||strstr(line, "having")){
	    word_counter[8]++;
	  }
	  if(strstr(line,"I")){
	    word_counter[9]++;
	  }
	  if(strstr(line,"it")||strstr(line, "It")){
	    word_counter[10]++;
	  }
	  if(strstr(line,"for")||strstr(line, "For")){
	    word_counter[11]++;
	  }
	  if(strstr(line,"not")||strstr(line, "Not")){
	    word_counter[12]++;
	  }
	  if(strstr(line,"on")||strstr(line, "On")){
	    word_counter[13]++;
	  }

	  if(strstr(line,"with")||strstr(line, "With")){
	    word_counter[14]++;
	  }
	  if(strstr(line,"he")||strstr(line, "He")){
	    word_counter[15]++;
	  }
	  if(strstr(line,"as")||strstr(line, "As")){
	    word_counter[16]++;
	  }
	  if(strstr(line,"You")||strstr(line, "you")){
	    word_counter[17]++;
	  }
	  if(strstr(line,"do")||strstr(line, "Do")||strstr(line, "Doest")||strstr(line, "doest")||strstr(line, "Dost")||strstr(line, "dost")||strstr(line, "Does")||strstr(line, "does")||strstr(line, "Doeth")||strstr(line, "doeth")||strstr(line, "doth")||strstr(line, "Doth")||strstr(line, "Did")||strstr(line, "did")||strstr(line, "Didst")||strstr(line, "didst")||strstr(line, "Done")||strstr(line, "done")||strstr(line, "doing")||strstr(line, "Doing")){
	    word_counter[18]++;
	  }
	  if(strstr(line,"At")||strstr(line, "at")){
	    word_counter[19]++;
	  }
	  if(strstr(line,"This")||strstr(line, "this")){
	    word_counter[20]++;
	  }
	  if(strstr(line,"But")||strstr(line, "but")){
	    word_counter[21]++;
	  }
	  if(strstr(line,"His")||strstr(line, "his")){
	    word_counter[22]++;
	  }
	  if(strstr(line,"By")||strstr(line, "by")){
	    word_counter[23]++;
	  }
	  if(strstr(line,"From")||strstr(line, "from")){
	    word_counter[24]++;
	  }
	  if(strstr(line,"They")||strstr(line, "they")){
	    word_counter[25]++;
	  }
	  if(strstr(line,"We")||strstr(line, "we")){
	    word_counter[26]++;
	  }
	  if(strstr(line,"Say")||strstr(line, "say")||strstr(line, "Says")||strstr(line, "says")||strstr(line, "Said")||strstr(line, "said")||strstr(line, "Saying")||strstr(line, "saying")){
	    word_counter[27]++;
	  }
	  if(strstr(line,"Her")||strstr(line, "her")){
	    word_counter[28]++;
	  }
	  if(strstr(line,"She")||strstr(line, "she")){
	    word_counter[29]++;
	  }
	  if(strstr(line,"Or")||strstr(line, "or")){
	    word_counter[30]++;
	  }
	  if(strstr(line,"An")||strstr(line, "an")){
	    word_counter[31]++;
	  }
	  if(strstr(line,"Will")||strstr(line, "will")){
	    word_counter[32]++;
	  }
	  if(strstr(line,"My")||strstr(line, "my")){
	    word_counter[33]++;
	  }
	  if(strstr(line,"One")||strstr(line, "one")){
	    word_counter[34]++;
	  }
	  if(strstr(line,"All")||strstr(line, "all")){
	    word_counter[35]++;
	  }
	  if(strstr(line,"Would")||strstr(line, "would")){
	    word_counter[36]++;
	  }
	  if(strstr(line,"There")||strstr(line, "there")){
	    word_counter[37]++;
	  }
	  if(strstr(line,"Their")||strstr(line, "their")){
	    word_counter[38]++;
	  }
	  if(strstr(line,"What")||strstr(line, "what")){
	    word_counter[39]++;
	  }
	  if(strstr(line,"So")||strstr(line, "so")){
	    word_counter[40]++;
	  }
	  if(strstr(line,"Up")||strstr(line, "up")){
	    word_counter[41]++;
	  }	  
	  if(strstr(line,"Out")||strstr(line, "out")){
	    word_counter[42]++;
	  }	  
	  if(strstr(line,"If")||strstr(line, "if")){
	    word_counter[43]++;
	  }	  
	  if(strstr(line,"About")||strstr(line, "about")){
	    word_counter[44]++;
	  }	  
	  if(strstr(line,"Who")||strstr(line, "who")){
	    word_counter[45]++;
	  }	  
	  if(strstr(line,"Get")||strstr(line, "get")||strstr(line, "Gets")||strstr(line, "gets")||strstr(line, "Got")||strstr(line, "got")||strstr(line, "Gat")||strstr(line, "Gat")||strstr(line, "Gotten")||strstr(line, "gotten")||strstr(line, "Getting")||strstr(line, "getting")){
	    word_counter[46]++;
	  }	  
	  if(strstr(line,"Which")||strstr(line, "which")){
	    word_counter[47]++;
	  }	 
	  if(strstr(line,"Go")||strstr(line, "go")||strstr(line, "Goes")||strstr(line, "goes")||strstr(line, "Went")||strstr(line, "went")||strstr(line, "Gone")||strstr(line, "gone")||strstr(line, "Going")||strstr(line, "Going")){
	    word_counter[48]++;
	  }	  
	  if(strstr(line,"Me")||strstr(line, "me")){
	    word_counter[49]++;
	  }

}

	  fclose(inp);

 inp = fopen("alice.txt", "r");
  do{
    c = getc(inp);
    if( feof(inp) ){
      break;
    }
    else if(c == 'A' || c == 'a'){
      counter[0]++;
    }
    else if(c == 'B' || c == 'b'){
      counter[1]++;
    }
    else if(c == 'C' || c == 'c'){
      counter[2]++;
    }
    else if(c == 'D' || c == 'd'){
      counter[3]++;
    }
    else if(c == 'E' || c == 'e'){
      counter[4]++;
    }
    else if(c == 'F' || c == 'f'){
      counter[5]++;
    }
    else if(c == 'G' || c == 'g'){
      counter[6]++;
    }
    else if(c == 'H' || c == 'h'){
      counter[7]++;
    }
    else if(c == 'I' || c == 'i'){
      counter[8]++;
    }
    else if(c == 'J' || c == 'j'){
      counter[9]++;
    }
    else if(c == 'K' || c == 'k'){
      counter[10]++;
    }
    else if(c == 'L' || c == 'l'){
      counter[11]++;
    }
    else if(c == 'M' || c == 'm'){
      counter[12]++;
    }
    else if(c == 'N' || c == 'n'){
      counter[13]++;
    }
    else if(c == 'O' || c == 'o'){
      counter[14]++;
    }
    else if(c == 'P' || c == 'p'){
      counter[15]++;
    }
    else if(c == 'Q' || c == 'q'){
      counter[16]++;
    }
    else if(c == 'R' || c == 'r'){
      counter[17]++;
    }
    else if(c == 'S' || c == 's'){
      counter[18]++;
    }
    else if(c == 'T' || c == 't'){
      counter[19]++;
    }
    else if(c == 'U' || c == 'u'){
      counter[20]++;
    }
    else if(c == 'V' || c == 'v'){
      counter[21]++;
    }
    else if(c == 'W' || c == 'w'){
      counter[22]++;
    }
    else if(c == 'X' || c == 'x'){
      counter[23]++;
    }
    else if(c == 'Y' || c == 'y'){
      counter[24]++;
    }
    else if(c == 'Z' || c == 'z'){
      counter[25]++;
    }
    else
      counter[26]++;

  }while(1);
 

  fclose(inp);

  //histograms w/ range 0.5:50.5
  h1init(&letter_stat,25,0.5,26.5,"letter statistics");
  h1init(&word_stat,25,0.5,50.5,"word statistics");


 
  for(i = 0; i<26; i++){
    h1fill(&letter_stat,i+1,(double)counter[i]);
    //printf("%d. %d\n",i,counter[i]);
  }

  for(k = 0; k <50; k++){
    h1fill(&word_stat,k+1,(double)word_counter[k]);
    //printf("%d. %d\n", k,word_counter[k]); 
  }

  h1labels(&letter_stat,"Letter", "Frequency of letter", "Letter Statistics");
 h1labels(&word_stat,"Word", "Frequency of Word", "Word Statistics");
  h1plot(&letter_stat);
  h1plot(&word_stat);


  return 0;


}
