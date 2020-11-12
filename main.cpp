#include <iostream>
#include <fstream>
#include <sstream>
#include "aviao.h"
#include "dados.h"

namespace svs = SimuladorDeVooSimples;

void leArquivos(ifstream &arquivo, svs::Aviao &novo)
{
    if (!arquivo.is_open())
    {
        std::cout << "Arquivo nao foi aberto!" << std::endl;
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
    }
    arquivo.close(); // Fecha o arquivo
}

int main()
{
    // Cria e chama o contrutor
    /*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
    */
    svs::Aviao novo("Cessna 172 Skyhawk", "Cessna Aircraft Company", 0.0, 0.0, 0.0, 0.0, 0.0); // Cria o avião com o construtor padrão
    novo.imprimirDadosAviao();

    //Abre os dados de decolagem e adiciona no novo avião
    ifstream arquivoDecolagem;
    arquivoDecolagem.open("Gerador-de-dados/dados-decolagem.txt");
    leArquivos(arquivoDecolagem, novo);

    novo.estabilizaAltura(0, 1170, -1);  // Estabiliza a Altura (onde começa a analise, altura maxima, altura minima -1 não precisa)
    novo.imprimirDadosDados(); // Imprimi os dados do avião

    //Abre os dados de cruzeiro e adiciona no novo avião
    ifstream arquivoCruzeiro;
    arquivoCruzeiro.open("Gerador-de-dados/dados-cruzeiro.txt");
    leArquivos(arquivoCruzeiro, novo);

    novo.estabilizaAltura(0, 1000, 995);  // Estabiliza a Altura (onde começa a analise, altura padrão)
    novo.imprimirDadosDados(); // Imprimi os dados do avião

    //Abre os dados de cruzeiro e adiciona no novo avião
    ifstream arquivoPouso;
    arquivoPouso.open("Gerador-de-dados/dados-pouso.txt");
    leArquivos(arquivoPouso, novo);

    novo.imprimirDadosDados(); // Imprimi os dados do avião

    return 0;
}
