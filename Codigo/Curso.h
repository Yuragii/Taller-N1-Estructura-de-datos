#pragma once;
#include <bits/stdc++.h>
#include "LinkedList.h"
#include "alumno.h"
using namespace std;

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
        int getIdCurso();
        string getNombreCurso();
        int getCantMaxAlumnos();
        string getCarrera();
        string getProfesor();
        LinkedList<Alumno> getListaAlumnos();
        void setIdCurso(int idCurso);
        void setNombreCurso(string nombreCurso);
        void setCantMaxAlumnos(int cantMaxAlumnos);
        void setCarrera(string carrera);
        void setProfesor(string profesor);
        void añadirAlumnoACurso(Alumno alumno);
        ~Curso();
        
};