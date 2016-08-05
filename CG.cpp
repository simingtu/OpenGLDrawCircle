#include "stdafx.h"
#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdlib.h>  
#include<math.h>

// 普通方法
void DrawCircle(int x, int y, int r)
{
	int n = 20000;  //分成20000份
	float increment = 2 * r * 1.0 / n; //每次x的增量

	glBegin(GL_POINTS);

	//上半个圆
	float xCurrent = x - r;
	float yCurrent = 0;
	for (int i = 0; i <= n; ++i)
	{
		xCurrent += i*increment;
		yCurrent = y + sqrtf(pow((float)r, 2) - pow((x - xCurrent), 2));
		glVertex3f(xCurrent, yCurrent, 0);
	}

	//下半个圆
	xCurrent = x - r;
	yCurrent = 0;
	for (int i = 0; i <= n; ++i)
	{
		xCurrent += i*increment;
		yCurrent = y - sqrtf(pow((float)r, 2) - pow((x - xCurrent), 2));
		glVertex3f(xCurrent, yCurrent, 0);
	}
	
	glEnd();
	glFlush();
}

//八分之一圆
void DrawCircle2()
{
	glBegin(GL_POINTS);
	double r = 400;
	double x = 0;
	double y = r;
	double d = 5 / 4 - r;
	while (x <= y)
	{
		if (d >= 0)
		{
			y = y - 1;
			d = d + 2 * (x - y) + 5;
		}
		else
		{
			x = x + 1;
			d = d + 2 * x + 3;
		}
		glVertex3f(x, y, 0);
	}
	glEnd();
	glFlush();
}

//主循环方法
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 1.0f);
	gluOrtho2D(-500,500,-500,500); //屏幕的坐标左下角为(-500,500)，右上角为(500,500)。
	glPointSize(3);
	//DrawCircle(0, 0, 250); //半径为250
	DrawCircle2();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}
