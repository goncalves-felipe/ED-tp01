#include <iostream>
#include <string>
#include <fstream>
#include "../include/Lista.h"

std::string obterStringAntesDoEspaco(std::string *valor)
{
    std::string string = (*valor).substr(0, (*valor).find(" "));
    (*valor).erase(0, string.length() + 1);
    return string;
}

void tratarComando(std::string valorLido, Lista **servidores, Lista buffer, int qtdServidores)
{
    std::string comando = obterStringAntesDoEspaco(&valorLido);

    if (comando == "INFO")
    {
        std::string servidor = obterStringAntesDoEspaco(&valorLido);
        std::string dados = valorLido;
        dados = dados.erase(0, 1).erase(dados.length() - 1, 1);
        servidores[std::stoi(servidor)]->InserirFim(dados);
    }
    // else if (comando == "WARN")
    // {
    //     std::string servidor = obterStringAntesDoEspaco(&valorLido);
    //     std::string posicao = obterStringAntesDoEspaco(&valorLido);

    //     int nroServidor = std::stoi(servidor);

    //     std::string valorRemovido = servidores[nroServidor].RemoverPosicao(std::stoi(posicao));
    //     servidores[nroServidor].InserirFim(valorRemovido);
    // }
    // else if (comando == "TRAN")
    // {
    //     std::cout << "entrou";
    //     std::string servidor1 = obterStringAntesDoEspaco(&valorLido);
    //     std::string servidor2 = obterStringAntesDoEspaco(&valorLido);

    //     int nroServidor1 = std::stoi(servidor1);

    //     while (servidores[nroServidor1].GetTamanho() > 0)
    //     {
    //         std::string valorDesenfileirado = servidores[nroServidor1].RemoverInicio();
    //         servidores[std::stoi(servidor2)].InserirFim(valorDesenfileirado);
    //     }

    //     servidores[nroServidor1].Limpar();
    // }
    // else if (comando == "ERRO")
    // {
    //     std::string servidor = obterStringAntesDoEspaco(&valorLido);
    //     std::cout << "ERRO " << servidor << std::endl;
    //     int nroServidor = std::stoi(servidor);
    //     while (servidores[nroServidor].GetTamanho() > 0)
    //     {
    //         std::cout << servidores[nroServidor].RemoverInicio() << std::endl;
    //     }
    //     servidores[nroServidor].Limpar();
    // }
    // else if (comando == "SEND")
    // {
    //     for (int i = 0; i < qtdServidores; i++)
    //     {
    //         std::string valorRemovido = servidores[i].RemoverInicio();
    //         buffer.InserirInicio(valorRemovido);
    //     }
    // }
    // else if (comando == "FLUSH")
    // {
    //     buffer.Imprimir();

    //     for (int i = 0; i < qtdServidores; i++)
    //     {
    //         servidores[i].Imprimir();
    //     }
    // }
}

int main(int argc, char *argv[])
{
    std::string nomeArquivo;
    std::ifstream arquivo;
    int qtdServidores = 0;
    std::string valorLido;
    Lista buffer = Lista();

    std::cin >> nomeArquivo;
    arquivo.open(nomeArquivo);

    if (!arquivo.is_open())
        return 1;

    std::getline(arquivo, valorLido);

    qtdServidores = std::stoi(valorLido);

    Lista *servidores[qtdServidores];

    for (int i = 0; i < qtdServidores; i++)
    {
        servidores[i] = new Lista();
    }

    while (!arquivo.eof())
    {
        std::getline(arquivo, valorLido);
        tratarComando(valorLido, servidores, buffer, qtdServidores);
    }

    return 0;
}
