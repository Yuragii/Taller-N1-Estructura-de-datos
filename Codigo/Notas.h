#pragma once
#include "Alumno.h"
#include "Curso.h"
#include <string>
#include <iostream>
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