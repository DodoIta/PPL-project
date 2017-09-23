/* Direttive al preprocessore */

#include <stdio.h>
#include <math.h>

#define PI_GRECO 3.14

/* Definizione dei tipi */

typedef struct num_compl_alg		/* forma algebrica di un numero complesso */
{
	double  parte_reale,		/* parte reale */
	        parte_imm;		/* parte immaginaria */
}num_compl_alg_t;

typedef struct num_compl_tri		/* forma trigonometrica di un numero complesso */
{
	double  modulo,			/* modulo di un numero complesso (reale positivo) */
		argomento;		/* argomento di un numero complesso */	
}num_compl_tri_t;

/* Dichiarazione delle funzioni */

void acquisisci_e_stampa(void);					/* funzione che acquisisce un numero complesso e lo stampa a video */
void inizializza_strutt(num_compl_alg_t, num_compl_tri_t);	/* funzione che inizializza le strutture per i numeri complessi */
void somma_num_compl(void);					/* funzione che fa la somma di due numeri complessi */
void inizializza_compl_alg(num_compl_alg_t, num_compl_alg_t);	/* simile ad inizializza_strutt, ma riceve in ingresso due num_compl_alg_t */
void stampa_alg(num_compl_alg_t);				/* funzione che stampa a video un numero complesso in forma algebrica */
void stampa_tri(num_compl_tri_t);				/* funzione che stampa a video un numero complesso in forma trigonometrica */
num_compl_alg_t acquisisci_compl_alg(void);			/* restituisce un numero complesso in forma algebrica immesso dall'utente */
num_compl_tri_t acquisisci_compl_tri(void);			/* restituisce un numero complesso in forma trigonometrica immesso dall'utente */
void differenza_num_compl(void);				/* funzione che effettua la differenza tra due numeri complessi */
void prodotto_num_compl(void);					/* funzione che calcola il prodotto di due numeri complessi */
int convalida_scelta(void);					/* funzione che acquisisce correttamente la scelta dell'utente */
void rapporto_num_compl(void);					/* funzione che effettua la divisione tra due numeri complessi */

/* Definizione delle funzioni */

void inizializza_strutt(num_compl_alg_t compl_1, num_compl_tri_t compl_2)
{
	compl_1.parte_reale = 0;
	compl_1.parte_imm = 0;

	compl_2.modulo = 0;
	compl_2.argomento = 0;
}

/*****************************************************************************************************************************************/

void inizializza_compl_alg(num_compl_alg_t num_1, num_compl_alg_t num_2)
{
	num_1.parte_reale = 0;
	num_1.parte_imm = 0;

	num_2.parte_reale = 0;
	num_2.parte_imm = 0;
}

/*****************************************************************************************************************************************/

int convalida_scelta(void)
{
	int esito_lettura;				/* lavoro: validazione stretta */
	char caratt_rimosso;				/* lavoro: validazione stretta */
	int scelta = 0;					/* output: scelta dell'utente */

	do								/** VALIDAZIONE STRETTA **/
	{
		printf("Digitare 1 per la forma algebrica o 2 per la forma trigonometrica: ");
		esito_lettura = scanf("%d",
					&scelta);
		if (esito_lettura != 1 || scelta < 1 || scelta > 2)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1 || scelta < 1 || scelta > 2);		/** FINE VALIDAZIONE STRETTA **/

	return(scelta);
}

/*****************************************************************************************************************************************/

void stampa_alg(num_compl_alg_t numero)
{
	char parentesi_1 = '(',				/* lavoro: stampa a video */
	     parentesi_2 = ')';				/* lavoro: stampa a video */
	
	/* stampo nella forma a + ib = numero complesso, con a parte reale e b parte immaginaria */
	if (numero.parte_imm >= 0)
		printf("%.2f + %.2f i.\n\n",
			numero.parte_reale,
			numero.parte_imm);
	else
		printf("%.2f + %c%.2f%c i.\n\n",
			numero.parte_reale,
			parentesi_1,
			numero.parte_imm,
			parentesi_2);
}

/*****************************************************************************************************************************************/

void stampa_tri(num_compl_tri_t numero)
{
		/* stampo nella forma r[cos(teta) + i sin(teta)] = numero complesso, con teta argomento ed r modulo */
		if (numero.argomento == 10)		/* caso in cui l'argomento è indefinito (a = 0, b = 0) */
			printf("indefinito (parte reale ed immaginaria uguali a zero!)\n\n");
		else
		{
			printf("%.2f[cos(%.2f) + i sin(%.2f)].\n",
				numero.modulo,
				numero.argomento,
				numero.argomento);
			printf("***    Notare che l'argomento e' espresso in radianti!    ***\n");
		}
}

/*****************************************************************************************************************************************/

num_compl_alg_t acquisisci_compl_alg(void)
{
	int esito_lettura;				/* lavoro: validazione stretta */
	char caratt_rimosso;				/* lavoro: validazione stretta */
	num_compl_alg_t numero;				/* variabile per memorizzare in numero in forma algebrica */

	/* acquisisco la parte reale */
	do								/** VALIDAZIONE STRETTA **/
	{
		printf("Inserire la parte reale: ");
		esito_lettura = scanf("%lf",
					&numero.parte_reale);
		if (esito_lettura != 1)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1);					/** FINE VALIDAZIONE STRETTA **/

	/* acquisisco la parte immaginaria */
	do								/** VALIDAZIONE STRETTA **/
	{
		printf("Inserire la parte immaginaria (escludendo i, che verra' aggiunta automaticamente): ");
		esito_lettura = scanf("%lf",
					&numero.parte_imm);
		if (esito_lettura != 1)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1);					/** FINE VALIDAZIONE STRETTA **/

	return(numero);
}

/*****************************************************************************************************************************************/

num_compl_tri_t acquisisci_compl_tri(void)
{
	int esito_lettura;				/* lavoro: validazione stretta */
	char caratt_rimosso;				/* lavoro: validazione stretta */
	num_compl_tri_t numero;				/* variabile per memorizzare il numero in forma trigonometrica */

	do								/** VALIDAZIONE STRETTA **/
	{
		printf("Inserire il modulo (si ricorda che deve essere reale positivo): ");
		esito_lettura = scanf("%lf",
					&numero.modulo);
		if (esito_lettura != 1 || numero.modulo < 0)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1 || numero.modulo < 0);		/** FINE VALIDAZIONE STRETTA **/

	do								/** VALIDAZIONE STRETTA **/
	{
		printf("Inserire l'argomento (in radianti): ");
		esito_lettura = scanf("%lf",
					&numero.argomento);
		if (esito_lettura != 1 || numero.argomento < 0 || numero.argomento > 6.28)
		{
			printf("Input non valido!\n");
			do
				caratt_rimosso = getchar();
			while (caratt_rimosso != '\n');
		}
	}
	while (esito_lettura != 1 || numero.argomento < 0 || numero.argomento > 6.28);	/** FINE VALIDAZIONE STRETTA **/

	return(numero);
}

/*****************************************************************************************************************************************/

void acquisisci_e_stampa(void)
{
	num_compl_alg_t forma_alg;			/* variabile per la forma algebrica */
	num_compl_tri_t forma_tri;			/* variabile per la forma trigonometrica */
	int scelta = 0;					/* memorizza la scelta tra forma algebrica(1) e trigonometrica(2) */

	/** inizializzo le strutture **/
	inizializza_strutt(forma_alg, forma_tri);

	/** scelta della forma **/
	printf("Scegliere se si vuole esprimere il numero complesso in forma algebrica o trigonometrica.\n\n");
	scelta = convalida_scelta();

	/** acquisizione della forma e relativa conversione **/
	if (scelta == 1)		/* forma algebrica: acquisisco e converto in forma trigonometrica */
	{
		/* acquisisco il numero dall'utente */
		forma_alg = acquisisci_compl_alg();

		/* stampo nella forma a + ib = numero complesso, con a parte reale e b immaginaria */
		printf("\nIl numero in forma algebrica inserito e' ");
		stampa_alg(forma_alg);

			/** conversione **/
		/* ricavo il modulo del numero */
		forma_tri.modulo = sqrt( pow(forma_alg.parte_reale, 2) + pow(forma_alg.parte_imm, 2) );

		/* ricavo l'argomento del numero (distinguo 6 casi) */
		if (forma_alg.parte_reale == 0 && forma_alg.parte_imm > 0)		/* a = 0, b > 0 */
			forma_tri.argomento = PI_GRECO / 2;
		else if (forma_alg.parte_reale == 0 && forma_alg.parte_imm < 0)		/* a = 0, b < 0 */
			forma_tri.argomento = 3 * (PI_GRECO / 2);
		else if (forma_alg.parte_reale == 0 && forma_alg.parte_imm == 0)	/* a = 0, b = 0 */
			forma_tri.argomento = 10;		/* non definito, assegno 10 per indicarlo */
		else if (forma_alg.parte_reale > 0 && forma_alg.parte_imm >= 0)		/* a < 0, b >= 0 */
			forma_tri.argomento = atan(forma_alg.parte_imm / forma_alg.parte_reale);
		else if (forma_alg.parte_reale > 0 && forma_alg.parte_imm < 0)		/* a > 0, b < 0 */
			forma_tri.argomento = atan(forma_alg.parte_imm / forma_alg.parte_reale) + (2 * PI_GRECO);
		else if (forma_alg.parte_reale < 0)					/* a < 0, b assume qualsiasi valore */
			forma_tri.argomento = atan(forma_alg.parte_imm / forma_alg.parte_reale) + PI_GRECO;

		/* stampo nella forma r[cos(teta) + i sin(teta)] = numero complesso, con teta argomento ed r modulo */
		printf("L'equivalente in forma trigonometrica e' ");
		stampa_tri(forma_tri);
	}
	else				/* forma trigonometrica: acquisisco e converto in forma algebrica */
	{
		/* acquisisco il numero dall'utente */
		forma_tri = acquisisci_compl_tri();

		/* stampo a video il numero complesso inserito in forma trigonometrica */
		printf("\nIl numero in forma trigonometrica inserito e' ");
		stampa_tri(forma_tri);

			/** conversione **/
		forma_alg.parte_reale = forma_tri.modulo * cos(forma_tri.argomento);	/* ricavo la parte reale */
		forma_alg.parte_imm = forma_tri.modulo * sin(forma_tri.argomento);	/* ricavo la parte immaginaria */

		/* stampo nella forma a + ib = numero complesso, con a parte reale e b parte immaginaria */
		printf("L'equivalente in forma algebrica e' ");
		stampa_alg(forma_alg);
	}
}/*** fine funzione acquisisci_e_stampa ***/

/*****************************************************************************************************************************************/

void somma_num_compl(void)
{
	num_compl_alg_t alg_1,				/* operando in forma algebrica */
			alg_2,				/* operando in forma algebrica */
			somma_alg;			/* somma di due numeri in forma algebrica */
	num_compl_tri_t tri_1,				/* operando in forma trigonometrica */
			tri_2;				/* operando in forma trigonometrica */
	num_compl_alg_t addendo_1,			/* primo addendo in forma trigonometrica convertito in forma algebrica */
			addendo_2,			/* secondo addendo in forma trigonometrica convertito in forma algebrica */
			somma_tri;			/* somma di due numeri complessi espressi in forma trigonometrica */
	int scelta = 0;					/* memorizza la scelta tra forma algebrica(1) e trigonometrica(2) */

	/** inizializzo le strutture **/
	inizializza_strutt(alg_1, tri_1);
	inizializza_strutt(alg_2, tri_2);
	inizializza_compl_alg(addendo_1, addendo_2);
	inizializza_compl_alg(somma_alg, somma_tri);

	/** scelta della forma **/
	printf("Scegliere se si vuole effettuare la somma tra numeri complessi in forma algebrica o trigonometrica.\n");
	scelta = convalida_scelta();

	if (scelta == 1)		/* forma algebrica: acquisisco gli operandi ed effettuo la somma */
	{
			/** acquisizione della forma algebrica e relativa somma **/
		printf("Primo addendo...\n");
		alg_1 = acquisisci_compl_alg();
		printf("Secondo addendo...\n");
		alg_2 = acquisisci_compl_alg();

		/* stampo a video il primo addendo */
		printf("\nIl primo addendo inserito e' ");
		stampa_alg(alg_1);

		/* stampo a video il secondo addendo */
		printf("Il secondo addendo inserito e' ");
		stampa_alg(alg_2);

		/* calcolo la somma in forma algebrica e la stampo a video */
		somma_alg.parte_reale = alg_1.parte_reale + alg_2.parte_reale;
		somma_alg.parte_imm = alg_1.parte_imm + alg_2.parte_imm;

		printf("La somma dei numeri complessi inseriti e' ");
		stampa_alg(somma_alg);
	}
	else				/* forma trigonometrica: acquisisco gli operandi ed effettuo la somma */
	{
			/** acquisizione della forma trigonometrica **/
		printf("Primo addendo...\n");
		tri_1 = acquisisci_compl_tri();
		printf("Secondo addendo...\n");
		tri_2 = acquisisci_compl_tri();

		/* stampo a video il primo addendo */
		printf("\nIl primo addendo inserito e' ");
		stampa_tri(tri_1);

		/* stampo a video il secondo addendo */
		printf("Il secondo addendo inserito e' ");
		stampa_tri(tri_2);

		/* calcolo la somma in forma trigonometrica e la stampo a video */
			/** conversione addendi in forma algebrica **/
		addendo_1.parte_reale = tri_1.modulo * cos(tri_1.argomento);		/* ricavo la parte reale del primo addendo */
		addendo_1.parte_imm = tri_1.modulo * sin(tri_1.argomento);		/* ricavo la parte immaginaria del primo addendo */

		addendo_2.parte_reale = tri_2.modulo * cos(tri_2.argomento);		/* ricavo la parte reale del secondo addendo */
		addendo_2.parte_imm = tri_2.modulo * sin(tri_2.argomento);		/* ricavo la parte immaginaria del secondo addendo */

			/** calcolo della somma in forma algebrica e stampa a video **/
		somma_tri.parte_reale = addendo_1.parte_reale + addendo_2.parte_reale;
		somma_tri.parte_imm = addendo_1.parte_imm + addendo_2.parte_imm;

		printf("La somma dei numeri complessi inseriti e' ");
		stampa_alg(somma_tri);
	}
}/*** fine funzione somma_num_compl ***/

/*****************************************************************************************************************************************/

void differenza_num_compl(void)
{
	num_compl_alg_t minuendo_alg,			/* operando in forma algebrica */
			sottraendo_alg,			/* operando in forma algebrica */
			differenza_alg;			/* differenza di due numeri in forma algebrica */
	num_compl_tri_t minuendo_tri,			/* operando in forma trigonometrica */
			sottraendo_tri;			/* operando in forma trigonometrica */
	num_compl_alg_t operando_1,			/* minuendo in forma trigonometrica convertito in forma algebrica */
			operando_2,			/* sottraendo in forma trigonometrica convertito in forma algebrica */
			differenza_tri;			/* differenza di due numeri complessi espressi in forma trigonometrica */
	int scelta = 0;					/* memorizza la scelta tra forma algebrica(1) e trigonometrica(2) */

	/** inizializzo le strutture **/
	inizializza_strutt(minuendo_alg, minuendo_tri);
	inizializza_strutt(sottraendo_alg, sottraendo_tri);
	inizializza_compl_alg(operando_1, operando_2);
	inizializza_compl_alg(differenza_alg, differenza_tri);

	/** scelta della forma **/
	scelta = convalida_scelta();

	if (scelta == 1)		/* forma algebrica: acquisisco gli operandi ed effettuo la differenza */
	{
			/** acquisizione della forma algebrica e relativa differenza **/
		printf("Minuendo...\n");
		minuendo_alg = acquisisci_compl_alg();
		printf("Sottraendo...\n");
		sottraendo_alg = acquisisci_compl_alg();

		/* stampo a video il minuendo */
		printf("\nIl minuendo inserito e' ");
		stampa_alg(minuendo_alg);

		/* stampo a video il sottraendo */
		printf("Il sottraendo inserito e' ");
		stampa_alg(sottraendo_alg);

		/* calcolo la differenza in forma algebrica e la stampo a video */
		differenza_alg.parte_reale = minuendo_alg.parte_reale - sottraendo_alg.parte_reale;
		differenza_alg.parte_imm = minuendo_alg.parte_imm - sottraendo_alg.parte_imm;

		printf("La differenza dei numeri complessi inseriti e' ");
		stampa_alg(differenza_alg);
	}
	else				/* forma trigonometrica: acquisisco gli operandi ed effettuo la differenza */
	{
			/** acquisizione della forma trigonometrica **/
		printf("Minuendo...\n");
		minuendo_tri = acquisisci_compl_tri();
		printf("Sottraendo...\n");
		sottraendo_tri = acquisisci_compl_tri();

		/* stampo a video il minuendo */
		printf("\nIl minuendo inserito e' ");
		stampa_tri(minuendo_tri);

		/* stampo a video il sottraendo */
		printf("Il sottraendo inserito e' ");
		stampa_tri(sottraendo_tri);

		/* calcolo la differenza in forma trigonometrica e la stampo a video */
			/** conversione operandi in forma algebrica **/
		operando_1.parte_reale = minuendo_tri.modulo * cos(minuendo_tri.argomento);	/* ricavo la parte reale del minuendo */
		operando_1.parte_imm = minuendo_tri.modulo * sin(minuendo_tri.argomento);	/* ricavo la parte immaginaria del minuendo */

		operando_2.parte_reale = sottraendo_tri.modulo * cos(sottraendo_tri.argomento);	/* ricavo la parte reale del sottraendo */
		operando_2.parte_imm = sottraendo_tri.modulo * sin(sottraendo_tri.argomento);	/* ricavo la parte immaginaria del sottraendo */

			/** calcolo della differenza in forma algebrica e stampa a video **/
		differenza_tri.parte_reale = operando_1.parte_reale - operando_2.parte_reale;
		differenza_tri.parte_imm = operando_1.parte_imm - operando_2.parte_imm;

		printf("La differenza dei numeri complessi inseriti e' ");
		stampa_alg(differenza_tri);
	}
}/*** fine funzione differenza_num_compl ***/

/*****************************************************************************************************************************************/

void prodotto_num_compl(void)
{
	num_compl_alg_t moltiplicando_alg,		/* moltiplicando in forma algebrica */
			moltiplicatore_alg,		/* moltiplicatore in forma algebrica */
			prodotto_alg;			/* prodotto di due numeri in forma algebrica */
	num_compl_tri_t moltiplicando_tri,		/* moltiplicando in forma trigonometrica */
			moltiplicatore_tri,		/* moltiplicatore in forma trigonometrica */
			prodotto_tri;			/* prodotto in forma trigonometrica di due numeri */
	int scelta = 0;					/* memorizza la scelta tra forma algebrica(1) e trigonometrica(2) */

	/** inizializzo le strutture **/
	inizializza_strutt(moltiplicando_alg, moltiplicando_tri);
	inizializza_strutt(moltiplicatore_alg, moltiplicatore_tri);
	inizializza_strutt(prodotto_alg, prodotto_tri);

	/** scelta della forma **/
	printf("Scegliere se si vuole effettuare il prodotto tra numeri complessi in forma algebrica o trigonometrica.\n");
	scelta = convalida_scelta();

	if (scelta == 1)		/* forma algebrica: acquisisco gli operandi ed effettuo il prodotto */
	{
			/** acquisizione della forma algebrica e relativo prodotto **/
		printf("Moltiplicando...\n");
		moltiplicando_alg = acquisisci_compl_alg();
		printf("Moltiplicatore...\n");
		moltiplicatore_alg = acquisisci_compl_alg();

		/* stampo a video il moltiplicando */
		printf("\nIl moltiplicando inserito e' ");
		stampa_alg(moltiplicando_alg);

		/* stampo a video il moltiplicatore */
		printf("Il moltiplicatore inserito e' ");
		stampa_alg(moltiplicatore_alg);

		/* calcolo il prodotto in forma algebrica e lo stampo a video */
		prodotto_alg.parte_reale = (moltiplicando_alg.parte_reale * moltiplicatore_alg.parte_reale) 
					   - (moltiplicando_alg.parte_imm * moltiplicatore_alg.parte_imm);
		prodotto_alg.parte_imm = (moltiplicando_alg.parte_reale * moltiplicatore_alg.parte_imm)
					 + (moltiplicando_alg.parte_imm * moltiplicatore_alg.parte_reale);

		printf("Il prodotto dei numeri complessi inseriti e' ");
		stampa_alg(prodotto_alg);
	}
	else				/* forma trigonometrica: acquisisco gli operandi ed effettuo la somma */
	{
			/** acquisizione della forma trigonometrica **/
		printf("Moltiplicando...\n");
		moltiplicando_tri = acquisisci_compl_tri();
		printf("Moltiplicatore...\n");
		moltiplicatore_tri = acquisisci_compl_tri();

		/* stampo a video il moltiplicando */
		printf("\nIl moltiplicando inserito e' ");
		stampa_tri(moltiplicando_tri);

		/* stampo a video il moltiplicatore */
		printf("Il moltiplicatore inserito e' ");
		stampa_tri(moltiplicatore_tri);

		/* calcolo il prodotto in forma trigonometrica e lo stampo a video */
		prodotto_tri.modulo = moltiplicando_tri.modulo * moltiplicatore_tri.modulo;
		prodotto_tri.argomento = moltiplicando_tri.argomento + moltiplicatore_tri.argomento;

		printf("Il prodotto dei numeri complessi inseriti e' ");
		stampa_tri(prodotto_tri);
	}
}/*** fine funzione prodotto_num_compl ***/

/*****************************************************************************************************************************************/

void rapporto_num_compl(void)
{
	num_compl_alg_t dividendo_alg,			/* dividendo in forma algebrica */
			divisore_alg,			/* divisore in forma algebrica */
			rapporto_alg;			/* rapporto di due numeri in forma algebrica */
	num_compl_tri_t dividendo_tri,			/* dividendo in forma trigonometrica */
			divisore_tri,			/* divisore in forma trigonometrica */
			rapporto_tri;			/* rapporto in forma trigonometrica di due numeri */
	int scelta = 0;					/* memorizza la scelta tra forma algebrica(1) e trigonometrica(2) */

	/** inizializzo le strutture **/
	inizializza_strutt(dividendo_alg, dividendo_tri);
	inizializza_strutt(divisore_alg, divisore_tri);
	inizializza_strutt(rapporto_alg, rapporto_tri);

	/** scelta della forma **/
	printf("Scegliere se si vuole effettuare il rapporto tra numeri complessi in forma algebrica o trigonometrica.\n");
	scelta = convalida_scelta();

	if (scelta == 1)		/* forma algebrica: acquisisco gli operandi ed effettuo il rapporto */
	{
			/** acquisizione della forma algebrica e relativo rapporto **/
		printf("Dividendo...\n");
		dividendo_alg = acquisisci_compl_alg();
		printf("Divisore...\n");
		divisore_alg = acquisisci_compl_alg();

		/* controllo che il denominatore sia diverso da zero */
		if (divisore_alg.parte_reale == 0 && divisore_alg.parte_imm == 0)	/* se denominatore = 0 */
			printf("Il divisore inserito e' uguale a zero, pertanto la divisione non e' possibile.\n");
		else									/* altrimenti proseguo e calcolo il rapporto */
		{
			/* stampo a video il dividendo */
			printf("\nIl dividendo inserito e' ");
			stampa_alg(dividendo_alg);
	
			/* stampo a video il divisore */
			printf("Il divisore inserito e' ");
			stampa_alg(divisore_alg);

			/* calcolo il rapporto in forma algebrica e lo stampo a video */
			rapporto_alg.parte_reale = ( (dividendo_alg.parte_reale * divisore_alg.parte_reale)
						   + (dividendo_alg.parte_imm * divisore_alg.parte_imm) )
						   / ( pow(divisore_alg.parte_reale, 2) + pow(divisore_alg.parte_imm, 2) );
			rapporto_alg.parte_imm = ( (dividendo_alg.parte_imm * divisore_alg.parte_reale)
						 - (dividendo_alg.parte_reale * divisore_alg.parte_imm) )
						 / ( pow(divisore_alg.parte_reale, 2) + pow(divisore_alg.parte_imm, 2) );
	
			printf("Il rapporto dei numeri complessi inseriti e' ");
			stampa_alg(rapporto_alg);
		}
	}
	else				/* forma trigonometrica: acquisisco gli operandi ed effettuo la somma */
	{
			/** acquisizione della forma trigonometrica **/
		printf("Dividendo...\n");
		dividendo_tri = acquisisci_compl_tri();
		printf("Divisore...\n");
		divisore_tri = acquisisci_compl_tri();

		/* controllo che il denominatore sia diverso da zero */
		if (divisore_tri.modulo == 0)						/* se divisore = 0 */
			printf("Il divisore inserito e' uguale a zero, pertanto la divisione non e' possibile.\n");
		else
		{
			/* stampo a video il dividendo */
			printf("\nIl dividendo inserito e' ");
			stampa_tri(dividendo_tri);
	
			/* stampo a video il divisore */
			printf("Il divisore inserito e' ");
			stampa_tri(divisore_tri);
	
			/* calcolo il rapporto in forma trigonometrica e lo stampo a video */
			rapporto_tri.modulo = dividendo_tri.modulo / divisore_tri.modulo;
			rapporto_tri.argomento = dividendo_tri.argomento - divisore_tri.argomento;
	
			printf("Il rapporto dei numeri complessi inseriti e' ");
			stampa_tri(rapporto_tri);
		}
	}
}/*** fine funzione rapporto_num_compl ***/
