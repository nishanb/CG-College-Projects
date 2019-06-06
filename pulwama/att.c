#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

//scene1 variables
float speed_car=2,speed_bus=2,startx=2,starty=-200,flag=0,speed_jet=2,speed_bomb=2;
GLfloat test=0.1;
//to manage which scene to be displayed
int state=0,cx=0;
//to manage window position
int x,y,i;
//manage tyre
float tx=0;
//crashing flag
int isCrashed=0;
//bus movement
int dpx=-500,dpy=0;
//next scene
int next=0;
//scene9 variables
int bx=0,by=0;
int lx=0,ly=0;
//font types
void *fonts[]=
{
  	GLUT_BITMAP_9_BY_15,
  	GLUT_BITMAP_TIMES_ROMAN_10,
 	GLUT_BITMAP_TIMES_ROMAN_24,
 	GLUT_BITMAP_HELVETICA_18,
	GLUT_BITMAP_HELVETICA_12

};

//GL_init function
void init()
{
	glClearColor(1,1,1,1);
  	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,1000);
	glMatrixMode(GL_MODELVIEW);
}

//method to handle keyboard inputs keyboard-
void keyboard( unsigned char key, int x, int y )
{
	state++;
}

//function to write text
void write_text(int x, int y, char *string,void *font)
{
	int len, i;
	glRasterPos2f(x, y);
  	len = (int) strlen(string);
  	for (i = 0; i < len; i++)
	{
  		glutBitmapCharacter(font, string[i]);
 	}
}

//with default font
void renderBitmapString(float x, float y, const char *string){
   	const char *c;
   	glRasterPos2f(x, y);
    	for (c=string; *c != '\0'; c++)
	{
        	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    	}
}
//intro --scene1 display
void intro()
{
        glColor3f(0.5,0.2,0.6);
        write_text(300,130," SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT",fonts[3]);
        glColor3f(0.3,0.5,0.8);
        write_text(375,100,"DEPT. OF COMPUTER SCIENCE & ENGG.",fonts[0]);
        glColor3f(0.8,0.1,0.2);
        write_text(160,600,"GRAPHICAL IMPLEMENTATION OF PULWAMA ATTACK AND BALAKOT AIRSTRIKE",fonts[2]);
        glColor3f(1.0,0.0,1.0);
        write_text(450,500,"SUBMITTED BY :",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        write_text(225,450,"RESHMA KUMARI",fonts[3]);
        write_text(670,450,"SONALI S KUMAR",fonts[3]);
        write_text(180,300,"",fonts[3]);
        write_text(220,400,"(4SF16CS128)",fonts[0]);
        write_text(680,400,"(4SF16CS152)",fonts[0]);

        write_text(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}

//used in all scenes
void sky()
{
	glColor3f(0.5294117647,0.8078431373,0.9215686275);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(10000,0);
	glVertex2f(10000,10000);
	glVertex2f(0,10000);
    	glEnd();
}

//clouds
void drawClouds()
{
  	glColor3f(0.9,0.9,0.9);
	glPushMatrix();
  	glTranslatef(530,750,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
 	glPopMatrix();

	glPushMatrix();
  	glTranslatef(580,740,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();

	glPushMatrix();
 	glTranslatef(580,700,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(500,8000,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();
}

//function to draw road division strip
void drawStrip()
{
  	glColor3f(1,1,1);
  	int tx=100,ty=200;
  	for(i=0;i<10;i++)
	{
  		glBegin(GL_POLYGON);
    		glVertex2f(tx+=30,250);
    		glVertex2f(tx,270);
    		glVertex2f(ty+=30,270);
    		glVertex2f(ty,250);
    		glEnd();
    		tx+=100;
   		ty+=100;
  	}
}

//function to draw road
void drawRoad()
{
	glColor3f(0.12941176, 0.12941176, 0.12941176);
  	glBegin(GL_POLYGON);
  	glVertex2f(0,150);
  	glVertex2f(0,450);
  	glVertex2f(1000,450);
  	glVertex2f(1000,150);
  	glEnd();

  	glPushMatrix();
  	glTranslatef(-120,20,0);
  	drawStrip();
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(2,0.5,1);
  	glTranslatef(-120,600,0);
  	drawStrip();
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(2,0.5,1);
  	glTranslatef(-120,50,0);
  	drawStrip();
  	glPopMatrix();
}

//fucntion to draw Tree
void drawTree()
{
	glBegin(GL_POLYGON);
	glColor3f(0.6,0,0);
	glVertex2f(525,500);
	glVertex2f(550,500);
	glVertex2f(550,750);
	glVertex2f(525,750);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0,0);
	glVertex2f(550,525);
	glVertex2f(600,575);
	glVertex2f(600,600);
	glVertex2f(550,550);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6,0,0);
	glVertex2f(525,600);
	glVertex2f(525,625);
	glVertex2f(475,675);
	glVertex2f(475,650);
	glEnd();

  	// right green
	glColor3f(0,1,0);

  	glPushMatrix();
  	glTranslatef(620,580,0);
  	glScalef(40,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(450,680,0);
  	glScalef(40,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(530,750,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(580,740,0);
  	glScalef(60,50,0);
  	glutSolidSphere(1,100,10);
  	glPopMatrix();
}

//function to draw 2 buses
void drawBus(){

	//bus1
	//top
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(300,700);
	glVertex2f(600,700);
	glVertex2f(550,650);
	glVertex2f(250,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(600,700);
	glVertex2f(610,690);
	glVertex2f(560,630);
	glVertex2f(550,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(550,650);
	glVertex2f(560,630);
	glVertex2f(240,630);
	glVertex2f(250,650);
	glEnd();

	//glass
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(610,690);
	glVertex2f(610,600);
	glVertex2f(560,540);
	glVertex2f(560,630);
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(560,630);
	glVertex2f(560,540);
	glVertex2f(240,540);
	glVertex2f(240,630);
	glEnd();

	//bottom
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(240,540);
	glVertex2f(240,460);
	glVertex2f(275,440);
	glVertex2f(320,440);
	glVertex2f(385,440);
	glVertex2f(450,440);
	glVertex2f(515,440);
	glVertex2f(560,440);
	glVertex2f(560,540);
	glVertex2f(240,540);
	glEnd();

  	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(560,540);
	glVertex2f(560,440);
	glVertex2f(610,530);
	glVertex2f(610,630);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(560,540);
	glVertex2f(560,510);
	glVertex2f(610,630);
	glVertex2f(610,600);
	glEnd();

	//bus2
	//top
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(300+500,700);
	glVertex2f(600+500,700);
	glVertex2f(550+500,650);
	glVertex2f(250+500,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(600+500,700);
	glVertex2f(610+500,690);
	glVertex2f(560+500,630);
	glVertex2f(550+500,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(550+500,650);
	glVertex2f(560+500,630);
	glVertex2f(240+500,630);
	glVertex2f(250+500,650);
	glEnd();

	//glass
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(610+500,690);
	glVertex2f(610+500,600);
	glVertex2f(560+500,540);
	glVertex2f(560+500,630);
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,630);
	glVertex2f(560+500,540);
	glVertex2f(240+500,540);
	glVertex2f(240+500,630);
	glEnd();

	//bottom
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(240+500,540);
	glVertex2f(240+500,460);
	glVertex2f(275+500,440);
	glVertex2f(320+500,440);
	glVertex2f(385+500,440);
	glVertex2f(450+500,440);
	glVertex2f(515+500,440);
	glVertex2f(560+500,440);
	glVertex2f(560+500,540);
	glVertex2f(240+500,540);
	glEnd();

  	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,540);
	glVertex2f(560+500,440);
	glVertex2f(610+500,530);
	glVertex2f(610+500,630);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,540);
	glVertex2f(560+500,510);
	glVertex2f(610+500,630);
	glVertex2f(610+500,600);
	glEnd();
	renderBitmapString(445,485,"CRPF");
	renderBitmapString(945,485,"CRPF");
  	glFlush();
}

//contains single bus
void drawBus1()
{
	//bus2
	//top
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(300+500,700);
	glVertex2f(600+500,700);
	glVertex2f(550+500,650);
	glVertex2f(250+500,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(600+500,700);
	glVertex2f(610+500,690);
	glVertex2f(560+500,630);
	glVertex2f(550+500,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(550+500,650);
	glVertex2f(560+500,630);
	glVertex2f(240+500,630);
	glVertex2f(250+500,650);
	glEnd();

	//glass
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(610+500,690);
	glVertex2f(610+500,600);
	glVertex2f(560+500,540);
	glVertex2f(560+500,630);
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,630);
	glVertex2f(560+500,540);
	glVertex2f(240+500,540);
	glVertex2f(240+500,630);
	glEnd();

	//bottom
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(240+500,540);
	glVertex2f(240+500,460);
	glVertex2f(275+500,440);
	glVertex2f(320+500,440);
	glVertex2f(385+500,440);
	glVertex2f(450+500,440);
	glVertex2f(515+500,440);
	glVertex2f(560+500,440);
	glVertex2f(560+500,540);
	glVertex2f(240+500,540);
	glEnd();

  	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,540);
	glVertex2f(560+500,440);
	glVertex2f(610+500,530);
	glVertex2f(610+500,630);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,540);
	glVertex2f(560+500,510);
	glVertex2f(610+500,630);
	glVertex2f(610+500,600);
	glEnd();
	renderBitmapString(945,485,"CRPF");
  	glFlush();
}

//bombing car arrives-scene 4
void drawCar()
{
	//top
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(200,550);
	glVertex2f(300,550);
	glVertex2f(310,530);
	glVertex2f(190,530);
	glEnd();
	//1
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(210,530);
	glVertex2f(220,530);
	glVertex2f(210,470);
	glVertex2f(200,470);
	glEnd();
	//2
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(300,530);
	glVertex2f(310,470);
	glVertex2f(300,470);
	glVertex2f(290,530);
	glEnd();

	//middle
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(245,530);
	glVertex2f(245,470);
	glVertex2f(255,470);
	glVertex2f(255,530);
	glEnd();

	//glass
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(290,530);
	glVertex2f(300,470);
	glVertex2f(255,470);
	glVertex2f(255,530);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(245,530);
	glVertex2f(245,470);
	glVertex2f(210,470);
	glVertex2f(220,530);
	glEnd();

	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(210,530);
	glVertex2f(200,530);
	glVertex2f(190,470);
	glVertex2f(200,470);
	glEnd();

	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(300,530);
	glVertex2f(310,530);
	glVertex2f(340,470);
	glVertex2f(310,470);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(350,470);
	glVertex2f(360,410);
	glVertex2f(345,410);
	glVertex2f(305,410);
	glVertex2f(240,410);
	glVertex2f(240,410);
	glVertex2f(200,410);
	glVertex2f(180,410);
	glVertex2f(190,470);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(365,410);
	glVertex2f(365,390);
	glVertex2f(345,390);
	glVertex2f(345,410);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,410);
	glVertex2f(240,410);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,410);
	glVertex2f(240,410);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(180,410);
	glVertex2f(180,390);
	glVertex2f(200,390);
	glVertex2f(200,410);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(360,390);
	glVertex2f(360,370);
	glVertex2f(345,370);
	glVertex2f(345,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,370);
	glVertex2f(240,370);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,370);
	glVertex2f(240,370);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(180,370);
	glVertex2f(180,390);
	glVertex2f(200,390);
	glVertex2f(200,370);
	glEnd();
	glFlush();
}

//bus tires
void drawTireBus()
{
	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(470,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(340,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

  	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(470,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();

	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(340,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(970,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(840,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

  	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(970,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();

	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(840,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();
}

/*//bus back tires
void drawTback()
{
	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(575,495,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(1075,495,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();
}
*/
//last bus tires
void drawTireBus1()
{
	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(850,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(940,440,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

  	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(850,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();

	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(940,440,0);
  	glScalef(15,15,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();
}

/*//last bus back tire
void drawTback1()
{
	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(1075,495,0);
 	glScalef(35,35,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();
}*/

//car tires
void drawTirecar()
{
	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(324,380,0);
 	glScalef(20,26,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

	glColor3f(0.25,0.25,0.25);
  	glPushMatrix();
 	glTranslatef(220,380,0);
 	glScalef(20,26,1);
  	glutSolidSphere(1,500,4);
  	glPopMatrix();

  	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(324,380,0);
  	glScalef(10,10,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();

	glColor3f(1,1,1);
  	glPushMatrix();
  	glTranslatef(220,380,0);
  	glScalef(10,10,1);
  	glutWireSphere(1,500,4);
  	glPopMatrix();
}

//land fxn used in scene 9
void land()
{
	glColor3f(0.75,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(0,100);
	glVertex2f(10000,690);
	glVertex2f(10000,0);
	glVertex2f(0,0);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(900,70);
	glVertex2f(900,30);
	glVertex2f(920,30);
	glVertex2f(920,70);
	glEnd();



	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(940,70);
	glVertex2f(940,30);
	glVertex2f(970,30);
	glVertex2f(970,70);
	glEnd();
}

//contains broken bus parts after blast
void drawBrokenBus()
{
	//bus1
	//top
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(300,700+20);
	glVertex2f(600+30,700);
	glVertex2f(550+40,650);
	glVertex2f(250-20,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(600,700);
	glVertex2f(610,690);
	glVertex2f(560,630);
	glVertex2f(550,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(550-220,650);
	glVertex2f(560-220,630);
	glVertex2f(240-220,630);
	glVertex2f(250-220,650);
	glEnd();

	//bottom
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(240+30,540);
	glVertex2f(240+30,460);
	glVertex2f(275+30,440);
	glVertex2f(320+30,440);
	glVertex2f(385,440);
	glVertex2f(450,440);
	glVertex2f(515,440);
	glVertex2f(560,440);
	glVertex2f(560,540);
	glVertex2f(240,540);
	glEnd();

  	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(560,540);
	glVertex2f(560,440);
	glVertex2f(610,530);
	glVertex2f(610,630);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(560,540);
	glVertex2f(560,510);
	glVertex2f(610,630);
	glVertex2f(610,600);
	glEnd();

	//bus2
	//top
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(300+500,700);
	glVertex2f(600+500,700);
	glVertex2f(550+500,650);
	glVertex2f(250+500,650);
	glEnd();
	glColor3f(0,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(600+500,700);
	glVertex2f(610+500,690);
	glVertex2f(560+500,630);
	glVertex2f(550+500,650);
	glEnd();
	glColor3f(0,0.5,0);

	//bottom
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(240+500,540);
	glVertex2f(240+500,460);
	glVertex2f(275+500,440);
	glVertex2f(515+500,440);
	glVertex2f(560+500,440);
	glVertex2f(560+500,540);
	glVertex2f(240+500,540);
	glEnd();

  	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(560+500,540);
	glVertex2f(560+500,440);
	glVertex2f(610+500,530);
	glVertex2f(610+500,630);
	glEnd();
  	glFlush();

}

//broken parts of car after blast
void drawBrokenCar()
{
	//top
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(200+500,530);
	glVertex2f(300,550);
	glVertex2f(310+500,510);
	glVertex2f(190,520);
	glEnd();
	//1
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(210,530);
	glVertex2f(220,530);
	glVertex2f(210,470);
	glVertex2f(200,470);
	glEnd();
	//2
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(300+100,530);
	glVertex2f(310+100,470);
	glVertex2f(300+100,470);
	glVertex2f(290+100,530);
	glEnd();

	//middle
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(245+500,530);
	glVertex2f(245+500,470);
	glVertex2f(255+500,470);
	glVertex2f(255+500,530);
	glEnd();

	//glass
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(290+100,530);
	glVertex2f(300+100,470);
	glVertex2f(255+100,470);
	glVertex2f(255+100,530);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(245,530);
	glVertex2f(245,470);
	glVertex2f(210,470);
	glVertex2f(220,530);
	glEnd();

	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(210,530);
	glVertex2f(200,530);
	glVertex2f(190,470);
	glVertex2f(200,470);
	glEnd();

	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(300-200,530);
	glVertex2f(310-200,530);
	glVertex2f(340-200,470);
	glVertex2f(310-200,470);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(350,470);
	glVertex2f(360,410);
	glVertex2f(345,410);
	glVertex2f(305,410);
	glVertex2f(240,410);
	glVertex2f(240,410);
	glVertex2f(200,410);
	glVertex2f(180,410);
	glVertex2f(190,470);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(365+200,410);
	glVertex2f(365+200,390);
	glVertex2f(345+200,390);
	glVertex2f(345+200,410);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305-200,410);
	glVertex2f(240-200,410);
	glVertex2f(240-200,390);
	glVertex2f(305-200,390);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,410);
	glVertex2f(240,410);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(180-200,410);
	glVertex2f(180-200,390);
	glVertex2f(200-200,390);
	glVertex2f(200-200,410);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(360+200,390);
	glVertex2f(360+200,370);
	glVertex2f(345+200,370);
	glVertex2f(345+200,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,370);
	glVertex2f(240,370);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(305,370);
	glVertex2f(240,370);
	glVertex2f(240,390);
	glVertex2f(305,390);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(180+200,370);
	glVertex2f(180+200,390);
	glVertex2f(200+200,390);
	glVertex2f(200+200,370);
	glEnd();
	glFlush();
}

//bom fxn used in scene 9
void bomb()
{
	glColor3f(0,0,0);
	glPushMatrix();
  	glTranslatef(590,750,0);
  	glScalef(6,9,0);
  	glutSolidSphere(1,5,10);
 	glPopMatrix();

	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
  	glTranslatef(590,750,0);
  	glScalef(4,6,0);
  	glutSolidSphere(1,5,10);
 	glPopMatrix();
}

//blast polygon construction-scene 6 & 9 and also in showblasts()
//red blast mark
void blast()
{
    	glPushMatrix();
    	glColor3f(1.0, 0.0, 0.0);
    	glBegin(GL_POLYGON);
    	glVertex2f(404.4, 320.0);
    	glVertex2f(384.0, 285.0);
    	glVertex2f(368.0, 344.5);
    	glVertex2f(344.0, 355.0);
    	glVertex2f(347.2, 414.5);
    	glVertex2f(332.8, 442.5);
    	glVertex2f(347.2, 477.5);
    	glVertex2f(352.0, 530.0);
    	glVertex2f(379.2, 519.5);
    	glVertex2f(396.8, 565.0);
    	glVertex2f(416.0, 530.0);
    	glVertex2f(440.0, 547.5);
    	glVertex2f(452.8, 512.5);
    	glVertex2f(472.0, 512.5);
    	glVertex2f(475.2, 470.5);
    	glVertex2f(488.0, 442.5);
    	glVertex2f(488.0, 404.0);
    	glVertex2f(470.0, 372.5);
    	glVertex2f(475.2, 337.5);
    	glVertex2f(464.0, 306.0);
    	glVertex2f(444.8, 320.0);
    	glVertex2f(425.6, 285.0);
    	glVertex2f(404.8, 320.0);
    	glEnd();
    	glPopMatrix();

}

//orange blast mark
void blasto()
{
	glPushMatrix();
    	glColor3f(1,0.5,0);
    	glBegin(GL_POLYGON);
    	glVertex2f(404.4, 320.0);
    	glVertex2f(384.0, 285.0);
    	glVertex2f(368.0, 344.5);
    	glVertex2f(344.0, 355.0);
    	glVertex2f(347.2, 414.5);
    	glVertex2f(332.8, 442.5);
    	glVertex2f(347.2, 477.5);
    	glVertex2f(352.0, 530.0);
    	glVertex2f(379.2, 519.5);
    	glVertex2f(396.8, 565.0);
    	glVertex2f(416.0, 530.0);
    	glVertex2f(440.0, 547.5);
    	glVertex2f(452.8, 512.5);
    	glVertex2f(472.0, 512.5);
    	glVertex2f(475.2, 470.5);
    	glVertex2f(488.0, 442.5);
    	glVertex2f(488.0, 404.0);
    	glVertex2f(470.0, 372.5);
    	glVertex2f(475.2, 337.5);
    	glVertex2f(464.0, 306.0);
    	glVertex2f(444.8, 320.0);
    	glVertex2f(425.6, 285.0);
    	glVertex2f(404.8, 320.0);
    	glEnd();
    	glPopMatrix();

}

//yellow blast mark
void blasty()
{
	glPushMatrix();
    	glColor3f(1,1,0);
    	glBegin(GL_POLYGON);
    	glVertex2f(404.4, 320.0);
    	glVertex2f(384.0, 285.0);
    	glVertex2f(368.0, 344.5);
    	glVertex2f(344.0, 355.0);
    	glVertex2f(347.2, 414.5);
    	glVertex2f(332.8, 442.5);
    	glVertex2f(347.2, 477.5);
    	glVertex2f(352.0, 530.0);
    	glVertex2f(379.2, 519.5);
    	glVertex2f(396.8, 565.0);
    	glVertex2f(416.0, 530.0);
    	glVertex2f(440.0, 547.5);
    	glVertex2f(452.8, 512.5);
    	glVertex2f(472.0, 512.5);
    	glVertex2f(475.2, 470.5);
    	glVertex2f(488.0, 442.5);
    	glVertex2f(488.0, 404.0);
    	glVertex2f(470.0, 372.5);
    	glVertex2f(475.2, 337.5);
    	glVertex2f(464.0, 306.0);
    	glVertex2f(444.8, 320.0);
    	glVertex2f(425.6, 285.0);
    	glVertex2f(404.8, 320.0);
    	glEnd();
    	glPopMatrix();
}

void showBlasts()
{
  	glPushMatrix();
  	glTranslatef(300,0,0);
  	glScalef(0.8,0.8,1);
  	blast();
  	glPopMatrix();


  	glPushMatrix();
  	glTranslatef(100,0,0);
  	glScalef(0.8,0.8,1);
  	blast();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(200,100,0);
  	glScalef(0.8,0.8,1);
  	blast();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(200,300,0);
  	glScalef(0.8,0.8,1);
  	blast();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(400,200,0);
  	glScalef(0.8,0.8,1);
  	blast();
  	glPopMatrix();

	glPushMatrix();
  	glTranslatef(250,360,0);
  	glScalef(0.2,0.2,1);
  	blasty();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(415,210,0);
  	glScalef(0.2,0.2,1);
  	blasty();
  	glPopMatrix();

	glPushMatrix();
  	glTranslatef(350,460,0);
  	glScalef(0.2,0.2,1);
  	blasty();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(215,310,0);
  	glScalef(0.2,0.2,1);
  	blasty();
  	glPopMatrix();

	glPushMatrix();
  	glTranslatef(480,0,0);
  	glScalef(0.35,0.35,1);
  	blasto();
  	glPopMatrix();


  	glPushMatrix();
  	glTranslatef(330,0,0);
  	glScalef(0.35,0.35,1);
  	blasto();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(290,120,0);
  	glScalef(0.35,0.35,1);
  	blasto();
  	glPopMatrix();
}

//jet used in scene 8 and 9 for the balakot airstrike
void drawJet()
{
	//jetfront-cone
   	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(825,700);
  	glVertex2f(850,700);
  	glVertex2f(940,665);
  	glVertex2f(975,600);
  	glVertex2f(940,575);
  	glVertex2f(860,550);
  	glVertex2f(825,550);
  	glEnd();

  	glColor3f(0,0.1,0);
  	glPushMatrix();
  	glScalef(50,40,0);
  	glTranslatef(18.6,15.4,0);
  	glutSolidSphere(1,100,100);
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(50,40,0);
  	glTranslatef(18.4,15.7,0);
  	glutSolidSphere(1,100,100);
  	glPopMatrix();
	
  	//jet middle
 	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(825,550);
  	glVertex2f(250,550);
  	glVertex2f(225,675);
  	glVertex2f(450,700);
  	glVertex2f(825,700);
  	glEnd();

  	//jet end
  	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(250,550);
  	glVertex2f(105,615);
  	glVertex2f(35,880);
  	glVertex2f(95,865);
  	glVertex2f(225,675);
  	glEnd();
	
  	//jetend wing
  	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(35,880);
  	glVertex2f(75,870);
  	glVertex2f(135,690);
  	glVertex2f(105,615);
  	glEnd();
	
  	//jet door
  	glColor3f(0.43921569, 0.43921569, 0.43921569);
  	glBegin(GL_POLYGON);
  	glVertex2f(910,600);
  	glVertex2f(895,645);
  	glVertex2f(840,665);
  	glVertex2f(840,600);
  	glEnd();

  	//jet wings
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(450,580);
  	glVertex2f(570,580);
  	glVertex2f(400,425);
  	glVertex2f(320,415);
  	glEnd();
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(350,420);
  	glVertex2f(450,525);
  	glVertex2f(415,540);
  	glVertex2f(320,416);
  	glEnd();
  	glFlush();

  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(500,700);
  	glVertex2f(370,885);
  	glVertex2f(360,870);
  	glVertex2f(415,695);
  	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
  	glVertex2f(370,885);
  	glVertex2f(365,880);
  	glVertex2f(460,700);
  	glVertex2f(500,700);
	glEnd();

	//jetfront-cone
   	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(825+300,700+400);
  	glVertex2f(850+300,700+400);
  	glVertex2f(940+300,665+400);
  	glVertex2f(975+300,600+400);
  	glVertex2f(940+300,575+400);
  	glVertex2f(860+300,550+400);
  	glVertex2f(825+300,550+400);
  	glEnd();

   	glColor3f(0,0.1,0);
  	glPushMatrix();
  	glScalef(50,40,0);
  	glTranslatef(18.6,15.4,0);
  	glutSolidSphere(1,100,100);
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(50,40,0);
  	glTranslatef(18.4,15.7,0);
  	glutSolidSphere(1,100,100);
  	glPopMatrix();
	
  	//jet middle
 	glColor3f(0,0.1,0);
	glBegin(GL_POLYGON);
	glVertex2f(825+300,550+400);
  	glVertex2f(250+300,550+400);
  	glVertex2f(225+300,675+400);
  	glVertex2f(450+300,700+400);
  	glVertex2f(825+300,700+400);
  	glEnd();
	
  	//jet end
  	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(250+300,550+400);
  	glVertex2f(105+300,615+400);
  	glVertex2f(35+300,880+400);
  	glVertex2f(95+300,865+400);
  	glVertex2f(225+300,675+400);
  	glEnd();
	
  	//jetend wing
   	glColor3f(0,0.1,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(35+300,880+400);
  	glVertex2f(75+300,870+400);
  	glVertex2f(135+300,690+400);
  	glVertex2f(105+300,615+400);
  	glEnd();

  	//jet door
  	glColor3f(0.43921569, 0.43921569, 0.43921569);
  	glBegin(GL_POLYGON);
  	glVertex2f(910+300,600+400);
  	glVertex2f(895+300,645+400);
  	glVertex2f(840+300,665+400);
  	glVertex2f(840+300,600+400);
  	glEnd();
	
	//jet wings
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(450+300,580+400);
  	glVertex2f(570+300,580+400);
  	glVertex2f(400+300,425+400);
  	glVertex2f(320+300,415+400);
  	glEnd();
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(350+300,420+400);
  	glVertex2f(450+300,525+400);
  	glVertex2f(415+300,540+400);
  	glVertex2f(320+300,416+400);
  	glEnd();
  	glFlush();
	
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(500+300,700+400);
  	glVertex2f(370+300,885+400);
  	glVertex2f(360+300,870+400);
  	glVertex2f(415+300,695+400);
  	glEnd();
	
	
  	glColor3f(0,0,0);
  	glBegin(GL_POLYGON);
  	glVertex2f(370+300,885+400);
  	glVertex2f(365+300,880+400);
  	glVertex2f(460+300,700+400);
  	glVertex2f(500+300,700+400);
	glEnd();
	glColor3f(1,1,1);
  	renderBitmapString(500+150,660+350,"INDIA");
  	renderBitmapString(480,640,"INDIA");
	glFlush();
}

void scenery()
{
	sky();
  	drawRoad();
	drawClouds();
  	glPushMatrix();
  	glScalef(3,2,1);
  	glTranslatef(0,-300,1);

	//lawn left extension
	glBegin(GL_POLYGON);
	glColor3f(0.19,0.80,0.19);
	glVertex2f(400,525);
	glVertex2f(400,575);
	glVertex2f(100,575);
	glVertex2f(75,550);
	glVertex2f(75,535);
	glVertex2f(100,525);
	glEnd();
	//left lawn
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.0);
	glVertex2f(400,500);
	glVertex2f(0,500);
	glVertex2f(0,550);
	glVertex2f(75,550);
	glVertex2f(75,535);
	glVertex2f(100,525);
	glVertex2f(400,525);
	glEnd();

  	glBegin(GL_POLYGON);
	glColor3f(0.19,0.80,0.19);
	glVertex2f(250,500);
	glVertex2f(0,500);
	glVertex2f(0,525);
	glVertex2f(250,525);
	glEnd();
  	glPopMatrix();

  	glPushMatrix();
  	glTranslatef(400,0,0);
  	drawTree();
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(0.8,0.8,1);
  	glTranslatef(350,100,0);
  	drawTree();
  	glPopMatrix();

	glPushMatrix();
  	glScalef(0.6,0.8,1);
  	glTranslatef(30,100,0);
  	drawTree();
  	glPopMatrix();

  	glPushMatrix();
  	glScalef(10,2,1);
  	glTranslatef(-200,-500,1);
  	//lawn left extension
	glBegin(GL_POLYGON);
	glColor3f(0.19,0.80,0.19);
	glVertex2f(400,525);
	glVertex2f(400,575);
	glVertex2f(100,575);
	glVertex2f(75,550);
	glVertex2f(75,535);
	glVertex2f(100,525);
	glEnd();
	//left lawn
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.0);
	glVertex2f(400,500);
	glVertex2f(0,500);
	glVertex2f(0,550);
	glVertex2f(75,550);
	glVertex2f(75,535);
	glVertex2f(100,525);
	glVertex2f(400,525);
	glEnd();

  	glBegin(GL_POLYGON);
	glColor3f(0.19,0.80,0.19);
	glVertex2f(250,500);
	glVertex2f(0,500);
	glVertex2f(0,525);
	glVertex2f(250,525);
	glEnd();
  	glPopMatrix();
	glPopMatrix();
	glColor3f(0.5,0.2,0.6);
	write_text(690,20," PLACE : PULWAMA,JAMMU AND KASHMIR",fonts[3]);
}

//intro texts are here
void scene1()
{
  	sky();
  	glPushMatrix();
  	glTranslatef(-50,150,0);
  	intro();
  	glPopMatrix();
	glFlush();
}

//title after intro
void topic1()
{
        glColor3f(0.5,0.2,0.6);
	write_text(400,430," PULWAMA ATTACK",fonts[2]);
	write_text(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}

//PULWAMA ATTACK
void scene2()
{
  	sky();
  	glPushMatrix();
  	glTranslatef(-50,150,0);
  	topic1();
  	glPopMatrix();
	glFlush();
}

//has 7 CRPF buses
void scene3()
{
	scenery();
  	//speed_bus=4;
  	glLoadIdentity();
  	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx,-50,1);
  	//drawTback();
	drawBus();
	drawTireBus();
  	glPopMatrix();
	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-1000,-50,1);
	//drawTback();
	drawBus();
	drawTireBus();
  	glPopMatrix();
	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-2000,-50,1);
	//drawTback();
  	drawBus();
	drawTireBus();

  	glPopMatrix();
	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-3000,-50,1);
  	//drawTback1();
  	drawBus1();
	drawTireBus1();
  	glPopMatrix();
  	startx+=speed_bus+1;
	if(startx>2800)
	{
	  	state=3;
		startx=-750;
  	}
	glColor3f(1.0, 0.33, 0.0);
	glFlush();
}

//one bomber car
void scene4()
{
	scenery();
  	glLoadIdentity();
  	glPushMatrix();
  	glScalef(0.8,0.6,1);
  	glTranslatef(startx+200,20,1);
  	drawCar();
	drawTirecar();
  	glPopMatrix();
  	startx+=speed_car+2;
	if(startx>900)
	{
	  	state=4;
  	}
  	glColor3f(1.0, 0.33, 0.0);
  	glFlush();
}

//&buses and car together
void scene5()
{
	scenery();
  	glLoadIdentity();
	write_text(60,20," TIME : 3:15 PM",fonts[3]);
  	glPushMatrix();
  	glScalef(0.8,0.5,1);
	glTranslatef(startx-1600,200,1);
  	drawCar();
	drawTirecar();
  	glPopMatrix();
	startx+=speed_car;
	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-1200,-50,1);
  	//drawTback();
	drawBus();
	drawTireBus();
	glPopMatrix();
	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-2400,-50,1);
  	//drawTback();
	drawBus();
	drawTireBus();
  	glPopMatrix();
  	glPushMatrix();
  	glScalef(0.5,0.5,1);
  	glTranslatef(startx-3400,-50,1);
  	//drawTback();
	drawBus();
	drawTireBus();
  	glPopMatrix();
	startx+=speed_bus;
	if(startx>1650)
	{
	  	state=5;
  	}
  	glFlush();
}

//blast scene
void scene6()
{
  	scenery();
  	glPushMatrix();
  	glScalef(0.7,0.7,0);
  	glTranslatef(dpx,dpy,0);
	if(dpx>-50)
	{
  		glPushMatrix();
    		glTranslatef(-200,0,0);
    		glScalef(2,2,0);
    		showBlasts();
    		glPopMatrix();
    		isCrashed=1;
    		glFlush();
  	}
	else
	{
		dpx+=2;
		drawBus();
		drawTireBus();
		drawCar();
		drawTirecar();
  	}
  	glPopMatrix();
  	if(isCrashed==1)
	{
    		drawTree();
		glPushMatrix();
    		glScalef(0.7,0.7,1);
		glRotatef(-80,0,0,1);
		glTranslatef(-840,400,0);
		drawBrokenBus();
		drawTireBus();
    		glPopMatrix();
    		glPushMatrix();
    		glScalef(0.7,0.7,1);
    		glTranslatef(450,00,0);
    		drawBrokenCar();
		drawTirecar();
    		glPopMatrix();
    		showBlasts();
    		if(next==300)
      			state++;
    		glPushMatrix();
    		glTranslatef(next++,0,0);
    		glPopMatrix();
  	}
	write_text(60,20," TIME : 3:15 PM",fonts[3]);
  	glFlush();
}

//blalkot airstrike title
 void topic2()
{
        glColor3f(0.5,0.2,0.6);
	write_text(400,430," BALAKOT AIRSTRIKE",fonts[2]);
	write_text(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}

//BALAKOT AIRSTRIKE
void scene7()
{
  	sky();
  	glPushMatrix();
  	glTranslatef(-50,150,0);
  	topic2();
  	glPopMatrix();
	glFlush();
}

//scenery for scene 8 and 9
void scenery1()
{
	sky();
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(1000,0);
	glVertex2f(1000,1000);
	glVertex2f(0,1000);
  	glEnd();
  	glPushMatrix();
	glTranslatef(cx--,0,0);
  	glPushMatrix();
  	glTranslatef(300,100,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(700,-100,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(-100,-100,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(100,-300,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(700,100,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(0,100,0);
  	drawClouds();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(20,1,1);
  	glScalef(10,20,1);
  	glPopMatrix();
	glPopMatrix();
}

//2jets leaving to pakistan
void scene8()
{
	scenery1();	
  	glPushMatrix();
  	glScalef(0.2,0.6,1);
  	glTranslatef(startx+1500,starty+400,1);
  	startx+=speed_bus+2;
  	drawJet();
  	glPopMatrix();
  	glPopMatrix();
  	if(startx>1000)
	{
  		state=8;
  	  	startx=-800;
  	 	starty=500;
    		flag=0;
    		tx=100;
  	}
  	glFlush();
}

//jets dropping bomb on balakot resulting in a blast
void scene9()
{
	scenery1();
	glPushMatrix();
  	glScalef(0.1,0.4,1);
  	glTranslatef(startx+5500,850,1);
  	startx+=speed_jet+2;
  	drawJet();
  	glPopMatrix();
  	glPushMatrix();
  	glTranslatef(lx--,0,0);
  	land();
  	glPopMatrix();
    	write_text(690,20," PLACE : BALAKOT,PAKISTAN",fonts[3]);
	if(by<-618)
	{
		glPushMatrix();
      		glTranslatef(0,-100,0);
		showBlasts();
		glPopMatrix();
		startx+=speed_jet-2;
    		lx++;
  	}
	else
	{
    		glPushMatrix();
  		glTranslatef(bx,by,0);
    		bx=bx+0.8;
    		by=by-2;
  		bomb();
    		glPushMatrix();
    		glTranslatef(50,0,0);
    		bomb();
    		glPopMatrix();
  		glPopMatrix();
  	}
  	if(startx>2000)
	{
  		state=9;
    		startx=-800;
    		starty=500;
    		flag=0;
    		tx=100;
	}
	glFlush();
}

//The end is displayed here
void end()
{
	sky();
    	glColor3f(0.5,0.2,0.6);
	write_text(400,430," THE END",fonts[2]);
}

//GL display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if(state==0)
	{
		scene1();
	}
	if(state==1)
	{
		scene2();
	}
	if(state==2)
	{
		scene3();
	}
	if(state==3)
	{
		scene4();
	}
	if(state==4)
	{
		scene5();
	}
	if(state==5)
	{
		scene6();
	}
	if(state==6)
	{
		scene7();
	}
	if(state==7)
	{
		scene8();
	}
	if(state==8)
	{
		scene9();
	}
	if(state==9)
	{
    		end();
  	}
	glutSwapBuffers();
  	glutPostRedisplay();
}

//main fucntion
int main(int argc,char **argv)
{
 	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(10000,10000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pulwama attack and Balakot airstrike");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
}
