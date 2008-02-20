/*
 * PDFedit - free program for PDF document manipulation.
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko,
 *                                              Miroslav Jahoda,
 *                                              Jozef Misutka,
 *                                              Martin Petricek
 * Project is hosted on http://sourceforge.net/projects/pdfedit
 */
// vim:tabstop=4:shiftwidth=4:noexpandtab:textwidth=80

#ifndef _COMPILER_H_
#define _COMPILER_H_


//
// GCC specific stuff
//
#ifdef __GNUC__
	
#define USE_GCC_PRAGMAS
#endif
/* There is a bug in the version of gcc which ships with MacOS X 10.2 */
#if defined(__APPLE__) && defined(__MACH__)
#  include <AvailabilityMacros.h>
#endif
#ifdef MAC_OS_X_VERSION_MAX_ALLOWED
#  if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
#    undef USE_GCC_PRAGMAS
#  endif

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#else

//
// We don't have gcc
//
	#define __atribute__(x)
#endif

#endif

