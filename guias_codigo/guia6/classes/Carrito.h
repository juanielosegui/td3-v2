// This is the header of the object "Carrito".
#include <string>
#include <vector>
#include <map>

class Carrito
{
    public:
        // Constructor
        Carrito(const int & peso_maximo);

        // Observers
        float peso_disponible() const;
        bool buscar_item(const std::string & nombre) const;
        float peso_de_item(const std::string & nombre) const;
        int precio_de_item(const std::string & nombre) const;

        // Modifiers
        void borrar_item(const std::string & nombre);
        void agregar_item(const std::string & nombre, const int & peso, const float & precio);

        // Other ops
        float monto_total() const;

    private:
        float _peso_maximo;
        std::vector<std::string> _items;
        std::map<std::string, int> _pesos_items;
        std::map<std::string, float> _precios_por_item;
};