#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>
#include <iostream>

using namespace std;

// Clase abstracta 
//Representa a cualquier persona dentro del equipo 
class Persona {
protected:
    string nombre; //Nombre de la persona
    int edad; //Edad de la persona 
    
public:
    // Constructores
    Persona() : nombre(""), edad(0) {}
    Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}
    
    // Getters y setters 
    string getNombre() { return nombre; }
    void setNombre(string nombrePersona) { nombre = nombrePersona; }
    
    int getEdad() { return edad; }
    void setEdad(int edadPersona) { edad = edadPersona; }
    
	/*Metodos virtuales que convierte a persona en una clase abstracta
no tiene implementacion aqui sino en las clases hijas 
Permite el polimorfismo */	
	virtual string mostrarInfo()=0;
	virtual bool puedeIrARegional ()=0; 
	

    virtual ~Persona() {} //Destructor
};
#endif