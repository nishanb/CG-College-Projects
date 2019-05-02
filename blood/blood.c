#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
//to manage which scene to be displayed
int state=0,k,moveFlag=1;
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
int startx=0;
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
  if(state==7){
    state=7;
  }
  else{
    state++;
  }

  startx=0;



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
//function to draw outline and box
void drawOutline(){
  glColor3f(0.152,0.505,0.905);
  glBegin(GL_POLYGON);
  glVertex2f(200,200);
  glVertex2f(800,200);
  glVertex2f(800,800);
  glVertex2f(200,800);
  glEnd();

  glColor3f(0.2,0.2,0.2);
  glBegin(GL_POLYGON);
  glVertex2f(250,250);
  glVertex2f(750,250);
  glVertex2f(750,750);
  glVertex2f(250,750);
  glEnd();

  glColor3f(0.015,0.188,0.384);
  glPushMatrix();
  glTranslatef(500,500,0);
  glScalef(200,200,0);
  glutSolidSphere(1,100,10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-600,0);
  glColor3f(0,0,0);
  write_text(400,730,"Press Any Key to Continue",fonts[3]);
  glPopMatrix();

}
//draw blood cell
void drawBloodCell(){
    glColor3f(0.929, 0.070, 0.070);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(20,20,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.968, 0.372, 0.372);
    glPushMatrix();
    glTranslatef(500,510,0);
    glScalef(10,20,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.980, 0.666, 0.658);
    glPushMatrix();
    glTranslatef(510,490,0);
    glScalef(10,20,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();
}
//draw blood cell isotonic
void drawIsoTonicBloodCell(){
    glColor3f(0.929, 0.070, 0.070);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(20,20,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.972, 0.576, 0.568);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(15,15,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.972, 0.576, 0.568);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(15,12,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

}
//draw hypo tonic blood cells
void drawHypoTonicBloodCell(){
    glColor3f(0.929, 0.070, 0.070);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(25,20,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.972, 0.576, 0.568);
    glPushMatrix();
    glTranslatef(510,510,0);
    glScalef(15,15,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0.972, 0.576, 0.568);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(15,12,0);
    glutSolidSphere(1,100,10);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(500,500,0);
    glScalef(5,5,0);
    glutSolidSphere(1,100,10);
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
  char str8[] = "Name And Usn";
  for (k = 0; k < strlen(str8); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str8[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 240);
  char str9[] = "Name and USn";
  for (k = 0; k < strlen(str9); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[k]);
  }

  glColor3f(0.6, 0.6, 0);
  glRasterPos2f(50, 200);
  char str10[] = "DEPT OF CSE";
  for (k = 0; k < strlen(str10); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str10[k]);
  }

  glPushMatrix();
  glTranslatef(-200,0,0);
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
  glPopMatrix();


  glPushMatrix();
  glTranslatef(-100,0,0);
  glColor3f(1, 0,0);
  glRasterPos2f(450, 130);
  char str15[] = "PRESS ANY KEY TO CONTINUE";
  for (k = 0; k < strlen(str15); k++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str15[k]);
  }
  glPopMatrix();

  glFlush();
}
//scene-1 state-1
void scene2() {

  drawOutline();

  if(startx%45==0){
    moveFlag*=-1;
  }
  if(moveFlag==1)
    startx=startx+1;
  else
    startx=startx-1;

  glPushMatrix();
  glTranslatef(-100,100-startx/2,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0-startx,100,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10-startx,-100,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100,70-startx,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20+startx,20,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,0+startx,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(00+startx,-70,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,-100-startx,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100+startx,-10,0);
  glScalef(1,1,0);
  drawBloodCell();
  glPopMatrix();

  //blod cell ends

  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(0,0,0);
  write_text(400,730,"Stage-1 Hyper Tonic",fonts[3]);
  glPopMatrix();

  glFlush();
}
//scene1-showStory
void scene2x(){
  background();

  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(1,0,0);
  write_text(410,500,"HYPER TONIC ",fonts[2]);
  write_text(410,450,"Concentration of ",fonts[0]);
  write_text(200,400,"Solute MoleCules OUTSIDE the cell > Solute MoleCules INSIDE the Cell",fonts[3]);
  write_text(330,350,"Consequence : The Shell SHRINKS.",fonts[0]);
  glPopMatrix();
}
//scene-2 state-2
void scene3(){
  drawOutline();

  if(startx%45==0){
    moveFlag*=-1;
  }
  if(moveFlag==1)
    startx=startx+1;
  else
    startx=startx-1;

  glPushMatrix();
  glTranslatef(-100,100-startx/2,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0-startx,100,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0-startx,100,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100,70-startx,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20+startx,20,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,0+startx,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(00+startx,-70,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,-100-startx,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100+startx,-10,0);
  glScalef(1,1,0);
  drawIsoTonicBloodCell();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(0,0,0);
  write_text(400,730,"Stage-2 Iso Tonic",fonts[3]);
  glPopMatrix();

  glFlush();


}
//scene2-showStory
void scene3x(){
  background();

  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(1,0,0);
  write_text(410,500,"ISO TONIC ",fonts[2]);
  write_text(410,450,"Concentration of ",fonts[0]);
  write_text(200,400,"Solute MoleCules OUTSIDE the cell = Solute MoleCules INSIDE the Cell",fonts[3]);
  //write_text(330,350,"Consequence : The Shell SHRINKS.",fonts[0]);
  glPopMatrix();
}
//scene-3 state-3
void scene4(){
  drawOutline();

  if(startx%45==0){
    moveFlag*=-1;
  }
  if(moveFlag==1)
    startx=startx+1;
  else
    startx=startx-1;

  glPushMatrix();
  glTranslatef(-100,100-startx/2,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0-startx,100,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(0-startx,100,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100,70-startx,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20+startx,20,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,0+startx,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(00+startx,-70,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-100,-100-startx,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100+startx,-10,0);
  glScalef(1,1,0);
  drawHypoTonicBloodCell();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(0,0,0);
  write_text(400,730,"Stage-3 Hypo Tonic",fonts[3]);
  glPopMatrix();

  glFlush();

}
//scene3-showStory
void scene4x(){
  background();

  glPushMatrix();
  glTranslatef(0,100,0);
  glColor3f(1,0,0);
  write_text(410,500,"HYPO TONIC ",fonts[2]);
  write_text(410,450,"Concentration of ",fonts[0]);
  write_text(200,400,"Solute MoleCules OUTSIDE the cell < Solute MoleCules INSIDE the Cell",fonts[3]);
  write_text(330,350,"Consequence : The Shell SWELLS.",fonts[0]);
  glPopMatrix();
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
    scene2x();
  }

  if (state==3) {
    scene3();
  }

  if(state==4){
    scene3x();
  }

  if(state==5){
    scene4();
  }
  if(state==6){
    scene4x();
  }
  if(state==7){
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
	glutCreateWindow("BLOOD CELL OSMOSIS");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
