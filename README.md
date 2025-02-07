Controle de Servo Motor com PWM no Raspberry Pi Pico W
Colaboradora: Isabel Rosa de Santana. 

Descrição

Este projeto implementa o controle de um servomotor usando PWM no Raspberry Pi Pico W, simulando a movimentação entre 0° e 180° com suavidade. Além disso, um LED no GPIO 12 pisca sincronizado com o movimento do servo, permitindo análise visual do comportamento do PWM na BitDogLab.

A simulação foi realizada no Wokwi, e o código foi desenvolvido em C, utilizando o Pico SDK no VS Code.


Requisitos da Atividade

1. Configurar o PWM na GPIO 22 com frequência de 50Hz (período de 20ms).


2. Ajustar o ciclo ativo do PWM para:

2400µs (12%) → Servo em 180° (aguardar 5s).

1470µs (7,35%) → Servo em 90° (aguardar 5s).

500µs (2,5%) → Servo em 0° (aguardar 5s).



3. Criar um movimento suave entre 0° e 180°, incrementando ±5µs a cada 10ms.


4. Utilizar o LED no GPIO 12 para observar o efeito da variação do PWM na BitDogLab.


5. Realizar a simulação no Wokwi e testar no Raspberry Pi Pico W.


6. Criar um repositório no GitHub e produzir um vídeo de até 3 minutos mostrando os resultados.

Componentes Utilizados

Raspberry Pi Pico W

Servo Motor (SG90 ou similar)

LED Vermelho (GPIO 12)

Resistor de 330Ω

Software: VS Code + Pico SDK + Wokwi

Como Executar o Código

1️⃣ Clonar o Repositório

git clone https://github.com/seu-usuario/nome-do-repositorio.git
cd nome-do-repositorio

2️⃣ Compilar o Código (Usando o Pico SDK)

mkdir build
cd build
cmake ..
make

3️⃣ Carregar no Raspberry Pi Pico W

Copie o arquivo .uf2 gerado para o Pico montado como unidade USB.

Simulação no Wokwi

Você pode testar a simulação no Wokwi usando o seguinte arquivo JSON:
Clique aqui para acessar a simulação no Wokwi

Para rodar localmente:

1. Acesse https://wokwi.com.


2. Crie um novo projeto de Raspberry Pi Pico.


3. Copie e cole o código fonte e o arquivo project.wokwi.json.


4. Clique em "Start Simulation".

Vídeo da Demonstração

🔗 [Link do Vídeo]  (https://youtu.be/SFKNolr5f3c?si=IIN023eEmowroVIO)

