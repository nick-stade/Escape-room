#include "3draytracer.c"
double obmat[100][4][4];
double obinv[100][4][4];
double color[100][3];
int num_objects;
int obtype[100]; // 0 line segment, 1 circle, 2 hyperbola
int obid[100];   // -1 for no id
#include "objects.c"


int main()
{
    double v[4][4], vi[4][4], eye[3], coi[3], up[3], vm[4][4];
    double Tvlist[100];
    int Tn, Ttypelist[100];
    double m[4][4], mi[4][4];
    light_in_eye_space[0] = 0;
    light_in_eye_space[1] = 0;
    light_in_eye_space[2] = 10;
    char fname[100];
    int frame;
    init_maps();
    for(int t = 0; t < 360; t += 8){
        init_objects(t);
        frame = t/8;
        draw_txt(frame);
    }
}