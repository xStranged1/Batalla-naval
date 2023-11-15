#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


int main(){
	srand(time(NULL));
	int tablero[20][20], tablerox[20], tableroy[20], torpedo[20][20], torpedox[20], torpedoy[20], cantTorpedosNodados, ntorpedo, i, j, k;
	int x, y, a, mayor;
	char nombreBarco[7][11];//la pos 0 no la usa, para que la interseccion en tablero no sea 0
	bool sw = true;
	//inicializa en 0
	for (i=0;i<20;i++){
		for(j=0;j<20;j++){
			tablero[i][j] = 0;
			torpedo[i][j] = 0;
			
		}
		torpedox[i] = 0;
		torpedoy[i] = 0;
		tablerox[i] = 0;
		tableroy[i] = 0;
	}
	for(i=0;i<20;i++){
		tablerox[i]=0;
		tableroy[i]=0;
	}
	for(i=1;i<7;i++){
		printf("\nNombre del barco %i: ", i);
		scanf("%s", nombreBarco[i]);
		
		//spawn aleatorio
		while(sw){
			x = rand()%20;
			y = rand()%20;
			if (tablerox[x]==0 && tableroy[y]==0){ // no hay barco en esa fila y columna
				
				tablero[x][y] = i;
				 // se le asigna en la interseccion el indice del vector nombreBarco
				tablerox[x] = 1;
				tableroy[y] = 1;
				sw = false;
				printf("\nBarco %s generado en la posicion: (%i, %i)", nombreBarco[i], x, y);
			}else printf("\nEn la fila o columna %i o %i ya hay un barco, se generan de vuelta", x, y);
		}
		sw = true;
		
	}
	
	for (i=0;i<20;i++){
		for(j=0;j<20;j++){
				if(tablero[j][i]!=0){
					a = tablero[j][i];
					printf("\nBarco: %s en posicion (%i, %i) = %i", nombreBarco[a], j, i, tablero[j][i]);
				}
				
			}
	}
		
	int cantDerribo = 0;
	for(i=0;i<20;i++){
		
		for(j=0;j<20;j++){
			if(torpedox[i] == 0 && torpedoy[j] == 0){//no hay barcos en esa fila ni columna
			ntorpedo++;
				printf("\nSe lanza misil n %i a la posicion (%i, %i)", ntorpedo, i, j);
				if (tablero[i][j]!=0){//le da a un barco
					torpedo[i][j] = ntorpedo;
					torpedox[i]=1;
					torpedoy[j]=1;
					cantDerribo++;
					cantTorpedosNodados = 0;
					printf("\nSe derribo al barco: %s, barcos restantes: %i", nombreBarco[tablero[i][j]], 6-cantDerribo);
					getch();
					if(cantDerribo>=6){
						j=21;
						i=21;
						printf("\nSe derribaron todos");
					} 
				}else{
					cantTorpedosNodados++;
					if (mayor<cantTorpedosNodados) mayor = cantTorpedosNodados;
				} 
				
			}
		}
	}
	
	printf("\nLa flota ha sido derrotada.\n\n---------RESULTADOS----------");
	for(i=19;i>-1;i--){
		for(j=19;j>-1;j--){//recorre tablero
			if(torpedo[i][j]!=0){//encontro barco
				a = tablero[i][j];
				printf("\nSe derribo el barco %s en la posicion (%i, %i) con el torpedo numero: %i", nombreBarco[a], i, j, torpedo[i][j]);
			}
		}
	}
	printf("\nMayor cantidad de torpedos fallados: %i", mayor);
	getch();
	

}
