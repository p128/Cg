#include<stdio.h>
#include <windows.h>
#include<iostream>
#include <GL/glut.h>
using namespace std;
static int window;
static int menu_id;
static int submenu_id1, submenu_id2;
static int value = 0;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}

void createMenu(void)
{
	submenu_id1 = glutCreateMenu(menu);
	glutAddMenuEntry("Normal", 1);
	glutAddMenuEntry("Print", 2);
	glutAddMenuEntry("Web", 3);

	submenu_id2 = glutCreateMenu(menu);
	glutAddMenuEntry("Cut", 4);
	glutAddMenuEntry("Copy", 5);
	glutAddMenuEntry("Paste", 6);

	menu_id = glutCreateMenu(menu);

	glutAddSubMenu("View", submenu_id1);
	glutAddSubMenu("Edit", submenu_id2);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display(void) {
	int i, n;
	glClear(GL_COLOR_BUFFER_BIT);
	//print necessary stuff on output window 
	if (value == 1) {
		cout << "Normal" << endl;
	}
	else if (value == 2) {
		cout << "Print" << endl;
	}
	else if (value == 3) {
		cout << "Web" << endl;
	}
	else  if (value == 4) {
		cout << "Cut" << endl;
	}
	else if (value == 5) {
		cout << "Copy" << endl;
	}
	else if (value == 6) {
		cout << "Paste" << endl;
	}
	glFlush();
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Menus - display output");
	createMenu();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
