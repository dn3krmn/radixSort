#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radix.h"

//0-9 -> 10 rakam vardır.
#define rakam 10

// double linked list kullanarak bir liste oluşturuldu. 
llist *createList(void) {
	//listeye ve kutuya eleman eklemek için node ve box oluşturuldu ve bunlara bellekte yer ayırtıldı.
	NODE *node = malloc (sizeof(NODE));    
	llist *box = malloc (sizeof(llist));
	box->head = node;   
	node->prev = node;
	node->next = node;  	      
	box->sayac = 0;
	return (box);
}


//listede yer alan eleman sayısını verir.
int elemanSayisi (llist *box) {
	return (box->sayac);
}


//listenin sonuna tamsayı ekler.
void ekle (llist *box, int k) {
	//eleman eklemek için düğüm oluşturuldu ve ona bellekte yer tahsis edildi.
	NODE *node = malloc (sizeof(NODE));
	node->key = k;		//node un keyine veri atandı.
	node->next = box->head;		//eklenen düğümün nextine box un head i atandı. 
	node->prev = box->head->prev;		//eklenen düğümün previne box daki ilk düğümün prev i atandı.
	node->prev->next = node;		//önceki düğümün nextine eklenen düğümün adresi atandı.
	box->head->prev = node;		    //box un ilk düğümünün prev işaretçisine node atandı.
	box->sayac++;   //listeye eleman eklendiği için eleman sayısı artırılır.
}


//listenin başından eleman silme ve bellekten ayrılan yeri serbest bırakma
int bastanSil (llist *box) {
	int s;
	box->head->next = box->head->next->next;		//kovadaki ilk düğümün nextine bir sonraki düğümünün nexti atandı.
	s = box->head->next->prev->key;			//s değişkenine  boxa eklenen düğümden bir önceki düğümün keyi atandı. 
	free (box->head->next->prev);           //boxdaki düğümün prev pointerının işaret ettiği adres  için bellekte ayırılan yeri serbest bırakma
	box->head->next->prev = box->head;		//boxda silinen düğümden sonra gelen düğümün prev işaretçisine boxdaki listenin başını gösteren head işaretçisini atanıyor.
	box->sayac--;      //listeden eleman silindiği için eleman sayısı azaltılır.
	return (s);
}

//listenin sonundan eleman silme ve bellekten ayrılan yeri serbest bırakma
int sil (llist *box) {
	int s;
	box->head->prev = box->head->prev->prev;		//boxdaki nodeun prev işaretçisine bir önceki nodun previ atanıyor.
	s = box->head->prev->next->key;					//s değişkenine kutuya eklenen sonraki elemanın keyi atandı.
	free (box->head->prev->next);					//boxdan silinen bir önceki node un next işaretçisininin gösterdiği adres için bellekte ayırılan yeri serbest bırakma
	box->head->prev->next = box->head;              // silinen düğümden bir önceki düğümün next işaretçisine boxdaki listenin başını gösteren head işaretçisini atanıyor.
	box->sayac--;      //listeden eleman silindiği için eleman sayısı azaltılır.
	return (s);
}



//Radix Sort
void radixSort(llist *arr){
	int i,j,sayiDegeri,sayi;
	//10 tabanında her sayı 0-9 rakamlarından oluşur, bu yüzden 10 tane box oluşturuldu. 
	llist *box[rakam];
	for (i = 0; i < rakam; i++) {
		box[i] = createList(); //boş kovalar dizisi oluşturuyor.
	}

    //LSB'ye göre sıralama
	int significantDigit = 1;
	i = 0;
    
    //Tüm anlamlı basamaklar için döngü
	while (significantDigit) {
		significantDigit = 0; // Sadece en az anlamlı basamak için hesaplama yapıyorsak 0 olur.

        //listeden kaldır ve box'a ekle
		/*
		sayıDeğeri hesaplama
		(126/10^0)%10
		(126/10^1)%10
		(126/10^2)%10
    	(sayi/(pow(10,i)))%10
		*/
		while(elemanSayisi(arr) != 0) {
			sayi = bastanSil(arr);
			sayiDegeri = (sayi / ((int)pow(10,i))) % 10;   //basamağa göre sıralama yapıldığı için basamakların sayı değerleri bulunuyor
			ekle(box[sayiDegeri], sayi);

			if ((sayi / ((int)pow(10,i))) > 0) {
				significantDigit = 1;
			}
		}

        	//Sırayla box'dan çıkartma ve listeye ekleme işlemi gerçekleştiriliyor.
		for (j = 0; j < rakam; j++) {
			while (elemanSayisi(box[j]) != 0) {
				sayi = bastanSil(box[j]);
				ekle(arr,sayi);
			}
		}

		i++;
	}
}

//Ekrana yazdırma fonksiyonu
void yazdir(llist *sirala){
	int i,j;
	for (i = 0; i < elemanSayisi(sirala); i++) {
		j = bastanSil(sirala);
		printf ("%d\n", j);
		ekle(sirala,j);
	}
}