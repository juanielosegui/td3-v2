// This is the header of the object "Conjunto".
#include <vector>

class Conjunto
{
    public:
        /* ... */
        void agregar(const int & elem);
        /* ... */
    private:
        std::vector<int> elementos;
};