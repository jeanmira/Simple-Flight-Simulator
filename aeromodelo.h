#ifndef AEROMODELO_H
#define AEROMODELO_H

#include <iostream>
#include <string>
using namespace std;

// Classe Aeromodelo herda classe Aviao
class Aeromodelo : public Aviao
{
private:
    float preco;
    string cor;
    string modeloTransmissor;

public:
    // Construtor padrão
    Aeromodelo() : modelo{"Cessna 172 Skyhawk"}, marca{"Cessna Aircraft Company"}, servoProfundor{0.0}, servoLeme{0.0}, servoAileronEs{0.0}, servoAileronDi{0.0}, servoAcelerador{0.0} {};
    Aeromodelo(const string &, const string &, float = 0.0, float = 0.0, float = 0.0, float = 0.0, float = 0.0);
    void setPreco();
    float getPreco(float);
    void setCor();
    string getCor(string);
    void setModeloTransmissor();
    string getModeloTransmissor(string);
}

#endif

/* // Figura 12.10: BasePlusCommissionEmployee.h
// Classe BasePlusCommissionEmployee derivada da classe
// CommissionEmployee.
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include <string> // classe string padrão C++
using std::string;
#include “CommissionEmployee.h” // declaração da classe CommissionEmployee
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &,
                               const string &, double = 0.0, double = 0.0, double = 0.0);
    void setBaseSalary(double);   // configura o salário-base
    double getBaseSalary() const; // retorna o salário-base
    double earnings() const;      // calcula os rendimentos
    void print() const;           // imprime o objeto BasePlusCommissionEmployee
private:
    double baseSalary; // salário-base
};                     // fim da classe BasePlusCommissionEmployee
#endif */
