#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include "persona.h" //Calse base de estudiante 
#include <iostream>
#include <string>
#include <sstream>  //  necesario para usar stringstream


using namespace std;

//Estudiante hereda de persona
class Estudiante : public Persona {
private:
    int puntosImpact; //Puntos impact que tiene el estudiante 
    string area; //Area donde trabajan 
    string tipoColab; //Tipo de colaborador(Mesa, colab, etc.)

public:
    // Constructores
    Estudiante() : Persona(), puntosImpact(0), area(""), tipoColab("") {}

    Estudiante(string nombre, int edad, int puntosImpact, string area, string tipoColab)
        : Persona(nombre, edad), puntosImpact(puntosImpact), area(area), tipoColab(tipoColab) {}

    // Getters y setters
    int getPuntosImpact() { return puntosImpact; }
    void setPuntosImpact(int numPI) { puntosImpact = numPI; }

    string getArea() { return area; }
    void setArea(string areaEstudiante) { area = areaEstudiante; }

    string getTipoColab() { return tipoColab; }
    void setTipoColab(string tipo) { tipoColab = tipo; }
	
	//Declaracion de metodos 
	string mostrarInfo();
	bool puedeIrARegional();
    

    
};

/* Mostrar info convierte los atributos en un string y lo imprime 
Este metodo sobreescribe virtualmente el de la clase base 
para mostrar la info del estudiante 
Utiliza stringstream para armar un string completo y devolverlo
*/

string Estudiante::mostrarInfo(){
		stringstream aux; 
		aux << "Estudiante: " << getNombre() << endl;
        aux << ", Edad: " << getEdad() << endl;
        aux << ", Puntos Impact: " << puntosImpact << endl;
        aux << ", Área: " << area << endl;
        aux << ", Tipo de Colaborador: " << tipoColab << endl;
			return aux.str();
	}
	
/* Este método encapsula la lógica de validación 
y sobreescribe de la clase base
 Devuelve true si el estudiante tiene al menos 30 puntos,
 lo cual se usa en el método generarListaAsistentes() del Administrador
*/
 
bool Estudiante::puedeIrARegional() {
        return puntosImpact >= 30;
    }
#endif
