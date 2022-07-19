#include<windows.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#define PI 3.1416


GLint i, j, k, flag=0,mode=0,sun_mode=0,boat_mode=0,smoke_mode=0;
GLfloat sun_spin=0, sun_x=0, sun_y=0, moon_spin=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0,moveB=0.0,rx=60.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;


void *currentfont;


void setFont(void *font)
{
	currentfont=font;
}


void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


void OpeningScreen()
{
    glClearColor(0.3,0.1,0.3,0);
    glClear(GL_COLOR_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1,1,1);
	drawstring(350.0,435.0,0,"*  *   VILLAGE SIMULATOR  *  *");

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.5,1.0,0.5);
	drawstring(420.0,370.0,0,"SUBMITTED   BY");

	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,340.0,0," Name: Roshni Anand            USN:1BY19CS125");

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,320.0,1.0," Name: Rohith Reddy D         USN:1BY19CS124");

	glColor3f(0.6,1.0,1.0);
	drawstring(335.0,300.0,1.0," Name: Rohan Joy                 USN:1BY19CS122");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.5,1.0,0.5);
	drawstring(360.0,225.0,0,"UNDER THE GUIDANCE OF");

	glColor3f(1.0,1.0,0.5);
	drawstring(262.0,180.0,1.0," Prof. CHETHANA C");

		setFont(GLUT_BITMAP_HELVETICA_12);


	glColor3f(0.0,1.0,1.0);
	drawstring(275.0,165.0,1.0,"  Asst. Prof., Dept of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(260.0,150.0,1.0,"  BMS INSTITUTE OF TECHNOLOGY");


	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,0.5);
	drawstring(460.0,180.0,1.0,"          Prof. MUNESHWARA M S");

	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(520.0,165.0,1.0,"          Asst. Prof., Dept of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(500.0,150.0,1.0,"          BMS INSTITUTE OF TECHNOLOGY");


	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.5,1.0,0.5);
	drawstring(350.0,80.0,0,"~ PRESS  -ENTER-  TO CONTINUE ~");


	glFlush();
}

void Screen2()
{
    glClearColor(0.3,0.1,0.3,0);
    glClear(GL_COLOR_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1,1,1);
	drawstring(430.0,450.0,0,"***  MENU  ***");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,0.1);
	drawstring(170.0,400.0,0,"MODE SIMULTATION:");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,400.0,0,"1. Press d for DAY MODE (Default)");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,370.0,0,"2. Press n for NIGHT MODE");


	glColor3f(1.0,1.0,0.1);
	drawstring(170.0,310.0,0,"SUN/MOON SIMULTATION:");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,310.0,0,"1. Press w to halt Sun/Moon Movement (Default)");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,280.0,0,"2. Press q to start Sun/Moon Movement");

	glColor3f(1.0,1.0,0.1);
	drawstring(170.0,220.0,0,"BOAT SIMULTATION:");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,220.0,0,"1. Press c for Normal Speed (Default)");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,190.0,0,"2. Press v to increase the Speed");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,160.0,0,"3. Press x to decrease the Speed");

	glColor3f(1.0,1.0,0.1);
	drawstring(540.0,130.0,0,"4. Press z to halt the Boat");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.1,1.0,0.1);
	drawstring(365.0,80.0,0,"Press S to start the Simulation");

	glColor3f(0.8,0.8,0.3);
	drawstring(350.0,50.0,0,"(Note: All keys are case insensitive)");

	glFlush();
}



///============================================================================================================///

///=================///
///*** All_Model ***///
///=================///



///*** Circle_Model***///

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}



///*** Triangle Model ***///
void triangle(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f){
    glBegin(GL_TRIANGLES);
        glVertex2f(a,b);
        glVertex2f(c,d);
        glVertex2f(e,f);
    glEnd();
}



///*** Rectangle Model ***///
void rectangle_model(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h){
    glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(c,d);
        glVertex2i(e,f);
        glVertex2i(g,h);
    glEnd();
}


///*** Line Model ***///
void line_draw(GLfloat a, GLfloat b, GLfloat c, GLfloat d){
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(a,b);
        glVertex2i(c,d);
    glEnd();
}


/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(500,300,0);
    circle(30);
    glPopMatrix();

}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin,0,0,-0.9);
    Sun_Model();
    glPopMatrix();

}

///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,410,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 425, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,410,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,410,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,410,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,404,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,404,0);
    circle(10);
    glPopMatrix();

    ///****Fill End****

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,395,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,400,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,397,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,397,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///****Fill End****

}
///*** Hill_Model***///
void hill_big(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 300);
	glVertex2i(170, 440);
	glVertex2i(270, 300);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

	glVertex2i(170, 440);
	glVertex2i(150, 412);
	glVertex2i(160, 420);
	glVertex2i(170, 412);
	glVertex2i(180, 420);
	glVertex2i(190, 412);

	glEnd();

}
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 330);
	glVertex2i(310, 390);
	glVertex2i(370, 330);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(310, 390);
	glVertex2i(290, 370);
	glVertex2i(300, 375);
	glVertex2i(310, 370);
	glVertex2i(320, 375);
	glVertex2i(330, 370);


	glEnd();
}
///*** Tilla_Model ***///
void Tilla_One_Model(){
    ///Tilla
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(125, 300);
	glVertex2i(150, 310);
	glVertex2i(160, 320);
	glVertex2i(170, 320);
	glVertex2i(180, 330);
	glVertex2i(190, 335);
	glVertex2i(200, 338);
	glVertex2i(300, 340);
	glVertex2i(300, 300);

	glEnd();

}

void Tilla_Two_Model(){

	glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,320,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,317,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,310,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,310,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,300,0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,310,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,305,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,300,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,305,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,290,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,295,0);
    circle(20);
    glPopMatrix();



}
///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 335);
	glVertex2i(285, 352);
	glVertex2i(380, 345);
	glVertex2i(380, 335);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 335);
	glVertex2i(285, 352);
	glVertex2i(380, 335);
	glVertex2i(380, 335);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 300);
	glVertex2i(290, 335);
	glVertex2i(375, 335);
	glVertex2i(375, 300);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 300);
	glVertex2i(350, 335);
	glVertex2i(375, 335);
	glVertex2i(375, 300);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 300);
	glVertex2i(330, 330);
	glVertex2i(350, 330);
	glVertex2i(350, 300);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 315);
	glVertex2i(295, 330);
	glVertex2i(310, 330);
	glVertex2i(310, 315);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(314, 310);
	glVertex2i(314, 325);
	glVertex2i(328, 325);
	glVertex2i(328, 310);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 310);
	glVertex2i(355, 325);
	glVertex2i(370, 325);
	glVertex2i(370, 310);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 320);
	glVertex2i(257, 335);
	glVertex2i(290, 335);
	glVertex2i(290, 320);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 300);
	glVertex2i(255, 320);
	glVertex2i(290, 320);
	glVertex2i(290, 300);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 300);
	glVertex2i(260, 315);
	glVertex2i(285, 315);
	glVertex2i(285, 300);

	glEnd();


}
///*** Field_Model ***///
void field(){
    ///Field
	glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
	glVertex2i(0, 280);
	glVertex2i(0, 300);
	glVertex2i(1000, 300);
	glVertex2i(1000, 280);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(0, 0);
	glVertex2i(0, 280);
	glVertex2i(1000, 280);
	glVertex2i(1000, 0);

	glEnd();


}
///*** Tree_Model ***///
void Tree_Model_One(){


    glPushMatrix();
    glTranslatef(110,340,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,330,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 300);
	glVertex2f(109, 320);
	glVertex2f(111, 320);
	glVertex2f(111, 300);

    glEnd();

}
void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,360,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,356,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,356,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,355,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 340);
	glVertex2f(129, 354);
	glVertex2f(131, 354);
	glVertex2f(131, 340);

    glEnd();
}

void Tree_Model_Three(){


    glBegin(GL_POLYGON);

	glVertex2f(125, 353);
	glVertex2f(133, 375);
	glVertex2f(141, 353);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 340);
	glVertex2f(132, 354);
	glVertex2f(134, 354);
	glVertex2f(134, 340);

    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(175, 150);
    glVertex2i(180, 290);
    glVertex2i(184, 290);
    glVertex2i(190, 150);
    glEnd();
}

///*** Windmill_Blades_Model ***///
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){



        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    glScaled(0.85,0.85,0.85);
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(156,252,0);
    glScaled(0.85,0.85,0.85);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(156,252,0);
    glScaled(0.85,0.85,0.85);
    Windmill_Blade();
    glPopMatrix();




}



///*** River Model ***///
void River()
{
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(400,300);
        glVertex2i(450,250);
        glVertex2i(650,250);
        glVertex2i(600,300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(450,250);
        glVertex2i(400,200);
        glVertex2i(600,200);
        glVertex2i(650,250);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(400,200);
        glVertex2i(450,150);
        glVertex2i(650,150);
        glVertex2i(600,200);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(400,200);
        glVertex2i(450,150);
        glVertex2i(650,150);
        glVertex2i(600,200);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(450,150);
        glVertex2i(400,120);
        glVertex2i(600,120);
        glVertex2i(650,150);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(0,131,185);
        glVertex2i(0,0);
        glVertex2i(1000,0);
        glVertex2i(1000,120);
        glVertex2i(0,120);
    glEnd();

    //Applying Borders for the river
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(410,300);
        glVertex2i(460,250);
        glVertex2i(450,250);
        glVertex2i(400,300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(460,250);
        glVertex2i(410,200);
        glVertex2i(400,200);
        glVertex2i(450,250);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(410,200);
        glVertex2i(460,150);
        glVertex2i(450,150);
        glVertex2i(400,200);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(460,150);
        glVertex2i(410,120);
        glVertex2i(400,120);
        glVertex2i(450,150);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(0,115);
        glVertex2i(400,115);
        glVertex2i(400,120);
        glVertex2i(0,120);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(400,120);
        glVertex2i(410,120);
        glVertex2i(400,115);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(590,300);
        glVertex2i(640,250);
        glVertex2i(650,250);
        glVertex2i(600,300);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(640,250);
        glVertex2i(590,200);
        glVertex2i(600,200);
        glVertex2i(650,250);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(590,200);
        glVertex2i(640,150);
        glVertex2i(650,150);
        glVertex2i(600,200);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(640,150);
        glVertex2i(590,120);
        glVertex2i(600,120);
        glVertex2i(650,150);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(600,115);
        glVertex2i(1000,115);
        glVertex2i(1000,120);
        glVertex2i(600,120);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(590,120);
        glVertex2i(600,120);
        glVertex2i(600,115);
    glEnd();
}



///*** Boat Model ***///
void Boat()
{
    glPushMatrix();
//    glTranslatef(moveB,0.0,0.0);

    //Boat Base
    glColor3f(0.4,0.2,0.2);
    glBegin(GL_POLYGON);
        glVertex2i(10,60);
        glVertex2i(60,45);
        glVertex2i(60,25);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(60,45);
        glVertex2i(200,45);
        glVertex2i(200,25);
        glVertex2i(60,25);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(200,45);
        glVertex2i(250,60);
        glVertex2i(200,25);
    glEnd();


    //Design
    glBegin(GL_POLYGON);
        glColor3f(1.0,4.0,55.0);
        glVertex2i(60,45);
        glVertex2i(70,75);
        glVertex2i(170,75);
        glVertex2i(160,45);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(88,4,5);
        glVertex2i(170,75);
        glVertex2i(180,45);
        glVertex2i(160,45);
    glEnd();


    //Design Lines
    glColor3f(0.0,0.0,0.0);
    line_draw(80,45,90,75);
    line_draw(100,45,110,75);
    line_draw(120,45,130,75);
    line_draw(140,45,150,75);

    //Pole
    glBegin(GL_POLYGON);
        glColor3ub(1,4,55);
        glVertex2i(180,45);
        glVertex2i(185,45);
        glVertex2i(185,110);
        glVertex2i(180,110);
    glEnd();

    //Flag
    glBegin(GL_POLYGON);
        glColor3ub(10,40,5);
        glVertex2i(185,110);
        glVertex2i(220,110);
        glVertex2i(220,85);
        glVertex2i(185,85);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2i(192,92);
        glVertex2i(212,102);
        glVertex2i(192,102);
        glVertex2i(212,92);
    glEnd();
    glPopMatrix();


//    moveB += 0.09;
//    if(moveB>1000)
//    {
//        moveB = 0.0;
//    }
}



///*** Plough Model ***///
void Plough()
{
    //Plough field
    glBegin(GL_POLYGON);
        glColor3ub(155,118,83);
        glVertex2i(750,220);
        glVertex2i(950,220);
        glVertex2i(900,150);
        glVertex2i(710,150);
    glEnd();

    glPushMatrix();
    glTranslatef(713,170,0);
    circle(21);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(723,190,0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(733,208,0);
    circle(20);
    glPopMatrix();


    //Plough Lines
    glLineWidth(0.8);
    glBegin(GL_LINES);
        glColor3ub(15,18,83);
        glVertex2i(705,170);
        glVertex2i(900,170);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(15,18,83);
        glVertex2i(725,190);
        glVertex2i(910,190);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(15,18,83);
        glVertex2i(745,210);
        glVertex2i(920,210);
    glEnd();

    //Adding Veggies
    glPushMatrix();
    glColor3f(1.0,0.5,0.5);
    glTranslatef(730,170,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.5,0.5);
    glTranslatef(780,170,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.5,0.5);
    glTranslatef(830,170,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.5,0.5);
    glTranslatef(880,170,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.5,0.1);
    glTranslatef(858,190,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.5,0.1);
    glTranslatef(810,190,0);
    circle(6);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0,0.5,0.1);
    glTranslatef(760,190,0);
    circle(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.1);
    glTranslatef(758,210,0);
    circle(6);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0,0.9,0.1);
    glTranslatef(800,210,0);
    circle(6);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0,0.9,0.1);
    glTranslatef(845,210,0);
    circle(6);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0,0.9,0.1);
    glTranslatef(890,210,0);
    circle(6);
    glPopMatrix();
}



///*** Grass Model ***///
void Grass()
{
    glPushMatrix();
    glColor3f(1.0,1.0,0.56);
    glBegin(GL_POLYGON);
        glVertex2i(200,150);
        glVertex2i(203,150);
        glVertex2i(202,170);
        glVertex2i(198,175);
        glVertex2i(201,167);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,1.0,0.6);
    glBegin(GL_POLYGON);
        glVertex2i(202,150);
        glVertex2i(204,150);
        glVertex2i(213,175);
        glVertex2i(216,170);
        glVertex2i(212,167);
    glEnd();
    glPopMatrix();
}


///*** Tractor Model ***///
void TractorBody(){

    //Top Part
    glPushMatrix();
    glTranslated(800,240,0);
    glColor3f(1.0,0,0);
    rectangle_model(0,10,90,10,90,40,0,40);
    glPopMatrix();


    //Top Right Part
    glPushMatrix();
    glTranslated(850,260,0);
    glColor3f(1.0,0,0);
    rectangle_model(0,10,40,10,40,40,0,40);
    glPopMatrix();


    //Window Part
    glPushMatrix();
    glTranslated(860,270,0);
    glColor3f(1,1,1);
    rectangle_model(0,10,20,10,20,25,0,25);
    glPopMatrix();


    //Pipe Long Part
    glPushMatrix();
    glTranslated(880,290,0);
    glColor3f(0.5,0.5,0.5);
    rectangle_model(0,10,5,10,5,25,0,25);
    glPopMatrix();


    //Pipe Short Part
    glPushMatrix();
    glTranslated(885,301,0);
    glColor3f(0.5,0.5,0.5);
    rectangle_model(0,10,15,10,15,14,0,14);
    glPopMatrix();


    //Wheels
    glPushMatrix();
    glTranslatef(800,250,0);
    glColor3f(0,0,0);
    circle(20);
    glColor3f(0.75,0.75,0.75);
    circle(3);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(880,250,0);
    glColor3f(0,0,0);
    circle(20);
    glColor3f(0.75,0.75,0.75);
    circle(3);
    glPopMatrix();

}

void TractorSmoke(){
    //Smoke
    glPushMatrix();
    glTranslatef(910,300,0);
    glColor3f(1,1,1);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(915,300,0);
    glColor3f(1,1,1);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(916,304,0);
    glColor3f(1,1,1);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(912,305,0);
    glColor3f(1,1,1);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900,300,0);
    glColor3f(1,1,1);
    rectangle_model(0,0,10,0,10,5,0,5);
    glPopMatrix();
}


void Tractor(){
    glPushMatrix();
    glTranslatef(0,0,0);
    TractorBody();
    glPopMatrix();

    if(smoke_mode==0){
        glPushMatrix();
        glTranslatef(4,11,0);
        TractorSmoke();
        glPopMatrix();
    }

}


///*** Night Sky Model ***///
void NightSky()
{
    glColor3ub(6, 0, 45);
    glBegin(GL_POLYGON);
        glVertex2d(0,300);
        glVertex2d(1000,300);
        glVertex2d(1000,500);
        glVertex2d(0,500);
    glEnd();

//    glPushMatrix();
//    glTranslatef(500,420,0);
//    glColor3f(1,1,1);
//    circle(25);
//    glPopMatrix();
}


///*** Four-star Model ***///
void star()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2i(200,200);
        glVertex2i(205,200);
        glVertex2i(202,207);
    glEnd();
    triangle(200,200,205,200,202,193);
    rectangle_model(195,200,202,202,210,200,198,198);
    glPopMatrix();
}


///*** Circle-star Model ***///
void star_circle()
{
    glPushMatrix();
    glTranslatef(220,240,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(309,230,0);
    circle(1.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,230,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(255,260,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360,240,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(440,280,0);
    circle(1.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(560,250,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(640,220,0);
    circle(1.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(770,265,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(120,235,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230,275,0);
    circle(1.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(67,215,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(848,285,0);
    circle(1.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(888,195,0);
    circle(1.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(930,265,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(960,235,0);
    circle(1.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,275,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,185,0);
    circle(1.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800,175,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(105,275,0);
    circle(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(805,225,0);
    circle(1.3);
    glPopMatrix();
}



///*** Flower Model ***///
void FlowerStraight()
{
    //Base Part
    glPushMatrix();
    glLineWidth(1.8);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2i(200,200);
        glVertex2i(200,230);
    glEnd();
    glPopMatrix();


    //Petals
    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(200,236,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(194,230,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(206,230,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(200,224,0);
    circle(4);
    glPopMatrix();

    //Centre Part
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(200,230,0);
    circle(3);
    glPopMatrix();

}


void FlowerSlantLeft()
{
    //Base Part
    glPushMatrix();
    glLineWidth(1.8);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2i(200,200);
        glVertex2i(196,208);
        glVertex2i(196,208);
        glVertex2i(180,220);
    glEnd();
    glPopMatrix();


    //Petals
    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(180,226,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(174,220,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(180,215,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(186,220,0);
    circle(4);
    glPopMatrix();

    //Centre Part
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(180,220,0);
    circle(3);
    glPopMatrix();

}

void FLowerSlantRight()
{
    //Base Part
    glPushMatrix();
    glLineWidth(1.8);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2i(200,200);
        glVertex2i(204,208);
        glVertex2i(204,208);
        glVertex2i(220,220);

    glEnd();
    glPopMatrix();


    //Petals
    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(220,226,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(226,220,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(214,220,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0.2,0.1);
    glTranslatef(220,214,0);
    circle(4);
    glPopMatrix();

    //Centre Part
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(220,220,0);
    circle(3);
    glPopMatrix();
}


///Model_End
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

///*** Moon ***///
void Moon(){
    //glTranslatef(500,420,0);
    glColor3f(1,1,1);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,100,0);
    glScalef(0.75,0.75,0.75);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    glScalef(0.75,0.75,0.75);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five(){

    glPushMatrix();
    glTranslatef(ax+-300,270,0);
    glScalef(0.75,0.75,0.75);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six(){

    glPushMatrix();
    glTranslatef(cx+-500,340,0);
    glScalef(0.5,0.5,0.5);
    cloud_model_Three();
    glPopMatrix();
}

///*** House_One ***///
void house_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_three(){
    glPushMatrix();
    glTranslatef(320, 37,0);
    house();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_small();
    glPopMatrix();

}
/// *** Tilla_One_Model_One ***///

void Tilla_One(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three(){

    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four(){

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    Tilla_One_Model();
    glPopMatrix();


}
///*** Tree_1 ***///
void Tree_One(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,40,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-20,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-60,60,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(98,20,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,40,0);
    Windmill();
    glPopMatrix();


}


///*** Grass ***///
void Grass_One(){
    glPushMatrix();
    glTranslatef(15,40,0);
    Grass();
    glPopMatrix();
}

void Grass_Two(){
    glPushMatrix();
    glTranslatef(-25,60,0);
    Grass();
    glPopMatrix();
}

void Grass_Three(){
    glPushMatrix();
    glTranslatef(150,100,0);
    Grass();
    glPopMatrix();
}

void Grass_Four(){
    glPushMatrix();
    glTranslatef(165,80,0);
    Grass();
    glPopMatrix();
}

void Grass_Five(){
    glPushMatrix();
    glTranslatef(-45,05,0);
    Grass();
    glPopMatrix();
}

void Grass_Six(){
    glPushMatrix();
    glTranslatef(135,-5,0);
    Grass();
    glPopMatrix();
}



///*** Tractor ***///
void TractorMove(){
    glPushMatrix();
    glTranslated(rx,0,0);
    Tractor();
    glPopMatrix();

    if(rx>=-70){
         rx-=0.01;
         smoke_mode=0;
    }
    else{
        smoke_mode=1;
    }
}


///*** Boat ***///
void BoatMove(){
    glPushMatrix();
    glTranslated(moveB-300,0,0);
    Boat();
    glPopMatrix();

    if(boat_mode==0){
        moveB += 0.1;
    }
    else if(boat_mode==1){
        moveB += 0.3;
    }
    else if(boat_mode==-1){
        moveB += 0.04;
    }
    else if(boat_mode==2){
        moveB = moveB;
    }
    if(moveB>1250)
    {
        moveB = 0.0;
    }
}

///*** Four-star ***///
void four_star()
{
    glPushMatrix();
    glTranslatef(0,260,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140,240,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,235,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,285,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,255,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(510,243,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(675,259,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(735,210,0);
    star();
    glPopMatrix();
}


///*** Circle-star ***///
void small_star()
{
    glPushMatrix();
    glTranslatef(0,200,0);
    star_circle();
    glPopMatrix();
}



///*** Flower ***///
void FlowerOne(){
    glPushMatrix();
    glTranslatef(-150,30,0);
    FlowerStraight();
    FlowerSlantLeft();
    FLowerSlantRight();
    glPopMatrix();
}


void FlowerTwo(){
    glPushMatrix();
    glTranslatef(-140,-50,0);
    FlowerStraight();
    FlowerSlantLeft();
    FLowerSlantRight();
    glPopMatrix();
}

void FlowerThree(){
    glPushMatrix();
    glTranslatef(120,30,0);
    FlowerStraight();
    FlowerSlantLeft();
    //FLowerSlantRight();
    glPopMatrix();
}

void FlowerFour(){
    glPushMatrix();
    glTranslatef(470,-6,0);
    FlowerStraight();
    FlowerSlantLeft();
    FLowerSlantRight();
    glPopMatrix();
}


///Object_End
///=========================================================================================================///


///========================///
///*** Display Function ***///
///========================///

void display(void)
{
    if(mode==0){
        glClearColor(.53, .81, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);


        ///*** Object_Layer ***///
        Sun();

        Windmill_Three();

        Hill_Big_One();
        Tilla_Four();

        house_three();

        Hill_Big_Two();
        Hill_Small_One();

        cloud_three();
        cloud_four();


        Tilla_One();
        Tilla_Two();
        Tilla_Three();


        house_one();
        cloud_one();
        house_two();


        Tree_One();
        Tree_Two();
        Tree_Three();
        Tree_Four();
        Tree_Five();
        Tree_Six();
        Tree_Seven();
        Tree_Eight();
        Tree_Nine();
        Tree_Ten();
        Tree_Eleven();
        Tree_Twelve();



        cloud_two();
        cloud_five();
        cloud_six();

        field();
        River();

     //   Windmill_Three();

        BoatMove();

        Plough();

        Grass();
        Grass_One();
        Grass_Two();
        Grass_Three();
        Grass_Four();
        Grass_Five();
        Grass_Six();

        FlowerOne();
        FlowerTwo();
        FlowerThree();
        FlowerFour();

        Windmill_One();
        Windmill_Two();

        TractorMove();

        glFlush();
    }
    else if(mode==1){

        ///*** Object_Layer ***///

        NightSky();

        Moon();

        Windmill_Three();

        Hill_Big_One();
        Tilla_Four();

        house_three();

        Hill_Big_Two();
        Hill_Small_One();


        Tilla_One();
        Tilla_Two();
        Tilla_Three();


        house_one();
        house_two();


        Tree_One();
        Tree_Two();
        Tree_Three();
        Tree_Four();
        Tree_Five();
        Tree_Six();
        Tree_Seven();
        Tree_Eight();
        Tree_Nine();
        Tree_Ten();
        Tree_Eleven();
        Tree_Twelve();


        field();
        River();

     //   Windmill_Three();

        BoatMove();

        Plough();

        Grass();
        Grass_One();
        Grass_Two();
        Grass_Three();
        Grass_Four();
        Grass_Five();
        Grass_Six();

        four_star();
        small_star();

        FlowerOne();
        FlowerTwo();
        FlowerThree();
        FlowerFour();

        Windmill_One();
        Windmill_Two();

        TractorMove();

        glFlush();
    }
}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move(){

    if(sun_mode==1){
        sun_spin = sun_spin + 0.003;
    }
    else if(sun_mode==0){
        sun_spin = sun_spin;
    }

}

void move_right(){

    sun_move();

    spin = spin + 0.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}


void DisplayOpening()
{
    if(flag==0)
        OpeningScreen();
    if(flag==1)
        Screen2();
    if(flag==2)
        display();
}


void keyboard(unsigned char action,int x,int y)
{
    switch(action)
    {
        case 13:flag=1;
                break;
        case 's':
        case 'S':
            flag=2;
            break;
        case 'n':
        case 'N':
            mode=1;
            break;
        case 'd':
        case 'D':
            mode=0;
        case 'q':
        case 'Q':
            sun_mode=1;
            break;
        case 'w':
        case 'W':
            sun_mode=0;
            break;
        case 'c':
        case 'C':
            boat_mode=0;
            break;
        case 'x':
        case 'X':
            boat_mode=-1;
            break;
        case 'v':
        case 'V':
            boat_mode=1;
            break;
        case 'z':
        case 'Z':
            boat_mode=2;
            break;
        case 27:exit(0);
    }
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                glutIdleFunc(move_right);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}



void init(void)
{
	//glClearColor(.53, .81, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("Village Simulator");
	glutDisplayFunc(DisplayOpening);
	//glutDisplayFunc(Screen2);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    init();
	glutMainLoop();
}
