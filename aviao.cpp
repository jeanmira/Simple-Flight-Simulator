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
    void Aviao::insereDados(Dados<float> temp) { dadosDoModelo.push_back(temp); }

    //Metodos para mudar as variaveis dos Dados
    void Aviao::setDadosAltimetro(int i, float altimetro) { dadosDoModelo[i].setAltimetro(altimetro); }
    void Aviao::setDadosPitot(int i, float pitot) { dadosDoModelo[i].setPitot(pitot); }
    void Aviao::setDadosPitch(int i, float pitch) { dadosDoModelo[i].setPitch(pitch); }
    void Aviao::setDadosRoll(int i, float roll) { dadosDoModelo[i].setRoll(roll); }
    void Aviao::setDadosYaw(int i, float yaw) { dadosDoModelo[i].setYaw(yaw); }

    //Metodos para saber os valores das variaveis
    string Aviao::getModelo() { return this->modelo; }
    string Aviao::getMarca() { return this->marca; }
    float Aviao::getServoProfundor() const { return this->servoProfundor; }
    float Aviao::getServoLeme() const { return this->servoLeme; }
    float Aviao::getServoAileronEs() const { return this->servoAileronEs; }
    float Aviao::getServoAileronDi() const { return this->servoAileronDi; }
    float Aviao::getServoAcelerador() const { return this->servoAcelerador; }

    //Metodos para saber os valores das variaveis dos Dados
    float Aviao::getDadosAltimetro(int i) { return this->dadosDoModelo[i].getAltimetro(); }
    float Aviao::getDadosPitot(int i) { return this->dadosDoModelo[i].getPitot(); }
    float Aviao::getDadosPitch(int i) { return this->dadosDoModelo[i].getGiroscopio_pitch(); }
    float Aviao::getDadosRoll(int i) { return this->dadosDoModelo[i].getGiroscopio_roll(); }
    float Aviao::getDadosYaw(int i) { return this->dadosDoModelo[i].getGiroscopio_yaw(); }

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

    // Destrutor padrão
    Aviao::~Aviao() {}

    // Métodos de incremento
    void Aviao::incrementaProfundor(int i) { this->servoProfundor += i; }
    void Aviao::incrementaLeme(int i) { this->servoLeme += i; }
    void Aviao::incrementaAcelerador(int i) { this->servoAcelerador += i; }
    void Aviao::incrementaAileronVaiEs(int i)
    {
        this->servoAileronDi += i;
        this->servoAileronEs -= i;
    }
    void Aviao::incrementaAileronVaiDi(int i)
    {
        this->servoAileronDi -= i;
        this->servoAileronEs += i;
    }

    // Métodos de decremento
    void Aviao::decrementaProfundor(int i) { this->servoProfundor -= i; }
    void Aviao::decrementaLeme(int i) { this->servoLeme -= i; }

    // Metodos da classe que estabiliza o avião na altura
    void Aviao::estabilizaAltura(int i, int max, int min)
    {
        incrementaProfundor(NIVEL); // Nivel de decremento do profundor

        // Percorre todos os dados
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Verifica se a altura esta entre o maximo e minimo esperado
            if (getDadosAltimetro(j) < ALTURAMAXIMA && getDadosAltimetro(j) > 0)
            {
                // Verifica se a altura é maior do que a ideal(max)
                if (getDadosAltimetro(j) > max)
                {
                    // Se a altura for maior ele vai reduzir
                    for (int k = j; k < (int)dadosDoModelo.size(); k++)
                    {
                        // cout << k << " " << getDadosAltimetro(k) << "\n";
                        dadosDoModelo[k].decrementaAltimetro(servoProfundor);
                        // cout << k << " " << getDadosAltimetro(k) << "\n";
                    }
                }
                // Verifica se a altura é menor do que a ideal(min)
                if (getDadosAltimetro(j) < min && min > 0)
                {
                    // Se a altura for menor ele vai aumentar
                    for (int k = j; k < (int)dadosDoModelo.size(); k++)
                    {
                        // cout << k << " " << getDadosAltimetro(k) << "\n";
                        dadosDoModelo[k].incrementaAltimetro(servoProfundor);
                        // cout << k << " " << getDadosAltimetro(k) << "\n";
                    }
                }
            }
        }
    }
    // Metodos da classe que estabiliza o avião na velocidade
    void Aviao::estabilizaVelocidade(int i)
    {
        incrementaAcelerador(NIVEL);
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            if (getDadosPitot(j) < 302 && getDadosPitot(j) > 0)
            {
                if (getDadosPitot(j) > 222)
                {
                    for (int k = j; k < (int)dadosDoModelo.size(); k++)
                    {
                        // cout << k << " " << getDadosPitot(k) << "\n";
                        dadosDoModelo[k].decrementaPitot(servoProfundor);
                        // cout << k << " " << getDadosPitot(k) << "\n";
                    }
                }
            }
        }
    }
    // void Aviao::estabilizaMomentos(int i) {}

    //Imprimi todos os dados do avião
    void Aviao::imprimirDadosAviao()
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

    //Imprimi todos os dados dos dados
    void Aviao::imprimirDadosDados()
    {
        for (int i = 0; i < (int)dadosDoModelo.size(); i++)
        {
            cout << "[" << i << "] " << dadosDoModelo[i].getAltimetro() << " "
                 << dadosDoModelo[i].getPitot() << " "
                 << dadosDoModelo[i].getGiroscopio_pitch() << " "
                 << dadosDoModelo[i].getGiroscopio_roll() << " "
                 << dadosDoModelo[i].getGiroscopio_yaw() << "\n";
        }
        cout << "\n";
    }
} // namespace SimuladorDeVooSimples
