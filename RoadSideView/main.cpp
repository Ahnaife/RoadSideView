#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include <cstdio>
using namespace std;
static float cm= 500.0;
//static float sm= 50.0;
static float tp3 = 0;
bool isRedlight = false;
float _nt = 0.0;
//float _sn = 0.0;
float sun = true;
float moon = false;
//float star = false;
bool night = false;
///////function///////
void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
int i;
float rad = 0;
glBegin(GL_POLYGON);
glVertex2f(x,y);
for(i = 0;i<=360; i++){
rad = i*(3.1416/180);
glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
}
glEnd();
}
void triangle(int x, int y, int x1, int x2,int y1)
{
glBegin(GL_POLYGON);
glVertex2d(x,y);
glVertex2d(x1,y);
glVertex2d(x1,y);
glVertex2d(x2,y1);
glVertex2d(x2,y1);
glVertex2d(x,y);
glEnd();
}
void rectangle(int x, int y, int x1, int y1)
{
glBegin(GL_QUADS);
glVertex2d(x,y);
glVertex2d(x,y1);
glVertex2d(x1,y1);
glVertex2d(x1,y);

glEnd();
}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
glBegin(GL_QUADS);
glVertex2d(x1,y1);
glVertex2d(x3,y3);
glVertex2d(x4,y4);
glVertex2d(x2,y2);
glEnd();
}

void Sun(){
if (sun){
glPushMatrix();
glTranslated(200,200,0);
glColor3f(1.0, 0.76, 0.3);
circle(20,40,5,60);
//circle(20,40,0,-20);
glPopMatrix();
}
}
void Moon(){
if(moon){
glPushMatrix();
glTranslated(215,165,0);
glColor3f(1.0,1.0,1.0);
circle(20,40,20,50);
glColor3f(0.0,0.0,0.0);
circle(20,40,25,55);
glPopMatrix();
}
}
void Night(int value){

if(night){
glClearColor(0.0,0.0,0.0,0.0);
glutPostRedisplay();
glutTimerFunc(5, Night, 0);
glFlush();
}
}
void Building()
{
//1st Building:
glColor3f(1.0, 0.8, 0.3);
glRectf(-285,-35,-240,180);
//side
glColor3f(0.95, 0.50, 0.0);
glRectf(-297,-35,-285,180);
//top
glColor3f(1.0, 0.0, 0.0);
glRectf(-297,190,-240,180);
//door
//glColor3f(0.9, 0.0, 0.0);
//glRectf(-255,-35,-255,20);
//window 1
glColor3f(1.0, 1.0, 0.0);
glRectf(-280,155,-270,175);
//window 2
glColor3f(1.0, 1.0, 0.0);
glRectf(-245,155,-255,175);
//window 3
glColor3f(1.0, 1.0, 0.0);
glRectf(-280,115,-270,135);
//window 4
glColor3f(1.0, 1.0, 0.0);
glRectf(-245,115,-255,135);
//window 5
glColor3f(1.0, 1.0, 0.0);
glRectf(-280,75,-270,95);
//window 6
glColor3f(1.0, 1.0, 0.0);
glRectf(-245,75,-255,95);
//window 7
glColor3f(1.0, 1.0, 0.0);
glRectf(-280,35,-270,55);
//window 8
glColor3f(1.0, 1.0, 0.0);
glRectf(-245,35,-255,55);
//window 9
glColor3f(1.0, 1.0, 0.0);
glRectf(-280,-5,-270,15);
//window 10
glColor3f(1.0, 1.0, 0.0);
glRectf(-245,-5,-255,15);

//2nd building:
glColor3f(0.60, 0.60, 0.60);
glRectf(-230,-35,-200,180);
//side
glColor3f(0.50, 0.50, 0.50);
glRectf(-238,-35,-230,180);
//top
glColor3f(0.0, 0.0, 0.0);
glRectf(-238,190,-200,180);
//window 1
glColor3f(1.0, 1.0, 0.0);
glRectf(-228,158,-220,175);
//window 2
glColor3f(1.0, 1.0, 0.0);
glRectf(-210,158,-202,175);
//window 3
glColor3f(1.0, 1.0, 0.0);
glRectf(-228,118,-220,135);
//window 4
glColor3f(1.0, 1.0, 0.0);
glRectf(-210,118,-202,135);
//window 5
glColor3f(1.0, 1.0, 0.0);
glRectf(-228,78,-220,95);
//window 6
glColor3f(1.0, 1.0, 0.0);
glRectf(-210,78,-202,95);
//window 7
glColor3f(1.0, 1.0, 0.0);
glRectf(-228,38,-220,55);
//window 8
glColor3f(1.0, 1.0, 0.0);
glRectf(-210,38,-202,55);
//window 9
glColor3f(1.0, 1.0, 0.0);
glRectf(-228,-2,-220,15);
//window 10
glColor3f(1.0, 1.0, 0.0);
glRectf(-210,-2,-202,15);

//3rd building:
glColor3f(0.0, 0.0, 1.50);
glRectf(-198,-35,-166,160);
//side
glColor3f(0.0, 0.0, 0.0);
glRectf(-166,-35,-158,160);
//window1
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,140,-188,155);
//window2
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,140,-169,155);
//window3
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,115,-188,130);
//window4
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,115,-169,130);
//window5
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,90,-188,105);
//window6
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,90,-169,105);
//window7
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,65,-188,80);
//window8
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,65,-169,80);
//window9
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,40,-188,55);
//window10
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,40,-169,55);
//window11
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,15,-188,30);
//window12
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,15,-169,30);
//window13
glColor3f(1.0, 1.0, 1.0);
glRectf(-195,-8,-188,7);
//window14
glColor3f(1.0, 1.0, 1.0);
glRectf(-176,-8,-169,7);

//4th building:
glColor3f(0.40, 0.40, 0.40);
glRectf(-157,-35,-121,170);
//window1
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,155,-146,165);
//window2
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,155,-136,165);
//window3
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,155,-126,165);
//window4
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,125,-146,135);
//window5
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,125,-136,135);
//window6
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,125,-126,135);
//window7
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,95,-146,105);
//window8
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,95,-136,105);
//window9
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,95,-126,105);
//window10
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,65,-146,75);
//window11
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,65,-136,75);
//window12
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,65,-126,75);
//window13
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,35,-146,45);
//window14
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,35,-136,45);
//window15
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,35,-126,45);
//window16
glColor3f(1.0, 1.0, 1.0);
glRectf(-152,5,-146,15);
//window17
glColor3f(1.0, 1.0, 1.0);
glRectf(-142,5,-136,15);
//window18
glColor3f(1.0, 1.0, 1.0);
glRectf(-132,5,-126,15);

//Shop:
glColor3f(1.0, 1.0, 1.0);
glRectf(-118,-35,-42,50);
//top
glColor3f(0.80, 0.80, 0.80);
glRectf(-118,120,-42,50);
//top1
glColor3f(0.90, 0.0, 0.0);
glRectf(-119,155,-41,120);
//design
glColor3f(0.10, 0.10, 0.10);
glRectf(-112,-35,-110,50);

glColor3f(0.10, 0.10, 0.10);
glRectf(-90,-35,-88,50);

glColor3f(0.10, 0.10, 0.10);
glRectf(-70,-35,-68,50);

glColor3f(0.10, 0.10, 0.10);
glRectf(-50,-35,-48,50);

//station
glColor3f(0.50, 0.50, 0.40);
glRectf(75,-35,78,135);
glRectf(78,110,180,115);
//top
glRectf(65,140,193,135);
//bottom
glRectf(78,0,180,5);
//top 1
glRectf(65,180,193,181);
//design (3bar)
glRectf(65,135,68,180);
glRectf(90,135,93,180);
glRectf(115,135,118,180);
glRectf(140,135,143,180);
glRectf(165,135,168,180);
//design 1(2 bar)
glRectf(110,-35,113,135);
glRectf(145,-35,148,135);
//right side
glRectf(180,-35,183,135);
glRectf(190,135,193,180);
//seat
glColor3f(1.0, 0.9, 0.4);
glRectf(118,15,175,30);
//stand
glColor3f(1.0, 0.7, 0.2);
glRectf(121,-35,124,15);
glRectf(169,-35,172,15);
/*
glRectf(70,-35,73,150);
glRectf(73,150,180,145);
*/

//Upper Tree 1
glColor3f(0.501, 0.231, 0.035);
glRectf(-40,-35,-30,25);
//tringle
glColor3f(0.0, 0.30, 0.0);
triangle(-60,25,-10,-35,65);
glColor3f(0.0, 0.40, 0.0);
triangle(-60,45,-10,-35,80);
glColor3f(0.0, 0.50, 0.0);
triangle(-60,65,-10,-35,105);
//Upper Tree 2
glColor3f(0.501, 0.231, 0.035);
glRectf(55,-35,65,25);
//tringle
glColor3f(0.0, 0.30, 0.0);
triangle(35,25,85,60,65);
glColor3f(0.0, 0.40, 0.0);
triangle(35,45,85,60,80);
glColor3f(0.0, 0.50, 0.0);
triangle(35,65,85,60,105);
//Upper Tree 1:
glColor3f(0.501, 0.231, 0.035);
glRectf(220,-35,230,25);
//tringle
glColor3f(0.0, 0.30, 0.0);
triangle(200,25,250,225,65);
glColor3f(0.0, 0.40, 0.0);
triangle(200,45,250,225,80);
glColor3f(0.0, 0.50, 0.0);
triangle(200,65,250,225,105);

}
void ground()
{
glColor3f(0.790, 0.450, 0.205);
rectangle(-300,-300,300,-10);
}
void tree()
{
//Ground Tree 1
glColor3f(0.501, 0.231, 0.035);
glRectf(200,-300,210,-230);
//tringle
glColor3f(0.0, 0.30, 0.0);
triangle(180,-230,230,205,-180);
glColor3f(0.0, 0.40, 0.0);
triangle(180,-200,230,205,-140);
glColor3f(0.0, 0.50, 0.0);
triangle(180,-170,230,205,-110);
}

void road()
{
//Road Area
glColor3f(0.3, 0.3, 0.3);
rectangle(-300,-140,300,-30);
//road side broader up
glColor3f(0.0, 0.0, 0.0);
rectangle(-300,-30,300,-33);
//road side broader down
glColor3f(0.0, 0.0, 0.0);
rectangle(-300,-143,300,-140);
//divider
glColor3f(1.0, 1.0, 1.0);
rectangle(-270,-80,-230,-86);
//divider
glColor3f(1.0, 1.0, 1.0);
rectangle(-270,-80,-200,-86);
//divider
glColor3f(1.0, 1.0, 1.0);
rectangle(-150,-80,0,-86);
//divider
glColor3f(1.0, 1.0, 1.0);
rectangle(50,-80,150,-86);
//divider
glColor3f(1.0, 1.0, 1.0);
rectangle(200,-80,290,-86);
}
void makeprivatecar(){
//1st left car circle
glColor3f(0.902, 0.902, 0.980);
circle(8,14,2,1);
//middle rectangle
rectangle(0,-10,60,15);
//right one
rectangle1(60,-10,80,-10,60,15,80,5);
// left upper triangle
glColor3f(0.184, 0.310, 0.310);
triangle(5,15,20,20,40);
glColor3f(0.0, 0.0, 1.0);
triangle(40,15,60,40,40);
//upper middle one
glColor3f(0, 0, 1.0);
rectangle(20,15,40,40);
// black wheel round
glColor3f(0, 0, 0);
circle(7,14,10,-10);
circle(7,14,60,-10);
// wheel white
glColor3f(1.000, 0.973, 0.863);
circle(5,10,10,-10);
circle(5,10,60,-10);
}
void privatecarMove(){
if (isRedlight)
{
cm +=0;
}
else
{ cm=cm+.2;
}
if(cm>500)
{
cm = -500;
}
glutPostRedisplay();
}
void privatecar()
{
privatecarMove();
{
if (isRedlight)
{
glColor3f( 0.000, 0.00, 0.000);
circle(3,4,44,90);
}
else
{
glColor3f(0.000, 0.000, 0.000);
circle(3,4,44,70);
}
glPushMatrix();
glTranslatef(cm,-50,0);
makeprivatecar();
glPopMatrix();
}
}
void Light()
{
//traffic light
//lower part
glColor3f( 0.412, 0.412, 0.412);
rectangle(45,63,42,-10);
//box part
glColor3f(0.85, 0.85, 0.85);
rectangle(49,60,39,100);
//1st
glColor3f(0.0, 0.60, 0.0);
circle(3,4,44,90);
//glColor3f(0.196, 0.804, 0.196);
// circle(3,4,44,80);
glColor3f( 0.90, 0.0, 0.0);
circle(3,4,44,70);
}
void make_cloud(int x, int y)
{
glColor3f(1.0, 1.0, 1.0);
circle(10,10,x,y);
circle(10,10,x+10,y);
circle(10,10,x+30,y);
circle(10,10,x+5,y-10);
circle(10,10,x+20,y-10);
circle(10,10,x+5,y+10);
circle(10,10,x+20,y+10);
}
void cloud_move_right(GLfloat t){
tp3=tp3+t;
if(tp3>600)
tp3 = -300;
glutPostRedisplay();
}
void cloud()
{
glPushMatrix();
glTranslatef(tp3,0,0);
make_cloud(-300,280);
make_cloud(-500,280);
make_cloud(-200,250);
make_cloud(-400,250);
make_cloud(200,250);
make_cloud(-100,250);
make_cloud(-350,230);
glPopMatrix();
cloud_move_right(.1);
glEnd();
}
void street()
{
//Road Area
glColor3f(0.753, 0.753, 0.753);
rectangle(-300,-185,300,-150);
glColor3f(0.663, 0.663, 0.663);
rectangle(-300,-210,300,-185);
//road side broader down
glColor3f(0.412, 0.412, 0.412);
//rectangle(-300,-150,300,-148);
//road side broader up
glColor3f(0.412, 0.412, 0.412);
// rectangle(-300,-185,300,-187);
//road side broader down
glColor3f(0.412, 0.412, 0.412);
//rectangle(-300,-210,300,-212);
//divider
glColor3f(0.412, 0.412, 0.412);
rectangle(-290,-210,-291,-185);
rectangle(-245,-210,-246,-185);
rectangle(-200,-210,-201,-185);
rectangle(-155,-210,-156,-185);
rectangle(-110,-210,-111,-185);
rectangle(-65,-210,-66,-185);
rectangle(-20,-210,-21,-185);
rectangle(25,-210,26,-185);
rectangle(70,-210,71,-185);
rectangle(115,-210,116,-185);
rectangle(160,-210,161,-185);
rectangle(205,-210,206,-185);
rectangle(250,-210,251,-185);
rectangle(295,-210,296,-185);
int i = 0;
glColor3f( 0.827, 0.827, 0.827);
glBegin(GL_QUADS);
for(i=-300;i<=300;i=i+45){
glVertex2d(i+8,-185);
glVertex2d(i+9,-185);
glVertex2d(i+25,-150);
glVertex2d(i+26,-150);
}
glEnd();
}
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 'r':
isRedlight = true;
break;
case 'g':
isRedlight = false;
break;
case 'n':
night = true;
Night(_nt);
sun=false;
moon = true;
//star = true;
break;
case 'd':
sun=true;
night = false;
moon = false;
glClearColor(0.3, .65, 1, 1.0);
break;
default:
break;
}
}
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
Sun();
Moon();
Building();
ground();
road();
street();
tree();
cloud();
Light();
privatecar();
glFlush();
}
void init()
{
glClearColor(0.3, .70, 1, 1.0);
glOrtho(-300,300,-300,300,-150,500);
}
int main()
{
cout << "**********Welcome***********" << endl;
cout << "press 'r' FOR Red Light " << endl;
cout << "press 'g' FOR Green Light " << endl;
cout << "press 'd' FOR DAY " << endl;
cout << "press 'n' FOR Night " << endl;

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1200,600);
glutInitWindowPosition(60,60);
glutCreateWindow("Road Side view");
init();
glutDisplayFunc(myDisplay);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
