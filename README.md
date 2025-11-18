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
### A Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El algoritmo implementado para ordenar a los estudiantes (por puntos) y mentores (por horas) es Merge Sort.

**División del arreglo:**
 Cada vez se divide el arreglo en dos mitades. **log₂(n)**

**Combinación de subarreglos:**
 En cada nivel de recursión, se comparan y combinan todos los elementos una vez. **O(n)**

**Combinando ambos procesos:**
Niveles de división → **O(log n)**
Trabajo por nivel → **O(n)**
 Complejidad total:
 **O(nlog⁡n)O(n \log n)O(nlogn)**

**Complejidad**
Mejor caso = O(n log n)
Caso promedio =  O(n log n)
Peor caso = O(n log n)

### B Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Se utiliza una Lista Doblemente Ligada para todos los integrantes del equipo gestionada en dlist.h.

Por accion dentro del archivo dlist.h

add() 
mejor caso = O(1)
caso promedio = O(1)
peor caso = O(1)

getAt()
mejor caso = O(1)
caso promedio = O(n)
peor caso = O(n)

removeAt() 
mejor caso = O(1)
caso promedio = O(n)
peor caso = O(n)

clear() 
mejor caso = O(1)
caso promedio = O(n)
peor caso = O(n)

## SICT0302 Toma de Decisiones
### A Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para este proyecto, seleccioné Merge Sort sobre opciones como Bubble Sort o Quick Sort basándome en las siguientes características técnicas:
1. Eficiencia: A diferencia de Bubble Sort (O(n^2)), Merge Sort mantiene una complejidad de O(n \log n) en todos los casos. Dado que el equipo TecDroid puede crecer, es importante que el tiempo de ejecución no aumente cuadráticamente con el número de miembros.
2. Estabilidad: Merge Sort es un algoritmo estable. Si dos estudiantes tienen la misma cantidad de puntos, el algoritmo preserva el orden original de registro. Esto es crucial para mantener la equidad en listas de espera o antigüedad
3. .Manejo de Listas Ligadas: Merge Sort es ideal para listas ligadas ya que no requiere acceso aleatorio a memoria (como Quick Sort), sino que trabaja manipulando punteros next y prev, lo cual es eficiente en esta estructura.

### B Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Decidí reemplazar el arreglo estático inicial por una Lista Doblemente Ligada (DList) debido a la naturaleza dinámica del equipo:
1. Gestión de Memoria: A diferencia de un arreglo fijo, la lista crece y decrece dinámicamente. Esto optimiza el uso de memoria, asignando recursos solo cuando se crea un nuevo Estudiante o Mentor.
2. Eficiencia en Modificaciones: En la lista ligada, una vez localizado el nodo, la eliminación es solo reasignación de punteros (O(1)), lo cual es más eficiente para la manipulación de la estructura.
3. Bidireccionalidad: La estructura doblemente ligada permite recorrer la información en ambos sentidos, facilitando algoritmos de ordenamiento y revisión de datos. 

## SICT0303 Implementa Acciones Científicas
### Implementa mecanismos para consultar información de las estructras correctos.
Para acceder a la información dentro de la estructura DList, implementé el método getAt(int index).

Mecanismo: Este método recibe un índice entero, inicia un puntero auxiliar en el head de la lista y realiza un ciclo for para avanzar a través de los punteros next hasta llegar a la posición deseada.

Retorno: Devuelve un puntero al objeto almacenado (Estudiante*, Mentor*, etc.), permitiendo el uso de polimorfismo para invocar métodos como mostrarInfo() o getPuntosImpact().

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En mi proyecto, implementé mecanismos de lectura de archivos para cargar los datos de estudiantes, mentores y profesores a las estructuras de datos del sistema. Cada tipo de integrante tiene su propio archivo de texto, en el que cada línea representa un objeto con sus atributos separados por comas (por ejemplo, nombre, edad, puntos o horas de servicio, área, tipo de colaborador). Para procesar estos archivos, se utiliza la clase ifstream de <fstream> para abrir y leer cada línea, y stringstream de <sstream> para separar cada componente de la línea y convertirlos a los tipos de datos correctos. Cada registro leído se convierte en un objeto dinámico de su clase (Estudiante, Mentor o Profesor) y se agrega a la lista doblemente ligada con los métodos agregarEstudiante, agregarMentor y agregarProfesor. De esta forma, el sistema carga lo datos y los agrega a la lista. 

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


