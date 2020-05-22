//This code is contibuted by Shreevatsa N and Yellappa Kumar.
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int board[3][3];	// board for gameplay
int turn;		// current move
int result;		// Result of the game
bool over;		// Is the game Over?
int comp = 0;		// for computer
int mainmenu=1;		// main menu 
/*
	Sets the board for Tic Tac Toe
*/
void Intialize()
{
	turn=1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			board[i][j]=0;
	}
}
/*
	Called when any key from keyboard is pressed
*/
void OnKeyPress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'p':   
			mainmenu = 0;
			over=false;
			Intialize();
			glutPostRedisplay();
			
		break;
		case 'c':
			mainmenu = 0;
			over=false;
			glutPostRedisplay();
			comp = 1;
			Intialize();
			
		break;		
		case 'y':
		if(over==true)
		{
			mainmenu = 1;
			over=false;
			Intialize();
		}
		break;
		case 'n':
		if(over==true)
		{
			exit(0);
		}
		break;
		default:
			exit(0);
	}
}
/*
	Called when Mouse is clicked 
*/
void OnMouseClick(int button,int state,int x,int y)	
{
	if(over==false && button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(turn==1)
		{
			if(board[(y-50)/100][x/100]==0)
			{
				board[(y-50)/100][x/100]=1;
				if(comp == 1) 
				turn = -1;
				else 
				turn=2;
			}
		}
		else if(turn==2)
		{
			if(board[(y-50)/100][x/100]==0)
			{
				board[(y-50)/100][x/100]=2;
				turn=1;
			}
		}
	}	
}

/*
	Utility function to draw string 	
*/
void DrawString(void *font,const char s[],float x,float y)
{
	unsigned int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(s);i++)
	{
		glutBitmapCharacter(font,s[i]);
	}
}

/*
	Function to draw up the horizontal and vertical lines
*/
void DrawLines()
{
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	
	glVertex2f(100,50);
	glVertex2f(100,340);
	glVertex2f(200,340);
	glVertex2f(200,50);
	
	glVertex2f(0,150);
	glVertex2f(300,150);
	glVertex2f(0,250);
	glVertex2f(300,250);
	
	glEnd();		
}

/*
	Utility function to draw the circle
*/
void DrawCircle(float cx, float cy, float r, int num_segments) 
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)   
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    }
    glEnd();
}

/*
	Function to draw the cross and circle of Tic Tac Toe
*/
void DrawXO()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==1)
			{
				glBegin(GL_LINES);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
			else if(board[i][j]==2)
			{
				DrawCircle(50 + j*100 , 100 + i*100 , 25 , 15);
			}
		}
	}
}


int blocking_win()
{
 int i, t;
 for( i = 0; i < 3; i++)
 {
	t = 0;
	t = board[i][0] + board[i][1] + board[i][2];
	if (t == 2)
	{
	// Find empty
	if (board[i][0] == 0) board[i][0] = 2;
	else if (board[i][1] == 0) board[i][1] = 2;
	else if (board[i][2] == 0) board[i][2] = 2;
	return 1;
	}
 }
 if ((board[0][1] + board[1][1] + board[2][1]) == 2)
 {
 	if (board[0][1] == 0) board[0][1] = 2;
 	else if (board[1][1] == 0) board[1][1] = 2;
 	else if (board[2][1] == 0) board[2][1] = 2;
 	return(1);
 }
 else if ((board[0][0] + board[1][0] + board[2][0]) == 2)
 {
 	if (board[0][0] == 0) board[0][0] = 2;
	else if (board[1][0] == 0) board[1][0] = 2;
 	else if (board[2][0] == 0) board[2][0] = 2;
 	return(1);
 }
 else if ((board[0][2] + board[1][2] + board[2][2]) == 2)
 {
 	if (board[0][2] == 0) board[0][2] = 2;
 	else if (board[1][2] == 0) board[1][2] = 2;
 	else if (board[2][2] == 0) board[2][2] = 2;
 	return(1);
 }
 else if ((board[0][0] + board[1][1] + board[2][2]) == 2)
 {
 	if (board[0][0] == 0) board[0][0] = 2;
	else if (board[1][1] == 0) board[1][1] = 2;
 	else if (board[2][2] == 0) board[2][2] = 2;
 	return(1);
 } 
 else if ((board[0][2] + board[1][1] + board[2][0]) == 2)
 {
 	if (board[0][2] == 0) board[0][2] = 2;
 	else if (board[1][1] == 0) board[1][1] = 2; 
 	else if (board[2][0] == 0) board[2][0] = 2;
 	return(1);
 }
 if (board[1][1] == 0){ 
	 board[1][1] = 2; return 1;
 }

 return(0);
 }
int check_corner(void)
{ 
 if (board[0][0]==0){ 
	 board[0][0]=2; 
	 return(1); 
 }
 else if(board[0][2]==0){ 
	 board[0][2]=2; 
	 return(1);
 }
 else if(board[2][0]==0){
	 board[2][0]=2;
	 return(1);
 }
 else if(board[2][2]==0){
	 board[2][2]=2;
	 return(1);
 }

 return(0);
 }
int check_row(void)
{
 if(board[0][1] == 0){ 
	 board[0][1]=2; 
	 return(1);
 }
 else if(board[1][0] == 0){
	 board[1][0]=2;
	 return(1);
 }
 else if(board[1][2] == 0){ 
	 board[1][2]=2;
	 return(1);
 }
 else if(board[2][1] == 0){ 
	 board[2][1]=2;
	 return(1);
 }

 return(0);
}

/*
	Function to check if there is any winner 
*/
bool CheckWinner()
{
	int i, j;
	// horizontal check
	for(i=0;i<3;i++)
	{
		for(j=1;j<3;j++)
		{
			if(board[i][0]!=0 && board[i][0]==board[i][j])
			{
				if(j==2)
				{
					return true;
				}
			}
			else
				break;
		}
	}
	// vertical check
	for(i=0;i<3;i++)
	{
		for(j=1;j<3;j++)
		{
			if(board[0][i]!=0 && board[0][i]==board[j][i])
			{
				if(j==2)
					return true;
			}
			else
				break;
		}
	}
	// Diagonal check
	if((board[0][0]!=0 && board[0][0]==board[1][1] && board[0][0]==board[2][2]) 
	|| (board[2][0]!=0 && board[2][0]==board[1][1] && board[2][0]==board[0][2]))
		return true;
	return false;
}

/*
	function to check if there is draw
*/
bool CheckIfDraw()
{
	int i, j;
	bool draw;
	for(i=0;i<3;i++)
	{ 
		for(j=0;j<3;j++)
		{ 
			if(board[i][j]==0)
				return false;
		}
	}
	return true;	
}
int computer()
{
if(!CheckWinner())
{
if(turn == -1){
if (blocking_win() == 1) turn = 1; 
else if ( check_corner() == 1) turn = 1; 
else if ( check_row() == 1) turn = 1;
return 1;	 
}
}
return 0;
}

/*
	Function to display up everything
*/
void Display(){
	if(mainmenu == 1)
		{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 1, 1, 1);
		glColor3f(0, 0, 1);
		DrawString(GLUT_BITMAP_HELVETICA_18, "Tic Tac Toe", 80, 80);
		glColor3f(1, 0, 1);
		DrawString(GLUT_BITMAP_HELVETICA_18, "Two player press - P", 60, 130);
		glColor3f(1, 0, 1);
		DrawString(GLUT_BITMAP_HELVETICA_18, "To play vs AI press - C", 60, 180);
		glutSwapBuffers();	
		}
	  	
	if(mainmenu == 0)
	{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 1, 1, 1);
	glColor3f(0, 0, 1);
	if(turn == 1){
		if(comp == 1) usleep(1000000);
		DrawString(GLUT_BITMAP_HELVETICA_18, "Player 1's turn", 100, 30);
}
	else if(turn == 2)
		DrawString(GLUT_BITMAP_HELVETICA_18, "Player 2's turn", 100, 30);
	else if(turn == -1){	
		DrawString(GLUT_BITMAP_HELVETICA_18, "computer's turn", 100, 30);
		
		}
	
	DrawLines();
	DrawXO();
	if(computer()) turn = 1;
	
	
	if(CheckWinner() == true)
	{
		if(turn == 1 && comp == 1)
		{
			over = true;
			result = 3;
		}
		else if(turn == 2 || turn == -1)
		{
			over = true;
			result = 1; 
		}
		else if(turn == 1 )
		{
			over = true;
			result = 2; 
		}

	}
	else if(CheckIfDraw() == true)
	{
		over = true;
		result = 0;
	}
	if(over == true)
	{
		glColor3f(0, 0, 1);
		DrawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 100, 160);
		if(result == 0)
			DrawString(GLUT_BITMAP_HELVETICA_18, "It's a draw", 110, 185);
		if(result == 1)
			DrawString(GLUT_BITMAP_HELVETICA_18, "Player1 wins", 95, 185);
		if(result == 2)
			DrawString(GLUT_BITMAP_HELVETICA_18, "Player2 wins", 95, 185);
		if(result == 3)
			DrawString(GLUT_BITMAP_HELVETICA_18, "computer wins", 95, 185);
		DrawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)", 40, 210);
	}
	
	glutSwapBuffers();
}
}
/*
	Function to reshape
*/
void Reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}
/*
	Driver Function
*/
int main(int argc, char **argv)
{
	Intialize();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(550,200);
	glutInitWindowSize(300,350);
	glutCreateWindow("Tic Tac Toe");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display); 
	glutKeyboardFunc(OnKeyPress);
	glutMouseFunc(OnMouseClick);
	glutIdleFunc(Display);
	glutMainLoop();
    return 0;
}
