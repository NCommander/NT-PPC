// keys.h - header file for reusable interface

    //
    // This is only for IS2WCGI: We want to store the inbound data
    // in a temporary file so we are compatible with 100% of the
    // applications that rely on IS2WCGI.DLL to call them.
    //
    #define USE_TEMPORARY_FILES
    //
    // Remove this constant unless you need support for multi-megabyte
    // requests (like a multi-part MIME that has a file attached).
    //


// Abstracted pointer
typedef void * HKEYLIST;

//
// Retrieves and decodes inbound form data.  Builds list of keys, and
// pointers to data within a content file.  Returns handle to first
// element in the list.
//

HKEYLIST GetKeyList (EXTENSION_CONTROL_BLOCK *pECB);

//
// GetKeyInfo extracts the key name and content values from the
// supplied key, and returns a handle to the next key in the list.
//
// The length is the exact length of the inbound data, but a NULL
// is appended to the data.  For example, a text string of five
// characters has a *pdwLength=5, but GetKeyBuffer returns at
// least a 6 byte buffer--the five characters and a NULL.
//

HKEYLIST GetKeyInfo (HKEYLIST hKey, LPCTSTR *plpszKeyName, 
                     LPDWORD pdwLength, BOOL *pbHasCtrlChars,
                     LPINT pnInstance);

//
// GetKeyBuffer returns a pointer to the buffer holding data.
// Depending on the implementation in keys.cpp, this may or may not
// be a buffer the exact size of the data (it may be bigger).
//
// The data is zero-terminated.
//

LPBYTE GetKeyBuffer (HKEYLIST hKey);


//
// FindKey sequentially searches the linked list for a specific key.
// The return handle can be used with GetKeyInfo to get more details.
// FindKey returns the very first occurance of a duplicate key.
// Also, it searches from the given key which need not be the head
// key.
//

HKEYLIST FindKey (HKEYLIST hKeyList, LPCTSTR lpszSearchName);


//
// FreeKeyList releases all of the memory associated with a key list.
// Also, content resources are deleted.
//

void FreeKeyList (HKEYLIST hKeyList);


//
// GetKeyOffset returns the offset within the internal buffer or
// the content file.  Under normal circumstances, use GetKeyInfo
// and GetKeyBuffer instead of directly accessing the buffer.
//

DWORD GetKeyOffset (HKEYLIST hKey);


#ifdef USE_TEMPORARY_FILES
//
// GetContentFile returns the name of the temporary file used
// to save the content.  The temporary file may be open.
//

LPCTSTR GetContentFile (HKEYLIST hKeyList);

//
// CloseContentFile forces the content file to be closed.  This
// allows you to pass the file to something else that may open
// it.  Call OpenContentFile before calling any other key
// function.
//

void CloseContentFile (HKEYLIST hKeyList);


//
// OpenContentFile forces the content file to be reopened.
// GetKeyBuffer will fail if the content file was closed by
// CloseContentFile, but not reopened.
//

void OpenContentFile (HKEYLIST hKeyList);

#else

//
// GetDataBuffer returns a pointer to the start of the data
// buffer which holds all content.  This function is not
// particularly useful -- use GetKeyBuffer to get a pointer
// to the buffer for a specific key.
//

LPBYTE GetDataBuffer (HKEYLIST hKey);

#endif

