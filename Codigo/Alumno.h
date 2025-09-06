#pragma once;
#include <bits/stdc++.h>
#include "LinkedList.h"
#include "curso.h"
using namespace std;
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
        int getIdAlumno();
        string getNombre();
        string getApellido();
        string getCarrera();
        string getFechaIngreso();
        LinkedList<Curso> getListaCursos();
        void setIdAlumno(int idAlumno);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setCarrera(string carrera);
        void setFechaIngreso(string fechaIngreso);
        ~Alumno();

};
