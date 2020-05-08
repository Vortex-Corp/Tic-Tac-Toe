#!/bin/bash
# Run this file to start playing tic-tac-toe. Command to run this is $ ./runme.sh

sudo apt-get update
#update permission to run the program in exec mode.
sudo chmod +x ./runme.sh

#link the program file tictactoe.cpp to the OpenGL libraries
g++ tictactoe.cpp -lGl -lGLU -lglut 

./a.out
