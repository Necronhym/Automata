#ifndef LUASCRIPT_H
#define LUASCRIPT_H
#include <functional>
extern "C"
	{
		#include "LuaCore/lua.h"
		#include "LuaCore/lualib.h"
		#include "LuaCore/lauxlib.h"
	}
class luaScript
	{
		lua_State *L;
		int script;
		public:	
		luaScript();
		lua_State* getLuaState();
		void passStringToLua(const char* string);
		void passFuncToLua( int(*fu)(lua_State*), const char* funcName);
		void doScript();
		void loadScript(const char* scriptLocation);
		~luaScript();
	};
#endif
