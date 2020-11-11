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

/*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
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
        int altimetro;       // Altitude medida em relação ao nível do mar
        float pitot;         // Instrumento de medição de velocidade

    public:
        void setGiroscopio(float pitch, float roll, float yaw); // Método set do Giroscopio
        float getGiroscopio_pitch();                            // Método get do pitch do Giroscopio
        float getGiroscopio_roll();                             // Método get do roll do Giroscopio
        float getGiroscopio_yaw();                              // Método get do yaw do Giroscopio
        void setAltimetro(int altimetro);                       // Método set do Altimetro
        int getAltimetro();                                     // Método get do Altimetro
        void setPitot(float pitot);                             // Método set do Pitot
        float getPitot();                                       // Método get do Pitot
    };
} // namespace SimuladorDeVooSimples
#endif
