
#include <GL/glut.h>
/* initial triangle */
GLfloat v[4][3] = { { -1.0, -1.0, 1.0 },{ 1.0, -1.0, 1.0 },{ 0.0, 0.732, 0.0 },{ 0.0, -0.4226,0.0 } };
int n; /* number of recursive steps */
void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
/* display one triangle  */
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
	/* triangle subdivision using vertex numbers */
	GLfloat v0[3], v1[3], v2[3];
	int j;
	if (m>0)
	{
		for (j = 0; j<3; j++) v0[j] = (a[j] + b[j]) / 2;
		for (j = 0; j<3; j++) v1[j] = (a[j] + c[j]) / 2;
		for (j = 0; j<3; j++) v2[j] = (b[j] + c[j]) / 2;
		divide_triangle(a, v0, v1, m - 1);
		divide_triangle(c, v1, v2, m - 1);
		divide_triangle(b, v2, v0, m - 1);
	}
	else(triangle(a, b, c));
	/* draw triangle at end of recursion */
}
void tetrahedron(int m)
{
	glColor3f(0.0, 1.0, 0.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v[0], v[2], v[3], m);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	tetrahedron(n);
	//divide_triangle(v[0], v[1], v[2], n);
	glEnd();
	glFlush();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glRotated(180, 0, 1, 0);
}
int main(int argc, char **argv)
{
	n = 4;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Gasket");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
