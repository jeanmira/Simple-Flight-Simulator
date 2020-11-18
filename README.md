# **Trabalho Final de Programação III**

[![Generic badge](https://img.shields.io/badge/Status-Construção-<COLOR>.svg)](https://shields.io/)

##  Descrição do Trabalho:
Para o trabalho final da disciplina  de programação 3 decidimos elaborar um sistema de estabilização de uma aeronave baseado em sensores como giroscópio, altímetro e o tubo de pitot que dão parâmetros para decidir o comportamento dos servomotores da aeronave, os servomotores servem para movimentar as superfícies de comando e portanto estabilizado a aeronave, o programa deve ser capaz de estabilizar a aeronave buscando sempre voltar ao seu estado de perfeita estabilidade. Tendo assim um arquivo .txt padrão para decolagem, voo de cruzeiro e pouso que são gerados através de um programa também desenvolvido neste projeto.

Para nossa análise vamos considerar o avião **Cessna 172 Skyhawk** e iremos analisar uma decolagem na qual o mesmo tem a tendência de estolar que nada mais é do que a perda da sustentação que pode ser causada por uma inclinação aguda do bico da aeronave além do vento lateral que pode vir a causar o mesmo problema. Durante o voo de cruzeiro, período no qual se mantém uma velocidade constante e durante o pouso, vamos novamente simular o movimento de todos os eixos da aeronave (pitch, roll, yaw).

A seguir podemos ver o diagrama de blocos simplificando o funcionamento do código:

Figura 1 - Diagrama de blocos do funcionamento do código.
![Diagrama de Blocos](https://github.com/jeanmira/Trabalho-Final-CPP/blob/master/Imagens/diagrama.png)

### Pré-requisitos para executar no sistema operacional UBUNTU | g++ 7 | coding utf-8 :
    • Pacotes:
        sudo apt-get install build-essential
        
###    Funcionamento da obtenção de dados:
    • altimetro(h) onde h e a altura referente ao nível do mar;
    • pitot(v) onde v e a velocidade da aeronave;
    • giroscopio(pitch, roll, yaw) onde pitch, roll e yaw são os principais eixos de inércia de uma aeronave, como pode ser visto na figura abaixo.

   Figura 2 - pitch, roll e yaw em uma aeronave.
   ![Eixos](https://github.com/jeanmira/Trabalho-Final-CPP/blob/master/Imagens/eixos.png)

#### Desenvolvedores:
Jean Marcelo Mira Junior - 16102369 | E-mail: jeandemira@gmail.com

William Chiou Abe - 17104146 | E-mail: williamabe1998@hotmail.com



#### Referências:
WIKIPEDIA. Aircraft principal axes. Disponível em: https://en.wikipedia.org/wiki/Aircraft_principal_axes. Acesso em: 31 out. 2020.

SILVA, Túlio Dapper e. Instrumentação de um veículo aéreo não tripulado para análise de sua performance. 2017. 48 f. TCC (Graduação) - Curso de Engenharia de Controle e Automação, Universidade Federal do Rio Grande do Sul, Porto Alegre, 2017. Disponível em: https://lume.ufrgs.br/bitstream/handle/10183/172738/001059842.pdf;jsessionid=6088500D3F5A15B86E0E6DD05B137684?sequence=1. Acesso em: 31 out. 2020.

WIKIPÉDIA. Cessna 172. Disponível em: https://pt.wikipedia.org/wiki/Cessna_172. Acesso em: 31 out. 2020.


