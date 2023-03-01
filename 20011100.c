#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>

int main() {
//de�i�ken tan�mlama
	int zorluk,kenar,i,j,k,op=0,bp=0,ot=0,bt=0;	
	int x,y,x1,x2,y1,y2;
	int h1;
	int h=0;
    srand(time(NULL));
    int flag;
    int bayrak;
//de�i�kenler tan�mlama bitti  
  
//zorluk se�me
	do{
		printf("Seviye seciniz:(1(kolay), 2(orta), 3(zor)) ");
		scanf("%d", &zorluk);
	}while(zorluk!=1 && zorluk!=2 && zorluk!=3);
	if(zorluk==1){
		kenar=4;
		h1=2;
	}
	else if(zorluk==2){
		kenar=6;
		h1=6;
	}
	else{
		kenar=8;
		h1=16;
	}
//zorluk se�imi bitti

//haf�za olu�turma
	int hafiza[500][2];
	for(i=0; i<500; i++){
		for(j=0; j<2; j++){
			hafiza[i][j]=0;
		}
	}	
//haf�za olu�turma bitti

//�zerinde i�lem yapaca��m arrayleri tan�mlama
	int a[kenar][kenar];
	char b[kenar][kenar];	   
//array tan�mlama bitti	

//kar���k say� destesini 0 matrisi yapma
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			a[i][j]='0';
		}
	}
//kar���k say� destesi bitti

//y�ld�z matrisi yapma
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			b[i][j]='*';
		}
	}	
//y�ld�z matrisi bitti

//kar���k say� destesi olu�turma
	int max,i1,j1;
	max=(kenar*kenar)/2;
	for(i=1;i<=max;i++){
		for(j=1;j<=2;j++){
			do{
				i1=rand()%kenar;
				j1=rand()%kenar;
			}while(a[i1][j1]!='0');
			a[i1][j1]=i;
		}
	}	
//kar���k say� destesi bitti

system("cls");

//kar��t�r�lm�� say�lar� ekrana bast�rd�m
	for(i=0;i<kenar;i++){
		for(j=0;j<kenar;j++){
			printf("    %2d  ",a[i][j]);      //buras�
		}
	printf("\n\n");
	}
//yazd�rma bitti

printf("\nGecmek icin enter'a basiniz.\n");
getch();
system("cls");
    
//oyun ba�lad�	
//burda say�sal olarak kazanmay� garantileyen var m� veya beraberlik durumu olu�mu� mu onu kontrol ediyor ona g�re devam ediyor
	while((op<=(max/2) && bp<=(max/2)) && ((op != kenar)||(bp != kenar)))
	{
	do
	{
//y�ld�z matrisini ekrana yazd�rd�m		
	printf("SIRA OYUNCUDA\n\n");	
    for (i = 0; i < kenar; ++i) {
        for (k = 0; k < kenar; ++k){
	    printf("    %2c  ", b[i][k]);    
	}
	printf("\n\n");
    }
//yazd�rma bitt

//sat�r s�tun ald�m
	do{
		printf("Lutfen satir sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &x);
    	printf("Lutfen sutun sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &y);
    	x=x-1;
    	y=y-1;
    	printf("\n\n");
	}while((b[x][y]!='*')||(y>(kenar-1) || y<0));
//sat�r s�tun alma bitti    
    system("cls");
    
//y�ld�z olan karakteri say� yapt�m ekrana yazd�rmak i�in
//ilk verilen koordinatlar�n kaybolmamas� i�in ba�ka bir de�i�kene atad�m 
	b[x][y] = a[x][y];
    x1 = x;
    y1 = y;
//atamalar bitti
    
//ekrana a��lan say�yla birlikte tabloyu bast�rd�m
    for(i = 0; i<kenar; i++) {
    	for(k = 0; k<kenar; k++){
    		if(i==x&&k==y){
    			printf("    %2d  ", b[i][k]);
			}
			else{
		    	printf("    %2c  ", b[i][k]);              
		
			}
		}
		printf("\n\n");
	}
//tablo bast�rma bitti	

//2. tahminini ald�m
	do{
		printf("Lutfen satir sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &x);
    	printf("Lutfen sutun sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &y);
    	x=x-1;
    	y=y-1;
    	printf("\n\n");
	}while((b[x][y]!='*')||(y>(kenar-1) || y<0));
//tahmin alma bitti    
    system("cls");
    
//y�ld�z olan karakteri say� yapt�m ekrana yazd�rmak i�in
//ilk verilen koordinatlar�n kaybolmamas� i�in ba�ka bir de�i�kene atad�m
	b[x][y] = a[x][y];
	x2 = x;
    y2 = y;
//atamalar bitti        
    
//2. tahminiyle beraber ilk tahminini ekrana bast�rd�m
    for(i = 0; i<kenar; i++) {
    	for(k = 0; k<kenar; k++){
    		if((i==x)&&(k==y)){
    			printf("    %2d  ", b[i][k]);
			}
			else if((i==x1)&&(k==y1)){
    			printf("    %2d  ", b[i][k]);
			}
			else{
		    	printf("    %2c  ", b[i][k]);                        
		
			}                             
		}
		printf("\n\n");
	}
//yazd�rma bitti	
	
//burda tahminler e�it mi diye kontrol ettim e�itse oyuncuya puan verdim
//ekrana bast�rmak i�in say�ya �evirdi�im y�ld�zlar� �imdi - yapt�m
//ekrana bildi�ini yazd�rd�m
	if (b[x1][y1]==b[x][y]){
		op++;
		b[x1][y1] = '-';
		b[x][y] = '-';
		printf("\nBildiniz :)\n\n");
	}
//atamalar ve yazd�rma biti
	
//e�it de�illerse say�lar� tekrar y�ld�z yapt�m
//kartlar� haf�zaya att�m
//bilemedi�ini yazd�rd�m
	else{
		b[x1][y1] = '*';
		b[x][y] = '*';
		hafiza[h][0]=x1;
		hafiza[h][1]=y1;
		h++;
		hafiza[h][0]=x2;
		hafiza[h][1]=y2;
		h++;
		printf("\nBilemediniz :(\n\n");	
	}
//atamalar ve yazd�rma bitti

//puanlar� yazd�rd�m ve kimini devap edece�ini kontrol ettim
//oyuncu tahmin say�s�n� 1 artt�rd�m
	printf("Oyuncu Puani: %d \nBilgisayar Puani: %d \n\n", op, bp);
	printf("\nGecmek icin enter'a basiniz.\n");
	getch();
	system("cls");
	ot++;
    }while(a[x1][y1]==a[x][y] && op <= (max/2) && ((op!=kenar)||(bp!=kenar)));	
//kontroller ve atamalar bitti

//burda oyuncunun say�sal olarak kazan�p kazanmad���n� kontrol ediyor kazand�ysa devam etmeycek.
	if(op<=(max/2) && ((op!=kenar)||(bp!=kenar))){
//kontrol bitti




//s�ra bilgisayarda   		
	do
	{
		
	//s�ray� belirttim ve ekrana * tablosu bast�rd�m	
	printf("SIRA BILGISAYARDA\n\n");	
    for (i = 0; i < kenar; ++i) {
        for (k = 0; k < kenar; ++k)
	    printf("    %2c  ", b[i][k]);
	printf("\n\n");
    }
    printf("\nGecmek icin enter'a basiniz.\n");
    getch();
	system("cls");
//tablo bast�rma bitti

//burda haf�zada nereye kadar bakmas� gerekti�ini anl�yor
//e�er haf�zadaki kart say�s� hat�rlama say�s�n� ge�tiyse son de�erden hat�rlama say�s� kadar geri gidiyor
//haf�zadaki kart say�s� hat�rlama say�s�n� ge�mediyse en ba�taki karttan okumaya ba�l�yor
	if(h1<=h){
		i=h-h1;
	}
	else{
		i=0;
	}
//haf�za kontrol� bitti

//burda haf�zada farkl� koordinatlarda ancak ayn� de�ere sahip kartlar var m� ona bak�yor varsa bu kartlar� a��yor
//kontrol de�i�keni burda haf�zada ayn� olan kartlardan unutulmaya en yak�n olan� a�mam�z� sa�l�yor
//burda while ve for d�ng�leriyle birlikte d�n�yor ilk ba�ta ifle ayn� olan koordinatlar� kontrol etmemi engelliyor
//2. ifte bu farkl� koordinatlara kar��l�k gelen de�erlere bak�yor
	int kontrol=0;
	while(i<=(h-2)&&kontrol==0){
		for(j=i+1;j<=h-1;j++){
			if((hafiza[i][0]!=hafiza[j][0]) || (hafiza[i][1]!=hafiza[j][1])){
				if((a[hafiza[i][0]][hafiza[i][1]]==a[hafiza[j][0]][hafiza[j][1]]) && b[hafiza[i][0]][hafiza[i][1]]=='*'){
					x1=hafiza[i][0];
					y1=hafiza[i][1];
					x=hafiza[j][0];
					y=hafiza[j][1];	
					kontrol=1;
				}
			}
		}
		i++;
	}
//ayn� koordinatlar� kontrol etme bitti	

//ayn� kartlar varsa burdan devam ediyor	
	if(kontrol==1)
	{
//ilk a��lan kart� ekrana bas�yor		
    	b[x1][y1] = a[x1][y1];	
		for(i = 0; i<(kenar); i++) {
    		for(k = 0; k<(kenar); k++){
    			if(i==x1 && k==y1){
    				printf("    %2d  ", b[i][k]);
				}
				else{
		    		printf("    %2c  ", b[i][k]);
				}
			
			}
			printf("\n\n");
		}
		printf("\n");
		printf("Bilgisayarin satir tahmini: %d\n", x1+1);
		printf("Bilgisayarin sutun tahmini: %d", y1+1);
		printf("\n\n");
		printf("\nGecmek icin enter'a basiniz.\n");
		getch();
		system("cls");
//ekrana bast�rma bitti

//2. a��lan kart� ekrana bas�yor
    	b[x][y] = a[x][y];
		x2 = x;
		y2 = y;    
      
    	for(i = 0; i<(kenar); i++) {
    		for(k = 0; k<(kenar); k++){
    			if(i==x&&k==y){
    				printf("    %2d  ", b[i][k]);
				}
				else if(i==x1&&k==y1){
    				printf("    %2d  ", b[i][k]);
				}
				else{
		    		printf("    %2c  ", b[i][k]);
		
				}
			}
			printf("\n\n");
		}
	printf("\n");
	printf("Bilgisayarin satir tahmini: %d\n", x+1);
	printf("Bilgisayarin sutun tahmini: %d", y+1);
	printf("\n\n");		
	}
//ekrana bast�rma bitti

//ayn� kartlar yoksa haf�zada burdan devam ediyor
	else{
//burda haf�zada olmayan ve - olmayan bir koordinat se�ip a��yor		
		flag = 0;
		do{
			flag=0;
			x = rand() % kenar;
			y = rand() % kenar;                          
			for(i=(h-h1);i<h;i++){
				if(hafiza[i][0]==x){
					if(hafiza[i][1]==y){
						flag=1;
					}
				}
			}
		}while((b[x][y]!='*')||flag==1);
//koordinat se�imi bitti
		
//girilen koordinatlar� yazd�rd�m 
//ekrana bast�rmak i�in y�ld�zlar� say�ya �evirdim
		x1 = x;
	    y1 = y;
	    b[x1][y1] = a[x1][y1];
	    
	    for(i = 0; i<(kenar); i++) {
	    	for(k = 0; k<(kenar); k++){
	    		if(i==x1 && k==y1){
	    			printf("    %2d  ", b[i][k]);
				}
				else{
			    	printf("    %2c  ", b[i][k]);
				}
				
			}
			printf("\n\n");
		}
		printf("\n");
		printf("Bilgisayarin satir tahmini: %d\n", x1+1);
		printf("Bilgisayarin sutun tahmini: %d", y1+1);
		printf("\n\n");
		printf("\nGecmek icin enter'a basiniz.\n");
		getch();
		system("cls");
//ekrana yazd�rma bitti

//burda rastgele a�t��� kart haf�zas�nda var m� onu kontrol ediyor varsa onu a��yor
		bayrak=0;
		for(i=(h-h1);i<h;i++){
				if(a[hafiza[i][0]][hafiza[i][1]]==b[x][y]){
					bayrak=1;
					x=hafiza[i][0];
					y=hafiza[i][1];
				}
			}
//haf�za kontrol� bitti

//burda ilk a�t��� kart haf�zas�nda olmad��� i�in haf�zas�ndakilerden farkl� bir kart a��yor			
		flag=0;
		if(bayrak!=1){
			do{
			flag=0;	
			x = rand() % kenar;
			y = rand() % kenar;
			for(i=(h-h1);i<h;i++){
				if(hafiza[i][0]==x){
					if(hafiza[i][1]==y){
						flag=1;
					}
				}
			}
		}while((b[x][y]!='*')||(flag==1));	
		}
//2. kart a�ma bitti

//a��lan kart� y�ld�zdan say�ya �evirdim ve ekrana yazd�rd�m
	    b[x][y] = a[x][y];
		x2 = x;
		y2 = y;    
	      
	    for(i = 0; i<(kenar); i++) {
	    	for(k = 0; k<(kenar); k++){
	    		if(i==x&&k==y){
	    			printf("    %2d  ", b[i][k]);
				}
				else if(i==x1&&k==y1){
	    			printf("    %2d  ", b[i][k]);
				}
				else{
			    	printf("    %2c  ", b[i][k]);
			
				}
			}
			printf("\n\n");
		}
	printf("\n");
	printf("Bilgisayarin satir tahmini: %d\n", x+1);
	printf("Bilgisayarin sutun tahmini: %d", y+1);
	printf("\n\n");
//ekrana yazd�rma bitti	

	}

//burda bilgisayar�n bilip bilmedi�ini kontrol ediyor bildiyse a�t��� kartlar� - yap�yor bilgisayara puan ekliyor
//e�er bilemedise daha �nce say� yapt��� kartlar� * yap�yor ve bu kartlar� haf�zaya at�yor
	if (b[x1][y1]==b[x][y]){
		bp++;
		b[x1][y1] = '-';
		b[x][y] = '-';
		printf("Bilgisayar bildi!\n\n");
	}
	else{
		b[x1][y1] = '*';
		b[x][y] = '*';
		hafiza[h][0]=x1;
		hafiza[h][1]=y1;
		h++;
		hafiza[h][0]=x2;
		hafiza[h][1]=y2;
		h++;
		printf("Bilgisayar bilemedi!\n\n");
	}
//do�ru yanl�� kontrol� bitti

//burda ekrana bilgiasyar ve oyuncunun puan�n� bast�r�yor
//bilgisayar tahmin say�s�na 1 ekliyor
//e�er bildiyse d�ng� devam ediyor bilemediyse devam etmiyor s�ra oyuncuya ge�iyor
//e�er bilgisayar say�sal olarak kazanmas� kesinle�tiyse d�ng� sona eriyor
//e�er b�t�n kartlar a��lm�� beraberlik sa�lanm��sa oyun sona eriyor	
	printf("Bilgisayar Puani: %d \nOyuncu Puani: %d \n\n", bp, op);
	printf("\nGecmek icin enter'a basiniz.\n");
	getch();
	system("cls");
	bt++;
    }while(a[x1][y1]==a[x][y] && bp <= (max/2) && ((op!=kenar)||(bp!=kenar)));
}
       
    }
//burda ekrana sonucu bas�yor ve ka� tahminde oldu�unu yaz�yor    
    if((op==(max/2) && bp==(max/2))){
    	printf("Berabere!");
    	printf("\nToplam oyuncu tahmin sayisi: %d", ot*2);
    	printf("\nToplam bilgisayar tahmin sayisi: %d", bt*2);
    	printf("\n\nBilgisayar Puani: %d \nOyuncu Puani: %d", bp, op);
	}
	else if(op>(max/2)){
		printf("Kazandiniz Tebrikler!");
		printf("\nToplam tahmin sayisi: %d", ot*2);
		printf("\n\nBilgisayar Puani: %d \nOyuncu Puani: %d", bp, op);
	}
	else{
		printf("Bilgisayar Kazandi!");
		printf("\nToplam tahmin sayisi: %d", bt*2);
		printf("\n\nBilgisayar Puani: %d \nOyuncu Puani: %d", bp, op);
	}
        
return 0;
}
