//Se incluyen clases que se van a utlizar
#include "estudiante.h"
#include "mentor.h"
#include "profesor.h"
#include "administrador.h"
#include "actividad.h"

#include <iostream>

using namespace std;
//Empieza el programa 
int main() {
	//Se crea un objeto administrador que maneja todo 
    Administrador admin; 
    int opcion; //Se usa para navegar el menu 

    do {
		//El menu imprime opciones al usuario y espera una entrada
        cout << "\n----- MENU TEC-DROID -----\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Agregar mentor\n";
        cout << "3. Agregar profesor\n";
        cout << "4. Mostrar todas las personas\n";
        cout << "5. Ver lista de personas que pueden ir al regional\n";
        cout << "6. Registrar actividad a una persona\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
		
		// Limpia el buffer para evitar errores con getline()
        cin.ignore(); 

        if (opcion == 1) {
			/*La opcion uno: 
			Solicita información básica del estudiante,
			crea el objeto con new 
			lo agrega al sistema usando el método agregarEstudiante()
            */
			
			//Se declaran las variables que se van a utilizar 
			string nombre, area, tipo;
            int edad, puntos;
			
	//Getline se usa para leer lineas de texto inclueyendo los espacios 
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cout << "Puntos Impact (iniciales): "; cin >> puntos;
            cin.ignore(); //Limpia el buffer 
            cout << "Area: "; getline(cin, area);
            cout << "Tipo colaborador: "; getline(cin, tipo);

			//Se crea el objeto y se agrega al arreglo 
            Estudiante* est= new Estudiante(nombre, edad, puntos, area, tipo);
            admin.agregarEstudiante(est);

        } else if (opcion == 2) {
			/*La opcion dos: 
			Solicita información básica del mentor,
			crea el objeto con new 
			lo agrega al sistema usando el método agregarMentor()
            */
			
			//Se declaran las variables que se van a utilizar 
            string nombre;
            int edad, horas;
//Getline se usa para leer lineas de texto inclueyendo los espacios 
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cout << "Horas de servicio (iniciales): "; cin >> horas;

		//Se crea el objeto y se agrega al arreglo 
            Mentor* m = new Mentor(nombre, edad, horas);
            admin.agregarMentor(m);

        } else if (opcion == 3) {
			/*La opcion tres: 
			Solicita información básica del profesor,
			crea el objeto con new 
			lo agrega al sistema usando el método agregarMentor()
            */
			
			//Se declaran las variables que se van a utilizar 
            string nombre, puesto, depto;
            int edad;
			
//Getline se usa para leer lineas de texto inclueyendo los espacios 
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cin.ignore();
            cout << "Puesto: "; getline(cin, puesto);
            cout << "Departamento: "; getline(cin, depto);
		//Se crea el objeto y se agrega al arreglo 
            Profesor* p = new Profesor(nombre, edad, puesto, depto);
            admin.agregarProfesor(p);

        } else if (opcion == 4) {
			/*La opcion cuatro: 
			Muestra las listas de personas que hay en el sistema 
			llamando la accion de mostrar por cada clase 
            */
            admin.mostrarEstudiantes();
            admin.mostrarMentores();
            admin.mostrarProfesores();

        } else if (opcion == 5) {
			/*La opcion cinco: 
			Ejecuta la lógica para determinar quién cumple
			con los requisitos para asistir al regional:
			Estudiantes con 30 puntos o mas.
			Mentores con suficientes horas.
			Se verifica si hay suficientes profesores acompañantes
            */
            admin.generarListaAsistentes();

        } else if (opcion == 6) {
			/*La opcion seis: 
			Crea una actividad con puntos CAS y horas
			Luego se asigna a un estudiante o mentor
			Dependiendo del cin (tipo)
			*/
			
			//Se declaran las variables que se van a utilizar 
            string nombreActividad, lugar;
            int puntos, horas, tipo;
			
			//Se pido la info de la actividad 
            cout << "Nombre de la actividad: ";
            cin.ignore();
            getline(cin, nombreActividad);
			cout << "Lugar en donde se lleva a cabo: ";
			getline(cin, lugar);
            cout << "Puntos CAS: ";
            cin >> puntos;
            cout << "Horas de servicio: ";
            cin >> horas;
            cout << "¿Asignar a? (1. Estudiante, 2. Mentor): ";
            cin >> tipo;
			
			//Se crea la actividad 
            Actividad act(nombreActividad, puntos, horas, lugar);

            if (tipo == 1) {
				/*Si es la opcion 1: 
				se muestran los estudiantes que existen 
				se pide el indice del estudiante 
				dependiendo del indice se registra la actividad al estudiante
				*/
                admin.mostrarEstudiantes();
                cout << "Selecciona el índice del estudiante: (Empieza el conteo en 0) ";
                int idx;
                cin >> idx;
				
			//El sistema le suma los puntos CAS de esa actividad al estudiante
                admin.registrarActividadEstudiante(idx, act);
            } else if (tipo == 2) {
				/*Si es la opcion 1: 
				se muestran los mentores que existen 
				se pide el indice del mentor
				dependiendo del indice se registra la actividad 
				*/
                admin.mostrarMentores();
                cout << "Selecciona el índice del mentor: ";
                int idx;
                cin >> idx;
				
			//El sistema le suma las horas de esa actividad al mentor
                admin.registrarActividadMentor(idx, act);
            } else {
				
				//Validacion de opcion incorrecta 
                cout << "Opción inválida.\n";
            }
        } else {
			
		//cualquier entrada que no sea del 0 al 6 y muestra un mensaje de error
			cout << "Opcion Invalida, porfavor selecciona una valida.\n";
		}
			

	//El menú sigue repitiéndose hasta que el usuario elige la opción 0
    } while (opcion != 0);

    cout << "Gracias por usar el sistema.\n";
    return 0;
}
