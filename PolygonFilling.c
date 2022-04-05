#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int v, p, q, input[2][10], x, y;
float boundarycolor[3], fillcolor[3];

int Round(int f){

	return f + 0.5;

}

void dda(int x1, int y1, int x2, int y2){

	int dx, dy, steps;

	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) > abs(dy)){

		steps = abs(dx);

	}else{

		steps = abs(dy);

	}

	float xinc, yinc;
	xinc = (float)(dx)/steps;
	yinc = (float)(dy)/steps;

	float x = x1, y = y1;

	glVertex2d(Round(x),Round(y));

	for(int i = 0; i < steps; i++){

		x = x + xinc;
		y = y + yinc;
		glVertex2d(Round(x), Round(y));

	}

}

void boundaryfill(int p, int q, float boundarycolor[3], float fillcolor[3]){

	float color[3];

	glReadPixels(p, q, 1.0, 1.0, GL_RGB, GL_FLOAT, color);

	/*for(int i = 0; i<3; i++){

		printf("%f\t", color[i]);

	}*/

	printf("\n");


	if((color[0]!=boundarycolor[0]) || (color[1]!=boundarycolor[1]) || (color[1]!=boundarycolor[1])){

		glColor3f(fillcolor[0], fillcolor[1], fillcolor[2]);
		glVertex2d(x, y);

		boundaryfill(p+1, q, boundarycolor, fillcolor);
		boundaryfill(p-1, q, boundarycolor, fillcolor);
		boundaryfill(p, q+1, boundarycolor, fillcolor);
		boundaryfill(p, q-1, boundarycolor, fillcolor);

	}

}


void display_point(){

	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	//glVertex2d(100,100);
	//dda(0,0,300,300);

	int j;

	for(j = 0; j < v-1; j++){

		dda(input[0][j], input[1][j], input[0][j+1], input[1][j+1]);

	}

	dda(input[0][j], input[1][j], input[0][0], input[1][0]);

	boundaryfill(p, q, boundarycolor, fillcolor);

	glEnd();
	glFlush();

}


int main(int argc, char **argv){

	printf("Vetices: ");
	scanf("%d", &v);

	//Coordinates for shape
	for(int x = 0; x < v; x++){

		printf(" X-coordinates = ");
		scanf("%d", &input[0][x]);

		printf(" Y-coordinates = ");
		scanf("%d", &input[1][x]);

	}

	//Change pixel color
	printf(" Enter 3 bit values for pixel fill color (R,G,B) = ");
	for(int x = 0; x < 3; x++){

		scanf("%f", &fillcolor[x]);

	}

	//Inside Pixel
	printf(" Coordinate for inside pixel = ");
	scanf("%d %d", &p, &q);


	//Background Fill Colour
	printf(" Enter values for background fill color = ");
	for(int x = 0; x < 3; x++){

		scanf("%f", &boundarycolor[x]);

	}

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(0, 0);

	glutInitWindowSize(640, 480);

	glutCreateWindow("Polygon Filling");

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(boundarycolor[0], boundarycolor[1], boundarycolor[2]);//Boundary
	gluOrtho2D(0, 640, 0, 480);

	glutDisplayFunc(display_point);

	glutMainLoop();
	
	return 0;
}
