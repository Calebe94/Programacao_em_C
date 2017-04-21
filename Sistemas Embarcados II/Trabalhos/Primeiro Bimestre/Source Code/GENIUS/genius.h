#include<stdint.h>
#include"tm4c123gh6pm.h"
#include"pins.h"

typedef struct{
    uint8_t queue[100];
    uint8_t index;
    uint8_t iVerify;
    uint8_t start_control;
    uint8_t level; // 0 a 2
    uint16_t delay;
    
}GENIUS;

/*************************************************************************
 * setup();
 * Função responsável chamar as funções que serão chamadas apenas uma vez,
 * e inicializar os terminais da TM4C123.
 *************************************************************************/
void setup(void);

/***************************************************************************
 * loop()
 * Função responsável por chamar funções que serão repetidas infinitamente.
 * E também é nessa função será realizado o jogo.
 ***************************************************************************/
void loop(void);

/***************************************************************************
 * wait_to_start();
 * Irá piscar todos os leds de forma sequencial e rápida,
 * e esperará até que qualquer um dos quatros botões sejam pressionados,
 * isso ocasionará a saída da função e consequentemente iniciará o jogo.
 ***************************************************************************/
unsigned int wait_to_start(GENIUS *this);

/***************************************************************************
 * game_init();
 * Inicia a sequência do jogo e atualiza a fila do jogo.
 * irá.
 * pisca um led aleatório e salva a posição na fila.
 * aguarda pressionar o botão.
 * pisca o led correspondente ao botão
 * verifica se o botão botão pressionado corresponde a fila.
 * executa a função verify().
 ***************************************************************************/
void game_init(GENIUS *this);

/***************************************************************************
 * verify();
 * Verifica se o botão pressionado corresponde a posição da fila.
 * se não, volta para função wait_to_start().
 ***************************************************************************/
void verify(GENIUS *this);

void execute(GENIUS *this);

/*Play music tones*/
void Tones(uint8_t which);

void You_Lose(GENIUS this);

void congratulations(GENIUS *this);
