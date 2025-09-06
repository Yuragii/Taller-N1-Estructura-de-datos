#include "Curso.h"
#include <bits/stdc++.h>
using namespace std;

Curso::Curso() {
    this->idCurso = 0;
    this->nombreCurso = "";
    this->cantMaxAlumnos = 0;
    this->carrera = "";
    this->profesor = "";
    this->listaAlumnos = LinkedList<Alumno>();
}
int Curso::getIdCurso() {
    return this->idCurso;
}
string Curso::getNombreCurso() {
    return this->nombreCurso;
}
int Curso::getCantMaxAlumnos() {
    return this->cantMaxAlumnos;
}
string Curso::getCarrera() {
    return this->carrera;
}
string Curso::getProfesor() {
    return this->profesor;
}
LinkedList<Alumno> Curso::getListaAlumnos() {
    return this->listaAlumnos;
}
void Curso::setIdCurso(int idCurso) {
    this->idCurso = idCurso;
}
void Curso::setNombreCurso(string nombreCurso) {
    this->nombreCurso = nombreCurso;
}
void Curso::setCantMaxAlumnos(int cantMaxAlumnos) {
    this->cantMaxAlumnos = cantMaxAlumnos;
}
void Curso::setCarrera(string carrera) {
    this->carrera = carrera;
}
void Curso::setProfesor(string profesor) {
    this->profesor = profesor;
}
void Curso::añadirAlumnoACurso(Alumno alumno) {
    this->listaAlumnos.append(alumno);
}