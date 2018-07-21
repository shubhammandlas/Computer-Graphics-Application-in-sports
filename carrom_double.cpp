// #include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include<cmath>
// #include <gl/Gl.h>
// #include <gl/Glu.h>
// #include <gl/glut.h>
#include <math.h>
#include <iostream>
// #include <fstream.h>
using namespace std;
void myIdle();
void myDisplay();

// struct stick
// {
// float x,y,z;
// } ;
 
// struct T3D
// {
// stick position;
// stick velocity;
// };
// T3D stic;



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
TObject3D sphere2;
TObject3D sphere3;
TObject3D temp1_sph,temp2_sph;

struct TObject3D balls[10];
// TObject3D sphere3;
// TObject3D sphere4;
// TObject3D sphere5;
// TObject3D sphere6;
// TObject3D sphere7;
// TObject3D sphere8;
int n=10,k;
GLdouble p1=-3.0,p2=2.0; 
GLfloat gAngle = 0.0; 
#define FRICTION 0.0;
#define PI 3.14159565;
int enter= 0,uni=0 ;
int flagup=0,flagdown=0,flag=0;

// 
void collision(TObject3D &temp1_sph , TObject3D &temp2_sph)
{

	// printf("sdfs");

	// cout<< " hellso  "<< temp1_sph.velocity.x << "  " << temp2_sph.velocity.x<< "  "<<temp1_sph.position.x<<" "<<temp2_sph.position.x  <<endl;
	// cout<< " hellso  "<< temp1_sph.velocity.y << "  " << temp2_sph.velocity.y<< "  "<<temp1_sph.position.y<<" "<<temp2_sph.position.y  <<endl;
	// cout<<"asdaaaa     "<<temp1_sph<<endl;
	// if(j==0):
	// 	cout<<
	// double c2c1=temp2_sph.position.x-temp1_sph.position.x;
	// double val=sqrt(pow(temp1_sph.position.x-temp2_sph.position.x,2)+pow(temp1_sph.position.y-temp2_sph.position.y,2));
	// double cosbeta,sinalpha,sinbeta,cosalpha;

	double x1x,x1y,x2x,x2y,v1x,v1y,v2x,v2y;
	x1x=temp1_sph.position.x;
	x1y=temp1_sph.position.y;
	x2x=temp2_sph.position.x;
	x2y=temp1_sph.position.y;
	v1x=temp1_sph.velocity.x;
	v1y=temp1_sph.velocity.y;
	v2x=temp2_sph.velocity.x;
	v2y=temp2_sph.velocity.y;
	cout<< x1x<<","<<x1y<<","<<x2x<<","<<x2y<<","<<v1x<<","<<v1y<<","<<v2x<<","<<v2y<<endl;
	if(uni==1)
		cout<<x2x<<","<<x2y<<endl;
	// val2=(val*abs(sphere.velocity.x));
	// cout << val <<endl;
	// double absval;
	// if (temp1_sph.velocity.x<0)
	// 	absval=-1*(temp1_sph.velocity.x);
	// else
	// 	absval=temp1_sph.velocity.x;

	// cosalpha=(temp1_sph.velocity.x*c2c1)/(val*absval);
	// if (temp2_sph.velocity.x==0){
	// 	cosbeta=cosalpha;
	// // 	sphere.velocity.x=(sphere.velocity.x*sinalpha+sphere.velocity.y*cosalpha)*sinalpha;
	// // 	sphere.velocity.y=(sphere.velocity.x*sinalpha+sphere.velocity.y*cosalpha)*cosalpha;
	// // 	sphere2.velocity.x=(sphere.velocity.x*cosalpha+sphere.velocity.y*sinalpha)*cosalpha;
	// // 	sphere2.velocity.y=(sphere.velocity.x*cosalpha+sphere.velocity.y*sinalpha)*sinalpha;

	temp1_sph.velocity.x=v1x-((((v1x*x1x)+(v1y*x1y)- (v1x*x2x)-(v1y*x2y)-(v2x*x1x)-(v2y*x1y)+(v2x*x2x)+(v2y*x2y))
		*(x1x-x2x))  / ( pow(x2x,2)+pow(x2y,2)+ pow(x1x,2)+pow(x1y,2)-2* x2x*x1x -2*x2y*x1y));

	temp1_sph.velocity.y=v1y-((((v1x*x1x)+(v1y*x1y)- (v1x*x2x)-(v1y*x2y)-(v2x*x1x)-(v2y*x1y)+(v2x*x2x)+(v2y*x2y))
		*(x1y-x2y))  / ( pow(x2x,2)+pow(x2y,2)+ pow(x1x,2)+pow(x1y,2)-2* x2x*x1x -2*x2y*x1y));

	temp2_sph.velocity.x=v2x-((((v2x*x2x)+(v2y*x2y)- (v2x*x1x)-(v2y*x1y)-(v1x*x2x)-(v1y*x2y)+(v1x*x1x)+(v1y*x1y))
		*(x2x-x1x))  / ( pow(x2x,2)+pow(x2y,2)+ pow(x1x,2)+pow(x1y,2)-2* x2x*x1x -2*x2y*x1y));

	temp2_sph.velocity.y=v2y-((((v2x*x2x)+(v2y*x2y)- (v2x*x1x)-(v2y*x1y)-(v1x*x2x)-(v1y*x2y)+(v1x*x1x)+(v1y*x1y))
		*(x2y-x1y))  / ( pow(x2x,2)+pow(x2y,2)+ pow(x1x,2)+pow(x1y,2)-2* x2x*x1x -2*x2y*x1y));

	cout<<"hoooo"<<temp1_sph.velocity.x<<","<<temp1_sph.velocity.y<<","<<temp2_sph.velocity.x<<","<<temp2_sph.velocity.y<<endl;

	// cout<<"voila  "<<( pow(x2x,2)+pow(x2y,2)+ pow(x1x,2)+pow(x1y,2)-2* x2x*x1x -2*x2y*x1y)<<endl;
	// cout<<"hola  "<<(v1x*x1x)+(v1y*x1y)- (v1x*x2x)-(v1y*x2y)-(v2x*x1x)-(v2y*x1y)+(v2x*x2x)+(v2y*x2y)<<endl;
	// // }
	// // else{
	// 	// rintf("");
	// sinalpha=sqrt(1-pow(cosalpha,2));
	// sinbeta=sqrt(1-pow(cosbeta,2));

	// temp1_sph.velocity.x=(temp1_sph.velocity.x*sinalpha+temp1_sph.velocity.y*cosalpha)*sinalpha - (temp2_sph.velocity.x*cosbeta-temp2_sph.velocity.y*sinbeta)*cosalpha;
	// temp1_sph.velocity.y=(temp1_sph.velocity.x*sinalpha+temp1_sph.velocity.y*cosalpha)*cosalpha + (temp2_sph.velocity.x*cosbeta-temp2_sph.velocity.y*sinbeta)*sinalpha;

	// temp2_sph.velocity.x=(temp1_sph.velocity.x*cosalpha-temp1_sph.velocity.y*sinalpha)*cosbeta - (temp2_sph.velocity.x*sinbeta+temp2_sph.velocity.y*cosbeta)*sinbeta;
	// temp2_sph.velocity.y=-1*(temp1_sph.velocity.x*cosalpha-temp1_sph.velocity.y*sinalpha)*sinbeta - (temp2_sph.velocity.x*sinbeta+temp1_sph.velocity.y*cosbeta)*cosbeta;
	// // printf("sdfqwww");
	// // }
	// // printf("%f %f %f %f\n",sphere.velocity.x,sphere.velocity.y,sphere2.velocity.x,sphere2.velocity.y);
	// double aq=();

	// double dn=pow(temp2_sph.position.x,2)+pow(temp2_sph.position.y,2)+ 
	// 	pow(temp1_sph.position.x,2)+pow(temp1_sph.position.y,2)-2* temp2_sph.position.x*temp1_sph.position.x -2*temp2_sph.position.y*temp1_sph.position.y;


	// cout<<"dfsss    " <<   "    "<< temp2_sph.position.x-temp1_sph.position.x <<  "   "<< dn << endl;
	// cout<< " hurre123  "<< temp1_sph.velocity.x << "  " << temp2_sph.velocity.x<< endl;
	
	// printf(" %f %lf %lf %lf\n",sphere.velocity.x,c2c1,val,absval);

	// else{
	// 	cosbeta=-1*sphere2.velocity.x*c2c1/(sqrt(pow(sphere.position.x-sphere2.position.x,2)+pow(sphere.position.y-sphere2.position.y,2))*abs(sphere2.velocity.x));
	
	// }
	// printf("%lf  %lf\n",cosalpha,cosbeta);
	// p
}


void detection(){
	// cout<< "hurre"<<balls[i].velocity.x<<"  "<<balls[i].velocity.y<< "  "<< sphere3.velocity.x<<endl;
	double val;
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){

			if(i==j)
				continue;
			if(i==n){
				val=sqrt(pow(sphere3.position.x-balls[j].position.x,2)+pow(sphere3.position.y-balls[j].position.y,2));

				if (val<=.30){
					cout<<"eeei="<<i<<"	j="<<j<<endl;
					collision(sphere3,balls[j]);
				}
				continue;	
			}
			else if(j==n){
				val=sqrt(pow(sphere3.position.x-balls[i].position.x,2)+pow(sphere3.position.y-balls[i].position.y,2));
				if (val<=.30){
					cout<<"yyyyi="<<i<<"	j="<<j<<endl;
					

					collision(balls[i],sphere3);
					// uni=0;
				}
				continue;	
			}
			val=sqrt(pow(balls[i].position.x-balls[j].position.x,2)+pow(balls[i].position.y-balls[j].position.y,2));
			if (val<=.30){
				cout<<"nnnni="<<i<<"	j="<<j<<endl;
				if(j==0 and i==1)
						uni=1;
				collision(balls[i],balls[j]);
				uni=0;
			}
		}
		// cout<< "hurre"<<balls[i].velocity.x<<"  "<<balls[i].velocity.y<< "  "<< sphere3.velocity.x<<endl;
	}

}







void RunPhysics(float dt)
{

	int i;	
	double theta=int(gAngle)%360;
	theta=theta*3.14159565/180;
	if (enter==1){

		double v=10;
		// double theta=(gAngle%360.00)*PI/180;
		// sphere3.velocity.x=v*cos(theta);
		// sphere3.velocity.y=v*sin(theta);

		sphere3.velocity.x=v;
		// sphere3.velocity.y=v;
		// sphere.velocity.y=1.5;
		enter=0;
		flag=1;	
	}
	

	// double val=sqrt(pow(sphere3.position.x-balls[0].position.x,2)+pow(sphere3.position.y-balls[0].position.y,2));
	// cout<<"val="<<val<<endl;
	// if (val<=.30 && flagup==0){
	// 	cout<<"checkbefore	"<<sphere3.velocity.x<<"  "<<balls[0].velocity.x<<endl;
	// 	collision(sphere3,balls[0]);
	// 	cout<<"checkafter	"<<sphere3.velocity.x<<"  "<<balls[0].velocity.x<<endl;
	// 	// sphere3.velocity.x;
	// 	// balls[0].velocity.x=sphere3.velocity.x;
	// 	// sphere3.velocity.x=0;
	// 	flagup=1;
	// 	// printf("aaaaa\n");
	// }
	// printf("mmmmm\n");
	// if(flagup==1)
	if(flag==1)
		detection();	

	for(i=0;i<=n;i++){
		if(i==n){
			sphere3.velocity.x=sphere3.velocity.x*exp(-(1.5*dt));
			sphere3.velocity.y=sphere3.velocity.y*exp(-(1.5*dt));
			continue;
		}
		balls[i].velocity.x=balls[i].velocity.x*exp(-(1.5*dt));
		balls[i].velocity.y=balls[i].velocity.y*exp(-(1.5*dt));
	}


	// if (sphere.velocity.y>0)
	// 	sphere.velocity.y=sphere.velocity.y*exp(-(2*dt));
	// if (sphere.velocity.y<0)
	// 	sphere.velocity.y=sphere.velocity.y*exp(-(2*dt));
	// if (sphere.velocity.x>0)
	// 	sphere.velocity.x=sphere.velocity.x*exp(-(2*dt));
	// if (sphere.velocity.x<0)
	// 	sphere.velocity.x=sphere.velocity.x*exp(-(2*dt));

	// sphere.velocity.y=sphere.velocity.y-FRICTION*dt;
	// sphere.velocity.x=sphere.velocity.x-FRICTION*dt; 
	

	cout<<"white	"<<sphere3.position.x<<"  "<<sphere3.position.y<<endl;

	if ((sphere3.position.x<=-2.85) || (sphere3.position.x>=3.35)){

		sphere3.velocity.x=-sphere3.velocity.x;
		// sphere.velocity.x=sphere.velocity.x*0.99;
		// sphere.velocity.y=sphere.velocity.y*0.99;
	}
			
	if ((sphere3.position.y<=-1.85) || (sphere3.position.y>=1.85)){

		sphere3.velocity.y=-sphere3.velocity.y;
		// sphere.velocity.y=sphere.velocity.y*0.99;
		// sphere.velocity.x=sphere.velocity.x*0.99;
	}		

	for(i=0;i<n;i++){
		if ((balls[i].position.x<=-2.85) || (balls[i].position.x>=3.35))
			balls[i].velocity.x=-balls[i].velocity.x;
		if ((balls[i].position.y<=-1.85) || (balls[i].position.y>=1.85))
			balls[i].velocity.y=-balls[i].velocity.y;
		}

	for(i=0;i<=n;i++){
		if(i==n){
			sphere3.position.x=sphere3.position.x+sphere3.velocity.x*dt;
			sphere3.position.y=sphere3.position.y+sphere3.velocity.y*dt;
			continue;
		}
		balls[i].position.x=balls[i].position.x+balls[i].velocity.x*dt;
		balls[i].position.y=balls[i].position.y+balls[i].velocity.y*dt;
	}

 	

	// if ((sphere2.position.x<=-0.9) || (sphere2.position.x>=1.9)){

	// 	sphere2.velocity.x=-sphere2.velocity.x;
	// 	// sphere.velocity.x=sphere.velocity.x*0.99;
	// 	// sphere.velocity.y=sphere.velocity.y*0.99;
	// }
			
	// if ((sphere2.position.y<=-1.9) || (sphere2.position.y>=0.9)){

	// 	sphere2.velocity.y=-sphere2.velocity.y;
	// 	// sphere.velocity.y=sphere.velocity.y*0.99;
	// 	// sphere.velocity.x=sphere.velocity.x*0.99;
	// }


	
	// sphere2.position.x=sphere2.position.x+sphere2.velocity.x*dt;
	// sphere2.position.y=sphere2.position.y+sphere2.velocity.y*dt;
	// sphere2.position.z=sphere2.position.z+sphere2.velocity.z*dt;





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
 // printf("hello\n");
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP); // Draw Platform
	// glVertex3d(p1,p2,0.0);
	// glVertex3d(p1+5.5,p2,0.0);
	// glVertex3d(p1+5.5,p2+4.0,0.0);
	// glVertex3d(p1,p2+4.0,0.0);
	// glVertex3d(p1,p2,0.0);
	// glVertex3d(p1+1,p2,0.0);
	// glVertex3d(p1+1,p2+1,0.0);
	// glVertex3d(p1,p2+1,0.0);

glVertex3d(-3,2,0.0);
	glVertex3d(3.5,2,0.0);
	glVertex3d(3.5,-2,0.0);
	glVertex3d(-3,-2,0.0);

 
glEnd();
glPushMatrix();
if (flag==0){
	gAngle+=0.5;
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
// printf("%f\n",a);
glColor3d(0,0,0);
glBegin(GL_LINES);
    glVertex3f(-2.0,0,0);
    glVertex3f(-0.2,0.00,0);    
glEnd();
glPopMatrix();

// glPushMatrix(); // draw and place Sphere
// glTranslated(sphere.position.x,sphere.position.y,sphere.position.z);
 
// glutSolidSphere(0.15, 8, 8);
// glPopMatrix();
float s=0.0,color1=0.0,color2=0.0,color3=0.0;
glPushMatrix(); // draw and place Sphere
glTranslated(sphere3.position.x,sphere3.position.y,sphere3.position.z);
 glColor3d(color1,color2,color3);
glutSolidSphere(0.15, 8, 8);
glPopMatrix();

int j;

for(j=0;j<10;j++){
	glPushMatrix(); // draw and place Sphere
// glTranslated(s,0,0);

 	glTranslated(balls[j].position.x,balls[j].position.y,balls[j].position.z);
 	if(j<5){
	 	color1+=0.1;
	 	color2+=0.2;
	 	color3+=0.3;
	 }	

	 else{

	 	color1+=0.3;
	 	color2+=0.2;
	 	color3+=0.1;
	 }	
	 if(j==5){
	 	color1=0.3;
	 	color2=0.2;
	 	color3=0.1;
	 }

 	glColor3d(color1,color2,color3);
 	
glutSolidSphere(0.15, 8, 8);

glPopMatrix();
// s+=2;
// cout<< balls[j].position.x <<"   "  <<  balls[j].position.y << endl ;
}




// glPushMatrix(); // draw and place Sphere
// glTranslated(sphere2.position.x,sphere2.position.y,sphere2.position.z); 
// glutSolidSphere(0.15, 8, 8);
// glPopMatrix(); 

// glPushMatrix(); // draw and place Sphere
// glTranslated(sphere3.position.x,sphere3.position.y,sphere3.position.z); 
// glutSolidSphere(0.15, 8, 8);
// glPopMatrix(); 



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
sphere.velocity.z=0.0;
// scanf("%d",&n); 
// sphere2.position.x=-2.0;
// sphere2.position.y=0.0;
// sphere2.position.z=0.0;

// sphere2.velocity.x=0.0;
// sphere2.velocity.y=0.0;
// sphere2.velocity.z=0;
sphere3.position.x=0.0;
sphere3.position.y=0.0;
sphere3.position.z=0.0;

sphere3.velocity.x=0.0;
sphere3.velocity.y=0.0;
sphere3.velocity.z=0.0;

float c1=2.0,c2=0.0,r=.15;
int i,j,count=0;
for(i=0;i<4;i++){
	if(i>0){
		c1=c1+1.73*r;
		c2=-i*r;
		}	
	for(j=0;j<=i;j++){
		balls[count].position.x=c1;
		balls[count++].position.y=c2;
		c2=c2+2*r;
	}
	

}
for(i=0;i<10;i++){
	cout<<balls[i].position.x<<" , "<<balls[i].position.y<<endl;
}

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
glutInitWindowSize(680,480);
glutInitWindowPosition(60,80);
glutCreateWindow("Rolling");
glutDisplayFunc(myDisplay);
glutIdleFunc(myIdle);
glClearColor(1.0f, 1.0f, 1.0f,0.0f);
glViewport(0, 0, 680, 480);
//glutKeyboardFunc(myKeyboard);
glutKeyboardFunc(keyboard);
glutSpecialFunc(specialKeyboard);
myInit();
glutMainLoop(); 
return(0);


}

