/* $Id: issuetests.cpp 54 2013-07-04 12:04:51Z rijswijk $ */

/*
 * Copyright (c) 2014 Antonio de la Piedra
 * Copyright (c) 2013 Roland van Rijswijk-Deij
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 issuetests.cpp

 Test credential issuance
 *****************************************************************************/

#include <stdlib.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include <gmpxx.h>
#include <time.h>
#include "managertests.h"
#include "silvia_issuer.h"
#include "silvia_types.h"
#include "silvia_parameters.h"
#include "silvia_macros.h"
#include "silvia_irma_issuer.h"
#include "silvia_irma_manager.h"

CPPUNIT_TEST_SUITE_REGISTRATION(manager_tests);

void manager_tests::setUp()
{
}

void manager_tests::tearDown()
{
}


void manager_tests::test_irma_manager()
{

	std::string PIN = "000000";
	silvia_irma_manager irma_manager;
	std::vector<bytestring> commands = irma_manager.get_log_commands(PIN);

	CPPUNIT_ASSERT(commands[0] == "00A4040009F849524D416361726400"); // select
	CPPUNIT_ASSERT(commands[1] == "00200001083030303030300000"); // VERIFY APDU
	CPPUNIT_ASSERT(commands[2] == "803B0000"); // LOG #1
	CPPUNIT_ASSERT(commands[3] == "803B0F00"); // LOG #2
}
