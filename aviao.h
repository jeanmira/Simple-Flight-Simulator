#ifndef AVIAO_H
#define AVIAO_H

#include <string>
#include <iostream>
#include <vector>
#include "dados.h"

using namespace std;

/*
    Classe responsável pelas especificações do avião

    modelo          =>  Recente a marca ou código do avião

    dadosDoAviao    =>  Recente a todos os dados do avião como 
                        giroscópio, altímetro e velocidade

    servo           =>  Todo servo motor tem uma abertura em graus 
                        que possibilita o comando de toda aeronave
*/

namespace SimuladorDeVooSimples
{
    class Aviao
    {
    private:
        string modelo;               // Modelo do avião
        string marca;                // Marca do avião
        vector<Dados<float>> dadosDoModelo; // Vetor de dados para cada avião
        float servoProfundor;        // Servo motor com abertura de 0 - 180° para o profundor
        float servoLeme;             // Servo motor com abertura de 0 - 180° para o Leme
        float servoAileronEs;        // Servo motor com abertura de 0 - 180° para aileron esquerdo
        float servoAileronDi;        // Servo motor com abertura de 0 - 180° para aileron direito
        float servoAcelerador;       // Servo motor com abertura de 0 - 180° para acelerador

    public:
        //Metodos para mudar as variaveis
        void setModelo(string);
        void setMarca(string);
        void setServoProfundor(float);
        void setServoLeme(float);
        void setServoAileronEs(float);
        void setServoAileronDi(float);
        void setServoAcelerador(float);
        void insereDados(Dados<float> temp);

        //Metodos para mudar as variaveis dos Dados
        void setDadosAltimetro(int, float);
        void setDadosPitot(int, float);
        void setDadosPitch(int, float);
        void setDadosRoll(int, float);
        void setDadosYaw(int, float);

        //Metodos para saber os valores das variaveis dos Dados
        float getDadosAltimetro(int);
        float getDadosPitot(int);
        float getDadosPitch(int);
        float getDadosRoll(int);
        float getDadosYaw(int);

        //Metodos para saber os valores das variaveis
        string getModelo();
        string getMarca();
        float getServoProfundor() const;
        float getServoLeme() const;
        float getServoAileronEs() const;
        float getServoAileronDi() const;
        float getServoAcelerador() const;

        // Contrutor padrão
        Aviao() : modelo{"DESCONHECIDO"}, marca{"DESCONHECIDA"}, servoProfundor{-1.0}, servoLeme{-1.0}, servoAileronEs{-1.0}, servoAileronDi{-1.0}, servoAcelerador{-1.0} {};

        // Contrutor que inicializa os parâmetros
        Aviao(string modelo, string marca, float servoProfundor, float servoLeme, float servoAileronEs, float servoAileronDi, float servoAcelerador);

        ~Aviao(); // Destrutor padrão

        void imprimirDadosAviao(); //Imprimi todos os dados do avião
        void imprimirDadosDados(); //Imprimi todos os dados dos dados
    };
} // namespace SimuladorDeVooSimples
#endif
