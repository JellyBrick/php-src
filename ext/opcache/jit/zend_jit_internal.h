/*
   +----------------------------------------------------------------------+
   | Zend JIT                                                             |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2016 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Dmitry Stogov <dmitry@zend.com>                             |
   |          Xinchen Hui <xinchen.h@zend.com>                            |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_JIT_INTERNAL_H
#define ZEND_JIT_INTERNAL_H

/* Profiler */
extern zend_ulong zend_jit_profile_counter;
extern int zend_jit_profile_counter_rid;

#define ZEND_COUNTER_INFO(op_array)  ((op_array)->reserved[zend_jit_profile_counter_rid])

/* Hot Counters */
#define ZEND_HOT_COUNTERS_COUNT 128

extern int16_t zend_jit_hot_counters[ZEND_HOT_COUNTERS_COUNT];

void zend_jit_hot_func(zend_execute_data *execute_data, const zend_op *opline);

/* VM handlers */
typedef void (ZEND_FASTCALL *zend_vm_opcode_handler_t)(void);

/* VM helpers */
void ZEND_FASTCALL zend_jit_leave_nested_func_helper(uint32_t call_info);
void ZEND_FASTCALL zend_jit_leave_top_func_helper(uint32_t call_info);
void ZEND_FASTCALL zend_jit_copy_extra_args_helper(void);
void ZEND_FASTCALL zend_jit_deprecated_or_abstract_helper(void);
void ZEND_FASTCALL zend_jit_func_header_helper(void);
void ZEND_FASTCALL zend_jit_loop_header_helper(void);
void ZEND_FASTCALL zend_jit_profile_helper(void);
void ZEND_FASTCALL zend_jit_func_counter_helper(void);
void ZEND_FASTCALL zend_jit_loop_counter_helper(void);

#endif /* ZEND_JIT_INTERNAL_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
