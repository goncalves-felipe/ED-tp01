#include "./Celula.h"
#include <iostream>
#include <string>

class Lista
{
public:
    Lista();
    ~Lista();

    int GetTamanho() { return tamanho; };
    void InserirInicio(std::string item);
    void InserirFim(std::string item);
    void InserirPosicao(std::string item, int pos);
    void SetItem(std::string item, int pos);
    std::string RemoverInicio();
    std::string RemoverFim();
    std::string RemoverPosicao(int pos);
    std::string GetItem(int pos);
    void Imprimir();
    void Limpar();
    Celula *inicio;

private:
    int tamanho;
    Celula *fim;
    Celula *Posicionar(int pos, bool antes);
};