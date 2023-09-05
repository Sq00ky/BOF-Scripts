#include <Windows.h>
#include <iostream>
#include "bofdefs.h"

#pragma region error_handling
#define print_error(msg, hr) _print_error(__FUNCTION__, __LINE__, msg, hr)
BOOL _print_error(char* func, int line, char* msg, HRESULT hr) {
#ifdef BOF
    BeaconPrintf(CALLBACK_ERROR, "(%s at %d): %s 0x%08lx", func, line, msg, hr);
#else
    printf("[-] (%s at %d): %s 0x%08lx", func, line, msg, hr);
#endif // BOF

    return FALSE;
}
#pragma endregion

using namespace std;
#ifdef BOF


extern "C" int go() {
    USER32$MessageBoxA(NULL, "Hello From BOF-land!", "Meterpreter Says...", MB_OK);
    BeaconPrintf(CALLBACK_OUTPUT, "Success!");
    return 0;
}

#else

int main() {
    go();
    return 0;
}

#endif
