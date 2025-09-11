#include "Notas.h"
#include <string>
#include <iostream>
using namespace std;
Nota::Nota() {
    this->alumno = Alumno();
    this->curso = Curso();
    this->valorNota = 0.0;
}
Alumno Nota::getAlumno() {
    return this->alumno;
}
Curso Nota::getCurso() {
    return this->curso;
}
float Nota::getValorNota() {
    return this->valorNota;
}
void Nota::setAlumno(Alumno alumno) {
    this->alumno = alumno;
}
void Nota::setCurso(Curso curso) {
    this->curso = curso;
}
void Nota::setValorNota(float valorNota) {
    this->valorNota = valorNota;
}
Nota::~Nota()= default; // Destructor