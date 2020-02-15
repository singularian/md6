#include "md6.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int hashTargetFile(char *filename, unsigned char* md_value, int bitsize);

int main (void) {

unsigned char in[100] = "Test MD6 string hash";

int msglenbytes = 0;

unsigned char hashval[512];

int result = 0;
int bitsize = 128;
int MD6_DIGEST_LENGTH = bitsize / 8;
md6_state st;
md6_init(&st, bitsize);

// extern int md6_update( md6_state *st,             /* initialized state */
//		       unsigned char *data,            /* data portion */
//		       uint64_t databitlen       /* its length in bits */
//		       );
result = md6_update( &st, in, 63);

printf("result %d\n", result);

md6_final( &st, hashval);

// printf("%x\n", hashval);
// printf("%s\n", st.hashval);

int length = st.d / 8;
printf("hash length %d\n", length);

int i;
for(i = 0; i < MD6_DIGEST_LENGTH; i++) printf("%02x", st.hashval[i]);

printf("\n");

char *filename="testMD6.c";
hashTargetFile(filename, hashval, bitsize);

}


int hashTargetFile(char *filename, unsigned char* md_value, int bitsize) {

    int i = 0;
    int MD6_DIGEST_LENGTH = bitsize / 8;
    int bytes;
    unsigned char data[1024];

    FILE *fp = fopen (filename, "rb");
    if(fp == NULL){
       printf("File %s doesn't exist\n", filename);
       exit(1);
    }

    printf("The File %s MD6 is ", filename);

    md6_state st;
    md6_init(&st, bitsize);
    while ((bytes = fread (data, 1, 1023, fp)) != 0)
        md6_update (&st, data, bytes);
 
    unsigned char hashval[512]; 
    md6_final (&st,hashval);

    for(i = 0; i < MD6_DIGEST_LENGTH; i++) printf("%02x", st.hashval[i]);
    printf("\n");

    fclose (fp);

    md_value = (unsigned char *) st.hashval;

    return 1;
}
