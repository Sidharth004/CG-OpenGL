#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int flag = 0;
int r, xc, yc;

void Init(){

    glClearColor(0.0,0.0,0.0,0);
    glColor3f(0.0,0.0,1.0);
    gluOrtho2D(0,640,0,480);
}

void brescircle(){

    int x = 0, y = r;

    int d = 3 - 2*r;

    do{

        //printf("%d\t%d\t%d\t%d\t%d\n",x,y,xc+x,yc+y,d);
        glVertex2d(xc+x,yc+y);
        glVertex2d(xc+x,yc-y);
        glVertex2d(xc-x,yc+y);
        glVertex2d(xc-x,yc-y);
        glVertex2d(xc+y,yc+x);
        glVertex2d(xc+y,yc-x);
        glVertex2d(xc-y,yc+x);
        glVertex2d(xc-y,yc-x);

        if(d<0){

            x = x + 1;
            d = d + 4*x + 6;

        }else{

            x = x + 1;
            y = y - 1;
            d = d+ 4*x - 4*y + 10;

        }

    }while(y>=x);

}

void plot(){

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	//glVertex2d(100,100);
    brescircle();
	glEnd();
	glFlush();

}


int main(int argc, char **argv){

    //Accept input

    printf("Enter center point = ");
    scanf("%d", &xc);
    scanf("%d", &yc);

    printf("Enter radius = ");
    scanf("%d", &r);


    //OpenGL
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);     //Width, Height
	glutCreateWindow("Bresenham Circle");
    Init();
    glutDisplayFunc(plot);
    glutMainLoop();
    return 0;
}