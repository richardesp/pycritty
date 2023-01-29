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


############################################################

borrar_pantalla();
lugar(10, 10);
estilo('NEGRITA_ROJO');
escribir_cadena('Bienvenido a esta aventura forastero...\n');

estilo('NEGRITA_CYAN');
escribir_cadena('\tPresiona ENTER para continuar...\n');
leer_cadena(pausa);

nDecisiones := 1;
decisiones := [nDecisiones]; # Array donde vamos a ir almacenando todas las decisiones que efectuamos

nObjetos := 3;
objetos := [nObjetos]; # Array donde vamos a ir almacenando nuestros distintos objetos

# Los elementos pares guardan el objeto y los impares la cantidad
ultimoObjeto := nObjetos - 3;
ultimaCantidadObjeto := nObjetos - 2;
ultimoEstiloObjeto := nObjetos - 1;

# Último objeto a guardar
objetos[ultimoObjeto] := 'Neo-Dólares (§)';

# Cantidad del último objeto
objetos[ultimaCantidadObjeto] := 500;

# Estilo personalizado del último objeto
objetos[ultimoEstiloObjeto] := 'NEGRITA_VERDE';

borrar_pantalla();
estilo('NEGRITA_ROJO');
lugar(10, 10);
escribir_cadena('¿Quieres acompañarme?\n');

estilo('NEGRITA_AMARILLO');
escribir_cadena('\t[0] No\n');
escribir_cadena('\t[1] Sí\n');
opcion := -1;

Mientras (opcion <> 0 y opcion <> 1) hacer

    leer(opcion);

    Segun (opcion)
        valor 0:
            indiceUltimoSuceso := nDecisiones - 1;
            decisiones[indiceUltimoSuceso] := 'No acompañaste al forastero a tierras Ansalianas';

            borrar_pantalla();
            estilo('NEGRITA_ROJO');
            lugar(10, 10);
            escribir_cadena('Bueno, supongo que nuestras aventuras se acaban en tierra Ansalianas\n');

            estilo('NEGRITA_CYAN');
            escribir_cadena('\tPresiona ENTER para continuar...\n');
            leer_cadena(pausa);
            estilo('DEFECTO');
        

        valor 1:
            indiceUltimoSuceso := nDecisiones - 1;
            decisiones[indiceUltimoSuceso] := 'Acompañaste al forastero a tierras Ansalianas';

            borrar_pantalla();
            estilo('NEGRITA_MAGENTA');
            estilo('ITALICA');
            escribir_cadena('\tTe encuentras en la barra del bar Willys');
            escribir_cadena(' a la espera de un elfo estraviado con chaqueta de aviador...\n');

            # Evento de recolección de cigarrillos

            estilo('NEGRITA_CYAN');
            escribir_cadena('\n\tPresiona ENTER para continuar...\n\n');
            leer_cadena(pausa);

            borrar_pantalla();

            estilo('NEGRITA_MAGENTA');
            estilo('ITALICA');

            escribir_cadena('\tEn una mesa vacía cercana a la barra, encuentras un paquete de cigarrillos ');
            estilo('NEGRITA_ROJO');
            escribir_cadena('Calboro');
            
            estilo('NEGRITA_MAGENTA');

            escribir_cadena('\n\tDebes decidir: \n\n');

            estilo('NEGRITA_AMARILLO');
            escribir_cadena('\t[0] Coger el paquete de cigarrillos de manera sigilosa\n');
            escribir_cadena('\t[1] No cogerlo\n');
        
            leer(opcion);

            Si (opcion == 0) entonces
                nObjetos := nObjetos + 3;
                ultimoObjeto := nObjetos - 3;
                ultimaCantidadObjeto := nObjetos - 2;
                ultimoEstiloObjeto := nObjetos - 1;

                # Actualizamos el tamaño del array de objetos
                objetos := [nObjetos];

                # Último objeto a guardar
                objetos[ultimoObjeto] := 'Paquete de cigarrillos calboro (♣)';

                # Cantidad del último objeto
                objetos[ultimaCantidadObjeto] := 1;

                # Estilo personalizado del último objeto
                objetos[ultimoEstiloObjeto] := 'NEGRITA_ROJO';

                estilo('NEGRITA_AMARILLO');
                escribir_cadena('\tCogiste el objeto...\n\n');

                estilo('NEGRITA_CYAN');
                escribir_cadena('\n\tPresiona ENTER para continuar...\n\n');
                leer_cadena(pausa);

                nDecisiones++;
                indiceUltimoSuceso := nDecisiones - 1;

                # Incrementamos el número de sucesos del Array de manera dinámica
                decisiones := [nDecisiones];

                # Agregamos el nuevo suceso
                decisiones[indiceUltimoSuceso] := 'Robaste el paquete de cigarrillos de la barra';
            
            Si_no 
                estilo('NEGRITA_AMARILLO');
                escribir_cadena('\tNo cogiste el objeto...\n\n');

                estilo('NEGRITA_CYAN');
                escribir_cadena('\n\tPresiona ENTER para continuar...\n\n');
                leer_cadena(pausa);

            fin_si;

            opcion := -1;

            mientras (opcion <> 0 y opcion <> 1 y opcion <> 2) hacer

                borrar_pantalla();

                estilo('NEGRITA_MAGENTA');
                escribir_cadena('\tFinalmente acabas llegando a la barra del bar Willys...\n');
                escribir_cadena('\tDebes decidir: \n\n');

                estilo('NEGRITA_AMARILLO');
                escribir_cadena('\t[0] Pedir un Jack Daniels etiqueta negra\n');
                escribir_cadena('\t[1] Hablar con el elfo \n');
                escribir_cadena('\t[2] Ir al baño \n');

                estilo('DEFECTO');
                estilo('NEGRITA_AZUL');
                estilo('ITÁLICA');
                escribir_cadena('\n\n\t[3] Ver inventario\n');

                leer(opcion);

                segun (opcion)

                    valor 0:
                        borrar_pantalla();
                        estilo('NEGRITA_MAGENTA');
                        estilo('ITALICA');

                        escribir_cadena('\t Empiezas a tomarlo de trago en trago y te comienzas a encontrar mal...\n');
                        
                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER tecla para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('NEGRITA_MAGENTA');
                        escribir_cadena('\tTe despiertas tras tu estado de embriagez y te despiertas sin ningún objeto en tu inventario...\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        borrar_pantalla();

                        estilo('NEGRITA_VERDE');
                        escribir_cadena('\tContinuará...\n\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('Defecto');

                        nDecisiones++;
                        indiceUltimoSuceso := nDecisiones - 1;

                        # Incrementamos el número de sucesos del Array de manera dinámica
                        decisiones := [nDecisiones];

                        # Agregamos el nuevo suceso
                        decisiones[indiceUltimoSuceso] := 'Tu estado de embriagez te dejó fuera de partida y perdiste todo tu inventario';

                        opcion := 0;

                    valor 1:
                        borrar_pantalla();
                        estilo('NEGRITA_MAGENTA');
                        estilo('ITALICA');

                        escribir_cadena('\t Al acercarte al elfo te comenta lo siguiente susurrando...\n');
                        
                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('NEGRITA_ROJO');
                        escribir_cadena('\tSígueme a la parte de atrás para comentarte el ');
                        estilo('NEGRITA_AMARILLO');
                        escribir_cadena('PLAN ');
                        estilo('NEGRITA_ROJO');
                        escribir_cadena('...\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        borrar_pantalla();

                        estilo('NEGRITA_VERDE');
                        escribir_cadena('\tContinuará...\n\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTE para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('Defecto');

                        nDecisiones++;
                        indiceUltimoSuceso := nDecisiones - 1;

                        # Incrementamos el número de sucesos del Array de manera dinámica
                        decisiones := [nDecisiones];

                        # Agregamos el nuevo suceso
                        decisiones[indiceUltimoSuceso] := 'Comenzaste a idear el plan con el Elfo estraviado en la parte de atrás';

                        opcion := 0;

                    valor 2:
                        borrar_pantalla();
                        estilo('NEGRITA_MAGENTA');
                        estilo('ITALICA');

                        escribir_cadena('\t Al llegar al baño comienzas a escuchar cierto barullo...\n');
                        
                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('NEGRITA_MAGENTA');
                        escribir_cadena('\tRecibes un golpe muy contudente en la cabeza. Te desvaneces en el suelo...\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        borrar_pantalla();

                        estilo('NEGRITA_VERDE');
                        escribir_cadena('\tContinuará...\n\n');

                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\tPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);

                        estilo('Defecto');

                        nDecisiones++;
                        indiceUltimoSuceso := nDecisiones - 1;

                        # Incrementamos el número de sucesos del Array de manera dinámica
                        decisiones := [nDecisiones];

                        # Agregamos el nuevo suceso
                        decisiones[indiceUltimoSuceso] := 'Recibiste un golpe en el baño, en la parte de atrás del bar';

                        opcion := 0;

                    valor 3:
                        borrar_pantalla();
                        estilo('NEGRITA_AZUL');
                        estilo('ITÁLICA');
                        escribir_cadena('\t\t««« INVENTARIO »»»\n\n');

                        para i desde 0 hasta nObjetos - 1 Paso 3 hacer
                            estilo('DEFECTO');
                            estilo('NEGRITA_AZUL');
                            estilo('ITÁLICA');
                            escribir_cadena('\t→ ');

                            ultimoObjeto := i;
                            ultimaCantidadObjeto := i + 1;
                            ultimoEstiloObjeto := i + 2;

                            objeto := objetos[ultimoObjeto]; # Cadena
                            ultimaCantidadObjeto := objetos[ultimaCantidadObjeto]; # Entero
                            ultimoEstiloObjeto := objetos[ultimoEstiloObjeto]; # Estilo

                            estilo(ultimoEstiloObjeto);
                            escribir_cadena(objeto);
                            escribir_cadena(' ⇒ ');
                            escribir(ultimaCantidadObjeto);
                            escribir_cadena('\n');

                        fin_para;

                        estilo('DEFECTO');

                        estilo('ITÁLICA');
                        estilo('NEGRITA_CYAN');
                        escribir_cadena('\n\nPresiona ENTER para continuar...\n\n');
                        leer_cadena(pausa);



                Fin_segun;

            fin_mientras;
    
    Fin_segun;

fin_mientras;

borrar_pantalla();
estilo('NEGRITA_MAGENTA');
estilo('ITÁLICA');
estilo('PARPADEO');
escribir_cadena('\tTu aventura ha consistido en lo siguiente durante el día de hoy...\n');

Para i desde 0 hasta nDecisiones - 1 hacer
    estilo('NEGRITA_AMARILLO');
    estilo('ITÁLICA');
    escribir_cadena('\t ► ');
    estilo('SUBRAYADO_AMARILLO');
    suceso := decisiones[i];
    escribir_cadena(suceso);
    escribir_cadena('\n');
    estilo('DEFECTO');

fin_para;

estilo('DEFECTO');
estilo('NEGRITA_CYAN');
escribir_cadena('\n\n\tPresiona ENTER para continuar...\n\n');
leer_cadena(pausa);

estilo('DEFECTO');