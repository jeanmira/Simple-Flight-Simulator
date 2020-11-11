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

        float giroscopio[3]; // Medição do momento
        float altimetro;     // Altitude medida em relação ao nível do mar
        float pitot;         // Instrumento de medição de velocidade

    public:
        void setGiroscopio(float pitch, float roll, float yaw); // Método set do Giroscopio
        void setAltimetro(float altimetro);                     // Método set do Altimetro
        void setPitot(float pitot);                             // Método set do Pitot
        void setPitch(float pitch);                             // Método set do pitch do Giroscopio
        void setRoll(float roll);                               // Método set do roll do Giroscopio
        void setYaw(float yaw);                                 // Método set do yaw do Giroscopio

        float getGiroscopio_pitch(); // Método get do pitch do Giroscopio
        float getGiroscopio_roll();  // Método get do roll do Giroscopio
        float getGiroscopio_yaw();   // Método get do yaw do Giroscopio
        float getAltimetro();        // Método get do Altimetro
        float getPitot();            // Método get do Pitot

        Dados(float altimetro, float pitot, float pitch, float roll, float yaw); // Contrutor que inicializa os parâmetros
        Dados();                                                                 // Contrutor padrão
    };
} // namespace SimuladorDeVooSimples
#endif
