from collections import deque
from copy import deepcopy


class EightPuzzle:
    def __init__(self,p):
        self.parentState = [[line for line in p]] #parentState now holds the root, the p stte
        # print(start the init process)
    def CoordinateFinder(self, val, sttroot):
        i = 0
        line = 0
        counter = 0
        for line in range(3):
            for column in range(3):
                counter = counter + 1
                if self.parentState[sttroot][line][column] == val:
                    return (line,column)

    def nextMoveType(self, sttroot): # determining the type of the move to be done
        line, column = self.CoordinateFinder(0,sttroot)# finding the cordinate for zero  
        moves = []
        UP = line - 1
        RIGHT = column + 1
        DOWN= line + 1
        LEFT = column - 1
        
        if column > 0:
            moves.append((line, LEFT))    #go left
        if line > 0:
            moves.append((UP, column))    #go up
        if line < 2:
            moves.append((DOWN, column))    #go down
        if column < 2:
            moves.append((line, RIGHT))    #go right
        return moves

    def DFS(self,sttroot,DepthLevelStart,goal):#managing the list, add and 
        closed = []
        size = len(self.parentState)-1 #size
        #print(size)
        TypeOfMove =0
        TypeOfMove = self.nextMoveType(size)
        MaxDepht = 5 # how deep to go in graph 
        zeroTile = self.CoordinateFinder(0,size) # empty tile
        
        while TypeOfMove or DepthLevelStart < MaxDepht:
            for tile in TypeOfMove:
                children = deepcopy(self.parentState[sttroot]) #copy and create the children

                children[zeroTile[0]][zeroTile[1]] = children[tile[0]][tile[1]] #swich the zero tile position

                children[tile[0]][tile[1]] = 0 # new tile hold empty tile

                if children not in self.parentState and children not in closed: 
                    self.parentState.append(children)

                    if children == goal:# cheking if we reach goal state
                        print('execution completed')
                        return True
                    else: #keeps excuting until equal to goal state
                        cur = 0
                        cur = TypeOfMove.pop()
                        closed.append(children) ## to the list 
                        self.DFS(len(self.parentState)-1,DepthLevelStart + 1, goal)
                        return True     
        return False
    
    def PrintPuzzle(self):
        i = 1
        costpath =0
        for stte in self.parentState:
        #while stte < self.parentState:
            print('\nState: ',i)
            i = i + 1
            for line in stte:
                print(line),
        costpath = i -1
        return costpath
def executable():
    print('\n********************************************************************' )
    print('********************** DFS Depth First Search **********************' )
    print('********************************************************************' )
    
    p = [[2,8,3],[1,6,4],[7,0,5]]
    print('\nInitial State')
    for line in p:
       print(line)
    
    goal = [[1,2,3],[8,0,4],[7,6,5]]
    print('\nGoal state')
    for line in goal:
        print(line)

    DepthLevelStart = 0  
    p = EightPuzzle(p) # init the parent
    p.DFS(0,DepthLevelStart,goal)            
    cost= p.PrintPuzzle()# printing the puzzle
    print('The shortest path cost = ', cost)
    print('')

    # filename = "mynumbers.txt"
    # mynumbers = []
    # with open(filename) as f:
    #     for line in f:
    #         mynumbers.append([int(n) for n in line.strip().split(',')])
    # for pair in mynumbers:
    #     try:
    #         x,y,z = pair[0],pair[1], pair[2]
    #     except IndexError:
    #         print("A line in the file doesn't have enough entries.")

executable()



