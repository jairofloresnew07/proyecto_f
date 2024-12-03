#include <graphics.h>
#include <mouse.h>

int main(){
int driver=DETECT,modo;
int click,limita,limitb,a=1,ma=0,r;
 initgraph(&driver,&modo,"C:\\tc20\\bin");
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 bar(1,1,639,479);

 setfillstyle(SOLID_FILL,BLUE);
 bar(232,222,260,316);
 bar(234,295,333,316);
 bar(306,254,333,316);
 bar(269,222,296,288);
 bar(269,222,368,245);
 bar(341,245,368,316);
 bar(341,294,404,316);
 bar(376,254,404,316);
 bar(376,222,404,245);

 setfillstyle(SOLID_FILL,WHITE);
 fillellipse(320,120,133,52);
 bar(1,1,139,479);
 bar(502,1,639,479);
 bar(180,350,300,390);
 bar(340,350,460,390);

 setcolor(BLACK);
 line(139,1,139,479);
 line(502,1,502,479);
 line(1,216,140,216);
 line(502,216,639,216);

 line(1,1,140,215);
 line(1,216,140,1);

 line(1,216,140,479);
 line(1,479,140,215);

 line(502,1,639,215);
 line(502,215,639,1);

 line(502,215,639,479);
 line(502,479,639,215);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(205,90,"PARADISE");

 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(200,360,"INICIAR");
 outtextxy(360,360,"SALIR");

 setcolor(LIGHTGRAY);
 circle(70,108,15);
 circle(70,346,15);
 circle(570,108,15);
 circle(570,346,15);
 setfillstyle(SOLID_FILL,BLACK);
 floodfill(70,108,LIGHTGRAY);
 floodfill(70,346,LIGHTGRAY);
 floodfill(570,108,LIGHTGRAY);
 floodfill(570,346,LIGHTGRAY);
 mver();
 while(a==1){
  click=mclick();
  limita=minlimit(1,180,350,300,390);
  limitb=minlimit(1,340,350,460,390);
   switch(click){

	case 0:
	 ma=0;
	 break;

	case 1:
	 ma=ma+1;

	 if(ma==1 && limita==1){
	  r=1;
	  goto entrada;
	 }

	 if(ma==1 && limitb==1){
	  r=0;
	  goto entrada;
	 }
	 break;
   }

 }
 entrada:
 closegraph();
 return 0;
}