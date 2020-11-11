#include <iostream>
#include <fstream>
#include "aviao.h"
#include "dados.h"

namespace svs = SimuladorDeVooSimples;

int main()
{
    // Abre o arquivo de dados de decolagem que esta na pasta Gerador-de-dados
    ifstream arquivo;

    arquivo.open("Gerador-de-dados/dados-decolagem.txt");

    if (!arquivo.is_open())
    {
        std::cout << "Arquivo nao foi aberto!" << std::endl;
        return 0;
    }

    // Cria e chama o contrutor
    /*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
    */
    svs::Aviao novo("Cessna 172 Skyhawk", "Cessna Aircraft Company", -1.0, -1.0, -1.0, -1.0, -1.0);
    novo.imprimiDados();

    return 0;
}
