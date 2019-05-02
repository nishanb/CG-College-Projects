#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

//to manage which scene to be displayed
int state=0,cx=0;
//to manage window position
int x,y,i,colorindex=0;

//mamage day and night
const GLfloat color[10][3]={
  {0.0,0.03,0.08},
  {0.01,0.07,0.16},
  {0.02,0.11,0.27},
  {0.02,0.16,0.39},
  {0.05,0.22,0.49},
  {0.07,0.28,0.6},
  {0.13,0.35,0.69},
  {0.5294117647,0.8078431373,0.9215686275},
  {0.23,0.45,0.79},
  {0.39,0.64,0.87}
};

//scene1 variables
float startx=2,starty=-200,flag=0;

//person variables
int moveFlag=0;
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
  //handle --> press any key to continue
  if(state==0){
     state=1;

  }

  //move to end
  if(state==5){
      state=6;
  }

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
//intro --scene1 display
void intro()
{
        glColor3f(0.5,0.2,0.6);
        write_text(300,130," SRINIVAS INSTITUTE OF TECHNOLOGY - MANLGLORE 571543",fonts[3]);
        glColor3f(0.3,0.5,0.8);
        write_text(375,100,"DEPT. OF COMPUTER SCIENCE & ENGG.",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        write_text(350,00,"UNDER THE GUIDENCE OF MR.SUDHAKAR.",fonts[3]);
        write_text(480,-50,"ASSITANT PROFEESSOR ",fonts[1]);
        glColor3f(0.8,0.1,0.2);
        write_text(350,600,"THE BOY WHO CRIED OVER WOLF",fonts[2]);
        glColor3f(1.0,0.0,1.0);
        write_text(450,500,"SUBMITTED BY :",fonts[0]);
        glColor3f(0.3,0.5,0.8);
        write_text(225,450,"SHRAVYA",fonts[3]);
        write_text(670,450,"SHREYASHREE",fonts[3]);
        write_text(180,300,"",fonts[3]);
        write_text(220,400,"(4SN16CS089)",fonts[0]);
        write_text(680,400,"(4SN16CS190)",fonts[0]);

        write_text(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}
//fuction to draw draw circle
void drawfcircle(GLfloat x,GLfloat y,GLfloat radius){
	int i;
	int triangleAmount=200000;
	GLfloat twicePi=2.0f*3.141592653;
	glEnable(GL_POINTS);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	for(i=0;i<=triangleAmount;i++){
		glVertex2f(x,y);
		glVertex2f(x+(radius*cos(i*twicePi/triangleAmount)),y+(radius*sin(i*twicePi/triangleAmount)));
	}
	glEnd();
}
//helper function for drawing sphere
void sphere(float r, float g, float b, float a)
{
        glColor4f(r,g,b,a);
        glutSolidSphere(1,100,32);

}
//function to draw sheep legs
void drawLegs(){
  glColor3f(0.9,0.9,0.9);

  glBegin(GL_POLYGON);
	glColor3f(0.62,0.62,0.62);
	glVertex2f(400,300);
	glVertex2f(500,300);
  glVertex2f(500,500);
	glVertex2f(400,500);
	glEnd();

  glColor3f(0.4,0.4,0.4);
  glPushMatrix();
  glTranslatef(450,300,0);
  glScalef(60,30,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
}
//function to draw sheep
void drawSheep(){

  //legs
  glPushMatrix();
  glTranslatef(360,335,0);
  glScalef(0.1,0.5,0);
  drawLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(375,335,0);
  glScalef(0.1,0.5,0);
  drawLegs();
  glPopMatrix();

  //front legs
  glPushMatrix();
  glTranslatef(445,335,0);
  glScalef(0.1,0.5,0);
  drawLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(460,335,0);
  glScalef(0.1,0.5,0);
  drawLegs();
  glPopMatrix();

  glColor3f(0.9,0.9,0.9);

  glPushMatrix();
  glTranslatef(500,600,0);
  glScalef(60,50,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(520,650,0);
  glScalef(60,50,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(450,650,0);
  glScalef(60,50,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(420,600,0);
  glScalef(60,50,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(500,620,0);
  glScalef(60,50,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //head
  glColor3f(0.8,0.8,0.9);
  glPushMatrix();
  glTranslatef(580,620,0);
  glScalef(25,40,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //eyes
  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(570,620,0);
  glScalef(3,3,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(585,620,0);
  glScalef(3,3,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //ears
  glColor3f(0.7,0.7,0.7);
  glPushMatrix();
  glTranslatef(605,635,0);
  glScalef(15,8,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(555,635,0);
  glScalef(15,8,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
}
//function to draw boy legs
void drawBoyLegs(){
  glColor3f(0.9,0.9,0.9);
  glBegin(GL_POLYGON);
	glVertex2f(400,300);
	glVertex2f(500,300);
  glVertex2f(500,500);
	glVertex2f(400,500);
	glEnd();

  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(450,300,0);
  glScalef(60,30,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


}
//draw boy
void drawBoy(){
  //glColor3f(0.9,0.9,0.9);

  glPushMatrix();
  glTranslatef(370,-50,0);
  glScalef(0.1,1,0);
  drawBoyLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(430,-50,0);
  glScalef(0.1,1,0);
  drawBoyLegs();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(520,-100,0);
  glScalef(0.1,1,0);
  glRotatef(60,0,0,1);
  drawBoyLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(340,680,0);
  glScalef(0.1,1,0);
  glRotatef(-60,0,0,1);
  drawBoyLegs();
  glPopMatrix();

  glPushMatrix();
  glScalef(1,1.2,0);
  glBegin(GL_POLYGON);
	glColor3f(0.62,0.62,0.62);
	glVertex2f(400,300);
	glVertex2f(500,300);
  glVertex2f(500,500);
	glVertex2f(400,500);
	glEnd();
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(450,630,0);
  glScalef(35,35,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


  glColor3f(0.9,0.9,0.9);
  glPushMatrix();
  glTranslatef(450,620,0);
  glScalef(35,35,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(430,620,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(460,620,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(450,500,0);
  glScalef(1,91,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

}
//function to draw background
void background()
{
	glColor3f(0.5294117647,0.8078431373,0.9215686275);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(1000,0);
	glVertex2f(1000,1000);
	glVertex2f(0,1000);
  glEnd();
}
//fucntion to draw Tree
void drawTree(){
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
//function to draw trees
void drawTrees(){
  glPushMatrix();
  glTranslatef(-500,0,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-300,0,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-250,0,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-50,0,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(70,-500,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(350,-500,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400,-200,0);
  drawTree();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(500,-500,0);
  drawTree();
  glPopMatrix();

}
//function to draw fox legs
void drawFoxLegs(){
  glColor3f(0.874,0.552,0.227);
  glBegin(GL_POLYGON);
  glVertex2f(300,500);
  glVertex2f(500,0);
  glVertex2f(700,500);
  glEnd();

  glColor3f(0.4,0.4,0.4);
  glPushMatrix();
  glTranslatef(480,50,0);
  glScalef(60,30,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
}
//function to draw fox
void drawFox(){
  glColor3f(0.874,0.552,0.227);
  glBegin(GL_POLYGON);
  glVertex2f(300,400);
  glVertex2f(300,600);
  glVertex2f(800,600);
  glVertex2f(800,400);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(300,600);
  glVertex2f(100,500);
  glVertex2f(300,400);
  glEnd();

  glPushMatrix();
  glTranslatef(115,500,0);
  glScalef(40,30,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(250,500,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(280,500,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


  glPushMatrix();
  glTranslatef(320,180,0);
  glScalef(0.1,0.5,0);
  drawFoxLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(350,180,0);
  glScalef(0.1,0.5,0);
  drawFoxLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(600,180,0);
  glScalef(0.1,0.5,0);
  drawFoxLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(615,180,0);
  glScalef(0.1,0.5,0);
  drawFoxLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(800,180,0);
  glRotatef(60,0,0,1);
  glScalef(0.5,0.5,0);
  drawFoxLegs();
  glPopMatrix();


}
//backround scene
void scene(){
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


    //------------

    glPushMatrix();
    glScalef(4,5,0);
    glTranslatef(-100,-495,0);
    //lawn left extension
    glBegin(GL_POLYGON);
    glColor3f(0.19,0.80,0.19);
    glVertex2f(400,525);
    glVertex2f(400,575);
    glVertex2f(100,575);
    glVertex2f(100,525);
    glEnd();
    glPopMatrix();

    // //draw sun
    // glColor3f(1.0, 0.33, 0.0);
    // drawfcircle(400,800,50);


    //head


}//intro texts are here
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
  //Add story part-1 here
}
//intro
void scene1(){
  background();
  glPushMatrix();
  glTranslatef(-50,150,0);
  intro();
  glPopMatrix();
  glFlush();
}
//scene-1 boy watchiing over a sheeps
void scene2() {
  background();
  scene();
  //big rock
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(100,200,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0.2,0.2,0.2);
  glPushMatrix();
  glTranslatef(290,150,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //sheeps
  glPushMatrix();
  glTranslatef(1,1,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400,100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,200,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200+startx/10,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200+startx/10,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(-100+startx/5,270,0);
  drawBoy();
  glPopMatrix();

  glColor3f(1.0, 0.33, 0.0);
  drawfcircle(400,800,50);

  showStory();
  glColor3f(1,1,1);
  write_text(00,30,"Everyday a sheperd boy stayed on a hill watchiing villages sheeps His job was to make sure nothing",fonts[0]);
  write_text(00,10," bad happend to sheeps!",fonts[0]);


  //next page
  if(startx>300){
    state=2;
    startx=0;
  }else{
    startx++;
  }
  glFlush();
}
//scene-2 shouting wolf
void scene3(){
  background();
  scene();
  //big rock
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(100,200,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0.2,0.2,0.2);
  glPushMatrix();
  glTranslatef(290,150,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //sheeps
  glPushMatrix();
  glTranslatef(1,1,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400+startx/100,100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,200,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200+startx/10,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(-100,270,0);
  drawBoy();
  glPopMatrix();

  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(520,750,0);
  glScalef(130,80,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(370,750,0);
  glScalef(15,15,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(330,750,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();



  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(950-startx,120,0);
  drawBoy();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(800-startx,120,0);
  drawBoy();
  glPopMatrix();

  showStory();
  glColor3f(1,1,1);
  write_text(00,30,"One afternoon Boy decided play a trick on villagers Wolf wolf he cried. There's a wolf chasing the sheep",fonts[0]);
  write_text(00,10," ",fonts[0]);

  if(moveFlag==0)
  {
    glColor3f(1,1,1);
    write_text(400,730," Wolf ! Wolf ! Wolf",fonts[3]);
    if(startx<500){
      startx++;
    }else{
      glColor3f(1,1,1);
      write_text(400,730,"Nothing in here i'm just kiddig",fonts[3]);
      for(int i=0;i<100000000;i++){
        starty++;
        glPushMatrix();
        glTranslatef(starty,1,1);
        glPopMatrix();
      }
      moveFlag=1;
    }
  }else{
    glColor3f(1,1,1);
      write_text(400,730,"Nothing in here i'm just kiddig",fonts[3]);
      startx--;
      if(startx==300){
        startx=0;
        moveFlag=0;
        state=3;
      }
  }

  glFlush();

}
//scene-3 calling wolf prank again
void scene4(){
  background();
  scene();
  //big rock
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(100,200,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0.2,0.2,0.2);
  glPushMatrix();
  glTranslatef(290,150,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //sheeps
  glPushMatrix();
  glTranslatef(1,1,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400+startx/100,100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,200,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200+startx/10,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(-100,270,0);
  drawBoy();
  glPopMatrix();

  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(520,750,0);
  glScalef(130,80,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(370,750,0);
  glScalef(15,15,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(330,750,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();



  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(950-startx,120,0);
  drawBoy();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(800-startx,120,0);
  drawBoy();
  glPopMatrix();

  showStory();
  glColor3f(1,1,1);
  write_text(00,30,"The next day boy tried his trick again Wolf Wolf he called out .There is a wolf chading the sheeps",fonts[0]);
  write_text(00,10," ",fonts[0]);

  if(moveFlag==0)
  {
    glColor3f(1,1,1);
    write_text(400,730," Wolf ! Wolf ! Again",fonts[3]);
    if(startx<500){
      startx++;
    }else{
      glColor3f(1,1,1);
      write_text(400,730,"LOL i'm just kiddig",fonts[3]);
      for(int i=0;i<100000;i++){
        starty++;  write_text(00,10," ",fonts[0]);
        glPushMatrix();
        glTranslatef(starty,1,1);
        glPopMatrix();
      }
      moveFlag=1;
    }
  }else{
    glColor3f(1,1,1);
      write_text(400,730,"LOL i'm just kiddig",fonts[3]);
      startx--;
      if(startx==300){
        state=4;
        startx=0;
      }
  }

  glFlush();
}
//actual fox comes
void scene5(){
  background();
  scene();
  //big rock
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(100,200,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0.2,0.2,0.2);
  glPushMatrix();
  glTranslatef(290,150,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //sheeps
  glPushMatrix();
  glTranslatef(1,1,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400+startx/100,100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,200,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200-startx/10,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200,-100,0);
  glScalef(0.5,0.5,0);
  drawSheep();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(-100,270,0);
  drawBoy();
  glPopMatrix();

  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(520,750,0);
  glScalef(130,80,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(370,750,0);
  glScalef(15,15,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(330,750,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0,1,1);
  write_text(400,730,"wolf wolf Real Wolf!",fonts[3]);
  startx=startx+2;

  glPushMatrix();
  glScalef(0.5,0.5,0);
  glTranslatef(2000-startx,2,1);
  drawFox();
  glPopMatrix();

  if (startx==1400) {
    state=5;
    startx=0;
  }

  showStory();
  glColor3f(1,1,1);
  write_text(00,30,"One day the real wolf comes and boy calls out wolf but no one comes for help!",fonts[0]);
  write_text(00,10," ",fonts[0]);
  glFlush();

}
//scene-5  all sheeps died
void scene6(){
  background();
  scene();
  //big rock
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(100,200,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0.2,0.2,0.2);
  glPushMatrix();
  glTranslatef(290,150,0);
  glScalef(505,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glScalef(0.8,0.8,0);
  glTranslatef(-100,100,0);
  drawBoy();
  glPopMatrix();

  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(520,750,0);
  glScalef(130,80,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(370,700,0);
  glScalef(15,15,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(330,650,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glColor3f(0,1,1);
  write_text(400,730,"All the sheeps died",fonts[3]);


  glPushMatrix();
  glScalef(0.5,0.5,0);
  glTranslatef(2000-startx,2,1);
  drawFox();
  glPopMatrix();



  showStory();
  glColor3f(1,1,1);
  write_text(00,30,"The villagers came running again and found no sheep They advised him to not repeat this again, ",fonts[0]);
  write_text(00,10," ",fonts[0]);
  glFlush();

}
//scene-6 conclusion
void end(){
  glColor3f(0.2,0.1,0.5);
  glBegin(GL_POLYGON);
  glVertex2f(0,0);
  glVertex2f(0,1000);
  glVertex2f(1000,1000);
  glVertex2f(1000,0);
  glEnd();

  showStory();
  glColor3f(1,1,1);
  write_text(470,500,"The End",fonts[2]);
  //Add story conclusion here
  //end of the story
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

  if (state==3) {
    scene4();
  }

  if(state==4){
    scene5();
  }
  if(state==5){
    scene6();
  }

  if(state==6){
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
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("The Boy Who Cried Over Wolf");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
