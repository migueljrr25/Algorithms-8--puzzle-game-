

#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include "Tile.hpp"

using namespace std;

int Tile::blank_space()
 {
    vector<int>::iterator iter;
    iter = find(game.begin(), game.end(), 0);
    int z;
    z = distance(game.begin(), iter);
   // cout<< "Z IS %d"<< endl; 
     return (int) z;
}// end of the blank_space function

void Tile::move_right(int Fz) 
{
  
  vector<int> right_vector;
  right_vector = game;
 
  if ( Fz!=2 &&  Fz != 5 && Fz != 8)
  {
       std::swap(right_vector[Fz], right_vector[Fz + 1]);
       Tile* new_child = new Tile(right_vector, this);
     child.push_back(new_child);
  }
 
}// end of the move_right function

void Tile::move_left(int Fz)
 {
  
  vector<int> left_vector;
  left_vector= game;

  if (Fz!= 0 && Fz != 3 && Fz != 6 )
  {
     std::swap(left_vector[Fz], left_vector[Fz - 1]);
     Tile* new_child = new Tile(left_vector, this);
     child.push_back(new_child);
  }
  
}// end of the move_left function
void Tile::move_up(int Fz) 
{
 
  vector<int> up_vector ;
  up_vector = game;
 
if ( Fz != 0 && Fz != 1 && Fz!=2 )
  {
    swap(up_vector[Fz], up_vector[Fz - 3]);
  
    Tile* new_child= new Tile(up_vector, this);
    child.push_back(new_child);
    
  }
}// end of the move_up functon

void Tile::move_down(int Fz)
 {
  
  vector<int> down_vector ;
  down_vector= game;
//this means the zero is not on the Third Row
   if (Fz != 6 && Fz != 7 && Fz != 8) 
   {
       std::swap(down_vector[Fz], down_vector[Fz + 3]);
    Tile* new_child = new Tile(down_vector, this);
    child.push_back(new_child);
   }

  

}// end of the movedDown function

void Tile::print8Puzzle() //Print function
{
  int counter= 0;
    int countstate = 1;
    
    for (auto i : game) //c++11
    {
      
      if (counter % 3 == 0 && counter !=0)
          std::cout << ']';
      if (counter % 3 == 0){
      std::cout << std::endl;}
      // cout<< "State: "<< countstate<<endl;}
      if (counter % 3 == 0)
          std::cout << '[';

      counter++;
      if (counter % 3 == 1 || counter % 3 == 2)
        std::cout << i << ", ";
      else
        std::cout << i;
      countstate = countstate +1;
    } 
  std::cout << ']';
 } //end of the print function

 