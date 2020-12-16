#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include "Tile.hpp"
#include <cstdlib>

using namespace std;

void my_solve(vector<Tile*> my_vector, Tile* my_Tile1) 
{
  Tile* curr = my_Tile1;
  my_vector.push_back(my_Tile1);
  int counter=-1;
  do {
     curr = curr->Parent;
    my_vector.push_back(curr);
  }while (curr->Parent != NULL) ;
  
  std::reverse(my_vector.begin(), my_vector.end());
  cout << "Initial State ";
int countstate = 0;
int notprint = 0;
  for (auto i : my_vector)  
  {
    if(notprint !=0)
    cout<< "State: "<< countstate;
    i->print8Puzzle();
    cout << endl<<endl;
    counter++;
    countstate = countstate +1;
    notprint = notprint +1;
  }
   
   cout << "The shortest path cost: " << counter<< endl;
}
bool number_in_puzzle(std::queue<Tile*> my_queue, Tile* my_tile) 
{
  bool here = false;
  while (!my_queue.empty() && my_queue.front()->game == my_tile->game) 
  {
      here = true;
      my_queue.pop();
  }
  return here;
}

//Dijkstra's Algorithm Priority Queue
bool my_priority_queue(priority_queue<Tile*> my_queue, Tile* my_tile) 
{
  bool here = false;
  while (!my_queue.empty() && my_queue.top()->game == my_tile->game) 
  {
      here = true;
      my_queue.pop();
  }
  return here;
}

void shuffle(int *arr, size_t n){
    if (n > 1) {
        size_t i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = arr[j];
          arr[j] = arr[i];
          arr[i] = t;
        }
    }
}


// compile g++ -std=c++11 Tile.cpp Tile.hpp main.cpp 
int main(void) 
{
  // int goal_state[3][3] ={
  //       {1, 2, 3},
  //       {4, 5, 6},
  //       {7, 8, 0}
  //   };
  // //Puzzle
  //   cout << "Array in order: " << endl;
  //   for(int i = 0; i < 3; ++i){
  //       for(int j = 0; j < 3; ++j){
  //           cout << goal_state[i][j] << " ";
  //       }
  //       cout << endl;
  //   }

  //   int temp[3][3];

	// srand((unsigned)time(NULL));

  //   cout << "Randomized Array (0-8)" << endl;
	// for(int i = 0; i < 3; ++i){
	//     for(int j = 0; j < 3; ++j){
  //           temp[i][j] = 0 + rand() % 9;
  //           cout << temp[i][j] << " ";
	//     }
  //       cout << endl;
  //   }

  cout<<"\n********************************************************************\n********************** BFS Breadth First Search **********************\n********************************************************************\n\n";

  std::vector<int> InitialState= { // error bc of the c++11 g++ -std=c++11 <filename>
          2, 8, 3,
          1, 6, 4,
          7, 0, 5
  };


  vector<int> FinalState = {   
         1, 2, 3,
         8, 0, 4,
         7, 6, 5 
      };

  Tile st = Tile(InitialState, NULL);
  queue<Tile*> fp;
  queue<Tile*> fc;
  fp.push(&st);
  bool solutionFound;
  solutionFound= false;
  
  vector<Tile*> solution;
  //cout << "Searching " << endl;

  while (!fp.empty() && !solutionFound)
  
   {
    Tile* currTile = fp.front();
    fc.push(currTile);
    fp.pop();
    //calling the functions
    int fz= currTile-> blank_space();

    currTile->move_up(fz);
    currTile->move_down(fz);
    currTile->move_right(fz);
    currTile->move_left(fz);

    for (auto j : currTile->child) 
    {
      Tile* currChildren = j;
      if (currChildren->game == FinalState) 
      {
       // cout << "Great I Found a Solution" << endl;
        my_solve(solution, currChildren);
        solutionFound = true;
        break;

      }
      if (!number_in_puzzle(fp, currChildren)
          && !number_in_puzzle(fc, currChildren)) 
          {
            fp.push(currChildren);
        }

    }
    
  }

  int result = system("python3 dfs.py");
  cout << result; 

  cout<<"\n********************************************************************\n********************** Dijkstra's Algorithm **********************\n********************************************************************\n\n";
  
  std::vector<int> InitialStateDijkstra= { // error bc of the c++11 g++ -std=c++11 <filename>
          2, 8, 3,
          1, 0, 4,
          7, 6, 5
  };


  vector<int> FinalStateDijkstra = {   
         1, 2, 3,
         8, 0, 4,
         7, 6, 5 
      };

  Tile st2 = Tile(InitialStateDijkstra, NULL);
  queue<Tile*> fp2;
  queue<Tile*> fc2;
  fp2.push(&st2);
  bool solutionFound2;
  solutionFound2= false;
  
  vector<Tile*> solution2;
  //cout << "Searching " << endl;

  while (!fp2.empty() && !solutionFound2)
  
   {
    Tile* currTile2 = fp2.front();
    fc2.push(currTile2);
    fp2.pop();
    //calling the functions
    int fz2= currTile2-> blank_space();

    currTile2->move_up(fz2);
    currTile2->move_down(fz2);
    currTile2->move_right(fz2);
    currTile2->move_left(fz2);

    for (auto j : currTile2->child) 
    {
      Tile* currChildren2 = j;
      if (currChildren2->game == FinalStateDijkstra) 
      {
       // cout << "Great I Found a Solution" << endl;
        my_solve(solution2, currChildren2);
        solutionFound2 = true;
        break;

      }
      if (!number_in_puzzle(fp2, currChildren2)
          && !number_in_puzzle(fc2, currChildren2)) 
          {
            fp2.push(currChildren2);
        }

    }
    
  }

  //my_priority_queue(priority_queue<Tile*> my_queue, Tile* my_tile);

  cout << result; 

  // int D[3][3] ={
  //       {1, 2, 3},
  //       {8, 0, 4},
  //       {7, 6, 5}
  //   };

  // int result2 = system("python3 depthFirstSearch.py");
  // cout << result2;

  //   cout << "\nResult: " << endl;
  //   for(int i = 0; i < 3; ++i){
  //       for(int j = 0; j < 3; ++j){
  //           cout << D[i][j] << " ";
  //       }
  //       cout << endl;
  //   }
}



