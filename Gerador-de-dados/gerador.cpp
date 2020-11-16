#include <iostream> // Biblioteca padrão
#include <fstream>  // Para manipular arquivos

using namespace std;

/* 
   O Cessna 172 Skyhawk é uma aeronave americana de quatro lugares,
   monomotor, asa alta e asa fixa, fabricada pela Cessna Aircraft Company.
 
   Altura máxima 1270 km
   Velocidade de cruzeiro 222 km/h
   Velocidade máxima 302 km/h
   Comprimento 8,28 m
   Envergadura 11 m
   Altura 2,72 m
   Área das asas 16,2 m²
   Alongamento 7.5
*/

int main()
{
    //-----------------------------------------------------------------------------------------------------------------------------
    ofstream papel("dados-decolagem.txt"); // Cria arquivo com dados de decolagem

    for (int i = 0; i <= 1270; i++)
    {
        if ((i % 5) == 0) //Pega as alturas de 5 em 5 até 1270 que é a altura maxima com máximo de carga
        {
            // Altura(km) velocidade(km/h) pitch(N/m) roll(N/m) yaw(N/m)
            papel << i << " "; // Altura
            if (i != 0)
                papel << (200 + (i * 102 / float(1270))) << " "; // Velocidade para voar
            else
                papel << "0"
                      << " ";                        // Velocidade para voar
            papel << (i + (0.0055 * 30000)) << " ";  // Valor de pitch baseado na metade da envergadura em km vezes uma força
            papel << (i + (0.00828 * 30000)) << " "; // O roll é o momento do comprimento em km vezes uma força
            papel << 0;                              // O momento em yaw é zero pois não tem giro nesse eixo
            papel << "\n";
        }
    }
    cout << endl; // Pula uma linha no fim
    //-----------------------------------------------------------------------------------------------------------------------------
    ofstream papel1("dados-cruzeiro.txt"); // Cria arquivo com dados de cruzeiro
    int tres = 0;
    float v = 302;
    for (int i = 0; i < 1000; i++)
    {
        // Altura(km) velocidade(km/h) pitch(N/m) roll(N/m) yaw(N/m)

        papel1 << (1270 - i) << " "; // Altura
        if (tres == 3 || tres == 1)
        {
            v -= 0.5;
            papel1 << v << " "; // Velocidade para voar
            tres = 0;
        }
        else
        {

            papel1 << v << " "; // Velocidade para voar
            tres++;
        }
        papel1 << -1 * (i + (0.0055 * 300)) << " ";        // Valor de pitch baseado na metade da envergadura em km vezes uma força
        papel1 << -1 * (i + (0.00828 * 30000)) << " ";     // O roll é o momento do comprimento em km vezes uma força
        papel1 << -1 * (i + ((0.00828 + 0.0055) * 30000)); // O momento em yaw é zero pois não tem giro nesse eixo
        papel1 << "\n";
    }
    cout << endl; // Pula uma linha no fim
    //-----------------------------------------------------------------------------------------------------------------------------
    ofstream papel2("dados-pouso.txt"); // Cria arquivo com dados de pouso
    float j = 0;
    for (int i = 0; i <= 1270; i++)
    {
        if ((i % 5) == 0) //Pega as alturas de 5 em 5 até 1270 que é a altura maxima com máximo de carga
        {
            // Altura(km) velocidade(km/h) pitch(N/m) roll(N/m) yaw(N/m)
            papel2 << 1270 - i << " "; // Altura
            if (j == 0)
            {
                papel2 << (222 - j) << " "; // Velocidade para voar
            }
            else
                papel2 << (222 - j) << " "; // Velocidade para voar
            j += 0.75;
            papel2 << -1 * (i + (0.0055 * 30000)) << " "; // Valor de pitch baseado na metade da envergadura em km vezes uma força
            papel2 << (i + (0.00828 * 30000)) << " ";     // O roll é o momento do comprimento em km vezes uma força
            papel2 << (i + ((0.0055 + 0.00828) * 30000)); // O momento em yaw é zero pois não tem giro nesse eixo
            papel2 << "\n";
        }
    }
    cout << endl; // Pula uma linha no fim
    //-----------------------------------------------------------------------------------------------------------------------------
    papel2.close(); // Fecha arquivo com dados de pouso
    papel1.close(); // Fecha arquivo com dados de cruzeiro
    papel.close();  // Fecha arquivo com dados de decolagem

    return 0;
}
