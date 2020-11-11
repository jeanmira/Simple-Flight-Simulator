#include "dados.h"
/*  
    O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares, 
    monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
*/
namespace SimuladorDeVooSimples
{

    // Set o pitch,roll e o yaw de acordo com as posições dos dados
    void Dados::setGiroscopio(float pitch, float roll, float yaw)
    {
        giroscopio[0] = pitch;
        giroscopio[1] = roll;
        giroscopio[2] = yaw;
    }
    void Dados::setAltimetro(float altimetro) { this->altimetro = altimetro; } // Set o altimetro recebido dos dados
    void Dados::setPitot(float pitot) { this->pitot = pitot; }                 // Set o pitot recebido dos dados
    void Dados::setPitch(float pitch) { giroscopio[0] = pitch; }               // Método set do pitch do Giroscopio
    void Dados::setRoll(float roll) { giroscopio[1] = roll; }                  // Método set do roll do Giroscopio
    void Dados::setYaw(float yaw) { giroscopio[2] = yaw; }                     // Método set do yaw do Giroscopio

    float Dados::getGiroscopio_pitch() { return giroscopio[0]; } // Retorna o valor de pitch
    float Dados::getGiroscopio_roll() { return giroscopio[1]; }  // Retorna o valor de roll
    float Dados::getGiroscopio_yaw() { return giroscopio[2]; }   // Retorna o valor de yaw
    float Dados::getAltimetro() { return altimetro; }            // Retorna o valor do altimetro
    float Dados::getPitot() { return pitot; }                    // Retorna o pitot

    // Contrutor que inicializa os parâmetros
    Dados::Dados(float altimetro, float pitot, float pitch, float roll, float yaw)
    {
        setAltimetro(altimetro);
        setPitot(pitot);
        setGiroscopio(pitch, roll, yaw);
    }

    // Contrutor padrão
    Dados::Dados()
    {
        setAltimetro(0);
        setPitot(0);
        setGiroscopio(0, 0, 0);
    }
} //namespace SimuladorDeVooSimples
