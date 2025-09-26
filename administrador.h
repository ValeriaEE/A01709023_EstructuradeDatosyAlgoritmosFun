#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <iostream>
//Se incluye las clases que se van a utilizar 
#include "estudiante.h"
#include "mentor.h"
#include "profesor.h"
#include "persona.h"
#include "actividad.h"


using namespace std;

//Se define el numero maximo de integrantes por categoria 
const int MAX = 100;


class Administrador {
private:
// Arreglo de apuntadores a objetos de tamaño Max 	
    Estudiante* estudiantes[MAX];
    Mentor* mentores[MAX];
    Profesor* profesores[MAX];

//Variables para llevar el conteo integrates registrados
    int numEstudiantes = 0;
    int numMentores = 0;
    int numProfesores = 0;

public:

    ~Administrador();  //destructor

//metodos para registrar actividades 
//suma puntos o haras a un estudiante o mentor
    void registrarActividadParaEstudiante(Estudiante* e, Actividad &a);
    void registrarActividadParaMentor(Mentor* m, Actividad &a);
	
//Sobrecarga para registrar activida por indice
    void registrarActividadEstudiante(int indice, Actividad &a);
    void registrarActividadMentor(int indice, Actividad &a);

//Metodos para agregar personas
    void agregarEstudiante( Estudiante* e);
    void agregarMentor( Mentor* m);
    void agregarProfesor(Profesor* p);

//Metodos para mostrar las personas
    void mostrarEstudiantes();
    void mostrarMentores();
    void mostrarProfesores();
	
//Genera una lista de quienes pueden ir al regional 
    void generarListaAsistentes();

    void bubbleSortEstudiantesPorPuntos();
    void bubbleSortMentoresPorHoras();  
};

// Destructores para todas las personas
Administrador::~Administrador() {
    for (int i = 0; i < numEstudiantes; ++i) delete estudiantes[i];
    for (int i = 0; i < numMentores; ++i) delete mentores[i];
    for (int i = 0; i < numProfesores; ++i) delete profesores[i];
}

//Agrega a un estudiante al arreglo si aun hay espacio 
void Administrador::agregarEstudiante( Estudiante* e) {
    if (numEstudiantes < MAX)
        estudiantes[numEstudiantes++] = e;
}

//Agrega a un profesor al arreglo si aun hay espacio 
void Administrador::agregarMentor(Mentor* m) {
    if (numMentores < MAX)
        mentores[numMentores++] = m;
}

//Agrega a un profesor al arreglo si aun hay espacio 
void Administrador::agregarProfesor(Profesor* p) {
    if (numProfesores < MAX)
        profesores[numProfesores++] = p;
}


void Administrador::mostrarEstudiantes() {
    cout << "\n--- Estudiantes  ---\n";

    // Ordenamos primero
    bubbleSortEstudiantesPorPuntos();

    // Ahora imprimimos
    for (int i = 0; i < numEstudiantes; ++i)
        cout << estudiantes[i]->mostrarInfo() << " | Puntos: " 
             << estudiantes[i]->getPuntosImpact() << endl;
}

//Imprime la info de los mentores
void Administrador::mostrarMentores() {
    cout << "\n--- Mentores ---\n";
    for (int i = 0; i < numMentores; ++i)
        cout << mentores[i]->mostrarInfo() <<endl;
}

//Imprime la info de los profesores
void Administrador::mostrarProfesores() {
    cout << "\n--- Profesores ---\n";
    for (int i = 0; i < numProfesores; ++i)
        cout << profesores[i]->mostrarInfo() <<endl;
}

//Verifica quien puede ir a los regionales e imprime esa lista 
void Administrador::generarListaAsistentes() {
    cout << "\n--- Lista de asistentes al regional ---\n";
	
	//Cuenta los estudiantes que cumplen los requisitos
    int estudiantesValidos = 0;
    for (int i = 0; i < numEstudiantes; ++i)
        if (estudiantes[i]->puedeIrARegional())
            estudiantesValidos++;
	
	//Cuenta los mentores que cumplen los requisitos 
    int mentoresValidos = 0;
    for (int i = 0; i < numMentores; ++i)
        if (mentores[i]->puedeIrARegional())
            mentoresValidos++;

	//Calcula cuantos profes se necesitan para viajar (1 por 15 estudiantes)
    int necesariosProfes = (estudiantesValidos + 14) / 15;

	//Si faltan profes se cancela todo y se imprime el mensaje 
    if (numProfesores < necesariosProfes) {
        cout << "Faltan profesores. Se requieren al menos "
             << necesariosProfes << " profesores, pero solo hay "
             << numProfesores << ".\n";
        return;
    }

//Muestra las personas validas que pueden ir 
    cout << "\nEstudiantes válidos:\n";
    for (int i = 0; i < numEstudiantes; ++i)
        if (estudiantes[i]->puedeIrARegional())
            cout << estudiantes[i]->mostrarInfo() << endl;

    cout << "\nMentores válidos:\n";
    for (int i = 0; i < numMentores; ++i)
        if (mentores[i]->puedeIrARegional())
            cout << mentores[i]->mostrarInfo()<< endl;

    cout << "\nProfesores acompañantes:\n";
    for (int i = 0; i < necesariosProfes; ++i)
        cout << profesores[i]-> mostrarInfo()<< endl;
}

// Métodos de registro de actividad

//Resgistra una act para un estudiante (se suma los puntos)
void Administrador::registrarActividadParaEstudiante(Estudiante* e,  Actividad &a) {
    e->setPuntosImpact(e->getPuntosImpact() + a.getNumPuntos());
}

//Registra una act para un mentor (se suman las horas)
void Administrador::registrarActividadParaMentor(Mentor* m,  Actividad &a) {
    m->setHorasServicio(m->getHorasServicio() + a.getHoras());
}

// Registra actividad a un estudiante por su índice en el arreglo
void Administrador::registrarActividadEstudiante(int indice,  Actividad &a) {
    if (indice >= 0 && indice < numEstudiantes)
        registrarActividadParaEstudiante(estudiantes[indice], a);
}

// Registra actividad a un mentor dado su índice en el arreglo
void Administrador::registrarActividadMentor(int indice,  Actividad &a) {
    if (indice >= 0 && indice < numMentores)
        registrarActividadParaMentor(mentores[indice], a);
}

// Ordenar por bubble Sort a los estudiantes 
void Administrador::bubbleSortEstudiantesPorPuntos() {
    for (int i = 0; i < numEstudiantes - 1; i++) {
        for (int j = 0; j < numEstudiantes - i - 1; j++) {
            if (estudiantes[j]->getPuntosImpact() < estudiantes[j + 1]->getPuntosImpact()) {
                // Intercambio de apuntadores
                Estudiante* temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}
// Ordenar por bubble Sort a los mentores
void Administrador::bubbleSortMentoresPorHoras() {
    for (int i = 0; i < numMentores - 1; i++) {
        for (int j = 0; j < numMentores - i - 1; j++) {
            if (mentores[j]->getHorasServicio() < mentores[j + 1]->getHorasServicio()) {
                // Intercambio de apuntadores
                Mentor* temp = mentores[j];
                mentores[j] = mentores[j + 1];
                mentores[j + 1] = temp;
            }
        }
    }
}
#endif
