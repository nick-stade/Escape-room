void draw_keypad(int i, int j){
	G_rgb(.4,.4,.4);
	G_fill_rectangle(j*50, 800-(i+1)*50, 400, 500);
	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+5, 800-(i+1)*50+5, 390, 490);

	G_rgb(.8,.2,.2);
	G_fill_rectangle(j*50+90, 800-(i+1)*50+30, 60, 60);
	G_rgb(.9,.3,.3);
	G_fill_rectangle(j*50+95, 800-(i+1)*50+35, 50, 50);
	G_rgb(0,0,0);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+30, 60, 60);
	G_rgb(.2,.8,.2);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+30, 60, 60);
	G_rgb(.3,.9,.3);
	G_fill_rectangle(j*50+255, 800-(i+1)*50+35, 50, 50);

	G_rgb(0,0,0);
	G_fill_rectangle(j*50+90, 800-(i+1)*50+110, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+110, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+110, 60, 60);

	G_fill_rectangle(j*50+90, 800-(i+1)*50+190, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+190, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+190, 60, 60);

	G_fill_rectangle(j*50+90, 800-(i+1)*50+270, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+270, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+270, 60, 60);

	G_fill_rectangle(j*50+50, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+130, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+210, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+290, 800-(i+1)*50+350, 60, 60);

	G_fill_rectangle(j*50+130, 800-(i+1)*50+445, 140, 20);


	G_rgb(1,1,1);
	G_draw_string("0",j*50+195, 800-(i+1)*50+55);

	G_draw_string("7",j*50+115, 800-(i+1)*50+135);
	G_draw_string("8",j*50+195, 800-(i+1)*50+135);
	G_draw_string("9",j*50+275, 800-(i+1)*50+135);

	G_draw_string("4",j*50+115, 800-(i+1)*50+215);
	G_draw_string("5",j*50+195, 800-(i+1)*50+215);
	G_draw_string("6",j*50+275, 800-(i+1)*50+215);

	G_draw_string("1",j*50+115, 800-(i+1)*50+295);
	G_draw_string("2",j*50+195, 800-(i+1)*50+295);
	G_draw_string("3",j*50+275, 800-(i+1)*50+295);

	G_rgb(1,1,1); G_draw_string("EXIT",335,600);
    G_rgb(0,0,0); G_fill_rectangle(350,120,80,20);
    G_rgb(1,1,1); G_draw_string("'q' to quit",355,125);

}

void display_txt(int frame){
	FILE *file;
	char fname[100];
	double rgb[3];
	sprintf(fname,"images/%d.txt",frame);
	file = fopen(fname,"r");
	for(int i = 0;i< 800;i++){
		for(int j = 0; j < 800; j++){
			fscanf(file,"%lf%lf%lf",&rgb[0],&rgb[1],&rgb[2]);
			G_rgb(rgb[0],rgb[1],rgb[2]);
			G_point(i,j);
		}
	}
	fclose(file);
}