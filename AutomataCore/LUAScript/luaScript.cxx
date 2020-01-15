#include "luaScript.h"
luaScript::luaScript()
	{
		L=luaL_newstate();
		luaL_openlibs(L);
	}
void luaScript::passStringToLua(const char* string)
	{
		luaL_dostring(L, string);
	}
void luaScript::passFuncToLua( int(*fu)(lua_State*), const char* funcName)
	{
		lua_pushcfunction(L, fu);
		lua_setglobal(L, funcName);	
	}
void luaScript::loadScript(const char* scriptLocation)
	{
		luaL_loadfile(L, scriptLocation);
	}
void luaScript::doScript()
	{
		lua_call(L, 0, 0);
	}
lua_State* luaScript::getLuaState()
	{
		return L;
	}
luaScript::~luaScript()
	{
		lua_close(L);
	}
