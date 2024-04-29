#include "FPToolkit.c"


void nightstand_drawer(){

      G_rgb(.7,.55,.36);
      G_fill_rectangle(150,250,500,320);
      G_fill_rectangle(110,550,580,250);
      G_rgb(.8,.64,.42);
      G_fill_rectangle(170,270,460,280);
      G_rgb(0,0,0);
      G_fill_rectangle(390,230,20,20);
      G_fill_circle(400,228,15);
      G_fill_rectangle(160, 600, 140,80);
      G_rgb(.3,.3,.3);
      G_fill_rectangle(190,610,80,20);
      G_rgb(0.8,.8,0);
      G_fill_circle(360,780,120);
      G_rgb(.45,.33,.14);
      G_fill_rectangle(530,610,100,160);
      G_rgb(.9,.9,.9);
      G_fill_rectangle(525,615,100,160);
      G_rgb(.45,.33,.14);
      G_fill_rectangle(520,620,100,160);
      G_rgb(0.98,.8,.33);
      G_fill_rectangle(567.5,690,6,60);
      G_fill_rectangle(550,728,41,6);

      G_rgb(1,1,1);
      G_fill_rectangle(298,420,44,10);
      G_rgb(1,.75,.25);
      G_fill_rectangle(302,345,36,75);
      G_rgb(1,1,1);
      G_fill_rectangle(302,360,36,45);

      G_rgb(0,0,0);
      G_draw_string("CAT", 315,380);

      G_rgb(.1,.1,.1);
      G_fill_rectangle(440,400,60,90);
      G_fill_rectangle(450,490,40,10);
      G_fill_rectangle(450,390,40,10);
      G_fill_circle(450,489,10);
      G_fill_circle(450,400,10);
      G_fill_circle(489,489,10);
      G_fill_circle(489,400,10);

      G_rgb(.3,.3,.3);
      G_fill_rectangle(445,405,50,80);
      G_circle(470,397.5,6);

      G_rgb(.95,.95,.95);
      G_draw_string("@@:@@",455,465);



}
void open_bible(){

	G_rgb(.45,.33,.14);
	G_fill_rectangle(170,290,460,280);
	G_rgb(.35,.23,.04);
	G_fill_rectangle(386,290,30,280);
	G_rgb(.95,.95,.95);
	G_fill_rectangle(185,300,430,260);
	G_rgb(.9,.9,.9);
	G_fill_rectangle(381,300,40,260);
	G_rgb(.4,.4,.4);
	G_line(400,300, 400, 560);


	G_rgb(1,1,.5);
	G_fill_rectangle(460, 380, 120, 80);
	G_fill_rectangle(460, 350, 90, 30);

	G_rgb(.98,.98,.48);
	G_fill_rectangle(460, 460, 120, 20);

	G_rgb(.92,.92,.42);
	G_fill_triangle(550, 350, 550, 380, 580, 380);

	G_rgb(.8,0,.3);
	G_draw_string("%", 520, 420);

}

void draw_globe(){

	G_rgb(0,0,.5);
	G_fill_circle(400,400,200);
	G_rgb(.3,.3,.3);
	G_fill_circle(400,400,120);

	G_rgb(1,1,1);
	G_line(400,390,400,410);
	G_line(390,400,410,400);
	
}

void desk_drawer(){

	G_rgb(.7,.55,.36);
	G_fill_rectangle(150,250,500,320);
	G_fill_rectangle(0,550,690,250);
	G_rgb(.8,.64,.42);
	G_fill_rectangle(170,270,460,280);
	G_rgb(0,0,0);
	G_fill_rectangle(390,230,20,20);
	G_fill_circle(400,228,15);
	G_rgb(.3,.3,.3);
	G_fill_rectangle(0,650,60,150);
	G_rgb(0,0,.5);
	G_fill_circle(400,750,120);

	G_rgb(.925,1,.74);
	G_fill_rectangle(320,400,160,70);
	G_rgb(.45,.6,.45);
	G_fill_rectangle(323,403,154,64);
	G_rgb(.925,1,.74);
	G_fill_rectangle(335,410,130,50);
	G_rgb(.45,.6,.45);
	G_fill_circle(335,456,10);
	G_fill_circle(335,413,10);
	G_fill_circle(465,456,10);
	G_fill_circle(465,413,10);

	G_fill_circle(400,425,20);

	G_rgb(.925,1,.74);
	G_draw_string("1",334,451);
	G_draw_string("1",334,409);
	G_draw_string("1",463,451);
	G_draw_string("1",463,409);

	G_rgb(0,0,0);
	G_draw_string("DOG",423,435);

	G_rgb(.7,.7,.7);
	G_fill_rectangle(504,306,80,110);
	G_rgb(.2,.2,.2);
	G_rectangle(504,306,80,110);
	G_rgb(.8,.8,.8);
	G_fill_rectangle(500,310,80,110);
	G_rgb(.2,.2,.2);
	G_rectangle(500,310,80,110);
	G_rgb(1,1,1);
	G_fill_rectangle(508,388,64,19);
	G_rgb(.2,.2,.2);
	G_fill_rectangle(510,390,60,15);

	G_rgb(.2,.2,.2);
	G_rectangle(505,316,69,69);
	G_rgb(.95,.95,.95);
	G_fill_rectangle(509,319,14.5,14.5);
	G_fill_rectangle(525.5,319,14.5,14.5);
	G_fill_rectangle(541,319,14.5,14.5);
	G_fill_rectangle(557.5,319,14.5,14.5);

	G_fill_rectangle(509,335.5,14.5,14.5);
	G_fill_rectangle(525.5,335.5,14.5,14.5);
	G_fill_rectangle(541,335.5,14.5,14.5);
	G_fill_rectangle(557.5,335.5,14.5,14.5);

	G_fill_rectangle(509,351,14.5,14.5);
	G_fill_rectangle(525.5,351,14.5,14.5);
	G_fill_rectangle(541,351,14.5,14.5);
	G_fill_rectangle(557.5,351,14.5,14.5);

	G_fill_rectangle(509,367.5,14.5,14.5);
	G_fill_rectangle(525.5,367.5,14.5,14.5);
	G_fill_rectangle(541,367.5,14.5,14.5);
	G_fill_rectangle(557.5,367.5,14.5,14.5);

	G_rgb(.2,.2,.2);
	G_rectangle(509,319,14.5,14.5);
	G_rectangle(525.5,319,14.5,14.5);
	G_rectangle(541,319,14.5,14.5);
	G_rectangle(557.5,319,14.5,14.5);

	G_rectangle(509,335.5,14.5,14.5);
	G_rectangle(525.5,335.5,14.5,14.5);
	G_rectangle(541,335.5,14.5,14.5);
	G_rectangle(557.5,335.5,14.5,14.5);

	G_rectangle(509,351,14.5,14.5);
	G_rectangle(525.5,351,14.5,14.5);
	G_rectangle(541,351,14.5,14.5);
	G_rectangle(557.5,351,14.5,14.5);

	G_rectangle(509,367.5,14.5,14.5);
	G_rectangle(525.5,367.5,14.5,14.5);
	G_rectangle(541,367.5,14.5,14.5);
	G_rectangle(557.5,367.5,14.5,14.5);

	G_rgb(.95,.95,.95);
	G_draw_string("& & & &", 520,392);




}

void password_screen(){

	double x[4], y[4];

	G_rgb(.5,.5,.5);
	G_fill_rectangle(170,290,460,280);
	G_rgb(0,0,0);
	G_fill_rectangle(185,300,430,260);

	x[0] = 170 ; x[3] = 150 ; x[1] = 630 ; x[2] = 650 ;
	y[0] = 290 ; y[3] = 180 ; y[1] = 290 ; y[2] = 180 ;
	G_rgb(.45,.45,.45);
	G_fill_polygon(x,y,4);

	G_rgb(0,0,0);
	G_line(180, 200, 620, 200);
	G_line(183, 214, 617, 214);
	G_line(186, 228, 614, 228);
	G_line(189, 242, 611, 242);
	G_line(192, 256, 608, 256);
	G_line(195, 270, 605, 270);

	G_rgb(0,1,0);
	G_rectangle(340,400,122,20);
	G_fill_rectangle(343,403,6,13);
	G_draw_string("Enter Password :",353,435);

}

void decoder_screen(){

	double x[4], y[4];

	G_rgb(.5,.5,.5);
	G_fill_rectangle(170,290,460,280);
	G_rgb(0,0,0);
	G_fill_rectangle(185,300,430,260);

	x[0] = 170 ; x[3] = 150 ; x[1] = 630 ; x[2] = 650 ;
	y[0] = 290 ; y[3] = 180 ; y[1] = 290 ; y[2] = 180 ;
	G_rgb(.45,.45,.45);
	G_fill_polygon(x,y,4);

	G_rgb(0,0,0);
	G_line(180, 200, 620, 200);
	G_line(183, 214, 617, 214);
	G_line(186, 228, 614, 228);
	G_line(189, 242, 611, 242);
	G_line(192, 256, 608, 256);
	G_line(195, 270, 605, 270);

	G_rgb(0,1,0);
	G_rectangle(375,510,50,20);
	G_draw_string("CAT",392,514);

	G_draw_string("! = 3  @ = 9  # = 2  $ = 4  % = 0  ^ = 6  & = 1  * = 5  + = 7  ? = 8",197,460);

	G_rectangle(375,400,50,20);
	G_draw_string("DOG",392,404);

	G_draw_string("! = 6  @ = 1  # = 0  $ = 3  % = 5  ^ = 8  & = 2  * = 7  + = 9  ? = 4",197,350);
}






