#include "aviao.h"

using namespace std;

/*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
*/
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
    void Aviao::imprimiDados() { cout << "Modelo: " << this->modelo << "\n"
                                      << "Marca: " << this->marca << "\n"
                                      << "Servo Profundor: " << this->servoProfundor << "\n"
                                      << "Servo Leme: " << this->servoLeme << "\n"
                                      << "Servo Aileron Esquerdo: " << this->servoAileronEs << "\n"
                                      << "Servo Aileron Direito: " << this->servoAileronDi << "\n"
                                      << "Servo Acelerador: " << this->servoAcelerador << "\n"; }

} // namespace SimuladorDeVooSimples
