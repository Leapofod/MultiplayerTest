#include "network.h"

#include <stdio.h>

#define ENET_IMPLEMENTATION
#include "enet.h"
#undef ENET_IMPLEMENTATION

void InitNetwork()
{
    int result = enet_initialize();
    if (result < 0)
    {
        printf("WARNING: NETWORK: Failed to initialize enet\n");
        return;
    }

    printf("INFO: NETWORK: enet initialized successfully\n");
}

void CloseNetwork()
{
    enet_deinitialize();
}
