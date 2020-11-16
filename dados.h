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
    • giroscopio(pitch, roll, yaw) onde pitch, roll e yaw são 
    os principais eixos de inércia de uma aeronave, como pode 
    ser visto na figura abaixo.

    •altimetro(h) onde h e a altura referente ao nível do mar;

    • pitot(v) onde v e a velocidade da aeronave;
    */

        T giroscopio[3]; // Medição do momento
        T altimetro;     // Altitude medida em relação ao nível do mar
        T pitot;         // Instrumento de medição de velocidade

    public:
        void setGiroscopio(T pitch, T roll, T yaw); // Método set do Giroscopio
        void setAltimetro(T altimetro);             // Método set do Altimetro
        void setPitot(T pitot);                     // Método set do Pitot
        void setPitch(T pitch);                     // Método set do pitch do Giroscopio
        void setRoll(T roll);                       // Método set do roll do Giroscopio
        void setYaw(T yaw);                         // Método set do yaw do Giroscopio

        T getGiroscopio_pitch(); // Método get do pitch do Giroscopio
        T getGiroscopio_roll();  // Método get do roll do Giroscopio
        T getGiroscopio_yaw();   // Método get do yaw do Giroscopio
        T getAltimetro();        // Método get do Altimetro
        T getPitot();            // Método get do Pitot

        Dados(T altimetro, T pitot, T pitch, T roll, T yaw); // Contrutor que inicializa os parâmetros
        Dados();                                             // Contrutor padrão
        ~Dados();                                            // Destrutor padrão

        // Métodos decrementos
        void movimentaAltimetro(T i);
        void movimentaPitot(T i);
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
    void Dados<T>::setAltimetro(T altimetro) { this->altimetro = altimetro; } // Set o altimetro recebido dos dados
    template <typename T>
    void Dados<T>::setPitot(T pitot) { this->pitot = pitot; } // Set o pitot recebido dos dados
    template <typename T>
    void Dados<T>::setPitch(T pitch) { giroscopio[0] = pitch; } // Método set do pitch do Giroscopio
    template <typename T>
    void Dados<T>::setRoll(T roll) { giroscopio[1] = roll; } // Método set do roll do Giroscopio
    template <typename T>
    void Dados<T>::setYaw(T yaw) { giroscopio[2] = yaw; } // Método set do yaw do Giroscopio

    template <typename T>
    T Dados<T>::getGiroscopio_pitch() { return giroscopio[0]; } // Retorna o valor de pitch
    template <typename T>
    T Dados<T>::getGiroscopio_roll() { return giroscopio[1]; } // Retorna o valor de roll
    template <typename T>
    T Dados<T>::getGiroscopio_yaw() { return giroscopio[2]; } // Retorna o valor de yaw
    template <typename T>
    T Dados<T>::getAltimetro() { return altimetro; } // Retorna o valor do altimetro
    template <typename T>
    T Dados<T>::getPitot() { return pitot; } // Retorna o pitot

    // Contrutor que inicializa os parâmetros
    template <typename T>
    Dados<T>::Dados(T altimetro, T pitot, T pitch, T roll, T yaw)
    {
        setAltimetro(altimetro);
        setPitot(pitot);
        setGiroscopio(pitch, roll, yaw);
    }

    // Contrutor padrão
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

    // Método decremento
    template <typename T>
    void Dados<T>::movimentaAltimetro(T profundor) { altimetro -= (profundor); }
    template <typename T>
    void Dados<T>::movimentaPitot(T acelerador) { pitot -= (acelerador); }

} // namespace SimuladorDeVooSimples
#endif
