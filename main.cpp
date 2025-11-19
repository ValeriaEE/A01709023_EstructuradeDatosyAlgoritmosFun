#include "estudiante.h"
#include "mentor.h"
#include "profesor.h"
#include "administrador.h"
#include "actividad.h"

#include <iostream>
#include <limits>

using namespace std;

int main() {
    Administrador admin;
    int opcion;

    // Carga inicial
    cout << "Cargando datos..." << endl;
    admin.cargarEstudiantesDesdeArchivo("estudiantes.txt");
    admin.cargarMentoresDesdeArchivo("mentores.txt");
    admin.cargarProfesoresDesdeArchivo("profesores.txt");
    admin.cargarActividadesDesdeArchivo("actividades.txt");
    cout << "Carga finalizada." << endl;

    do {
        cout << "\n----- MENU TEC-DROID -----\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Agregar mentor\n";
        cout << "3. Agregar profesor\n";
        cout << "4. Mostrar todas las personas\n";
        cout << "5. Ver lista de asistentes al regional\n";
        cout << "6. Registrar actividad a una persona\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // OPCION 1 – Agregar Estudiante
        if (opcion == 1) {
            string nombre, area, tipo;
            int edad, puntos;

            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cout << "Puntos iniciales: ";
            cin >> puntos;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Area: ";
            getline(cin, area);
            cout << "Tipo colaborador: ";
            getline(cin, tipo);

            Estudiante* est = new Estudiante(nombre, edad, puntos, area, tipo);
            admin.agregarEstudiante(est);
        }

        // OPCION 2 – Agregar Mentor
        else if (opcion == 2) {
            string nombre;
            int edad, horas;

            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cout << "Horas iniciales: ";
            cin >> horas;

            Mentor* m = new Mentor(nombre, edad, horas);
            admin.agregarMentor(m);
        }

        // OPCION 3 – Agregar Profesor
        else if (opcion == 3) {
            string nombre, puesto, depto;
            int edad;

            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Puesto: ";
            getline(cin, puesto);
            cout << "Departamento: ";
            getline(cin, depto);

            Profesor* p = new Profesor(nombre, edad, puesto, depto);
            admin.agregarProfesor(p);
        }

        // OPCION 4 – Mostrar todo
        else if (opcion == 4) {
            admin.mostrarEstudiantes();
            admin.mostrarMentores();
            admin.mostrarProfesores();
        }

        // OPCION 5 – Lista asistentes
        else if (opcion == 5) {
            admin.generarListaAsistentes();
        }

        // OPCION 6 – Registrar una actividad
        else if (opcion == 6) {
            int tipo, idxActividad, idxPersona;

            cout << "Asignar a: (1. Estudiante, 2. Mentor): ";
            cin >> tipo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (tipo != 1 && tipo != 2) {
                cout << "Tipo invalido.\n";
                continue;
            }

            admin.mostrarActividadesDisponibles();
            cout << "Selecciona el numero de la actividad: ";
            cin >> idxActividad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Actividad* act = admin.getActividad(idxActividad);
            if (!act) {
                cout << "Actividad invalida.\n";
                continue;
            }

            if (tipo == 1) {
                admin.mostrarEstudiantes();
                cout << "Selecciona indice del estudiante: ";
                cin >> idxPersona;

                if (idxPersona >= 0 && idxPersona < admin.getnumEstudiantes()) {
                    admin.registrarActividadEstudiante(idxPersona, *act);
                } else {
                    cout << "Indice invalido.\n";
                }
            } else {
                admin.mostrarMentores();
                cout << "Selecciona indice del mentor: ";
                cin >> idxPersona;

                if (idxPersona >= 0 && idxPersona < admin.getnumMentores()) {
                    admin.registrarActividadMentor(idxPersona, *act);
                } else {
                    cout << "Indice invalido.\n";
                }
            }
        }

        else if (opcion != 0) {
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    cout << "Guardando datos..." << endl;
    admin.guardarTodo();
    cout << "Saliendo del sistema.\n";

    return 0;
}
