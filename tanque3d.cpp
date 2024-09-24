#include <stdlib.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include"arquivosH/tanque.h"
#include "arquivosH/stb_image.h"
#include "arquivosH/SOIL.h"
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
   
GLUquadric* quad;
float anguloTanque = 0.0;
float tanquePosX = 0.0, tanquePosZ =0.0, camView = 25.0;
GLuint texID, texID1, texID2, texID3;
bool keys[256]; 

void cameraSeguirTorre() {
    float torrePosX = tanquePosX;
    float torrePosY = 1.5;
    float torrePosZ = tanquePosZ;

    // Cálculo da posição da câmera atrás da torre
    float distanciaCamera = 12.0;  // Distância da câmera em relação à torre
    float alturaCamera = 2.0;     // Altura da câmera em relação ao chão

    float anguloRadianos = (camView + anguloTanque) * M_PI / 180.0;

    float cameraPosX = torrePosX - distanciaCamera * sin(anguloRadianos);
    float cameraPosY = torrePosY + alturaCamera;
    float cameraPosZ = torrePosZ - distanciaCamera * cos(anguloRadianos);

    float verAtX = torrePosX;
    float verAtY = torrePosY;
    float verAtZ = torrePosZ;

    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,
              verAtX, verAtY, verAtZ,
              0.0, 1.0, 0.0);
}

void keyDown(unsigned char tecla, int x, int y) {
    keys[tecla] = true;  // Marca a tecla como pressionada
}

void keyUp(unsigned char tecla, int x, int y) {
    keys[tecla] = false;  // Marca a tecla como solta
}

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
    carregarTextura(texID3,"imagens/grama.jpeg");
}
void mapa(float x,float x2,float y,float z,float z2){
    glBindTexture(GL_TEXTURE_2D,texID3);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glTexCoord2f(1.0, 1.0); glVertex3f(x, y, z);  // a
        glTexCoord2f(0.0, 1.0); glVertex3f(x2, y, z);   // b
        glTexCoord2f(0.0, 0.0); glVertex3f(x2, y, z2);    // e
        glTexCoord2f(1.0, 0.0); glVertex3f(x, y, z2);   // h
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Configurar a câmera para seguir a torre
    cameraSeguirTorre();

    glPushMatrix();
    // Desenhar o mapa
    mapa(-150, 150, -1.5, 50, -50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tanquePosX, 0.0, tanquePosZ);
    glRotatef(anguloTanque, 0.0, 1.0, 0.0);

    // Corpo principal do tanque
    quadrado(texID1, -1.0, 0.5, -1.0, 1.0, 1.4, -1.4);

    // Rodas esquerda e direita
    quadrado(texID, -1.2, -0.5, 1.7, 0.7, 1.9, -1.9);  // Roda esquerda
    quadrado(texID, -1.2, -0.5, -1.7, -0.7, 1.9, -1.9); // Roda direita

    // Torre rotacionável
    glPushMatrix();
    glRotatef(camView, 0.0, 1.0, 0.0);
    torre(texID1, 0.5, 1.3, -0.5, 0.5, -0.7, 0.4);

    // Canhão
    quadrado(texID2, 0.7, 1.0, -0.2, 0.2, 0.4, 2.4);
    glPopMatrix();
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
void update() {
    float velocidade = 0.1;
    float radiano = anguloTanque * M_PI / 180.0;
    float dx = velocidade * sin(radiano);
    float dz = velocidade * cos(radiano);

    // Verificar quais teclas estão pressionadas e ajustar os movimentos
    if (keys['w']) {
        tanquePosX += dx;
        tanquePosZ += dz;
    }
    if (keys['s']) {
        tanquePosX -= dx;
        tanquePosZ -= dz;
    }
    if (keys['a']) {
        anguloTanque += 1.0;  // Rotação mais suave
        camView -=1.0;
    }
    if (keys['d']) {
        anguloTanque -= 1.0;  // Rotação mais suave
        camView+=1.0;
    }
    if (keys['j']){
        camView+=1.0;
    }
    if(keys['l']){
        camView-=1.0;
    }
    

    glutPostRedisplay();  // Redesenha a cena
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1260, 720);
    glutCreateWindow("tanque 3D");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    
    glutIdleFunc(update);
    glutPostRedisplay(); // Chama a função idle continuamente para animar o cubo

    glutMainLoop();
    return 0;
}