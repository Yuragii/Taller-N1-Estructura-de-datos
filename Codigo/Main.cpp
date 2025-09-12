#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <cctype>
#include "Alumno.h"
#include "Curso.h"
#include "LinkedList.h"
#include "Notas.h"
using namespace std;
//  g++ -o m Main.cpp
//    ./m

// Funciones de menú
void desplegarMenu(){
    cout << "Menu principal: " << endl;
    cout << "1. Manejo de Alumnos" << endl;
    cout << "2. Manejo de Cursos" << endl;
    cout << "3. Manejo de Inscripciones" << endl;
    cout << "4. Manejo de Notas" << endl;
    cout << "5. Consultas y Reportes" << endl;
    cout << "6. Salir" << endl;
    cout << "--------------------------" << endl;
}
void menuAlumnos(){
    cout << "1) Crear alumno" << endl;
    cout << "2) Buscar alumno" << endl;
    cout << "3) Eliminar alumno" << endl;
    cout << "4) Atras" << endl;
    cout << "--------------------------" << endl;
}
void menuCursos(){
    cout << "1) Crear curso" << endl;
    cout << "2) Buscar curso" << endl;
    cout << "3) Eliminar curso" << endl;
    cout << "4) Atras" << endl;
    cout << "--------------------------" << endl;
}
void menuInscripciones(){
    cout << "1) Inscribir alumno a curso" << endl;
    cout << "2) Eliminar Alumno de un curso" << endl;
    cout << "3) Atras" << endl;
    cout << "--------------------------" << endl;
}
void menuNotas(){
    cout << "1) Ingresar nota" << endl;
    cout << "2) Atras" << endl;
    cout << "--------------------------" << endl;
}
void menuConsultas(){
    cout << "1) Obtener alumnos de una carrera" << endl;
    cout << "2) Obtener cursos inscrito por un alumno" << endl;
    cout << "3) Promedio de notas de un alumno en un curso" << endl;
    cout << "4) Promedio general de notas de un alumno" << endl;
    cout << "5) Atras" << endl;
    cout << "--------------------------" << endl;
}

// Requisitos Funcionales
void mostrarCursosInscritos(const Alumno& alumno) {
    const LinkedList<Curso*>& cursos = alumno.getListaCursos();
    Node<Curso*>* actual = cursos.getHead();

    if (actual == nullptr) {
        cout << "El alumno no esta inscrito en ningun curso." << endl;
        return;
    }

    cout << "Cursos inscritos por " << alumno.getNombre() << " " << alumno.getApellido() << ":" << endl;
    while (actual != nullptr) {
        const Curso* curso = actual->getDato();
        cout << "-----------------------------\n";
        cout << "ID: " << curso->getIdCurso()
             << "\nNombre: " << curso->getNombreCurso();
        actual = actual->getNext();
    }
}

void buscarAlumnoPorIdONombre(const LinkedList<Alumno>& listaAlumnos) {
    string tipoBusqueda;
    cout << "¿Desea buscar por ID (i) o por nombre (n)? ";
    cin >> tipoBusqueda;

    
    transform(tipoBusqueda.begin(), tipoBusqueda.end(), tipoBusqueda.begin(), ::tolower);

    if (tipoBusqueda == "i") {
        int idBuscado;
        cout << "Ingrese el ID del alumno: ";
        while (!(cin >> idBuscado)) {
            cout << "Entrada invalida. Ingrese un numero entero: ";
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
            cout << "\nNo se encontro ningun alumno con ese ID.\n";
        }

    } else if (tipoBusqueda == "n") {
        string nombreBuscado;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(std::cin, nombreBuscado);
        transform(nombreBuscado.begin(), nombreBuscado.end(), nombreBuscado.begin(),[](unsigned char c){ return tolower(c);});
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
        cout << "Opción invalida. Use 'i' para ID o 'n' para nombre.\n";
    }
}

void eliminarAlumnoPorId(LinkedList<Alumno>& listaAlumnos, LinkedList<Nota>& listaNotas, LinkedList<Curso>& listaCursos) {
    int idBuscado;
    cout << "Ingrese el ID del alumno a eliminar: ";
    while (!(cin >> idBuscado)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Alumno>* actual = listaAlumnos.getHead();
    Node<Alumno>* anterior = nullptr;
    bool eliminado = false;

    while (actual) {
        Alumno& alumno = actual->getDato();

        if (alumno.getIdAlumno() == idBuscado) {
            Node<Nota>* notaActual = listaNotas.getHead();
            Node<Nota>* notaAnterior = nullptr;

            while (notaActual) {
                Nota& nota = notaActual->getDato();
                if (nota.getAlumno() && nota.getAlumno()->getIdAlumno() == idBuscado) {
                    Node<Nota>* siguiente = notaActual->getNext();
                    if (notaAnterior) {
                        notaAnterior->setNext(siguiente);
                    } else {
                        listaNotas.setHead(siguiente);
                    }
                    delete notaActual;
                    notaActual = siguiente;
                } else {
                    notaAnterior = notaActual;
                    notaActual = notaActual->getNext();
                }
            }

            
            LinkedList<Curso*>& cursosAlumno = alumno.getListaCursos();
            Node<Curso*>* cursoActual = cursosAlumno.getHead();

            while (cursoActual) {
                Curso* curso = cursoActual->getDato();
                if (curso) {
                    LinkedList<Alumno*>& alumnosCurso = curso->getListaAlumnos();
                    Node<Alumno*>* alumnoCursoActual = alumnosCurso.getHead();
                    Node<Alumno*>* alumnoCursoAnterior = nullptr;

                    while (alumnoCursoActual) {
                        if (alumnoCursoActual->getDato()->getIdAlumno() == idBuscado) {
                            if (alumnoCursoAnterior) {
                                alumnoCursoAnterior->setNext(alumnoCursoActual->getNext());
                            } else {
                                alumnosCurso.setHead(alumnoCursoActual->getNext());
                            }
                            delete alumnoCursoActual;
                            break;
                        }
                        alumnoCursoAnterior = alumnoCursoActual;
                        alumnoCursoActual = alumnoCursoActual->getNext();
                    }
                }
                cursoActual = cursoActual->getNext();
            }

            
            alumno.getListaCursos().clear();

            
            if (anterior) {
                anterior->setNext(actual->getNext());
            } else {
                listaAlumnos.setHead(actual->getNext());
            }

            delete actual;
            cout << "Alumno, sus notas y sus inscripciones fueron eliminados correctamente." << endl;
            eliminado = true;
            break;
        }

        anterior = actual;
        actual = actual->getNext();
    }

    if (!eliminado) {
        cout << "No se encontro ningun alumno con ese ID." << endl;
    }
}

void buscarCursoPorCodigoONombre(const LinkedList<Curso>& listaCursos) {
    string tipoBusqueda;
    cout << "¿Desea buscar por codigo (c) o por nombre (n)? ";
    cin >> tipoBusqueda;

    transform(tipoBusqueda.begin(), tipoBusqueda.end(), tipoBusqueda.begin(), ::tolower);

    if (tipoBusqueda == "c") {
        int codigoBuscado;
        cout << "Ingrese el codigo del curso: ";
        while (!(cin >> codigoBuscado)) {
            cout << "Entrada invalida. Ingrese un numero entero: ";
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
            cout << "\nNo se encontro ningun curso con ese codigo.\n";
        }

    } else if (tipoBusqueda == "n") {
        string nombreBuscado;
        cout << "Ingrese el nombre del curso: ";
        cin.ignore();
        getline(cin, nombreBuscado);
        transform(nombreBuscado.begin(), nombreBuscado.end(), nombreBuscado.begin(),[](unsigned char c){ return tolower(c);});
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
        cout << "Opcion invalida. Use 'c' para codigo o 'n' para nombre.\n";
    }
}

void eliminarCursoPorId(LinkedList<Curso>& listaCursos, LinkedList<Alumno>& listaAlumnos) {
    int idBuscado;
    std::cout << "Ingrese el ID del curso a eliminar: ";
    while (!(cin >> idBuscado)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Curso>* actualCurso = listaCursos.getHead();
    Node<Curso>* anteriorCurso = nullptr;
    bool eliminado = false;

    while (actualCurso) {
        Curso* cursoPtr = &actualCurso->getDato();
        if (cursoPtr->getIdCurso() == idBuscado) {
            if (anteriorCurso) {
                anteriorCurso->setNext(actualCurso->getNext());
            } else {
                listaCursos.setHead(actualCurso->getNext());
            }

            Node<Alumno>* actualAlumno = listaAlumnos.getHead();
            while (actualAlumno) {
                LinkedList<Curso*>& cursosAlumno = actualAlumno->getDato().getListaCursos();
                Node<Curso*>* cursoAlumno = cursosAlumno.getHead();
                Node<Curso*>* anteriorCursoAlumno = nullptr;

                while (cursoAlumno) {
                    if (cursoAlumno->getDato()->getIdCurso() == idBuscado) {
                        if (anteriorCursoAlumno) {
                            anteriorCursoAlumno->setNext(cursoAlumno->getNext());
                        } else {
                            cursosAlumno.setHead(cursoAlumno->getNext());
                        }

                        delete cursoAlumno;
                        break;
                    }
                    anteriorCursoAlumno = cursoAlumno;
                    cursoAlumno = cursoAlumno->getNext();
                }

                actualAlumno = actualAlumno->getNext();
            }

            delete actualCurso; 
            cout << "Curso eliminado y se removio la inscripcion de los alumnos.\n";
            eliminado = true;
            break;
        }

        anteriorCurso = actualCurso;
        actualCurso = actualCurso->getNext();
    }

    if (!eliminado) {
        cout << "No se encontro ningun curso con ese ID.\n";
    }
}

void inscribirAlumnoEnCurso(LinkedList<Alumno>& listaAlumnos, LinkedList<Curso>& listaCursos) {
    int idAlumno, idCurso;

    cout << "Ingrese el ID del alumno: ";
    while (!(cin >> idAlumno)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el ID del curso: ";
    while (!(cin >> idCurso)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Alumno>* nodoAlumno = listaAlumnos.getHead();
    while (nodoAlumno && nodoAlumno->getDato().getIdAlumno() != idAlumno) {
        nodoAlumno = nodoAlumno->getNext();
    }

    if (!nodoAlumno) {
        cout << "No se encontro ningun alumno con ese ID.\n";
        return;
    }

    Node<Curso>* nodoCurso = listaCursos.getHead();
    Curso* cursoEncontrado = nullptr;
    while (nodoCurso) {
        if (nodoCurso->getDato().getIdCurso() == idCurso) {
            cursoEncontrado = &nodoCurso->getDato();
            break;
        }
        nodoCurso = nodoCurso->getNext();
    }

    if (!cursoEncontrado) {
        cout << "No se encontró ningun curso con ese ID.\n";
        return;
    }

    const string& carreraAlumno = nodoAlumno->getDato().getCarrera();
    const string& carreraCurso = cursoEncontrado->getCarrera();

    if (carreraAlumno != carreraCurso) {
        cout << "La carrera del alumno (" << carreraAlumno << ") no coincide con la del curso (" << carreraCurso << ").\n";
        return;
    }

    LinkedList<Curso*>& cursosAlumno = nodoAlumno->getDato().getListaCursos();
    Node<Curso*>* actualCurso = cursosAlumno.getHead();
    while (actualCurso) {
        if (actualCurso->getDato()->getIdCurso() == idCurso) {
            cout << "El alumno ya esta inscrito en ese curso.\n";
            return;
        }
        actualCurso = actualCurso->getNext();
    }

    LinkedList<Alumno*>& alumnosCurso = cursoEncontrado->getListaAlumnos();
    int inscritos = 0;
    Node<Alumno*>* actualAlumno = alumnosCurso.getHead();
    while (actualAlumno) {
        inscritos++;
        actualAlumno = actualAlumno->getNext();
    }

    if (inscritos >= cursoEncontrado->getCantMaxAlumnos()) {
        cout << "No se puede inscribir al alumno. El curso \"" << cursoEncontrado->getNombreCurso()
             << "\" ya alcanzo el máximo de " << cursoEncontrado->getCantMaxAlumnos() << " alumnos.\n";
        return;
    }

    cursosAlumno.append(cursoEncontrado);
    cursoEncontrado->getListaAlumnos().append(&nodoAlumno->getDato());

    cout << "Alumno inscrito exitosamente en el curso \"" << cursoEncontrado->getNombreCurso() << "\".\n";
}

void eliminarAlumnoDeCurso(LinkedList<Alumno>& listaAlumnos, LinkedList<Curso>& listaCursos, int idAlumno, int idCurso) {
    Node<Alumno>* nodoAlumno = listaAlumnos.getHead();
    while (nodoAlumno && nodoAlumno->getDato().getIdAlumno() != idAlumno) {
        nodoAlumno = nodoAlumno->getNext();
    }

    if (!nodoAlumno) {
        cout << "No se encontro ningun alumno con ese ID.\n";
        return;
    }

    Node<Curso>* nodoCurso = listaCursos.getHead();
    while (nodoCurso && nodoCurso->getDato().getIdCurso() != idCurso) {
        nodoCurso = nodoCurso->getNext();
    }

    if (!nodoCurso) {
        std::cout << "No se encontro ningun curso con ese ID.\n";
        return;
    }

    LinkedList<Curso*>& cursosAlumno = nodoAlumno->getDato().getListaCursos();
    Node<Curso*>* actualCurso = cursosAlumno.getHead();
    Node<Curso*>* anteriorCurso = nullptr;
    bool cursoEliminado = false;

    while (actualCurso) {
        if (actualCurso->getDato()->getIdCurso() == idCurso) {
            if (anteriorCurso) {
                anteriorCurso->setNext(actualCurso->getNext());
            } else {
                cursosAlumno.setHead(actualCurso->getNext());
            }
            delete actualCurso;
            cursoEliminado = true;
            break;
        }
        anteriorCurso = actualCurso;
        actualCurso = actualCurso->getNext();
    }

    LinkedList<Alumno*>& alumnosCurso = nodoCurso->getDato().getListaAlumnos();
    Node<Alumno*>* actualAlumno = alumnosCurso.getHead();
    Node<Alumno*>* anteriorAlumno = nullptr;
    bool alumnoEliminado = false;

    while (actualAlumno) {
        if (actualAlumno->getDato()->getIdAlumno() == idAlumno) {
            if (anteriorAlumno) {
                anteriorAlumno->setNext(actualAlumno->getNext());
            } else {
                alumnosCurso.setHead(actualAlumno->getNext());
            }
            delete actualAlumno;
            alumnoEliminado = true;
            break;
        }
        anteriorAlumno = actualAlumno;
        actualAlumno = actualAlumno->getNext();
    }

    if (cursoEliminado && alumnoEliminado) {
        cout << "El alumno fue desinscrito del curso exitosamente.\n";
    } else {
        cout << "No se encontro relación entre el alumno y el curso.\n";
    }
}

void registrarNotasParaAlumno(LinkedList<Alumno>& listaAlumnos, const LinkedList<Curso>& listaCursos, LinkedList<Nota>& listaNotas) {
    int idAlumno, idCurso;
    cout << "Ingrese el ID del alumno: ";
    while (!(cin >> idAlumno)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el ID del curso: ";
    while (!(cin >> idCurso)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Alumno>* nodoAlumno = listaAlumnos.getHead();
    while (nodoAlumno && nodoAlumno->getDato().getIdAlumno() != idAlumno) {
        nodoAlumno = nodoAlumno->getNext();
    }

    if (!nodoAlumno) {
        cout << "No se encontro ningun alumno con ese ID.\n";
        return;
    }

    Node<Curso>* nodoCurso = listaCursos.getHead();
    Curso* cursoEncontrado = nullptr;
    while (nodoCurso) {
        if (nodoCurso->getDato().getIdCurso() == idCurso) {
            cursoEncontrado = &nodoCurso->getDato();
            break;
        }
        nodoCurso = nodoCurso->getNext();
    }

    if (!cursoEncontrado) {
        cout << "No se encontro ningun curso con ese ID.\n";
        return;
    }

    LinkedList<Curso*>& cursosAlumno = nodoAlumno->getDato().getListaCursos();
    Node<Curso*>* actualCurso = cursosAlumno.getHead();
    bool inscrito = false;
    while (actualCurso) {
        if (actualCurso->getDato()->getIdCurso() == idCurso) {
            inscrito = true;
            break;
        }
        actualCurso = actualCurso->getNext();
    }

    if (!inscrito) {
        cout << "El alumno no esta inscrito en ese curso.\n";
        return;
    }

    int cantidadNotas;
    cout << "¿Cuántas notas desea registrar? ";
    while (!(cin >> cantidadNotas) || cantidadNotas <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 1; i <= cantidadNotas; ++i) {
        float nota;
        cout << "Ingrese nota #" << i << " (1.0 a 7.0): ";
        while (!(cin >> nota) || nota < 1.0 || nota > 7.0) {
            cout << "Nota invalida. Ingrese un valor entre 1.0 y 7.0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Nota nuevaNota;
        nuevaNota.setAlumno(&nodoAlumno->getDato());
        nuevaNota.setCurso(cursoEncontrado);
        nuevaNota.setValorNota(nota);

        listaNotas.append(nuevaNota);
    }

    cout << "Notas registradas exitosamente para el alumno \"" 
              << nodoAlumno->getDato().getNombre() << " " 
              << nodoAlumno->getDato().getApellido() << "\" en el curso \"" 
              << cursoEncontrado->getNombreCurso() << "\".\n";
}

void mostrarAlumnosPorCarrera(const LinkedList<Alumno>& listaAlumnos) {
    string carreraBuscada;
    cout << "Ingrese el nombre de la carrera: ";
    cin.ignore();
    getline(cin, carreraBuscada);

    Node<Alumno>* actual = listaAlumnos.getHead();
    bool encontrado = false;

    while (actual) {
        const Alumno& alumno = actual->getDato();
        if (alumno.getCarrera() == carreraBuscada) {
            if (!encontrado) {
                cout << "\nAlumnos de la carrera \"" << carreraBuscada << "\":\n";
            }
            cout << "-----------------------------\n";
            cout << "ID: " << alumno.getIdAlumno()
                      << "\nNombre: " << alumno.getNombre() << " " << alumno.getApellido()
                      << "\nFecha de ingreso: " << alumno.getFechaIngreso() << "\n";
            encontrado = true;
        }
        actual = actual->getNext();
    }

    if (!encontrado) {
        cout << "\nNo se encontraron alumnos en la carrera \"" << carreraBuscada << "\".\n";
    }
}

void mostrarCursosDeAlumno(const LinkedList<Alumno>& listaAlumnos) {
    int idAlumno;
    cout << "Ingrese el ID del alumno: ";
    while (!(cin >> idAlumno)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Alumno>* nodoAlumno = listaAlumnos.getHead();
    while (nodoAlumno && nodoAlumno->getDato().getIdAlumno() != idAlumno) {
        nodoAlumno = nodoAlumno->getNext();
    }

    if (!nodoAlumno) {
        cout << "No se encontro ningun alumno con ese ID.\n";
        return;
    }

    const Alumno& alumno = nodoAlumno->getDato();
    const LinkedList<Curso*>& cursos = alumno.getListaCursos();
    Node<Curso*>* actualCurso = cursos.getHead();

    if (!actualCurso) {
        cout << "El alumno no está inscrito en ningun curso.\n";
        return;
    }

    cout << "\nCursos inscritos por " << alumno.getNombre() << " " << alumno.getApellido() << ":\n";
    while (actualCurso) {
        Curso* curso = actualCurso->getDato();

        if (curso) {
            cout << "-----------------------------\n";
            cout << "ID: " << curso->getIdCurso()
                 << "\nNombre: " << curso->getNombreCurso()
                 << "\nCarrera: " << curso->getCarrera()
                 << "\nProfesor: " << curso->getProfesor()
                 << "\nMáximo de alumnos: " << curso->getCantMaxAlumnos() << "\n";
        }

        actualCurso = actualCurso->getNext();
    }
}

void calcularPromedioNotas(const LinkedList<Nota>& listaNotas) {
    int idAlumno, idCurso;

    cout << "Ingrese el ID del alumno: ";
    while (!(cin >> idAlumno)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el ID del curso: ";
    while (!(cin >> idCurso)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node<Nota>* actual = listaNotas.getHead();
    float sumaNotas = 0.0;
    int cantidadNotas = 0;

    while (actual) {
        const Nota& nota = actual->getDato();
        if (nota.getAlumno()->getIdAlumno() == idAlumno &&
            nota.getCurso()->getIdCurso() == idCurso) {
            sumaNotas += nota.getValorNota();
            cantidadNotas++;
        }
        actual = actual->getNext();
    }

    if (cantidadNotas == 0) {
        cout << "No se encontraron notas para ese alumno en ese curso.\n";
        return;
    }

    float promedio = sumaNotas / cantidadNotas;
    cout << "Promedio de notas del alumno ID " << idAlumno
              << " en el curso ID " << idCurso << ": " << promedio << "\n";
}

void calcularPromedioGeneralAlumno(const LinkedList<Nota>& listaNotas) {
    int idAlumno;
    cout << "Ingrese el ID del alumno: ";
   while (!(cin >> idAlumno)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
    int idCursos[100];
    float sumaPorCurso[100];
    int cantidadPorCurso[100];
    int totalCursos = 0;

    Node<Nota>* actual = listaNotas.getHead();
    while (actual) {
        const Nota& nota = actual->getDato();
        if (nota.getAlumno()->getIdAlumno() == idAlumno) {
            int idCurso = nota.getCurso()->getIdCurso();
            bool encontrado = false;

            for (int i = 0; i < totalCursos; ++i) {
                if (idCursos[i] == idCurso) {
                    sumaPorCurso[i] += nota.getValorNota();
                    cantidadPorCurso[i]++;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado && totalCursos < 100) {
                idCursos[totalCursos] = idCurso;
                sumaPorCurso[totalCursos] = nota.getValorNota();
                cantidadPorCurso[totalCursos] = 1;
                totalCursos++;
            }
        }
        actual = actual->getNext();
    }

    if (totalCursos == 0) {
        cout << "El alumno no tiene notas registradas.\n";
        return;
    }

    float sumaPromedios = 0.0;
    for (int i = 0; i < totalCursos; ++i) {
        float promedioCurso = sumaPorCurso[i] / cantidadPorCurso[i];
        sumaPromedios += promedioCurso;
    }

    float promedioGeneral = sumaPromedios / totalCursos;
    cout << "Promedio general del alumno ID " << idAlumno << ": " << promedioGeneral << "\n";
}

bool existeAlumnoConId(const LinkedList<Alumno>& listaAlumnos, int idBuscado) {
    Node<Alumno>* actual = listaAlumnos.getHead();
    while (actual) {
        if (actual->getDato().getIdAlumno() == idBuscado) {
            return true;
        }
        actual = actual->getNext();
    }
    return false;
}

bool existeCursoConId(const LinkedList<Curso>& listaCursos, int idBuscado) {
    Node<Curso>* actual = listaCursos.getHead();
    while (actual) {
        if (actual->getDato().getIdCurso() == idBuscado) {
            return true;
        }
        actual = actual->getNext();
    }
    return false;
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
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        string nombre;
                        cout << "Ingrese nombre del alumno: "<< endl;
                        cin >> nombre;
                        transform(nombre.begin(), nombre.end(), nombre.begin(),[](unsigned char c){ return tolower(c);}); // Convertir a minúsculas
                        string apellido;
                        cout << "Ingrese apellido del alumno: "<< endl;
                        cin >> apellido;
                        string carrera;
                        cout << "Ingrese carrera del alumno: "<< endl;
                        cin >> carrera;
                        transform(carrera.begin(), carrera.end(), carrera.begin(),[](unsigned char c){ return tolower(c);});
                        string fechaIngreso;
                        cout << "Ingrese fecha de ingreso del alumno (DD/MM/AAAA): "<< endl;
                        cin >> fechaIngreso;
                        
                        if (existeAlumnoConId(listaAlumnos, idAlumno)) {
                            cout << "Ya existe un alumno con ese ID. No se puede crear el alumno." << endl;
                            cout << "-------------------------" << endl;
                            break; 
                        } else {
                            Alumno nuevoAlumno;
                            nuevoAlumno.setIdAlumno(idAlumno);
                            nuevoAlumno.setNombre(nombre);
                            nuevoAlumno.setApellido(apellido);
                            nuevoAlumno.setCarrera(carrera);
                            nuevoAlumno.setFechaIngreso(fechaIngreso);
                            listaAlumnos.append(nuevoAlumno);
                            cout << "Alumno creado" << endl;
                            cout << "-------------------------" << endl;
                        }
                    } else if (opcionAux == 2){
                        buscarAlumnoPorIdONombre(listaAlumnos);
                        cout << "-------------------------" << endl;
                       
                    } else if (opcionAux == 3){
                        eliminarAlumnoPorId(listaAlumnos, listaNotas,listaCursos);
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 4){
                        cout << "Atras" << endl;
                        cout << "-------------------------" << endl;
                        
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
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        }

                        string nombreCurso;
                        cout << "Ingrese nombre del curso: "<< endl;
                        cin >> nombreCurso;
                        transform(nombreCurso.begin(), nombreCurso.end(), nombreCurso.begin(),[](unsigned char c){ return tolower(c);}); // Convertir a minúsculas
                        int cantMaxAlumnos;
                        cout << "Ingrese cantidad maxima de alumnos del curso: "<< endl;
                        while (!(cin >> cantMaxAlumnos)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        }

                        string carrera;
                        cout << "Ingrese carrera del curso: "<< endl;
                        cin >> carrera;
                        transform(carrera.begin(), carrera.end(), carrera.begin(),[](unsigned char c){ return tolower(c);});
                        string profesor;
                        cout << "Ingrese nombre del profesor del curso: "<< endl;
                        cin >> profesor;
                        if (existeCursoConId(listaCursos, idCurso)) {
                            cout << "Ya existe un curso con ese ID. No se puede crear el curso." << endl;
                            cout << "-------------------------" << endl;
                            break; 
                        } else {
                            Curso nuevoCurso;
                            nuevoCurso.setIdCurso(idCurso);
                            nuevoCurso.setNombreCurso(nombreCurso);
                            nuevoCurso.setCantMaxAlumnos(cantMaxAlumnos);
                            nuevoCurso.setCarrera(carrera);
                            nuevoCurso.setProfesor(profesor);
                            listaCursos.append(nuevoCurso);
                            cout << "Curso creado" << endl;
                            cout << "-------------------------" << endl;
                        } 
                    } else if (opcionAux == 2){
                        buscarCursoPorCodigoONombre(listaCursos);
                        cout << "-------------------------" << endl;
                       
                    } else if (opcionAux == 3){
                        eliminarCursoPorId(listaCursos, listaAlumnos);
                        cout << "-------------------------" << endl;

                    } else if (opcionAux == 4){
                        cout << "Atras" << endl;
                        cout << "-------------------------" << endl;
                        
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

                        inscribirAlumnoEnCurso(listaAlumnos, listaCursos);
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 2){
                        int idAlumno, idCurso;
                        cout << "Ingrese el ID del Curso: ";
                        while (!(cin >> idCurso)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        }
                        cout << "Ingrese el ID del Alumno: ";
                        while (!(cin >> idAlumno)) {
                            cout << "Entrada invalida. Por favor ingrese un numero entero: ";
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        }
                        eliminarAlumnoDeCurso(listaAlumnos, listaCursos, idAlumno, idCurso);
                        cout << "-------------------------" << endl;
                       
                    } else if (opcionAux == 3){
                        cout << "Atras" << endl;
                        cout << "-------------------------" << endl;
                        
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

                        registrarNotasParaAlumno(listaAlumnos, listaCursos, listaNotas);
                        cout << "-------------------------" << endl;
            
                    } else if (opcionAux == 2){
                        cout << "Atras" << endl;
                        cout << "-------------------------" << endl;

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

                        mostrarAlumnosPorCarrera(listaAlumnos);
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 2){

                        mostrarCursosDeAlumno(listaAlumnos);
                        cout << "-------------------------" << endl;
                       
                    } else if (opcionAux == 3){

                        calcularPromedioNotas(listaNotas);
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 4){

                        calcularPromedioGeneralAlumno(listaNotas);
                        cout << "-------------------------" << endl;
                        
                    } else if (opcionAux == 5){
                        cout << "Atras" << endl;
                        cout << "-------------------------" << endl;
                        
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

