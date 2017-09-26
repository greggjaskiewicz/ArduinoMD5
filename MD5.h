#ifndef MD5_h
#define MD5_h

/**
 * @file MD5.h
 *
 * Class declaration for MD5 and helper enums
 */

#include "MD5_config.h"
/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security,
 * Inc. MD5 Message-Digest Algorithm (RFC 1321).
 *
 * Written by Solar Designer <solar at openwall.com> in 2001, and placed
 * in the public domain.  There's absolutely no warranty.
 *
 * This differs from Colin Plumb's older public domain implementation in
 * that no 32-bit integer data type is required, there's no compile-time
 * endianness configuration, and the function prototypes match OpenSSL's.
 * The primary goals are portability and ease of use.
 *
 * This implementation is meant to be fast, but not as fast as possible.
 * Some known optimizations are not included to reduce source code size
 * and avoid compile-time configuration.
 */

/*
 * Updated by Scott MacVicar for arduino
 * <scott@macvicar.net>
 */

typedef unsigned long MD5_u32plus;

//typedef struct {
//    MD5_u32plus lo, hi;
//    MD5_u32plus a, b, c, d;
//    unsigned char buffer[64];
//    MD5_u32plus block[16];
//} MD5_CTX;/**< MD5 context */

class MD5
{
public:
	/**
	 * class constructor.
	 * Does nothing.
	 */
	MD5();

    /** This processes one or more 64-byte data blocks, but does NOT update the bit counters.
     *  There are no alignment requirements.
     *
     *  @param data pointer to the data that will be processed
     *  @param size size_t type, that hold the size
     */
    void update(const void *data, size_t size);

    /** finish finilized the Hashing process and creates the diggest.
     *  This function must be called after MD5Init and MD5Update
     *  @param result pointer that will hold the digest.
     *  The class is not usable anymore after this
     */
    void finish(unsigned char *result);

private:

    void body(const void *data, size_t size);

    MD5_u32plus lo, hi;
    MD5_u32plus a, b, c, d;
    unsigned char buffer[64];
    MD5_u32plus block[16];
};
extern MD5 hashMD5;
#endif


