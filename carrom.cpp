// #include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

// #include <gl/Gl.h>
// #include <gl/Glu.h>
// #include <gl/glut.h>
#include <math.h>
// #include <iostream.h>
// #include <fstream.h>

void myIdle();
void myDisplay();
 
struct stick
{
float x,y,z;
} ;
 
struct T3D
{
stick position;
stick velocity;
};
T3D stic;

struct TVector
{
float x,y,z;
};
 
struct TObject3D
{
TVector position;
TVector velocity;
};
 
TObject3D sphere;
 
GLfloat gAngle = 0.0; 
#define FRICTION 0.2
#define PI 3.14159565;
int enter= 0 ;
int flagup=0,flagdown=0,flag=0;
void RunPhysics(float dt)
{
	float v=3;
	double theta=int(gAngle)%360;
	theta=theta*3.14159565/180;
	if (enter==1){
		// double theta=(gAngle%360.00)*PI/180;
		sphere.velocity.x=v*cos(theta);
		sphere.velocity.y=v*sin(theta);
		// sphere.velocity.y=1.5;
		enter=0;
		flag=1;
		
	}


	if (sphere.velocity.y>0)
		sphere.velocity.y=sphere.velocity.y-FRICTION*dt;
	if (sphere.velocity.y<0)
		sphere.velocity.y=sphere.velocity.y+FRICTION*dt;
	if (sphere.velocity.x>0)
		sphere.velocity.x=sphere.velocity.x-FRICTION*dt;
	if (sphere.velocity.x<0)
		sphere.velocity.x=sphere.velocity.x+FRICTION*dt;

	// sphere.velocity.y=sphere.velocity.y-FRICTION*dt;
	// sphere.velocity.x=sphere.velocity.x-FRICTION*dt; 
	

	if ((sphere.position.x<=-0.9) || (sphere.position.x>=1.9)){

		sphere.velocity.x=-sphere.velocity.x;
		// sphere.velocity.x=sphere.velocity.x*0.99;
		// sphere.velocity.y=sphere.velocity.y*0.99;
	}
			
	if ((sphere.position.y<=-1.9) || (sphere.position.y>=0.9)){

		sphere.velocity.y=-sphere.velocity.y;
		// sphere.velocity.y=sphere.velocity.y*0.99;
		// sphere.velocity.x=sphere.velocity.x*0.99;
	}		


 	sphere.position.x=sphere.position.x+sphere.velocity.x*dt;
	sphere.position.y=sphere.position.y+sphere.velocity.y*dt;
	sphere.position.z=sphere.position.z+sphere.velocity.z*dt;
 	
	// if (sphere.velocity.y<0)
	// {
	 
	// 	if (sphere.position.y<0.5)
	// 	{
			 
	// 		if ((sphere.position.x>-2) && (sphere.position.x<-1.2))
	// 			sphere.velocity.y=-sphere.velocity.y;
	// 	}
			 
	// 	if (sphere.position.y<-0.9) 
	// 		sphere.velocity.y=-sphere.velocity.y;
			 
	// } 


 
}
 
void myInit()
{
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	gluPerspective(60.0, 64/48.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(0,0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	 
	glColor3d(0,0,0);
}
 
void myIdle()
{
RunPhysics(0.01);
myDisplay();
 
}
 
void myDisplay(void)
{
 
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP); // Draw Platform
	glVertex3d(2.0,-2.0,0.0);
	glVertex3d(2.0,1.0,0.0);
	glVertex3d(-1.0,1.0,0.0);
	glVertex3d(-1.0,-2.0,0.0);

 
glEnd();
glPushMatrix();
if (flag==0){
	gAngle+=1;
	glRotatef(gAngle,0,0,1);
}
// if (flagup==1){
// 	printf("aa");
// 	gAngle+=20;
// 	glRotatef(gAngle,0,0,1);
// 	flagup=0;
// 	}
// if (flagdown==1){
// 	printf("ll");
// 	gAngle-=20;
// 	glRotatef(gAngle,0,0,1);
// 	flagdown=0;
// 	}
// gAngle	


float a=gAngle;
printf("%f\n",a);

glBegin(GL_LINES);

    glVertex3f(-.4,0,0);
    glVertex3f(-2.00,0.00,0);

    
glEnd();  


glPopMatrix();
glPushMatrix(); // draw and place Sphere
glTranslated(sphere.position.x,sphere.position.y,sphere.position.z);
 
glutSolidSphere(0.15, 8, 8);
glPopMatrix();
 
 
glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	// if (key == 27)
	// 	exit(1);
	if (key == 27)
		enter=1;

}

void specialKeyboard(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		flagup=1;
		break;
	case GLUT_KEY_DOWN:
		flagdown=1;
		break;
	// 	glRotatef(gAngle,0,0,1);
	// 	gAngle+=1;


	// case GLUT_KEY_F1:
	// 	fullscreen = !fullscreen;
	// 	if (fullscreen)
	// 		glutFullScreen();
	// 	else
	// 	{
	// 		glutReshapeWindow(500, 500);
	// 		glutPositionWindow(50, 50);
	// 	}
		
	}
}
 
int main(int argc, char **argv)
{
sphere.position.x=0.0;
sphere.position.y=0.0;
sphere.position.z=0.0;

sphere.velocity.x=0.0;
sphere.velocity.y=0.0;
sphere.velocity.z=0;
 
 
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
glutInitWindowSize(640,480);
glutInitWindowPosition(50, 50);
glutCreateWindow("Rolling");
glutDisplayFunc(myDisplay);
glutIdleFunc(myIdle);
glClearColor(1.0f, 1.0f, 1.0f,0.0f);
glViewport(0, 0, 640, 480);
//glutKeyboardFunc(myKeyboard);
glutKeyboardFunc(keyboard);
glutSpecialFunc(specialKeyboard);
myInit();
glutMainLoop(); 
return(0);
}