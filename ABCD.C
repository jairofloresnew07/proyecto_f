#include <stdio.h>
#include <conio.h>

int main() {
 clrscr();
 textcolor(CYAN);
 gotoxy(24,2); cprintf("---- Formato Paradise ----");
 gotoxy(10,4); cprintf("Bienvenido a formato paradise!, creado para adaptar tu uso en el");

 textcolor(WHITE);
 gotoxy(10,6); cprintf("Dentro de paradise encontraras 2 apartados, Inventario - Clientes");
 gotoxy(5,7); cprintf("Ten la dicha de agregar cualquier tipo de producto relacionado con Paradise");
 textcolor(LIGHTBLUE);
 gotoxy(28,8); cprintf("---- Condiciones ----");
 textcolor(RED);
 gotoxy(5,9); cprintf("Una cantidad no mayor a 100, un codigo valido(#0000) & un precio adecuado");
 textcolor(WHITE);
 gotoxy(8,10); cprintf("Con estos simples paso, sabras utilizar todo el campo de Inventario");
 gotoxy(5,12); cprintf("Agendate como cliente de Paradise para recibir una regalia de 100 creditos");
 gotoxy(5,13); cprintf("Si no eres cliente de paradise, no realizaras compras de Producto - Credito");
 textcolor(LIGHTBLUE);
 gotoxy(28,14); cprintf("---- Condiciones ----");
 textcolor(RED);
 gotoxy(9,15); cprintf("Agenda tu nombre, un codigo valido(#ABCD) & tu telefonia(########)");
 textcolor(WHITE);
 gotoxy(10,16); cprintf("Siendo cliente, accede a cualquier apartado que gustes realizar");
 gotoxy(20,18); cprintf("No te quedes sin adquirir tu membresia!");
 gotoxy(20,19); cprintf("Podras obtener descuentos en las compras");
 textcolor(LIGHTBLUE);
 gotoxy(32,20); cprintf("---- Tipos ----");
 textcolor(RED);
 gotoxy(29,21); cprintf("VIP   PREMIUM   ALPHA");
 textcolor(WHITE);
 gotoxy(29,22); cprintf(" 5%     15%      35%");
 textcolor(CYAN);
 gotoxy(31,24); cprintf("Esto es Paradise!");


 getch();
 clrscr();
 return 0;
}