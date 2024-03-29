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
  servos           =>  Todo servo motor tem uma abertura em graus
                      que possibilita o comando de toda aeronave
*/

namespace SimuladorDeVooSimples
{
    class Aviao
    {
    private:
        string modelo;                      // Modelo do avião
        string marca;                       // Marca do avião
        vector<Dados<float>> dadosDoModelo; // Vetor de dados para cada avião
        float servoProfundor;               // Servo motor com abertura de 0 - 180° para o profundor
        float servoLeme;                    // Servo motor com abertura de 0 - 180° para o Leme
        float servoAileronEs;               // Servo motor com abertura de 0 - 180° para aileron esquerdo
        float servoAileronDi;               // Servo motor com abertura de 0 - 180° para aileron direito
        float servoAcelerador;              // Servo motor com abertura de 0 - 180° para acelerador

    public:
        // Sobrecarga de operador ==
        bool operator==(const Aviao &) const;

        // Métodos para mudar as variaveis
        void setModelo(string);
        void setMarca(string);
        void setServoProfundor(float);
        void setServoLeme(float);
        void setServoAileronEs(float);
        void setServoAileronDi(float);
        void setServoAcelerador(float);
        void insereDados(Dados<float> temp);

        // Métodos para mudar as variáveis dos Dados
        void setDadosAltimetro(long unsigned int, float);
        void setDadosPitot(long unsigned int, float);
        void setDadosPitch(long unsigned int, float);
        void setDadosRoll(long unsigned int, float);
        void setDadosYaw(long unsigned int, float);

        // Métodos para saber os valores das variáveis dos Dados
        float getDadosAltimetro(long unsigned int);
        float getDadosPitot(long unsigned int);
        float getDadosPitch(long unsigned int);
        float getDadosRoll(long unsigned int);
        float getDadosYaw(long unsigned int);

        // Métodos para saber os valores das variáveis
        string getModelo();
        string getMarca();
        float getServoProfundor() const;
        float getServoLeme() const;
        float getServoAileronEs() const;
        float getServoAileronDi() const;
        float getServoAcelerador() const;

        // Construtor padrão
        Aviao() : modelo{"DESCONHECIDO"}, marca{"DESCONHECIDA"}, servoProfundor{0.0}, servoLeme{0.0}, servoAileronEs{0.0}, servoAileronDi{0.0}, servoAcelerador{0.0} {};

        // Construtor que inicializa os parâmetros
        Aviao(string modelo, string marca, float servoProfundor, float servoLeme, float servoAileronEs, float servoAileronDi, float servoAcelerador);

        ~Aviao(); // Destrutor padrão

        // Métodos de incremento
        void incrementaProfundor(float i);
        void incrementaLeme(float i);
        void incrementaAcelerador(float i);

        // Métodos de incremento e decremento
        void incrementaAileronVaiEs(float i);
        void incrementaAileronVaiDi(float i);

        // Métodos de decremento
        void decrementaProfundor(float i);
        void decrementaLeme(float i);
        void decrementaAcelerador(float i);

        // Métodos da classe
        void estabilizaAltura(long unsigned int i, float max, float min);
        void estabilizaVelocidade(long unsigned int i, float max, float min);
        void estabilizaMomentos(long unsigned int i, float max, float min);

        virtual void imprimirEspecificacoes() const; /// Imprime todos os dados do avião aplicando os conceitos de polimorfismo
        void imprimirDadosDados();                   // Imprime todos os dados dos dados

        void setServos(); // Verifica se os servos estão na posição inicial (0.0) onde a superfície de comando está sem inclinação
    };

} // namespace SimuladorDeVooSimples
#endif
