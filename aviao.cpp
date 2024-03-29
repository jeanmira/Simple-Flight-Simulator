#include "aviao.h"

namespace SimuladorDeVooSimples
{
    // Sobrecarga de operador ==
    bool Aviao::operator==(const Aviao &aviaoDeComparacao) const
    {
        if (modelo == aviaoDeComparacao.modelo && marca == aviaoDeComparacao.marca && servoProfundor == aviaoDeComparacao.servoProfundor && servoLeme == aviaoDeComparacao.servoLeme && servoAileronEs == aviaoDeComparacao.servoAileronEs && servoAileronDi == aviaoDeComparacao.servoAileronDi && servoAcelerador == aviaoDeComparacao.servoAcelerador)
            return true;
        else
            return false;
    }

    // Métodos para mudar as variáveis
    void Aviao::setModelo(string n_modelo) { this->modelo = n_modelo; }
    void Aviao::setMarca(string n_marca) { this->marca = n_marca; }
    void Aviao::setServoProfundor(float n_servoProfundor) { this->servoProfundor = n_servoProfundor; }
    void Aviao::setServoLeme(float n_servoLeme) { this->servoLeme = n_servoLeme; }
    void Aviao::setServoAileronEs(float n_servoAileronEs) { this->servoAileronEs = n_servoAileronEs; }
    void Aviao::setServoAileronDi(float n_servoAileronDi) { this->servoAileronDi = n_servoAileronDi; }
    void Aviao::setServoAcelerador(float n_servoAcelerador) { this->servoAcelerador = n_servoAcelerador; }
    void Aviao::insereDados(Dados<float> temp) { dadosDoModelo.push_back(temp); }

    // Métodos para mudar as variáveis dos Dados
    void Aviao::setDadosAltimetro(long unsigned int i, float altimetro) { dadosDoModelo[i].setAltimetro(altimetro); }
    void Aviao::setDadosPitot(long unsigned int i, float pitot) { dadosDoModelo[i].setPitot(pitot); }
    void Aviao::setDadosPitch(long unsigned int i, float pitch) { dadosDoModelo[i].setPitch(pitch); }
    void Aviao::setDadosRoll(long unsigned int i, float roll) { dadosDoModelo[i].setRoll(roll); }
    void Aviao::setDadosYaw(long unsigned int i, float yaw) { dadosDoModelo[i].setYaw(yaw); }

    // Métodos para saber os valores das variáveis
    string Aviao::getModelo() { return this->modelo; }
    string Aviao::getMarca() { return this->marca; }
    float Aviao::getServoProfundor() const { return this->servoProfundor; }
    float Aviao::getServoLeme() const { return this->servoLeme; }
    float Aviao::getServoAileronEs() const { return this->servoAileronEs; }
    float Aviao::getServoAileronDi() const { return this->servoAileronDi; }
    float Aviao::getServoAcelerador() const { return this->servoAcelerador; }

    // Métodos para saber os valores das variáveis dos Dados
    float Aviao::getDadosAltimetro(long unsigned int i) { return this->dadosDoModelo[i].getAltimetro(); }
    float Aviao::getDadosPitot(long unsigned int i) { return this->dadosDoModelo[i].getPitot(); }
    float Aviao::getDadosPitch(long unsigned int i) { return this->dadosDoModelo[i].getGiroscopio_pitch(); }
    float Aviao::getDadosRoll(long unsigned int i) { return this->dadosDoModelo[i].getGiroscopio_roll(); }
    float Aviao::getDadosYaw(long unsigned int i) { return this->dadosDoModelo[i].getGiroscopio_yaw(); }

    // Construtor que inicializa os parâmetros
    Aviao::Aviao(string n_modelo, string n_marca, float n_servoProfundor, float n_servoLeme, float n_servoAileronEs, float n_servoAileronDi, float n_servoAcelerador)
    {
        setModelo(n_modelo);
        setMarca(n_marca);
        setServoProfundor(n_servoProfundor);
        setServoLeme(n_servoLeme);
        setServoAileronEs(n_servoAileronEs);
        setServoAileronDi(n_servoAileronDi);
        setServoAcelerador(n_servoAcelerador);
    }

    // Destrutor padrão
    Aviao::~Aviao() { cout << "Avião Destruido!" << endl; }

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

    // Métodos da classe que estabiliza o avião na altura
    void Aviao::estabilizaAltura(long unsigned int i, float max, float min)
    {
        setServos(); // Verifica se os servos estão na posição inicial (0.0) onde a superfície de comando está sem inclinação
        int acesso = 0;
        // Verifica a taxa de variação
        float nivel = (dadosDoModelo[i + 1].getAltimetro() - dadosDoModelo[i].getAltimetro());
        // Se a taxa for negativa faz o módulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o ideal
        for (long unsigned int j = i; j < static_cast<long unsigned int>(dadosDoModelo.size()); j++)
        {
            // Se o dados forem menores que o mínimo entra e ajusta
            if (dadosDoModelo[j].getAltimetro() < min)
            {
                // Questão de acesso para ajustar o nível do profundor
                if (acesso == 0)
                {
                    // Ajusta o nível do profundor
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
            // Se o dados forem maiores que o máximo entra e ajusta
            if (dadosDoModelo[j].getAltimetro() > max)
            {
                // Questão de acesso para ajustar o nível do profundor
                if (acesso == 0)
                {
                    // Ajusta o nível do profundor
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

    // Métodos da classe que estabiliza o avião na velocidade
    void Aviao::estabilizaVelocidade(long unsigned int i, float max, float min)
    {
        setServos(); // Verifica se os servos estão na posição inicial (0.0) onde a superficie de comando entá sem inclinação
        int acesso = 0;
        // Verifica a taxa de variação
        float nivel = (dadosDoModelo[i + 1].getPitot() - dadosDoModelo[i].getPitot());
        // Se a taxa for negativa faz o módulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o ideal
        for (long unsigned int j = i; j < static_cast<long unsigned int>(dadosDoModelo.size()); j++)
        {
            // Se o dados forem menores que o mínimo entra e ajusta
            if (dadosDoModelo[j].getPitot() < min)
            {
                // Questão de acesso para ajustar o nível do acelerador
                if (acesso == 0)
                {
                    // Ajusta o nível do acelerador
                    decrementaAcelerador(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar a velocidade
                while (dadosDoModelo[j].getPitot() < min)
                    dadosDoModelo[j].movimentaPitot(servoAcelerador);
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoAcelerador = 0;
            // Se o dados forem maiores que o máximo entra e ajusta
            if (dadosDoModelo[j].getPitot() > max)
            {
                // Questão de acesso para ajustar o nível do acelerador
                if (acesso == 0)
                {
                    // Ajusta o nível do acelerador
                    incrementaAcelerador(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir a velocidade
                while (dadosDoModelo[j].getPitot() > max)
                    dadosDoModelo[j].movimentaPitot(servoAcelerador);
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoAcelerador = 0;
        }
    }

    // Métodos da classe que estabiliza o avião nos seus momentos
    void Aviao::estabilizaMomentos(long unsigned int i, float max, float min)
    {
        setServos(); // Verifica se os servos estão na posição inicial (0.0) onde a superficie de comando entá sem inclinação
        //---------------------------------------------------------------------------------------------------------------------------
        // ESTABILIZA O PITCH
        //---------------------------------------------------------------------------------------------------------------------------
        int acesso = 0;
        // Verifica a taxa de variação do momento
        float nivel = (dadosDoModelo[i + 1].getGiroscopio_pitch() - dadosDoModelo[i].getGiroscopio_pitch());
        // Se a taxa for negativa faz o módulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o momento do pitch ideal que e 0
        for (long unsigned int j = i; j < static_cast<long unsigned int>(dadosDoModelo.size()); j++)
        {
            // Se o dados forem menores que o mínimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_pitch() < min)
            {
                // Questão de acesso para ajustar o nível do momento pitch que é controlado pelo profundor
                if (acesso == 0)
                {
                    // Ajusta o nível do profundor
                    decrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento pitch que é controlado pelo profundor
                while (dadosDoModelo[j].getGiroscopio_pitch() < min && dadosDoModelo[j].getGiroscopio_pitch() <= 0)
                {
                    dadosDoModelo[j].movimentaPitch(servoProfundor);
                    // Se aumentar demais ele faz um último ajuste fino
                    if (dadosDoModelo[j].getGiroscopio_pitch() != nivel && dadosDoModelo[j].getGiroscopio_pitch() < nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                        dadosDoModelo[j].movimentaPitch(+(dadosDoModelo[j].getGiroscopio_pitch()));
                }
            }
            // Zera o acesso e o profundor para poder ter outro movimento
            acesso = 0;
            servoProfundor = 0;
            // Se o dados forem maiores que o máximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_pitch() > max)
            {
                // Questão de acesso para ajustar o nível do momento pitch que é controlado pelo profundor
                if (acesso == 0)
                {
                    // Ajusta o nivel do profundor
                    incrementaProfundor(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento pitch que é controlado pelo profundor
                while (dadosDoModelo[j].getGiroscopio_pitch() > max && dadosDoModelo[j].getGiroscopio_pitch() >= 0)
                {
                    dadosDoModelo[j].movimentaPitch(servoProfundor);
                    // Se diminuir demais ele faz um último ajuste fino
                    if (dadosDoModelo[j].getGiroscopio_pitch() != nivel && dadosDoModelo[j].getGiroscopio_pitch() < nivel && dadosDoModelo[j].getGiroscopio_pitch() != 0)
                        dadosDoModelo[j].movimentaPitch(-(dadosDoModelo[j].getGiroscopio_pitch()));
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
        // Se a taxa for negativa faz o módulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o momento do roll ideal que e 0
        for (long unsigned int j = i; j < static_cast<long unsigned int>(dadosDoModelo.size()); j++)
        {
            // Se o dados forem menores que o mínimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_roll() < min)
            {
                // Questão de acesso para ajustar o nível do momento roll que é controlado pelos ailerons
                if (acesso == 0)
                {
                    // Ajusta o nível dos ailerons
                    incrementaAileronVaiDi(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento roll que é controlado pelos ailerons
                while (dadosDoModelo[j].getGiroscopio_roll() < min && dadosDoModelo[j].getGiroscopio_roll() <= 0)
                {
                    dadosDoModelo[j].movimentaRoll(servoAileronEs, servoAileronDi);
                    // Se aumentar demais ele faz um último ajuste
                    if (dadosDoModelo[j].getGiroscopio_roll() != nivel && dadosDoModelo[j].getGiroscopio_roll() > nivel)
                        dadosDoModelo[j].movimentaRoll(+(dadosDoModelo[j].getGiroscopio_roll() / 2), -(dadosDoModelo[j].getGiroscopio_roll() / 2));
                }
            }
            // Zera o acesso e os ailerons para poder ter outro movimento
            acesso = 0;
            servoAileronEs = 0;
            servoAileronDi = 0;
            // Se o dados forem maiores que o máximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_roll() > max)
            {
                // Questão de acesso para ajustar o nível do momento roll que é controlado pelos ailerons
                if (acesso == 0)
                {
                    // Ajusta o nível dos ailerons
                    incrementaAileronVaiEs(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento roll que é controlado pelos ailerons
                while (dadosDoModelo[j].getGiroscopio_roll() > max && dadosDoModelo[j].getGiroscopio_roll() >= 0)
                {
                    dadosDoModelo[j].movimentaRoll(servoAileronEs, servoAileronDi);
                    // Se diminuir demais ele faz um último ajuste
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
        // Se a taxa for negativa faz o módulo
        if (nivel < 0)
            nivel *= -1;
        // Percorre os dados para corrigir para o momento do yaw ideal que e 0
        for (long unsigned int j = i; j < static_cast<long unsigned int>(dadosDoModelo.size()); j++)
        {
            // Se o dados forem menores que o mínimo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_yaw() < min)
            {
                // Questão de acesso para ajustar o nível do momento yaw que é controlado pelo leme
                if (acesso == 0)
                {
                    // Ajusta o nível do leme
                    decrementaLeme(nivel);
                    acesso++;
                }
                // Faz o ajuste para aumentar o momento yaw que é controlado pelo leme
                while (dadosDoModelo[j].getGiroscopio_yaw() < min && dadosDoModelo[j].getGiroscopio_yaw() <= 0)
                {
                    dadosDoModelo[j].movimentaYaw(servoLeme);
                    // Se aumentar demais ele faz um último ajuste
                    if (dadosDoModelo[j].getGiroscopio_yaw() != nivel && dadosDoModelo[j].getGiroscopio_yaw() < nivel && dadosDoModelo[j].getGiroscopio_yaw() != 0)
                        dadosDoModelo[j].movimentaYaw(+(dadosDoModelo[j].getGiroscopio_yaw()));
                }
            }
            // Zera o acesso e o leme para poder ter outro movimento
            acesso = 0;
            servoLeme = 0;
            // Se o dados forem maiores que o máximo entra e ajusta
            if (dadosDoModelo[j].getGiroscopio_yaw() > max)
            {
                // Questão de acesso para ajustar o nível do momento yaw que é controlado pelo leme
                if (acesso == 0)
                {
                    // Ajusta o nível do leme
                    incrementaLeme(nivel);
                    acesso++;
                }
                // Faz o ajuste para diminuir o momento yaw que é controlado pelo leme
                while (dadosDoModelo[j].getGiroscopio_yaw() > max && dadosDoModelo[j].getGiroscopio_yaw() >= 0)
                {
                    dadosDoModelo[j].movimentaYaw(servoLeme);
                    // Se diminuir demais ele faz um último ajuste
                    if (dadosDoModelo[j].getGiroscopio_yaw() != nivel && dadosDoModelo[j].getGiroscopio_yaw() < nivel && dadosDoModelo[j].getGiroscopio_yaw() != 0)
                        dadosDoModelo[j].movimentaYaw(+(dadosDoModelo[j].getGiroscopio_yaw()));
                }
            }
            // Zera o acesso e o leme para poder ter outro movimento
            acesso = 0;
            servoLeme = 0;
        }
        //---------------------------------------------------------------------------------------------------------------------------
    }

    // Imprime todos os dados do avião aplicando os conceitos de polimorfismo
    void Aviao::imprimirEspecificacoes() const
    {
        cout << endl
             << "Modelo: " << this->modelo << endl
             << "Marca: " << this->marca << endl
             << "Servo Profundor: " << this->servoProfundor << endl
             << "Servo Leme: " << this->servoLeme << endl
             << "Servo Aileron Esquerdo: " << this->servoAileronEs << endl
             << "Servo Aileron Direito: " << this->servoAileronDi << endl
             << "Servo Acelerador: " << this->servoAcelerador << endl;
    }

    // Imprime todos os dados dos dados
    void Aviao::imprimirDadosDados()
    {
        cout << "Dados do modelo " << getModelo() << endl;
        cout << "---------------------" << endl
             << "A -> Altura" << endl
             << "V -> Velocidade" << endl
             << "Mp -> Momento pitch" << endl
             << "Mr -> Momento roll" << endl
             << "My -> Momento yaw" << endl
             << "---------------------" << endl;
        cout << "[i] A V Mp Mr My" << endl;
        for (long unsigned int i = 0; i < static_cast<long unsigned int>(dadosDoModelo.size()); i++)
        {
            cout << "[" << i << "] " << dadosDoModelo[i].getAltimetro() << " "
                 << dadosDoModelo[i].getPitot() << " "
                 << dadosDoModelo[i].getGiroscopio_pitch() << " "
                 << dadosDoModelo[i].getGiroscopio_roll() << " "
                 << dadosDoModelo[i].getGiroscopio_yaw() << endl;
        }
        cout << endl;
    }
    // Verifica se os servos estão na posição inicial (0.0) onde a superfície de comando está sem inclinação
    void Aviao::setServos()
    {
        if (servoProfundor != 0)
            servoProfundor = 0;
        if (servoLeme != 0)
            servoLeme = 0;
        if (servoAileronEs != 0)
            servoAileronEs = 0;
        if (servoAileronDi != 0)
            servoAileronDi = 0;
        if (servoAcelerador != 0)
            servoAcelerador = 0;
    }
} // namespace SimuladorDeVooSimples
