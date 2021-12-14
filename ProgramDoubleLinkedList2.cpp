#include <windows.h> //MEMBUAT TAMPILAN
#include <iostream>
#include <conio.h> //MENGGUNAKAN GETCH()
#include <stdlib.h> 
#include <limits> // Only Integer
#include <time.h> // MENGGUNAKAN srand(time(0))

using namespace std;

struct Node
{
     char nama[30];
     int umur;
     Node *next;
     Node *prev;
};

Node *head = NULL, *tail = NULL;

void gotoxy(int x, int y)
{
   	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void tambahDepan() {
	char namaorg[30];
	int umurorg;
	cout<<"Nama : "; cin>>namaorg;
	cout<<"Umur : "; cin>>umurorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	baru->umur = umurorg;

	baru->prev = NULL;
	baru->next = head;
	if(head==NULL)
		tail = baru;
	else
		head->prev = baru;
	head = baru;
	
	cout<<namaorg<<" "<<umurorg<<" berhasil masuk list\n";
}

void tambahSetelah() {
	char namaorg[30];
	bool found;
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	if(head==NULL) {
		baru->prev = NULL;
		baru->next = NULL;
		head = baru;
		tail = baru;
		found = true;
	}	else {
		char cari[30];
		cout<<"Tambahkan setelah siapa : "; cin>>cari;
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->next = bantu->next;
				baru->prev = bantu;
				bantu->next = baru;
				if(bantu==tail) tail = baru;
				found = true;
				break;
			}
			bantu = bantu->next;
		}
	}
	if(found) cout<<namaorg<<" berhasil masuk list\n";
	else cout<<namaorg<<" gagal masuk list\n";
}

void tambahSebelum() {
	char namaorg[30];
	bool found = false;
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	if(head==NULL) {
		baru->prev = NULL;
		baru->next = NULL;
		head = baru;
		tail = baru;
		found = true;
	}	else {
		char cari[30];
		cout<<"Tambahkan sebelum siapa : "; cin>>cari;
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->prev = bantu->prev;
				baru->next = bantu;
				bantu->prev = baru;
				if(bantu==head) head = baru;
				found = true;
				break;
			}
			bantu = bantu->next;
		}
	}	
	if(found) cout<<namaorg<<" berhasil masuk list\n";
	else cout<<namaorg<<" gagal masuk list\n";
}

void tambah_belakang()
{
	char a[30];
	int b;
	//Masukan Data-datanya
	cout<<"Masukan Nama Teman : "; cin>>a;
	cout<<"Masukan Umur Teman : "; cin>>b;
	//Buat Node Baru :: Memesan Tempat di memory
	Node *baru;
	baru= new Node;
	//Masukan Datanya ke Node Baru
	strcpy(baru->nama,a);
	baru->umur=b;
	//Jika data Teman Belum Ada di Memory
	if(head==NULL)
	{
		head=baru;	
		head->next=NULL;
        head->prev=NULL;
		tail=head;
	}
	//Jika Data Teman sudah ada datanya di Memory
	else
	{
		tail->next=baru;
        baru->prev=tail;
		tail=baru;
		tail->next=NULL;
	}
}

void cetakmundur() {
	Node *bantu = tail;
	while(bantu!=NULL) {
		cout<<bantu->nama<<" -> ";
		bantu = bantu->prev;
	} cout<<"NULL\n";
}

void cetakmaju() {
	Node *bantu = head;
	while(bantu!=NULL) {
		cout<<bantu->nama<<" -> ";
		bantu = bantu->next;
	} 
    cout<<"NULL\n";
}

void menu(){
    int choose, urut;
    do{
            system("cls");
            gotoxy(0,2);cout<< "===== PROGRAM DOUBLE LINKED LIST ================="<<endl;
            gotoxy(0,3);cout<< "=================================================="<<endl;
            gotoxy(0,4);cout<< "|1. Tambah Data DiDepan                           |"<<endl;
            gotoxy(0,5);cout<< "|2. Tambah Data DiBelakang                        |"<<endl;
            gotoxy(0,6);cout<< "|3. Tambah Data DiTengah Sebelum Node Tertentu    |"<<endl;
            gotoxy(0,7);cout<< "|4. Tambah Data DiTengah Sesudah Node Tertentu    |"<<endl;
            gotoxy(0,8);cout<< "|5. Tampil Data Maju                              |"<<endl;
            gotoxy(0,9);cout<< "|6. Tampil Data Mundur                            |"<<endl;
			gotoxy(0,10);cout<<"|7. Hapus Depan		         	          |"<<endl;
            gotoxy(0,11);cout<<"|8. Hapus Tengah	 	                  |"<<endl;
			gotoxy(0,12);cout<<"|9. Hapus Belakang	 	                  |"<<endl;
            gotoxy(0,13);cout<<"|10. Keluar Dari Program                          |"<<endl;
            gotoxy(0,14);cout<< "================================================="<<endl;
            gotoxy(0,15);cout<< "Pilih (1-10) = ";
            while(!(cin>>choose)){
                system("cls");
                cin.clear();   
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                gotoxy(0,1);cout << "Invalid input...";
                gotoxy(0,3);cout << "Tekan Tombol Apapun Untuk Melanjutkan...";
                getch();
                return menu();
            }
            if(choose == 1){
                tambahDepan();
            }
            else if(choose == 2){
                tambah_belakang();
            }
            else if(choose == 3){
                tambahSebelum();
            }
            else if(choose == 4){
                tambahSetelah();
            }
            else if(choose == 5){
                cetakmaju();
            }
            else if(choose == 6){
                cetakmundur();
            }
			else if(choose == 7){
                if(head==NULL){ 
					cout<<"List masih Kosong \n";
					cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
				}
				else{
					if(head==tail){
						gotoxy(0,17);cout<<"Lokasi terakhir Data "<<head<<endl;   
						delete head;
						gotoxy(0,18);cout<<"Data Berhasil dihapus"<<endl; 
						gotoxy(0,19);cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
						head = NULL;
						tail = NULL;
					}
					else{
						char x[30];
						cout<<"Manghapus Nama siapa : ";cin>>x;
						if(strcmp(head->nama,x)==0){
							Node *hapus;        
							hapus = head;             
							head = head->next;
							gotoxy(0,17);cout<<"Lokasi terakhir Data "<< x << " : " <<hapus<<endl;       
							delete hapus;
							gotoxy(0,18);cout<<"Data "<< x <<" Berhasil dihapus"<<endl;
							gotoxy(0,19);cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
						}
						else{
							cout<<"Tidak Ada Data \n";
							cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
							getch();
							return menu();
						}
					}
				}
            }
			else if(choose == 8){
                char x[30];
				cout<<"Manghapus Nama siapa : ";cin>>x;
				Node *bantu;
				bantu=head; 
				while(bantu!=NULL){ 
					if(strcmp(bantu->next->nama,x)==0){
						Node *hapus; 
						hapus = bantu->next; 
						bantu->next = bantu->next->next;
						gotoxy(0,17);cout<<"Lokasi terakhir Data "<< x << " : " <<hapus<<endl;   
						delete hapus; //hapus hapus(bantu->next)
						gotoxy(0,18);cout<<"Data "<< x <<" Berhasil dihapus"<<endl; 
						gotoxy(0,19);cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
						break; 
					}
					else{ 
						cout<<"Tidak Ada Data \n"; 
						cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
						getch();
						return menu();
					}
				}
            }
			else if(choose == 9){
                char x[30];
				cout<<"Manghapus Nama siapa : ";cin>>x;
				if(strcmp(tail->nama,x)==0){
					Node *bantu;     
					bantu = head;             
					while(bantu->next != tail){             
						bantu = bantu->next;            
					}
					gotoxy(0,17);cout<<"Lokasi terakhir Data "<< x << " : " <<tail<<endl;                    
					delete tail;
					gotoxy(0,18);cout<<"Data "<< x <<" Berhasil dihapus"<<endl;
					gotoxy(0,19);cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
					bantu->next = NULL;          
					tail = bantu;
				}
				else{
					cout<<"Tidak Ada Data \n";
					cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
					getch();
					return menu();
				}
            }
            else if(choose == 10){
                gotoxy(0,17);cout<<"TERIMAKASIH";	
            }
            else{
                system("cls");
                gotoxy(0,1);cout << "Masukan anda salah ! \n"<< endl;
                getch();
                return menu();

            }
            getch();
        }
        while(choose!=10);
}

int main(){
    system("color E");
    system("cls");
    menu();
}
