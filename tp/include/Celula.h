#include <iostream>
#include <string>

class Celula
{
public:
    Celula();
    ~Celula();
    void SetValor(std::string valor);
    std::string GetValor() { return valor; };

private:
    std::string valor;
    Celula *prox;

    friend class Lista;
};
