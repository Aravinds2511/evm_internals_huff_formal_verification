// 0x608060405234801561000f575f80fd5b506101438061001d5f395ff3fe608060405234801561000f575f80fd5b5060043610610034575f3560e01c8063cdfead2e14610038578063e026c01714610054575b5f80fd5b610052600480360381019061004d91906100ba565b610072565b005b61005c61007b565b60405161006991906100f4565b60405180910390f35b805f8190555050565b5f8054905090565b5f80fd5b5f819050919050565b61009981610087565b81146100a3575f80fd5b50565b5f813590506100b481610090565b92915050565b5f602082840312156100cf576100ce610083565b5b5f6100dc848285016100a6565b91505092915050565b6100ee81610087565b82525050565b5f6020820190506101075f8301846100e5565b9291505056fea26469706673582212202933696e039e00fd68f73eaa120fd8e644406f3362bb5018edda82d7553a662b64736f6c63430008140033

// horsestore solidity contract opcode breakdown.

// FREE MEMORY POINTER
PUSH1 0x80   // [0x80]
PUSH1 0x40   // [0x40, 0x80] 
MSTORE       // free memory pointer

// CHECK FOR MSG.VALUE - JUMP IF ZERO OR REVERT IF ANY VALUE
CALLVALUE    // [msg.value]
DUP1         // [msg.value, msg.value]
ISZERO       // [msg.value == 0, msg.value]
PUSH2 0x000f // [0x000f, msg.value == 0, msg.value]
JUMPI        // [msg.value]
PUSH0        // [0x00, msg.value]
DUP1         // [0x00, 0x00, msg.value]
REVERT       // [msg.value]

// CONTRACT CREATION - VIA TRANSACTION 
JUMPDEST     // [msg.value]
POP          // []
PUSH2 0x0143 // [0x0143]
DUP1         // [0x0143, 0x0143]
PUSH2 0x001d // [0x001d, 0x0143, 0x0143] 
PUSH0        // [0x00, 0x001d, 0x0143, 0x0143]
CODECOPY     // [0x0143]                       // Memory: [runtime code]
PUSH0        // [0x00, 0x0143]
RETURN       // []              // returns from memory
INVALID      // []

// ----------------------------------------------------------------
// RUNTIME CODE 
// FREE MEMORY POINTER
PUSH1 0x80
PUSH1 0x40
MSTORE

// CHECK FOR MSG.VALUE - JUMP IF ZERO OR REVERT IF ANY VALUE
CALLVALUE    // [msg.value]
DUP1         // [msg.value, msg.value]
ISZERO       // [msg.value == 0, msg.value]
PUSH2 0x000f // [0x000f, msg.value == 0, msg.value]
JUMPI        // [msg.value]
PUSH0        // [0x00, msg.value]
DUP1         // [0x00, 0x00, msg.value]
REVERT       // [msg.value]

// WHEN THERE IS NO CALLVALUE
JUMPDEST     // [msg.value]
POP          // []

// CHECK CALLDATA SIZE 
PUSH1 0x04   // [0x04]
CALLDATASIZE // [calldata_size_bytes, 0x04] 
LT           // [calldata_size_bytes < 0x04 = 1]
PUSH2 0x0034 // [0x0034, calldata_size_bytes < 0x04 = 1]
JUMPI        // []

// FUNCTION DISPATCHING - CHECK FOR FIRST FUNCTION SELECTOR - updateHorseNumber 
PUSH0        // [0x00]
CALLDATALOAD // [calldata_32bytes]
PUSH1 0xe0   // [0x0e, calldata_32bytes] // 28 bytes right shift
SHR          // [function_selector_4_bytes]
DUP1         // [function_selector_4_bytes, function_selector_4_bytes]
PUSH4 0xcdfead2e // [0xcdfead2e, function_selector_4_bytes, function_selector_4_bytes]
EQ               // [0xcdfead2e == function_selector_4_bytes = 1, function_selector_4_bytes]
PUSH2 0x0038     // [0x0038, 0xcdfead2e == function_selector_4_bytes = 1, function_selector_4_bytes]
JUMPI            // [function_selector_4_bytes]

// FUNCTION DISPATCHING - CHECK FOR SECOND FUNCTION SELECTOR - readNumberOfHorses
DUP1             // [function_selector_4_bytes, function_selector_4_bytes]      
PUSH4 0xe026c017 // [0xe026c017, function_selector_4_bytes, function_selector_4_bytes] 
EQ               // [0xe026c017 == function_selector_4_bytes = 1, function_selector_4_bytes]
PUSH2 0x0054     // [0x0054, 0xe026c017 == function_selector_4_bytes = 1, function_selector_4_bytes]
JUMPI            // [function_selector_4_bytes]

// REVERT IF THERE THE CALDATA IS LESS THAN 0X04 BYTES
JUMPDEST     // []
PUSH0        // [0x00]
DUP1         // [0x00, 0x00]
REVERT       // []

// START OF THE UPDATEHORSENUMBER FUNCTION 
// ---pc - 0x0038---
JUMPDEST     // [function_selector_4_bytes]
PUSH2 0x0052 // [0x0052, function_selector_4_bytes]
PUSH1 0x04   // [0x04, 0x0052, function_selector_4_bytes]
DUP1         // [0x04, 0x04, 0x0052, function_selector_4_bytes]
CALLDATASIZE // [calldata_size_bytes, 0x04, 0x04, 0x0052, function_selector_4_bytes]
SUB          // [calldata_size_bytes - 0x04, 0x04, 0x0052, function_selector_4_bytes]
DUP2         // [0X04, (calldata_size_bytes - 0x04), 0x04, 0x0052, function_selector_4_bytes]
ADD          // [(0X04 + (calldata_size_bytes - 0x04)), 0x04, 0x0052, function_selector_4_bytes]
SWAP1        // [0X04, calldata_size_bytes, 0x0052, function_selector_4_bytes]
PUSH2 0x004d // [0x004d, 0X04, calldata_size_bytes, 0x0052, function_selector_4_bytes]
SWAP2        // [calldata_size_bytes, 0X04, 0x004d, 0x0052, function_selector_4_bytes]
SWAP1        // [0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00ba // [0x00ba, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP         // [0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc - 0x004d---
JUMPDEST     // [calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
PUSH2 0x0072 // [0x0072, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
JUMP         // [calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
// ---pc - 0x0052---
JUMPDEST     // [function_selector_4_bytes]
STOP         // [function_selector_4_bytes]  // HALTS EXECUTION
// ---pc - 0x0054---
JUMPDEST       // [function_selector_4_bytes]
PUSH2 0x005c   // [0x005c, function_selector_4_bytes]
PUSH2 0x007b   // [0x007b, 0x005c, function_selector_4_bytes]
JUMP           // [0x005c, function_selector_4_bytes]
// ---pc - 0x005c---
JUMPDEST       // [stored_value, function_selector_4_bytes]
PUSH1 0x40     // [0x40, stored_value, function_selector_4_bytes]
MLOAD          // [free_memory_pointer(0x80), stored_value, function_selector_4_bytes]
PUSH2 0x0069   // [0x0069, free_memory_pointer(0x80), stored_value, function_selector_4_bytes]
SWAP2          // [stored_value, free_memory_pointer(0x80), 0x0069, function_selector_4_bytes]
SWAP1          // [free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH2 0x00f4   // [0x00f4, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMP           // [free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMPDEST
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
// returns 32 bytes from memory where it was mload-ed
RETURN
// ---pc - 0x0072---
JUMPDEST  // [calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
DUP1      // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
PUSH0     // [0x00, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
DUP2      // [calldata[0x04:]_32bytes, 0x00, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
SWAP1     // [0x00, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
SSTORE    // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]                                 // STORAGE : [0X00 : calldata[0x04:]_32bytes]
POP       // [calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]  
POP       // [0x0052, function_selector_4_bytes]  
JUMP      // [function_selector_4_bytes]

// START OF THE READNUMBEROFHORSES FUNCTION 
// ---pc - 0x007b---
JUMPDEST  // [0x005c, function_selector_4_bytes]
PUSH0     // [0x00, 0x005c, function_selector_4_bytes]
DUP1      // [0x00, 0x00, 0x005c, function_selector_4_bytes]
SLOAD     // [stored_value, 0x00, 0x005c, function_selector_4_bytes]
SWAP1     // [0x00, stored_value, 0x005c, function_selector_4_bytes]
POP       // [stored_value, 0x005c, function_selector_4_bytes]
SWAP1     // [0x005c, stored_value, function_selector_4_bytes]
JUMP      // [stored_value, function_selector_4_bytes]
// ---pc - 0x0083---
JUMPDEST // [0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH0    // [0x00, 0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP1     // [0x00, 0x00, 0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
REVERT   // [...]
// ---pc - 0x0087---
JUMPDEST // [calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH0 // [0x00, calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP2  // [calldata[0x04:]_32bytes, 0x00, calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP1 // [0x00, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP   // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP2 // [0x0099, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP1 // [calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP   // [0x0099, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP  // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc - 0x0090---
JUMPDEST     // [calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x0099 // [0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP2         // [calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x0087 // [0x0087, calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP // [calldata[0x04:]_32bytes, 0x0099, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc- 0x0099---
JUMPDEST // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP2    // [calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
EQ      // [(calldata[0x04:]_32bytes == calldata[0x04:]_32bytes), calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00a3 // [0x00a3, (calldata[0x04:]_32bytes == calldata[0x04:]_32bytes), calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMPI   // [calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// revert code
PUSH0
DUP1
REVERT
// ---pc - 0x00a3---
JUMPDEST   // [calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP       // [0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP      // [calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc - 0x00a6---
JUMPDEST     // [0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH0        // [0x00, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP2         // [0x04, 0x00, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
CALLDATALOAD // [calldata[0x04:]_32bytes, 0x00, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP1        // [0x00, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP          // [calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00b4 // [0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP2         // [calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x0090 // [0x0090, calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP         // [calldata[0x04:]_32bytes, 0x00b4, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc - 0x00b4---
JUMPDEST // [calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP3    // [0x00dc, 0x04, calldata_size_bytes, calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP2    // [calldata_size_bytes, 0x04, 0x00dc, calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP      // [0x04, 0x00dc, calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP      // [0x00dc, calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP     // [calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// JUMP 0x00ba
JUMPDEST     // [0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH0        // [0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH1 0x20   // [0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP3         // [0x04, 0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP5         // [calldata_size_bytes, 0x04, 0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SUB          // [(calldata_size_bytes - 0x04), 0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---check if there is more calldata than just the function selector---
SLT          // [(calldata_size_bytes - 0x04) < 0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
ISZERO       // [(calldata_size_bytes - 0x04) < 0x20 == 0, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00cf // [0x00cf, (calldata_size_bytes - 0x04) < 0x20, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---jump if there is calldata other than func selector---
JUMPI        // [0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00ce // [0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x0083 // [0x0083, 0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---jumps to the revert code---
JUMP         // [0x00ce, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMPDEST
// ---pc - 0x00cf---
JUMPDEST     // [0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH0        // [0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00dc // [0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP5         // [calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP3         // [0x00, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
DUP6         // [0x04, 0x00, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
ADD          // [0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
PUSH2 0x00a6 // [0x00a6, 0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
JUMP         // [0x04, calldata_size_bytes, 0x00dc, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
// ---pc - 0x00dc---
JUMPDEST     // [calldata[0x04:]_32bytes, 0x00, 0x00, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP2        // [0x00, 0x00, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP          // [0x00, calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
POP          // [calldata[0x04:]_32bytes, 0x04, calldata_size_bytes, 0x004d, 0x0052, function_selector_4_bytes]
SWAP3        // [0x004d, 0x04, calldata_size_bytes, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
SWAP2        // [calldata_size_bytes, 0x04, 0x004d, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
POP          // [0x04, 0x004d, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
POP          // [0x004d, calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
JUMP         // [calldata[0x04:]_32bytes, 0x0052, function_selector_4_bytes]
// ---pc - 0x00e5---
JUMPDEST      // [stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH2 0x00ee  // [0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP2          // [stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH2 0x0087  // [0x0087, stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMP          // [stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
// ---pc - 0x00ee---
JUMPDEST      // [stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP3          // [0x0107, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
MSTORE        // [0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]                        // [stored_value] offset - 0x0107
POP           // [0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]   
POP           // [0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMP          // [free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
// ---pc - 0x00f4---
JUMPDEST      // [free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH0         // [0x00, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH1 0x20    // [0x20, 0x00, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP3          // [free_memory_pointer(0x80), 0x20, 0x00, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
ADD           // [0xa0, 0x00, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
SWAP1         // [0x00, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
POP           // [0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]]
PUSH2 0x0107  // [0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH0         // [0x00, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP4          // [free_memory_pointer(0x80), 0x00, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
ADD           // [0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP5          // [stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH2 0x00e5  // [0x00e5, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMP          // [stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP

// --------------------------------------------------
// METADATA
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
INVALID
CALLER
PUSH10 0x6e039e00fd68f73eaa12
INVALID
INVALID
INVALID
PREVRANDAO
BLOCKHASH
PUSH16 0x3362bb5018edda82d7553a662b64736f
PUSH13 0x63430008140033


// COPY OF THE JUMPDEST CODE IN PC - 0x0087 - for read function 
// ---pc - 0x0087---
JUMPDEST   // [stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
PUSH0      // [0x00, stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
DUP2       // [stored_value, 0x00, stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
SWAP1      // [0x00, stored_value, stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
POP        // [stored_value, stored_value, 0x00ee, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
SWAP2      // [0x00ee, stored_value, stored_value, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
SWAP1      // [stored_value, 0x00ee, stored_value, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
POP        // [0x00ee, stored_value, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]
JUMP       // [stored_value, stored_value, 0x80, 0x0107, 0xa0, free_memory_pointer(0x80), stored_value, 0x0069, function_selector_4_bytes]

// pc - program counter