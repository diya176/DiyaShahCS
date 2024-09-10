#include <iostream>
#include <cstring>
#include  <bits/stdc++.h>

using namespace std;

/*
This progran reads in a phrase and checks if that phrase is a palindrome by reversing the char array and seeing if the original and new char array are the same.

Author: Diya Shah

Date: 9/9/2024

*/


int main()
{
  //local variables input string, string without punctuation, and reversed string
  char old_string[81];
  char str_without_punctuation[81];
  char reversed_str[81];
  int a=-1;
  //input of phrase from user
  cout<<"Please enter a phrase"<<endl;
  //need to use cin.getline because of spaces
  cin.getline(old_string,80,'\n');

  //removes all punctuation, spaces, and numbers
  int j=0;
  for(int i=0;i<=strlen(old_string);i++)
  {
    if (isdigit(old_string[i])==false &&(old_string[i]!=' ') && ispunct(old_string[i])==false)
    {
      //puts the good characters into a new array 
      str_without_punctuation[j]=tolower(old_string[i]);
      j++;
    }
  }
  //removes null character 
  str_without_punctuation[j]='\0';
  // reverses the new characer array without punctuation and checks if they are the same
  for (int i=strlen(str_without_punctuation)-1;i>=0;i--)
  {
    reversed_str[a+1]=str_without_punctuation[i];
    a++;
  }
  //removes null character at end of array
  reversed_str[a+1]='\0';
  //compares the two strings
  if (strcmp(reversed_str,str_without_punctuation)==0)
  {
    cout<<"The phrase is a palindrome."<<endl;
  }
  else
  {
    cout<<"This phrase is not a palindrome."<<endl;
  }
  return 0;
}
