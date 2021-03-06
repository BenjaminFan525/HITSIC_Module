#ifndef _SYS_RMCALL_HPP_
#define _SYS_RMCALL_HPP_
#include "hitsic_common.h"
#include "inc_stdlib.h"

#ifndef HITSIC_USE_RMCALL
#define HITSIC_USE_RMCALL 1U
#endif // ! HITSIC_USE_RMCALL

#if defined(HITSIC_USE_RMCALL) && (HITSIC_USE_RMCALL > 0)

//#define HITSIC_RMCALL_UART LPUART2

// #define HITSIC_RMCALL_USE_HEARTBEAT (1U)
// #if defined(HITSIC_RMCALL_USE_HEARTBEAT) && (HITSIC_RMCALL_USE_HEARTBEAT > 0)
// #define HITSIC_RMCALL_PITISR_TIMELAG 100
// #define HITSIC_RMCALL_HEARTBEAT_TIMELAG 1000
// #define HITSIC_RMCALL_HEARTBEAT_FAIL_TH 2000
// #define HITSIC_RMCALL_HEARTBEAT_Callback() HardFault_IRQHandler()
// #endif // ! HITSIC_RMCALL_USE_HEARTBEAT

#define HITSIC_RMCALL_HEADER_MAGIC 0x68U
#define HITSIC_RMCALL_STATUS_MAGIC 0x86U

#endif // ! HITSIC_RMCALL_USE_HEARTBEAT

#endif // HITSIC_USE_RMCALL

#endif // ! _SYS_RMCALL_HPP_