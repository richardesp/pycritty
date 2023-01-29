n := 9;

array := [n];

<<
para i desde 0 hasta n - 1 hacer
    array[i] := uniforme();
fin_para;
>>

array[0] := 'bootstraping';
array[1] := 'compilador';
array[2] := 'intérprete';
array[3] := 'tabla de símbolos';
array[4] := 'análisis ascendente';
array[5] := 'autómata';
array[6] := 'clausura';
array[7] := 'regla';
array[8] := 'gramática';

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
