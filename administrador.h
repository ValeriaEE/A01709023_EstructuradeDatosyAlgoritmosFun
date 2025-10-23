#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include <iostream>
#include "estudiante.h"
#include "mentor.h"
#include "profesor.h"
#include "persona.h"
#include "actividad.h"
#include "dlist.h"

using namespace std;

class Administrador {
private:
    DList<Estudiante*> estudiantes;
    DList<Mentor*> mentores;
    DList<Profesor*> profesores;

    DLink<Estudiante*>* mergeSortEstudiantes(DLink<Estudiante*>* cabeza);
    DLink<Estudiante*>* mergeEstudiantes(DLink<Estudiante*>* izquierda, DLink<Estudiante*>* derecha);
    DLink<Estudiante*>* dividirListaEstudiantes(DLink<Estudiante*>* cabeza);
    
    DLink<Mentor*>* mergeSortMentores(DLink<Mentor*>* cabeza);
    DLink<Mentor*>* mergeMentores(DLink<Mentor*>* izquierda, DLink<Mentor*>* derecha);
    DLink<Mentor*>* dividirListaMentores(DLink<Mentor*>* cabeza);

    void clear(); 

public:
    Administrador();  
    ~Administrador(); 

    void registrarActividadParaEstudiante(Estudiante* e, Actividad &a);
    void registrarActividadParaMentor(Mentor* m, Actividad &a);
    void registrarActividadEstudiante(int indice, Actividad &a);
    void registrarActividadMentor(int indice, Actividad &a);

    void agregarEstudiante(Estudiante* e);
    void agregarMentor(Mentor* m);
    void agregarProfesor(Profesor* p);

    void mostrarEstudiantes();
    void mostrarMentores();
    void mostrarProfesores();

    void eliminarEstudiante(int indice);
    void eliminarMentor(int indice);
    void eliminarProfesor(int indice);
	
    void generarListaAsistentes();

    void mergeSortEstudiantesPorPuntos();
    void mergeSortMentoresPorHoras();

    Estudiante* getEstudiante(int indice);
    Mentor* getMentor(int indice);
    Profesor* getProfesor(int indice);
    
    int getnumEstudiantes() const;
    int getnumMentores() const;
    int getnumProfesores() const;
};

// Constructor
Administrador::Administrador() {}

// Destructor
Administrador::~Administrador() {
    clear();
}

void Administrador::clear() {
    for (int i = estudiantes.size() - 1; i >= 0; i--) delete estudiantes.getAt(i);
    estudiantes.clear();
    
    for (int i = mentores.size() - 1; i >= 0; i--) delete mentores.getAt(i);
    mentores.clear();
    
    for (int i = profesores.size() - 1; i >= 0; i--) delete profesores.getAt(i);
    profesores.clear();
}

void Administrador::agregarEstudiante(Estudiante* e) { estudiantes.add(e); }
void Administrador::agregarMentor(Mentor* m) { mentores.add(m); }
void Administrador::agregarProfesor(Profesor* p) { profesores.add(p); }

void Administrador::eliminarEstudiante(int indice) {
    if (indice >= 0 && indice < estudiantes.size()) {
        delete estudiantes.getAt(indice);
        estudiantes.removeAt(indice);
    }
}

void Administrador::eliminarMentor(int indice) {
    if (indice >= 0 && indice < mentores.size()) {
        delete mentores.getAt(indice);
        mentores.removeAt(indice);
    }
}

void Administrador::eliminarProfesor(int indice) {
    if (indice >= 0 && indice < profesores.size()) {
        delete profesores.getAt(indice);
        profesores.removeAt(indice);
    }
}

Estudiante* Administrador::getEstudiante(int indice) {
    if (indice < 0 || indice >= estudiantes.size()) return NULL;
    return estudiantes.getAt(indice);
}

Mentor* Administrador::getMentor(int indice) {
    if (indice < 0 || indice >= mentores.size()) return NULL;
    return mentores.getAt(indice);
}

Profesor* Administrador::getProfesor(int indice) {
    if (indice < 0 || indice >= profesores.size()) return NULL;
    return profesores.getAt(indice);
}

int Administrador::getnumEstudiantes() const { return estudiantes.size(); }
int Administrador::getnumMentores() const { return mentores.size(); }
int Administrador::getnumProfesores() const { return profesores.size(); }


void Administrador::mostrarEstudiantes() {
    std::cout << "\n--- Estudiantes ---\n"; 
    std::cout << "Numero de estudiantes: " << estudiantes.size() << std::endl;

    mergeSortEstudiantesPorPuntos();

    for (int i = 0; i < estudiantes.size(); i++) {
        Estudiante* est = estudiantes.getAt(i); 
        std::cout << i + 1 << ". " << est->mostrarInfo()
                  << " | Puntos: " << est->getPuntosImpact() << std::endl;
    }
}

void Administrador::mostrarMentores() {
    std::cout << "\n--- Mentores ---\n";
    std::cout << "Numero de mentores: " << mentores.size() << std::endl;

    mergeSortMentoresPorHoras(); 
    
    for (int i = 0; i < mentores.size(); i++) {
        Mentor* men = mentores.getAt(i);
        std::cout << i + 1 << ". " << men->mostrarInfo() << std::endl;
    }
}

void Administrador::mostrarProfesores() {
    std::cout << "\n--- Profesores ---\n";
    std::cout << "Numero de profesores: " << profesores.size() << std::endl;

    for (int i = 0; i < profesores.size(); i++) {
        Profesor* prof = profesores.getAt(i);
        std::cout << i + 1 << ". " << prof->mostrarInfo() << std::endl;
    }
}

void Administrador::registrarActividadParaEstudiante(Estudiante* e, Actividad &a) {
    e->setPuntosImpact(e->getPuntosImpact() + a.getNumPuntos());
}

void Administrador::registrarActividadParaMentor(Mentor* m, Actividad &a) {
    m->setHorasServicio(m->getHorasServicio() + a.getHoras());
}

void Administrador::registrarActividadEstudiante(int indice, Actividad &a) {
    Estudiante* estudiante = getEstudiante(indice);
    if (estudiante != NULL) {
        registrarActividadParaEstudiante(estudiante, a);
    }
}

void Administrador::registrarActividadMentor(int indice, Actividad &a) {
    Mentor* mentor = getMentor(indice);
    if (mentor != NULL) {
        registrarActividadParaMentor(mentor, a);
    }
}


// Implementación de Merge Sort para Estudiantes
void Administrador::mergeSortEstudiantesPorPuntos() {
    if (estudiantes.size() <= 1) return;
    
    DLink<Estudiante*>* nuevaCabeza = mergeSortEstudiantes(estudiantes.getHead());
    estudiantes.setHead(nuevaCabeza);
    
    // Reconstruir tail
    DLink<Estudiante*>* actual = nuevaCabeza;
    while (actual != NULL && actual->getNext() != NULL) {
        actual = actual->getNext();
    }
    estudiantes.setTail(actual);
}

DLink<Estudiante*>* Administrador::dividirListaEstudiantes(DLink<Estudiante*>* cabeza) {
    if (cabeza == NULL || cabeza->getNext() == NULL) return NULL;
    
    DLink<Estudiante*>* lento = cabeza;
    DLink<Estudiante*>* rapido = cabeza->getNext();
    
    while (rapido != NULL && rapido->getNext() != NULL) {
        lento = lento->getNext();
        rapido = rapido->getNext()->getNext();
    }
    
    DLink<Estudiante*>* mitad = lento->getNext();
    lento->setNext(NULL);;
    if (mitad != NULL) mitad->setPrevious(NULL);
    
    return mitad;
}

DLink<Estudiante*>* Administrador::mergeEstudiantes(DLink<Estudiante*>* izquierda, DLink<Estudiante*>* derecha) {
    if (izquierda == NULL) return derecha;
    if (derecha == NULL) return izquierda;
    
    // Orden descendente por puntos
    if (izquierda->getValue()->getPuntosImpact() >= derecha->getValue()->getPuntosImpact()) {
        izquierda->setNext(mergeEstudiantes(izquierda->getNext(), derecha));
        if (izquierda->getNext() != NULL) {
            izquierda->getNext()->setPrevious(izquierda);
        }
        izquierda->setPrevious(NULL);
        return izquierda;
    } else {
        derecha->setNext(mergeEstudiantes(izquierda, derecha->getNext()));
        if (derecha->getNext() != NULL) {
            derecha->getNext()->setPrevious(derecha);
        }
        derecha->setPrevious(NULL);
        return derecha;
    }
}

DLink<Estudiante*>* Administrador::mergeSortEstudiantes(DLink<Estudiante*>* cabeza) {
    if (cabeza == NULL || cabeza->getNext() == NULL) return cabeza;
    
    DLink<Estudiante*>* mitad = dividirListaEstudiantes(cabeza);
    DLink<Estudiante*>* izquierda = mergeSortEstudiantes(cabeza);
    DLink<Estudiante*>* derecha = mergeSortEstudiantes(mitad);
    
    return mergeEstudiantes(izquierda, derecha);
}

// Implementación de Merge Sort para Mentores
void Administrador::mergeSortMentoresPorHoras() {
    if (mentores.size() <= 1) return;
    
    DLink<Mentor*>* nuevaCabeza = mergeSortMentores(mentores.getHead());
    mentores.setHead(nuevaCabeza);
    
    // Reconstruir tail
    DLink<Mentor*>* actual = nuevaCabeza;
    while (actual != NULL && actual->getNext() != NULL) {
        actual = actual->getNext();
    }
    mentores.setTail(actual);
}

DLink<Mentor*>* Administrador::dividirListaMentores(DLink<Mentor*>* cabeza) {
    if (cabeza == NULL || cabeza->getNext() == NULL) return NULL;
    
    DLink<Mentor*>* lento = cabeza;
    DLink<Mentor*>* rapido = cabeza->getNext();
    
    while (rapido != NULL && rapido->getNext() != NULL) {
        lento = lento->getNext();
        rapido = rapido->getNext()->getNext();
    }
    
    DLink<Mentor*>* mitad = lento->getNext();
    lento->setNext(NULL);
    if (mitad != NULL) mitad->setPrevious(NULL);
    
    return mitad;
}

DLink<Mentor*>* Administrador::mergeMentores(DLink<Mentor*>* izquierda, DLink<Mentor*>* derecha) {
    if (izquierda == NULL) return derecha;
    if (derecha == NULL) return izquierda;
    
    // Orden descendente por horas
    if (izquierda->getValue()->getHorasServicio() >= derecha->getValue()->getHorasServicio()) {
        izquierda->setNext(mergeMentores(izquierda->getNext(), derecha));
        if (izquierda->getNext() != NULL) {
            izquierda->getNext()->setPrevious(izquierda);
        }
        izquierda->setPrevious(NULL);
        return izquierda;
    } else {
        derecha->setNext(mergeMentores(izquierda, derecha->getNext()));
        if (derecha->getNext() != NULL) {
            derecha->getNext()->setPrevious(derecha);
        }
        derecha->setPrevious(NULL);
        return derecha;
    }
}

DLink<Mentor*>* Administrador::mergeSortMentores(DLink<Mentor*>* cabeza) {
    if (cabeza == NULL || cabeza->getNext() == NULL) return cabeza;
    
    DLink<Mentor*>* mitad = dividirListaMentores(cabeza);
    DLink<Mentor*>* izquierda = mergeSortMentores(cabeza);
    DLink<Mentor*>* derecha = mergeSortMentores(mitad);
    
    return mergeMentores(izquierda, derecha);
}
// Generar lista de asistentes al regional
void Administrador::generarListaAsistentes() {
    cout << "\n--- Lista de asistentes al regional ---\n";
    
    // Contar estudiantes válidos
    int estudiantesValidos = 0;
    for (int i = 0; i < estudiantes.size(); i++) {
        if (estudiantes.getAt(i)->puedeIrARegional()) {
            estudiantesValidos++;
        }
    }
    
    // Contar mentores válidos
    int mentoresValidos = 0;
    for (int i = 0; i < mentores.size(); i++) {
        if (mentores.getAt(i)->puedeIrARegional()) {
            mentoresValidos++;
        }
    }
    
    // Calcular profesores necesarios
    int necesariosProfes = (estudiantesValidos + 14) / 15;
    
    if (profesores.size() < necesariosProfes) {
        cout << "Faltan profesores. Se requieren al menos "
             << necesariosProfes << " profesores, pero solo hay "
             << profesores.size() << ".\n";
        return;
    }
    
    // Mostrar estudiantes válidos
    cout << "\nEstudiantes válidos (" << estudiantesValidos << "):\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        Estudiante* est = estudiantes.getAt(i);
        if (est->puedeIrARegional()) {
            cout << "- " << est->mostrarInfo() << " | Puntos: " << est->getPuntosImpact() << endl;
        }
    }
    
    // Mostrar mentores válidos
    cout << "\nMentores válidos (" << mentoresValidos << "):\n";
    for (int i = 0; i < mentores.size(); i++) {
        Mentor* men = mentores.getAt(i);
        if (men->puedeIrARegional()) {
            cout << "- " << men->mostrarInfo() << " | Horas: " << men->getHorasServicio() << endl;
        }
    }
    
    // Mostrar profesores acompañantes
    cout << "\nProfesores acompañantes (" << necesariosProfes << "):\n";
    for (int i = 0; i < necesariosProfes && i < profesores.size(); i++) {
        cout << "- " << profesores.getAt(i)->mostrarInfo() << endl;
    }
}
#endif
