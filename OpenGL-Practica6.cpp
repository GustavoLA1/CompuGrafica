#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

GLsizei winWidth=700, winHeight=480;

void IniciarOpenGL (void) {
	glShadeModel( GL_FLAT );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glShadeModel(GL_SMOOTH);				
	glClearDepth(1.0);					
	glEnable(GL_DEPTH_TEST);			
	glDepthFunc(GL_LEQUAL);
}

void Dibujar (void) { 
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	//Su código aquí
	
	
	glFlush(); 
}

void RedimensionVentana (int x,int y ) {
	glViewport (10, 10, x, y);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)x/(GLfloat)y,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);     
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(300,300);
	glutInitWindowSize(winWidth, winHeight); 
	glutCreateWindow("teteta");
	IniciarOpenGL();
	glutDisplayFunc(Dibujar); 
	glutReshapeFunc(RedimensionVentana);
	glutMainLoop(); 
}
