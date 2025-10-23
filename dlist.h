#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

using namespace std;

// Declaración adelantada
template <class T> class DList;

// Clase del nodo doblemente ligado
template <class T>
class DLink {
private:
    DLink(T);
    DLink(T, DLink<T>*, DLink<T>*);

    T value;
    DLink<T> *previous;
    DLink<T> *next;

    friend class DList<T>;

public: 
    // Getters y setters
    T getValue() const { return value; }
    void setValue(T val) { value = val; }

    DLink<T>* getNext() const { return next; }
    void setNext(DLink<T>* nxt) { next = nxt; }

    DLink<T>* getPrevious() const { return previous; }
    void setPrevious(DLink<T>* prev) { previous = prev; }
};

// Implementaciones de DLink
template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

// Clase de lista doblemente ligada optimizada
template <class T>
class DList {
public:
    // Constructores y destructor
    DList();
    ~DList();

    // Métodos esenciales para tu proyecto
    void add(T val);                    // Agregar al final
    T getAt(int index) const;           // Obtener por índice
    void setAt(int index, T val);       // Modificar por índice
    T removeAt(int index);              // Eliminar por índice
    int size() const;                   // Tamaño de la lista
    bool empty() const;                 // Ver si está vacía
    void clear();                       // Limpiar lista
    
    // Métodos de utilidad para mostrar
    string toStringForward() const;     // De inicio a fin
    string toStringBackward() const;    // De fin a inicio
    
    // Métodos para iteración (necesarios para ordenamiento)
    DLink<T>* getHead() const { return head; }
    DLink<T>* getTail() const { return tail; }
    void setHead(DLink<T>* newHead) { head = newHead; }
    void setTail(DLink<T>* newTail) { tail = newTail; }

private:
    DLink<T> *head;
    DLink<T> *tail;
    int listSize;
};

// Constructor
template <class T>
DList<T>::DList() : head(0), tail(0), listSize(0) {}

// Destructor
template <class T>
DList<T>::~DList() {
    clear();
}

// Checar si está vacía
template <class T>
bool DList<T>::empty() const {
    return (head == 0 && tail == 0);
}

// Tamaño de la lista
template <class T>
int DList<T>::size() const {
    return listSize;
}

// Limpiar lista
template <class T>
void DList<T>::clear() {
    DLink<T> *p, *q;
    p = head;
    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    listSize = 0;
}

// Agregar elemento al final
template <class T>
void DList<T>::add(T val) {
    DLink<T> *newLink = new DLink<T>(val);
    
    if (empty()) {
        head = newLink;
        tail = newLink;
    } else {
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    listSize++;
}

// Obtener elemento por índice
template <class T>
T DList<T>::getAt(int index) const {
    if (index < 0 || index >= listSize) {
        return T(); // Valor por defecto
    }

    DLink<T> *p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    return p->value;
}

// Modificar elemento por índice
template <class T>
void DList<T>::setAt(int index, T val) {
    if (index < 0 || index >= listSize) {
        return;
    }

    DLink<T> *p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    p->value = val;
}

// Eliminar elemento por índice
template <class T>
T DList<T>::removeAt(int index) {
    if (index < 0 || index >= listSize) {
        return T();
    }

    // Caso especial: eliminar primer elemento
    if (index == 0) {
        DLink<T> *p = head;
        T val = p->value;
        
        if (head == tail) {
            head = 0;
            tail = 0;
        } else {
            head = p->next;
            head->previous = 0;
        }
        
        delete p;
        listSize--;
        return val;
    }

    // Buscar el nodo a eliminar
    DLink<T> *p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }

    T val = p->value;
    
    // Reconectar nodos adyacentes
    if (p->previous != 0) {
        p->previous->next = p->next;
    }
    if (p->next != 0) {
        p->next->previous = p->previous;
    }
    if (p == tail) {
        tail = p->previous;
    }
    
    delete p;
    listSize--;
    return val;
}

// Convertir a string de inicio a fin
template <class T>
string DList<T>::toStringForward() const {
    stringstream aux;
    DLink<T> *p = head;
    
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

// Convertir a string de fin a inicio
template <class T>
string DList<T>::toStringBackward() const {
    stringstream aux;
    DLink<T> *p = tail;
    
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif /* DLIST_H_ */