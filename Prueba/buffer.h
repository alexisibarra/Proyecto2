 #define MAXEMP 15
 #define MAXNOMBRE 40

 typedef struct reg {
   int edad;
   int ttrabajo;
   char nombre[MAXNOMBRE];

 } emple;

 emple personal[MAXEMP] =  {{25, 2, "Carolina Perez"}, {40, 5, "Jesus Oviedo"}, {22, 1, "Mariana Lopez"}, {30, 3, "Jose Ragu"}, {35, 10, "Estefania Diaz"}, {40, 3, "Luis Ladera"}, {18, 1, "Petra Bueno"}, {38, 11, "Altagracia Abad"}, {26, 4, "Elena Garcia"}, {27, 7, "Flor Soto"}, {24, 1, "Carlos Montiel"}, {29, 6, "Chelique Bono"}, {31, 4, "Marcos Avendano"}, {33, 3, "Arturo Sosa"}, {34, 4, "Hugo Paez"}};
 emple personal1[MAXEMP], personal2[MAXEMP];

 void  imprimir(emple *, int);
