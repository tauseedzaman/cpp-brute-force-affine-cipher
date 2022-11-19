#include <iostream>
using namespace std;
string encrypt(string plain_text) {
  string cipher;
  char ch;
  for (int i = 0; i < plain_text.length(); i++) {
    char charr = plain_text[i];
    ch = (3 * (charr - 97) + 20) % 26 + 97;
    cipher += ch;
  }
  return cipher;
}

string decrypt(string cipher_text) {
  string text;
  char ch;
  for (int i = 0; i < cipher_text.length(); i++) {
    char charr = cipher_text[i];
    ch = (3 * (charr - 97 - 15 + 26)) % 26 + 97;
    text += ch;
  }
  return text;
}

string decrypt_with_bfource(string cipher_text, int key_a, int key_b) {
  string text;
  char ch;
  for (int i = 0; i < cipher_text.length(); i++) {
    char charr = cipher_text[i];
    ch = (key_a * (charr - 97 - key_b + 26)) % 26 + 97;
    text += ch;
  }
  return text;
}

int main() {
  string text = "tauseedzaman";
  cout << "given string: " << text << endl;

  string cipher = encrypt(text);
  cout << "generated cipher: " << cipher << endl;

// for key a
  for (int i = 0; i < 26; i++) {
    // for key b
    for (int j = 0; j < 26; j++) {
      //                decrypt_with_bfource(cipher, key a, key b);
      string guss_text = decrypt_with_bfource(cipher, i, j);
      if (text == guss_text) {
        cout << "key a: " << i << "\nkey b: " << j << "\ntext:" << guss_text
             << endl;
      }
    }
  }
}