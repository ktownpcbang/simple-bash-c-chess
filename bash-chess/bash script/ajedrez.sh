#!/bin/bash
declare -A tablero
function imprimir() {
    echo "  a b c d e f g h"
    for (( i=1 ; $i<9 ; i=$i+1 )); do
	echo -n "$i "
	for (( j=1 ; $j<9 ; j=$j+1 )); do
	    echo -n "${tablero[$i,$j]} "
	done
	echo " "
    done
}
function comprobar() {
    let b=0
    let n=0
    for (( i=1 ; $i<9 ; i=$i+1 )); do
	for (( j=1 ; $j<9 ; j=$j+1 )); do
	    if [ "${tablero[$i,$j]}" = 'k' ]; then
		let n=1
	    elif [ "${tablero[$i,$j]}" = 'K' ]; then
		let b=1
	    fi
	done
    done
    if [ "$n" -eq 1 -a "$b" -eq 0 ]; then
	imprimir
	echo "EL JUGADOR NEGRO HA GANADO LA PARTIDA"
	return 1
    elif [ "$n" -eq 0 -a "$b" -eq 1 ]; then
	imprimir
	echo "EL JUGADOR BLANCO HA GANADO LA PARTIDA"
	return 1
    else
	return 0;
    fi
}
function mover() {
    case $2 in
	a) let j1=1;;
	b) let j1=2;;
    c) let j1=3;;
	d) let j1=4;;
	e) let j1=5;;
	f) let j1=6;;
	g) let j1=7;;
	h) let j1=8;;
	*) echo "ERROR en la letra de columna introducida"
	   return 0;;
    esac
    case $4 in
	a) let j2=1;;
	b) let j2=2;;
    c) let j2=3;;
	d) let j2=4;;
	e) let j2=5;;
	f) let j2=6;;
	g) let j2=7;;
	h) let j2=8;;
	*) echo "ERROR en la letra de columna itroducida"
	   return 0;;
    esac
    if [ "$1" -lt 0 -o "$1" -gt 8 ]; then
	echo "ERROR en el numero de fila introducido"
	return 0
    fi
    if [ "$3" -lt 0 -o "$3" -gt 8 ]; then
	echo "ERROR en el numero de fila introducido"
	return 0
    fi
    if [ "$5" -eq 1 ]; then
	if [ "${tablero[$1,$j1]}" = 'p' -o "${tablero[$1,$j1]}" = 'r' -o "${tablero[$1,$j1]}" = 'n' -o "${tablero[$1,$j1]}" = 'b' -o "${tablero[$1,$j1]}" = 'q' -o "${tablero[$1,$j1]}" = 'k' ]; then
	    echo "ERROR ha intentado mover una pieza del otro jugador"
	    return 0
	elif [ "${tablero[$1,$j1]}" = 'P' -o "${tablero[$1,$j1]}" = 'R' -o "${tablero[$1,$j1]}" = 'N' -o "${tablero[$1,$j1]}" = 'B' -o "${tablero[$1,$j1]}" = 'Q' -o "${tablero[$1,$j1]}" = 'K' ]; then
	    if [ "${tablero[$3,$j2]}" = 'P' -o "${tablero[$3,$j2]}" = 'R' -o "${tablero[$3,$j2]}" = 'N' -o "${tablero[$3,$j2]}" = 'B' -o "${tablero[$3,$j2]}" = 'Q' -o "${tablero[$3,$j2]}" = 'K' ]; then
		echo "ERROR ha intentado comer una pieza del propio jugador"
		return 0
	    else
		tablero[$3,$j2]=${tablero[$1,$j1]}
		tablero[$1,$j1]=' '
		return 1
	    fi
	 else
	    echo "ERROR en esa posicion no hay ninguna pieza"
	    return 0
	 fi
     elif [ "$5" -eq 2 ]; then
	    if [ "${tablero[$1,$j1]}" = 'P' -o "${tablero[$1,$j1]}" = 'R' -o "${tablero[$1,$j1]}" = 'N' -o "${tablero[$1,$j1]}" = 'B' -o "${tablero[$1,$j1]}" = 'Q' -o "${tablero[$1,$j1]}" = 'K' ]; then
	    echo "ERROR ha intentado mover una pieza del otro jugador"
	    return 0
	elif [ "${tablero[$1,$j1]}" = 'p' -o "${tablero[$1,$j1]}" = 'r' -o "${tablero[$1,$j1]}" = 'n' -o "${tablero[$1,$j1]}" = 'b' -o "${tablero[$1,$j1]}" = 'q' -o "${tablero[$1,$j1]}" = 'k' ]; then
	    if [ "${tablero[$3,$j2]}" = 'p' -o "${tablero[$3,$j2]}" = 'r' -o "${tablero[$3,$j2]}" = 'n' -o "${tablero[$3,$j2]}" = 'b' -o "${tablero[$3,$j2]}" = 'q' -o "${tablero[$3,$j2]}" = 'k' ]; then
		echo "ERROR ha intentado comer una pieza del propio jugador"
		return 0
	    else
		tablero[$3,$j2]=${tablero[$1,$j1]}
		tablero[$1,$j1]=' '
		return 1
	    fi
	else
	     echo "ERROR en esa posicion no hay ninguna pieza"
	     return 0
	fi
      fi     
      return 0
}

if [ -z  "$1" ]; then
    echo "Te falta introducir el argumento del nombre de fichero de texto para guardar la secuencia de movimientos"
else
for (( i=1 ; $i<9 ; i=$i+1 )); do
    if [ "$i" -eq 1 ]; then
	tablero[$i,1]='r'
	tablero[$i,2]='n'
	tablero[$i,3]='b'
	tablero[$i,4]='q'
	tablero[$i,5]='k'
	tablero[$i,6]='b'
	tablero[$i,7]='n'
	tablero[$i,8]='r'
     elif [ "$i" -eq 8 ]; then
	tablero[$i,1]='R'
	tablero[$i,2]='N'
	tablero[$i,3]='B'
	tablero[$i,4]='Q'
	tablero[$i,5]='K'
	tablero[$i,6]='B'
	tablero[$i,7]='N'
	tablero[$i,8]='R'
	  elif [ "$i" -eq 3 -o "$i" -eq 4 -o "$i" -eq 5 -o "$i" -eq 6 ]; then
	  	for (( j=1 ; $j<9 ; j=$j+1 )); do
	    	tablero[$i,$j]=' '
		done
      elif [ "$i" -eq 2 ]; then
		for (( j=1 ; $j<9 ; j=$j+1 )); do
	    	tablero[$i,$j]='p'
		done
      elif [ "$i" -eq 7 ]; then
	  	for (( j=1 ; $j<9 ; j=$j+1 )); do
	      tablero[$i,$j]='P'
	  	done
      fi
done
echo "JUEGO DE AJEDREZ"
let njugador=1
let cont1=1
let cont2=1
while comprobar
do
    imprimir
    if [ "$njugador" -eq 1 ]; then
	echo "TURNO DEL JUGADOR BLANCO (MAYUSCULAS): "
    elif [ "$njugador" -eq 2 ]; then
	echo "TURNO DEL JUGADOR NEGRO (minusculas): "
    fi
    echo "Introduzca posicion de la ficha que desea mover: "
    echo -n "    Letra columna: "
    read c1
    echo -n "    Numero fila: "
    read f1
    echo "Introduzca posicion a la que quiere mover: "
    echo -n "    Letra columna: "
    read c2
    echo -n "    Numero fila: "
    read f2
    while mover $f1 $c1 $f2 $c2 $njugador
    do
	echo "Introduzca de nuevo la posicion de la ficha que desea mover: "
	echo -n "    Letra columna: "
	read c1
	echo -n "    Numero fila: "
	read f1
	echo "Introduzca posicion a la que quiere mover: "
	echo -n "    Letra columna: "
	read c2
	echo -n "    Numero fila: "
	read f2
    done
    if [ "$njugador" -eq 1 ]; then
	echo "Movimiento numero $cont1 del jugador BLANCO: [$c1 $f1] a [$c2 $f2]"
	echo "Movimiento numero $cont1 del jugador BLANCO: [$c1 $f1] a [$c2 $f2]">>$1
        let njugador=2
	let cont1=$cont1+1
    elif [ "$njugador" -eq 2 ]; then
	echo "Movimiento numero $cont2 del jugador NEGRO: [$c1 $f1] a [$c2 $f2]"
	echo "Movimiento numero $cont2 del jugador NEGRO: [$c1 $f1] a [$c2 $f2]">>$1
	let njugador=1
	let cont2=$cont2+1
    fi
done
fi
