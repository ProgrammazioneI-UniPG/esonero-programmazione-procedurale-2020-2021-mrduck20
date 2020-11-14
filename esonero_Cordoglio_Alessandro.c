#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Inizializzazione di tutte le variabili ed array all'interno della funzione main
int main() {

  time_t t;
  int i=0;
  int x;
  int n=129;
  int lcifrato;
  char plaintext[n];
  char chiave[n];
  char testocifrato[n];
  char testodecifrato[n];
  int ch;
//Richiesta all'utente di una stringa, controllata tramite fgets, viene poi mostrata a schermo ed inserita nell'array
  printf("Inserisci la stringa da cifrare: ");
  fgets (plaintext, n , stdin );
  while((ch=getchar()!='\n' && ch!=EOF)); //per pulire il buffer (nel programma bisogna dare doppio invio dopo l'immissione della stringa per motivi a me sconosciuti)
  printf("La stringa inserita è: %s", plaintext);

  printf("\n1)Seleziona '1' da tastiera se vuoi inserire tu la chiave di cifratura\n"
         "2)Seleziona '2' da tastiera se vuoi che la chiave sia generata randomicamente\n");


inizio: //label a cui posso ritornare in caso di errori durante l'esecuzione del programma
  scanf("%d", &x );
  getchar();
/*Tutto questo if riguarda il caso della prima scelta da parte dell'utente, se non viene rispettata
  la condizione l'utente verrà riportato alla decisione delle alternative*/
    if (x==1){

      printf("\ninserisci la chiave di cifratura\n");

opzione:
      fgets (chiave, n , stdin );
      printf("La chiave è: %s \n", chiave);
      /*Controllo di eventuali errori di scrittura dell'utente della chiave con un if annidato,
        Se la condizione viene rispettata si entra nel ciclo while che eseguirà l'operazione di XOR
        Nel caso contrario si richiede un'altra chiave all'utente*/
        if (strlen(plaintext)<=strlen(chiave)) {
          //Cifratura
          while (i<strlen(plaintext)) {
            testocifrato[i]=plaintext[i]^chiave[i];
            i++;
          }
          lcifrato=strlen(testocifrato);
          printf("Testo cifrato: %p \n", testocifrato); //il pointer %p mi mostra il testo in esadecimale
          printf("Lungezza testo cifrato: %d \n", lcifrato );
          //Decifratura
          i=0;
          while (i<strlen(plaintext)) {
            testodecifrato[i]=testocifrato[i]^chiave[i];
            i++;
          }
          printf("\nTesto decifrato: %s\n", testodecifrato);
        }

      else {
        printf("ERRORE: chiave troppo piccola! Inseriscine un'altra che sia grande almeno quanto la stringa\n");
        goto opzione; //punto di ritorno alla label
        }
    }

//Inizio seconda alternativa
    else if (x==2) {
      srand((unsigned) time(&t));
      char chiave[i];
      //generazione di una chiave random
      for (i=0; i <strlen(plaintext);  i++) {
        chiave[i] += 'A'+(rand() % 128);
      }
      printf("La chiave generata è: %s\n", chiave );
      printf("La lunghezza della chiave è:%ld\n", strlen(chiave));

      //Cifratura
      i=0;
      while (i<strlen(plaintext)) {
        testocifrato[i]=plaintext[i]^chiave[i];
        i++;
      }
      lcifrato=strlen(testocifrato);
      printf("\nTesto cifrato: %s\n ", testocifrato);
      printf("Lungezza testo cifrato: %d\n", lcifrato );
      //Decifratura
      i=0;
      while (i<strlen(plaintext)) {
        testodecifrato[i]=testocifrato[i]^chiave[i];
        i++;
      }
      printf("\nTesto decifrato: %s\n ", testodecifrato);

    }

    else {
      printf("ERRORE: inserisci '1' o '2'\n");
      goto inizio;
    }

}
