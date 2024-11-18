#include <stdexcept>

template<typename T>
class Lista {
    public:
        Lista() : _primero(nullptr), _ultimo(nullptr), _longitud(0), _cursor(nullptr) {}
        ~Lista();

        int longitud();

        void agregarAtras(const T& elemento);

        // Pre: 0 <= posicion < longitud()
        T iesimo(const int posicion);

        void borrarUltimo();
        void borrarIesimo(const int posicion);

        // Operación cursor: devuelve el elemento apuntado por el cursor.
        T cursor() const;

        // Operación avanzar: avanza el cursor al siguiente nodo.
        void avanzar();

        // Operación retroceder: mueve el cursor al nodo anterior.
        void retroceder();

    private:
        struct nodo {
            nodo(const T& un_elemento) : elemento(un_elemento), siguiente(nullptr), anterior(nullptr) {}
            T elemento;
            nodo* siguiente;
            nodo* anterior;
        };

        nodo* _primero;
        nodo* _ultimo;
        int _longitud;
        nodo* _cursor;  // Puntero al cursor
};

// Destructor para liberar memoria
template<typename T>
Lista<T>::~Lista() {
    nodo* actual = _primero;
    while (actual != nullptr) {
        nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Método longitud: devuelve el número de elementos en la lista
template<typename T>
int Lista<T>::longitud() {
    return _longitud;
}

// Agrega un nuevo elemento al final de la lista
template<typename T>
void Lista<T>::agregarAtras(const T& elemento) {
    nodo* nuevoNodo = new nodo(elemento);
    if (_longitud == 0) {
        _primero = nuevoNodo;
        _ultimo = nuevoNodo;
        _cursor = _primero;  // Si la lista estaba vacía, el cursor apunta al primer elemento
    } else {
        _ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = _ultimo;
        _ultimo = nuevoNodo;
    }
    _longitud++;
}

template<typename T>
T Lista<T>::iesimo(const int posicion) {
    nodo* actual = _primero;
    for (int i = 0; i < posicion && actual != nullptr; ++i) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        throw std::out_of_range("Posición fuera de rango");
    }
    return actual->elemento;
}

// Borra el último elemento de la lista
template<typename T>
void Lista<T>::borrarUltimo() {
    if (_longitud == 0) return;

    if (_longitud == 1) {
        delete _primero;
        _primero = nullptr;
        _ultimo = nullptr;
        _cursor = nullptr;  // El cursor queda indefinido
    } else {
        nodo* temp = _ultimo;
        _ultimo = _ultimo->anterior;
        _ultimo->siguiente = nullptr;
        if (_cursor == temp) {
            _cursor = _ultimo;  // Si el cursor estaba en el último, se mueve al anterior
        }
        delete temp;
    }
    _longitud--;
}

// Borra el elemento en la posición i-ésima
template<typename T>
void Lista<T>::borrarIesimo(const int posicion) {
    if (posicion < 0 || posicion >= _longitud) return;

    if (posicion == 0) {
        nodo* temp = _primero;
        _primero = _primero->siguiente;
        if (_primero) _primero->anterior = nullptr;
        if (_cursor == temp) _cursor = _primero;  // Si el cursor apuntaba al primer elemento
        delete temp;
    } else {
        nodo* actual = _primero;
        for (int i = 0; i < posicion - 1 && actual != nullptr; ++i) {
            actual = actual->siguiente;
        }
        nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        if (temp->siguiente) temp->siguiente->anterior = actual;
        if (_cursor == temp) {
            if (_cursor->siguiente) {
                _cursor = _cursor->siguiente;
            } else {
                _cursor = actual;  // Si el cursor estaba en el último, se mueve al anterior
            }
        }
        delete temp;
    }
    _longitud--;
}

// Devuelve el elemento apuntado por el cursor
template<typename T>
T Lista<T>::cursor() const {
    return (_cursor != nullptr) ? _cursor->elemento : T();
}

// Avanza el cursor al siguiente nodo
template<typename T>
void Lista<T>::avanzar() {
    if (_cursor != nullptr && _cursor->siguiente != nullptr) {
        _cursor = _cursor->siguiente;
    }
}

// Retrocede el cursor al nodo anterior
template<typename T>
void Lista<T>::retroceder() {
    if (_cursor != nullptr && _cursor->anterior != nullptr) {
        _cursor = _cursor->anterior;
    }
}