//Rukmini Basu
//Rb2ep
//Final Problem 1
//On my honor I have neither given or received help on this assignment
//Strategy 2 consistently gave better results in terms of shutting the box. Typically, the probability of shutting the box hovered around 1.1% for strategy 2 where as for strategy 1, the probability of shutting the box was usually lowered than 0.03%. Both strategies yieled a probability of achieving the worst possible score around 0.8% of the time.

//usage: shutthebox num_of_pseudogames strategy
//compile with g++ -O -Wall rb2ep_shutthebox.cpp -o shutthebox $P2660FLAGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"

int strategy_more();
int strategy_fewer();

int main (int argc, char *argv[]){
  if(argc < 2){
    printf("Error");
    return -1;
  }

  int score1,worst_score, i;
  double worst_prob, best_prob;
  int pseudogames = atoi(argv[1]);
  // h1 strat1;

  worst_score = 76;
  worst_prob = 0;
  best_prob = 0;
  score1 = 0;
  

  //h1init(&strat1,12,0.5, 77.5, "");
 

  if(argc == 2){
    //run both strategies
    for(i = 0; i < pseudogames; i++){
      score1 = strategy_more();
      if(score1 == worst_score){
	worst_prob++;
      }
      else if(score1 == 0){
	best_prob++;
      }
      score1 = strategy_fewer();
      if(score1 == worst_score){
	worst_prob++;
      }
      else if(score1 == 0){
	best_prob++;
      }
      
    }
    printf("Both strategies were tested\n");
  }
  else if(atoi(argv[2]) == 1){
    //run strategy 1
    for(i = 0; i < pseudogames; i++){
    score1 = strategy_more();
      if(score1 == worst_score){
	worst_prob++;
      }
      else if(score1 == 0){
	best_prob++;
      }
    }
    printf("Strategy 1 (more first) was tested\n");
  }
  else if(atoi(argv[2]) == 2){
    //run strategy 2
    for(i = 0; i < pseudogames; i++){
      if(score1 == worst_score){
	worst_prob++;
      }
      else if(score1 == 0){
	best_prob++;
      }
    score1 = strategy_fewer();
    }
    printf("Strategy 2 (fewer first) was tested\n");
  }
  else{
    return -1;
  }

  best_prob = 100*best_prob/pseudogames;
  worst_prob = 100*worst_prob/pseudogames;

  if(argc == 2){
    worst_prob = 100*worst_prob/(2*pseudogames);
    best_prob = 100*best_prob/(2*pseudogames);
  }


  printf("The number of pseudogames tested is: %d\n", pseudogames);
  printf("The worst score possible is: 76\n");
  printf("The probability of achieving the worst possible score is: %lf\n", worst_prob);
  printf("The probability of shutting the box is: %lf\n", best_prob);
  
  return 0;
}


int strategy_more(){
  int score = 0;
  int game = 1;
  int roll,i,j;
  int box[13];

  for(j = 0; j<13; j++){
    box[j] = j;
  }
  while(game == 1){
    roll = randui(2, 12);
    if(roll == 12){
      if(box[6] == 6 && box[2] == 2 && box[3] == 3 && box[1] == 1){
	box[6] = 0;
	box[2] = 0;
	box[3] = 0;
	box[1] = 0;
      }

      else if(box[5] == 5 && box[2] == 2 && box[4] == 4 && box[1] == 1){
	box[5] = 0;
	box[2] = 0;
	box[4] = 0;
	box[1] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[9] == 9){
	box[1] = 0;
	box[2] = 0;
	box[9] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[8] == 8){
	box[1] = 0;
	box[3] = 0;
	box[8] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[7] == 7){
	box[1] = 0;
	box[4] = 0;
	box[7] = 0;

      }
      else if(box[2] == 2 && box[3] == 3 && box[7] == 7){
	box[2] = 0;
	box[3] = 0;
	box[7] = 0;

      }
      else if(box[1] == 1 && box[5] == 5 && box[6] == 6){
	box[1] = 0;
	box[5] = 0;
	box[6] = 0;

      }
      else if(box[2] == 2 && box[4] == 4 && box[6] == 6){
	box[2] = 0;
	box[4] = 0;
	box[6] = 0;
      }
      else if(box[3] == 3 && box[4] == 4 && box[5] == 5){
	box[3] = 0;
	box[4] = 0;
	box[5] = 0;

      } 
      else if(box[1] == 1 && box[11] == 11){
	box[1] = 0;
	box[11] = 0;

      } 
      else if(box[2] == 2 && box[10] == 10){
	box[2] = 0;
	box[10] = 0;

      } 
      else if(box[3] == 3 && box[9] == 9){
	box[3] = 0;
	box[9] = 0;
      } 
      else if(box[4] == 4 && box[8] == 8){
	box[4] = 0;
	box[8] = 0;
      } 
      else if(box[5] == 5 && box[7] == 7){
	box[5] = 0;
	box[7] = 0;
      } 
      else if(box[12] == 12){
	box[12] = 0;
      } 
      else{ game = 0;}
    }


    else if(roll == 11){
      if(box[1] == 1 && box[2] == 2 && box[3] == 3 && box[5] == 5){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
	box[5] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[8] == 8){
	box[1] = 0;
	box[2] = 0;
	box[8] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[7] == 7){
	box[1] = 0;
	box[3] = 0;
	box[7] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[6] == 6){
	box[1] = 0;
	box[4] = 0;
	box[6] = 0;

      }
      else if(box[2] == 2 && box[3] == 3 && box[6] == 6){
	box[2] = 0;
	box[3] = 0;
	box[6] = 0;
      }

      else if(box[2] == 2 && box[4] == 4 && box[5] == 5){
	box[2] = 0;
	box[4] = 0;
	box[5] = 0;

      }
      else if(box[1] == 1 && box[10] == 10){
	box[1] = 0;
	box[10] = 0;	
      } 
      else if(box[2] == 2 && box[9] == 9){
	box[2] = 0;
	box[9] = 0;
      } 
      else if(box[3] == 3 && box[8] == 8){
	box[3] = 0;
	box[8] = 0;

      } 
      else if(box[4] == 4 && box[7] == 7){
	box[4] = 0;
	box[7] = 0;
      } 
      else if(box[5] == 5 && box[6] == 6){
	box[5] = 0;
	box[6] = 0;

      } 

      else if(box[11] == 11){
	box[11] = 0;

      } 
      else {game = 0;}
    }

    else if(roll == 10){
      if(box[1] == 1 && box[2] == 2 && box[3] == 3 && box[4] == 4){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
	box[4] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[7] == 7){
	box[1] = 0;
	box[2] = 0;
	box[7] = 0;
      }
      else if(box[1] == 1 && box[3] == 3 && box[6] == 6){
	box[1] = 0;
	box[3] = 0;
	box[6] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[5] == 5){
	box[1] = 0;
	box[4] = 0;
	box[5] = 0;
      }
      else if(box[2] == 2 && box[3] == 3 && box[5] == 5){
	box[5] = 0;
	box[3] = 0;
	box[2] = 0;
      }
      else if(box[1] == 1 && box[9] == 9){
	box[9] = 0;
	box[1] = 0;

      } 
      else if(box[2] == 2 && box[8] == 8){
	box[2] = 0;
	box[8] = 0;

      } 
      else if(box[3] == 3 && box[7] == 7){
	box[3] = 0;
	box[7] = 0;

      } 
      else if(box[4] == 4 && box[6] == 6){
	box[4] = 0;
	box[6] = 0;

      } 

      else if(box[10] == 10){
	box[10] = 0;

      } 
      else{ game = 0;}
    }

    else if(roll == 9){
      if(box[1] == 1 && box[2] == 2 && box[6] == 6){
	box[1] = 0;
	box[2] = 0;
	box[6] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[5] == 5){
	box[1] = 0;
	box[3] = 0;
	box[5] = 0;
      }
      else if(box[2] == 2 && box[4] == 4 && box[3] == 3){
	box[2] = 0;
	box[4] = 0;
	box[3] = 0;
      }
      else if(box[1] == 1 && box[8] == 8){
	box[1] = 0;
	box[8] = 0;
      } 
      else if(box[2] == 2 && box[7] == 7){
	box[2] = 0;
	box[7] = 0;
      } 
      else if(box[3] == 3 && box[6] == 6){
	box[3] = 0;
	box[6] = 0;
      } 
      else if(box[4] == 4 && box[5] == 5){
	box[5] = 0;
	box[4] = 0;
      } 

      else if(box[9] == 9){
	box[9] = 0;
      } 
      else{ game = 0;}
    }

    else if(roll == 8){
      if(box[1] == 1 && box[2] == 2 && box[5] == 5){
	box[1] = 0;
	box[2] = 0;
	box[5] = 0;
      }
      else if(box[1] == 1 && box[3] == 3 && box[4] == 4){
	box[1] = 0;
	box[3] = 0;
	box[4] = 0;
      }
      else if(box[1] == 1 && box[7] == 7){
	box[1] = 0;
	box[7] = 0;
      } 
      else if(box[2] == 2 && box[6] == 6){
	box[2] = 0;
	box[6] = 0;
      } 
      else if(box[3] == 3 && box[5] == 5){
	box[5] = 0;
	box[3] = 0;
      } 
      else if(box[8] == 8){
	box[8] = 0;
      } 
      else{ game = 0;}
    }

    else if(roll == 7){
      if(box[1] == 1 && box[2] == 2 && box[4] == 4){
	box[1] = 0;
	box[2] = 0;
	box[4] = 0;
      }
      else if(box[1] == 1 && box[6] == 6){
	box[1] = 0;
	box[6] = 0;
      } 
      else if(box[2] == 2 && box[5] == 5){
	box[5] = 0;
	box[2] = 0;
      } 
      else if(box[3] == 3 && box[4] == 4){
	box[3] = 0;
	box[4] = 0;
      } 
      else if(box[7] == 7){
	box[7] = 0;
      } 
      else game = 0;
    }

    else if(roll == 6){
      if(box[1] == 1 && box[2] == 2 && box[3] == 3){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
      }
      else if(box[1] == 1 && box[5] == 5){
	box[5] = 0;
	box[1] = 0;
      } 
      else if(box[2] == 2 && box[4] == 4){
	box[2] = 0;
	box[4] = 0;
      } 
      else if(box[6] == 6){
	box[6] = 0;
      } 
      else{ game = 0;}
    }

    else if(roll == 5){
      if(box[1] == 1 && box[4] == 4){
	box[4] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[3] == 3){
	box[2] = 0;
	box[3] = 0;
      } 
      else if(box[5] == 5){
	box[5] = 0;
      } 
      else{ game = 0;}
    }

    else if(roll == 4){
      if(box[1] == 1 && box[3] == 3){
	box[1] = 0;
	box[3] = 0;
      }
      else if(box[4] == 4){
	box[4] = 0;
      } 
      else{ game = 0;}
    }

    else if(roll == 3){
      if(box[1] == 1 && box[2] == 2){
	box[1] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3){
	box[3] = 0;
      } 
      else{ game = 0;}
    }
    else{
      if(box[2] == 2){
	box[2] = 0;
      }
      else{game = 0;}
    }
  }


  for(i = 0; i < 13; i++){
    score += box[i];
  }
  return score;


}

int strategy_fewer(){
  int score = 0;
  int roll,i,j;
  int box[13];
  int game = 1;

  for(j = 0; j < 13; j++){
    box[j] = j;
  }

  while(game == 1){
    roll = randui(2,12);
    //strategy 2

    if(roll == 12){
      if(box[12] == 12){
	box[12] = 0;
      }
      else if(box[1] == 1 && box[11] == 11){
	box[11] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[10] == 10){
	box[10] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[9] == 9){
	box[9] = 0;
	box[3] = 0;
      }

      else if(box[4] == 4 && box [8] == 8){
	box[8] = 0;
	box[4] = 0;
      }

      else if(box[5] == 5 && box[7] == 7){
	box[5] = 0;
	box[7] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[9] == 9){
	box[1] = 0;
	box[2] = 0;
	box[9] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[8] == 8){
	box[1] = 0;
	box[3] = 0;
	box[8] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[7] == 7){
	box[1] = 0;
	box[4] = 0;
	box[7] = 0;

      }
      else if(box[2] == 2 && box[3] == 3 && box[7] == 7){
	box[2] = 0;
	box[3] = 0;
	box[7] = 0;


      }
      else if(box[1] == 1 && box[5] == 5 && box[6] == 6){
	box[1] = 0;
	box[5] = 0;
	box[6] = 0;

      }
      else if(box[2] == 2 && box[4] == 4 && box[6] == 6){
	box[2] = 0;
	box[4] = 0;
	box[6] = 0;

      }
      else if(box[3] == 3 && box[4] == 4 && box[5] == 5){
	box[3] = 0;
	box[4] = 0;
	box[5] = 0;

      } 
      else if(box[6] == 6 && box[2] == 2 && box[3] == 3 && box[1] == 1){
	box[6] = 0;
	box[2] = 0;
	box[3] = 0;
	box[1] = 0;
      }

      else if(box[5] == 5 && box[2] == 2 && box[4] == 4 && box[1] == 1){
	box[5] = 0;
	box[2] = 0;
	box[4] = 0;
	box[1] = 0;
      }
      else{
	game = 0;
      }
    }

    else if(roll == 11){
      if(box[11] == 11){
	box[11] = 0;
      }
      else if(box[1] == 1 && box[10]  == 10){
	box[10] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[9] == 9){
	box[9] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[8] == 8){
	box[8] = 0;
	box[3] = 0;
      }

      else if(box[4] == 4 && box[7] == 7){
	box[7] = 0;
	box[4] = 0;
      }

      else if(box[5] == 5 && box[6] == 6){
	box[5] = 0;
	box[6] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[8] == 8){
	box[1] = 0;
	box[2] = 0;
	box[8] = 0;
      }
      else if(box[1] == 1 && box[3] == 3 && box[7] == 7){
	box[1] = 0;
	box[3] = 0;
	box[7] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[6] == 6){
	box[1] = 0;
	box[4] = 0;
	box[6] = 0;

      }
      else if(box[2] == 2 && box[3] == 3 && box[6] == 6){
	box[2] = 0;
	box[3] = 0;
	box[6] = 0;

      }

      else if(box[2] == 2 && box[4] == 4 && box[5] == 5){
	box[2] = 0;
	box[4] = 0;
	box[5] = 0;

      }
      else if(box[1] == 1 && box[2] == 2 && box[3] == 3 && box[5] == 5){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
	box[5] = 0;
      }
      else{
	game = 0;
      }	
    }

    else if(roll == 10){
      if(box[10] == 10){
	box[10] = 0;
      }
      else if(box[1] == 1 && box[9] == 9){
	box[9] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[8] == 8){
	box[8] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[7] == 7){
	box[7] = 0;
	box[3] = 0;
      }

      else if(box[4] == 4 && box[6] == 6){
	box[6] = 0;
	box[4] = 0;
      }

      else if(box[1] == 1 && box[2] == 2 && box[7] == 7){
	box[1] = 0;
	box[2] = 0;
	box[7] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[6] == 6){
	box[1] = 0;
	box[3] = 0;
	box[6] = 0;

      }
      else if(box[1] == 1 && box[4] == 4 && box[5] == 5){
	box[1] = 0;
	box[4] = 0;
	box[5] = 0;

      }
      else if(box[2] == 2 && box[3] == 3 && box[5] == 5){
	box[5] = 0;
	box[3] = 0;
	box[2] = 0;

      }
      else if(box[1] == 1 && box[2] == 2 && box[3] == 3 && box[4] == 4){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;
	box[4] = 0;
      }
      else{
	game = 0;
      }
    }

    else if(roll == 9){
      if(box[9] == 9){
	box[9] = 0;
      }
      else if(box[1] == 1 && box[8] == 8){
	box[8] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[7] == 7){
	box[7] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[6] == 6){
	box[6] = 0;
	box[3] = 0;
      }

      else if(box[4] == 4 && box[5] == 5){
	box[5] = 0;
	box[4] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[6] == 6){
	box[1] = 0;
	box[2] = 0;
	box[6] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[5] == 5){
	box[1] = 0;
	box[3] = 0;
	box[5] = 0;

      }
      else if(box[2] == 2 && box[4] == 4 && box[3] == 3){
	box[2] = 0;
	box[4] = 0;
	box[3] = 0;

      }
      else{
	game = 0;
      }
    }

    else if(roll == 8){
      if(box[8] == 8){
	box[8] = 0;
      }
      else if(box[1] == 1 && box[7] == 7){
	box[7] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[6] == 6){
	box[6] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[5] == 5){
	box[5] = 0;
	box[3] = 0;
      }

      else if(box[1] == 1 && box[2] == 2 && box[5] == 5){
	box[1] = 0;
	box[2] = 0;
	box[5] = 0;

      }
      else if(box[1] == 1 && box[3] == 3 && box[4] == 4){
	box[1] = 0;
	box[3] = 0;
	box[4] = 0;

      }
      else{
	game = 0;
      }
    }

    else if(roll == 7){
      if(box[7] == 7){
	box[7] = 0;
      }
      else if(box[1] == 1 && box[6] == 6){
	box[6] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[5] == 5){
	box[5] = 0;
	box[2] = 0;
      }
      else if(box[3] == 3 && box[4] == 4){
	box[4] = 0;
	box[3] = 0;
      }

      else if(box[1] == 1 && box[2] == 2 && box[4] == 4){
	box[1] = 0;
	box[2] = 0;
	box[4] = 0;

      }
      else{
	game = 0;
      }
    }

    else if(roll == 6){
      if(box[6] == 6){
	box[6] = 0;
      }
      else if(box[1] == 1 && box[5] == 5){
	box[5] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[4] == 4){
	box[4] = 0;
	box[2] = 0;
      }
      else if(box[1] == 1 && box[2] == 2 && box[3] == 3){
	box[1] = 0;
	box[2] = 0;
	box[3] = 0;

      }
      else{
	game = 0;
      }
    }

    else if(roll == 5){
      if(box[5] == 5){
	box[5] = 0;
      }
      else if(box[1] == 1 && box[4] == 4){
	box[4] = 0;
	box[1] = 0;
      }
      else if(box[2] == 2 && box[3] == 3){
	box[3] = 0;
	box[2] = 0;
      }
      else{
	game = 0;
      }
    }

    else if(roll == 4){
      if(box[4] == 4){
	box[4] = 0;
      }
      else if(box[1] == 1 && box[3] == 3){
	box[3] = 0;
	box[1] = 0;
      }
      else{
	game = 0;
      }
    }

    else if(roll == 3){
      if(box[3] == 3){
	box[3] = 0;
      }
      else if(box[1] == 1 && box[2] == 2){
	box[2] = 0;
	box[1] = 0;
      }
      else{
	game = 0;
      }
    }

    else{
      if(box[2] == 2){
	box[2] = 0;
      }
      else{
	game = 0;
      }
    }

  }
  for(i = 0; i < 13; i++){
    score += box[i];
  }
  return score;

}

//78

//2 = 2
//3 = 2,1;3
//4 = 1,3;4
//5 = 1,4;2,3;5
//6 = 1,5;2,4;6;
//7 = 1,6;2,5;3,4;7;1,2,4;
//8 = 
