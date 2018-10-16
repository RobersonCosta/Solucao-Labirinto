#include <stdio.h>
#include <stdlib.h>

void main(){
	int map[100][100], c, l, nlc, pl, pc;
	printf("O LABIRINTO TEM LIMITE QUADRADO COM O NUMERO: 100\n");
	printf("Digite o valor para construir o labirinto: ");
	scanf("%i", &nlc);
	printf("\n'0' para lugar vazio e '1' para obstaculos:\n\n");
	for (l=0; l<nlc; l++){
		for (c=0;c<nlc;c++){
			map[l][c] = rand()%2;
			map[0][0] = 0;
			map[nlc-1][nlc-1] = 0;
			printf(" %i", map[l][c]);
		}		
		printf("\n");
	}	
	printf("\n");
	printf("Inicio [1][1] destino [%i][%i]\n", nlc, nlc);
	printf("O '2' equivale ao caminho tracejado para finalizar o labirinto\n\n", nlc, nlc);
	
	pl = 0;
	pc = 0;
	c = 0;
	l = 0;
	map[l][c] = 2;
	while (map[nlc-1][nlc-1] != 2){
		
		// DIREITA
		
		if (c+1 <= nlc && map[l][c+1] == 0){
			c++;
			map[l][c] = 2;			
			pc++;
		} 
		
		// BAIXO
		
		else {
			if (l+1 <= nlc && map[l+1][c] == 0){
				l++;
				map[l][c] = 2;
				pl++;
			} 
			
			// ESQUERDA
			
			else {
				if (c-1 >= 0 && map[l][c-1] == 0){
					c--;
					map[l][c-1] = 2;					
					pc--;
				} 
				
				// CIMA
				
				else {
					if (l-1 <= nlc && map[l-1][c] == 0){
						l--;
						map[l-1][c] = 2;						
						pl--;
					}
					
					// TRAVOU DIREITA
					
					if (map[l][c+1] == 1 && map[l][c-1] == 2){
						pl = l;
						while (pl == l){
							if (c-1>=0 && map[l][c-1] == 0){
								c--;
								map[l][c] = 2;
								pc--;
							}
							if (l+1 <= nlc && map[l+1][c] == 0){
								l++;
								map[l][c] = 2;
							}else{
								if (l-1 <= nlc && map[l-1][c] == 0){
									l--;
									map[l][c] = 2;					
								}
							}								
						}
					} 
					
					// TRAVOU ESQUERDA
					
					else {
						if (map[l][c-1] == 1 && map[l][c+1] == 2){
							pl = l;
							while (pl == l){
								if (c+1>=0 && map[l][c+1] == 0){
									c++;
									map[l][c] = 2;
									pc++;
								}
								if (l+1 <= nlc && map[l+1][c] == 0){
									l++;
									map[l][c] = 2;
								}else{
									if (l-1 <= nlc && map[l-1][c] == 0){
										l--;
										map[l][c] = 2;					
									}
								}								
							}
						} 
					}
				}
			}
		}
	}
	
	for (l=0; l<nlc; l++){
		for (c=0; c<nlc; c++){
			printf(" %i", map[l][c]);
		}
		printf("\n");
	}
	
	system ("PAUSE");
}
