#include <iostream>
#include <cstring>

using namespace std;

const char* fileContent = "Hello, this is a test file content.";
int filePointer = 0;

// Функция read4 читает до 4 символов из глобальной строки fileContent в буфер buf4 и возвращает количество прочитанных символов.
int read4(char *buf4) {
    int i = 0;
    while (i < 4 && fileContent[filePointer] != '\0') {
        buf4[i++] = fileContent[filePointer++];
    }
    return i;
}

// Функция read читает до n символов, используя read4, и записывает их в буфер buf. 
// Она продолжает читать, пока не будет прочитано n символов или не достигнут конец файла.
int read(char *buf, int n) {
    
    int totalRead = 0;    
    bool eof = false;
    
    for (char buf4[4]; totalRead < n && !eof;) {
        int currentRead = read4(buf4);
        if (currentRead < 4) eof = true;
        for (int i = 0; i < currentRead && totalRead < n; ++i) {
            buf[totalRead++] = buf4[i];
        }
    }
    return totalRead;
}

int main() {
    char buf[100];
    int n = 10;
    int readChars = read(buf, n);
    buf[readChars] = '\0';  // добавляем null-terminator
    cout << "Read " << readChars << " characters: " << buf << endl;
    return 0;
}
