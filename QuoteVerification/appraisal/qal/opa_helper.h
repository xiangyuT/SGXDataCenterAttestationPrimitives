/*
 * Copyright (C) 2011-2023 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef OPA_HELPER_H
#define OPA_HELPER_H
#include "wasm_export.h"
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <map>
#define UNUSED(val) (void)(val)
extern std::map<int, std::string> g_builtins;

extern std::map<std::string, void *> g_builtin_func_map;

struct opa_value
{
 unsigned char type;
};

//OPA exported functions
int opa_builtins(wasm_module_inst_t module_inst,  wasm_exec_env_t exec_env);
int opa_eval_ctx_new(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env);
void opa_eval_ctx_set_input(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int ctx, int v);
int eval(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int ctx);
int opa_eval_ctx_get_result(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int ctx);
int opa_malloc(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, uint32_t size);
void opa_free(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int addr);
int opa_json_parse(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int input, uint32_t len);
int opa_json_dump(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int v);
int opa_heap_ptr_get(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env);
void opa_heap_ptr_set(wasm_module_inst_t module_inst, wasm_exec_env_t exec_env, int addr);

// OPA imported functions
int opa_builtin0(wasm_exec_env_t exec_env, int builtin_id, void *ctx);
int opa_builtin1(wasm_exec_env_t exec_env, int builtin_id, void *ctx, opa_value* a1);
int opa_builtin2(wasm_exec_env_t exec_env, int builtin_id, void *ctx, opa_value* a1, opa_value* a2);
int opa_builtin3(wasm_exec_env_t exec_env, int builtin_id, void *ctx, opa_value* a1, opa_value* a2, opa_value* a3);
int opa_builtin4(wasm_exec_env_t exec_env, int builtin_id, void *ctx, opa_value* a1, opa_value* a2, opa_value* a3, opa_value* a4);
void opa_abort(wasm_exec_env_t exec_env, const char *msg);

#endif