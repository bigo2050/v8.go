#ifndef _V8_WARP_H_
#define _V8_WARP_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
isolate wrappers
*/
extern void* V8_NewEngine();

extern void V8_DisposeEngine(void* engine);

/*
context wrappers
*/
extern void* V8_NewContext(void* engine);

extern void V8_DisposeContext(void* context);

/*
script wrappers
*/
extern void* V8_Compile(void* engine, const char* code, int length, void* script_origin, void* script_data);

extern void V8_DisposeScript(void* script);

extern void* V8_RunScript(void* context, void* script);

/*
script data wrappers
*/
extern void* V8_PreCompile(void* engine, const char* code, int length);

extern void* V8_NewScriptData(const char* data, int length);

extern void V8_DisposeScriptData(void* script_data);

extern int V8_ScriptDataLength(void* script_data);

extern const char* V8_ScriptDataGetData(void* script_data);

extern int V8_ScriptDataHasError(void* script_data);

/*
script origin wrappers
*/
extern void* V8_NewScriptOrigin(void* engine, const char* name, int name_length, int line_offset, int column_offset);

extern void V8_DisposeScriptOrigin(void* script_origin);

/*
value wrappers
*/
extern void V8_DisposeValue(void* value);

extern int V8_ValueIsUndefined(void* value);

extern int V8_ValueIsNull(void* value);

extern int V8_ValueIsTrue(void* value);

extern int V8_ValueIsFalse(void* value);

extern int V8_ValueIsString(void* value);

extern int V8_ValueIsFunction(void* value);

extern int V8_ValueIsArray(void* value);

extern int V8_ValueIsObject(void* value);

extern int V8_ValueIsBoolean(void* value);

extern int V8_ValueIsNumber(void* value);

extern int V8_ValueIsExternal(void* value);

extern int V8_ValueIsInt32(void* value);

extern int V8_ValueIsUint32(void* value);

extern int V8_ValueIsDate(void* value);

extern int V8_ValueIsBooleanObject(void* value);

extern int V8_ValueIsNumberObject(void* value);

extern int V8_ValueIsStringObject(void* value);

extern int V8_ValueIsNativeError(void* value);

extern int V8_ValueIsRegExp(void* value);

/*
special values
*/
extern void* V8_Undefined(void* engine);

extern void* V8_Null(void* engine);

extern void* V8_True(void* engine);

extern void* V8_False(void* engine);

extern int V8_ValueToBoolean(void* value);
  
extern double V8_ValueToNumber(void* value);

extern int64_t V8_ValueToInteger(void* value);

extern uint32_t V8_ValueToUint32(void* value);

extern int32_t V8_ValueToInt32(void* value);

extern char* V8_ValueToString(void* value);

extern void* V8_NewNumber(void* engine, double val);

extern void* V8_NewString(void* engine, const char* val, int val_length);

/*
object
*/
extern void* V8_NewObject(void* engine);

extern int V8_ObjectSetProperty(void* value, const char* key, int key_length, void* prop_value, int attribs);

extern void* V8_ObjectGetProperty(void* value, const char* key, int key_length);

extern int V8_ObjectSetElement(void* value, uint32_t index, void* elem_value);

extern void* V8_ObjectGetElement(void* value, uint32_t index);

extern int V8_ObjectGetPropertyAttributes(void *value, const char* key, int key_length);

extern int V8_ObjectForceSetProperty(void* value, const char* key, int key_length, void* prop_value, int attribs);

extern int V8_ObjectHasProperty(void *value, const char* key, int key_length);

extern int V8_ObjectDeleteProperty(void *value, const char* key, int key_length);

extern int V8_ObjectForceDeleteProperty(void *value, const char* key, int key_length);

extern int V8_ObjectHasElement(void* value, uint32_t index);

extern int V8_ObjectDeleteElement(void* value, uint32_t index);

extern void* V8_ObjectGetPropertyNames(void *value);

extern void* V8_ObjectGetOwnPropertyNames(void *value);

extern void* V8_ObjectGetPrototype(void *value);

extern int V8_ObjectSetPrototype(void *value, void *proto);

/*
array
*/
extern void* V8_NewArray(void* engine, int length);

extern int V8_ArrayLength(void* value);

/*
regexp
*/
extern void* V8_NewRegExp(void* engine, const char* pattern, int length, int flags);

extern char* V8_RegExpPattern(void* value);

extern int V8_RegExpFlags(void* value);

/*
function
*/
extern void* V8_FunctionCall(void* value, int argc, void* argv);

#ifdef __cplusplus
} // extern "C"
#endif

#endif