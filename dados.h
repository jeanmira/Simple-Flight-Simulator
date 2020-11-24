#ifndef DADOS_H
#define DADOS_H

/*
  Classe responsável pelos dados do avião, como podem haver
  vários aviões com vários parâmetros foi necessário criar
  essa classe
  
  giroscopio  =>  A ideia para o giroscópio e poder saber
                  em qual posição o avião está assim dando
                  autonomia para que os servos motores possam
                  manter a estabilidade
  altimetro   =>  Vai dar dados que possibilitem a modificacao
                  da altura do avião, assim podendo alterar a
                  abertura do profundor para subir ou descer
  pitot       =>  Esse instrumento é utilizado medir a velocidade e
                  após retornar esse dado é possível aumentar o
                  diminuir a velocidade para que o aviao nao estole
*/

namespace SimuladorDeVooSimples
{
    template <typename T>
    class Dados
    {
    private:
        /*
   • giroscópio(pitch, roll, yaw) onde pitch, roll e yaw são
   os principais eixos de inércia de uma aeronave, como pode
   ser visto na figura abaixo.
 
   •altímetro(h) onde h e a altura referente ao nível do mar;
 
   • pitot(v) onde v e a velocidade da aeronave;
   */

        T giroscopio[3]; // Medição do momento
        T altimetro;     // Altitude medida em relação ao nível do mar
        T pitot;         // Instrumento de medição de velocidade

    public:
        void setGiroscopio(T pitch, T roll, T yaw); // Método set do Giroscópio
        void setAltimetro(T altimetro);             // Método set do Altímetro
        void setPitot(T pitot);                     // Método set do Pitot
        void setPitch(T pitch);                     // Método set do pitch do Giroscópio
        void setRoll(T roll);                       // Método set do roll do Giroscópio
        void setYaw(T yaw);                         // Método set do yaw do Giroscópio

        T getGiroscopio_pitch(); // Método get do pitch do Giroscópio
        T getGiroscopio_roll();  // Método get do roll do Giroscópio
        T getGiroscopio_yaw();   // Método get do yaw do Giroscópio
        T getAltimetro();        // Método get do Altímetro
        T getPitot();            // Método get do Pitot

        Dados(T altimetro, T pitot, T pitch, T roll, T yaw); // Construtor que inicializa os parâmetros
        Dados();                                             // Construtor padrão
        ~Dados();                                            // Destrutor padrão

        // Métodos decrementos
        void movimentaAltimetro(T profundor);
        void movimentaPitot(T acelerador);
        void movimentaPitch(T profundor);
        void movimentaRoll(T aileronEs, T aileronDi);
        void movimentaYaw(T leme);
    };

    // Set o pitch,roll e o yaw de acordo com as posições dos dados
    template <typename T>
    void Dados<T>::setGiroscopio(T pitch, T roll, T yaw)
    {
        giroscopio[0] = pitch;
        giroscopio[1] = roll;
        giroscopio[2] = yaw;
    }
    template <typename T>
    void Dados<T>::setAltimetro(T n_altimetro) { this->altimetro = n_altimetro; } // Set o altimetro recebido dos dados
    template <typename T>
    void Dados<T>::setPitot(T n_pitot) { this->pitot = n_pitot; } // Set o pitot recebido dos dados
    template <typename T>
    void Dados<T>::setPitch(T n_pitch) { giroscopio[0] = n_pitch; } // Método set do pitch do Giroscópio
    template <typename T>
    void Dados<T>::setRoll(T n_roll) { giroscopio[1] = n_roll; } // Método set do roll do Giroscópio
    template <typename T>
    void Dados<T>::setYaw(T n_yaw) { giroscopio[2] = n_yaw; } // Método set do yaw do Giroscópio

    template <typename T>
    T Dados<T>::getGiroscopio_pitch() { return giroscopio[0]; } // Retorna o valor de pitch
    template <typename T>
    T Dados<T>::getGiroscopio_roll() { return giroscopio[1]; } // Retorna o valor de roll
    template <typename T>
    T Dados<T>::getGiroscopio_yaw() { return giroscopio[2]; } // Retorna o valor de yaw
    template <typename T>
    T Dados<T>::getAltimetro() { return altimetro; } // Retorna o valor do altímetro
    template <typename T>
    T Dados<T>::getPitot() { return pitot; } // Retorna o pitot

    // Construtor que inicializa os parâmetros
    template <typename T>
    Dados<T>::Dados(T n_altimetro, T n_pitot, T n_pitch, T n_roll, T n_yaw)
    {
        setAltimetro(n_altimetro);
        setPitot(n_pitot);
        setGiroscopio(n_pitch, n_roll, n_yaw);
    }

    // Construtor padrão
    template <typename T>
    Dados<T>::Dados()
    {
        setAltimetro(0);
        setPitot(0);
        setGiroscopio(0, 0, 0);
    }

    // Destrutor padrão
    template <typename T>
    Dados<T>::~Dados() {}

    // Métodos de movimento das estruturas de controle
    template <typename T>
    void Dados<T>::movimentaAltimetro(T profundor) { altimetro -= (profundor); }
    template <typename T>
    void Dados<T>::movimentaPitot(T acelerador) { pitot -= (acelerador); }
    template <typename T>
    void Dados<T>::movimentaPitch(T profundor) { giroscopio[0] -= (profundor); }
    template <typename T>
    void Dados<T>::movimentaRoll(T aileronEs, T aileronDi)
    {
        giroscopio[1] -= (aileronDi);
        giroscopio[1] += (aileronEs);
    }
    template <typename T>
    void Dados<T>::movimentaYaw(T leme) { giroscopio[2] -= (leme); }

} // namespace SimuladorDeVooSimples
#endif
