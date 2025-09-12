#include "Curso.h"
#include "Alumno.h"
#include <string>
#include <iostream>
using namespace std;

Curso::Curso() {
    this->idCurso = 0;
    this->nombreCurso = "";
    this->cantMaxAlumnos = 0;
    this->carrera = "";
    this->profesor = "";
    this->listaAlumnos = LinkedList<Alumno*>();
}
int Curso::getIdCurso () const {
    return this->idCurso;
}
string Curso::getNombreCurso() const {
    return this->nombreCurso;
}
int Curso::getCantMaxAlumnos() const {
    return this->cantMaxAlumnos;
}
string Curso::getCarrera() const {
    return this->carrera;
}
string Curso::getProfesor() const {
    return this->profesor;
}
LinkedList<Alumno*>& Curso::getListaAlumnos()  {
    return this->listaAlumnos;
}
const LinkedList<Alumno*>& Curso::getListaAlumnos() const {
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
void Curso::añadirAlumnoACurso(Alumno* alumno) {
    if (cantMaxAlumnos > 0 ) {
        int count = 0;
        Node<Alumno*>* current = listaAlumnos.getHead();
        while (current != nullptr) {
            count++;
            current = current->getNext();
        }
        if (count >= cantMaxAlumnos) {
            cout << "No se puede añadir más alumnos, se ha alcanzado el máximo de " << cantMaxAlumnos << " alumnos." << endl;
            return;
        } 
        this->listaAlumnos.append(alumno);
        cout << "Añadiendo alumno al curso." << endl;
    }
}

Curso::~Curso() = default; // Destructor
    