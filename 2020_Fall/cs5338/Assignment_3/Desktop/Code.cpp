#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
const int screenHeight = 480; // window height is 480
const int screenWidth = 640 ; //window width is 640
//<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
	void exit(int) ;
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 { 
 
        glClearColor(1.0,1.0,1.0,1.0);       // set white background color
        glColor3f(0,0,0);          // set the drawing color 
 	glPointSize(4.0);		       // a ?dot? is 4 by 4 pixels
 	glLineWidth(4.0);
		      
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
  
 
	gluLookAt(0,0,0,    0,0,0,    80,0,0);
	
	glShadeModel(GL_SMOOTH);
 	glViewport(0,0,500,500); 
 
}
void ngon(int n, float r, float b, float g){
 
	float degree, vertx, verty, rotate, degToRad; 
 
	rotate = 360.0/n; 
		
	degree = rotate/2 + 100; 
	degToRad = 180/3.14159; 
 
	glColor3f(r,b,g);
 
	glBegin(GL_POLYGON); 
 
	for(int i = 0; i < n; i++, degree += rotate){
		vertx = 0.5 * sin(degree/degToRad); 
		verty = 0.5 * sin( (90 - degree)/degToRad); 
		glVertex3f(vertx, verty, 0);
 
	}
 
 
	glPushMatrix();		 
		GLfloat ambient1[] = { 0.2*r, 0.7*g, 0.7*b, 1.0 };
		GLfloat diffuse1[] = { 0.1*r, 0.1*g, 0.8*b, 1.0 };
		GLfloat specular1[] = { 0.5*r, 0.1*g, 1.0*b, 1.0 };
 
		GLfloat shininess[] = { 30 };
		GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};
 
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
 
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
 
		glShadeModel(GL_SMOOTH);
	glPushMatrix();
 
	glEnd();
 
	glFlush(); 
}
 
void cube(float scale, float degree, float x, float y, float z, float t, float tt, float ttt){
 
 		    glLoadIdentity();		
 
		    glTranslatef(t,tt,ttt);
 
		    glRotatef(degree,x,y,z);
		    glScalef(scale,scale,scale);
		    
		    glBegin(GL_POLYGON); //face #1
			glColor3f (1, 0.5, 1);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #2
			glColor3f (1.0, 1.0, 1);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #3
			glColor3f(0.8,1,1);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #4
			glColor3f (0, 1, 0);
			glVertex3f(0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #5
 
 
			glPushMatrix();		 
				GLfloat ambient2[] = { 0.4, 0.8, 0.4, 1.0 };
				GLfloat diffuse2[] = { 0.4, 0.4, 0.3, 1.0 };
				GLfloat specular2[] = { 0.3, 0.8, 0.3, 1.0 };
 
				GLfloat shininess2[] = { 30 };
				GLfloat emission2[] =  {0.3, -0.2, 0.3, 0.0};
 
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
 
				glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission2);
 
				glShadeModel(GL_SMOOTH);
			glPushMatrix();
 
			glColor3f (0.5, 1, 1);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, 0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #6
 
			glPushMatrix();		 
				GLfloat ambient1[] = { 0.2, 0.4, 0.8, 1.0 };
				GLfloat diffuse1[] = { 0.4, 0.1, 0.3, 1.0 };
				GLfloat specular1[] = { 0.8, 0.3, 0.3, 1.0 };
 
				GLfloat shininess[] = { 30 };
				GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};
 
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
 
				glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission);
 
				glShadeModel(GL_SMOOTH);
			glPushMatrix();
 
 
			glColor3f (1, 1.0, 0);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
 
 
 
 
 
 
 
                    glFlush(); 
 
 
		
 
 
 
}
 
 
 
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{ 
 
	GLfloat shininess[] = { 30 };
	GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};
 
	//Enable the light
	  
	 glEnable(GL_LIGHTing);  
	 glEnable(GL_LIGHT1);  
	 glEnable(GL_LIGHT2);
	 glEnable(GL_LIGHT3);  
	 glEnable(GL_LIGHT4);
    
	// set the light1 details
	GLfloat light_diffuse1[] = { 0.4f, 0.8f, 0.6f,1.0f };
	GLfloat light_ambient1[] = { 0.3f, 0.8f, 0.3f, 1.0f };
	GLfloat light_specular1[] ={0.3, 0.5, 0.6, 1.0};
 
	GLfloat light1_pos[]={4.0, 8.0, 6,0, 1};
 
	glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
 
        // set the light2 details
 
	GLfloat light_diffuse2[] = { 0.1f, 0.8f, 0.3f,1.0f };
	GLfloat light_ambient2[] = { 0.3, 0.5, 0.6, 1.0f };
	GLfloat light_specular2[] ={ 0.4f, 0.8f, 0.6f, 1.0};
	
	GLfloat light2_pos[]={4.0, 8.0, 6,0, 0};
 
	glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);
 	 
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 70.0);
	  
        // set the light3 details
	GLfloat light_diffuse3[] = { 0.5f, 0.3f, 0.6f,1.0f };
	GLfloat light_ambient3[] = { 0.1f, 0.3f, 0.8f, 1.0f };
	GLfloat light_specular3[] ={ 0.3, 0.5, 0.6, 1.0};
 
	glLightfv(GL_LIGHT3, GL_POSITION, light1_pos);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular3);
 
	GLfloat light3_pos[]={3.0, 8.0, 3,0, 1.0};
 	 
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 70);
 
       // set the light4 details	 
	GLfloat light_ambient4[] = { 0.3, 0.5, 0.6, 1.0f };
	GLfloat light4_pos[]={-0.7,0,-0.7, 1.0};
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient4);
	
	GLfloat visible_Ambient_light[] = {  0.3, 0.5, 0.6, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, visible_Ambient_light);
  
	// deep test
	glEnable(GL_DEPTH_TEST);
	// set the background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////
 
	glShadeModel(GL_SMOOTH);
	
	glShadeModel(GL_FLAT);
 
	///  Here is the sphere~!!!!!!!!!!!
 
        glLoadIdentity();
 
	glClear(GL_COLOR_BUFFER_BIT);
 
	glColor3f(0.7,0.6,.5); 
  
	glTranslatef(-0.7,0,-0.7);
 
	int color = 0; 
	float PI = atan(1.0) * 4.0;
	float a, b, x, y, z;
	float da = 6.0, db = 6.0;
	float radius = 0.2;
 
	for (a = -90.0; a + da <= 90.0; a += da) {
 
		glBegin(GL_QUAD_STRIP);
 
		glPushMatrix();		 
			GLfloat ambient1[] = { 0.1, 0.4, 0.8, 1.0 };
			GLfloat diffuse1[] = { 0.0, 0.1, 0.3, 1.0 };
			GLfloat specular1[] = { 0.2, 0.3, 0.3, 1.0 };
 
			GLfloat shininess[] = { 30 };
			GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};
 
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
 
			glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, emission);
 
			glShadeModel(GL_SMOOTH);
		glPushMatrix();
 
		for (b = 0.0; b <= 360.0; b += db) {
   
			if(color){
				
				glIndexi(1); 
 
				glColor3f(1,0,1);
			}else {
	
				glIndexi(255); 
 
				glColor3f(1,1,0);		
			}
	 
			x = radius * cos(b * PI / 180) * cos(a * PI / 180);
			y = radius * sin(b * PI / 180) * cos(a * PI / 180);
			z = radius * sin(a * PI / 180);
			glVertex3f(x, y, z);
 
			x = radius * cos(b * PI / 180) * cos((a + da) * PI / 180);
			y = radius * sin(b * PI / 180) * cos((a + da) * PI / 180);
			z = radius * sin((a + da) * PI / 180);
			glVertex3f(x, y, z);
 
			color = 1 - color; 
			 
		 }
 		glEnd();
		glFlush();
	 }
  
	glLoadIdentity();
 
	//////////////////////////////////
	//////////////////////////////////
 
	// glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glScalef(0.4,0.4,0.4);
 
	glColor3f(1,0,1);
  	
        glRotatef(20,-40,30,-20);
 
        glTranslatef(-0.7,0,-0.7);
 
	glBegin(GL_LINES);
 
 		glPushMatrix();		 
		GLfloat ambient[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
		GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
 
		 
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
 
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glShadeModel(GL_FLAT);
 		glPushMatrix();
 
		glVertex2f(0.5,  0.5) ;
		glVertex2f(-0.5,  -0.5) ;
 
	glEnd();
	glFlush();          // send all output to display 
 
	
 
	//////////////////////////////////
	//////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
 
	glLoadIdentity();
 
	glScalef(0.3,0.3,0.3);
 
        glRotatef(20,40,-30,20);
 
 
        glPopMatrix();
	glTranslatef(-1,-1,-1);
	 	
	 
	glColor3f(0,1,1);
	glBegin(GL_TRIANGLES);
 
		glVertex2f(0.5,  0) ;
		glVertex2f(0,  0.5) ;
		glVertex2f(-0.3,  -0.3) ;
	glEnd();
	glFlush();          // send all output to display 
 
	//////////////////////////////////
	//////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
 
	glLoadIdentity();
 
	glScalef(0.3,0.3,0.3);
        glRotatef(20,-40,30,-20);
 
	glTranslatef(0,-3,0);
	glColor3f(0,0,1);
	glBegin(GL_TRIANGLES);
 
		glPushMatrix();		 
		GLfloat ambient1[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat diffuse1[] = { 0.1, 0.5, 0.8, 1.0 };
		GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0 };
 
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
 
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glShadeModel(GL_FLAT);
 		glPushMatrix();
 
		glVertex2f(0.5,  0) ;
		glVertex2f(0,  0.5) ;
		glVertex2f(-0.3,  -0.3) ;
	glEnd();
	glFlush();          // send all output to display 
 
        //////////////////////////////////
	//////////////////////////////////
		//	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
glLoadIdentity();
			glScalef(0.3,0.3,0.3);
glTranslatef(1,-1,2);
 
        glRotatef(20,-40,30,-20);
			glColor3f(0,1,0);
			glBegin(GL_POINTS);
				glVertex2i(0,  0) ;
			glEnd();
			glFlush();          // send all output to display 
        //////////////////////////////////
	//////////////////////////////////
 
        //////////////////////////////////
	//////////////////////////////////
		//	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glLoadIdentity();
			glTranslatef(0.5,0.5,-1);
			glScalef(0.3,0.3,0.3);
			ngon(4,1,0,0);
 
        //////////////////////////////////
	//////////////////////////////////
		// 	glClear(GL_COLOR_BUFFER_BIT); 
			glLoadIdentity();
			glTranslatef(0,0,1);
 
 			glRotatef(20,-40,30,-20);
			glScalef(0.3,0.3,0.3);
			ngon(6,0,0,0);
 
        //////////////////////////////////
	//////////////////////////////////
		//      glClear(GL_COLOR_BUFFER_BIT); 
		
			glLoadIdentity();
 
		 	glTranslatef(0.7,-0.2,-0.7);
 
 glRotatef(20,-40,30,-20);
 
			glScalef(0.3,0.3,0.3);
			ngon(30,0,1,1);
 
        //////////////////////////////////
	//////////////////////////////////
		 //   glClear(GL_COLOR_BUFFER_BIT);
 
		cube(0.25, 45, 1, 1, 1, 0.5, 0.5, 0.8);	   
 
		cube(0.25, 15, 1, 2, 2, -0.5, 0.5, 0.8);
 
		cube(0.25, 30, 1, 2, 2, 0.5, -0.5, 0);	  
  
}
 
//<<<<<<<<<<<<<<<<<<<<<<<< ngon >>>>>>>>>>>>>>
 
 
 
 
 
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int	 main(int argc, char** argv)
{
 
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
 
 
 
	glutInitWindowSize(800,600);     // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Bigg Deep - Type Q or q to quit") ; // open the screen window 
	glutDisplayFunc(myDisplay);     // register redraw function
     //   glutKeyboardFunc(myKeyboard); // register the keyboard action function
 
 
 
 
 
 
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
 
}