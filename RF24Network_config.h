
/*
 Copyright (C) 2011 James Coliz, Jr. <maniacbug@ymail.com>

 Modified by Aleksandr Borisenko to make it compile without arduino core.
 NOTE: Only the ATmega328P is supported.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

#ifndef __RF24NETWORK_CONFIG_H__
#define __RF24NETWORK_CONFIG_H__

//#define DUAL_HEAD_RADIO
//#define ENABLE_SLEEP_MODE  //AVR only
//#define RF24NetworkMulticast

// Saves memory by disabling fragmentation
//#define DISABLE_FRAGMENTATION

/** System defines */

/** The size of the main buffer. This is the user-cache, where incoming data is stored.
 * Data is stored using Frames: Header (8-bytes) + Frame_Size (2-bytes) + Data (?-bytes)
 *
 * @note The MAX_PAYLOAD_SIZE is (MAIN_BUFFER_SIZE - 10), and the result must be divisible by 24.
 */
#define MAIN_BUFFER_SIZE 144 + 10

/** Maximum size of fragmented network frames and fragmentation cache. This MUST BE divisible by 24.
 * @note: Must be a multiple of 24.
 * @note: If used with RF24Ethernet, this value is used to set the buffer sizes.
 */
#define MAX_PAYLOAD_SIZE  MAIN_BUFFER_SIZE-10

/** Disable user payloads. Saves memory when used with RF24Ethernet or software that uses external data.*/
//#define DISABLE_USER_PAYLOADS

/** Enable tracking of success and failures for all transmissions, routed and user initiated */
//#define ENABLE_NETWORK_STATS
    
/** Enable dynamic payloads - If using different types of NRF24L01 modules, some may be incompatible when using this feature **/
#define ENABLE_DYNAMIC_PAYLOADS

/** Debug Options */
//#define SERIAL_DEBUG
//#define SERIAL_DEBUG_MINIMAL
//#define SERIAL_DEBUG_ROUTING
//#define SERIAL_DEBUG_FRAGMENTATION
//#define SERIAL_DEBUG_FRAGMENTATION_L2

#include <RF24_config.h>

#if defined (SERIAL_DEBUG_MINIMAL)
#define IF_SERIAL_DEBUG_MINIMAL(x) ({x;})
#else
#define IF_SERIAL_DEBUG_MINIMAL(x)
#endif

#if defined (SERIAL_DEBUG_FRAGMENTATION)
#define IF_SERIAL_DEBUG_FRAGMENTATION(x) ({x;})
#else
#define IF_SERIAL_DEBUG_FRAGMENTATION(x)
#endif

#if defined (SERIAL_DEBUG_FRAGMENTATION_L2)
#define IF_SERIAL_DEBUG_FRAGMENTATION_L2(x) ({x;})
#else
#define IF_SERIAL_DEBUG_FRAGMENTATION_L2(x)
#endif

#if defined (SERIAL_DEBUG_ROUTING)
#define IF_SERIAL_DEBUG_ROUTING(x) ({x;})
#else
#define IF_SERIAL_DEBUG_ROUTING(x)
#endif

#endif //RF24_NETWORK_CONFIG_H
