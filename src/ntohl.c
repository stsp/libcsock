/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2021 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Implementation of ntohl() for Linux and RDOS.
*
****************************************************************************/


#include <sys/types.h>
#include <netinet/in.h>

#ifdef __RDOS__
#include <rdos.h>
#endif

_WCRTLINK unsigned long ntohl( unsigned long netlong )
{
#if defined( __RDOS__ )
    return( (unsigned long)RdosSwapLong( netlong ) );
#elif defined( __BIG_ENDIAN__ )
    return( netlong );
#else
    return( ((netlong >> 24) & 0xff) | ((netlong >> 16) & 0xff) << 8 |
                     ((netlong >> 8) & 0xff) << 16 | (netlong & 0xff) << 24 );
#endif
}
