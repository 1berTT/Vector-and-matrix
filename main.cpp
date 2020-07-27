#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Vetor.h"
//#include <Matriz.h>
#include <stdlib.h>
#include <stdio.h>

Vetor a = Vetor();
Vetor b = Vetor();
Vetor v = Vetor();

void init(){
    glClearColor(0.0,0.0,0.0, 1.0);//cor de fundo
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho()
}

void desenha(Vetor &v){
    glBegin(GL_TRIANGLES);
            glColor3f(0.9, 0.2, 1.0);
            glVertex3d(v.a,v.b+4, v.c);
            glVertex3d(v.a-4,v.b, v.c);
            glVertex3d(v.a+4,v.b,v.c);

    glEnd();
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    Matriz m = Matriz(1,0,0,v.a,0,1,0,v.b, 0,0,1,v.c,0,0,0,1);

    Vetor result = a.multMatriz(m);

    desenha(result);

    //glutPostRedisplay();


    glutSwapBuffers();//para atualizar a tela e mudar o buffers
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("girar");
    init();//configura a openGL
    printf("Digite o destino");
    int x,y,z = 0;
    scanf("%f, %f, %f", &x, &y, &z);
    b.a = x;
    b.b = y;
    b.c = z;
    b.d = 1;
    a.a = 25.0;
    a.b = 25.0;
    a.c = 1;
    a.d = 1;
    v = b-a;
    desenha(a);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
return 0;


/*
    TESTE PRA SABER SE TA CRIANDO CERTO
    Vetor *v =  new Vetor(10.0, 5.0,20.0,1.0);
    printf("%f", v->a);
    printf("%f", v->b);
    printf("%f", v->c);
    printf("%f", v->d);
*/

    /*
        TESTE PARA O VETOR
    Vetor v =  Vetor(10.0, 5.0,20.0,1.0);
    Vetor x =  Vetor(10.0, 5.0,20.0,1.0);
    Vetor result;
    result = x/v;
    printf("%f", result.a);
    printf("%f", result.b);
    printf("%f", result.c);
    printf("%f", result.d);*/

    /*
    TESTANDO, MULTIPLICAÇÃO DE MATRIZES(A SOMA ENTRE MATRIZES JA ESTÁ CORRETA)
    Matriz x = Matriz(2,2,2,2,3,3,3,3,5,5,5,5,1,2,3,4);
    Matriz y = Matriz(2,4,3,2,2,4,3,4,2,4,3,4,2,4,3,3);

    Matriz result;

    result = x*y;
    printf("%f", result.a);
    printf("%f", result.b);
    printf("%f", result.c);
    printf("%f", result.d);
    printf("%f", result.e);
    printf("%f", result.f);
    printf("%f", result.g);
    printf("%f", result.h);
    printf("%f", result.i);
    printf("%f", result.j);
    printf("%f", result.k);
    printf("%f", result.l);
    printf("%f", result.m);
    printf("%f", result.n);
    printf("%f", result.o);
    printf("%f", result.p);

*/
}
