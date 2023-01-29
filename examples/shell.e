n := 20;

array := [n];


para i desde 0 hasta n - 1 hacer
    array[i] := uniforme();
fin_para;


array[0] := 56;
array[1] := 251;
array[2] := -12;
array[3] := 442;
array[4] := -32.3;
array[5] := 1.23e4;
array[6] := 782;
array[7] := 57;
array[8] := 12;
array[9] := 86;
array[10] := -2;
array[11] := 321;
array[12] := 12;
array[13] := 44;
array[14] := 23.34e-2;
array[15] := -7;
array[16] := 78;
array[17] := -557;
array[18] := 1;
array[19] := -826;

escribir_cadena('El array inicializado con valores aleatorios es: ');
escribir_array(array);

d := n;

repetir
    d := d // 2;
    
    repetir
        bandera := 0;
        i := 0;
        
        repetir
            itemActual := array[i];
            indiceProx := i + d;
            itemProximo := array[indiceProx];

            si (itemActual > itemProximo) entonces

                auxiliar := array[indiceProx];
                itemActual := array[i];
                array[indiceProx] := itemActual;
                array[i] := auxiliar;
                bandera := 1;

            fin_si;
            i := i + 1;
            
        hasta(i+d > n-1);

    hasta(bandera == 0);

hasta (d == 1);

escribir_cadena('El array ordenado mediante el algoritmo shell: ');
escribir_array(array);
escribir_cadena('\n');
