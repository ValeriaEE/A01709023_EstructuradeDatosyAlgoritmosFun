# A01709023_EstructuradeDatosyAlgoritmosFun
Proyecto de la clase TC1031.603 Programacion de estructura de datos y algoritmos fundamentales 

## *Contexto*
Este programa está diseñado para mejorar la organización del grupo estudiantil de robótica TecDroid 3354. Dentro del equipo existen tres tipos principales de integrantes:

Estudiantes (divididos en mesa directiva y colaboradores)

Mentores

Profesores

El objetivo del programa es facilitar la gestión de los integrantes del equipo y apoyar en la planeación de los eventos regionales. Para ello, el código permite:

Crear personas y asignarlas a las distintas categorías del equipo.

Asignar puntos CAS (Puntos Impact) a los estudiantes y horas de servicio a los mentores.

Determinar qué personas cumplen con los requisitos para asistir a los regionales:

Estudiantes necesitan una cierta cantidad de puntos CAS.

Mentores necesitan un mínimo de horas de servicio.

Generar una lista final de asistentes que puedan ir al regional:

Incluye estudiantes que tengan los puntos para ir, mentores con horas de servicio y profesores acompañantes.

Se asegura que por cada 15 estudiantes haya al menos un profesor acompañante, cumpliendo con las reglas de supervisión.

Este sistema ayuda a mantener el control del equipo de forma automatizada, asegurando que se cumplan los requisitos para asistir a los eventos y organizando de forma clara quiénes van y quiénes acompañan. 

## *Como usar el programa*
Compilar el programa

***g++ menuTD.cpp -o menuTD***


Ejecutar el programa

***./menuTD***


Navegar el menú
Al iniciar, verás un menú con opciones:

----- MENU TECDROID -----
1. Agregar estudiante
2. Agregar mentor
3. Agregar profesor
4. Mostrar todas las personas
5. Ver lista de personas que pueden ir al regional
6. Registrar actividad a una persona
0. Salir


Opción 1-3: Agregar estudiantes, mentores o profesores escribiendo sus datos.

Opción 4: Mostrar todas las personas registradas.

Los estudiantes aparecen ordenados por puntos.

Los mentores aparecen ordenados por horas de servicio.

Opción 5: Genera la lista de asistentes al regional validando puntos, horas y profesores acompañantes.

Opción 6: Registrar una actividad (suma puntos a un estudiante o horas a un mentor).

Opción 0: Salir del sistema.

Solo necesita seguir las instrucciones que aparecen en consola, escribiendo los datos que se piden.

## *Analisis de complejidad y justificacion* 

El programa utiliza el algoritmo Bubble Sort para ordenar:

Estudiantes (por puntos).

Mentores (por horas de servicio).

Complejidad de Bubble Sort

Tiempo:

Peor caso y caso promedio: O(n²)

Mejor caso (lista ya ordenada): O(n²)

Se usa Bubble Sort porque es un algoritmo muy sencillo de implementar y entender, lo que lo hace perfecto para un proyecto como este donde como mucho en el equipo habrá unas 70 personas. Además, el programa solo trabaja con un máximo de 100 elementos, así que la eficiencia cuadrática no representa un problema real. También es útil porque permite mostrar de manera clara cómo se pueden ordenar objetos como estudiantes o mentores sin necesidad de estructuras complicadas. Bubble Sort resulta una buena elección: es simple, práctico y cumple con lo que el programa necesita.
