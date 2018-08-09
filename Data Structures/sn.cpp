// sn.cpp

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void packet_dump(FILE *&stream, const unsigned char *buf, const unsigned int len) {
    // Declarations
    unsigned char c;
    int i,j;

    // Output Packets
    for(i = 0; i < len; i++) {
        //printf("%02x ", buf[i]);
        fprintf(stream, "%02x ", buf[i]);

        if((i % 16) == 15 || (i == len-1)) {
            for(j = 0; j < 15 - (i % 16); j++) {
                printf("   ");
                fprintf(stream, "   ");
            }
        
            printf("| ");
            fprintf(stream, "| ");
            for(j = (i - (i % 16)); j <= i; j++) {
                c = buf[j];
                if((c > 31) && (c < 127)) {
                    printf("%c", c);
                    fprintf(stream, "%c", c);
                }    
                else {
                    printf(".");
                    fprintf(stream, ".");
                }
            }
            printf("\n");
            fprintf(stream, "\n");
        }
    }
}

int main() {
    // Declarations
    int received_length, sock_fd, i;
    u_char buf[5000];
    ssize_t numRead;

    // Open File for Writing
    FILE *stream;
    if(!(stream = fopen("/home/newuser/Desktop/hashchainSetTree/log.dat", "ab"))) {
        perror("PacketDump File: open error");
        printf("Creating file log.txt .......");
    }  

    // Open Socket
    if((sock_fd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("PacketDump Socket error");
        exit(1);
    }

    // Total Packet Reads
    for(i = 0; i < 50; i++) {
        received_length = recv(sock_fd, buf, 4000, 0);
        printf("%d byte packet\n", received_length);
        packet_dump(stream, buf, received_length);
    }

    // Close File to Read
    if(fclose(stream))
        perror("PacketDump File: fclose error");

    return 0;
}

