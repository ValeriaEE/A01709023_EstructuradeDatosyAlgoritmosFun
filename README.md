# Proyecto: Registro de estudiantes TecDroid
Proyecto de la clase TC1031.603 Programacion de estructura de datos y algoritmos fundamentales 
Valeria Escalante Campos A01709023 

## Contexto
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

## SICT0301 Evalua los Componentes 
# A Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Analisis de complejidad de merge sort 

# B Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Analisis de complejidad de lista doblemente encadenada 

## SICT0302 Toma de Decisiones
# A Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Porque elegi merge sort 

# B Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Porque elgi la lista doblemente encadenada 


## SICT0303 Implementa Acciones Científicas
# Implementa mecanismos para consultar información de las estructras correctos.
quien sabe 

# Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Como use el archivo de la lista de alumnos 

## Como usar el programa
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


