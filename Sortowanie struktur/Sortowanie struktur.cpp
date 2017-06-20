// Sortowanie struktur.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct czlowiek {
	char imie_nazwisko[50];
	double zarobki;
	struct Czlowiek *next;
	struct Czlowiek *prev;

} Czlowiek;


void Sort(Czlowiek *head, Czlowiek *tail, int n)
{
	Czlowiek *a=(Czlowiek*)0, *b= (Czlowiek*)0, *c= (Czlowiek*)0, *d= (Czlowiek*)0;
	int zmiany = 1;
	int i = 0;

	while (zmiany != 0)
	{
		zmiany = 0;
		i = 0;
		for (b=head; i<n-2; b=b->next, i++)
		{

			a = b->prev;
			c = b->next;
			d = c->next;

			if (b->zarobki < c->zarobki)
			{
				if (a == (Czlowiek*)0)
				{
					zmiany++;
					head = c;
					b->prev = c;
					b->next = d;
					c->next = b;
					c->prev = (Czlowiek*)0;
					d->prev = b;
				}
				else if (d == (Czlowiek*)0)
				{
					zmiany++;
					tail = b;
					a->next = c;
					c->next = b;
					c->prev = a;
					b->next = (Czlowiek*)0;
					b->prev = c;

				}
				else
				{
					zmiany++;
					c->next = b;
					c->prev = a;
					a->next = c;
					b->next = d;
					b->prev = c;
					d->prev = b;
				}
			}

		}//petla
	}//petla
	i = 0;

}

void WypiszStrukture(Czlowiek *head, int n)
{
	printf("\nWypis wczytanych danych: ");
	int i = 0;
	for (Czlowiek *temp = head; i<n; temp = temp->next, i++)
	{
		printf("\n%s   %lf", temp->imie_nazwisko, temp->zarobki);

	}
}
int main()
{
	Czlowiek *head = NULL;
	Czlowiek *tail = NULL;
	Czlowiek *a = NULL;
	Czlowiek *temp = NULL;
	int n=0;
		
	printf("Podaj ilosc osob do wczytania: ");
	scanf("%d", &n);
	if (n <= 0) exit(4);

	head = malloc(sizeof(Czlowiek));
	a = head;
	head->prev = NULL;
	for (int i = 0; i < n; i++)
	{
		printf("Podaj imie i nazwisko (bez spacji :> ), oraz zarobki: ");
		scanf("%s %lf", a->imie_nazwisko, &(a->zarobki));
		temp = a;
		a = NULL;
		a = malloc(sizeof(Czlowiek));
		temp->next = a;
		a->prev = temp;
	}
	remove(a);
	
	temp->next = NULL;
	tail = temp;
		
	
	WypiszStrukture(head, n);
	Sort(head, tail, n);
	WypiszStrukture(head, n);
	getchar();
	getchar();
    return 0;
}

