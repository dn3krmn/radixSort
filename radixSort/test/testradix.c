#include <stdio.h>
#include <stdlib.h>
#include "radix.h"


int main (void) {
	
    //sıralanacak elemanları eklemek için liste oluşturma
	llist *sirala = createList();

	//listeye eleman ekleme
	ekle(sirala, 45);
	ekle(sirala, 124);
	ekle(sirala, 777);
	ekle(sirala, 1);
	ekle(sirala, 1998);
	ekle(sirala, 155);
	ekle(sirala, 7);
	ekle(sirala, 26);
	ekle(sirala, 226);

	//Dizinin sıralanmamış hali
	printf ("Dizinin sıralanmamış hali:\n");
	yazdir(sirala);

	//listeye/diziye eklenen elemanları sıralamak için radixSort fonksiyonu çağırılıyor
    radixSort(sirala);

	printf ("\nDizinin sıralanmış hali:\n");
	yazdir(sirala);
	
	//sıralanan Listeden eleman silme
	bastanSil(sirala);
	sil(sirala);
	printf ("\nSıralanan Listenin İlk ve Son Elemananını Silme:\n");
	yazdir(sirala);

}