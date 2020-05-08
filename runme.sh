#!/bin/bash
#Run this file to start playing tic-tac-toe. Command to run this is $ ./runme.sh

#link the program file tictactoe.cpp to the OpenGL libraries
#The cmd line will produce an executable file called as tictactoe in the current dir,
#Without -o the resulting execultablf file will be as a.out
g++ tictactoe.cpp -o tictactoe -lGL -lGLU -lglut

./tictactoe
