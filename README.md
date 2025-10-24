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
Por accion dentro del archivo dlist.h
add() = O(1)
getAt() = O(n)
setAt() = O(n)
removeAt() = O(1)
removeAt() = O(n)
removeAt() = O(n)
clear() = O(n)
toString() = O(n)

## SICT0302 Toma de Decisiones
### A Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para mi proyecto, decidí utilizar Merge Sort por varias características que lo hacen el más adecuado: 

Una de las principales razones es su complejidad constante de O(n log n) tanto en el mejor como en el peor de los casos. Esto lo convierte en una excelente opción para manejar arreglos grandes y desordenados de objetos, como en mi programa, donde se almacenan estudiantes y mentores con distintos valores de puntos CAS o de horas de servicio.

Además, Merge Sort es un algoritmo estable, lo que significa que si dos elementos tienen el mismo valor en el criterio de ordenamiento (por ejemplo, dos estudiantes con la misma cantidad de puntos CAS), el algoritmo mantiene su orden relativo original en la lista. Esto es importante en mi proyecto, ya que cada estudiante o mentor tiene múltiples atributos (nombre, ID, rol, etc.), y mantener la coherencia entre ellos al ordenar mejora la claridad y precisión del sistema.

En comparación de Bubble Sort, que solo es eficiente con listas muy pequeñas o casi ordenadas, Merge Sort se mantiene eficiente y predecible sin importar el estado inicial de los datos.

En conclusión, elegí Merge Sort porque  es constante y confiable,, mantiene la estabilidad de los datos, y puede manejar grandes volúmenes de información sin comprometer lo eficiente que es.  Por eso es el ideal para mi proyecto, pues necesito ordenar los integrantes del equipo según sus puntos o sus horas de servicio, garantizando una organización clara y justa para determinar quiénes pueden asistir a los eventos regionales.

### B Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para este avance cambié un arreglo fijo que medía 100 por una lista doblemente ligada para guardar los integrantes del equipo. Esto lo hice crenaod otro archivo llamado dlist.h y lo utilize en administrador. Elegí usar una  lista doblemente ligada porque:

La lista doblemente ligada me  permite insertar y eliminar estudiantes, mentores o profesores fácilmente, incluso en medio de la lista. Esto es muy bueno para mi programa porque para un equipo tan dinámico como TecDroid donde la gente se va y llega y los puntos van cambiando se necesita poder modificarlo. 

Me permite recorrer la lista hacia adelante y hacia atrás, lo cual es útil para organizar la supervisión y ordenar por puntos o horas.

Facilita gestionar distintos tipos de integrantes usando polimorfismo. Como estudiante, profesor y mentor que son personas. 

Es eficiente y flexible para un equipo dinámico como TecDroid, donde los integrantes cambian, el grupo crece y se hace más pequeño, las actividades se van actualizando, etc. 



## SICT0303 Implementa Acciones Científicas
### Implementa mecanismos para consultar información de las estructras correctos.


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


