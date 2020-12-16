
#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_


#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Tile 
{
 public:
  vector<Tile*> child;
  vector<int> game;
  Tile *Parent;
 // vector<int> x;
  Tile(vector<int> puzzle, Tile *parent) 
  {
    game = puzzle;
    Parent = parent;
  }

//Implement functions 
  bool number_in_puzzle(std::queue<Tile*> my_queue, Tile* my_tile) ; 
  void my_solve(vector<Tile*> my_vector, Tile* my_Tile1);
  void print8Puzzle();
  int blank_space();
  void move_up(int Fz);
  void move_down(int Fz);
  void move_right(int Fz);
  void move_left(int Fz);

 
};

#endif





