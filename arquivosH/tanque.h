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
         glTexCoord2f(1.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zfrente);   // b
         glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zatras);    // e
         glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
         glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c

        // Esquerda
         glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zfrente);  // a
         glTexCoord2f(0.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zatras);   // h
         glTexCoord2f(0.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
         glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
    glEnd();

    glDisable(GL_TEXTURE_2D);  // Desativa a textura após desenhar o quadrado
}
void quadrado_roda(GLuint texid, GLuint texid2, float Ybaixo, float Ycima, float Xesquerda, float Xdireita, float Zfrente, float Zatras) {
    
    // Frente e Traseira usam texid
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
    glEnd();

    // Superior e Inferior usam texid
    glBegin(GL_QUADS);
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
    glEnd();

    // Direita e Esquerda usam texid2
    glBindTexture(GL_TEXTURE_2D, texid2);  // Troca para a segunda textura
    glBegin(GL_QUADS);
        // Direita
        glTexCoord2f(1.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zfrente);   // b
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ybaixo, Zatras);    // e
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c

        // Esquerda
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zfrente);  // a
        glTexCoord2f(0.0, 1.0); glVertex3f(Xesquerda, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
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
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zfrente-0.3);   // b
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);           // c
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);          // d

        // Traseira
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zatras);    // e
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g

        // Superior
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
        glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c
        glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
        
        // Direita
         glTexCoord2f(1.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zfrente-0.3);   // b
         glTexCoord2f(0.0, 1.0); glVertex3f(Xdireita+0.3, Ybaixo, Zatras);    // e
         glTexCoord2f(0.0, 0.0); glVertex3f(Xdireita, Ycima, Zatras);     // f
         glTexCoord2f(1.0, 0.0); glVertex3f(Xdireita, Ycima, Zfrente);    // c

        // Esquerda
        glTexCoord2f(1.0, 1.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zfrente-0.3);  // a
        glTexCoord2f(0.0, 1.0); glVertex3f(Xesquerda-0.3, Ybaixo, Zatras);   // h
        glTexCoord2f(0.0, 0.0); glVertex3f(Xesquerda, Ycima, Zatras);    // g
        glTexCoord2f(1.0, 0.0); glVertex3f(Xesquerda, Ycima, Zfrente);   // d
    glEnd();

    glDisable(GL_TEXTURE_2D);  // Desativa a textura após desenhar o quadrado
}
 void arvore(float X, float Y){
    

    glBegin(GL_QUADS);
    glColor3f(0.65, 0.16, 0.16);  // Define a cor marrom
         // Frente
        glVertex3f(X, -1.0, Y);         // a
        glVertex3f(X+2.0, -1.0, Y);     // b
        glVertex3f(X+2.0, 4.0, Y);     // c
        glVertex3f(X, 4.0, Y);         // d

        // Traseira
        glVertex3f(X, -1.0, Y+2.0);     // h
        glVertex3f(X+2.0, -1.0, Y+2.0); // e
        glVertex3f(X+2.0, 4.0, Y+2.0); // f
        glVertex3f(X, 4.0, Y+2.0);     // g
        //direita
        glVertex3f(X+2.0, -1.0, Y);     // b
        glVertex3f(X+2.0, -1.0, Y+2.0); // e
        glVertex3f(X+2.0, 4.0, Y+2.0); // f
        glVertex3f(X+2.0, 4.0, Y);     // c
        //esquerda
        glVertex3f(X, -1.0, Y);         // a
        glVertex3f(X, -1.0, Y+2.0);     // h
        glVertex3f(X, 4.0, Y+2.0);     // g
        glVertex3f(X, 4.0, Y);         // d

    //folhas 
    glColor3f(0.0, 1.0, 0.0);  
         // Frente
        glVertex3f(X-2.0, 4.0, Y-2.0);         // a
        glVertex3f(X+4.0, 4.0, Y-2.0);     // b
        glVertex3f(X+4.0, 9.0, Y-2.0);     // c
        glVertex3f(X-2.0, 9.0, Y-2.0);         // d

        // Traseira
        glVertex3f(X-2.0, 4.0, Y+4.0);     // h
        glVertex3f(X+4.0, 4.0, Y+4.0); // e
        glVertex3f(X+4.0, 9.0, Y+4.0); // f
        glVertex3f(X-2.0, 9.0, Y+4.0);     // g
        //direita
        glVertex3f(X+4.0, 4.0, Y-2.0);     // b
        glVertex3f(X+4.0, 4.0, Y+4.0); // e
        glVertex3f(X+4.0, 9.0, Y+4.0); // f
        glVertex3f(X+4.0, 9.0, Y-2.0);     // c
        //esquerda
        glVertex3f(X-2.0, 4.0, Y-2.0);         // a
        glVertex3f(X-2.0, 4.0, Y+4.0);     // h
        glVertex3f(X-2.0, 9.0, Y+4.0);     // g
        glVertex3f(X-2.0, 9.0, Y-2.0);         // d
        //baixo
        glVertex3f(X-2.0, 4.0, Y-2.0);         // a
        glVertex3f(X+4.0, 4.0, Y-2.0);     // b
        glVertex3f(X-2.0, 4.0, Y+4.0);     // h
        glVertex3f(X+4.0, 4.0, Y+4.0); // e

    glColor3f(0.0,1.0,0.0);
    glEnd();
}

  void gerarFloresta(){
arvore(-25.4, 88.3);arvore(72.1, -56.7);arvore(-113.2, 42.5);arvore(39.8, 117.6);arvore(81.0, -23.9);arvore(-47.5, 90.2);arvore(115.3, 66.0);arvore(-82.7, -105.5);arvore(22.8, -14.9);arvore(5.6, 45.1);arvore(-68.9, 102.7);arvore(60.2, -12.4);arvore(-130.0, 78.6);arvore(33.4, -66.3);arvore(-12.1, 127.5);arvore(100.4, 53.9);arvore(-71.7, -36.8);arvore(54.3, 29.2);
arvore(-89.4, 109.1);arvore(7.7, -120.5);arvore(-104.6, 38.0);arvore(-62.3, 74.1);arvore(115.6, -89.4);arvore(-48.7, 20.5);arvore(93.1, 134.2);arvore(-110.5, -60.3);arvore(76.8, -42.1);arvore(-25.4, 118.0);arvore(31.6, 56.9);arvore(-89.2, -97.8);arvore(56.5, 3.4);arvore(-23.7, 102.5);arvore(12.9, -88.6);arvore(95.4, 64.3);arvore(-130.0, -45.7);arvore(77.8, 12.2);arvore(45.0, -114.3);arvore(-90.1, 57.4);arvore(33.3, -120.9);arvore(-66.6, 89.0);arvore(100.1, -73.5);arvore(-48.2, 110.3);arvore(58.7, -19.4);arvore(-12.0, -37.8);arvore(74.5, 118.4);
arvore(-100.2, 47.1);arvore(29.5, -84.9);arvore(-57.9, 73.6);arvore(85.3, -33.0);arvore(-24.1, 11.5);arvore(115.0, -29.6);arvore(-30.6, 130.0);arvore(67.2, -2.4);arvore(-130.0, 0.0);arvore(50.6, 92.7);arvore(-81.5, -56.4);arvore(36.8, 48.3);
  }
#endif