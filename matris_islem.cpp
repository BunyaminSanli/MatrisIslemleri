
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int matris[26][26];	//matris tanimlama. global tanimladim cunku matrisyaz fonksiyonunda da kullanmak istedim
using namespace std;

void matrisyaz(int matrisboyutuf);

int main()
{
	int matrisToplami = 0;	//case 4 te toplama yaparken kullandigim degisken
	int matrisBoyutu;		//kullanicidan alacagimiz matrisboyutunu bircok yerde sinirlama yaparken kullandim
	int islem;				//islem yapacagimiz değeri kullanıcıdan alacagimiz degisken
	int gecicideger;	//matris icinde kaydirma yaparken kullanacgimiz gecici deger

	//random fonksiyonu her seferinde farkli deger uretmesi icin
	srand((unsigned) time(NULL));
	do
	{
		cout << "Matris boyutu: ";
		cin >> matrisBoyutu;
	}
	while (matrisBoyutu < 5 || matrisBoyutu>25);	//boyut kontrol
	
	
	for (int i = 1; i <= matrisBoyutu; i++)	//matris random deger atama
	{
		for (int j = 1; j <= matrisBoyutu; j++)
		{
			matris[i][j] = rand() % 9 + 1;
		}

	}
	matrisyaz(matrisBoyutu); //matrisyaz fonksiyonundan matris yazdirirlir
	
	cout << endl;
	cout << " 1. Sutun Satir Degistir \n 2. Tekleri Basa Al (satir)\n 3. Ters Cevir (sutun)\n 4. Toplamlari Yazdir" << endl;
	cin >> islem;
	
	int satir, sutun;		//kullanicidan satir ve sutun degeri almak icin 2 degisken tanimlariz
	
	switch (islem)		//switch case kullanarak islem menusunu tasarladim
	{
		case 1:
		{
			
			cout << "satir sutun : ";
			cin >> satir >> sutun;

			while (satir > matrisBoyutu || sutun > matrisBoyutu)	//araliga denk gelmedigi surece tekrar tekrar deger ister
			{
				
				cout << "satir veya sutun matris boyundan buyuk olamaz" << endl;

				
				matrisyaz(matrisBoyutu);	//matrisyaz fonksiyonuyla matrisimiz yazdirilir

				cout << "satir sutun : ";
				cin >> satir >> sutun;
			}
			
			
			for (int i = 1; i <= matrisBoyutu; i++)	//satirdaki ya da sutundaki elemanlar tek tek okunuyor
			{
				int a = matris[i][sutun];			//gecici a degiskeni kullanarak elemanları yer degistirdim
				matris[i][sutun] = matris[satir][i];
				matris[satir][i] = a;
			}
			matris[satir][sutun] = matris[satir][sutun] * 2; //kesişen yerdeki elemanları toplar

		matrisyaz(matrisBoyutu);
		
		break;
		}

		case 2:
		{
			
			cout << "satir degeri giriniz";
			cin >> satir;

			while (satir > matrisBoyutu)		//satir degeri matris boyutundan kucuk olana kadar tekrar isteyecek
			{
				cout << "satir matris boyundan buyuk olamaz" << endl;
				matrisyaz(matrisBoyutu);

				cout << " 1. Sutun Satir Degistir \n 2. Tekleri Basa Al (satir)\n 3. Ters Cevir (sutun)\n 4. Toplamlari Yazdir" << endl;
				cin >> islem;
			}
			
			int matrisGecici[25] = {0};
				for (int i = 1; i <= matrisBoyutu; i++)	//secilen satirdaki elemanlari gecici matrise yazma islemi
				{
					matrisGecici[i] = matris[satir][i];
				}

			int j = 1;		//burada iki farkli for kullanacagim icin degiskenleri yukarida tanimladim
			int i = 1;
			
			for (i = 1; i <= matrisBoyutu; i++)		//geçici dizideki elemanlar tek ise matrisimize geri yollaniyor
			{
				if (matrisGecici[i] % 2 == 1)
				{
					matris[satir][j] = matrisGecici[i];
					j++;
				}
			}

			for (int i=1; i <= matrisBoyutu; i++)	 //kalan cift sayilar tek tek matrise geri yollanir
			{
				if (matrisGecici[i] % 2 == 0)
				{
					matris[satir][j] = matrisGecici[i];
					j++;
				}
			}
			
			matrisyaz(matrisBoyutu);

			break;
		}

		case 3:
		{
			cout << "sutun numarasi : ";
			cin >> sutun;

			while (sutun > matrisBoyutu)		//girilen sutun degeri matrisboyutundan kucuk olana kadar tekrar deger ister
			{

				cout << "sutun matris boyundan buyuk olamaz" << endl;


				matrisyaz(matrisBoyutu);

				cout << "sutun : ";
				cin >>sutun;
			}
			for (int i = 1; i <= matrisBoyutu/2; i++)	//sutundaki elemanların yarisi kadar for dondurulur
			{
				//en alttaki ile en ustteki yer degistirir ve her seferinde birbirlerine yaklasarak devam eder	
				gecicideger = matris[i][sutun];			
				matris[i][sutun] = matris[matrisBoyutu + 1 - i][sutun];
				matris[matrisBoyutu + 1 - i][sutun] = gecicideger;
			}

			matrisyaz(matrisBoyutu);		//matris yaz fonksiyonu ile matris yazdirilir

			break;
		}

		case 4:
		{
			//matrisin toplami alma icin iki for kullanarak biri satir biri sutun ifade eder tum elelamnlar toplanir
			for (int i = 1; i <= matrisBoyutu; i++)	
			{
				for (int j = 1; j <= matrisBoyutu; j++)
				{
					matrisToplami = matrisToplami + matris[i][j];
				}
			}
			
			cout << endl;
			cout << "    ";				//matris sutun belirtecleri yazdirma
			for (int i = 1; i <= matrisBoyutu; i++)
			{
				if (i <= 9)		//düzgün gozukmesi icin tek sayilarda 2 cift haneli sayilarda 1 bosluk birakir
				{
					cout << "  " << i;
				}
				else
				{
					cout << " " << i;
				}
			}

			cout << endl;

			cout << "     ";
			for (int i = 1; i <= matrisBoyutu; i++)		//matris sutun belitrecleri altindaki cizgiyi cekmek icin dongu
			{
				cout << "____";
			}

			cout << endl;
			cout << endl;

			for (int i = 1; i <= matrisBoyutu; i++)
			{
				for (int j = 1; j <= matrisBoyutu; j++)
				{
					if (i == 1 && j == 1)		//matristeki a11 elemanı yerine toplam -a11 degeri atanmasi icin if kontrolu
					{
						matris[i][j] = matrisToplami - matris[1][1];
					}
					
					else if (j == 1)			//eger sutun 1 ise ve satir birden farkliysa bir onceki satirin son elemanindan cikarmak icin else if kontrolu yapilir
					{
						matris[i][j] = matris[i - 1][matrisBoyutu] - matris[i][j];
					}

					else				    	//geri kalan durumlarda soldakinden sagdaki deger cikarilir
					{
						matris[i][j] = matris[i][j - 1] - matris[i][j];
					}

					for (int a = 1; a <= matrisBoyutu; a++)	//satir sayisi belirteci yazdirma
					{
						if (i == a && j == 1) //a degiskeni sayesinde kac satir varsa o kadar olusturalacak
						{
							if (a <= 9)		 // duzgun gozukmesi icin cift haneli sayialara gecince bosluk bir azaltılıyor
							{
								cout << "  ";
							}

							else
							{
								cout << " ";
							}

							cout << i << " | ";
						}
					}
					if (matris[i][j] < 99 && matris[i][j] > 9)
					{
						cout << matris[i][j] << "  ";		//2 haneli sayilar icin 2 bosluk
					}
					else if (matris[i][j] <= 9)
					{
						cout << matris[i][j] << "   ";		//tek haneli sayilar icin 3 bosluk
					}
					else
					{
						cout << matris[i][j] << " ";	//3 haneli sayilar icin 1 bosluk
					}

				}
				cout << endl;
			}

			break;
		}
	}


}

void matrisyaz(int matrisBoyutuf)	//matris yazdirmak icin tanimladigim matrisyaz metodu
{

	cout << "      ";				//matris sutun belirtecleri yazdirma
	for (int i = 1; i <= matrisBoyutuf; i++)
	{
		if (i <= 9)		//düzgün gozukmesi icin tek sayilarda 2 cift haneli sayilarda 1 bosluk birakir
		{
			cout << "  " << i;
		}
		else
		{
			cout << " " << i;
		}
	
	}

	cout << endl;

	cout << "      ";
	for (int i = 1; i <= matrisBoyutuf; i++)
	{
		cout << "___";
	}

	cout << endl;
	cout << endl;

	//matris yazdirma
	for (int i = 1; i <= matrisBoyutuf; i++)
	{
		for (int j = 1; j <= matrisBoyutuf; j++)
		{
			for (int a = 1; a <= matrisBoyutuf; a++)	//satir sayisini belirtme
			{
				if (i == a && j == 1) //a degiskeni sayesinde kac satir varsa o kadar olusturalacak
				{
					if (a <= 9)		 // duzgun gozukmesi icin cift haneli sayialara gecince bosluk bir azaltılıyor
					{
						cout << "  ";
					}
					else
					{
						cout << " ";
					}

					cout << i << " | ";
				}
			}

			cout << "  ";
			cout << matris[i][j];
		}
		cout << endl;
	}
}
