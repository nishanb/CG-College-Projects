#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

//to manage which scene to be displayed
int state=0,k;

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
float startx=0;
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
	gluOrtho2D(0,1200,0,1000);
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
  if(state==4){
      state=5;
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
  //Add story part-1 here
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
}

//function for the background
void background()
{
	glColor3f(0.5294117647,0.8078431373,0.9215686275);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(1200,0);
	glVertex2f(1200,1000);
	glVertex2f(0,1000);
  glEnd();
}

//function to draw person
void drawPerson(){
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(850, 100); //left leg
  glVertex2i(850, 80);
  glVertex2i(910, 80);
  glVertex2i(910, 100);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(935, 200);
  glVertex2i(875, 100); //left leg
  glVertex2i(910, 100);
  glVertex2i(960, 200);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(970, 80);
  glVertex2i(970, 100); //right leg
  glVertex2i(1015, 100);
  glVertex2i(1015, 80);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(995, 100);
  glVertex2i(1015, 100); //right leg
  glVertex2i(1015, 200);
  glVertex2i(995, 200);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(885, 185);
  glVertex2i(870, 200); //front hand
  glVertex2i(985, 310);
  glVertex2i(1005, 305);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(1080, 185);
  glVertex2i(1085, 205);
  glVertex2i(1025, 250); //back hand
  glVertex2i(1025, 230);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(950, 310);
  glVertex2i(925, 275);
  glVertex2i(925, 200); //body
  glVertex2i(1025, 200);
  glVertex2i(1025, 275);
  glVertex2i(1000, 310);
  glEnd();
  glFlush();

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(950, 400);
  glVertex2i(915, 365);
  glVertex2i(925, 370);
  glVertex2i(925, 350);
  glVertex2i(935, 350); //face
  glVertex2i(925, 340);
  glVertex2i(950, 310);
  glVertex2i(1000, 310);
  glVertex2i(1025, 335);
  glVertex2i(1025, 375);
  glVertex2i(1000, 400);
  glEnd();
  glFlush();

  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  glVertex2i(950, 400);
  glVertex2i(960, 415);
  glVertex2i(1005, 415); //hair
  glVertex2i(1025, 400);
  glVertex2i(1025, 375);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(900, 140);
  glVertex2i(935, 140);
  glVertex2i(965, 200); // front
  glVertex2i(930, 200);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(990, 200);
  glVertex2i(990, 140); // back
  glVertex2i(1020, 140);
  glVertex2i(1020, 200);
  glEnd();

  glColor3f(01,01,01);
  glPushMatrix();
  glTranslatef(960,350,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(980,350,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(970,330,0);
  glScalef(20,2,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
}

//scene1 background
void drawHouse(){


  glColor3f(0, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(0, 0);
  glVertex2i(1200, 0);
  glVertex2i(1200, 400);
  glVertex2i(0, 400);
  glEnd();
  glFlush();

  glColor3f(0, 1, 1);
  glBegin(GL_POLYGON);
  glVertex2i(0, 400);
  glVertex2i(0, 1000);
  glVertex2i(1200, 1000);
  glVertex2i(1200, 400);
  glEnd();
  glFlush();

  glPushMatrix();
  glTranslatef(100,-100,0);
  drawTrees();
  glPopMatrix();


}

//apple tree and the background
void drawAppleTree(){
  glColor3f(0, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(0, 400);
  glVertex2i(1200, 400); //grass
  glVertex2i(1200, 0);
  glVertex2i(0, 0);
  glEnd();
  glFlush();

  glColor3f(0, 1, 0.2);
  glPushMatrix();
  glTranslatef(100,-100,0);
  glScalef(605,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0, 1, 1);
  glBegin(GL_POLYGON);
  glVertex2i(0, 1000);
  glVertex2i(1200, 1000); //sky
  glVertex2i(1200, 400);
  glVertex2i(0, 400);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.4, 0);
  glBegin(GL_POLYGON);
  glVertex2i(150, 125);
  glVertex2i(150, 325); //root tree
  glVertex2i(175, 300);
  glVertex2i(200, 325);
  glVertex2i(200, 125);
  glVertex2i(225, 100);
  glVertex2i(125, 100);
  glEnd();
  glFlush();

  glColor3f(0, 0.5, 0);
  glBegin(GL_POLYGON);
  glVertex2i(150, 285);
  glVertex2i(130, 315);
  glVertex2i(125, 300);
  glVertex2i(90, 335);
  glVertex2i(100, 360);
  glVertex2i(80, 385);
  glVertex2i(85, 420);
  glVertex2i(95, 420);
  glVertex2i(90, 500);
  glVertex2i(100, 475);
  glVertex2i(110, 480);
  glVertex2i(100, 500);
  glVertex2i(110, 525);
  glVertex2i(120, 520);
  glVertex2i(140, 550);
  glVertex2i(110, 575);
  glVertex2i(155, 565);
  glVertex2i(145, 595);
  glVertex2i(195, 575);
  glVertex2i(190, 590);
  glVertex2i(215, 575);
  glVertex2i(215, 550);
  glVertex2i(230, 565);
  glVertex2i(245, 540);
  glVertex2i(265, 550);
  glVertex2i(280, 525);
  glVertex2i(275, 510);
  glVertex2i(290, 500);
  glVertex2i(300, 475);
  glVertex2i(315, 455);
  glVertex2i(315, 430);
  glVertex2i(295, 425);
  glVertex2i(290, 400); //tree
  glVertex2i(275, 380);
  glVertex2i(265, 350);
  glVertex2i(265, 320);
  glVertex2i(245, 300);
  glVertex2i(240, 315);
  glVertex2i(230, 305);
  glVertex2i(230, 295);
  glVertex2i(210, 270);
  glVertex2i(200, 305);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(225, 280);
  glVertex2i(215, 270);
  glVertex2i(215, 255);
  glVertex2i(225, 250);
  glVertex2i(245, 250); //apple down
  glVertex2i(255, 260);
  glVertex2i(255, 275);
  glVertex2i(245, 280);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.4, 0);
  glBegin(GL_LINES);
  glVertex2i(230, 295);
  glVertex2i(230, 280);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(300, 410);
  glVertex2i(290, 400);
  glVertex2i(290, 380);
  glVertex2i(300, 370);
  glVertex2i(325, 370); //apple right
  glVertex2i(340, 380);
  glVertex2i(340, 400);
  glVertex2i(330, 410);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.4, 0);
  glBegin(GL_LINES);
  glVertex2i(310, 430);
  glVertex2i(310, 410);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(230, 525);
  glVertex2i(220, 520);
  glVertex2i(220, 500);
  glVertex2i(230, 495);
  glVertex2i(250, 495);
  glVertex2i(255, 505); //apple up
  glVertex2i(255, 515);
  glVertex2i(250, 525);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.4, 0);
  glBegin(GL_LINES);
  glVertex2i(240, 525);
  glVertex2i(240, 545);
  glEnd();
  glFlush();

  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(95, 470);
  glVertex2i(85, 460);
  glVertex2i(85, 445);
  glVertex2i(95, 440);
  glVertex2i(120, 440); //apple left
  glVertex2i(125, 450);
  glVertex2i(125, 460);
  glVertex2i(120, 470);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.4, 0);
  glBegin(GL_LINES);
  glVertex2i(105, 480);
  glVertex2i(105, 470);
  glEnd();
  glFlush();



}

//person sitting
void drawSittingerson(){
  glColor3f(0.9, 0.4, 0);
  glBegin(GL_LINES);
  glVertex2i(105, 480);
  glVertex2i(105, 470);
  glEnd();
  glFlush();

  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(225, 225);
  glVertex2i(215, 205);
  glVertex2i(215, 190);
  glVertex2i(225, 180); //sitting
  glVertex2i(250, 180);
  glVertex2i(255, 185);
  glVertex2i(250, 190);
  glVertex2i(255, 190); //face
  glVertex2i(255, 200);
  glVertex2i(250, 200);
  glVertex2i(250, 215);
  glEnd();
  glFlush();

  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(225, 180);
  glVertex2i(210, 165); //body
  glVertex2i(210, 125);
  glVertex2i(265, 125);
  glVertex2i(265, 160);
  glVertex2i(250, 180);
  glEnd();
  glFlush();

  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(220, 170);
  glVertex2i(215, 165); //hand front
  glVertex2i(270, 135);
  glVertex2i(275, 140);
  glEnd();
  glFlush();

  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(260, 165);
  glVertex2i(270, 165); //hand back
  glVertex2i(275, 165);
  glVertex2i(255, 175);
  glEnd();
  glFlush();

  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  glVertex2i(265, 130);
  glVertex2i(265, 140); //leg
  glVertex2i(280, 140);
  glVertex2i(285, 150);
  glVertex2i(285, 145);
  glVertex2i(295, 145);
  glVertex2i(295, 140);
  glVertex2i(280, 145);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.7, 0.4);
  glBegin(GL_POLYGON);
  glVertex2i(265, 160);
  glVertex2i(265, 150); //leg
  glVertex2i(290, 170);
  glVertex2i(290, 165);
  glVertex2i(295, 160);
  glVertex2i(295, 155);
  glVertex2i(255, 140);
  glVertex2i(255, 145);
  glEnd();
  glFlush();
}

//intro project details
void scene1(){

  background();


  char str1[] = "SRINIVAS INSTITUTE OF TECHNOLOGY";
  glColor3f(0, 1, 1);
  glRasterPos2f(380, 855);
  for (k = 0; k < strlen(str1); k++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[k]);
  }
  glColor3f(0, 1, 1);
  glRasterPos2f(530, 810);
  char str2[] = "MANGALURU-574143";
  for (k = 0; k < strlen(str2); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[k]);
  }

  glColor3f(1, 0.5, 0.2);
  glRasterPos2f(265, 700);
  char str3[] = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
  for (k = 0; k < strlen(str3); k++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[k]);
  }

  glColor3f(0.8, 0.3, 0.4);
  glRasterPos2f(330, 630);
  char str4[] = "COMPUTER GRAPHICS AND VISUALIZATION";
  for (k = 0; k < strlen(str4); k++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[k]);
  }

  glColor3f(0.3, 0.5, 0.1);
  glRasterPos2f(520, 560);
  char str5[] = "MINI PROJECT ON";
  for (k = 0; k < strlen(str5); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str5[k]);
  }

  glColor3f(1, 0, 0);
  glRasterPos2f(465, 490);
  char str6[] = "DISCOVERY OF GRAVITY";
  for (k = 0; k < strlen(str6); k++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 320);
  char str7[] = "TEAM MEMBERS";
  for (k = 0; k < strlen(str7); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str7[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 280);
  char str8[] = "NIRISHA-4SN16CS062";
  for (k = 0; k < strlen(str8); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str8[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 240);
  char str9[] = "SHWETHA A-4SN16CS091";
  for (k = 0; k < strlen(str9); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 200);
  char str10[] = "DEPT OF CSE";
  for (k = 0; k < strlen(str10); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str10[k]);
  }

  glColor3f(0.8, 0.5, 0);
  glRasterPos2f(950, 320);
  char str11[] = "PROJECT GUIDED BY";
  for (k = 0; k < strlen(str11); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[k]);
  }

  glColor3f(0.8, 0.5, 0);
  glRasterPos2f(950, 280);
  char str12[] = "MR.ARAVIND NAIK ";
  for (k = 0; k < strlen(str12); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str12[k]);
  }

  glColor3f(0.8, 0.5, 0);
  glRasterPos2f(950, 240);
  char str13[] = "ASSISTANT PROFESSOR";
  for (k = 0; k < strlen(str13); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str13[k]);
  }

  glColor3f(0.8, 0.5, 0);
  glRasterPos2f(950, 200);
  char str14[] = "DEPT OF CSE";
  for (k = 0; k < strlen(str14); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str14[k]);
  }

  glColor3f(1, 0,0);
  glRasterPos2f(450, 130);
  char str15[] = "PRESS ANY KEY TO CONTINUE";
  for (k = 0; k < strlen(str15); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str15[k]);
  }

  glFlush();
}
//scene-1 newton walking house <-----
void scene2() {
  glClear(GL_COLOR_BUFFER_BIT);

  drawHouse();

  glColor3f(0, 1, 0.2);
  glPushMatrix();
  glTranslatef(100,-100,0);
  glScalef(605,400,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(60-startx,100,0);
  drawPerson();
  glPopMatrix();



    glPushMatrix();
    glTranslatef(60,-180,0);
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(600, 300);
    glVertex2i(600, 550);
    glVertex2i(800, 550);
    glVertex2i(800, 300);
    glEnd();
    glFlush();


    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(600, 550);
    glVertex2i(700, 700);
    glVertex2i(800, 550);
    glEnd();
    glFlush();

    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(800, 550);
    glVertex2i(800, 300);
    glVertex2i(1100, 300);
    glVertex2i(1100, 550);
    glEnd();
    glFlush();


    glColor3f(0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(800, 550);
    glVertex2i(700, 700);
    glVertex2i(1100, 700);
    glVertex2i(1100, 550);
    glEnd();
    glFlush();

    glColor3f(0, 0.1, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(850, 300);
    glVertex2i(1000, 300);
    glVertex2i(1000, 450);
    glVertex2i(850, 450);
    glEnd();
  glPopMatrix();






  startx++;

  if(startx==800){
    state=2;
    startx=0;
  }
  glFlush();
}
//scene-2 walking towards apple tree
void scene3(){
  drawAppleTree();

  glPushMatrix();
  glTranslatef(400,-100,0);
  drawTrees();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(300-startx,100,0);
  drawPerson();
  glPopMatrix();

  startx++;

  if(startx==800){
    state=3;
    startx=0;
  }

  glFlush();

}
//scene-3
void scene4(){

  drawAppleTree();

  glPushMatrix();
  drawSittingerson();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400,-100,0);
  drawTrees();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(600,-100,0);
  drawTrees();
  glPopMatrix();



  if(startx>-200){
      startx=startx-0.4;
  }else{
    glPushMatrix();
    glTranslatef(-50,-400,0);
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
    write_text(400,730,"There is a Gravity!!!!",fonts[3]);
    glPopMatrix();

    state=4;
  }
  if(startx>-300){
    // state=4;
  }

  glPushMatrix();
  glTranslatef(-100,startx+100,0);
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(320, 320);
  glVertex2i(320, 335);
  glVertex2i(325, 340);
  glVertex2i(335, 340);
  glVertex2i(345, 340);
  glVertex2i(350, 335); //apple
  glVertex2i(350, 320);
  glVertex2i(345, 315);
  glVertex2i(325, 315);
  glEnd();
  glPopMatrix();


  glFlush();

}
//scene-5
void scene5(){
  drawAppleTree();

  glPushMatrix();
  glTranslatef(400,-100,0);
  drawTrees();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-300,100,0);
  drawPerson();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(400,400,0);
  glColor3f(0.1,0.1,0.1);
  glPushMatrix();
  glTranslatef(400,100,0);
  glBegin(GL_POLYGON);
  glVertex2f(0,0);
  glVertex2f(100,0);
  glVertex2f(100,100);
  glVertex2f(0,100);
  glEnd();
  glPopMatrix();

  glColor3f(0.941,0.796,0.098);
  glPushMatrix();
  glTranslatef(450,250,0);
  glScalef(70,100,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
  glPopMatrix();

  //drawAppleTree
  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(410,-150,0);
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
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glColor3f(0,0,1);
  glTranslatef(400,-100,0);
  write_text(400,730," Gravity!!!!",fonts[3]);
  glPopMatrix();

  glFlush();
}
//scene-4 conclusion
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

  if (state==3) {
    scene4();
  }

  if(state==4){
    scene5();
  }

  if(state==5){
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
	glutCreateWindow("Newtons Gravity");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
