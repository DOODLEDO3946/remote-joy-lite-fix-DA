#include "dxerr.h"

const WCHAR* DXGetErrorStringW(HRESULT hr) {
    static WCHAR message[16];

    swprintf(message, 16, L"0x%08X", (unsigned)hr);

    return message;
}

const CHAR* DXGetErrorStringA(HRESULT hr) {
    static CHAR message[16];

    snprintf(message, 16, "0x%08X", (unsigned)hr);

    return message;
}