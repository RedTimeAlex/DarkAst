#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

#include <SOIL/SOIL.h>

int main(int argc, char** argv)
{
    //create GL context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("windowname");

    //upload to GPU texture
    GLuint tex = SOIL_load_OGL_texture
	    (
	     "dirt.png",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
	    );
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    //match projection to window resolution (could be in reshape callback)
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 800, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    //clear and draw quad with texture (could be in display callback)
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0); glVertex2i(100, 100);
    glTexCoord2i(0, 1); glVertex2i(100, 500);
    glTexCoord2i(1, 1); glVertex2i(500, 500);
    glTexCoord2i(1, 0); glVertex2i(500, 100);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFlush(); //don't need this with GLUT_DOUBLE and glutSwapBuffers

    getchar(); //pause so you can see what just happened
    //System("pause"); //I think this works on windows

    return 0;
}
