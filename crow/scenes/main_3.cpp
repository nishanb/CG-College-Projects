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

void DrawSegment(float,float,float,int,int,int);

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

void draw_vase()
{
    glColor3f(0.3,0.9,0.9);
    glBegin(GL_POLYGON);
    //glVertex2f(750,280);



    glVertex2f(750,50);
    glVertex2f(850,50);
    glVertex2f(900,100);
    glVertex2f(900,200);
    glVertex2f(850,250);
    glVertex2f(850,280);
    glVertex2f(750,280);
    glVertex2f(750,250);
    glVertex2f(700,200);
    glVertex2f(700,100);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(750,280);
    glVertex2f(750,300);
    glVertex2f(850,300);
    glVertex2f(850,280);
    glEnd();
}

void draw_crow()
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    //glVertex2f(750,300);
    //glVertex2f(735,305);
    //glVertex2f(725,315);
    glVertex2f(700,310);
    glVertex2f(680,300);
    glVertex2f(650,295);
    glVertex2f(600,290);
    glVertex2f(575,300);
    glVertex2f(540,315);
    glVertex2f(570,330);
    glVertex2f(605,350);
    glVertex2f(645,365);
    glVertex2f(680,380);
    glVertex2f(705,390);
    glVertex2f(730,400);
    glVertex2f(755,410);
    glVertex2f(760,390);
    glVertex2f(765,380);
    glVertex2f(770,370);
    glVertex2f(740,335);
    //glVertex2f(730,330);
    //glVertex2f(745,315);
    //glVertex2f(755,300);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(755,410);
    glVertex2f(770,412);
    glVertex2f(785,420);
    glVertex2f(800,425);
    glVertex2f(820,430);
    glVertex2f(830,428);
    glVertex2f(840,420);
    glVertex2f(845,410);
    glVertex2f(840,400);
    glVertex2f(837,390);
    glVertex2f(830,380);
    glVertex2f(825,375);
    glVertex2f(820,365);
    glVertex2f(815,340);
    glVertex2f(810,365);
    glVertex2f(800,375);
    glVertex2f(800,370);
    glVertex2f(790,370);
    glVertex2f(770,370);
    glVertex2f(760,390);
    glVertex2f(765,380);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(730,330);
    glVertex2f(755,300);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(750,300);
    glVertex2f(710,325);
    glEnd();
}

void draw_tree()
{
    glBegin(GL_QUADS);
    glColor3f(0.3,0,0);
    glVertex2f(100,100);
    glVertex2f(150,100);
    glVertex2f(150,200);
    glVertex2f(100,200);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0.4,0.1);
    glVertex2f(100,200);
    glVertex2f(80,200);
    glVertex2f(60,210);
    glVertex2f(50,230);
    glVertex2f(50,250);
    glVertex2f(55,280);
    glVertex2f(65,310);
    glVertex2f(80,335);
    glVertex2f(100,360);
    glVertex2f(110,370);
    glVertex2f(135,370);
    glVertex2f(160,350);
    glVertex2f(180,330);
    glVertex2f(200,300);
    glVertex2f(205,270);
    glVertex2f(210,250);
    glVertex2f(205,230);
    glVertex2f(190,220);
    glVertex2f(180,210);
    glVertex2f(150,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0,0);
    glVertex2f(250,300);
    glVertex2f(300,300);
    glVertex2f(300,400);
    glVertex2f(250,400);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0.4,0.1);
    glVertex2f(250,400);
    glVertex2f(210,400);
    glVertex2f(190,415);
    glVertex2f(190,450);
    glVertex2f(200,500);
    glVertex2f(230,540);
    glVertex2f(260,560);
    glVertex2f(300,560);
    glVertex2f(325,530);
    glVertex2f(345,500);
    glVertex2f(360,450);
    glVertex2f(360,410);
    glVertex2f(330,400);
    glVertex2f(300,400);
    glEnd();
}

void draw_stone()
{
    int i;
	float rad;
	glColor3f(0.3,0.4,0.4);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		rad=i*3.14159/180;
		glVertex2f(cos(rad)*7,sin(rad)*7);
	}
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

void scene4()
{
	draw_hill();
	draw_sky();

	draw_tree();
	glPushMatrix();
	glTranslatef(950,190,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(960,100,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(920,30,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,10,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700,15,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(650,30,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(680,70,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(620,100,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(570,10,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,60,0);
	draw_stone();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(820,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(760,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(770,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(840,60,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(770,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(840,70,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,80,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,90,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,90,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,90,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,90,0);
	draw_stone();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,90,0);
	draw_stone();
	glPopMatrix();
    draw_vase();
    glPushMatrix();
	glTranslatef(815,400,0);
	draw_eyes();
	glPopMatrix();
	draw_crow();
	//glPushMatrix();

	//glTranslatef(100,270,0);

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

	scene4();

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
	glutCreateWindow("scene4");
	init();
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	//glutTimerFunc(25,time,0);
	glutMainLoop();
}

