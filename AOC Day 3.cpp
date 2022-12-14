#include <iostream>
#include <string.h>
//Use for file input and output
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int Priority(char check);
char Unique(string First,string Second);
char Unique(string First,string Second,string Third);

int main()
{
//Input filestream
ifstream file;

string Sack;
string FirstItem;
string SecondItem;
int strSize;
int midpoint;
int prioritySum = 0;

file.open("input.txt");

//Part 1
while(file >> Sack){
  //Get Total String Size and divide by half to get midpoint
  strSize = Sack.length();
  //midpoint calculation for substring use
  midpoint = (strSize/2);


  //Make an even split between first half of string and last half of string
  // Using midpoint as a stopping/starting point as well as indicate how many
  // characters to copy
  FirstItem = Sack.substr(0,midpoint);
  SecondItem = Sack.substr(midpoint,midpoint);
  prioritySum += Priority(Unique(FirstItem,SecondItem));
  //cout << "\nFirst String is:" << FirstItem << " Second Item is:" << SecondItem << endl;



}
file.close();
cout << "\nPriority Sum is:" << prioritySum;


//Part 2, I seperated this portion of the code for readability
int groupSum = 0;
string elfBags[3];
int count = 0;


file.open("input.txt");
//Part 1
while(file >> elfBags[0] >> elfBags[1] >> elfBags[2]){
groupSum += Priority(Unique(elfBags[0],elfBags[1],elfBags[2]));
}
file.close();

cout << "\nGroup Sum is:" << groupSum;


}

//Returns a Unique char that is contained in both strings
//Ended up using STL find, implementation is n^2 though
char Unique(string First,string Second)
{
  for(int i = 0;i < First.length();i++)
  {

    if(Second.find(First[i]) != -1)
    {
        //cout <<"\nStrings share:" << First[i];
        return (char)First[i];
    }

  }

}

//Returns a Unique char that is contained in all 3 strings
//Ended up using STL find, implementation is n^2 though
char Unique(string First,string Second,string Third)
{
  for(int i = 0;i < First.length();i++)
  {

    if((Second.find(First[i]) != -1) && (Third.find(First[i]) != -1))
    {
        //cout <<"\nStrings share:" << First[i];
        return (char)First[i];
    }

  }

}

//Calculates Priority of a Letter
int Priority(char check)
{
   if(check >= 'a' && check <= 'z')
   {
      return check -'a' + 1;
   }
  if(check >= 'A' && check <= 'Z')
  {
      return check-'A' + 27;
  }
  return -1;
}




