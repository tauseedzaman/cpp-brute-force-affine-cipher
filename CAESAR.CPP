#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>

int key = 24;
void encrypt(ifstream plain);
void decrypt(ifstream cipher);

void main() {clrscr();
 ifstream cipher("plain.txt");

 cout<<"\n\t\t\tPlaintext before Caesar Cipher\n----------------------------------------"<<
       "----------------------------------------";
 cout<<cipher.rdbuf()<<"\n";

 cout<<"\n\t\t\tCiphertext by Caesar Cipher\n----------------------------------------"<<
       "----------------------------------------";

 encrypt("plain.txt");
 decrypt("cipher.txt");
 getch();
}

void encrypt(ifstream plain) {
  char ch;
  ofstream cipher("cipher.txt");
    while(plain) {
     plain.get(ch);
     if(isalpha(ch))
      {
       ch = tolower(ch);
       ch = (ch - 97 + 25) % 26 + 97;
      }
      cout<<(char) toupper(ch);
      cipher.put(toupper((char) ch));
  }
 cout<<"\n\n\t\t\tPlaitext by Caesar Cipher\n----------------------------------------"<<
       "----------------------------------------\n";
 }

void decrypt(ifstream cipher) {
  char ch;
  ofstream plain("plain2.txt");
  while(cipher) {
		cipher.get(ch);
		if(isalpha(ch))
		  {
		   ch = tolower(ch);
		   ch = (ch - 97 - 25 + 26) % 26 + 97;
		  }
		cout<<ch;
		plain.put(ch);
  }
 cout<<"\n";
 }
