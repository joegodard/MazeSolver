# MazeSolver
A maze solver implemented in C.     
The program will read in a txt file with the maze to be solved, find the position of a "mouse" and the exit, and determine if a path exists through the maze.     
It does this by first adding each possible adjacent path onto a linked list, then moving to the next node in the list, adding adjacent paths again, 
and continuing until either the exit is found or the list is empty.
The mazes in the txt file should be of a certain format.

## Example Maze Format:
```
    6 5     
    1 1 1 1 1          
    1 0 0 e 1     
    1 1 1 0 1     
    1 r 1 0 1     
    1 0 0 0 1     
    1 1 1 1 1
```    

The maze can be a maximum 20*20 square, although this value can be adjusted in maze.h.

### Character Representations:
- 1 - Wall
- 0 - Empty Space
- r - The Mouse
- e - The Exit
- . - A Visited Space

The solver will print out the maze at each step of the process until the exit has been found or all possible paths have been checked.

## Example Successful Output:
![Successful Output](https://github.com/joegodard/MazeSolver/blob/main/Images/ExampleSuccessfulOutput.png?raw=true)

## Example Unsuccessful Output:
![Unsuccessful Output](https://github.com/joegodard/MazeSolver/blob/main/Images/ExampleUnsuccessfulOutput.png?raw=true)
