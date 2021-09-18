#ifndef RADIX_H
#define RADIX_H

/* Double linked list algoritması kullanıldığı için her düğümün key adında verileri tutacağı bir değişkeni ile
 * kendinden önceki ve sonraki düğümlerin adreslerini tutacak next ve prev isminde iki pointer var.
*/

typedef struct node{
    int key;
    struct node *next;
    struct node *prev;
}NODE;

/* bucket sort kullanıldığı için box da tutulacak elemanların sayısını tutmak için sayaç değişkeni
 * ve box daki listenin başını gösteren head pointerı var.
*/
typedef struct list{
    int sayac;
    NODE *head;
} llist;


llist *createList(void);        //Linked List oluşturma
int elemanSayisi (llist *box);
void ekle (llist *box, int k);  //Linked Liste eleman ekleme
int bastanSil (llist *box);
int sil (llist *box);           //Linked Listden eleman silme
void radixSort(llist *box);     
void yazdir(llist *sirala);

#endif //RADIX_H