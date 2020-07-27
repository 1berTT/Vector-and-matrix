#ifndef MATRIZ_H
#define MATRIZ_H
#include <Vetor.h>


class Matriz
{
    public:
        float a;
        float b;
        float c;
        float d;
        float e;
        float f;
        float g;
        float h;
        float i;
        float j;
        float k;
        float l;
        float m;
        float n;
        float o;
        float p;
        Matriz(float a1=0,float b1=0,float c1=0,float d1=0,float e1=0,float f1=0,float g1=0,float h1=0,float i1=0,float j1=0,float k1=0,float l1=0,float m1=0,float n1=0,float o1=0,float p1=0){
            this->a = a1;
            this->b = b1;
            this->c = c1;
            this->d = d1;
            this->e = e1;
            this->f = f1;
            this->g = g1;
            this->h = h1;
            this->i = i1;
            this->j = j1;
            this->k = k1;
            this->l = l1;
            this->m = m1;
            this->n = n1;
            this->o = o1;
            this->p = p1;
        }
        Matriz(Vetor x, Vetor y, Vetor z, Vetor w){
            this->a = x.a;
            this->b = x.b;
            this->c = x.c;
            this->d = x.d;
            this->e = y.a;
            this->f = y.b;
            this->g = y.c;
            this->h = y.d;
            this->i = z.a;
            this->j = z.b;
            this->k = z.c;
            this->l = z.d;
            this->m = w.a;
            this->n = w.b;
            this->o = w.c;
            this->p = w.d;
        }

        Matriz operator+(Matriz &v);
        Matriz operator-(Matriz &v);
        Matriz operator*(Matriz &v);
        Vetor getLine(Matriz &v,int i);
        Vetor getColumn(Matriz &v, int i);
        Matriz transposta(Matriz &v, int i);

};

Matriz Matriz::operator+(Matriz &v){
    Vetor x = Vetor(this->a, this->b, this->c,this->d);
    Vetor y = Vetor(this->e, this->f, this->g,this->h);
    Vetor z = Vetor(this->i, this->j, this->k,this->l);
    Vetor w = Vetor(this->m, this->n, this->o,this->p);

    Vetor x1 = Vetor(v.a, v.b, v.c, v.d);
    Vetor y1 = Vetor(v.e, v.f, v.g, v.h);
    Vetor z1 = Vetor(v.i, v.j, v.k, v.l);
    Vetor w1 = Vetor(v.m, v.n, v.o,v.p);

    Vetor result1 = x + x1;
    Vetor result2 = y + y1;
    Vetor result3 = z + z1;
    Vetor result4 = w + w1;

    return Matriz(result1, result2, result3, result4);
}

Matriz Matriz::operator-(Matriz &v){
    Vetor x = Vetor(this->a, this->b, this->c,this->d);
    Vetor y = Vetor(this->e, this->f, this->g,this->h);
    Vetor z = Vetor(this->i, this->j, this->k,this->l);
    Vetor w = Vetor(this->m, this->n, this->o,this->p);

    Vetor x1 = Vetor(v.a, v.b, v.c, v.d);
    Vetor y1 = Vetor(v.e, v.f, v.g, v.h);
    Vetor z1 = Vetor(v.i, v.j, v.k, v.l);
    Vetor w1 = Vetor(v.m, v.n, v.o,v.p);

    Vetor result1 = x - x1;
    Vetor result2 = y - y1;
    Vetor result3 = z - z1;
    Vetor result4 = w - w1;

    return Matriz(result1, result2, result3, result4);
}

Matriz Matriz::operator*(Matriz &v){
    Vetor x = Vetor(this->a, this->b, this->c,this->d);
    Vetor y = Vetor(this->e, this->f, this->g,this->h);
    Vetor z = Vetor(this->i, this->j, this->k,this->l);
    Vetor w = Vetor(this->m, this->n, this->o,this->p);

    Vetor x1 = getColumn(v, 1);
    Vetor y1 = getColumn(v, 2);
    Vetor z1 = getColumn(v, 3);
    Vetor w1 = getColumn(v, 4);

    return Matriz(x>>x1, x>>y1, x>>z1, x>>w1, y>>x1, y>>y1, y>>z1, y>>w1, z>>x1, z>>y1, z>>z1, z>>w1, w>>x1, w>>y1, w>>z1, w>>w1);
}

Matriz Matriz::transposta(Matriz &v, int i){
    Vetor x = Vetor(v.a, v.e, v.i, v.m);
    Vetor y = Vetor(v.b, v.f, v.j, v.n);
    Vetor z = Vetor(v.c, v.g, v.k, v.o);
    Vetor w = Vetor(v.d, v.h, v.l,v.p);

    return Matriz(x,y,z,w);
}


Vetor Matriz::getLine(Matriz &v, int i){
    switch(i){
    case 1:{
        return Vetor(v.a, v.b, v.c, v.d);
        break;
    }case 2:{
        return Vetor(v.e, v.f, v.g, v.h);
        break;
    }case 3:{
        return Vetor(v.i, v.j, v.k, v.l);
        break;
    }case 4:{
        return Vetor(v.m, v.n, v.o,v.p);
        break;
    } default:{
        return Vetor(0.0,0.0,0.0,0.0);
    }

    }
    return Vetor(0.0,0.0,0.0,0.0);
}


Vetor Matriz::getColumn(Matriz &v, int i){
    switch(i){
    case 1:{
        return Vetor(v.a, v.e, v.i, v.m);
        break;
    }case 2:{
        return Vetor(v.b, v.f, v.j, v.n);
        break;
    }case 3:{
        return Vetor(v.c, v.g, v.k, v.o);
        break;
    }case 4:{
        return Vetor(v.d, v.h, v.l,v.p);
        break;
    } default:{
        return Vetor(0.0,0.0,0.0,0.0);
    }

    }
    return Vetor(0.0,0.0,0.0,0.0);
}




#endif // MATRIZ_H
