// jogo de adivinhacao em C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main () {
	
	printf("\n\n");
	printf("	   _		     _											\n");
	printf("	  / \\               / \\										\n");
    printf("	 /   \\             /   \\											\n");
    printf("	(_____)           (_____)											\n");
    printf("	 |   |  _   _   _  |   |											\n");
	printf("	 | O |_| |_| |_| |_| O |										\n");
	printf("	 |-  |          _  | - |										\n");
	printf("	 |   |   - _^_     |   |										\n");
	printf("	 |  _|    //|\\\\  - |   |										\n");
	printf("	 |   |   ///|\\\\\\   |  -|		Bem-vindo(a) ao nosso						\n");
	printf("	 |-  |_  |||||||   |   |		jogo de adivinhacao!						\n");
	printf("	 |   |   |||||||   |-  |										\n");
	printf("	 |___|___|||||||___|___|										\n");
	printf("	         (      (											\n");
	printf("	          \\      \\											\n");
	printf("	           )      )											\n");
	printf("	           |      |											\n");
	printf("	           (      (											\n");
	printf("	            \\      \\											\n");
	printf("\n\n");
	
	srand(time(0)); // para pegar numeros diferentes
	
	int secretNumber = rand()%100; // para pegar numeros de 1 a 99
	
	int guess, itsRight, itsGreater, totalAttempts, attempts;
	
	float points = 1000;
	int level;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil\n(2) Medio\n(3) Dificil\n");
	printf("Escolha: ");
	scanf("%d", &level);
	
	itsRight = (guess == secretNumber);
	itsGreater = (guess > secretNumber);
	
	
	switch (level) {
		case 1:
			totalAttempts = 20;
			break;
		case 2:
			totalAttempts = 15;
			break;
		default:
			totalAttempts = 6;
			break;
	}
	
	
	for(attempts = 1; attempts <= totalAttempts; attempts++){
		
		printf("\nTentativa %d\n", attempts);
		printf("Qual eh o seu chute? ");
		scanf("%d", &guess);
		printf("Seu chute foi %d\n", guess);
		
		if(guess < 0) {
			printf("Voce nao pode chutar numeros negativos!\n");
			attempts--;
			
			continue;
		}
		
		itsRight = (guess == secretNumber);
		itsGreater = (guess > secretNumber);
			
		if(itsRight) {
			printf("Voce acertou!\n");
			break;
		}
		else if (itsGreater) {
			printf("Seu chute eh maior que o numero secreto!\n");
			//attempts++;
		}
		else {
			printf("Seu chute eh menor que o numero secreto!\n");
			//attempts++;
		}
		
		float lostPoints = (guess - secretNumber)/2.0;
		points = points - abs(lostPoints);
		
	}
	printf("\nFim de jogo!\n");
	
	if(itsRight) {
		
		printf("\n\n");
		printf("	 ,xXXXXx,				\n");
		printf("	,XXXXXXXX,				\n");
		printf("	XXXXXXXXXX				\n");
		printf("	`'''XX'''`				\n");
		printf("	    XX					\n");
		printf("	    XX					\n");
		printf("	    XX					\n");
		printf("\n");
		printf("Parabens!\n");
		printf("Voce acertou em %d tentativas!\n", attempts);
		printf("Total de pontos: %.1f\n", points);
		
	} else {
		printf("\n\n");
		printf("     ,-,		\n");
		printf("    /.(			\n");
		printf("    \\ {			\n");
		printf("     `-`		\n");
		printf("\n");
		printf("Voce perdeu! Tente novamente!\n");
	}

	return 0;
}
