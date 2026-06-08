#include <stdio.h>
#include <string.h>

void encrypt(char orig[], char enc[], int key) {
    int len = strlen(orig); //널 문자 탐색 필요없음
    
    for (int i = 0; i < len; i++) {
        char ch = orig[i]; 

        if (ch >= 'A' && ch <= 'Z') {
            enc[i] = (ch - 'A' + key) % 26 + 'A';
        } 
        else if (ch >= 'a' && ch <= 'z') {
            enc[i] = (ch - 'a' + key) % 26 + 'a';
        } 
        else {
            enc[i] = ch; // 알파벳이 아니면 그대로 복사
        }
    }
    enc[len] = '\0'; // 널 문자 처리
}

void decrypt(char enc[], char dec[], int key) {
    int len = strlen(enc); //널 문자 탐색 필요없음
    
    for (int i = 0; i < len; i++) {
        char ch = enc[i];

        if (ch >= 'A' && ch <= 'Z') {
            dec[i] = (ch - 'A' - key + 26) % 26 + 'A';
        } 
        else if (ch >= 'a' && ch <= 'z') {
            dec[i] = (ch - 'a' - key + 26) % 26 + 'a';
        } 
        else {
            dec[i] = ch; 
        }
    }
    dec[len] = '\0'; // 널 문자 처리
}

int main() {
    char original_pw[20];
    char encrypted_pw[30];
    char decrypted_pw[20];
    
    scanf("%19s", original_pw);

    // 주소 값을 이용해 키 생성
    int shift_key = (unsigned long long)encrypted_pw % 26;  
    if (shift_key == 0) { //키가 0일 때 방지
        shift_key = 3;
    }
    
    printf("메모리 주소값: %p\n", encrypted_pw);
    printf("밀어낼 칸수(키): %d\n", shift_key);


    encrypt(original_pw, encrypted_pw, shift_key);
    printf("암호화 결과: %s\n", encrypted_pw);

    decrypt(encrypted_pw, decrypted_pw, shift_key);
    printf("복호화 결과: %s\n", decrypted_pw);

    return 0;
}
