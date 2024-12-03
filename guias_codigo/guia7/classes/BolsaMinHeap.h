//  This is the header of the object "BolsaMinHeap".

#ifndef BOLSAMINHEAP_H
#define BOLSAMINHEAP_H

class BolsaMinHeap
{
    public:
        BolsaMinHeap();
        bool es_vacio() const;
        //  Indica si no hay más elementos.
        //  O(1)
        void encolar(const int & c);
        //  Almacena el elemento c.
        //  O(log N)
        int desencolar_minimo();
        //  Quita el elemento más chico y lo devuelve.
        //  O(log N)
    
        //  N being the amount of stored elements
    private:
        
};

#endif