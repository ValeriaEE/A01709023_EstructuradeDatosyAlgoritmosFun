#ifndef ACTIVIDAD_H_
#define ACTIVIDAD_H_

#include <string>

using namespace std;

class Actividad {
private:
    string nombre; //Nombre de la activida
    int numPuntos; //Puntos Impact que da la act 
	string lugar; //Lugar donde se llevo acabo 
	int horas; //Horas de servicio que da la act 
  
public:
	//Constructores 
	Actividad() : nombre(""), numPuntos(0), horas(0), lugar("") {}
    Actividad(string nombre, int numPuntos, int horas, string lugar)
        : nombre(nombre), numPuntos(numPuntos), horas(horas), lugar(lugar) {}
		
    // Getters y setters
    string getNombre() { return nombre; }
    void setNombre(string nombreAct) { nombre = nombreAct; }
    
    int getNumPuntos() { return numPuntos; }
    void setNumPuntos(int npAct) { numPuntos = npAct; }
    
    string getLugar() { return lugar; }
    void setLugar(string lugarAct) { lugar = lugarAct; }
    
    int getHoras() { return horas; }
    void setHoras(int horasAct) { horas = horasAct; }
};

#endif