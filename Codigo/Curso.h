#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Alumno.h"
using namespace std;

class Alumno;

class Curso{
    private:
        int idCurso;
        string nombreCurso;
        int cantMaxAlumnos;
        string carrera;
        string profesor;
        LinkedList<Alumno> listaAlumnos;
    public:
        Curso();
        
        int getIdCurso() const;
        string getNombreCurso() const;
        int getCantMaxAlumnos() const;
        string getCarrera() const;
        string getProfesor() const;
        LinkedList<Alumno> getListaAlumnos() const;
        void setIdCurso(int idCurso);
        void setNombreCurso(string nombreCurso);
        void setCantMaxAlumnos(int cantMaxAlumnos);
        void setCarrera(string carrera);
        void setProfesor(string profesor);
        void añadirAlumnoACurso(Alumno alumno);
        ~Curso();
        
};