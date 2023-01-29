# IMPRESIÓN DEL LOGO DEL LENGUAJE

borrar_pantalla();

ejeYLogo := 50;
ejeXLogo := 50;

c1 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c2 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c3 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c4 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c5 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⣀⡀⠈⢻⣿⡿⠋⠉⠉⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c6 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠘⠿⠟⠀⢸⠏⠀⢀⣠⣤⣄⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c7 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⢀⣀⣀⣤⡟⠀⢠⣿⣿⣿⣿⣿⣄⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c8 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⣾⣿⣿⡿⠀⢀⣿⣿⠁⢻⣿⣿⣿⣆⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c9 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⣼⣿⣿⣿⠃⠀⣾⣿⣿⡄⠀⢿⣿⣿⣿⣆⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c10 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⣰⣿⣿⣿⠇⠀⣸⣿⣿⣿⣿⡀⠈⢿⣿⣿⣿⣆⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c11 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⢠⣿⣿⣿⡟⠀⢠⣿⣿⣿⣿⣿⣷⠀⠈⢿⣿⣿⣿⣆⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c12 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⣾⣿⠟⠛⠀⠀⣿⣿⣿⣿⣿⣿⣿⣧⠀⠈⢿⣿⣿⣿⣆⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c13 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⣸⣿⠁⢀⣤⣤⠀⠸⣿⣿⣿⣿⣿⠟⠋⠀⠀⠈⢿⣿⣿⣿⡆⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c14 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⢠⣿⣿⡀⠈⠛⠋⠀⣰⣿⣿⠟⠋⠀⠀⣀⣴⣆⠀⠈⢿⣿⣿⣿⡀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c15 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⣾⣿⣿⣿⣦⣤⣤⣶⠟⠋⠀⢀⣠⣴⣿⣿⣿⣿⣆⠀⠈⢿⣿⣿⣷⠀⠀⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c16 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⣸⣿⣿⣿⣿⡿⠟⠉⠀⢀⣤⣶⠛⠉⠉⠙⢻⣿⣿⣿⣆⠀⠘⣿⣿⠁⠀⣠⡀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c17 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠿⠿⠟⠛⠉⠀⢀⣠⣾⣿⣿⡇⠀⢼⣿⠄⠀⠿⠿⣿⡿⠀⠀⣿⣿⠀⠘⠿⠃⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c18 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠀⠀⠀⠀⣀⣠⣶⣿⣿⣿⣿⣿⣷⣀⠈⠉⢀⣀⣀⡀⠀⢀⣀⣼⣿⣿⣷⣤⣀⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c19 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c20 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c21 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c22 := '⣿⣿⣿⣿⣿⣿⠟⠛⠛⢿⣿⣿⠛⢿⣿⡟⢻⣿⣿⡿⠟⠛⠛⢻⣿⣿⠟⠛⠛⠻⣿⣿⣿⠟⢻⣿⣿⠛⠛⠛⠛⢿⣿⠟⠛⠛⠛⢻⣿⡟⠻⣿⣿⠟⢿⣿⣿⣿⣿⣿\n';
c23 := '⣿⣿⣿⣿⣿⣿⠀⣾⡇⠈⣿⣿⣧⠈⠟⢀⣾⣿⡟⠀⣴⣿⣿⣾⣿⣿⠀⢸⡷⠀⣿⣿⣿⠀⢸⣿⣿⣿⡇⠀⣿⣿⣿⣿⡇⠀⣿⣿⣿⣿⡄⠘⠇⢠⣿⣿⣿⣿⣿⣿\n';
c24 := '⣿⣿⣿⣿⣿⣿⠀⣉⣁⣼⣿⣿⣿⡇⠀⣾⣿⣿⣇⠀⢿⣿⣿⣿⣿⣿⠀⢠⡄⠰⣿⣿⣿⠀⢸⣿⣿⣿⡇⠀⣿⣿⣿⣿⡇⠀⣿⣿⣿⣿⣿⡄⢠⣿⣿⣿⣿⣿⣿⣿\n';
c25 := '⣿⣿⣿⣿⣿⣿⣀⣿⣿⣿⣿⣿⣿⣇⣀⣿⣿⣿⣿⣦⣄⣀⣀⣼⣿⣿⣀⣸⣿⣄⣹⣿⣿⣀⣸⣿⣿⣿⣇⣀⣿⣿⣿⣿⣇⣀⣿⣿⣿⣿⣿⣇⣸⣿⣿⣿⣿⣿⣿⣿\n';
c26 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c27 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c28 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c29 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';
c30 := '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n';

estiloPrev := 'NEGRITA_CYAN';
estiloPost := 'NEGRITA_AZUL';

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c1);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c2);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c3);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c4);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c5);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c6);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c7);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c8);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c9);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c10);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c11);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c12);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c13);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c14);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c15);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c16);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c17);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c18);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c19);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c20);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c21);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c22);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c23);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c24);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c25);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c26);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c27);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c28);


lugar(ejeXLogo, ejeYLogo);
estilo(estiloPrev);
escribir_cadena(c29);

lugar(ejeXLogo, ejeYLogo);
estilo(estiloPost)
escribir_cadena(c30);

estilo('NEGRITA_ROJO');
estilo('PARPADEO');

escribir_cadena('\n\n');
escribir_cadena('\t\t\t\t\t\t\t');
escribir_cadena('  > Presione ENTER para comenzar la partida <');
leer_cadena(pausa);

estilo('DEFECTO');