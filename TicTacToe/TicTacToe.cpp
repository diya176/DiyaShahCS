#include <iostream>
#include <cstring>
using namespace std;

/*
  This program simulates the game TicTacToe. It allows 2 players to play TicTacToe against each other. Play 1 will always be X and player 2 will always be O. To play enter a number for the row followed by a number for the column.

  Author: Diya Shah
  Date: 9/12/2024
 */

//declaration of functions 
void print_board(char board[3][3]);
bool checkIsValidMove (int row, int column, char board[3][3]);
void placePlayer(char player,int row,int column,char board[3][3]);
void take_turn (char player, char board[3][3],int x_win_count,int o_win_count,int tie_count);
bool checkWin(char player, char board[3][3]);
void play_again(char player,char board[3][3],int x_win_count,int o_win_count, int tie_count);

//main function that contains the board variable and the rows
//also starts the game initially 
int main()
{
  char board[3][3];
  for (int i=0; i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
      board[i][j]='-';
    }
  }
  print_board(board);
  int row;
  int column;
  char player='X';
  int x_win_count=0;
  int o_win_count=0;
  int tie_count=0;
  take_turn(player,board,x_win_count,o_win_count,tie_count);
  return 0;
}

//this function checks if a move is valid by checking if there is still a hypen at that location on board 
// if the move is not valid it returns false, if it is valid it returns true
bool checkIsValidMove(int row, int column, char board[3][3])
{
  if (board[row][column]=='-')
  {
    return true;
  }
  else if (board[row][column]=='X' || board[row][column]=='Y')
  {
    return false;
  }
  else
  {
    return false;
  }
}

//this function changes the location in board based on the move played
//it changes the space to an x or o depending on the player
//it uses the function checkIsValidMove to make sure that the space inputted is open 
void placePlayer(char player,int row,int column,char board[3][3])
{
  if (checkIsValidMove(row,column,board))
  {
    board[row][column]=player;
  }
}

//this function prints the board after each move 
void print_board(char board[3][3])
{
  cout<<"\n";
  cout<<"\t0\t\t1\t\t2";
  for(int i=0;i<3;i++)
  {
    cout<<"\n"<<endl;
    cout<<i;
    for (int j=0;j<3;j++)
    {
      cout<<"\t"<<board[i][j]<<"\t";
    }
    cout<<"\n"<<endl;
  }
}


//checks for a Tie by seeing if there are any open spaces on the board
//if there are then the game has not ended in a tie yet 
void checkBoard(char player, char board[3][3], int x_win_count,int o_win_count,int tie_count)
{
  if (board[0][0]=='-' || board [0][1]=='-'||board[0][2]=='-' || board[1][0]=='-'|| board[1][1]=='-'||board[1][2]=='-'||board[2][0]=='-'||board[2][1]=='-' || board[2][2]=='-')
  {
    cout << ' '<<endl;
  }
  else
  {
    tie_count=tie_count+1;
    player='T';
    play_again(player,board,x_win_count,o_win_count,tie_count);
  }
}

//checks if there is a column win, row win, or diagonal win 
bool checkWin(char player, char board[3][3])
{
  if(board[0][0]==player && board[1][0]==player && board [2][0]==player)
  {
    return true; 
  }
  else if (board[0][1]==player && board[1][1]==player && board[2][1]==player)
  {
    return true;
  }
  else if (board [0][2]==player && board[1][2]==player && board[2][2]==player)
  {
    return true;
  }
  else if (board[0][0]==player && board[0][1]==player && board[0][2]==player)
  {
    return true;
  }
  else if (board[1][0]==player && board[1][1]==player && board[1][2]==player)
  {
    return true;
  }
  else if (board[2][0]==player && board[2][1]==player && board [2][2]==player)
  {
    return true;
  }
  else if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
  {
    return true;
  }
  else if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//main function for playing the game

void take_turn(char player,char board[3][3],int x_win_count,int o_win_count,int tie_count)
{
  //makes a row and column variable
  int row;
  int column;
  //keeps running until game ends
  while (true)
  {
    //keeps running until a valid row move has been played (as in a 0, 1, or 2 has been inputted)
    while (true)
    {
      checkBoard(player,board,x_win_count,o_win_count,tie_count);
      cout<<"Please enter a number for the row where you want to place your piece"<<endl;
      cin>>row;
      //breaks if a valid number has been inputted
      if (row==0 || row==1 || row==2)
      {
	break;
      }
      else
      {
	cout<<"Failed"<<endl;
	;
      }
    }
    //same thing except for columns
    while (true)
    {
      //makes sure the board is not already in a tie situation 
      checkBoard(player,board,x_win_count,o_win_count,tie_count);
      cout<<"Please enter a number for the column where you want to place your piece"<<endl;
      cin>>column;
      if (column==0|| column==1|| column==2)
      {
	break;
      }
      else
      {
	cout<<"Failed"<<endl;
	;
      }
    }
    //checks if the move is valid and if it is not valid it reruns this function until the move is valid
    if(checkIsValidMove(row,column,board)==false)
    {
      print_board(board);
      cout<<"Try Again!"<<endl;
      take_turn(player,board,x_win_count,o_win_count,tie_count);
    }
    else
    {
      //pass function is just a semicolon
      ;
    }
    //if move is valid it places the player and then reprints the board
    placePlayer(player,row,column,board);
    print_board(board);
    //if player if X, it checks win and if the game has not ended in a win it changes the player to O and then reruns this function
    if (player=='X')
    {
      if (checkWin(player,board))
      {
	cout<<player<<" wins!"<<endl;
	x_win_count=x_win_count+1;
	play_again(player,board,x_win_count,o_win_count,tie_count);
      }
      player='O';
      take_turn(player,board,x_win_count,o_win_count,tie_count);
    }
    //same thing but for player o
    else
    {
      if (checkWin(player,board))
      {
	cout<<player<<" wins!"<<endl;
	o_win_count=o_win_count+1;
	play_again(player,board,x_win_count,o_win_count,tie_count);
      }
      player='X';
      take_turn(player,board,x_win_count,o_win_count,tie_count);
    }
  }
}

//asks user if they want to play again
//reruns the entire program is player says yes
void play_again(char player,char board[3][3], int x_win_count,int o_win_count,int tie_count)
{
  char play[2];
  //if it is a tie print the tie_count, etc. for players X and O
  if (player=='T')
  {
    cout<<"Tied: "<<tie_count<<" times."<<endl;
  }
  else if (player=='X')
  {
    cout<<"X has won: "<<x_win_count<<" times."<<endl;
  }
  else if (player=='O')
  {
    cout<<"O has won: "<<o_win_count<<" times."<<endl;
  }

  cout<<"Do you want to play again?"<<endl;
  cin>>play;
  if (strcmp(play,"yes")==0)
  {
    //resets the board
    for (int i=0; i<3;i++)
    {
      for (int j=0;j<3;j++)
      {
	board[i][j]='-';
      }
    }
    //prints the clean board
    print_board(board);
    player='X';
    //restarts the game
    take_turn(player,board,x_win_count,o_win_count,tie_count);
  }
  //ends the game 
  else
  {
    cout<<"Thanks for playing"<<endl;
    exit(0);
  }
      
}
