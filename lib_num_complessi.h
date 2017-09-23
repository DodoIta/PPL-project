/* ridefinizione delle costanti simboliche */

#define PI_GRECO 3.14

/* ridefinizione dei tipi */

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

/* ridichiarazione delle funzioni da esportare */

extern void acquisisci_e_stampa(void);				/* funzione che acquisisce un numero complesso e lo stampa a video */
extern void somma_num_compl(void);				/* funzione che fa la somma di due numeri complessi */
extern void differenza_num_compl(void);				/* funzione che effettua la differenza tra due numeri complessi */
extern void prodotto_num_compl(void);				/* funzione che calcola il prodotto di due numeri complessi */
extern void rapporto_num_compl(void);				/* funzione che effettua la divisione tra due numeri complessi */
