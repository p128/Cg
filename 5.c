#include <stdlib.h>
#include <GL/glut.h>
GLsizei wh = 500, ww = 500;
int states = 0;
int a, b;
void Polyline(int x, int y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(a, b);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void myReshape(GLsizei w, GLsizei h)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	ww = w;
	wh = h;
}
void mymouse(int btn, int state, int x, int y)
{
	y = wh - y;
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (states == 0) {
			states = 1;
			a = x;
			b = y;
		}
		else if(states == 1){
			Polyline(x, y);
			a = x;
			b = y;
		}
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		states = 0;
		glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
		glFlush();
	}
}
void myinit(void)
{
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
	glFlush();
}
void display(void)
{
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Mouse Events - Polyline");
	myinit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(mymouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

