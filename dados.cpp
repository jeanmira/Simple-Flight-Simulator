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

    // Retorna o valor de pitch
    float Dados::getGiroscopio_pitch()
    {
        return giroscopio[0];
    }
    // Retorna o valor de roll
    float Dados::getGiroscopio_roll()
    {
        return giroscopio[1];
    }
    // Retorna o valor de yaw
    float Dados::getGiroscopio_yaw()
    {
        return giroscopio[2];
    }
    // Set o altimetro recebido dos dados
    void Dados::setAltimetro(float altimetro)
    {
        this->altimetro = altimetro;
    }
    // Retorna o valor do altimetro
    float Dados::getAltimetro()
    {
        return altimetro;
    }
    // Set o pitot recebido dos dados
    void Dados::setPitot(float pitot)
    {
        this->pitot = pitot;
    }
    // Retorna o pitot
    float Dados::getPitot()
    {
        return pitot;
    }

    Dados::Dados(float altimetro, float pitot, float pitch, float roll, float yaw)
    {
        setAltimetro(altimetro);
        setPitot(pitot);
        setGiroscopio(pitch, roll, yaw);
    }
    Dados::Dados()
    {
        setAltimetro(0);
        setPitot(0);
        setGiroscopio(0, 0, 0);
    }

    void Dados::setPitch(float pitch)
    {
        giroscopio[0] = pitch;
    }
    void Dados::setRoll(float roll)
    {
        giroscopio[1] = roll;
    }
    void Dados::setYaw(float yaw)
    {
        giroscopio[2] = yaw;
    }
} //namespace SimuladorDeVooSimples
