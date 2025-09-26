#ifndef PROFESOR_H_
#define PROFESOR_H_

#include "persona.h" // clase base de estudiante
#include <iostream>
#include <string> 
#include <sstream>  //  necesario para usar stringstream


using namespace std;

//Profesor hereda de persona
class Profesor: public Persona {
private:
    string puesto; //Puesto en el equipo
	string departamento; //Departamento dentro del tec

public:
// Constructores
    Profesor() : puesto(""), departamento("") {}
    Profesor(string nombre, int edad, string puesto, string departamento)
        : Persona(nombre, edad), puesto(puesto), departamento(departamento) {}
    
    // Getters y setters 
    string getPuesto() { return puesto; }
    void setPuesto(string puestoenTD) { puesto = puestoenTD; }
    
	string getDepartamento() { return departamento; }
    void setDepartamento(string depProfesor) { departamento = depProfesor;}
    
	//Declaracion de metodos
	 string mostrarInfo();
	bool puedeIrARegional();
    

    
};

/* Mostrar info convierte los atributos en un string y lo imprime 
Este metodo sobreescribe virtualmente el de la clase base 
para mostrar la info del profesor  
Utiliza stringstream para armar un string completo y devolverlo
*/
string Profesor::mostrarInfo(){
		stringstream aux; 
		aux << "Profesor: " << getNombre()
             << ", Edad: " << getEdad()
             << ", Puesto: " << puesto
             << ", Departamento: " << departamento
             << endl;
			return aux.str();
	}
	
/* Este método sobreescribe de la clase base
 En profesor simepr devuelve true pues los profesores 
 no necesitan ningun tipo de validacion para ir a los regionales 
*/
bool Profesor::puedeIrARegional() {
        return true; 
    }

#endif