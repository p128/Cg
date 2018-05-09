#include<stdio.h>
#include <windows.h>
#include <GL/glut.h> 
static int window;
static int menu_id;
static int submenu_id;
static int value = 1;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else if(num == 1) {
		value = value * 2;
	}
	else {
		if(value != 1)
		value = value / 2;
	}

	glutPostRedisplay();
}
void createMenu(void)
{
	submenu_id = glutCreateMenu(menu);

	glutAddMenuEntry("Increase size", 1);
	glutAddMenuEntry("Decrease size", 2);

	menu_id = glutCreateMenu(menu);

	glutAddSubMenu("Resize square", submenu_id);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display(void) {
	int i, n;
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glVertex2f(0.2 * value, 0.2 * value);
	glVertex2f(-0.2 * value, 0.2 * value);
	glVertex2f(-0.2 * value, -0.2 * value);
	glVertex2f(0.2 * value, -0.2 * value);
	glEnd();
	glFlush();
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Menus - Square");
	createMenu();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
