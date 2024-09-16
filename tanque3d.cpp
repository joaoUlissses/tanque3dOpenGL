#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "arquivosH/stb_image.h"
#include "arquivosH/SOIL.h"
#include <string>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
   
GLUquadric* quad;
float anguloTanque = 0.0;
float tanquePosX = 0.0, tanquePosZ =0.0;
GLuint texID, texID1, texID2;

void carregarTextura(GLuint tex_id, std::string filePath) {
    unsigned char* imgData;
    int largura, altura, canais;

    imgData = stbi_load(filePath.c_str(), &largura, &altura, &canais, 4);
    if (imgData) {
        glBindTexture(GL_TEXTURE_2D, tex_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, largura, altura, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        stbi_image_free(imgData);
    }
    else {
        std::cout << "ERROR:: nao foi possivel carregar a textura! " << filePath << std::endl;
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(3, &texID);
    carregarTextura(texID, "imagens/esteira_tanque.png");
    carregarTextura(texID1,"imagens/aco.jpeg");
    carregarTextura(texID2,"imagens/darkMetal.jpeg");
}

void quadrado(GLuint texid, float Ybaixo, float Ycima, float Xesquerda, float Xdireita, float Zfrente, float Zatras) {
    
        glBindTexture(GL_TEXTURE_2D, texid);
        glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        // Frente
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zfrente);  // a
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zfrente);   // b
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d

        // Traseira
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zatras);    // e
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g

        // Superior
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g

        // Inferior
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zfrente);  // a
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zfrente);   // b
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ybaixo, Zatras);    // e
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ybaixo, Zatras);   // h

        // Direita
         glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zfrente);   // b
         glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ybaixo, Zatras);    // e
         glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
         glTexCoord2f(1.0, 1.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c

        // Esquerda
         glTexCoord2f(0.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zfrente);  // a
         glTexCoord2f(0.0, 0.0); glVertex3f(Xesquerda, Ybaixo, Zatras);   // h
         glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
         glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
    glEnd();

    glDisable(GL_TEXTURE_2D);  // Desativa a textura após desenhar o quadrado
}
void torre (GLuint texid, float Ybaixo, float Ycima, float Xesquerda, float Xdireita, float Zfrente, float Zatras) {  
        glBindTexture(GL_TEXTURE_2D, texid);
        glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        // Frente
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zfrente-0.3);  // a
        glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita+0.3, Ybaixo, Zfrente-0.3);   // b
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);           // c
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);          // d

        // Traseira
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zatras);    // e
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g

        // Superior
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
        
        // Direita
         glTexCoord2f(1.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zfrente-0.3);   // b
         glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zatras);    // e
         glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
         glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c

        // Esquerda
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zfrente-0.3);  // a
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 1.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
        glTexCoord2f(0.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
    glEnd();

    glDisable(GL_TEXTURE_2D);  // Desativa a textura após desenhar o quadrado
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);

    glPushMatrix();
    glTranslatef(tanquePosX,0.0,tanquePosZ);
    glRotatef(anguloTanque,0.0,1.0,0.0);

    // corpo principal
    quadrado(texID1, -1.0, 0.5, -1.0, 1.0, 1.4, -1.4);
    
    // torre 
    torre(texID1, 0.5, 1.3, -0.5, 0.5, -0.7, 0.4);
    
    // canhão
    quadrado(texID2, 0.7, 1.0, -0.2, 0.2, 0.4, 2.4);
    
    // roda esquerda 
    quadrado(texID, -1.2, -0.5, 1.7, 0.7, 1.9, -1.9);
    
    // roda direita
    quadrado(texID, -1.2, -0.5, -1.7, -0.7, 1.9, -1.9);
     glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}
void teclado(unsigned char tecla, int x, int y) {
    float velocidade = 0.5;
    float radiano = anguloTanque * M_PI / 180.0; 
    float dx = velocidade * sin(radiano); 
    float dz = velocidade * cos(radiano); 

    switch (tecla) {
        case 's':
            tanquePosX -= dx;
            tanquePosZ -= dz;
            break;
        case 'w':
            tanquePosX += dx;
            tanquePosZ += dz;
            break;
        case 'a':
            anguloTanque += 5.0;
            break;
        case 'd':
            anguloTanque -= 5.0;
            break;
            case 'd'+'s':
            anguloTanque-= 5.0;
            tanquePosX -= dx;
            tanquePosZ -= dz;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("tanque 3D");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(teclado);
    glutPostRedisplay(); // Chama a função idle continuamente para animar o cubo

    glutMainLoop();
    return 0;
}