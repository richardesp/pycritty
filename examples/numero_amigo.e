borrar_pantalla();
lugar(0, 0);
estilo('NEGRITA_CYAN');

escribir_cadena('Introduzca un número n para ver si es amigable: ');
leer(n);
escribir_cadena('\n');

sum := 1;
i := 2;

mientras (i*i <= n) hacer
    si ((n % i) == 0) entonces
        sum := sum + i + n//i;
    fin_si;

    i := i + 1;
fin_mientras;

estilo('NEGRITA_MAGENTA');
escribir_cadena('\t➤ El número ');

estilo('NEGRITA_AMARILLO');
escribir(n);

estilo('NEGRITA_MAGENTA');
escribir_cadena(': ');

si (sum == n y n <> 1) entonces
    estilo('NEGRITA_VERDE');
    escribir_cadena('es amigable\n');

si_no 
    estilo('NEGRITA_ROJO');
    escribir_cadena('no es amigable\n');

fin_si;

estilo('DEFECTO');
escribir_cadena('\n');