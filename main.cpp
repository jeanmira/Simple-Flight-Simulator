#include <iostream>
#include <fstream>
#include <sstream>
#include "aviao.h"
#include "dados.h"
#include "aeromodelo.h"

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
            numFloat.push_back(stof(aux)); // Pega os valores da string separa convertido para float e coloca no vetor float temporário

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
    // Cria e chama o construtor
    /* 
   O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares,
   monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
   */
    svs::Aviao aeronave("Cessna 172 Skyhawk", "Cessna Aircraft Company", 0.0, 0.0, 0.0, 0.0, 0.0); // Cria o avião com o construtor padrão
    aeronave.imprimirDadosAviao();                                                                 // Imprime as especificações do Avião

    svs::Aeromodelo miniAeronave("Albatroz", "Incoaer", "Azul", "Transmissor 6ch", 0.0, 0.0, 0.0, 0.0, 0.0, 1400.55); // Cria um Aeromodelo com o construtor padrão
    miniAeronave.printAeromodelo();                                                                                   // Imprime as especificações do Aeromodelo

    // Verifica se as duas aeronavem são iguais, utilizando do recurso de sobrecarga de operadores
    if (aeronave == miniAeronave)
        cout << "A aeronave [1] ("
             << aeronave.getModelo()
             << ") e a aeronave [2] (" << miniAeronave.getModelo()
             << ") tem as mesmas especificações, portanto os modelos são iguais!"
             << "\n"
             << "\n";
    else
        cout << "A aeronave [1] ("
             << aeronave.getModelo()
             << ") e a aeronave [2] (" << miniAeronave.getModelo()
             << ") não tem as mesmas especificações, portanto os modelos são diferentes!"
             << "\n"
             << "\n";

    // Abre os dados de decolagem e adiciona no novo avião
    ifstream arquivoDecolagem;
    arquivoDecolagem.open("Gerador-de-dados/dados-decolagem.txt");
    leArquivos(arquivoDecolagem, aeronave);

    aeronave.estabilizaAltura(0, 1120, -1); // Estabiliza a Altura (onde começa a análise, altura máxima, altura mínima)
    aeronave.estabilizaMomentos(0, 0, 0);   // Estabiliza os Momentos (onde começa a analise, máximo de momento permitido, mínimo de momento permitido)

    //Abre os dados de cruzeiro e adiciona no novo avião
    ifstream arquivoCruzeiro;
    arquivoCruzeiro.open("Gerador-de-dados/dados-cruzeiro.txt");
    leArquivos(arquivoCruzeiro, aeronave);

    aeronave.estabilizaAltura(255, 1000, 900);    // Estabiliza a Altura (onde começa a análise, altura padrão, altura mínima )
    aeronave.estabilizaVelocidade(255, 222, 216); // Estabiliza a Velocidade (onde começa a analise, velocidade maxima, velocidade mínima )
    aeronave.estabilizaMomentos(255, 0, 0);       // Estabiliza os Momentos (onde começa a analise, máximo de momento permitido, mínimo de momento permitido)

    //Abre os dados de cruzeiro e adiciona no novo avião
    ifstream arquivoPouso;
    arquivoPouso.open("Gerador-de-dados/dados-pouso.txt");
    leArquivos(arquivoPouso, aeronave);

    aeronave.estabilizaAltura(1255, 800, -1);    // Estabiliza a Altura (onde começa a análise, altura padrão, altura mínima)
    aeronave.estabilizaVelocidade(1255, 200, 0); // Estabiliza a Velocidade (onde começa a analise, velocidade máxima, velocidade mínima)
    aeronave.estabilizaMomentos(1255, 0, 0);     // Estabiliza os Momentos (onde começa a analise, máximo de momento permitido, mínimo de momento permitido)
    aeronave.imprimirDadosDados();               // Imprime os dados do avião

    return 0;
}
