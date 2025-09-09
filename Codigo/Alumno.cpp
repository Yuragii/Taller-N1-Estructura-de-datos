#include "Alumno.h"
#include <bits/stdc++.h>
using namespace std;

Alumno::Alumno() {
    this->idAlumno = 0;
    this->nombre = "";
    this->apellido = "";
    this->carrera = "";
    this->fechaIngreso = "";
    this->listaCursos = LinkedList<Curso>();
}
int Alumno::getIdAlumno() {
    return this->idAlumno;
}
string Alumno::getNombre() {
    return this->nombre;
}
string Alumno::getApellido() {
    return this->apellido;
}
string Alumno::getCarrera() {
    return this->carrera;
}
string Alumno::getFechaIngreso() {
    return this->fechaIngreso;
}
LinkedList<Curso> Alumno::getListaCursos() {
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
Alumno::~Alumno() {
    // Destructor
}

