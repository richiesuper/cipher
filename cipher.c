#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int KEY = 1;

int main(int argc, char *argv[]) {
    char *msg;
    char convmsg[4096];
    int msglen;
    if (argc != 2) {
        printf("Usage: [filename] [\"Strings to be ciphered.\"]");
        return 1;
    } else {
        msg = strdup(argv[1]);
        msg[strcspn(msg, "\n")] = 0;
        msglen = strlen(msg);
        for (int i = 0; i < msglen; i++) {
            convmsg[i] = (int) msg[i];
            convmsg[i] += KEY;
        }
        convmsg[msglen] = '\0';
        printf("Your plaintext message:\n%s\nYour ciphered message:\n%s\n", msg, convmsg);
    }
    return 0;
}
