/*
 * user-defined.h
 *
 *  Created on: Mar 10, 2010
 *      Author: trungtq
 */

#ifndef USERDEFINED_H_
#define USERDEFINED_H_

#define _TRUNGTQ_CODE_			// co the la _TrungTQ_Code hoac _SPASS_Code

enum CodeUser {
	TrungTQ,
	SPASS,
	All
};

static enum CodeUser codeUser = SPASS;				// xac dinh doan code se dc chay

#endif /* USERDEFINED_H_ */
