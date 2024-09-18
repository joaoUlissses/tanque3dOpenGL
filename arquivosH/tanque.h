#ifndef TANQUE_H
#define TANQUE_H
#include <GL/freeglut.h>

void quadrado(GLuint texid, float Ybaixo, float Ycima, float Xesquerda,     
                                    float Xdireita, float Zfrente, float Zatras) {
    
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


void torre (GLuint texid, float Ybaixo, float Ycima, float Xesquerda, 
                                    float Xdireita, float Zfrente, float Zatras) {  
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
#endif