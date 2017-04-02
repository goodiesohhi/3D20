#pragma once
#include "desc/desc.h"

typedef enum
{
	AES_128_KEY_SIZE = 16,
	MAX_CMN_KEY = MAX_U8,
	MAX_NCCH_KEYX = MAX_U8
} keydata_limits;

typedef enum
{
	KEYSET_ERROR = -10,
} keyset_errors;

typedef enum
{
	RSA_1024_KEY_SIZE = 0x80,
	RSA_2048_KEY_SIZE = 0x100,
	RSA_4096_KEY_SIZE = 0x200,
} rsa_keysize;

typedef enum
{
	pki_TEST,
	pki_BETA, // Not used, but is here for completeness
	pki_DEVELOPMENT,
	pki_PRODUCTION,
	pki_CUSTOM,
} pki_keyset;

// Structs

typedef struct
{
	pki_keyset keyset;
	bool keysetLoaded;
	bool dumpkeys;

	struct
	{
		u32 presetType;
		u32 targetFirmware;
	} accessDescSign;

	struct
	{
		// CIA
		u8 **commonKey;
		u16 currentCommonKey;
		
		// NCCH Keys
		u8 *normalKey;
		u8 *systemFixedKey;
		u8 **ncchKeyX;
		
		u8 *ncchKey0;
		u8 *ncchKey1;
	} aes;
	
	struct
	{
		bool isFalseSign;
		// CIA RSA
		u8 *cpPvt;
		u8 *cpPub;
		u8 *xsPvt;
		u8 *xsPub;
		
		// CCI/CFA
		u8 *cciCfaPvt;
		u8 *cciCfaPub;
		
		// CXI
		bool requiresPresignedDesc;
		u8 *acexPvt;
		u8 *acexPub;
		u8 *cxiHdrPub;
		u8 *cxiHdrPvt;
	} rsa;
	
	struct
	{
		// CIA
		u8 *caCert;
		u8 *xsCert;
		u8 *cpCert;
	} certs;
} keys_struct;

// Public Prototypes
void InitKeys(keys_struct *keys);
int SetKeys(keys_struct *keys);
void FreeKeys(keys_struct *keys);

int SetCommonKey(keys_struct *keys, const u8 *key, u8 Index);
int SetCurrentCommonKey(keys_struct *keys, u8 Index);
int SetNormalKey(keys_struct *keys, const u8 *key);
int SetSystemFixedKey(keys_struct *keys, const u8 *key);