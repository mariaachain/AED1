int main() {  

 int N; 
printf ("Digite o tamanho do vetor: ");
scanf("%d", &N);

 int X[N]; 
 int i; 


printf ("Digite os %d valores do vetor: \n", N);
 for (i = 0; i < N; i++) { 
  scanf("%d", &X[i]); 
} 

int menor = X[0]; 
int posicao = 0; 


for (i = 1; i < N; i++) { 
if (X[i] < menor) { 
 menor = X[i]; 
 posicao = i; 
  } 
} 

return 0; 
}
