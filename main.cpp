#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;
void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(5.0, 5.0, 0.0, 5.0);
    gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

}
void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
		if(key=='a')
			glutIdleFunc(spinDisplay);

		else if(key=='c')
			glutIdleFunc(spinDisplayReverse);

}
void init (void)
{
    glClearColor (0.5, 0.5, 0.5, 0.0);
    glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);

}

void drawFan()
{
	glTranslatef(translate_x, translate_y, translate_z);

	glRotatef(spin,spin_x,spin_y,spin_z);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.5);
	glVertex2i(0, 0);
	glVertex2i(-2, 5);
	glVertex2i(2, 5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2i(0, 0);
	glVertex2i(5, 2);
	glVertex2i(5, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(0, 0);
	glVertex2i(-2, -5);
	glVertex2i(2, -5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(0, 0);
	glVertex2i(-5, 2);
	glVertex2i(-5, -2);
	glEnd();
}


void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
 drawFan();
  glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 400);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("===18CS30 ==");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
        init ();
           glutMainLoop();
}
