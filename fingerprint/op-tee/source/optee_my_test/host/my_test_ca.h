#ifndef MOUDLE_NAME_H_
#define MOUDLE_NAME_H_

//TODO 定义UUID 和 Command ID
#define TA_MY_TEST_UUID { 0x9269fadd, 0x99d5, 0x4afb, \
	{0xa1, 0xdc, 0xee, 0x3e, 0x9c, 0x61, 0xb0, 0x4c}}

#define TA_MY_TEST_CMD_INC_VALUE 	0
#define TA_MY_TEST_CMD_HASH 		1
#define TA_MY_TEST_CMD_RANDOM 		2


#define FAIL -1
#define OK 0

/* SHA operation type */
typedef enum
{
    EN_OP_SHA1 = 1,
    EN_OP_SHA224,
    EN_OP_SHA256,
    EN_OP_SHA384,
    EN_OP_SHA512,
    EN_OP_SHA_INVALID
}EN_SHA_MODE;


/* Define the type of variable */
typedef unsigned char  UINT8;    /**< Typedef for 8bits unsigned integer  */
typedef unsigned short UINT16;   /**< Typedef for 16bits unsigned integer */
typedef uint32_t       UINT32;   /**< Typedef for 32bits unsigned integer */
typedef signed char    INT8;     /**< Typedef for 8bits signed integer    */
typedef signed short   INT16;    /**< Typedef for 16bits signed integer   */
typedef signed int     INT32;    /**< Typedef for 32bits signed integer   */
typedef char           CHAR;     /**< Typedef for char                    */


#ifndef MODULE_NAME_C_

#endif

#endif  /* MOUDLE_NAME_H*/
