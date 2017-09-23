/* direttive al preprocessore */

#include <stdio.h>
#include "lib_num_complessi.h"

/* dichiarazione delle funzioni */
int acquisisci_scelta(void);						/* acquisisce correttamente il valore scelta */

/* definizione delle funzioni */
int acquisisci_scelta(void)
{
	int esito_lettura;				/* lavoro: validazione stretta */
	char caratt_rimosso;				/* lavoro: validazione stretta */
	int scelta = 0;					/* output: scelta dell'utente */

	do								/** VALIDAZIONE STRETTA **/
	{
		esito_lettura = scanf("%d",
					&scelta);
		if (esito_lettura != 1 || scelta < 1 || scelta > 5)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1 || scelta < 1 || scelta > 5);		/** FINE VALIDAZIONE STRETTA **/

	return(scelta);
}

/*** MAIN ***/

int main(void)
{
	int scelta = 0;							/* scelta dell'utente */
	
	printf("\n\t**********************************************\n");
	printf("\t** Programma-test per «lib_num_complessi.h» **\n");
	printf("\t**********************************************\n");
	printf("\nDigitare uno dei seguenti numeri, ciascuno corrispondente alla funzione indicata:\n");
	printf("1 - per convertire un numero complesso dalla forma algebrica alla trigonometrica e viceversa;\n");
	printf("2 - per calcolare la somma tra due numeri complessi;\n");
	printf("3 - per calcolare la differenza tra due numeri complessi;\n");
	printf("4 - per calcolare il rapporto tra due numeri complessi;\n");
	printf("5 - per calcolare il quoziente tra due numeri complessi.\n...");

	/* acquisizione e convalida della scelta */
	scelta = acquisisci_scelta();

	switch (scelta)
	{
		case 1:
			acquisisci_e_stampa();
			break;
		case 2:
			somma_num_compl();
			break;
		case 3:
			differenza_num_compl();
			break;
		case 4:
			prodotto_num_compl();
			break;
		case 5:
			rapporto_num_compl();
			break;
		default:
			printf("Si e' verificato un errore.\n");
			break;
	}

	printf("\tEsecuzione terminata!\n\n");

	return(0);
}
