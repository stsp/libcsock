/* Kendall's select.h for WattTCP32
 */

#ifndef __WATT_SYS_SELECT_H
#define __WATT_SYS_SELECT_H

#ifndef __SYS_WTYPES_H
#include <sys/wtypes.h>
#endif
#ifndef __SYS_WTIME_H
#include <sys/wtime.h>
#endif

#define select(a,b,c,d,e) select_s(a,b,c,d,e)
int select_s (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

#endif /* __WATT_SYS_SELECT_H */

