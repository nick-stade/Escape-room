#include "FPToolkit.c"
#include "M3d_matrix_tools.c"
#include "xwd_tools_03.c"


double obmat[100][4][4] ;
double obinv[100][4][4] ;
double color[100][3] ;
int    num_objects ;
int    obtype[100] ; // 0 line segment, 1 circle, 2 hyperbola
int    obid[100]; // -1 for no id
int reflections;
int MAX_REFLECTIONS = 2;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// To support the light model :
double light_in_eye_space[3] ;
double AMBIENT      = 0.2 ;
double MAX_DIFFUSE  = 0.5 ;
double SPECPOW      = 100 ;



int Light_Model (double irgb[3],
                 double s[3],
                 double p[3],
                 double n[3],
                 double argb[3])
// s,p,n in eyespace

// irgb == inherent color of object (input to this function)
// s = location of start of ray (probably the eye)
// p = point on object (input to this function)
// n = normal to the object at p (input to this function)
// argb == actual color of object (output of this function)
// globals : AMBIENT, MAX_DIFFUSE, SPECPOW, light_in_eye_space[3]

// return 1 if successful, 0 if error
{

  double len ;
  double N[3] ; 
  len = sqrt(n[0]*n[0] + n[1]*n[1] + n[2]*n[2]) ;
  if (len == 0) return 0 ;
  N[0] = n[0]/len ;  N[1] = n[1]/len ;  N[2] = n[2]/len ;

  double E[3] ;
  E[0] = s[0] - p[0] ; 
  E[1] = s[1] - p[1] ; 
  E[2] = s[2] - p[2] ; 
  len = sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]) ;
  if (len == 0) return 0 ;
  E[0] /= len ;  E[1] /= len ;  E[2] /= len ;
  double NdotE = N[0]*E[0] + N[1]*E[1] + N[2]*E[2] ;

  double L[3] ;
  L[0] = light_in_eye_space[0] - p[0] ; 
  L[1] = light_in_eye_space[1] - p[1] ; 
  L[2] = light_in_eye_space[2] - p[2] ; 
  len = sqrt(L[0]*L[0] + L[1]*L[1] + L[2]*L[2]) ;
  if (len == 0) return 0 ;
  L[0] /= len ;  L[1] /= len ;  L[2] /= len ;
  double NdotL = N[0]*L[0] + N[1]*L[1] + N[2]*L[2] ;





  double max_ambient_and_diffuse = AMBIENT + MAX_DIFFUSE ;
     // this needs to occur BEFORE you possibly jump to LLL below




  double intensity ;
  if (NdotL*NdotE < 0) {
    // eye and light are on opposite sides of polygon
    intensity = AMBIENT ; 
    goto LLL ;
  } else if ((NdotL < 0) && (NdotE < 0)) {
    // eye and light on same side but normal pointing "wrong" way
    N[0] *= (-1.0) ;    N[1] *= (-1.0) ;    N[2] *= (-1.0) ; 
    NdotL *= (-1.0) ;
    NdotE *= (-1.0) ;   // don't use NdotE below, probably should eliminate this
  }


  // ignore Blinn's variant
  double R[3] ; // Reflection vector of incoming light
  R[0] = 2*NdotL*N[0] - L[0] ;
  R[1] = 2*NdotL*N[1] - L[1] ;
  R[2] = 2*NdotL*N[2] - L[2] ;

  double EdotR = E[0]*R[0] + E[1]*R[1] + E[2]*R[2] ;

  double diffuse ;
  if (NdotL <= 0.0) { diffuse = 0.0 ; }
  else { diffuse = MAX_DIFFUSE*NdotL ; }

  double specular ;
  if (EdotR <= 0.0) { specular = 0.0 ; }
  else { specular = (1.0 - max_ambient_and_diffuse)*pow(EdotR,SPECPOW) ;}

  // printf("%lf %lf\n",diffuse,specular) ;
  intensity = AMBIENT + diffuse + specular ;



 LLL : ;

  double f,g ;
  if (intensity <= max_ambient_and_diffuse) {
    f = intensity / max_ambient_and_diffuse ;
    argb[0] = f * irgb[0] ;
    argb[1] = f * irgb[1] ;
    argb[2] = f * irgb[2] ;
  } else {
    f = (intensity - max_ambient_and_diffuse) / 
                           (1.0 - max_ambient_and_diffuse) ;
    g = 1.0 - f ;
    argb[0] = g * irgb[0] + f ;
    argb[1] = g * irgb[1] + f ;
    argb[2] = g * irgb[2] + f ;
  }

  return 1 ;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int quadratic(double a, double b, double c, double result[2])
// return number of solutions
{
  int n ;
  double d,ta ;

  d = b*b - 4*a*c ;

  if (d < 0) {
     n = 0 ;  
  } else if (d == 0) {
     ta = 2*a ;
     result[0] = -b / ta ;
     n = 1 ;
  } else {
     d = sqrt(d) ;
     ta = 2*a ;
     result[0] = (-b + d) / ta ;
     result[1] = (-b - d) / ta ;
     n = 2 ;
  }

  return n ;
}

void normal_usphere( int onum,double result[],double obpt[]){
  double dzdx,dzdy,dzdz,dzdp[3];
  dzdx = 2*obpt[0]; dzdy = 2*obpt[1]; dzdz = 2*obpt[2];
  dzdp[0] = obinv[onum][0][0]*dzdx + obinv[onum][1][0]*dzdy + obinv[onum][2][0]*dzdz;
  dzdp[1] = obinv[onum][0][1]*dzdx + obinv[onum][1][1]*dzdy + obinv[onum][2][1]*dzdz;
  dzdp[2] = obinv[onum][0][2]*dzdx + obinv[onum][1][2]*dzdy + obinv[onum][2][2]*dzdz;
  M3d_normalize(dzdp,dzdp);
  result[0] = dzdp[0];
  result[1] = dzdp[1];
  result[2] = dzdp[2];
}

void normal_plane( int onum,double result[],double obpt[]){
  // double dzdx,dzdy,dzdz,dzdp[3];
  // dzdx = 1; dzdy = 1; dzdz = 0;
  // dzdp[0] = obinv[onum][0][0]*dzdx + obinv[onum][1][0]*dzdy + obinv[onum][2][0]*dzdz;
  // dzdp[1] = obinv[onum][0][1]*dzdx + obinv[onum][1][1]*dzdy + obinv[onum][2][1]*dzdz;
  // dzdp[2] = obinv[onum][0][2]*dzdx + obinv[onum][1][2]*dzdy + obinv[onum][2][2]*dzdz;
  // M3d_normalize(dzdp,dzdp);
  // result[0] = dzdp[0];
  // result[1] = dzdp[1];
  // result[2] = dzdp[2];
  result[0] = 0;
  result[1] = 0;
  result[2] = 1;
  M3d_mat_mult_pt(result,obmat[onum],result);
}

void normal_hyperboloid( int onum,double result[],double obpt[]){
  double dzdx,dzdy,dzdz,dzdp[3];
  dzdx = 2*obpt[0]; dzdy = -2*obpt[1]; dzdz = 2*obpt[2];
  dzdp[0] = obinv[onum][0][0]*dzdx + obinv[onum][1][0]*dzdy + obinv[onum][2][0]*dzdz;
  dzdp[1] = obinv[onum][0][1]*dzdx + obinv[onum][1][1]*dzdy + obinv[onum][2][1]*dzdz;
  dzdp[2] = obinv[onum][0][2]*dzdx + obinv[onum][1][2]*dzdy + obinv[onum][2][2]*dzdz;
  M3d_normalize(dzdp,dzdp);
  result[0] = dzdp[0];
  result[1] = dzdp[1];
  result[2] = dzdp[2];
}

int normal(int objnum, double normal[3],double point[]) 
{
  if(obtype[objnum] == 1){
    normal_usphere(objnum,normal,point);
  }else if(obtype[objnum] == 2){
    normal_hyperboloid(objnum,normal,point);
  }else if(obtype[objnum] == 0){
    normal_plane(objnum,normal,point);
  }
}

double intersect_usphere(double S[3], double T[3], double pt[3]){
  double a,b,c,x,y,dx,dy,dz;
  dx = T[0] - S[0];
  dy = T[1] - S[1];
  dz = T[2] - S[2];
  a = pow(dx,2) + pow(dy,2) + pow(dz,2);
  b = 2*S[0]*dx + 2*S[1]*dy + 2*S[2]*dz;
  c = pow(S[0],2) + pow(S[1],2) + pow(S[2],2) - 1;
  double solns[2];
  int num_solns = quadratic(a,b,c,solns);
  if(num_solns == 0 || 
    (num_solns == 1 && solns[0] < 0) ||
    (num_solns == 2 && solns[0] < 0 && solns[1] < 0)){
    return -1;
  }else if(num_solns == 1 || (num_solns == 2 && solns[0] < solns[1]) || solns[1] < 0){
    pt[0] = S[0] + solns[0]*dx;
    pt[1] = S[1] + solns[0]*dy;
    pt[2] = S[2] + solns[0]*dz;
    return solns[0];
  }else{
    pt[0] = S[0] + solns[1]*dx;
    pt[1] = S[1] + solns[1]*dy;
    pt[2] = S[2] + solns[1]*dz;
    return solns[1];
  }
}

double intersect_plane(double S[], double T[], double res[]){
  double dx,dy,dz,t,x,y;
  dx = T[0] - S[0];
  dy = T[1] - S[1];
  dz = T[2] - S[2];
  if(dz == 0){return -1;}
  t = -S[2]/dz;
  x = S[0] + t*dx;
  y = S[1] + t*dy;
  if(x > 1 || x < -1 || y > 1 || y < -1 || t < 0){return -1;}
  res[0] = x;
  res[1] = y;
  res[2] = 0;
  return t;
}

double intersect_hyperboloid(double S[],double T[],double res[]){
  double a,b,c,x,y,z,dx,dy,dz,temp,yshort,ylong;
  dx = T[0] - S[0];
  dy = T[1] - S[1];
  dz = T[2] - S[2];
  a = pow(dx,2) - pow(dy,2) + pow(dz,2);
  b = 2*S[0]*dx - 2*S[1]*dy + 2*S[2]*dz ;
  c = pow(S[0],2) - pow(S[1],2) + pow(S[2],2) - 1;
  double solns[2];
  int num_solns = quadratic(a,b,c,solns);
  if(num_solns == 0){
    return -1;
  }else if(num_solns == 1){
    x = S[0] + solns[0]*dx;
    y = S[1] + solns[0]*dy;
    z = S[2] + solns[0]*dz;
    if(y > 1 || y < -1){
      return -1;
    }
    res[0] = x;
    res[1] = y;
    res[2] = z;
    return solns[0];
  }else if(num_solns == 2){
    if(solns[1] < solns[0]){
      temp = solns[0];
      solns[0] = solns[1];
      solns[1] = temp;
      yshort = S[1] + solns[0]*dy;
      ylong = S[1] + solns[1]*dy;
    }
    if(yshort<=1 && yshort>=-1){
      x = S[0] + solns[0]*dx;
      y = S[1] + solns[0]*dy;
      z = S[2] + solns[0]*dz;
      res[0] = x;
      res[1] = y;
      res[2] = z;
      if(y > 1 || y < -1){return -1;}
      return solns[0];
    }else if(ylong<=1 && ylong>=-1){
      x = S[0] + solns[1]*dx;
      y = S[1] + solns[1]*dy;
      z = S[2] + solns[1]*dz;
      res[0] = x;
      res[1] = y;
      res[2] = z;
      if(y > 1 || y < -1){return -1;}
      return solns[1];
    }else{return -1;}
  }
}

double intersect_ray_with_object(int objnum, double source[], double tip[], double res[]) 
{
  double S[3], T[3];
  M3d_mat_mult_pt(S,obinv[objnum],source);
  M3d_mat_mult_pt(T,obinv[objnum],tip);
  if(obtype[objnum] == 1){
    return intersect_usphere(S,T,res);
  }else if(obtype[objnum] == 2){
    return intersect_hyperboloid(S,T,res);
  }else if(obtype[objnum] == 0){
    return intersect_plane(S,T,res);
  }
}

void map_plane(double pt[3],double uv[2]){
  uv[0] = (pt[0] + 1)/2;
  uv[1] = (pt[1] + 1)/2;
}

void map_sphere(double pt[3],double uv[2]){
  double r = sqrt(pow(pt[0],2) + pow(pt[1],2) + pow(pt[2],2));\
  uv[0] = atan2(pt[0],pt[2])/(2*M_PI) + .5;
  uv[1] = asin(pt[1])/M_PI + .5;
}

void map_hyperboloid(double pt[3],double uv[2]){}

//take x y z , obnum,  stores in argb
void color_object(double pt[3], int onum, double argb[3]){
  double uv[2];//convert xyz to 1,1 uv map
  if(obid[onum] == -1){
    argb[0] = color[onum][0];
    argb[1] = color[onum][1];
    argb[2] = color[onum][2];
    return;
  }else if(obtype[onum] == 0){
    map_plane(pt,uv);
  }else if(obtype[onum] == 1){
    map_sphere(pt,uv);
  }else if(obtype[onum] == 2){
    map_hyperboloid(pt,uv);
  }
  int ud,vd;
  int e,d[2] ;
  int width,height ;
  e = get_xwd_map_dimensions(obid[onum], d) ;
  if (e == -1) { printf("failure1 %d\n",onum) ;  exit(0) ; }
  width = d[0] - 1 ; height = d[1] - 1;
  ud = (int)(uv[0]*width);
  vd = (int)(uv[1]*height);
  e = get_xwd_map_color(obid[onum], ud,vd,argb) ; // returns -1 on error, 1 if ok
  if (e == -1) { printf("failure2 %d\n",onum) ;  exit(0) ; }
}

void reflect(double S[], double T[], double Nu[],double NS[], double NT[]){
  double Ru[3], Vu[3];
  Vu[0] = T[0] - S[0]; Vu[1] = T[1] - S[1]; Vu[2] = T[2] - S[2];
  M3d_normalize(Vu,Vu);
  M3d_normalize(Nu,Nu);
  Vu[0] = -Vu[0]; Vu[1] = -Vu[1]; Vu[2] = -Vu[2];
  double h = M3d_dot(Vu,Nu); //printf("%lf\n",h);
  Ru[0] = 2*h*Nu[0] - Vu[0];
  Ru[1] = 2*h*Nu[1] - Vu[1];
  Ru[2] = 2*h*Nu[2] - Vu[2];
  NS[0] = T[0] + .01*Ru[0];
  NS[1] = T[1] + .01*Ru[1];
  NS[2] = T[2] + .01*Ru[2];
  NT[0] = T[0] + Ru[0];
  NT[1] = T[1] + Ru[1];
  NT[2] = T[2] + Ru[2];
  // printf("Vu (l:%lf) = (%lf,%lf,%lf)\nRu (l:%lf) = (%lf,%lf,%lf)\nNu (l:%lf) = (%lf,%lf,%lf)\n\n",
  //         sqrt(pow(Vu[0],2) + pow(Vu[1],2) + pow(Vu[2],2)),
  //         Vu[0],Vu[1],Vu[2],
  //         sqrt(pow(Ru[0],2) + pow(Ru[1],2) + pow(Ru[2],2)),
  //         Ru[0],Ru[1],Ru[2],
  //         sqrt(pow(Nu[0],2) + pow(Nu[1],2) + pow(Nu[2],2)),
  //         Nu[0],Nu[1],Nu[2]);
  reflections++;
}

//for now only intersecting one object
int ray (double Rsource[3], double Rtip[3], 
         double argb[3]) 
{
  double points[num_objects][3],t[num_objects],tfinal;
  int closest;
  tfinal = INFINITY; closest = -1;
  for(int i = 0; i < num_objects; i++){
    t[i] = intersect_ray_with_object(i,Rsource,Rtip,points[i]);
    if(t[i] < tfinal && t[i] != -1){tfinal = t[i];closest = i;}
  }

  double vnormal[3] = {0,0,0};
  double rgb[3] = {0,0,0};
  if(closest != -1){
    double point[3] = {points[closest][0],points[closest][1],points[closest][2]};
    color_object(point,closest,rgb);
    normal(closest,vnormal,point);
    M3d_mat_mult_pt(point,obmat[closest],point);
    if(obid[closest] == -1 && reflections < MAX_REFLECTIONS){
      double NT[3], NS[3];
      reflect(Rsource,point,vnormal,NS,NT);
      ray(NS,NT,argb);
      argb[0] = argb[0]*.8 + rgb[0]*.2;
      argb[1] = argb[1]*.8 + rgb[1]*.2;
      argb[2] = argb[2]*.8 + rgb[2]*.2;
      Light_Model(argb,Rsource,point,vnormal,argb);
    }else{
      Light_Model(rgb,Rsource,point,vnormal,argb);
    }
  }
} // end ray

void ray_recurse(double Rsource[3], double Rtip[3], double argb[3]){
  argb[0] = 0; argb[1] = 0; argb[2] = 0;
  reflections = 0;
  ray(Rsource,Rtip,argb);
}


int test01()
{
  double vm[4][4], vi[4][4];
  double Tvlist[100];
  int Tn, Ttypelist[100];
  double m[4][4], mi[4][4];
  double Rsource[3];
  double Rtip[3];
  double argb[3] ;

    //////////////////////////////////////////////////////////////////////
    M3d_make_identity(vm) ;    M3d_make_identity(vi) ; // OVERRIDE for 2d
    //////////////////////////////////////////////////////////////////////

    num_objects = 0 ;

    /////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
    obtype[num_objects] = 1 ; // sphere
    // color[num_objects][0] = 0.8 ;
    // color[num_objects][1] = 0.0 ; 
    // color[num_objects][2] = 0.0 ;
    // obid[num_objects] = -1;
    obid[num_objects]  = init_xwd_map_from_file ("earthJ.xwd") ;
	
    Tn = 0 ;
    Ttypelist[Tn] = SX ; Tvlist[Tn] =  10   ; Tn++ ;
    Ttypelist[Tn] = SY ; Tvlist[Tn] =  10   ; Tn++ ;
    Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++;
    Ttypelist[Tn] = RX ; Tvlist[Tn] =  -45   ; Tn++ ;
    Ttypelist[Tn] = TZ ; Tvlist[Tn] =  40   ; Tn++ ;
    Ttypelist[Tn] = TX ; Tvlist[Tn] =  -20   ; Tn++ ;


	
    M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
    M3d_mat_mult(obmat[num_objects], vm, m) ;
    M3d_mat_mult(obinv[num_objects], mi, vi) ;

    num_objects++ ; // don't forget to do this

    //////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
    obtype[num_objects] = 1 ; // sphere
    color[num_objects][0] = 0.0 ;
    color[num_objects][1] = 0.8 ; 
    color[num_objects][2] = 0.8 ;
    obid[num_objects] = -1;
    //obid[num_objects]  = init_xwd_map_from_file ("earthJ.xwd") ;
  
    Tn = 0 ;
    Ttypelist[Tn] = SX ; Tvlist[Tn] =  10   ; Tn++ ;
    Ttypelist[Tn] = SY ; Tvlist[Tn] =  10   ; Tn++ ;
    Ttypelist[Tn] = SZ ; Tvlist[Tn] =  10   ; Tn++;
    Ttypelist[Tn] = RX ; Tvlist[Tn] =  -45   ; Tn++ ;
    Ttypelist[Tn] = TZ ; Tvlist[Tn] =  50   ; Tn++ ;
    Ttypelist[Tn] = TX ; Tvlist[Tn] =  20   ; Tn++ ;
    //Ttypelist[Tn] = TX ; Tvlist[Tn] =  -20   ; Tn++ ;


  
    M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
    M3d_mat_mult(obmat[num_objects], vm, m) ;
    M3d_mat_mult(obinv[num_objects], mi, vi) ;

    num_objects++ ; // don't forget to do this

    //////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
    obtype[num_objects] = 0 ; // plane
    color[num_objects][0] = 0.8 ;
    color[num_objects][1] = 0.0 ; 
    color[num_objects][2] = 0.0 ;
    obid[num_objects] = -1;
    //obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
  
    Tn = 0 ;

    Ttypelist[Tn] = SX ; Tvlist[Tn] =  20   ; Tn++ ;
    Ttypelist[Tn] = SY ; Tvlist[Tn] =  20   ; Tn++ ;
    Ttypelist[Tn] = SZ ; Tvlist[Tn] =  20   ; Tn++ ;
    //Ttypelist[Tn] = RY ; Tvlist[Tn] =  20   ; Tn++ ;
    Ttypelist[Tn] = TZ ; Tvlist[Tn] =  60   ; Tn++ ;

  
    M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
    M3d_mat_mult(obmat[num_objects], vm, m) ;
    M3d_mat_mult(obinv[num_objects], mi, vi) ;

    num_objects++ ; // don't forget to do this

    //////////////////////////////////////////////////////////////
    /*/////////////////////////////////////////////////////////////
    obtype[num_objects] = 2; //hyperboloid
    // color[num_objects][0] = 0.8 ;
    // color[num_objects][1] = 0.0 ; 
    // color[num_objects][2] = 0.0 ;
    // obid[num_objects] = -1;
    obid[num_objects] = init_xwd_map_from_file ("space2J.xwd") ;
  
    Tn = 0 ;
    Ttypelist[Tn] = SX ; Tvlist[Tn] =  5   ; Tn++ ;
    Ttypelist[Tn] = SY ; Tvlist[Tn] =  5   ; Tn++ ;
    Ttypelist[Tn] = SZ ; Tvlist[Tn] =  5   ; Tn++ ;
    Ttypelist[Tn] = RX ; Tvlist[Tn] =  45  ; Tn++ ;
    Ttypelist[Tn] = TZ ; Tvlist[Tn] =  40   ; Tn++ ;
    Ttypelist[Tn] = TX ; Tvlist[Tn] =  -20   ; Tn++ ;


  
    M3d_make_movement_sequence_matrix(m, mi, Tn, Ttypelist, Tvlist);
    M3d_mat_mult(obmat[num_objects], vm, m) ;
    M3d_mat_mult(obinv[num_objects], mi, vi) ;

    num_objects++ ; // don't forget to do this

    /*/////////////////////////////////////////////////////////////

    G_rgb(0,0,0) ;
    G_clear() ;
    light_in_eye_space[0] =  20 ;
    light_in_eye_space[1] =  10 ;
    light_in_eye_space[2] =  0 ;
    
    Rsource[0] =  0 ;  Rsource[1] =  0 ;  Rsource[2] = 0 ;    
    Rtip[2] = 692.8; // (400/tan30)

    for(Rtip[0] = -400; Rtip[0] < 400; Rtip[0]++){
    	for(Rtip[1] = -400; Rtip[1] < 400; Rtip[1]++){
    		ray_recurse(Rsource, Rtip, argb);
        G_rgb(argb[0],argb[1],argb[2]);
        G_point(Rtip[0]+400,Rtip[1]+400);
    	}
    }

    G_rgb(1,1,1) ; G_draw_string("'q' to quit", 50,50) ;
    while (G_wait_key() != 'q') ;
    G_save_image_to_file("3d_Simple_RaytracerB.xwd") ;
}




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void test02(){
  double source[3] = {1,1,1},tip[3] = {0,0,0},normal[3] = {0,0,-1},nsource[3],ntip[3];
  reflect(source,tip,normal,nsource,ntip);
}



int main()
{
  G_init_graphics(800,800);
  test01() ;
  //test02() ;
}
