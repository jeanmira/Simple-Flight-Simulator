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
float Dados::getGiroscopio_pitch(){
    return giroscopio[0];
}    
// Retorna o valor de roll
float Dados::getGiroscopio_roll(){
    return giroscopio[1];
}
// Retorna o valor de yaw
float Dados::getGiroscopio_yaw(){
    return giroscopio[2];
}
// Set o altimetro recebido dos dados
void Dados::setAltimetro(int altimetro)
{
    this->altimetro = altimetro;
}
// Retorna o valor do altimetro
int Dados::getAltimetro()
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
    
}//namespace SimuladorDeVooSimples
