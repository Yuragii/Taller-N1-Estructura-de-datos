#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include "Alumno.h"
#include "Curso.h"
#include "LinkedList.h"
#include "Notas.h"
using namespace std;
//  g++ -o m Main.cpp
//    ./m
void desplegarMenu(){
    cout << "Menu principal: " << endl;
    cout << "1. Manejo de Alumnos" << endl;
    cout << "2. Manejo de Cursos" << endl;
    cout << "3. Manejo de Inscripciones" << endl;
    cout << "4. Manejo de Notas" << endl;
    cout << "5. Consultas y Reportes" << endl;
    cout << "6. Salir" << endl;
}
void menuAlumnos(){
    cout << "1) Crear alumno" << endl;
    cout << "2) Buscar alumno" << endl;
    cout << "3) Eliminar alumno" << endl;
    cout << "4) Atras" << endl;
}
void menuCursos(){
    cout << "1) Crear curso" << endl;
    cout << "2) Buscar curso" << endl;
    cout << "3) Eliminar curso" << endl;
    cout << "4) Atras" << endl;
}
void menuInscripciones(){
    cout << "1) Inscribir alumno a curso" << endl;
    cout << "2) Eliminar Alumno de un curso" << endl;
    cout << "3) Atras" << endl;
}
void menuNotas(){
    cout << "1) Ingresar nota" << endl;
    cout << "2) Atras" << endl;
}
void menuConsultas(){
    cout << "1) Obtener alumnos de una carrera" << endl;
    cout << "2) Obtener cursos inscrito por un alumno" << endl;
    cout << "3) Promedio de notas de un alumno en un curso" << endl;
    cout << "4) Promedio general de notas de un alumno" << endl;
    cout << "5) Atras" << endl;
}
void mostrarCursosInscritos(const Alumno& alumno) {
    const LinkedList<Curso>& cursos = alumno.getListaCursos();
    Node<Curso>* actual = cursos.getHead();

    if (actual == nullptr) {
        cout << "El alumno no esta inscrito en ningun curso." << endl;
        return;
    }

    cout << "Cursos inscritos por " << alumno.getNombre() << " " << alumno.getApellido() << ":" << endl;
    while (actual != nullptr) {
        const Curso& curso = actual->getDato();
        cout << "-----------------------------\n";
        cout << "ID: " << curso.getIdCurso()
             << "\nNombre: " << curso.getNombreCurso();
        actual = actual->getNext();
    }
}

void buscarAlumnoPorIdONombreConCursos(const LinkedList<Alumno>& listaAlumnos) {
    string tipoBusqueda;
    cout << "¿Desea buscar por ID (i) o por nombre (n)? ";
    cin >> tipoBusqueda;

    
    transform(tipoBusqueda.begin(), tipoBusqueda.end(), tipoBusqueda.begin(), ::tolower);

    if (tipoBusqueda == "i") {
        int idBuscado;
        cout << "Ingrese el ID del alumno: ";
        while (!(cin >> idBuscado)) {
            cout << "Entrada inválida. Ingrese un número entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Node<Alumno>* actual = listaAlumnos.getHead();
        bool encontrado = false;

        while (actual) {
            const Alumno& alumno = actual->getDato();
            if (alumno.getIdAlumno() == idBuscado) {
                cout << "\nAlumno encontrado:\n";
                cout << "ID: " << alumno.getIdAlumno()
                          << "\nNombre: " << alumno.getNombre()
                          << "\nApellido: " << alumno.getApellido()
                          << "\nCarrera: " << alumno.getCarrera()
                          << "\nFecha de ingreso: " << alumno.getFechaIngreso() << "\n";
                mostrarCursosInscritos(alumno);
                encontrado = true;
                break;
            }
            actual = actual->getNext();
        }

        if (!encontrado) {
            cout << "\nNo se encontró ningún alumno con ese ID.\n";
        }

    } else if (tipoBusqueda == "n") {
        string nombreBuscado;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(std::cin, nombreBuscado);

        Node<Alumno>* actual = listaAlumnos.getHead();
        bool encontrado = false;

        while (actual) {
            const Alumno& alumno = actual->getDato();
            if (alumno.getNombre() == nombreBuscado) {
                if (!encontrado) {
                    std::cout << "\nAlumnos encontrados con nombre \"" << nombreBuscado << "\":\n";
                }
                cout << "-----------------------------\n";
                cout << "ID: " << alumno.getIdAlumno()
                          << "\nApellido: " << alumno.getApellido()
                          << "\nCarrera: " << alumno.getCarrera()
                          << "\nFecha de ingreso: " << alumno.getFechaIngreso() << "\n";
                mostrarCursosInscritos(alumno);
                encontrado = true;
            }
            actual = actual->getNext();
        }

        if (!encontrado) {
            cout << "\nNo se encontraron alumnos con ese nombre.\n";
        }

    } else {
        cout << "Opción inválida. Use 'i' para ID o 'n' para nombre.\n";
    }
}

void eliminarAlumnoPorId(LinkedList<Alumno>& listaAlumnos, LinkedList<Nota>& listaNotas) {
    int idBuscado;
    cout << "Ingrese el ID del alumno a eliminar: ";
    while (!(cin >> idBuscado)) {
        cout << "Entrada inválida. Ingrese un número entero: " ;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Alumno>* actual = listaAlumnos.getHead();
    Node<Alumno>* anterior = nullptr;
    bool eliminado = false;

    while (actual) {
        Alumno alumno = actual->getDato();
        if (alumno.getIdAlumno() == idBuscado) {
            // 1. Eliminar notas asociadas
            Node<Nota>* notaActual = listaNotas.getHead();
            while (notaActual) {
                Nota nota = notaActual->getDato();
                if (nota.getAlumno().getIdAlumno() == idBuscado) {
                    listaNotas.remove(notaActual); 
                    notaActual = listaNotas.getHead(); 
                } else {
                    notaActual = notaActual->getNext();
                }
            }

            
            alumno.getListaCursos().clear(); 

            
            if (anterior) {
                anterior->setNext(actual->getNext());
            } else {
                listaAlumnos.setHead(actual->getNext());
            }

            delete actual;
            cout << "Alumno y sus registros fueron eliminados correctamente." << endl;
            eliminado = true;
            break;
        }

        anterior = actual;
        actual = actual->getNext();
    }

    if (!eliminado) {
        cout << "No se encontró ningún alumno con ese ID."<< endl;
    }
}

void buscarCursoPorCodigoONombre(const LinkedList<Curso>& listaCursos) {
    string tipoBusqueda;
    cout << "¿Desea buscar por código (c) o por nombre (n)? ";
    cin >> tipoBusqueda;

    transform(tipoBusqueda.begin(), tipoBusqueda.end(), tipoBusqueda.begin(), ::tolower);

    if (tipoBusqueda == "c") {
        int codigoBuscado;
        cout << "Ingrese el código del curso: ";
        while (!(cin >> codigoBuscado)) {
            cout << "Entrada inválida. Ingrese un número entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Node<Curso>* actual = listaCursos.getHead();
        bool encontrado = false;

        while (actual) {
            const Curso& curso = actual->getDato();
            if (curso.getIdCurso() == codigoBuscado) {
                cout << "\nCurso encontrado:\n";
                cout << "ID: " << curso.getIdCurso()
                          << "\nNombre: " << curso.getNombreCurso()
                          << "\nCarrera: " << curso.getCarrera()
                          << "\nProfesor: " << curso.getProfesor()
                          << "\nMáximo de alumnos: " << curso.getCantMaxAlumnos() << "\n";
                encontrado = true;
                break;
            }
            actual = actual->getNext();
        }

        if (!encontrado) {
            cout << "\nNo se encontró ningún curso con ese código.\n";
        }

    } else if (tipoBusqueda == "n") {
        string nombreBuscado;
        cout << "Ingrese el nombre del curso: ";
        cin.ignore();
        getline(cin, nombreBuscado);

        Node<Curso>* actual = listaCursos.getHead();
        bool encontrado = false;

        while (actual) {
            const Curso& curso = actual->getDato();
            if (curso.getNombreCurso() == nombreBuscado) {
                if (!encontrado) {
                    std::cout << "\nCursos encontrados con nombre \"" << nombreBuscado << "\":\n";
                }
                cout << "-----------------------------\n";
                cout << "ID: " << curso.getIdCurso()
                          << "\nCarrera: " << curso.getCarrera()
                          << "\nProfesor: " << curso.getProfesor()
                          << "\nMáximo de alumnos: " << curso.getCantMaxAlumnos() << "\n";
                encontrado = true;
            }
            actual = actual->getNext();
        }

        if (!encontrado) {
            cout << "\nNo se encontraron cursos con ese nombre.\n";
        }

    } else {
        cout << "Opción inválida. Use 'c' para código o 'n' para nombre.\n";
    }
}

void eliminarCursoPorId(LinkedList<Curso>& listaCursos, LinkedList<Alumno>& listaAlumnos) {
    int idBuscado;
    std::cout << "Ingrese el ID del curso a eliminar: ";
    while (!(cin >> idBuscado)) {
        cout << "Entrada inválida. Ingrese un número entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Curso>* actualCurso = listaCursos.getHead();
    Node<Curso>* anteriorCurso = nullptr;
    bool eliminado = false;

    while (actualCurso) {
        Curso curso = actualCurso->getDato();
        if (curso.getIdCurso() == idBuscado) {
            // 1. Eliminar el curso de la lista de cursos
            if (anteriorCurso) {
                anteriorCurso->setNext(actualCurso->getNext());
            } else {
                listaCursos.setHead(actualCurso->getNext());
            }
            delete actualCurso;
            eliminado = true;

            // 2. Eliminar inscripción de alumnos a ese curso
            Node<Alumno>* actualAlumno = listaAlumnos.getHead();
            while (actualAlumno) {
                LinkedList<Curso>& cursosAlumno = actualAlumno->getDato().getListaCursos();
                Node<Curso>* cursoAlumno = cursosAlumno.getHead();
                Node<Curso>* anteriorCursoAlumno = nullptr;

                while (cursoAlumno) {
                    if (cursoAlumno->getDato().getIdCurso() == idBuscado) {
                        if (anteriorCursoAlumno) {
                            anteriorCursoAlumno->setNext(cursoAlumno->getNext());
                        } else {
                            cursosAlumno.setHead(cursoAlumno->getNext());
                        }
                        delete cursoAlumno;
                        break; // solo una inscripción por curso
                    }
                    anteriorCursoAlumno = cursoAlumno;
                    cursoAlumno = cursoAlumno->getNext();
                }

                actualAlumno = actualAlumno->getNext();
            }

            std::cout << "Curso eliminado y se removio la inscripción de los alumnos.\n";
            break;
        }

        anteriorCurso = actualCurso;
        actualCurso = actualCurso->getNext();
    }

    if (!eliminado) {
        std::cout << "No se encontro ningun curso con ese ID.\n";
    }
}



int main() {
    LinkedList<Alumno> listaAlumnos;
    LinkedList<Curso> listaCursos;
    LinkedList<Nota> listaNotas;
    int opcion;
    int opcionAux;
    
    do {
        desplegarMenu();
        while (!(cin >> opcion) || opcion < 1 || opcion > 6) {
            cout << "Entrada invalida Por favor ingrese un numero entre 1 y 6: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        switch (opcion){
            case 1:
                opcionAux = 0;
                while (opcionAux != 4){
                    menuAlumnos();
                    cin >> opcionAux;
                    if (opcionAux == 1 ){
                        int idAlumno;
                        cout << "Ingrese ID del alumno: "<< endl;
                        while (!(cin >> idAlumno)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); // limpia el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta la entrada incorrecta
                        }
                        string nombre;
                        cout << "Ingrese nombre del alumno: "<< endl;
                        cin >> nombre;
                        string apellido;
                        cout << "Ingrese apellido del alumno: "<< endl;
                        cin >> apellido;
                        string carrera;
                        cout << "Ingrese carrera del alumno: "<< endl;
                        cin >> carrera;
                        string fechaIngreso;
                        cout << "Ingrese fecha de ingreso del alumno (DD/MM/AAAA): "<< endl;
                        cin >> fechaIngreso;
                        Alumno nuevoAlumno;
                        nuevoAlumno.setIdAlumno(idAlumno);
                        nuevoAlumno.setNombre(nombre);
                        nuevoAlumno.setApellido(apellido);
                        nuevoAlumno.setCarrera(carrera);
                        nuevoAlumno.setFechaIngreso(fechaIngreso);
                        listaAlumnos.append(nuevoAlumno);
                        cout << "Alumno creado" << endl;
                    
                    } else if (opcionAux == 2){
                        buscarAlumnoPorIdONombreConCursos(listaAlumnos);
                       
                    } else if (opcionAux == 3){
                        eliminarAlumnoPorId(listaAlumnos, listaNotas);
                        
                    } else if (opcionAux == 4){
                        cout << "Atras" << endl;
                        
                    } else {
                         menuAlumnos();
                        cin >> opcionAux;
                        cout << "Opcion no valida" << endl;
                    }
                   
                }
                break;
            case 2:
                opcionAux = 0;
                menuCursos();
                cin >> opcionAux;
                while (opcionAux != 4){
                    if (opcionAux == 1 ){
                        int idCurso;
                        cout << "Ingrese ID del curso: "<< endl;
                        while (!(cin >> idCurso)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); // limpia el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta la entrada incorrecta
                        }

                        string nombreCurso;
                        cout << "Ingrese nombre del curso: "<< endl;
                        cin >> nombreCurso;
                        int cantMaxAlumnos;
                        cout << "Ingrese cantidad maxima de alumnos del curso: "<< endl;
                        while (!(cin >> cantMaxAlumnos)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); // limpia el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta la entrada incorrecta
                        }

                        string carrera;
                        cout << "Ingrese carrera del curso: "<< endl;
                        cin >> carrera;
                        string profesor;
                        cout << "Ingrese nombre del profesor del curso: "<< endl;
                        cin >> profesor;
                        Curso nuevoCurso;
                        nuevoCurso.setIdCurso(idCurso);
                        nuevoCurso.setNombreCurso(nombreCurso);
                        nuevoCurso.setCantMaxAlumnos(cantMaxAlumnos);
                        nuevoCurso.setCarrera(carrera);
                        nuevoCurso.setProfesor(profesor);
                        listaCursos.append(nuevoCurso);
                        cout << "Curso creado" << endl;
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 2){
                        buscarCursoPorCodigoONombre(listaCursos);
                       
                    } else if (opcionAux == 3){
                        eliminarCursoPorId(listaCursos, listaAlumnos);
                        
                    } else if (opcionAux == 4){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuCursos();
                    cin >> opcionAux;
                } 
                break;
            case 3:
                opcionAux = 0;
                menuInscripciones();
                cin >> opcionAux;
                while (opcionAux != 3){
                    if (opcionAux == 1 ){
                        cout << "Inscribir alumno a curso" << endl;
                        
                    } else if (opcionAux == 2){
                        cout << "Eliminar Alumno de un curso" << endl;
                       
                    } else if (opcionAux == 3){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuInscripciones();
                    cin >> opcionAux;
                }
                break;
            case 4:
                opcionAux = 0;
                menuNotas();
                cin >> opcionAux;
                while (opcionAux != 2){
                    if (opcionAux == 1 ){
                        cout << "Ingresar nota" << endl;
                        
                    } else if (opcionAux == 2){
                        cout << "Atras" << endl;
                       
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuNotas();
                    cin >> opcionAux;
                }
                break;
            case 5:
                opcionAux = 0;
                menuConsultas();
                cin >> opcionAux;
                while (opcionAux != 5){
                    if (opcionAux == 1){
                        cout << "Obtener alumnos de una carrera" << endl;
                        
                    } else if (opcionAux == 2){
                        cout << "Obtener cursos inscrito por un alumno" << endl;
                       
                    } else if (opcionAux == 3){
                        cout << "Promedio de notas de un alumno en un curso" << endl;
                        
                    } else if (opcionAux == 4){
                        cout << "Promedio general de notas de un alumno" << endl;
                        
                    } else if (opcionAux == 5){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuConsultas();
                    cin >> opcionAux;
                }
                break;

            case 6:
                opcionAux = 0;
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                
                break;
        }
        
    } while (opcion != 6);
    return 0;
}

