#include <stdio.h>
#define A 25
#define B 50

void ikinciAsama(int veriler[A][B]);
int main(int argc, const char * argv[]) {
   
  
    
       int i,j;
            
               int veriler[A][B];
               
       for(i=0;i<A;i++) {
           for( j=0;j<B;j++) {
               const deger = rand() % 2; //rastgele 0 veya 1 üretme
               veriler[i][j]=deger;
           }
       }
       
    ////rastgele üretilen sayý 0 ise +,deðil ise -
        for ( i = 0; i < A; i++)
        {
        	int j;
            for (j = 0; j < B; j++)
            {
                if (veriler[i][j] == 0)
                    printf("-");
                else
                    printf("+");
            }
            printf("\n");
        }
        printf("\n");
    
       ikinciAsama(veriler);
     
    
    return 0;
}
void ikinciAsama(int veriler[A][B])
    {
    	int sonrakiVeriler[A][B];
    	int k;
		for(k=0;k<50;k++) {
			
		sleep(1);//milisaniye cinsinden gecikme
    	system("cls");//ölen,doðan komþularý görmemiz için ekranýn temizlenmesi
    	
		
  			int l,m,i,j;
        // Tüm hücreleri teker teker gezme
        for ( l = 1; l < A - 1; l++)
        {
            for ( m = 1; m < B - 1; m++)
            {
                  
                 // yaþayan komþu sayýsýný bulma
                int yasayanKomsu = 0;
                for ( i = -1; i <= 1; i++)
                    for ( j = -1; j <= 1; j++)
                        yasayanKomsu += veriler[l + i][m + j];
  
                yasayanKomsu -= veriler[l][m];
  
               
  
                // ölen Hücreler
                if ((veriler[l][m] == 1) && (yasayanKomsu < 2))
                    sonrakiVeriler[l][m] = 0;
  
                // Hücre öldü
                else if ((veriler[l][m] == 1) && (yasayanKomsu > 3))
                    sonrakiVeriler[l][m] = 0;
  
                // Hücre dogdu
                else if ((veriler[l][m] == 0) && (yasayanKomsu == 3))
                   sonrakiVeriler[l][m]  = 1;
  
                
                else
                    sonrakiVeriler[l][m]  = veriler[l][m];
            }
        }
  
        //ölen-doðan komþulara göre deðiþen hali
        for ( i = 0; i < A; i++)
        {
            for ( j = 0; j < B; j++)
            {
                if (sonrakiVeriler[i][j] == 0)
                    printf("-");
                else
                    printf("+");
            }
            printf("\n");
        }
        
         for ( i = 0; i < A; i++)
        {
            for ( j = 0; j < B; j++)
            {
            	veriler[i][j] = sonrakiVeriler[i][j];
                sonrakiVeriler[i][j] = 0;
            }
            printf("\n");
        }
         
		}
		
        
    }

