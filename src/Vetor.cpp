#include "Vetor.h"

Vetor::Vetor(float x, float y, float z, float w){
    this->a = x;
    this->b = y;
    this->c = z;
    this->d = w;

}

Vetor::operator+(Vetor v){
    return Vetor(this->a + v.a, this->b + v.b, this->c + v.c, this->d + v.d);
}

