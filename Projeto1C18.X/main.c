/************************************************
* Compilador Multiplataforma MPLABX C18:
* https://dl.dropboxusercontent.com/u/101922388/BaixarMPLABX_C18.pdf*/

#include "SanUSB48.h" //Vídeo: http://www.youtube.com/watch?v=9inU3HIoy7o
#include "GLCD.h"
#include "imagem.h" // editar imagem no http://apps.pixlr.com/editor/

#pragma interrupt interrupcao
void interrupcao(){}

const rom unsigned char imagem[];

void main (void){
    unsigned char i;
        clock_int_48MHz();
	Init_GLCD();

        SetPos(1,1);
	SanDraw((rom char*)imagem);
        tempo_ms(2000);
        //ClearScreen();

        //box(1,1,126,62);//plota caixa entre os 4 pontos x1,y1,x2,y2 (máx 126 e 62)
	//ASCII 22 (x16) is set position followed by x,y//\x16(constante para determina escrita)
        //\x32 (ou seja 48 pixels) detrmina a coluna e \x08 (ou seja 08 pixels) determina a linha
	//PutMessage((rom char*)"\x16\x32\x08Grupo\x16\x32\x10SanUSB\n Titulo:\n Autor:\n Compilador:");//coluna 50 - linha 16
	PutMessage((rom char*)"\x16\x32\x18Lcd Grafico");//coluna 50 - linha 24
	PutMessage((rom char*)"\x16\x32\x20Grupo SanUSB");//coluna 50 - linha 32
	PutMessage((rom char*)"\x16\x40\x28MPLABX C18");//coluna 64 - linha 40
        tempo_ms(1000);
        //ClearScreen(); //*/

	while (1){inverte_saida(pin_b7); inverte_saida(pin_d7); tempo_ms(500);
                  if(!entrada_pin_e3){Reset();} //Estado de gravação via USB
                 }
}

