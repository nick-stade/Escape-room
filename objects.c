int earthmap,wallmap,rugmap;
void init_maps(){
    enum objects{floor,wallnegx,wallnegy,wallposy,wallposx,door,keypad,painting,
                    bedfoot,bedside,bedtop,poster,nightstandfront,nightstandside,
                    nightstandtop,lampbase,lampshade,bible,alarmclock,clock,bookshelf,
                    bookside,deskdrawers,desktop,deskside1,deskside2,lapscreen,lapkeys,
                    closet,closetside,globebase,globe};

    //textures:
	obid[floor] = init_xwd_map_from_file ("textures/floorJ.xwd");
	obid[wallnegx] = init_xwd_map_from_file ("textures/wallJ.xwd") ;
    obid[wallnegy] = obid[wallnegx];
    obid[wallposy] = obid[wallnegx];
    obid[wallposx] = obid[wallnegx];
	obid[door] = init_xwd_map_from_file ("textures/doorJ.xwd") ;
    obid[closet] = init_xwd_map_from_file ("textures/closetJ.xwd") ;
    obid[bookshelf] = init_xwd_map_from_file ("textures/bookshelfJ.xwd") ;
    obid[keypad] = init_xwd_map_from_file ("textures/keypadJ.xwd") ;
    obid[poster] = init_xwd_map_from_file ("textures/posterJ.xwd") ;
    obid[painting] = init_xwd_map_from_file ("textures/paintingJ.xwd") ;
    obid[bible] = init_xwd_map_from_file ("textures/bibleJ.xwd") ;
    obid[alarmclock] = init_xwd_map_from_file ("textures/clockJ.xwd") ;
    obid[clock] = init_xwd_map_from_file ("textures/hashtagJ.xwd") ;
    obid[globe] = init_xwd_map_from_file ("textures/earthJ.xwd") ;
    obid[deskdrawers] = init_xwd_map_from_file ("textures/DrawerJ.xwd") ;
    int wood = init_xwd_map_from_file ("textures/WoodJ.xwd") ;
    obid[desktop] = wood;
    obid[deskside1] = wood;
    obid[deskside2] = wood;
    obid[desktop] = wood;
    obid[nightstandtop] = wood;
    obid[nightstandside] = wood;
    obid[nightstandfront] = obid[deskdrawers];
    obid[closetside] = wood;
    obid[bedfoot] = init_xwd_map_from_file("textures/bedfootJ.xwd");
    obid[bedside] = init_xwd_map_from_file("textures/bedsideJ.xwd");
    obid[bedtop] = init_xwd_map_from_file("textures/bedtopJ.xwd");
}
	

void init_objects(int t){
	double v[4][4], vi[4][4], eye[3], coi[3], up[3], vm[4][4];
    double Tvlist[100];
    int Tn, Ttypelist[100];
    double m[4][4], mi[4][4];
    double light[3] = {0,0,20};
    char fname[100];
    int frame;

	eye[0] = 4*cos(t*M_PI/180);
    eye[1] = 4*sin(t*M_PI/180);
    eye[2] = 17;

    coi[0] = 0;
    coi[1] = 0;
    coi[2] = 16;

    up[0] = 0;
    up[1] = 0;
    up[2] = 40;
    M3d_view(vm, vi, eye, coi, up);
    M3d_mat_mult_pt(light_in_eye_space,vm,light);
    num_objects = 0;

    //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0 ; // floor
      color[num_objects][0] = 0.7 ;
      color[num_objects][1] = 0.2 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects]  = -1;//init_xwd_map_from_file ("earthJ.xwd") ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  15   ; Tn++;


    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0 ; // wall1
      color[num_objects][0] = 0.8 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.0 ;
      //obid[num_objects] = -1;
      //obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  0   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -20   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //wall2
      color[num_objects][0] = 0.0 ;
      color[num_objects][1] = 0.8 ; 
      color[num_objects][2] = 0.0 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -20   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  0   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //wall3
      color[num_objects][0] = 0.0 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.8;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  0   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //wall4
      color[num_objects][0] = 0.8 ;
      color[num_objects][1] = 0.8 ; 
      color[num_objects][2] = 0.0 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  0   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  20   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0 ; // door
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
      //obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  13   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  6   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  13   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -11   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -19.9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0 ; // keypad
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
      //obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  1.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  12   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -3   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -19.9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0 ; // painting
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
      //obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  6   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  14   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  180   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  16   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -19.9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bedfoot
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  6   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  7   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -19.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  0   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bedside
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  6   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  270   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -12.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  10   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bed top
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  7   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  270   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  9   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -19.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  10   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //poster (with a clue)
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  6.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  4   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  270   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  17   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -19.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  6   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //front nightstand
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -8.9    ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  14.9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //side nightstand
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -5.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  17.83   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //nightstand top
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -8.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  17.83   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
       //////////////////////////////////////////////////////////////
      obtype[num_objects] = 2; //lamp base
      color[num_objects][0] = 0.2 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.4 ;
      obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  .5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  0.5   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  11.1   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -8.7   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  17.5   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
       //////////////////////////////////////////////////////////////
      obtype[num_objects] = 2; //lamp shade
      color[num_objects][0] = 0.5 ;
      color[num_objects][1] = 0.5 ; 
      color[num_objects][2] = 0.0 ;
      obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  13.1   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -8.7   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  17.5   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bible
      color[num_objects][0] = 0.6 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.6 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  0.7   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1.1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10.1   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -7.1   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  16.6   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //Alarm clock
      color[num_objects][0] = 0.0 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.0 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  .5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1.1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10.5   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -9.8    ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  15.4   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 1; //Clock
      color[num_objects][0] = 0.7 ;
      color[num_objects][1] = 0.7 ; 
      color[num_objects][2] = 0.7 ;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  0.1   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  2.5   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  2.5   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  180   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  22   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  -13    ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  19   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bookshelf
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  15   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  16.7   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //bookshelf side
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  15   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1.8   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  0   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  18.45   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //desk drawers
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  3.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  2.5   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  14.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  3   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //desktop
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.2 ; 
      color[num_objects][2] = 0.2;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  6   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  5   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  6.5   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  19.9   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  6.5   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //desk sides
      color[num_objects][0] = 0.2 ;
      color[num_objects][1] = 0.4 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  3.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  3.1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  18   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  0.5   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //desk sides
      color[num_objects][0] = 0.2 ;
      color[num_objects][1] = 0.4 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  3.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  3.1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  3   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  18   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  12.5   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //laptop screen
      color[num_objects][0] = 0.2 ;
      color[num_objects][1] = 0.2 ; 
      color[num_objects][2] = 0.2;
      obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  1.5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  2   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  7   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  18.5   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //laptop keyboard
      color[num_objects][0] = 0.3 ;
      color[num_objects][1] = 0.3 ; 
      color[num_objects][2] = 0.3;
      obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  1.4   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  2   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = RX ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  6.6   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  17   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  9   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //closet
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  8   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  16   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -11   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 0; //closet side
      color[num_objects][0] = 0.4 ;
      color[num_objects][1] = 0.0 ; 
      color[num_objects][2] = 0.2 ;
      //obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  2   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  -90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  10   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  18   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  -3  ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
       //////////////////////////////////////////////////////////////
      obtype[num_objects] = 2; //globe base
      color[num_objects][0] = 0.3 ;
      color[num_objects][1] = 0.3 ; 
      color[num_objects][2] = 0.3;
      obid[num_objects] = -1;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  .5   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  0.5   ; Tn++ ;
      Ttypelist[Tn] = RZ ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = RY ; Tvlist[Tn] =  90   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  7   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  17   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  3   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////
      obtype[num_objects] = 1; //globe
      color[num_objects][0] = 0.3 ;
      color[num_objects][1] = 0.3 ; 
      color[num_objects][2] = 0.3;
    
      Tn = 0 ;
      Ttypelist[Tn] = SX ; Tvlist[Tn] =  1.3   ; Tn++ ;
      Ttypelist[Tn] = SY ; Tvlist[Tn] =  1.3   ; Tn++ ;
      Ttypelist[Tn] = SZ ; Tvlist[Tn] =  1.3   ; Tn++ ;
      Ttypelist[Tn] = TZ ; Tvlist[Tn] =  8.5   ; Tn++ ;
      Ttypelist[Tn] = TY ; Tvlist[Tn] =  17   ; Tn++ ;
      Ttypelist[Tn] = TX ; Tvlist[Tn] =  3   ; Tn++ ;

    
      M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
      M3d_mat_mult(obmat[num_objects], vm, m) ;
      M3d_mat_mult(obinv[num_objects], mi, vi) ;

      num_objects++ ; // don't forget to do this

      //////////////////////////////////////////////////////////////


}




































