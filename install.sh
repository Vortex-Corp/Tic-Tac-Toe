#!/bin/bash
#Run this file for installing all the required dependencies. $ ./install.sh <- cmd to run.
echo "Starting to install Glut Packages"
echo "->"
echo "-->"
echo "--->"
echo "---->"
echo "----->"
echo "------>"
echo "------->"
echo "-------->"
echo "---------->"
echo "----------->"
echo "------------>"
echo "------------->"
echo "-------------->"
echo "---------------------------->"

#Update permission to run shell scripts in exe mode.
sudo chmod +x runme.sh

#Update all Ubuntu-Bionic Updates.
sudo apt-get update

#Install all required dependencies listed on requirements.txt
sudo apt-get install $(cat requirements.txt)

echo "<----------------------------"

echo "Installation complete. OpenGL and associated libraries are ready to use."
