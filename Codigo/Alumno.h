#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Curso.h"
using namespace std;

class Curso;

class Alumno{
    private:
        int idAlumno;
        string nombre;
        string apellido;
        string carrera;
        string fechaIngreso;
        LinkedList<Curso> listaCursos;
    public:
        Alumno();

        int getIdAlumno() const;
        string getNombre() const;
        string getApellido() const;
        string getCarrera() const;
        string getFechaIngreso() const;
        LinkedList<Curso>& getListaCursos();
        const LinkedList<Curso>& getListaCursos() const;
        void setIdAlumno(int idAlumno);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setCarrera(string carrera);
        void setFechaIngreso(string fechaIngreso);
        void añadirCursoAlumno(Curso curso);
        ~Alumno();

};
