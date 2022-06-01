#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void n (char *p_i)
{
	int sz;
	char c;
	FILE *f;
	int i = 0;
	
	if(p_i != NULL)
	{
		free(p_i);
		if((f = fopen("DNAsekvencia.txt", "r")) == NULL)
		{
			printf("Neotvoreny subor\n");
			exit(0);
		}
	
	fseek(f, 0L, SEEK_SET);		//nastavenie sa na zaciatok suboru

	while((c = fgetc(f)) != EOF)
	{	
	if (!(c == 'a' || c == 'A' || c == 'c' || c == 'C' || c == 'g' || c == 'G' || c == 'T' || c == 't'))
 		{
			printf("Sekvencia nesplna podmienky\n");		
			exit(0);
		}
	}
	
	fseek(f, 0L, SEEK_SET);	
	
	i = 0;
	while((c = getc(f)) != EOF)
	{
		p_i[i] = c;
		i++;
	}
	if(!(p_i[0] == '\0'))
	{
		printf("Sekvenciu sa podarilo nacitat\n");
	}
	}
	
	else
	{
		if((f = fopen("DNAsekvencia.txt", "r")) == NULL)
		{
			printf("Neotvoreny subor\n");
			exit(0);
		}
	
	fseek(f, 0L, SEEK_SET);		//nastavenie sa na zaciatok suboru

	
	while((c = fgetc(f)) != EOF)
	{	
	if (!(c == 'a' || c == 'A' || c == 'c' || c == 'C' || c == 'g' || c == 'G' || c == 'T' || c == 't'))
 		{
			printf("Sekvencia nesplna podmienky\n");		
			exit(0);
		}
	}
	
	fseek(f, 0L, SEEK_SET);	
	
	i = 0;
	while((c = getc(f)) != EOF)
	{
		p_i[i] = c;
		i++;
	}
	if(!(p_i[0] == '\0'))
	{
		printf("Sekvenciu sa podarilo nacitat\n");
	}
}
}

void v (char *pole, int dlzka)
{
	int z, k, i;	
	
		if(pole[0] == '\0')				//ak je na 1. mieste nic, pole je prazdne
	{
		printf("Sekvencia nie je nacitana\n");
		exit(0);
	}
	
	printf("Zadajte 2 cele cisla 'z' a 'k'.\nCislo 'z' musi byt vacsie ako 1\na cislo 'k' musi byt vacsie ako 'z'\n");
	scanf("%d %d", &z, &k);

	if(z > dlzka || k < z || k > dlzka)
	{
		printf("Zadanu podsekvenciu nie je mozne vypisat\n");		//ak zaciatok je vacsie miesto ako dlzka sekvencie || koniec podsekvencie je na nizsom miesto ako zaciatok 
		exit(0);													//alebo ak je koniec na vyssom mieste ako je dlzka
	}
	for(i = z; i <=k; i++)
	{
		printf("%c", pole[i-1]);
	}
	printf("\n");	
}

void h(char *pole, int dlzka)
{
	int pocet_a = 0;
	int pocet_c = 0;
	int pocet_g = 0;
	int pocet_t = 0;
	int i;
	
		if(pole[0] == '\0')
		{
			printf("Sekvencia nie je nacitana\n");
			exit(0);
		}
		
		for(i = 0; i < dlzka; i++)		//prechadzam pole
		{
			if(pole[i] == 'A' || pole[i] == 'a')
				pocet_a++;

			else if(pole[i] == 'C' || pole[i] == 'c')
				pocet_c++;
			
			else if (pole[i] == 'G' || pole[i] == 'g')
				pocet_g++;
			
			else if(pole[i] == 'T' || pole[i] == 't')
				pocet_t++;
		}
		
		printf("A: %d\n", pocet_a);			//vypisuje pocty
		printf("C: %d\n", pocet_c);
		printf("G: %d\n", pocet_g);
		printf("T: %d\n", pocet_t);
}

void p(char *pole, int dlzka)
{
	int d, i, j, k, dlzka_podsekvencie;
	printf("Zadajte velkost podsekvencie: \n");
	scanf("%d", &d);			// velkost podsekvencie
	char podsekvencia[d];		// kde zapisem podsekvenciu
	printf("Zadajte podsekvenciu: \n");
	scanf("%s", podsekvencia);
	
	dlzka_podsekvencie = strlen(podsekvencia);
	if(dlzka_podsekvencie > d) podsekvencia[d] = '\0';
	if(dlzka_podsekvencie < d) d = dlzka_podsekvencie;
	
	   for(i=0;i<strlen(podsekvencia);i++){
        podsekvencia[i] = toupper(podsekvencia[i]);
    }

    char* pos = pole;
    for(i = 0; i < strlen(pos); i++)
    {
    	pos[i] = toupper(pos[i]);
	}

    while (pos) {
        pos = strstr(pos, podsekvencia);
        if (pos) {
            printf("%d ", pos-pole+1);	// pos-pole+1 je miesto na ktorom sa nachadza zaciatok podsekvencie
			for(i = pos-pole-d; i <= pos-pole+d+3; i++)
			{
				if(i < 1) printf("-");
				else if (i > dlzka) printf("-");
				else printf("%c", (toupper(pole[i-1])));
			}
			printf("\n");
            pos++;  // preskoèí jeden znak
        }
    }
}

void l(char *pole, int dlzka)
{
	int p, d, i, dlzka_podsekvencie;
	char *podsekvencia;
	
	if(pole[0] == '\0')
	{
		printf("Sekvencia nie je nacitana\n");
		exit(0);
	}

	printf("Zadajte poziciu na vlozenie a dlzku podsekvencie\n");
	scanf("%d %d", &p, &d);
		
	if((podsekvencia = (char *) calloc(d, sizeof(char))) == NULL)		//polu pridelim pamat
	printf("Nepodarilo sa pridelit pamat\n");
	
	printf("Zadajte podsekvenciu: \n");
	
	scanf("%s", podsekvencia);
	dlzka_podsekvencie = strlen(podsekvencia);
	if(dlzka_podsekvencie > d) podsekvencia[d] = '\0';
	if(dlzka_podsekvencie < d) d = dlzka_podsekvencie;

	if(p < 1 || p > dlzka + 1)
	{
		printf("Do sekvencie nie je mozne sekvenciu vlozit\n");
		exit(0);
	}
	
	p = p-1;
	pole = (char *) realloc(pole, pole + ((sizeof(char) * d)));		//zvacsim pole
	
	int dlzka_vysledku = strlen(pole) + strlen(podsekvencia) + 1;
	char* vysledok = (char*)malloc(dlzka_vysledku);
	strncpy(vysledok, pole, p);
	vysledok[p] = '\0';
	strcat(vysledok, podsekvencia);
	strcat(vysledok, pole + p);
	pole = vysledok;
	printf("Podsekvencia vlozena\n");
}

void o(char *pole, int dlzka) //dlzka je pocet prvkov
{
 	int i,j,max=0,rozdiel;
 	char znak;
 	
 	for(i=0;i<dlzka;i++)
 	{
		znak = (toupper(pole[i]));
		j=i;
		while((toupper(pole[j]))== znak && j < dlzka) j++;
		
		rozdiel = j-i;
		if(rozdiel > max) max = rozdiel;		 	 
	} 	
 	
	printf("Najdlhsie useky opakujucich sa nukleotidov: %d\n", max);
	
	for(i=0;i<dlzka;i++)
 	{
		znak = (toupper(pole[i]));
		j=i;
		while((toupper(pole[j])) == znak && j < dlzka) j++;
		
		rozdiel = j-i;
		if(rozdiel == max) 	printf("%c %d\n",znak, i);	 	 
	}	
}
			//urobim si pole ktore poslem ako argument so smernikom
int main()
{
	char *hlavne, prikaz;
	FILE *f;
	int velkost_suboru;
	int i;
	
	if((f = fopen("DNAsekvencia.txt", "r")) == NULL)	//otvorim subor nech zistim velkost suboru
		{
			printf("Neotvoreny subor\n");
			exit(0);
		}
	
	fseek(f, 0L, SEEK_END);					//nastavenie sa na koniec suboru
	velkost_suboru = ftell(f);				//zistuje velkost suboru
	printf("%d\n", velkost_suboru);			//vypisuje velkost suboru
	
	if((hlavne = (char *) calloc(velkost_suboru, sizeof(char))) == NULL)		//polu pridelim pamat
		printf("Nepodarilo sa pridelit pamat\n");
	
 	printf("Zadajte prikaz: \n");
 	while(scanf("%c", &prikaz) != 'k')
	{	if(prikaz == 'n') n(hlavne);
		else if(prikaz == 'v') v(hlavne, velkost_suboru);
		else if (prikaz == 'h') h(hlavne, velkost_suboru);
		else if(prikaz == 'l') l(hlavne, velkost_suboru);
		else if(prikaz == 'o') o(hlavne, velkost_suboru);
		else if (prikaz == 'k') 
			{
				free(hlavne);
				return 0;
			}
	}
	return 0;	
}
