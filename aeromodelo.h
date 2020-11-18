#ifndef AEROMODELO_H
#define AEROMODELO_H

#include <iostream>
#include <string>
#include "aviao.h"

using namespace std;

namespace SimuladorDeVooSimples
{
    // Classe Aeromodelo herda classe Aviao
    class Aeromodelo : public Aviao
    {
    private:
        float preco;              // Valor do aeromodelo
        string cor;               // Cor predominante do aeromodelo
        string modeloTransmissor; // Modelo de transmisor do aeromodelo

    public:
        // Construtor padrão
        //Aeromodelo() : modelo{"DESCONHECIDO"}, marca{"DESCONHECIDA"}, cor{"DESCONHECIDA"}, modeloTransmissor{"DESCONHECIDA"}, servoProfundor{0.0}, servoLeme{0.0}, servoAileronEs{0.0}, servoAileronDi{0.0}, servoAcelerador{0.0}, preco{0.0} {};

        // Construtor que inicializa os parâmetros
        Aeromodelo(string, string, string, string, float = 0.0, float = 0.0, float = 0.0, float = 0.0, float = 0.0, float = 0.0);

        // Métodos para mudar as variaveis do aeromodelo
        void setPreco(float);
        void setCor(string);
        void setModeloTransmissor(string);

        // Métodos para saber os valores das variáveis do aeromodelo
        float getPreco();
        string getCor();
        string getModeloTransmissor();

        // Imprime todos os dados do aeromodelo
        void printAeromodelo(); 
    };
} // namespace SimuladorDeVooSimples

#endif