#ifndef MENTOR_H_
#define MENTOR_H_

#include "persona.h"
#include <iostream>
#include <string>
#include <sstream>  // necesario para usar stringstream


using namespace std;

class Mentor : public Persona {
private:
    int horasServicio;

public:
    // Constructores
    Mentor() : horasServicio(0) {}
    Mentor(int horasServicio) : horasServicio(horasServicio) {}
    Mentor(const string& nombre, int edad, int horasServicio)
        : Persona(nombre, edad), horasServicio(horasServicio) {}

    // Getters y setters
    int getHorasServicio() { return horasServicio; }
    void setHorasServicio(int horas) { horasServicio = horas; }
	
	// declaracion de metodos 
	string mostrarInfo();
	bool puedeIrARegional();
};

/* Mostrar info convierte los atributos en un string y lo imprime 
Este metodo sobreescribe virtualmente el de la clase base 
para mostrar la info del mentor
Utiliza stringstream para armar un string completo y devolverlo
*/
string Mentor::mostrarInfo(){
		stringstream aux; 
		aux << "Mentor: " << getNombre()
             << ", Edad: " << getEdad()
             << ", Horas de Servicio: " << horasServicio
             << endl;
			return aux.str();
	}
	
/* Este método encapsula la lógica de validación 
y sobreescribe de la clase base
 Devuelve true si el estudiante tiene al menos 20 horas de servicio,
 lo cual se usa en el método generarListaAsistentes() del Administrador
*/
 
bool Mentor::puedeIrARegional() {
        return horasServicio >= 20;
    }


#endif
