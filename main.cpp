#include <iostream>
#include <fstream>
#include <sstream>
#include "aviao.h"
#include "dados.h"

namespace svs = SimuladorDeVooSimples;

int main()
{
    // Cria e chama o contrutor
    /*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
    */
    svs::Aviao novo("Cessna 172 Skyhawk", "Cessna Aircraft Company", -1.0, -1.0, -1.0, -1.0, -1.0);
    novo.imprimirDadosAviao();

    ifstream arquivo; // Abre o arquivo de dados de decolagem que esta na pasta Gerador-de-dados

    arquivo.open("Gerador-de-dados/dados-decolagem.txt");

    if (!arquivo.is_open())
    {
        std::cout << "Arquivo nao foi aberto!" << std::endl;
        return 0;
    }
    else
    {
        vector<float> numFloat;
        string aux;                                                                                // Auxiliar para pegar uma string por vez
        string dadosTemporario((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>()); // Coloca todo arquivo em uma string
        istringstream fluxo{dadosTemporario};                                                      // Classe de fluxo de entrada para operar uma strings
        while (fluxo >> aux)
            numFloat.push_back(stof(aux)); // Pega os valores da string separa converte para float e coloca no vetor float temporario

        for (int i = 0; i <= (int)numFloat.size(); i++)
        {
            if (i != 0 && (i % 5) == 0)
            {
                svs::Dados<float> temporarios(numFloat[i - 5], numFloat[i - 4], numFloat[i - 3], numFloat[i - 2], numFloat[i - 1]);
                novo.insereDados(temporarios);
            }
        }
        novo.imprimirDadosDados();

        arquivo.close(); // Fecha o arquivo
    }

    return 0;
}
