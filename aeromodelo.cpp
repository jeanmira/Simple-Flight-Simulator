#include "aeromodelo.h"

namespace SimuladorDeVooSimples
{
    // Construtor que inicializa os parâmetros

    Aeromodelo::Aeromodelo(const string modelo, const string marca, const string cor, const string modeloTransmissor, float servoProfundor, float servoLeme, float servoAileronEs, float servoAileronDi, float servoAcelerador, float preco) : Aviao(modelo, marca, servoProfundor, servoLeme, servoAileronEs, servoAileronDi, servoAcelerador)
    {
        setPreco(preco);
        setCor(cor);
        setModeloTransmissor(modeloTransmissor);
    }

    // Destrutor padrão
    Aeromodelo::~Aeromodelo() { cout << "Aeromodelo Destruido!" << endl; }

    // Métodos para mudar as variaveis
    void Aeromodelo::setPreco(float preco) { this->preco = (preco < 0.0) ? 0.0 : preco; }
    void Aeromodelo::setCor(string cor) { this->cor = cor; }
    void Aeromodelo::setModeloTransmissor(string modeloTransmissor) { this->modeloTransmissor = modeloTransmissor; }

    // Métodos para saber os valores das variáveis
    float Aeromodelo::getPreco() { return this->preco; }
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
