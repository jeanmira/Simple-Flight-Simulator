#include <iostream>
#include <fstream>
#include "aviao.h"
#include "dados.h"

namespace svs = SimuladorDeVooSimples;

int main()
{
    ifstream arquivo;

    arquivo.open("dados-decolagem.txt");

    if (!arquivo.is_open())
    {
        std::cout << "Arquivo nao foi aberto" << std::endl;
        return 0;
    }

    svs::Aviao pequeno;
    pequeno.imprimiDados();

    return 0;
}
