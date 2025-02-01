# Tarefa 2 - Controle Sequencial de LEDs com Temporização

## 🛠️ Componentes Utilizados

- 03 LEDs (Vermelho, Verde e Azul)
- 01 Botão
- 01 Resistor de 1kΩ (para pull-down do botão)
- 01 Raspberry Pi Pico W
- Protoboard e jumpers

## 💻 Firmware

Desenvolvido em C utilizando:

- IDE: Visual Studio Code
- SDK: Raspberry Pi Pico SDK
- Simulador: Wokwi (para testes virtuais)
- LED Vermelho: GP13
- LED Verde: GP11
- LED Azul: GP12
- Botão: GP5 (com resistor pull-down)

## 🎯 Funcionamento

### Estado Inicial

- Todos os LEDs iniciam desligados

### Fluxo de Operação:

1. Primeiro acionamento do botão:
    - Todos os LEDs acendem simultaneamente
    - Inicia temporização de 3 segundos

2. Após 3 segundos:
    - LED Verde se apaga
    - Nova temporização de 3 segundos inicia

3. Após 6 segundos totais:
    - LED Azul se apaga
    - Última temporização de 3 segundos inicia

4. Após 9 segundos totais:
    - LED Vermelho se apaga
    - Sistema retorna ao estado inicial (Reset)

### Explicação

Os intervalos são gerenciados pelo hardware do Pico através da função add_alarm_in_ms, deixando-o livre para realizar outras operações.

## 👥 Autoria
**Guilherme Emetério Santos Lima**  
[![GitHub](https://img.shields.io/badge/GitHub-Profile-blue?style=flat&logo=github)](https://github.com/DankAlighieri)