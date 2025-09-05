#include <iostream>
using namespace std;

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
    cout << "a) Crear alumno" << endl;
    cout << "b) Buscar alumno" << endl;
    cout << "c) Eliminar alumno" << endl;
    cout << "d) Atras" << endl;
}
void menuCursos(){
    cout << "a) Crear curso" << endl;
    cout << "b) Buscar curso" << endl;
    cout << "c) Eliminar curso" << endl;
    cout << "d) Atras" << endl;
}
void menuInscripciones(){
    cout << "a) Inscribir alumno a curso" << endl;
    cout << "b) Eliminar Alumno de un curso" << endl;
    cout << "c) Atras" << endl;
}
void menuNotas(){
    cout << "a) Ingresar nota" << endl;
    cout << "b) Atras" << endl;
}
void menuConsultas(){
    cout << "a) Obtener alumnos de una carrera" << endl;
    cout << "b) Obtener cursos inscrito por un alumno" << endl;
    cout << "c) Promedio de notas de un alumno en un curso" << endl;
    cout << "d) Promedio general de notas de un alumno" << endl;
    cout << "e) Atras" << endl;
}
int main() {
    int opcion;
    string opcionChar;
    desplegarMenu();
    cin >> opcion;

    while (opcion != 6){
        switch (opcion){
            case 1:
                menuAlumnos();
                cin >> opcionChar;
                while (opcionChar != "d"){
                    if (opcionChar == "a" ){
                        cout << "Crear alumno" << endl;
                        
                    } else if (opcionChar == "b"){
                        cout << "Buscar alumno" << endl;
                       
                    } else if (opcionChar == "c"){
                        cout << "Eliminar alumno" << endl;
                        
                    } else if (opcionChar == "d"){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuAlumnos();
                    cin >> opcionChar;
                }
                break;
            case 2:
                menuCursos();
                cin >> opcionChar;
                while (opcionChar != "d"){
                    if (opcionChar == "a" ){
                        cout << "Crear curso" << endl;
                        
                    } else if (opcionChar == "b"){
                        cout << "Buscar curso" << endl;
                       
                    } else if (opcionChar == "c"){
                        cout << "Eliminar curso" << endl;
                        
                    } else if (opcionChar == "d"){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuCursos();
                    cin >> opcionChar;
                } 
                break;
            case 3:
                menuInscripciones();
                cin >> opcionChar;
                while (opcionChar != "c"){
                    if (opcionChar == "a" ){
                        cout << "Inscribir alumno a curso" << endl;
                        
                    } else if (opcionChar == "b"){
                        cout << "Eliminar Alumno de un curso" << endl;
                       
                    } else if (opcionChar == "c"){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuInscripciones();
                    cin >> opcionChar;
                }
                break;
            case 4:
                menuNotas();
                cin >> opcionChar;
                while (opcionChar != "b"){
                    if (opcionChar == "a" ){
                        cout << "Ingresar nota" << endl;
                        
                    } else if (opcionChar == "b"){
                        cout << "Atras" << endl;
                       
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuNotas();
                    cin >> opcionChar;
                }
                break;
            case 5:
                menuConsultas();
                cin >> opcionChar;
                while (opcionChar != "e"){
                    if (opcionChar == "a" ){
                        cout << "Obtener alumnos de una carrera" << endl;
                        
                    } else if (opcionChar == "b"){
                        cout << "Obtener cursos inscrito por un alumno" << endl;
                       
                    } else if (opcionChar == "c"){
                        cout << "Promedio de notas de un alumno en un curso" << endl;
                        
                    } else if (opcionChar == "d"){
                        cout << "Promedio general de notas de un alumno" << endl;
                        
                    } else if (opcionChar == "e"){
                        cout << "Atras" << endl;
                        
                    } else {
                        cout << "Opcion no valida" << endl;
                    }
                    menuConsultas();
                    cin >> opcionChar;
                }
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        desplegarMenu();
        cin >> opcion;
    }
    return 0;
}

//  g++ -o m Main.cpp
//    ./m