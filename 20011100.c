#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>

int main() {
//deðiþken tanýmlama
	int zorluk,kenar,i,j,k,op=0,bp=0,ot=0,bt=0;	
	int x,y,x1,x2,y1,y2;
	int h1;
	int h=0;
    srand(time(NULL));
    int flag;
    int bayrak;
//deðiþkenler tanýmlama bitti  
  
//zorluk seçme
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
//zorluk seçimi bitti

//hafýza oluþturma
	int hafiza[500][2];
	for(i=0; i<500; i++){
		for(j=0; j<2; j++){
			hafiza[i][j]=0;
		}
	}	
//hafýza oluþturma bitti

//Üzerinde iþlem yapacaðým arrayleri tanýmlama
	int a[kenar][kenar];
	char b[kenar][kenar];	   
//array tanýmlama bitti	

//karýþýk sayý destesini 0 matrisi yapma
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			a[i][j]='0';
		}
	}
//karýþýk sayý destesi bitti

//yýldýz matrisi yapma
	for(i=0;i<(kenar);i++){
		for(j=0;j<(kenar);j++){
			b[i][j]='*';
		}
	}	
//yýldýz matrisi bitti

//karýþýk sayý destesi oluþturma
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
//karýþýk sayý destesi bitti

system("cls");

//karýþtýrýlmýþ sayýlarý ekrana bastýrdým
	for(i=0;i<kenar;i++){
		for(j=0;j<kenar;j++){
			printf("    %2d  ",a[i][j]);      //burasý
		}
	printf("\n\n");
	}
//yazdýrma bitti

printf("\nGecmek icin enter'a basiniz.\n");
getch();
system("cls");
    
//oyun baþladý	
//burda sayýsal olarak kazanmayý garantileyen var mý veya beraberlik durumu oluþmuþ mu onu kontrol ediyor ona göre devam ediyor
	while((op<=(max/2) && bp<=(max/2)) && ((op != kenar)||(bp != kenar)))
	{
	do
	{
//yýldýz matrisini ekrana yazdýrdým		
	printf("SIRA OYUNCUDA\n\n");	
    for (i = 0; i < kenar; ++i) {
        for (k = 0; k < kenar; ++k){
	    printf("    %2c  ", b[i][k]);    
	}
	printf("\n\n");
    }
//yazdýrma bitt

//satýr sütun aldým
	do{
		printf("Lutfen satir sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &x);
    	printf("Lutfen sutun sayisi giriniz:(1'le '%d arasi) ", kenar);
    	scanf("%d", &y);
    	x=x-1;
    	y=y-1;
    	printf("\n\n");
	}while((b[x][y]!='*')||(y>(kenar-1) || y<0));
//satýr sütun alma bitti    
    system("cls");
    
//yýldýz olan karakteri sayý yaptým ekrana yazdýrmak için
//ilk verilen koordinatlarýn kaybolmamasý için baþka bir deðiþkene atadým 
	b[x][y] = a[x][y];
    x1 = x;
    y1 = y;
//atamalar bitti
    
//ekrana açýlan sayýyla birlikte tabloyu bastýrdým
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
//tablo bastýrma bitti	

//2. tahminini aldým
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
    
//yýldýz olan karakteri sayý yaptým ekrana yazdýrmak için
//ilk verilen koordinatlarýn kaybolmamasý için baþka bir deðiþkene atadým
	b[x][y] = a[x][y];
	x2 = x;
    y2 = y;
//atamalar bitti        
    
//2. tahminiyle beraber ilk tahminini ekrana bastýrdým
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
//yazdýrma bitti	
	
//burda tahminler eþit mi diye kontrol ettim eþitse oyuncuya puan verdim
//ekrana bastýrmak için sayýya çevirdiðim yýldýzlarý þimdi - yaptým
//ekrana bildiðini yazdýrdým
	if (b[x1][y1]==b[x][y]){
		op++;
		b[x1][y1] = '-';
		b[x][y] = '-';
		printf("\nBildiniz :)\n\n");
	}
//atamalar ve yazdýrma biti
	
//eþit deðillerse sayýlarý tekrar yýldýz yaptým
//kartlarý hafýzaya attým
//bilemediðini yazdýrdým
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
//atamalar ve yazdýrma bitti

//puanlarý yazdýrdým ve kimini devap edeceðini kontrol ettim
//oyuncu tahmin sayýsýný 1 arttýrdým
	printf("Oyuncu Puani: %d \nBilgisayar Puani: %d \n\n", op, bp);
	printf("\nGecmek icin enter'a basiniz.\n");
	getch();
	system("cls");
	ot++;
    }while(a[x1][y1]==a[x][y] && op <= (max/2) && ((op!=kenar)||(bp!=kenar)));	
//kontroller ve atamalar bitti

//burda oyuncunun sayýsal olarak kazanýp kazanmadýðýný kontrol ediyor kazandýysa devam etmeycek.
	if(op<=(max/2) && ((op!=kenar)||(bp!=kenar))){
//kontrol bitti




//sýra bilgisayarda   		
	do
	{
		
	//sýrayý belirttim ve ekrana * tablosu bastýrdým	
	printf("SIRA BILGISAYARDA\n\n");	
    for (i = 0; i < kenar; ++i) {
        for (k = 0; k < kenar; ++k)
	    printf("    %2c  ", b[i][k]);
	printf("\n\n");
    }
    printf("\nGecmek icin enter'a basiniz.\n");
    getch();
	system("cls");
//tablo bastýrma bitti

//burda hafýzada nereye kadar bakmasý gerektiðini anlýyor
//eðer hafýzadaki kart sayýsý hatýrlama sayýsýný geçtiyse son deðerden hatýrlama sayýsý kadar geri gidiyor
//hafýzadaki kart sayýsý hatýrlama sayýsýný geçmediyse en baþtaki karttan okumaya baþlýyor
	if(h1<=h){
		i=h-h1;
	}
	else{
		i=0;
	}
//hafýza kontrolü bitti

//burda hafýzada farklý koordinatlarda ancak ayný deðere sahip kartlar var mý ona bakýyor varsa bu kartlarý açýyor
//kontrol deðiþkeni burda hafýzada ayný olan kartlardan unutulmaya en yakýn olaný açmamýzý saðlýyor
//burda while ve for döngüleriyle birlikte dönüyor ilk baþta ifle ayný olan koordinatlarý kontrol etmemi engelliyor
//2. ifte bu farklý koordinatlara karþýlýk gelen deðerlere bakýyor
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
//ayný koordinatlarý kontrol etme bitti	

//ayný kartlar varsa burdan devam ediyor	
	if(kontrol==1)
	{
//ilk açýlan kartý ekrana basýyor		
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
//ekrana bastýrma bitti

//2. açýlan kartý ekrana basýyor
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
//ekrana bastýrma bitti

//ayný kartlar yoksa hafýzada burdan devam ediyor
	else{
//burda hafýzada olmayan ve - olmayan bir koordinat seçip açýyor		
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
//koordinat seçimi bitti
		
//girilen koordinatlarý yazdýrdým 
//ekrana bastýrmak için yýldýzlarý sayýya çevirdim
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
//ekrana yazdýrma bitti

//burda rastgele açtýðý kart hafýzasýnda var mý onu kontrol ediyor varsa onu açýyor
		bayrak=0;
		for(i=(h-h1);i<h;i++){
				if(a[hafiza[i][0]][hafiza[i][1]]==b[x][y]){
					bayrak=1;
					x=hafiza[i][0];
					y=hafiza[i][1];
				}
			}
//hafýza kontrolü bitti

//burda ilk açtýðý kart hafýzasýnda olmadýðý için hafýzasýndakilerden farklý bir kart açýyor			
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
//2. kart açma bitti

//açýlan kartý yýldýzdan sayýya çevirdim ve ekrana yazdýrdým
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
//ekrana yazdýrma bitti	

	}

//burda bilgisayarýn bilip bilmediðini kontrol ediyor bildiyse açtýðý kartlarý - yapýyor bilgisayara puan ekliyor
//eðer bilemedise daha önce sayý yaptýðý kartlarý * yapýyor ve bu kartlarý hafýzaya atýyor
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
//doðru yanlýþ kontrolü bitti

//burda ekrana bilgiasyar ve oyuncunun puanýný bastýrýyor
//bilgisayar tahmin sayýsýna 1 ekliyor
//eðer bildiyse döngü devam ediyor bilemediyse devam etmiyor sýra oyuncuya geçiyor
//eðer bilgisayar sayýsal olarak kazanmasý kesinleþtiyse döngü sona eriyor
//eðer bütün kartlar açýlmýþ beraberlik saðlanmýþsa oyun sona eriyor	
	printf("Bilgisayar Puani: %d \nOyuncu Puani: %d \n\n", bp, op);
	printf("\nGecmek icin enter'a basiniz.\n");
	getch();
	system("cls");
	bt++;
    }while(a[x1][y1]==a[x][y] && bp <= (max/2) && ((op!=kenar)||(bp!=kenar)));
}
       
    }
//burda ekrana sonucu basýyor ve kaç tahminde olduðunu yazýyor    
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
