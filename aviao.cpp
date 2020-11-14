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

    // Métodos de incremento e decremento
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
    void Aviao::decrementaAcelerador(int i) { this->servoAcelerador -= i; }

    // Metodos da classe que estabiliza o avião na altura
    void Aviao::estabilizaAltura(int i, int max, int min)
    {
        int acessoUm = 0, acessoDois = 0;

        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            if (dadosDoModelo[j].getAltimetro() < ALTURAMAXIMA && dadosDoModelo[j].getAltimetro() >= ALTURAMINIMA)
            {
                if (dadosDoModelo[j].getAltimetro() > max)
                {
                    if (acessoUm < 1)
                    {
                        // Para não fichar um nivel o programa vê pela variação entre o primeiro e segundo valor
                        // assim para qualquer mudança de altura ele mesmo faz o ajsute
                        incrementaProfundor((dadosDoModelo[1].getAltimetro() - dadosDoModelo[0].getAltimetro()));
                        acessoUm++;
                    }
                    for (int k = j; k < (int)dadosDoModelo.size(); k++)
                    {
                        /* cout << "[" << getServoProfundor() << "]"
                             << "[" << k << "] " << getDadosAltimetro(k) << "\n"; */

                        if (dadosDoModelo[k].getAltimetro() > min)
                            dadosDoModelo[k].movimentaAltimetro(servoProfundor);

                        /* cout << "[" << getServoProfundor() << "]"
                             << "[" << k << "] " << getDadosAltimetro(k) << "\n";
                        cout << dadosDoModelo[k].getAltimetro() << "\n"; */
                    }
                    servoProfundor = 0;
                    acessoUm = 0;
                }
            }
        }
        for (int j = ((int)dadosDoModelo.size() - 1); j >= i; j--)
        {
            if (acessoDois < 1)
            {
                // Para não fichar um nivel o programa vê pela variação entre o primeiro e segundo valor
                // assim para qualquer mudança de altura ele mesmo faz o ajsute
                decrementaProfundor((dadosDoModelo[1].getAltimetro() - dadosDoModelo[0].getAltimetro()));
                acessoDois++;
            }
            if (dadosDoModelo[j].getAltimetro() < min)
            {
                for (int k = j; k >= i; k--)
                {
                    if (dadosDoModelo[k].getAltimetro() < max)
                        dadosDoModelo[k].movimentaAltimetro(servoProfundor);
                }
            }
            servoProfundor = 0;
            acessoDois = 0;
        }
    }

    // Metodos da classe que estabiliza o avião na velocidade
    void Aviao::estabilizaVelocidade(int i)
    {
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
            if (i == 254 || i == 1254)
                cout << "\n";
        }
        cout << "\n";
    }
} // namespace SimuladorDeVooSimples
