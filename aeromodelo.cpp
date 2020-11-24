#include "aeromodelo.h"

namespace SimuladorDeVooSimples
{
    // Construtor que inicializa os parâmetros

    Aeromodelo::Aeromodelo(const string n_modelo, const string n_marca, const string n_cor, const string n_modeloTransmissor, float n_servoProfundor, float n_servoLeme, float n_servoAileronEs, float n_servoAileronDi, float n_servoAcelerador, double n_preco) : Aviao(n_modelo, n_marca, n_servoProfundor, n_servoLeme, n_servoAileronEs, n_servoAileronDi, n_servoAcelerador)
    {
        setPreco(n_preco);
        setCor(n_cor);
        setModeloTransmissor(n_modeloTransmissor);
    }

    // Destrutor padrão
    Aeromodelo::~Aeromodelo() { cout << "Aeromodelo Destruido!" << endl; }

    // Métodos para mudar as variáveis
    void Aeromodelo::setPreco(double n_preco) { this->preco = (n_preco < 0.0) ? 0.0 : n_preco; }
    void Aeromodelo::setCor(string n_cor) { this->cor = n_cor; }
    void Aeromodelo::setModeloTransmissor(string n_modeloTransmissor) { this->modeloTransmissor = n_modeloTransmissor; }

    // Métodos para saber os valores das variáveis
    double Aeromodelo::getPreco() { return this->preco; }
    string Aeromodelo::getCor() { return this->cor; }
    string Aeromodelo::getModeloTransmissor() { return this->modeloTransmissor; }

    // Imprime todos os dados do aeromodelo aplicando os conceitos de polimorfismo
    void Aeromodelo::imprimirEspecificacoes() const
    {
        Aviao::imprimirEspecificacoes();
        cout << "Cor: " << this->cor << endl
             << "Valor: " << this->preco << endl
             << endl;
    }

} // namespace SimuladorDeVooSimples
