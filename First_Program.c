#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


void Init(){


	glClearColor(0.0,0.0,0.0,0);
	glColor3f(0.0,1.0,0.0);
	gluOrtho2D(0,640,0,480);

}


void display_point(){

	//Clear Buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Plot pixel
	glBegin(GL_POINTS);
	glVertex2d(100,100);
	glEnd();
	
	//Clear the flush
	glFlush();

}


int main(int argc, char **argv){

	//Initilise GLUT library
	glutInit(&argc,argv);

	//Set initial disllay mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	//Set initial windpw position & size
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);     //Width, Height
	
	/*Create window with title*/
	glutCreateWindow("PLOT");
	
	//Initialise Drawing colours
	Init();
	
	//Call the display function
	glutDisplayFunc(display_point);
	
	//Keep displaying until program exit
	glutMainLoop();
	
	return 0;
}
