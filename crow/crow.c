#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

//display variable
int state=0,k;

//animation variables
float startx=0;

//fonts types
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

//keyboard function
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
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

//helper function for drawing sphere
void sphere(float r, float g, float b, float a)
{
        glColor4f(r,g,b,a);
        glutSolidSphere(1,100,32);

}

//story box
void showStory(){
  //story box
  glColor3f(0.2,0.1,0.5);
  glBegin(GL_POLYGON);
  glVertex2f(0,0);
  glVertex2f(0,80);
  glVertex2f(1000,80);
  glVertex2f(1000,0);
  glEnd();
}

//drawer functions
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

//scene-1 end

//scene-2 drawer function
void draw_hill2()
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

void DrawSegment2(float,float,float,int,int,int);

void draw_sky2()
{
	glColor3f(0.3,0.9,0.9);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(0,1000);
	glVertex2f(1000,1000);
	glVertex2f(1000,600);
	glEnd();
}

void draw_vase2()
{
    glColor3f(0.3,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(700,140);
    glVertex2f(700,100);
    glVertex2f(750,50);
    glVertex2f(850,50);
    glVertex2f(900,100);
    glVertex2f(900,140);
    glVertex2f(700,140);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(700,140);
    glVertex2f(700,200);
    glVertex2f(750,250);
    glVertex2f(750,300);
    glVertex2f(850,300);
    glVertex2f(850,250);
    glVertex2f(900,200);
    glVertex2f(900,140);
    glVertex2f(700,140);
    glEnd();
}

void draw_crow2()
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

void draw_tree2()
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

void draw_stone2()
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

void draw_eyes2()
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

//scene-2 end

//scene-3 drawer start
void draw_hill3()
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


void draw_sky3()
{
	glColor3f(0.3,0.9,0.9);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(0,1000);
	glVertex2f(1000,1000);
	glVertex2f(1000,600);
	glEnd();
}

void draw_vase3()
{
    glColor3f(0.3,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(700,140);
    glVertex2f(700,100);
    glVertex2f(750,50);
    glVertex2f(850,50);
    glVertex2f(900,100);
    glVertex2f(900,140);
    glVertex2f(700,140);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(700,140);
    glVertex2f(700,200);
    glVertex2f(750,250);
    glVertex2f(750,300);
    glVertex2f(850,300);
    glVertex2f(850,250);
    glVertex2f(900,200);
    glVertex2f(900,140);
    glVertex2f(700,140);
    glEnd();
}

void draw_crow3()
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(540,130);
    glVertex2f(545,140);
    glVertex2f(550,165);
    glVertex2f(555,185);
    glVertex2f(570,190);
    glVertex2f(590,190);
    glVertex2f(610,180);
    glVertex2f(620,170);
    glVertex2f(620,150);
    glVertex2f(580,125);
    glVertex2f(560,120);
    glVertex2f(540,127);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(620,150);
    glVertex2f(645,120);
    glVertex2f(620,120);
    glVertex2f(620,100);
    glVertex2f(595,130);
    glVertex2f(580,125);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(555,185);
    glVertex2f(540,195);
    glVertex2f(530,200);
    glVertex2f(450,200);
    glVertex2f(410,200);
    glVertex2f(425,180);
    glVertex2f(450,150);
    glVertex2f(480,135);
    glVertex2f(520,130);
    glVertex2f(540,130);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(480,135);
    glVertex2f(500,70);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(510,130);
    glVertex2f(530,70);
    glEnd();
}

void draw_tree3()
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

void draw_stone3()
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

void draw_eyes3()
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


//scene-3 end

//scene-4 drawer start

void draw_hill4()
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

void DrawSegment4(float,float,float,int,int,int);

void draw_sky4()
{
	glColor3f(0.3,0.9,0.9);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(0,1000);
	glVertex2f(1000,1000);
	glVertex2f(1000,600);
	glEnd();
}

void draw_vase4()
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

void draw_crow4()
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

void draw_tree4()
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

void draw_stone4()
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

void draw_eyes4()
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

//scene-4 end


//intro project details
void scene1(){

	 glColor3f(0.2,0.1,0.5);
	 glBegin(GL_POLYGON);
	 glVertex2f(0,0);
	 glVertex2f(0,1000);
	 glVertex2f(1200,1000);
	 glVertex2f(1200,0);
	 glEnd();
	
		glColor3f(0.5,0.2,0.6);
  	glPushMatrix();
  	glTranslatef(0,200,0);
  	write_text(300,130,"SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT",fonts[3]);
    glColor3f(0.3,0.5,0.8);
        write_text(375,100,"DEPT. OF COMPUTER SCIENCE & ENGG.",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        write_text(350,00,"UNDER THE GUIDENCE OF -----------",fonts[3]);
        write_text(480,-50,"--------- PROFEESSOR ",fonts[1]);
        glColor3f(0.8,0.1,0.2);
        write_text(450,600,"CROW-project title",fonts[2]);
        glColor3f(1.0,0.0,1.0);
        write_text(450,500,"SUBMITTED BY :",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        write_text(225,450,"Name1",fonts[3]);
        write_text(670,450,"Name2",fonts[3]);
        write_text(180,300,"",fonts[3]);
        write_text(220,400,"USN1",fonts[0]);
        write_text(680,400,"USN2",fonts[0]);

        write_text(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
	 glPopMatrix();
	 
	 //project deatils
 	 glFlush();
}

//scene-1 [crow flying]
void scene2() {
	glClearColor(0.2,0.8,0.1,1);
	draw_hill();
	draw_home();
	draw_tree();
	draw_sky();
	draw_path();
	
	glPushMatrix();
	glTranslatef(-600+startx++,0,0);
	draw_crow();
	glPushMatrix();
	glTranslatef(620,890,0);
  draw_eyes();
  glPopMatrix();
  glPopMatrix(); 
  
  if(startx>900){
  	state++;
  	startx=0;
  }
  
  glFlush();
}

//scene-2 
void scene3(){
  draw_hill2();
	draw_sky2();
	draw_tree2();
	glPushMatrix();
	glTranslatef(950,190,0);
	draw_stone2();
	glPopMatrix();
  glPushMatrix();
	glTranslatef(960,100,0);
	draw_stone2();
	glPopMatrix();
  glPushMatrix();
	glTranslatef(920,30,0);
	draw_stone2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,10,0);
	draw_stone2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700,15,0);
	draw_stone2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(650,30,0);
	draw_stone2();
	glPopMatrix();
  glPushMatrix();
	glTranslatef(680,70,0);
	draw_stone2();
	glPopMatrix();
  glPushMatrix();
	glTranslatef(620,100,0);
	draw_stone2();
	glPopMatrix();
  glPushMatrix();
	glTranslatef(570,10,0);
	draw_stone2();
	glPopMatrix();
  draw_vase2();

  draw_crow2();
  glPushMatrix();
	glTranslatef(815,400,0);
	draw_eyes2();
	glPopMatrix();
}

void scene4(){
	draw_hill3();
	draw_sky3();


	draw_tree3();
	glPushMatrix();
	glTranslatef(950,190,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(960,100,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(920,30,0);
	draw_stone3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,10,0);
	draw_stone3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700,15,0);
	draw_stone3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(650,30,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(680,70,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(630,100,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(570,10,0);
	draw_stone3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(770,60,0);
	draw_stone3();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(790,60,0);
	draw_stone3();
	glPopMatrix();
  draw_vase3();
  
	draw_crow3();
	glPushMatrix();
	glTranslatef(590,160,0);
	draw_eyes3();
	glPopMatrix();
}

void scene5(){
	draw_hill4();
	draw_sky4();

	draw_tree4();
	glPushMatrix();
	glTranslatef(950,190,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(960,100,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(920,30,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,10,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700,15,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(650,30,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(680,70,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(620,100,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(570,10,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,60,0);
	draw_stone4();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(820,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(760,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(770,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(840,60,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(770,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(840,70,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(780,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(830,80,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(790,90,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(800,90,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(810,90,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,90,0);
	draw_stone4();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(820,90,0);
	draw_stone4();
	glPopMatrix();
    draw_vase4();
  
	draw_crow4();
	
	glPushMatrix();
	glTranslatef(815,400,0);
	draw_eyes4();
	glPopMatrix();
}

void end(){
 glColor3f(0.2,0.1,0.5);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(0,1000);
 glVertex2f(1200,1000);
 glVertex2f(1200,0);
 glEnd();

 showStory();
 glColor3f(1,1,1);
 write_text(470,500,"The End",fonts[2]);
}

//GL display function
void display()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	if(state==0){
		scene1();
	}

	if(state==1){
		scene2();

	}

  if(state==2){
    scene3();
  }


  if(state==3){
    scene4();
  }
  
  if(state==4){
    scene5();
  }
  
  if(state==5){
    end();
  }
  if(state==6){
    exit(0);
  }
	
	
  glutSwapBuffers();
  glutPostRedisplay();
}
//main fucntion
int main(int argc,char **argv)
 {
  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project Name");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
