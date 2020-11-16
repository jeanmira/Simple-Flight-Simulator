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
    void Aviao::incrementaProfundor(float i) { this->servoProfundor += i; }
    void Aviao::incrementaLeme(float i) { this->servoLeme += i; }
    void Aviao::incrementaAcelerador(float i) { this->servoAcelerador += i; }

    // Métodos de incremento e decremento
    void Aviao::incrementaAileronVaiEs(float i)
    {
        this->servoAileronDi += i;
        this->servoAileronEs -= i;
    }
    void Aviao::incrementaAileronVaiDi(float i)
    {
        this->servoAileronDi -= i;
        this->servoAileronEs += i;
    }

    // Métodos de decremento
    void Aviao::decrementaProfundor(float i) { this->servoProfundor -= i; }
    void Aviao::decrementaLeme(float i) { this->servoLeme -= i; }
    void Aviao::decrementaAcelerador(float i) { this->servoAcelerador -= i; }

    // Metodos da classe que estabiliza o avião na altura
    void Aviao::estabilizaAltura(int i, float max, float min)
    {
        int acesso = 0;
        // Verifica a taxa de variação
        float nivel = (dadosDoModelo[i + 1].getAltimetro() - dadosDoModelo[i].getAltimetro());
        // Se a taxa der negatriva faz o modulo
        if (nivel < 0)
            nivel *= -1;
        //cout << nivel << "\n";
        // Percorre os dados para corrigir para o ideal
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Se o dados forem menores que o minimo entra e ajusta
            if (dadosDoModelo[j].getAltimetro() < min)
            {
                // Questão de acesso para ajustar o nivel do profundor
                if (acesso == 0)
                {
                    // Ajusta o nivel do profundor
                    decrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar a altura
                while (dadosDoModelo[j].getAltimetro() < min)
                    dadosDoModelo[j].movimentaAltimetro(servoProfundor);
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoProfundor = 0;
            // Se o dados forem maiores que o maximo entra e ajusta
            if (dadosDoModelo[j].getAltimetro() > max)
            {
                // Questão de acesso para ajustar o nivel do profundor
                if (acesso == 0)
                {
                    // Ajusta o nivel do profundor
                    incrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir a altura
                while (dadosDoModelo[j].getAltimetro() > max)
                    dadosDoModelo[j].movimentaAltimetro(servoProfundor);
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoProfundor = 0;
        }
    }

    // Metodos da classe que estabiliza o avião na velocidade
    void Aviao::estabilizaVelocidade(int i, float max, float min)
    {
        int acesso = 0;
        // Verifica a taxa de variação
        float nivel = (dadosDoModelo[i + 1].getPitot() - dadosDoModelo[i].getPitot());
        // Se a taxa der negatriva faz o modulo
        if (nivel < 0)
            nivel *= -1;
        //cout << nivel << "\n";
        // Percorre os dados para corrigir para o ideal
        //cout << nivel << " " << getServoAcelerador() << " " << dadosDoModelo[i + 1].getPitot() << " " << dadosDoModelo[i].getPitot() << "\n";
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Se o dados forem menores que o minimo entra e ajusta
            if (dadosDoModelo[j].getPitot() < min)
            {
                // Questão de acesso para ajustar o nivel do acelerador
                if (acesso == 0)
                {
                    // Ajusta o nivel do acelerador
                    decrementaAcelerador(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar a velocidade
                while (dadosDoModelo[j].getPitot() < min)
                {
                    //cout << "[" << j << "] " << dadosDoModelo[j].getPitot() << "\n";
                    dadosDoModelo[j].movimentaPitot(servoAcelerador);
                    //cout << "[" << j << "] " << dadosDoModelo[j].getPitot() << "\n";
                }
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoAcelerador = 0;
            // Se o dados forem maiores que o maximo entra e ajusta
            if (dadosDoModelo[j].getPitot() > max)
            {
                // Questão de acesso para ajustar o nivel do acelerador
                if (acesso == 0)
                {
                    // Ajusta o nivel do acelerador
                    incrementaAcelerador(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir a velocidade
                while (dadosDoModelo[j].getPitot() > max)
                {
                    //cout << "[" << j << "] " << dadosDoModelo[j].getPitot() << "\n";
                    dadosDoModelo[j].movimentaPitot(servoAcelerador);
                    //cout << "[" << j << "] " << dadosDoModelo[j].getPitot() << "\n";
                }
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoAcelerador = 0;
        }
    }

    // Metodos da classe que estabiliza o avião nos seus momentos
    void Aviao::estabilizaMomentos(int i, float max, float min)
    {
        //---------------------------------------------------------------------------------------------------------------------------
        // ESTABILIZA O PITCH
        //---------------------------------------------------------------------------------------------------------------------------
        int acesso = 0;
        // Verifica a taxa de variação do momento
        float nivel = (dadosDoModelo[i + 1].getGiroscopio_pitch() - dadosDoModelo[i].getGiroscopio_pitch());
        // Se a taxa der negatriva faz o modulo
        if (nivel < 0)
            nivel *= -1;
        //cout << nivel << "\n";
        // Percorre os dados para corrigir para o momento do pitch ideal que e 0
        //cout << nivel << " " << getGiroscopio_pitch()) << " " << dadosDoModelo[i + 1].getGiroscopio_pitch() << " " << dadosDoModelo[i].getPitot() << "\n";
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Se o dados forem menores que o minimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_pitch() < min)
            {
                // Questão de acesso para ajustar o nivel do momento pitch que e controlado pelo profundor
                if (acesso == 0)
                {
                    // Ajusta o nivel do profundor
                    decrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento pitch que e controlado pelo profundor
                while (dadosDoModelo[j].getGiroscopio_pitch() < min && dadosDoModelo[j].getGiroscopio_pitch() <= 0)
                {
                    /* cout << "1 - I[" << j << "] - N[" << nivel << "] - P[" << getServoProfundor() << "] - A[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_pitch() << "] "
                         << "\n"; */
                    dadosDoModelo[j].movimentaPitch(servoProfundor);
                    // Se aumentar demais ele faz um ultimo ajuste fino
                    /* cout << "Entrou 1.1"
                         << "\n"; */
                    if (dadosDoModelo[j].getGiroscopio_pitch() != nivel && dadosDoModelo[j].getGiroscopio_pitch() < nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                    {
                        dadosDoModelo[j].movimentaPitch(+(dadosDoModelo[j].getGiroscopio_pitch()));
                        /* cout << "if------1"
                             << "\n"; */
                    }
                    /* cout << "2 - I[" << j << "] - N[" << nivel << "] - P[" << getServoProfundor() << "] - A[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_pitch() << "] "
                         << "\n"; */
                }
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoProfundor = 0;
            // Se o dados forem maiores que o maximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_pitch() > max)
            {
                // Questão de acesso para ajustar o nivel do momento pitch que e controlado pelo profundor
                if (acesso == 0)
                {
                    // Ajusta o nivel do profundor
                    incrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento pitch que e controlado pelo profundor
                while (dadosDoModelo[j].getGiroscopio_pitch() > max && dadosDoModelo[j].getGiroscopio_pitch() >= 0)
                {
                    /* cout << "1 - i[" << j << "] - Nivel[" << nivel << "] - Profundor[" << getServoProfundor() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_pitch() << "] "
                         << "\n"; */
                    dadosDoModelo[j].movimentaPitch(servoProfundor);
                    // Se diminuir demais ele faz um ultimo ajuste fino
                    /* cout << "Entrou 1.2"
                         << "\n"; */
                    if (dadosDoModelo[j].getGiroscopio_pitch() != nivel && dadosDoModelo[j].getGiroscopio_pitch() < nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                        dadosDoModelo[j].movimentaPitch(-(dadosDoModelo[j].getGiroscopio_pitch()));
                    /* cout << "2 - i[" << j << "] - Nivel[" << nivel << "] - Profundor[" << getServoProfundor() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_pitch() << "] "
                         << "\n"; */
                }
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoProfundor = 0;
        }
        //---------------------------------------------------------------------------------------------------------------------------

        //---------------------------------------------------------------------------------------------------------------------------
        // ESTABILIZA O ROLL
        //---------------------------------------------------------------------------------------------------------------------------
        acesso = 0;
        // Verifica a taxa de variação do momento
        nivel = (dadosDoModelo[i + 1].getGiroscopio_roll() - dadosDoModelo[i].getGiroscopio_roll()) / 2;
        // Se a taxa der negatriva faz o modulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o momento do roll ideal que e 0
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Se o dados forem menores que o minimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_roll() < min)
            {
                // Questão de acesso para ajustar o nivel do momento roll que e controlado pelos ailerons
                if (acesso == 0)
                {
                    // Ajusta o nivel dos ailerons
                    incrementaAileronVaiDi(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento roll que e controlado pelos ailerons
                while (dadosDoModelo[j].getGiroscopio_roll() < min && dadosDoModelo[j].getGiroscopio_roll() <= 0)
                {
                    dadosDoModelo[j].movimentaRoll(servoAileronEs, servoAileronDi);
                    /* cout << "Entrou 2.1"
                         << "\n"; */
                    // Se aumentar demais ele faz um ultimo ajuste
                    if (dadosDoModelo[j].getGiroscopio_roll() != nivel && dadosDoModelo[j].getGiroscopio_roll() > nivel)
                        dadosDoModelo[j].movimentaRoll(+(dadosDoModelo[j].getGiroscopio_roll() / 2), -(dadosDoModelo[j].getGiroscopio_roll() / 2));
                }
            }
            // Zera o acesso e os ailerons para poder ter outro movimento
            acesso = 0;
            servoAileronEs = 0;
            servoAileronDi = 0;
            // Se o dados forem maiores que o maximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_roll() > max)
            {
                // Questão de acesso para ajustar o nivel do momento roll que e controlado pelos ailerons
                if (acesso == 0)
                {
                    // Ajusta o nivel dos ailerons
                    incrementaAileronVaiEs(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento roll que e controlado pelos ailerons
                while (dadosDoModelo[j].getGiroscopio_roll() > max && dadosDoModelo[j].getGiroscopio_roll() >= 0)
                {
                    dadosDoModelo[j].movimentaRoll(servoAileronEs, servoAileronDi);
                    /* cout << "Entrou 2.2"
                         << "\n"; */
                    // Se diminuir demais ele faz um ultimo ajuste
                    if (dadosDoModelo[j].getGiroscopio_roll() != nivel && dadosDoModelo[j].getGiroscopio_roll() < nivel)
                        dadosDoModelo[j].movimentaRoll(-(dadosDoModelo[j].getGiroscopio_roll() / 2), +(dadosDoModelo[j].getGiroscopio_roll() / 2));
                }
            }
            // Zera o acesso e os ailerons para poder ter outro movimento
            acesso = 0;
            servoAileronEs = 0;
            servoAileronDi = 0;
        }
        //---------------------------------------------------------------------------------------------------------------------------

        //---------------------------------------------------------------------------------------------------------------------------
        // ESTABILIZA O YAW
        //---------------------------------------------------------------------------------------------------------------------------
        acesso = 0;
        // Verifica a taxa de variação do momento
        nivel = (dadosDoModelo[i + 1].getGiroscopio_yaw() - dadosDoModelo[i].getGiroscopio_yaw());
        // Se a taxa der negatriva faz o modulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o momento do yaw ideal que e 0
        for (int j = i; j < (int)dadosDoModelo.size(); j++)
        {
            // Se o dados forem menores que o minimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_yaw() < min)
            {
                // Questão de acesso para ajustar o nivel do momento yaw que e controlado pelo leme
                if (acesso == 0)
                {
                    // Ajusta o nivel do leme
                    decrementaLeme(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento yaw que e controlado pelo leme
                while (dadosDoModelo[j].getGiroscopio_yaw() < min && dadosDoModelo[j].getGiroscopio_yaw() <= 0)
                {
                    cout << "1 - i[" << j << "] - Nivel[" << nivel << "] - Leme[" << getServoLeme() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_yaw() << "] "
                         << "\n";
                    dadosDoModelo[j].movimentaYaw(servoLeme);
                    cout << "2 - i[" << j << "] - Nivel[" << nivel << "] - Leme[" << getServoLeme() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_yaw() << "] "
                         << "\n";
                    cout << "Entrou 3.1"
                         << "\n";
                    // Se aumentar demais ele faz um ultimo ajuste
                    /* if (dadosDoModelo[j].getGiroscopio_yaw() != nivel && dadosDoModelo[j].getGiroscopio_yaw() > nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                        dadosDoModelo[j].movimentaYaw(-(dadosDoModelo[j].getGiroscopio_yaw())); */
                }
            }
            // Zera o acesso e o leme para poder ter outro movimento
            acesso = 0;
            servoLeme = 0;
            // Se o dados forem maiores que o maximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_yaw() > max)
            {
                // Questão de acesso para ajustar o nivel do momento yaw que e controlado pelo leme
                if (acesso == 0)
                {
                    // Ajusta o nivel do leme
                    incrementaLeme(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento yaw que e controlado pelo leme
                while (dadosDoModelo[j].getGiroscopio_yaw() > max && dadosDoModelo[j].getGiroscopio_yaw() >= 0)
                {
                    cout << "1 - i[" << j << "] - Nivel[" << nivel << "] - Leme[" << getServoLeme() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_yaw() << "] "
                         << "\n";
                    dadosDoModelo[j].movimentaYaw(servoLeme);
                    // Se diminuir demais ele faz um ultimo ajuste
                    cout << "2 - i[" << j << "] - Nivel[" << nivel << "] - Leme[" << getServoLeme() << "] - Acesso[" << acesso << "] - Valor[" << dadosDoModelo[j].getGiroscopio_yaw() << "] "
                         << "\n";
                    cout << "Entrou 3.2"
                         << "\n";
                    /* if (dadosDoModelo[j].getGiroscopio_roll() != nivel && dadosDoModelo[j].getGiroscopio_roll() < nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                        dadosDoModelo[j].movimentaYaw(+(dadosDoModelo[j].getGiroscopio_yaw())); */
                }
            }
            // Zera o acesso e o leme para poder ter outro movimento
            acesso = 0;
            servoLeme = 0;
        }
        //---------------------------------------------------------------------------------------------------------------------------
    }

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
