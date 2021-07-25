#include "../include/Celula.h"
#include <iostream>
#include <string>

Celula::Celula()
{
    this->valor = "teste";
    this->prox = NULL;
}

Celula::~Celula() {}

void Celula::SetValor(std::string valor)
{
    this->valor = valor;
}
