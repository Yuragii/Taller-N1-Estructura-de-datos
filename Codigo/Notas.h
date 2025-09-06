#pragma once;
#include "alumno.h"
#include "curso.h"
#include <bits/stdc++.h>
using namespace std;

class Nota{
    private:
        Alumno alumno;
        Curso curso;
        float valorNota;
    public:
        Nota();
        Alumno getAlumno();
        Curso getCurso();
        float getValorNota();
        void setAlumno(Alumno alumno);
        void setCurso(Curso curso);
        void setValorNota(float valorNota);
        ~Nota();
};