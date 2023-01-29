borrar_pantalla();
lugar(10,10);
escribir_cadena('Introduce tu nombre --> ');
leer_cadena(nombre);

borrar_pantalla();
lugar(10,10);
escribir_cadena(' Bienvenido/a << ');
escribir_cadena(nombre);
escribir_cadena(' >> al intérprete de pseudocódigo en español:\'ipe.exe\'.');

lugar(40,10);
escribir_cadena('Pulsa una tecla para continuar');
leer_cadena(pausa);

repetir

    borrar_pantalla();
    lugar(10,10);
    escribir_cadena(' Factorial de un número --> 1 \n');

    lugar(11,10);
    escribir_cadena(' Máximo común divisor ----> 2');
 
    lugar(12,10);
    escribir_cadena(' Finalizar ---------------> 0 \n');

    lugar(15,10);
    escribir_cadena(' Elige una opción: ');

    leer(opcion);

    si (opcion == 0) entonces
        borrar_pantalla();
        lugar(10,10);
        escribir_cadena(nombre);
        escribir_cadena(': gracias por usar el intérpretre ipe.exe\n');

    si_no 
        si (opcion == 1) entonces
            borrar_pantalla();
            lugar(10, 10);
            escribir_cadena('Factorial de un número\n');
            lugar(11, 10);
            escribir_cadena('Introduce un número entero: ');
            leer(N);

            factorial := 1;

            para i desde 2 hasta N paso 1 hacer
                factorial := factorial * i;
            fin_para;

            lugar(15, 10);
            escribir_cadena('El factorial de ');
            escribir(N);
            escribir_cadena(' es ');
            escribir(factorial);

        si_no
            # Maximo comun divisor
            si (opcion == 2) entonces
                borrar_pantalla();
                lugar(10,10);
                escribir_cadena(' Maximo común divisor de dos números ');

                lugar(11,10);
                escribir_cadena( ' algoritmo de Euclides ' );

                lugar(12,10);
                escribir_cadena(' Escribe el primer número: ');
                leer(a);

                lugar(13,10);
                escribir_cadena(' Escribe el segundo número: ');
                leer(b);

                # Se ordenan los números
                si (a < b)
                    entonces    
                        auxiliar := a;
                        a := b;
                        b := auxiliar;
                fin_si;

                # Se guardan los valores originales
                    A1 := a;
                    B1 := b;
                
                # Se aplica el método de Euclides
                    resto := a % b;

                mientras (resto <> 0) hacer
                    a := b;
                    b := resto;
                    resto := a % b;
                fin_mientras;

                # Se muestra el resultado
                lugar(15,10);
                escribir_cadena(' Máximo común divisor de ');
                escribir(A1);
                escribir_cadena(' y ');
                escribir(B1);
                escribir_cadena(' es ---> ');
                escribir(b);

            # Resto de Opciones
            si_no
                lugar(15,10);
                escribir_cadena(' Opcion incorrecta ');
            fin_si;
        fin_si;
    fin_si;
    lugar(40,10);
    escribir_cadena('\n Pulse una tecla para continuar --> ');
    leer_cadena(pausa);

hasta(opcion == 0);

# Despedida final
borrar_pantalla;
lugar(10,10);
escribir_cadena(' El programa ha concluido ');
