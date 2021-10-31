
///      BIT OPERATIONS


/*
bytes in a bitstring of nbits bits
Right shift by 3 is == divide by 8 to get the number of bytes
     15 bits === (15-1)/8 = 1 === 1+1 = 2 bytes needed
     16 bits === (16-1)/8 = 1 === 1+1 = 2 bytes needed
     17 bits === (17-1)/8 = 2 === 2+1 = 3 bytes needed
*/

// - 1 is to take care of border cases
#define bitstr_size(nbits)    ((((nbits) - 1) >> 3) + 1)

//Alocate bytes depending on number of bits will be used for the application
#define bit_alloc(nbits)  (bitstr_t *)calloc(1, (unsigned int)bitstr_size(nbits) * sizeof(bitstr_t))


/* find the byte to which the bit belongs*/
#define _bit_byte(bit) ((bit) >> 3)

/* mask for the bit within its byte
   only last three bit matters == > and with 0x7...bit 0 to 7
   0111==0x07
   then left shift 1 by that much.
*/
#define _bit_mask(bit)  (1 << ((bit)&0x7))

/* set bit N of bitstring name */
#define bit_set(name, bit) (name)[_bit_byte(bit)] |= _bit_mask(bit)


/* find first unset bit in bitstring */
#define bit_ffc(name, nbits, value) do {                                
        bitstr_t *_name = (name);                                       
        int _byte, _nbits = (nbits);                                    
        int _stopbyte = _bit_byte(_nbits - 1), _value = -1;             
        if (_nbits > 0)                                                 
                for (_byte = 0; _byte <= _stopbyte; ++_byte)            
                        //if the byte has all bits set skip 
                        if (_name[_byte] != 0xff) {                     
                                bitstr_t _lb;                           
                                _value = _byte << 3; //byte*8 gives offest in bitstring                   
                                for (_lb = _name[_byte]; (_lb & 0x1);   
                                    ++_value, _lb >>= 1);               
                                break;                                  
                        }
        if (_value >= nbits)                                            
                _value = -1;                                            
        *(value) = _value;                                              
} while (0)

    /* find first bit set in name */
#define bit_ffs(name, nbits, value) do {                                \
        bitstr_t *_name = (name);                                       \
        int _byte, _nbits = (nbits);                                    \
        int _stopbyte = _bit_byte(_nbits - 1), _value = -1;             \
        if (_nbits > 0)                                                 \
                for (_byte = 0; _byte <= _stopbyte; ++_byte)            \
                        if (_name[_byte]) {                             \
                                //if all bits are unset then skip that byte
                                bitstr_t _lb;                           \
                                _value = _byte << 3;     //divide by 8 to get byte index
                                for (_lb = _name[_byte]; !(_lb & 0x1);  \
                                    ++_value, _lb >>= 1);               \
                                break;                                  \
                        }                                               \
        if (_value >= nbits)                                            \
                _value = -1;                                            \
        *(value) = _value;                                              \
} while (0)