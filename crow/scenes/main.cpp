#include<GL/glut.h>
#include<math.h>
void draw_hill()
{
	glColor3f(0.6,0.3,0);
	glBegin(GL_POLYGON);
	glVertex2f(0,600);
	glVertex2f(250,900);
	glVertex2f(500,600);
	glEnd();
	glColor3f(0.6,0.3,0);
	glBegin(GL_POLYGON);
	glVertex2f(500,600);
	glVertex2f(750,900);
	glVertex2f(1000,600);
	glEnd();
}

void draw_sky()
{
	glColor3f(0.3,0.9,0.9);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(0,1000);
	glVertex2f(1000,1000);
	glVertex2f(1000,600);
	glEnd();
}
void draw_crow()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

//glVertex2f(400,800);
    glVertex2f(400,840);
    glVertex2f(380,850);
    glVertex2f(370,860);
    glVertex2f(380,870);

    //glVertex2f(450,830);
    //glVertex2f(400,910);
    //glVertex2f(450,890);
    glVertex2f(500,880);
    glVertex2f(470,930);
    glVertex2f(520,950);
    glVertex2f(540,950);
    glVertex2f(590,930);
    glVertex2f(590,920);
    glVertex2f(570,880);
    glVertex2f(600,900);
    glVertex2f(620,910);
    glVertex2f(630,910);
    glVertex2f(640,890);
    glVertex2f(660,880);
    glVertex2f(640,860);
    glVertex2f(600,840);
    glVertex2f(560,810);
    glVertex2f(500,800);
    glVertex2f(450,810);
    //glVertex2f(400,800);
    glEnd();

}
void draw_home()
{
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(780,50);
    glVertex2f(820,50);
    glVertex2f(820,100);
    glVertex2f(780,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9,1,0);
    glVertex2f(730,50);
    glVertex2f(870,50);
    glVertex2f(870,150);
    glVertex2f(730,150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.6,0.2);
    glVertex2f(700,150);
    glVertex2f(900,150);
    glVertex2f(800,235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(300,400);
    glVertex2f(350,400);
    glVertex2f(350,460);
    glVertex2f(300,460);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9,1,0);
    glVertex2f(250,400);
    glVertex2f(400,400);
    glVertex2f(400,500);
    glVertex2f(250,500);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.6,0.2);
    glVertex2f(230,500);
    glVertex2f(420,500);
    glVertex2f(325,580);
    glEnd();

}

void draw_tree()
{
    glBegin(GL_QUADS);
    glColor3f(0.3,0,0.1);
    glVertex2f(310,60);
    glVertex2f(340,60);
    glVertex2f(340,100);
    glVertex2f(310,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.4,0.1);
    glVertex2f(300,150);
    glVertex2f(270,100);
    glVertex2f(380,100);
    glVertex2f(350,150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.4,0.1);
    glVertex2f(270,150);
    glVertex2f(380,150);
    glVertex2f(325,220);
    glEnd();
}

void draw_eyes()
{
    int i;
	float rad;
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		rad=i*3.14159/180;
		glVertex2f(cos(rad)*4,sin(rad)*4);
	}
	glEnd();
}
void draw_path()
{
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.1);
    glVertex2f(0,250);
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glVertex2f(1000,250);
    glEnd();
}


void scene1()
{
	draw_hill();

	draw_home();
	draw_tree();

    draw_path();
	glPushMatrix();
	glTranslatef(620,890,0);
    draw_eyes();
    glPopMatrix();
    draw_crow();
    draw_sky();
	//draw_pond();



}


void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1000,0,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClearColor(0.2,0.8,0.1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	scene1();

	//scene3();
	//scene4();
	//scene5();
	//scene6();

	glFlush();
	glutSwapBuffers();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	//glutInitWindowPosition(50,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("First scene");
	init();
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	//glutTimerFunc(25,time,0);
	glutMainLoop();
}

