#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
// #include <gl/Gl.h>
// #include <gl/Glu.h>
// #include <gl/glut.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <string>
// #include <iostream.h>
// #include <fstream.h>
// ofstream myfile;
#include <time.h>
#include <sys/time.h>
ifstream infile;
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
// RunPhysics(0.01);
myDisplay();
 
}
void split(const string &s, const char* delim, vector<string> & v){
    // to avoid modifying original string
    // first duplicate the original string and return a char pointer then free the memory
    char * dup = strdup(s.c_str());
    char * token = strtok(dup, delim);
    while(token != NULL){
        v.push_back(string(token));
        // the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation
        token = strtok(NULL, delim);
    }
    free(dup);
}


void myDisplay(){
	string STRING;
	vector <string> pch;
	int i=0;
	// ifstream infile;
	// infile.open ("moving.txt");
	// string pch="";
	getline(infile ,STRING);
	string temp;
	// pch = strtok(STRING,",");
    // while(pch != NULL){
    // 	pch=strtok(STRING,",");
    // 	printf("%s\n",pch);
	int arr[3];
	split(STRING, ",", pch);
	 int iter;

	vector<string>::const_iterator x = pch.begin();
	vector<string>::const_iterator y = x+1;
	vector<string>::const_iterator z = y+1;
	float time = stof(*(z+1));
	sphere.position.x = stof(*x);
	sphere.position.y = stof(*y);
	sphere.position.z = stof(*z);

    // for (vector<string>::const_iterator iter = pch.begin();
    //      iter != pch.end(); ++iter){
    // 	// arr[i]=iter;
    // 	// i++;
    // 	iter;
    // printf("%d",i);
    // cout << *iter << endl;
    // printf("%d%d%d",arr[0],arr[1],arr[2]);	
// }	
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
	printf("%f  %f   %f\n",sphere.position.x,sphere.position.y,sphere.position.z) ;
	glPushMatrix(); // draw and place Sphere
	glTranslated(sphere.position.x,sphere.position.y,sphere.position.z);
	 
	glutSolidSphere(0.2, 15, 15);
	// myfile.open ("moving.txt"); 
	// if(sphere.position.x>3.26){
	// 	// myfile.close();
	// 	// return();
	// 	exit(0);

	// }
	// // myfile << sphere.position.x<<","<<sphere.position.y<<","<<sphere.position.z<<"\n";
	// myfile.close();
	glPopMatrix();
	 
	 
	glutSwapBuffers();
	    
	      			// cout << STRING << '\n';
	     // To get you all the lines.
	        
		        // getline(infile,STRING); // Saves the line in STRING.
		        // cout<<STRING; // Prints our STRING.
	        
	     
			// infile.close();
	sleep(time);
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
infile.open ("moving.txt"); 
 
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
