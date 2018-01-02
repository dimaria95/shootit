#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <GL/glut.h>
#include "field.h"


#define PI 3.141592653589793

void draw_field(void){
    
    
    glPushMatrix();
    
        draw_freethrow(7);
    
        draw_floor();
        
        
    glPopMatrix();
}

void draw_floor(){
    glPushMatrix();
    
        fieldMaterialSetup();
        glTranslatef(10,-40,0);
        glRotatef(90,1,0,0);
        glScalef(2.5,2.5,0.1);
        glutSolidCube(70);
        
        
    glPopMatrix();
}


void fieldMaterialSetup(){

    GLfloat fieldAmbient[] = {0.913,0.71,0.51,1};
    GLfloat fieldDiffuse[] = {0.1,0.1,0.1,1};
    GLfloat fieldSpecular[] = {0,0,0,1};
    GLfloat shiness_field = 20;
   
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,fieldAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,fieldDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,fieldSpecular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_field);
        
    
}

void draw_freethrow(float r){
    
    glDisable(GL_LIGHTING);
    float i;
    glPushMatrix();
    
    
    glColor3f(0.9,0.9,0.9);
  
    glTranslatef(-20,-36,0);
    glRotatef(90,0,1,0); 
    glScalef(3,0,3);
    
    
    
    
    
    /*lines for freethrow */
    glBegin(GL_LINES);
            glVertex3f(-r,0,-(r+5));
            glVertex3f(-r,0,0);
            glVertex3f(r,0,-(r+5));
            glVertex3f(r,0,0);
    glEnd();
    
    /*half circle for freethrow */
    glBegin(GL_LINE_LOOP);
        for(i = 0 ; i <= PI + 0.01 ; i+= PI/100){ 
            glVertex3f(r*cos(i) ,0,  r*sin(i));
        }
    glEnd();
    
    
    /*three point half circle */
     glBegin(GL_LINE_STRIP);
        for(i = 0 ; i <=  PI + 0.01 ; i+= PI/100){ 
            glVertex3f(3.2*r*cos(i) ,0,  3.2*r*sin(i));
        }
    glEnd();
    
    /* three point lines */
    glBegin(GL_LINES);
            glVertex3f(-3.2*r,0,-(r+5));
            glVertex3f(-3.2*r,0,0);
            glVertex3f(3.2*r,0,-(r+5));
            glVertex3f(3.2*r,0,0);
    glEnd();
    
    /* draw inbound lines */
    glBegin(GL_LINES);
            glVertex3f(-4.1*r,0,-(r+5));
            glVertex3f(4.1*r,0,-(r+5));
    glEnd();
    
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

