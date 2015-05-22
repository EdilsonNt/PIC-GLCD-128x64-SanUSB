/************************************************
* Compilador Multiplataforma MPLABX C18:
* https://dl.dropboxusercontent.com/u/101922388/BaixarMPLABX_C18.pdf*/

#include "SanUSB48.h" //Vídeo: http://www.youtube.com/watch?v=9inU3HIoy7o
#include "GLCD.h"     //carrega imagem Logo inicial fixa
#include "imagem64.h" //verificar o nome da imagem no arquivo imagemxx.h 
                      //editar imagem no http://apps.pixlr.com/editor/

#pragma interrupt interrupcao
void interrupcao(){}

const rom unsigned char imagem[], imagem32[], imagem64[];

void main (void){
    unsigned char i;
        clock_int_48MHz();
	Init_GLCD();
        //Figuras iniciam do pixel (1,1) - *********plota imagem**********
        SetPos(1,1);
	SanDraw((rom char*)imagem64); //verificar o nome da imagem no arquivo imagemxx.h
        tempo_ms(1000);
        //ClearScreen(); //limpa tela (opcional)
        //*********fim plota imagem**********

        //******Escreve texto**********************
        //box(1,1,126,62);//plota caixa entre os 4 pontos x1,y1,x2,y2 (máx 126 e 62)
	//ASCII 22 (x16) is set position followed by x,y//\x16(constante para determinar escrita)
        //\x32 (ou seja 48 pixels) detrmina a coluna e \x08 (ou seja 08 pixels) determina a linha
	//PutMessage((rom char*)"\x16\x32\x08Grupo\x16\x32\x10SanUSB\n Titulo:\n Autor:\n Compilador:");//coluna 50 - linha 16
	//PutMessage((rom char*)"\x16\x32\x18LcdGrafico C18");//coluna 50 - linha 24
	PutMessage((rom char*)"\x16\x32\x20Grupo SanUSB");//coluna 50 - linha 32
	PutMessage((rom char*)"\x16\x40\x28MPLABX C18");//coluna 64 - linha 40
        tempo_ms(1000);
           
	while (1){inverte_saida(pin_b7); inverte_saida(pin_d7); tempo_ms(300);
                  if(!entrada_pin_e3){  ClearScreen();   //pino 1
                                        SanDraw((rom char*)imagem); //Logo
                                        tempo_ms(300);
                                        Reset();
                                        } //Estado de gravação via USB
                 }
}

