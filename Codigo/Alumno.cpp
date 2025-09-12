#include "Alumno.h"
#include "Curso.h"
#include <string>
#include <iostream>
using namespace std;

Alumno::Alumno() {
    this->idAlumno = 0;
    this->nombre = "";
    this->apellido = "";
    this->carrera = "";
    this->fechaIngreso = "";
    this->listaCursos = LinkedList<Curso*>();
}
int Alumno::getIdAlumno() const {
    return this->idAlumno;
}
string Alumno::getNombre() const {
    return this->nombre;
}
string Alumno::getApellido() const{
    return this->apellido;
}
string Alumno::getCarrera() const{
    return this->carrera;
}
string Alumno::getFechaIngreso() const{
    return this->fechaIngreso;
}
LinkedList<Curso*>& Alumno::getListaCursos() {
    return this->listaCursos;
}

const LinkedList<Curso*>& Alumno::getListaCursos() const {
    return this->listaCursos;
}
void Alumno::setIdAlumno(int idAlumno) {
    this->idAlumno = idAlumno;
}
void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}
void Alumno::setApellido(string apellido) {
    this->apellido = apellido;
}
void Alumno::setCarrera(string carrera) {
    this->carrera = carrera;
}
void Alumno::setFechaIngreso(string fechaIngreso) {
    this->fechaIngreso = fechaIngreso;
}

void Alumno::añadirCursoAlumno(Curso* curso) {
    this->listaCursos.append(curso);
}

Alumno::~Alumno() = default; // Destructor
