// #include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

// #include <gl/Gl.h>
// #include <gl/Glu.h>
// #include <gl/glut.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

// #include <iostream.h>
// #include <fstream.h>
ofstream myfile;

// myfile.open ("moving.txt"); 
void myIdle();
void myDisplay();
 
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
 
#define GRAVITY 10.0
 
void RunPhysics(float dt)
{

	sphere.velocity.y=sphere.velocity.y-GRAVITY*dt;
	 
	sphere.position.x=sphere.position.x+sphere.velocity.x*dt;
	sphere.position.y=sphere.position.y+sphere.velocity.y*dt;
	sphere.position.z=sphere.position.z+sphere.velocity.z*dt;
 // 	if(sphere.position.x>1 || sphere.position.x>-1){
	// 	sphere.velocity.x=-sphere.velocity.x;
	// }
 	
	if (sphere.velocity.y<0)
	{
		 
		if (sphere.position.y<0.5)
		{
			 
			if ((sphere.position.x>-2) && (sphere.position.x<-1.2))
				sphere.velocity.y=-sphere.velocity.y;
		}
			 
		if (sphere.position.y<-0.9) 
			sphere.velocity.y=-sphere.velocity.y;
			 
	}
	
	
 
}
 
void myInit()
{
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(60.0, 64/48.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(0,0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	 
	glColor3d(0,0,0);
}
 
void myIdle()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	std::cout << gettimeofday(&tv, NULL) << std::endl;
	double begin =
	(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	std::cout << tv.tv_sec << "  "<<tv.tv_usec << std::endl;
	
	RunPhysics(0.01);
	myDisplay();

	gettimeofday(&tv, NULL);
	std::cout << tv.tv_sec << "  "<<tv.tv_usec << std::endl;

	double end =
	(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	myfile << sphere.position.x<<","<<sphere.position.y<<","<<sphere.position.z << "," << (end - begin)/1000 <<"\n";
	printf("Execution time %f\n", (end - begin)/1000); 
}
 
void myDisplay(void)
{
 
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP); // Draw Platform
glVertex3d(0.8,-0.9,0.5); 
glVertex3d(0.8,0.9,0.5);
glVertex3d(-1.8,0.9,0.9);
glVertex3d(-1.8,-0.9,0.9);
glEnd();
 
 
 
glBegin(GL_LINE_LOOP); 
glVertex3d(-2.0, 0.1, 0.5); // Draw little Bar
glVertex3d(-2.0, 0.3,0.5);
glVertex3d(-1.2, 0.3,0.5);
glVertex3d(-1.2, 0.1,0.5); 
 
glEnd();
 
glPushMatrix(); // draw and place Sphere
glTranslated(sphere.position.x,sphere.position.y,sphere.position.z);
 
glutSolidSphere(0.2, 15, 15);
// myfile.open ("moving.txt"); 
if(sphere.position.x>3.26){
	myfile.close();
	// return();
	exit(0);

}
// myfile.close();
glPopMatrix();
 
 
glutSwapBuffers();
sleep(.05);
}
 
int main(int argc, char **argv)
{
sphere.position.x=-1.7;
sphere.position.y=0.5;
sphere.position.z=0.5;

sphere.velocity.x=1;
sphere.velocity.y=0;
sphere.velocity.z=0;
// ofstream myfile;
myfile.open ("moving.txt"); 
 
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
myInit();
glutMainLoop(); 
return(0);
}