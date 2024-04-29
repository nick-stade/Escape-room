#include "3draytracer.c"
#include "objects.c"
#include "graphics_assets.c"
#include "dialogue.c"
#include "2dPops.c"

int view = 0;
int locked = 1;

//return the object clicked
int click_to_intersect(double P[2]){
	double Rsource[3] = {0,0,0},Rtip[3] = {P[0] - 400,P[1] - 400,screenz};
	double dx,dy,dz;
	double points[num_objects][3],t[num_objects],tfinal;
	int closest;
	double nsource[3], ntip[3];
	tfinal = INFINITY; closest = -1;
	for(int i = 0; i < num_objects; i++){
		M3d_mat_mult_pt(nsource,obinv[i],Rsource);
		M3d_mat_mult_pt(ntip,obinv[i],Rtip);
		t[i] = intersect_ray_with_object(i,nsource,ntip,points[i]);
		if(t[i] < tfinal && t[i] != -1){tfinal = t[i];closest = i;}
	}
	return closest;
}

void dialogue(char text[][500], int numlines)
{
    int line_length;
    char key = 0;
    int swch = 1;
    G_rgb(0, 0, 0);
    G_fill_rectangle(250, 100, 300, 101);
    G_fill_circle(250, 150, 50);
    G_fill_circle(550, 150, 50);
    G_rgb(1, 1, 1);
    for (int i = 0; i < numlines; i++)
    {
        line_length = strlen(text[i]);
        G_draw_string(text[i], 400 - (3 * line_length), 140 + (10 * numlines) - (20 * i));
    }
    G_draw_string("(return)", 500, 110);
    double P[2];
    do{
    	G_wait_click(P);
    }while(P[0] < 200 || P[0] > 600 || P[1] < 100 || P[1] > 300);
}

void unlock_computer(){
	char password[] = "woodstock69";
	char entry;
	int success;
	int count;
	do{
		password_screen();
		success = 1;
		count = 0;
		do{
			entry = G_wait_key();
			if(entry == 27){return;}
			if(password[count] != entry && entry != 13){
				success = 0;
			}
			count++;
			G_rgb(0,1,0);
			G_fill_rectangle(343 + count*10,403,6,13);
		}while(entry != 13);
		if(count < 12){success = 0;}
		if(success != 1){}//failure
	}while(success != 1);
	locked = 0;
}

void unlock_keypad(){
    int combo[4] = {5,9,0,9};
    char entry;
    int success;
    do{
    	success = 1;
    	draw_keypad(12,4);
	    for(int j = 0; j < 4; j++){
	        entry = G_wait_key();
	        if(entry == 'q'){return;}
	        else if(combo[j] != entry - '0'){success = 0;}
	        G_fill_circle(280 + j*80,530,15);
	    }
	}while(success != 1);
    dialogue(win,1);
    for(int i = 0; i > -1;i++){combo[i] = 1;}
}

void greyify(){
	G_rgb(0,0,0);
	for(int i = 0; i < 800;i++){
		for(int j = 0; j< 800; j++){
			if(fmod(j+i,3) != 0){
				G_point(i,j);
			}
		}
	}
}

int main(){
	G_init_graphics(800,800);
	enum objects{floor,wallnegx,wallnegy,wallposy,wallposx,door,keypad,painting,
					bedfoot,bedside,bedtop,poster,nightstandfront,nightstandside,
					nightstandtop,lampbase,lampshade,bible,alarmclock,clock,bookshelf,
					bookside,deskdrawers,desktop,deskside1,deskside2,lapscreen,lapkeys,
					closet,closetside,globebase,globe};
	double P[2];
	char fname[100];
	init_maps();
	init_objects(0);
	int obj;
	display_txt(0);
	dialogue(start,1);
	display_txt(0);
	while(0==0){
		G_wait_click(P);
		if(P[0] > 700){
			view  = fmod(view+1,45);
			init_objects(view*8);
		}else if(P[0] <= 100){
			view = view-1;
			if(view == -1){view = 44;}
			init_objects(view*8);
		}else{
			obj = click_to_intersect(P);
			if(obj != -1){
				if(obj == keypad){
					greyify();
					unlock_keypad();
					G_wait_click(P);
				}else if(obj == door){
					dialogue(lockeddoor,1);
				}else if(obj == nightstandfront){
					greyify();
					nightstand_drawer();
					G_wait_click(P);
				}else if(obj == bible){
					greyify();
					open_bible();
					G_wait_click(P);
				}else if(obj == deskdrawers){
					greyify();
					desk_drawer(P);
					G_wait_click(P);
				}else if(obj == globe){
					greyify();
					draw_globe();
					G_wait_click(P);
				}else if(obj == lapscreen || obj == lapkeys){
					greyify();
					if(locked == 1){unlock_computer();}
					if(locked == 0){decoder_screen();G_wait_click(P);}
				}
			}
		}
		display_txt(view);
		// sprintf(fname,"images/%d.bmp",view);
		// G_display_bmp_file(fname,0,0);
	}
}