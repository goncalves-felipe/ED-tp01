#include "../include/Lista.h"
#include <string>

Lista::Lista()
{
    this->tamanho = 0;
    this->inicio = new Celula();
    this->fim = this->inicio;
}

Lista::~Lista()
{
}

void Lista::Limpar()
{
    Celula *aux = this->inicio->prox;

    while (aux != NULL)
    {
        this->inicio->prox = aux->prox;
        delete aux;
        aux = this->inicio->prox;
    }

    this->fim = this->inicio;
    this->tamanho = 0;
}

Celula *Lista::Posicionar(int pos, bool antes = false)
{
    if ((pos > this->tamanho) || (pos <= 0))
        exit(1);

    Celula *aux = this->inicio;

    for (int i = 1; i < pos; i++)
    {
        aux = aux->prox;
    }

    if (!antes)
        aux = aux->prox;

    return aux;
}

void Lista::SetItem(std::string item, int pos)
{
    Celula *aux = Posicionar(pos);
    aux->valor = item;
}

std::string Lista::GetItem(int pos)
{
    Celula *aux = Posicionar(pos);
    return aux->valor;
}

void Lista::InserirInicio(std::string item)
{
    Celula *novoItem = new Celula();

    novoItem->valor = item;
    novoItem->prox = this->inicio->prox;
    this->inicio->prox = novoItem;

    if (novoItem->prox == NULL)
        this->fim = novoItem;

    this->tamanho++;
}

void Lista::InserirFim(std::string item)
{
    Celula *novoItem = new Celula();
    novoItem->valor = item;
    this->fim->prox = novoItem;
    this->fim = novoItem;
    this->tamanho++;
}

void Lista::InserirPosicao(std::string item, int pos)
{
    Celula *novoItem = new Celula(), *aux = Posicionar(pos, true);

    novoItem->valor = item;
    novoItem->prox = aux->prox;
    aux->prox = novoItem;

    if (novoItem->prox == NULL)
        this->fim = novoItem;

    this->tamanho++;
}

std::string Lista::RemoverInicio()
{
    if (this->tamanho == 0)
        throw "Lista vazia.";

    std::string item;
    Celula *aux = this->inicio->prox;

    this->inicio->prox = aux->prox;

    if (this->inicio->prox == NULL)
        this->fim = this->inicio;

    item = aux->valor;
    delete aux;
    this->tamanho--;

    return item;
}

std::string Lista::RemoverFim()
{
    if (this->tamanho == 0)
        throw "Lista vazia";

    std::string valor;
    Celula *aux = Posicionar(this->tamanho, true);

    aux->prox = NULL;
    valor = this->fim->valor;
    delete fim;
    this->fim = aux;

    this->tamanho--;

    return valor;
}

std::string Lista::RemoverPosicao(int pos)
{
    if (this->tamanho == 0)
        throw "Lista vazia.";

    std::string valor;
    Celula *posicao = Posicionar(pos), *aux;

    aux = posicao->prox;
    posicao->prox = aux->prox;

    valor = aux->valor;
    delete aux;

    if (posicao->prox == NULL)
        this->fim = posicao;

    this->tamanho--;

    return valor;
}

void Lista::Imprimir()
{
    Celula *aux = this->inicio->prox;

    while (aux != NULL)
    {
        std::cout << aux->valor << std::endl;
        aux = aux->prox;
    }
}
