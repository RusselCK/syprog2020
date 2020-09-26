#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <endian.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40; 
    const uint8_t shift = (letter >> 3) | (letter >> 6); 
    return (in + shift) & 0xf;
}

size_t hexspeak2val(char str[]){

    int len = strlen(str);
    assert(len);

    if (len == 1) /* case 1 */
        return hexchar2val(str[0]);
    
    assert(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'));

    size_t total = 0;

    size_t i = 2; 
    for (; (i + 8) <= len ; i += 8) /* case 2 */
    {
        uint64_t payload;
        memcpy(&payload, str + i, 8);
    
        const uint64_t letter = payload & PACKED_BYTE(0x40); 
        const uint64_t shift = (letter >> 3) | (letter >> 6);
        const uint64_t value = (payload + shift) & PACKED_BYTE(0x0f);
        printf("\n%lx\n", payload);
        printf("%lx\n", value);

        //total = total << 64 ;
#if __BYTE_ORDER == __LITTLE_ENDIAN
        for (size_t j = 0; j < 64 ; j += 8)
        {
            total += (( value << j ) >> 56) << (j >> 1);
            //printf("%lx",total);
        }
#else
        for (size_t j = 0; j < 64 ; j += 8)
            total += (( value << j ) >> 56) << ((56 - j) >> 3);
#endif
        //printf("%lx\n",total);
    }
    //printf("%lx\n",total);

    //i = 10;
    for (; i < len ; i++) /* case 3 */
    {
     total = ( total << 4 | hexchar2val(str[i]));
     //printf("%lx\n",total);
     //total = total << 4;
     //total += hexchar2val(str[i]);
     //printf("%lx\n",total);
    }


    return total;
}



int main(){
    char a[] = "123456789AaBbCcDdEeFf";
    char b[] = "0x8BADF00D";   // 2343432205
    char c[] = "0x78BADF00D";  // 32408203277
    //char d[] = "0xFEEDFACECAFEBEEF"; // 18369614221190020847
    char e[] = "0x4B1D"; //19229
    //for(int i = 0; i < strlen(a);i++) 
    //    printf("%c %d\n", a[i], hexchar2val(a[i]));
    printf("%ld \n", hexspeak2val(b));
    //printf("%llx\n", (unsigned long long)(hexspeak2val(d) & 0xFFFFFFFFFFFFFFFF));
        
    return 0;
}