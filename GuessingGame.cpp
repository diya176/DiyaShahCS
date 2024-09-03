#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

//1. No global variables. (Global constants are all right.)
//2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
//3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".

//This is a program that picks a random number and then allows users to guess that number.
//Author: Diya S.


int main(){
  //creates a random number 
  srand(time(NULL));
  int random_number=0;
  int number_of_guesses=0;
  random_number=1+ rand()%100;
  while (true){
    // takes in the players guess
    int player_guess;
    cout<<"Please make a guess: ";
    cin>> player_guess;
    //checks if the provided number is the random number 
    if (player_guess==random_number){
      //prints out the number of guesses taken
      cout<<"Number of guesses taken: ";
      number_of_guesses=number_of_guesses+1;
      cout<<number_of_guesses<<endl;
      //asks the user if they want to play again
      char[]play_again;
      cout<<"Would you like to play again?: ";
      cin>>play_again;
      if (play_again=="yes" || play_again=="y" || play_again=="Yes" || play_again=="Y"){
	main();
       }
      else {
	exit(0);
       }
     }
    //checks if the guess is too big 
    else if (player_guess>random_number){
      cout<<"Your guess is too big"<<endl;
      number_of_guesses=number_of_guesses+1;
     }
    //checks if the guess is too small
    else if (player_guess<random_number){
      cout<<"Your guess is too small"<<endl;
      number_of_guesses=number_of_guesses+1;
     }
    
   }
  
  
}


