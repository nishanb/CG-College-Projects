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
  if(state==2){
      state=3;
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
//function to draw cloud
void drawClouds(){
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

void backg1(){
  background();

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
    glPushMatrix();
    glTranslatef(-20,0,0);
    glColor3f(1.0, 0.33, 0.0);
    glTranslatef(320,850,0);
    glScalef(50,50,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();
    // drawfcircle(400,800,50);

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(450,-100,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(650,-400,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(1150,-150,0);
    drawTrees();
    glPopMatrix();

    //head
}
void backg2(){
  background();

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
    glPushMatrix();
    glTranslatef(-20,0,0);
    glColor3f(1.0, 0.33, 0.0);
    glTranslatef(320,850,0);
    glScalef(50,50,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();
    // drawfcircle(400,800,50);

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(450,-100,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(650,-400,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(1150,-150,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(150,-400,0);
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(-50,-250,0);
    drawTrees();
    glPopMatrix();

    //head
}
//part1
void part1(){
  glBegin(GL_POLYGON);
  glColor3f(0.964, 0.525, 0.454);
  glVertex2f(100,100);
  glVertex2f(200,20);
  glVertex2f(600,100);
  glVertex2f(600,400);
  glVertex2f(100,500);
  glEnd();
}
//part2
void part2(){
  glBegin(GL_POLYGON);
  glColor3f(0.964, 0.525, 0.454);
  glVertex2f(100,0);
  glVertex2f(300,50);
  glVertex2f(600,100);
  glVertex2f(590,500);
  glVertex2f(350,450);
  glVertex2f(250,200);
  glVertex2f(100,130);
  glEnd();
}
//part3
void part3(){
  glBegin(GL_POLYGON);
  glColor3f(0.964, 0.525, 0.454);
  glVertex2f(100,100);
  glVertex2f(300,200);
  glVertex2f(500,70);
  glVertex2f(600,100);
  glVertex2f(600,500);
  glVertex2f(500,600);
  glVertex2f(300,550);
  glVertex2f(90,500);
  glEnd();
}
//eyes
void drawEyes(/* arguments */) {
  /* code */
  glPushMatrix();
  glTranslatef(-20,0,0);
  glColor3f(0, 0, 0.2);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(1, 1, 1);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPopMatrix();

  glPushMatrix();
  glTranslatef(30,0,0);
  glColor3f(0, 0, 0.2);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(10,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(1, 1, 1);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(5,5,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPopMatrix();
}
//drawLegs
void drawLegs(/* arguments */) {
  /* code */
  glBegin(GL_POLYGON);
  glColor3f(0.5,0.5,0.5);
  glVertex2f(100,320);
  glVertex2f(200,100);
  glVertex2f(350,200);
  glVertex2f(500,400);
  glVertex2f(400,600);
  glVertex2f(320,320);
  glVertex2f(220,220);
  glVertex2f(150,350);
  glEnd();


}
//drawArms
void drawArms(/* arguments */) {
  /* code */
  glPushMatrix();

  glTranslatef(500,390,0);
  glRotatef(-50,0,0,1);
  glScalef(0.50,0.2,0);
  drawLegs();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(640,210,0);
  glRotatef(10,0,0,1);
  glScalef(0.50,0.2,0);
  drawLegs();
  glPopMatrix();

  glColor3f(0.1, 0.1, 0.1);
  glPushMatrix();
  glTranslatef(830,330,0);
  glScalef(35,35,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();
}
//draw Hanuman
void drawHanuman(){

  //drawArms
  glPushMatrix();
  glTranslatef(100,351,0);
  glScalef(1,1,0);
  glRotatef(-30,0,0,1);
  drawArms();
  glPopMatrix();

  //drawLegs
  glPushMatrix();
  glTranslatef(1000,251,0);
  glScalef(1,1,0);
  glRotatef(140,0,0,1);
  drawArms();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1000,321,0);
  glScalef(1,1,0);
  glRotatef(140,0,0,1);
  drawArms();
  glPopMatrix();

  //drawArms
  glPushMatrix();
  glTranslatef(200,451,0);
  glScalef(1,1,0);
  glRotatef(-30,0,0,1);
  drawArms();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(70,430,0);
  glRotatef(-50,0,0,1);
  glScalef(0.40,0.1,0);
  drawLegs();
  glPopMatrix();

  //part1
  glPushMatrix();
  glTranslatef(400,300,0);
  glScalef(0.5,0.5,0);
  part1();
  glPopMatrix();

  //part 2
  glPushMatrix();
  glTranslatef(160,300,0);
  glScalef(0.5,0.5,0);
  part2();
  glPopMatrix();

  //part3
  glPushMatrix();
  glTranslatef(600,320,0);
  glScalef(0.5,0.35,0);
  part3();
  glPopMatrix();

  //head
  glColor3f(0.952, 0.803, 0.168);
  glPushMatrix();
  glTranslatef(920,500,0);
  glScalef(70,70,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0.9, 0.2, 0.2);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(70,70,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //eyes
  drawEyes();

  //ears
  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(850,490,0);
  glScalef(20,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(990,490,0);
  glScalef(20,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //holder
  glPushMatrix();
  glColor3f(0,0,0);
  glScalef(0.5,2,0);
  glTranslatef(2100,10,0);
  glRotatef(120,0,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(100,100);
  glVertex2f(150,100);
  glVertex2f(150,400);
  glVertex2f(100,400);
  glEnd();
  glPopMatrix();

  glColor3f(0.952, 0.803, 0.168);
  glPushMatrix();
  glTranslatef(900,370,0);
  glScalef(40,40,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


  glColor3f(0.952, 0.576, 0.168);
  glPushMatrix();
  glScalef(0.7,0.7,1);
  glTranslatef(1350,380,0);
  glBegin(GL_POLYGON);
  glVertex2f(100,100);
  glVertex2f(300,100);
  glVertex2f(200,300);
  glEnd();
  glPopMatrix();




}

//draw Hanuman
void drawHanumanStanding(){

  //drawArms
  glPushMatrix();
  glTranslatef(100,351,0);
  glScalef(1,1,0);
  glRotatef(-30,0,0,1);
  drawArms();
  glPopMatrix();

  //drawLegs
  glPushMatrix();
  glTranslatef(1000,211,0);
  glScalef(1,1,0);
  glRotatef(140,0,0,1);
  drawArms();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1000,321,0);
  glScalef(1,1,0);
  glRotatef(140,0,0,1);
  drawArms();
  glPopMatrix();

  //drawArms
  glPushMatrix();
  glTranslatef(200,451,0);
  glScalef(1,1,0);
  glRotatef(-30,0,0,1);
  drawArms();
  glPopMatrix();



  //part1
  glPushMatrix();
  glTranslatef(400,300,0);
  glScalef(0.5,0.5,0);
  part1();
  glPopMatrix();

  //part 2
  glPushMatrix();
  glTranslatef(160,300,0);
  glScalef(0.5,0.5,0);
  part2();
  glPopMatrix();

  //part3
  glPushMatrix();
  glTranslatef(600,320,0);
  glScalef(0.5,0.35,0);
  part3();
  glPopMatrix();

  //head
  glColor3f(0.952, 0.803, 0.168);
  glPushMatrix();
  glTranslatef(940,490,0);
  glScalef(70,70,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(0.9, 0.2, 0.2);
  glPushMatrix();
  glTranslatef(920,490,0);
  glScalef(70,70,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();



  //ears
  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(930,550,0);
  glScalef(20,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(930,430,0);
  glScalef(20,10,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  //holder
  glPushMatrix();
  glColor3f(0,0,0);
  glScalef(0.5,2,0);
  glTranslatef(2100,10,0);
  glRotatef(120,0,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(100,100);
  glVertex2f(150,100);
  glVertex2f(150,400);
  glVertex2f(100,400);
  glEnd();
  glPopMatrix();

  glColor3f(0.952, 0.803, 0.168);
  glPushMatrix();
  glTranslatef(900,370,0);
  glScalef(40,40,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();


  glColor3f(0.952, 0.576, 0.168);
  glPushMatrix();
  glScalef(0.7,0.7,1);
  glTranslatef(1550,250,0);
  glRotatef(30,0,0,1);
  glBegin(GL_POLYGON);
  glVertex2f(100,100);
  glVertex2f(300,100);
  glVertex2f(200,300);
  glEnd();
  glPopMatrix();

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
  char str6[] = "HANUMAN AND SANJEEVINI";
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
  char str8[] = "Name USN";
  for (k = 0; k < strlen(str8); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str8[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 240);
  char str9[] = "Name USN";
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
  backg1();

  glPushMatrix();
  glTranslatef(100-startx/10,100,0);
  drawClouds();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(500+startx/10,140,0);
  drawClouds();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-400+startx/10,-40,0);
  drawClouds();
  glPopMatrix();

  startx++;
  if(startx==350){
    state=2;
    startx=0;
  }
  glPushMatrix();
  glScalef(0.5,0.5,1);
  glTranslatef(700,0,0);
  glRotatef(90,0,0,1);
  drawHanumanStanding();
  glPopMatrix();

  //eyes
  glPushMatrix();
  glScalef(0.7,0.7,1);
  glTranslatef(-780,180,0);
  drawEyes();
  glPopMatrix();

  glFlush();
}
//scene-2 walking towards apple tree
void scene3(){

  backg2();

  glPushMatrix();
  glTranslatef(100-startx/10,100,0);
  drawClouds();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(500+startx/10,140,0);
  drawClouds();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-400+startx/10,-40,0);
  drawClouds();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-800+startx,500,0);
  glScalef(0.5,0.5,1);
  drawHanuman();
  glPopMatrix();

  if(startx<2500)
    startx++;

  if(startx==1000){
    state=3;
  }
  glFlush();

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
	glutCreateWindow("HANUMAN AND SANJEEVINI");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
