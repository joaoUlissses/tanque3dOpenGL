#include <GL/glut.h>
#include <GL/glu.h>
#include "arquivosH/SOIL.h"
#include <math.h>
#include <stdio.h>

float anguloTanque = 0.0; 
float posicaoTanqueX = 0.0, posicaoTanqueZ = 0.0; 
GLuint texturaCorpo, texturaTorreta, texturaCano; 

// Função para carregar uma textura
GLuint carregarTextura(const char* caminho) {
    GLuint texturaID;
    int largura, altura, canais;
    unsigned char* imagem = SOIL_load_image(caminho, &largura, &altura, &canais, SOIL_LOAD_AUTO);
    
    if (!imagem) {
        printf("Erro ao carregar a imagem: %s\n", SOIL_last_result());
        return 0;
    }
    

    glGenTextures(1, &texturaID);
    glBindTexture(GL_TEXTURE_2D, texturaID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    GLenum formato = (canais == 4) ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, formato, largura, altura, 0, formato, GL_UNSIGNED_BYTE, imagem);
    
    SOIL_free_image_data(imagem);
    return texturaID;
}

// Função para desenhar o tanque
void desenharTanque() {
    // Corpo do tanque
    glBindTexture(GL_TEXTURE_2D, texturaCorpo);
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glScalef(2.0, 1.0, 2.5); 


    glBegin(GL_QUADS);
    // Front
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.5, -1.25);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.5, -1.25);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.5, -1.25);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.5, -1.25);
    // Back
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.5, 1.25);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.5, 1.25);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.5, 1.25);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.5, 1.25);
    // Left
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.5, -1.25);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -0.5, 1.25);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 0.5, 1.25);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.5, -1.25);
    // Right
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -0.5, -1.25);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.5, 1.25);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.5, 1.25);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 0.5, -1.25);
    // Top
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 0.5, -1.25);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.5, -1.25);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.5, 1.25);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.5, 1.25);
    glEnd();
    glPopMatrix();

    // Torreta
    glBindTexture(GL_TEXTURE_2D, texturaTorreta);
    glPushMatrix();
    glTranslatef(0.0, 0.6, 0.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glutSolidSphere(1.0, 15, 15); 
    glPopMatrix();

    // Cano da torreta
    glBindTexture(GL_TEXTURE_2D, texturaCano);
    glPushMatrix();
    glTranslatef(0.0, 0.6, 3.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glScalef(0.4, 0.4, 4.0); 
    glutSolidCube(1.0); 
    glPopMatrix();

}

// Função de exibição
void exibir() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Câmera fixa acima do tanque, olhando para baixo
    gluLookAt(0.0, 20.0, 20.0, 
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 

    glPushMatrix();
    glTranslatef(posicaoTanqueX, 0.0, posicaoTanqueZ); 
    glRotatef(anguloTanque, 0.0, 1.0, 0.0); 
    desenharTanque();
    glPopMatrix();

    glutSwapBuffers();
}

// Função para configurar a iluminação
void configurarIluminacao() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat luzAmbiente[] = { 0.8, 0.8, 0.8, 1.0 }; 
    GLfloat luzDifusa[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat luzSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat posicaoLuz[] = { 10.0, 10.0, 10.0, 1.0 }; 

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    // Configura propriedades do material para garantir visibilidade da textura
    GLfloat ambienteMaterial[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat difusoMaterial[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat especularMaterial[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat brilhoMaterial[] = { 80.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambienteMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difusoMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, brilhoMaterial);

    glShadeModel(GL_SMOOTH); // Sombreamento suave
}

// Função para inicialização
void inicializar() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    configurarIluminacao();
    texturaCorpo = carregarTextura("esteira_tanque.png");
    texturaTorreta = carregarTextura("esteira_tanque.png");
    texturaCano = carregarTextura("esteira_tanque.png");
}

// Função para processamento de teclas
void teclado(unsigned char tecla, int x, int y) {
    float velocidade = 0.5;
    float radiano = anguloTanque * M_PI / 180.0; 
    float dx = velocidade * sin(radiano); 
    float dz = velocidade * cos(radiano); 

    switch (tecla) {
        case 's':
            posicaoTanqueX -= dx;
            posicaoTanqueZ -= dz;
            break;
        case 'w':
            posicaoTanqueX += dx;
            posicaoTanqueZ += dz;
            break;
        case 'a':
            anguloTanque += 5.0;
            break;
        case 'd':
            anguloTanque -= 5.0;
            break;
    }
    glutPostRedisplay();
}


// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tanque 3D");
    inicializar();
    glutDisplayFunc(exibir);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}
