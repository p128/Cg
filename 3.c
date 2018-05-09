#include <stdlib.h>
#include <GL/glut.h>
GLsizei wh = 500, ww = 500;
GLfloat size = 3.0;
void drawSquare(int x, int y)
{
	glColor3ub((char)rand() % 256, (char)rand() % 256, (char)rand() % 256);
	glBegin(GL_POLYGON);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
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
		drawSquare(x, y);
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
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
	glutCreateWindow("Mouse Events - Random Points");
	myinit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(mymouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
