/**************************************************************/
/* ********************************************************** */
/* *                                                        * */
/* *         EXTENDED KNUTH BENDIX ORDERING                 * */
/* *                                                        * */
/* *  $Module:   KBO                                        * */ 
/* *                                                        * */
/* *  Copyright (C) 1996, 1997, 2001 MPI fuer Informatik    * */
/* *                                                        * */
/* *  This program is free software; you can redistribute   * */
/* *  it and/or modify it under the terms of the GNU        * */
/* *  General Public License as published by the Free       * */
/* *  Software Foundation; either version 2 of the License, * */
/* *  or (at your option) any later version.                * */
/* *                                                        * */
/* *  This program is distributed in the hope that it will  * */
/* *  be useful, but WITHOUT ANY WARRANTY; without even     * */
/* *  the implied warranty of MERCHANTABILITY or FITNESS    * */
/* *  FOR A PARTICULAR PURPOSE.  See the GNU General Public * */
/* *  License for more details.                             * */
/* *                                                        * */
/* *  You should have received a copy of the GNU General    * */
/* *  Public License along with this program; if not, write * */
/* *  to the Free Software Foundation, Inc., 59 Temple      * */
/* *  Place, Suite 330, Boston, MA  02111-1307  USA         * */
/* *                                                        * */
/* *                                                        * */
/* $Revision: 1.1.1.1 $                                        * */
/* $State: Exp $                                            * */
/* $Date: 2006/02/20 10:28:28 $                             * */
/* $Author: topic $                                       * */
/* *                                                        * */
/* *             Contact:                                   * */
/* *             Christoph Weidenbach                       * */
/* *             MPI fuer Informatik                        * */
/* *             Stuhlsatzenhausweg 85                      * */
/* *             66123 Saarbruecken                         * */
/* *             Email: spass@mpi-inf.mpg.de                * */
/* *             Germany                                    * */
/* *                                                        * */
/* ********************************************************** */
/**************************************************************/


/* $RCSfile: kbo.h,v $ */

#ifndef _KBO_
#define _KBO_

/**************************************************************/
/* Includes                                                   */
/**************************************************************/

#include "term.h"
#include "context.h"
#include "foldfg.h"
#include "order.h"
#include "../usercode/user-defined.h"

/**************************************************************/
/*  FUNCTIONS                                                 */
/**************************************************************/

ord_RESULT kbo_Compare(TERM, TERM);
ord_RESULT kbo_ContCompare(CONTEXT, TERM, CONTEXT, TERM); 
BOOL       kbo_ContGreater(CONTEXT, TERM, CONTEXT, TERM);

#endif
