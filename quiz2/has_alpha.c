#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

bool has_alpha(char *s, size_t size)
{
    if (size == 0)
        return false;
        
    for (size_t j = 0; j < size; j++) {
        if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))
            return true;
   }
   return false;
}

bool has_alpha_vector(char *s, size_t size)
{
    if (size == 0)
        return false;
        
    size_t i = 0;
    while ( (i + 8) <= size){
        // uint64_t payload;
        // memcpy(&payload, str + i, 8);
        uint64_t *payload = (uint64_t *) s;

        if ((*payload & PACKED_BYTE(0x80)) == 0) { /* is ASCII? */
            
            // Upper mask
            uint64_t A = *payload + PACKED_BYTE(128 - 'A'); 
            uint64_t Z = *payload + PACKED_BYTE(127 - 'Z');
            uint64_t upper_mask = ((A ^ Z) & PACKED_BYTE(0x80));
        
            // Lower mask
            uint64_t a = *payload + PACKED_BYTE(128 - 'a');  
            uint64_t z = *payload + PACKED_BYTE(127 - 'z');
            uint64_t lower_mask = ((A ^ Z) & PACKED_BYTE(0x80));
        
            if ( (upper_mask | lower_mask) & PACKED_BYTE(0x80) )
                return true;
        }else{
            if (has_alpha(s, 8))
                return true;
        }
    i += 8;
    s += 8;
    }
    
    i = size % 8;
    if (i){
        if (has_alpha(s, 8))
                return true;
    }
        
    return false;
}