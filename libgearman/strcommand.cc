/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * 
 *  Gearmand client and server library.
 *
 *  Copyright (C) 2011 Data Differential, http://datadifferential.com/
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <config.h>

#include <libgearman/command.h>
#include <libgearman/strcommand.h>

#include <cassert>
#include <cstdlib>

const char *gearman_strcommand(gearman_command_t command)
{
  switch(command)
  {
  case GEARMAN_COMMAND_TEXT: return "GEARMAN_COMMAND_TEXT";
  case GEARMAN_COMMAND_CAN_DO: return "GEARMAN_COMMAND_CAN_DO";
  case GEARMAN_COMMAND_CANT_DO: return "GEARMAN_COMMAND_CANT_DO";
  case GEARMAN_COMMAND_RESET_ABILITIES: return "GEARMAN_COMMAND_RESET_ABILITIES";
  case GEARMAN_COMMAND_PRE_SLEEP: return "GEARMAN_COMMAND_PRE_SLEEP";
  case GEARMAN_COMMAND_UNUSED: return "GEARMAN_COMMAND_UNUSED";
  case GEARMAN_COMMAND_NOOP: return "GEARMAN_COMMAND_NOOP";
  case GEARMAN_COMMAND_SUBMIT_JOB: return "GEARMAN_COMMAND_SUBMIT_JOB";
  case GEARMAN_COMMAND_JOB_CREATED: return "GEARMAN_COMMAND_JOB_CREATED";
  case GEARMAN_COMMAND_GRAB_JOB: return "GEARMAN_COMMAND_GRAB_JOB";
  case GEARMAN_COMMAND_NO_JOB: return "GEARMAN_COMMAND_NO_JOB";
  case GEARMAN_COMMAND_JOB_ASSIGN: return "GEARMAN_COMMAND_JOB_ASSIGN";
  case GEARMAN_COMMAND_WORK_STATUS: return "GEARMAN_COMMAND_WORK_STATUS";
  case GEARMAN_COMMAND_WORK_COMPLETE: return "GEARMAN_COMMAND_WORK_COMPLETE";
  case GEARMAN_COMMAND_WORK_FAIL: return "GEARMAN_COMMAND_WORK_FAIL";
  case GEARMAN_COMMAND_GET_STATUS: return "GEARMAN_COMMAND_GET_STATUS";
  case GEARMAN_COMMAND_ECHO_REQ: return "GEARMAN_COMMAND_ECHO_REQ";
  case GEARMAN_COMMAND_ECHO_RES: return "GEARMAN_COMMAND_ECHO_RES";
  case GEARMAN_COMMAND_SUBMIT_JOB_BG: return "GEARMAN_COMMAND_SUBMIT_JOB_BG";
  case GEARMAN_COMMAND_ERROR: return "GEARMAN_COMMAND_ERROR";
  case GEARMAN_COMMAND_STATUS_RES: return "GEARMAN_COMMAND_STATUS_RES";
  case GEARMAN_COMMAND_SUBMIT_JOB_HIGH: return "GEARMAN_COMMAND_SUBMIT_JOB_HIGH";
  case GEARMAN_COMMAND_SET_CLIENT_ID: return "GEARMAN_COMMAND_SET_CLIENT_ID";
  case GEARMAN_COMMAND_CAN_DO_TIMEOUT: return "GEARMAN_COMMAND_CAN_DO_TIMEOUT";
  case GEARMAN_COMMAND_ALL_YOURS: return "GEARMAN_COMMAND_ALL_YOURS";
  case GEARMAN_COMMAND_WORK_EXCEPTION: return "GEARMAN_COMMAND_WORK_EXCEPTION";
  case GEARMAN_COMMAND_OPTION_REQ: return "GEARMAN_COMMAND_OPTION_REQ";
  case GEARMAN_COMMAND_OPTION_RES: return "GEARMAN_COMMAND_OPTION_RES";
  case GEARMAN_COMMAND_WORK_DATA: return "GEARMAN_COMMAND_WORK_DATA";
  case GEARMAN_COMMAND_WORK_WARNING: return "GEARMAN_COMMAND_WORK_WARNING";
  case GEARMAN_COMMAND_GRAB_JOB_UNIQ: return "GEARMAN_COMMAND_GRAB_JOB_UNIQ";
  case GEARMAN_COMMAND_JOB_ASSIGN_UNIQ: return "GEARMAN_COMMAND_JOB_ASSIGN_UNIQ";
  case GEARMAN_COMMAND_SUBMIT_JOB_HIGH_BG: return "GEARMAN_COMMAND_SUBMIT_JOB_HIGH_BG";
  case GEARMAN_COMMAND_SUBMIT_JOB_LOW: return "GEARMAN_COMMAND_SUBMIT_JOB_LOW";
  case GEARMAN_COMMAND_SUBMIT_JOB_LOW_BG: return "GEARMAN_COMMAND_SUBMIT_JOB_LOW_BG";
  case GEARMAN_COMMAND_SUBMIT_JOB_SCHED: return "GEARMAN_COMMAND_SUBMIT_JOB_SCHED";
  case GEARMAN_COMMAND_SUBMIT_JOB_EPOCH: return "GEARMAN_COMMAND_SUBMIT_JOB_EPOCH";
  case GEARMAN_COMMAND_SUBMIT_REDUCE_JOB: return "GEARMAN_COMMAND_SUBMIT_REDUCE_JOB";
  case GEARMAN_COMMAND_SUBMIT_REDUCE_JOB_BACKGROUND: return "GEARMAN_COMMAND_SUBMIT_REDUCE_JOB_BACKGROUND";
  case GEARMAN_COMMAND_GRAB_JOB_ALL: return "GEARMAN_COMMAND_GRAB_JOB_ALL";
  case GEARMAN_COMMAND_JOB_ASSIGN_ALL: return "GEARMAN_COMMAND_JOB_ASSIGN_ALL";
  case GEARMAN_COMMAND_MAX: return "GEARMAN_COMMAND_MAX";
  case GEARMAN_COMMAND_GET_STATUS_UNIQUE: return "GEARMAN_COMMAND_GET_STATUS_UNIQUE";
  case GEARMAN_COMMAND_STATUS_RES_UNIQUE: return "GEARMAN_COMMAND_STATUS_RES_UNIQUE";
  }

  assert(0); // We should never reach this
  abort();
}
