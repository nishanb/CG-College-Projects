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
	gluOrtho2D(0,1200,0,1000);
  glMatrixMode(GL_MODELVIEW);
}

//keyboard function
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
}


//intro project details
void scene1(){

	 glColor3f(0.2,0.1,0.5);
	 glBegin(GL_POLYGON);
	 glVertex2f(0,0);
	 glVertex2f(0,1000);
	 glVertex2f(1200,1000);
	 glVertex2f(1200,0);
	 glEnd();
	
	 //project deatils
 	 glFlush();
}

//scene-1 
void scene2() {
  
  glFlush();
}

//scene-2 
void scene3(){

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
	glutCreateWindow("Project Name");
	glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
	glutMainLoop();
}
