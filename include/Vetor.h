#ifndef VETOR_H
#define VETOR_H
#include "Matriz.h"


class Vetor
{
    public:
        float a;
        float b;
        float c;
        float d;
        Vetor(float x=0, float y=0, float z=0, float w =0){
            this->a = x;
            this->b = y;
            this->c = z;
            this->d = w;
        }

        Vetor operator+(Vetor &v);
        Vetor operator-(Vetor &v);
        Vetor operator*(Vetor &v);
        int operator>>(Vetor &v);
        Vetor operator/(Vetor &v);
        Vetor multMatriz(Matriz &m);
};

Vetor Vetor::operator+(Vetor &v){
    return Vetor(this->a + v.a, this->b + v.b, this->c + v.c, this->d + v.d);
}

Vetor Vetor::operator-(Vetor &v){
    return Vetor(this->a - v.a, this->b - v.b, this->c - v.c, this->d - v.d);
}

Vetor Vetor::operator*(Vetor &v){
    return Vetor(this->a * v.a, this->b * v.b, this->c * v.c, this->d * v.d);
}

int Vetor::operator>>(Vetor &v){
    return (this->a * v.a) + (this->b * v.b) + (this->c * v.c) + (this->d * v.d);
}

Vetor Vetor::operator/(Vetor &v){
    return Vetor(this->a / v.a, this->b / v.b, this->c / v.c, this->d / v.d);
}

Vetor Vetor::multMatriz(Matriz &m){
/*
    int x = (m.a * this->a) + (m.b * this->b) + (m.c * this->c) + (m.d * this->d);
    int y = (m.e * this->a) + (m.f * this->b) + (m.g * this->c) + (m.h * this->d);
    int z = (m.i * this->a) + (m.j * this->b) + (m.k * this->c) + (m.l * this->d);
    int w = (m.m * this->a) + (m.n * this->b) + (m.o * this->c) + (m.p * this->d);

    return Vetor(x,y,z,w);*/

    return NULL;
}



#endif // VETOR_H
