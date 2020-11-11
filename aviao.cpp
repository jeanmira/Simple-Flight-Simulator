#include "aviao.h"

using namespace std;

namespace SimuladorDeVooSimples
{
    //Metodos para mudar as variaveis
    void Aviao::setModelo(string modelo) { this->modelo = modelo; }
    void Aviao::setMarca(string marca) { this->marca = marca; }
    void Aviao::setServoProfundor(float servoProfundor) { this->servoProfundor = servoProfundor; }
    void Aviao::setServoLeme(float servoLeme) { this->servoLeme = servoLeme; }
    void Aviao::setServoAileronEs(float servoAileronEs) { this->servoAileronEs = servoAileronEs; }
    void Aviao::setServoAileronDi(float servoAileronDi) { this->servoAileronDi = servoAileronDi; }
    void Aviao::setServoAcelerador(float servoAcelerador) { this->servoAcelerador = servoAcelerador; }

    //Metodos para saber os valores das variaveis
    string Aviao::getModelo() { return this->modelo; }
    string Aviao::getMarca() { return this->marca; }
    float Aviao::getServoProfundor() const { return this->servoProfundor; }
    float Aviao::getServoLeme() const { return this->servoLeme; }
    float Aviao::getServoAileronEs() const { return this->servoAileronEs; }
    float Aviao::getServoAileronDi() const { return this->servoAileronDi; }
    float Aviao::getServoAcelerador() const { return this->servoAcelerador; }

    //Imprimi todos os dados do avião
    void Aviao::imprimiDados()
    {
        cout << "\n"
             << "Modelo: " << this->modelo << "\n"
             << "Marca: " << this->marca << "\n"
             << "Servo Profundor: " << this->servoProfundor << "\n"
             << "Servo Leme: " << this->servoLeme << "\n"
             << "Servo Aileron Esquerdo: " << this->servoAileronEs << "\n"
             << "Servo Aileron Direito: " << this->servoAileronDi << "\n"
             << "Servo Acelerador: " << this->servoAcelerador << "\n"
             << "\n";
    }

    // Contrutor que inicializa os parâmetros
    Aviao::Aviao(string modelo, string marca, float servoProfundor, float servoLeme, float servoAileronEs, float servoAileronDi, float servoAcelerador)
    {
        setModelo(modelo);
        setMarca(marca);
        setServoProfundor(servoProfundor);
        setServoLeme(servoLeme);
        setServoAileronEs(servoAileronEs);
        setServoAileronDi(servoAileronDi);
        setServoAcelerador(servoAcelerador);
    }
} // namespace SimuladorDeVooSimples
