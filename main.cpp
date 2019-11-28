
#include<GL/freeglut.h>
#include<iostream>
#include<math.h>
using namespace std;
double radius=80;
double angle=0;
static int col;

void torusCircle(float inradius,float outradius,float cx,float cy){
	float th;
	float x,y;
	glLineWidth(5);
	glColor3f(1,0,0.2);
	glBegin(GL_LINE_STRIP);
	for(double i=0.3;i<=6.59;i+=0.629){
		x= inradius * cos(i);
		y= inradius * sin(i);
		glVertex2f(cx+x,cy+y);
		x= outradius * cos(i);
		y= outradius * sin(i);
		glVertex2f(cx+x,cy+y);
	}
	glEnd();

}

void ballon(int radius1,int radius2,int cx,int cy){
	float th;
	float x,y;
	glLineWidth(2);
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	for(double i=0.27;i<=6.8;i+=.3){
		x= radius1 * cos(i);
		y= radius2 * sin(i);
		glVertex2f(cx+x,cy+y);
	}
	glEnd();

}
void drawCircle(int radius,int cx,int cy){
	float x,y;
	glPointSize(5);
	glBegin(GL_POLYGON);
	for(double i=0;i<=6.29;i+=.1){
		x= radius * cos(i);
		y= radius * sin(i);
		glVertex3f(cx+x,cy+y,0);
}
	glEnd();
}

void init(){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
glOrtho(-300,300,-200,200,-200,200);
glMatrixMode(GL_MODELVIEW);
}

void baseStand(){
	//  Base Lines
glLineWidth(10);
glColor3f(0.5,0.7,0.8);
glBegin(GL_LINES); //
glVertex3f(0,50,0);
glVertex3f(-30,-80,0);
glVertex3f(0,50,0);
glVertex3f(30,-80,0);
glVertex3f(30,-80,0);
glVertex3f(-19,-30,0);
glVertex3f(-30,-80,0);
glVertex3f(19,-30,0);
glVertex3f(-19,-30,0);
glVertex3f(9,7.5,0);
glVertex3f(19,-30,0);
glVertex3f(-9,7.5,0);
glColor3f(0.2,0.3,0.3);
glVertex3f(30+10,-80,0);
glVertex3f(-30-10,-80,0);
glEnd();


}

void chamber(){

	// CHAMBER
	glPushMatrix();
	glScalef(0.5,0.5,0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	switch (col % 5) {
	case 0:
		glColor3f(0.0, 0.5, 1.0);  /* Sky blue */
		break;
	case 1:
		glColor3f(0.0, 1.0, 0.3);  /* Faint Green */
		break;
	case 2:
		glColor3f(1.0, 0.7, 0.0);  /* Faint Orange */
		break;
	case 3:
		glColor3f(1.0, 0.0, 0.4);  /* Dark Pink */
		break;
	case 4:
		glColor3f(1.0, 1.0, 0.2);  /* Faint Yellow */
		break;
	}
	glVertex2i(80,135);
	glVertex2i(120,135);
	glVertex2i(80,70);
	glVertex2i(120,70);
	glVertex2i(80,135);
	glVertex2i(80,110);
	glVertex2i(120,135);
	glVertex2i(120,110);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(78.5,110);
	glVertex2i(122.5,110);
	glVertex2i(122.5,70);
	glVertex2i(78.5,70);
	glEnd();
	col++;
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(76.5,110);
	glVertex2f(124.5,110);
	glVertex2f(78.5,100);
	glVertex2f(122.5,100);
	glEnd();
	glPopMatrix();


}

void tent(){

	//Tent
glPushMatrix();//<1>

glScalef(4,2,0);
glTranslatef(-45,-30,0);
glBegin(GL_QUADS);
glColor3f(1,0.8,0.2);
glVertex3f(-6,0,0);
glVertex3f(6,0,0);
glVertex3f(6,20,0);
glVertex3f(-6,20,0);
glColor3f(1,0.5,0.2);
glVertex3f(10,20,0);
glVertex3f(-10,20,0);
glVertex3f(-10,23,0);
glVertex3f(10,23,0);
glColor3f(0,1,0.5);
glVertex3f(-10,0,0);
glVertex3f(10,0,0);
glVertex3f(10,-2,0);
glVertex3f(-10,-2,0);
glEnd();
glColor3f(1,0,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(-10,23,0);
glVertex3f(10,23,0);
glVertex3f(0,37,0);
glEnd();
glPopMatrix();//</1>

}

void idle(){
	glutPostRedisplay();
}
void Display(){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
col = 0;


// Ground
glColor3f(.5,.5,0.5);
glBegin(GL_QUADS);
glVertex3f(-300,-40,-20);
glVertex3f(300,-40,-20);
glVertex3f(300,-200,-20);
glVertex3f(-300,-200,-20);
glEnd();

//Sky
glColor3f(0,0.1,0.1);
glBegin(GL_QUADS);
glVertex3f(300,-40,-20);
glVertex3f(-300,-40,-20);
glVertex3f(-300,200,-20);
glVertex3f(300,200,-20);
glEnd();

// Moon
glPushMatrix();
glTranslatef(30,30,0);
glColor3f(1,1,1);
drawCircle(20,150,100);
glColor3f(0,0.1,0.1);
drawCircle(20,160,110);
glPopMatrix();

//Tent
tent();
	
glPushMatrix();//<2>
glTranslatef(0,0,-20);
glPushMatrix();//<3>
glTranslatef(0,50,0);
glRotatef(angle,0,0,1);
glTranslatef(0,-50,0);
angle+=0.1;

for(int i=0;i<5;i++){
	glPushMatrix();//<4>
	glTranslatef(0,50,0);
	glRotatef(36*i,0,0,1);
	glTranslatef(0,-50,0);

	glTranslatef(0,-30,0);
	glRotatef(180+36*i,0,0,-1);
	glTranslatef(0,30,0);
//
	glTranslatef(0,-30,0);
	glRotatef(angle,0,0,-1);
	glTranslatef(0,30,0);


glPushMatrix();//<5>
glRotatef(180,0,0,1);
glTranslatef(-50,-40,0);

chamber();
glPopMatrix();//</5>

	glPopMatrix();//</4>

}
for(int i=0;i<5;i++){
	glPushMatrix();//<6>
	glTranslatef(0,50,0);
	glRotatef(36*i,0,0,1);
	glTranslatef(0,-50,0);
	
	glTranslatef(0,130,0);
	glRotatef(36*i,0,0,-1);
	glTranslatef(0,-130,0);

	glTranslatef(0,130,0);
	glRotatef(angle,0,0,-1);
	glTranslatef(0,-130,0);

	glPushMatrix();//<7>
	glTranslatef(-50,60,0);
	chamber();
	glPopMatrix();//</7>

	glPopMatrix();//</6>
	glPushMatrix();//<8>
	glTranslatef(0,50,0);
	glRotatef(36*i,0,0,1);
	glTranslatef(0,-50,0);

	glLineWidth(5);
	glColor3f(0,0.4,0.2);
	glBegin(GL_LINES);
	glVertex3f(0,130,0);
	glVertex3f(0,-30,0);
	glEnd();
	glPopMatrix();//</8>

}

glPopMatrix(); //</3>
glTranslatef(0,50,0);
glRotatef(angle,0,0,1);
glTranslatef(0,-50,0);
glColor3f(0,0,1);
torusCircle(0,10,0,50); //Ring
torusCircle(34,35,0,50);
glColor3f(0,1,0);
torusCircle(80,81,0,50);
torusCircle(75,76,0,50);

glPopMatrix(); //</2>
baseStand();
glutSwapBuffers();
}

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowPosition(30, 0);
glutInitWindowSize(1200,800);
glutCreateWindow("Ferries Wheel");
init();
glutDisplayFunc(Display);
glutIdleFunc(idle);
glutMainLoop();
return 0;
}
