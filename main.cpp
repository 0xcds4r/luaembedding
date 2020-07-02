#include <iostream>
#include <string>

// include Lua, assumes it is local to this file
extern "C"
{
  #include "lua/include/lua.h"
  #include "lua/include/lauxlib.h"
  #include "lua/include/lualib.h"
}

bool CheckLua(lua_State *L, int r)
{
	if (r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		return false;
	}
  
	return true;
}

int lua_TestFunction(lua_State *L)
{
	float a = (float)lua_tonumber(L, 1);
	float b = (float)lua_tonumber(L, 2);
	std::cout << "[result] TestFunction(" << a << ", " << b << ")" << std::endl;
  
	return 1;
}

int main()
{	
	// Create Lua State
	lua_State *L = luaL_newstate();

	// Add default libraries to LVM
	luaL_openlibs(L);

	// Register our C++ Function in the global Lua space
	lua_register(L, "TestFunction", lua_TestFunction);
	 
	// Load and parse the Lua File
	if(CheckLua(L, luaL_dofile(L, "test.lua")))
	{ 
	    // todo
	}

	system("pause");
	lua_close(L);
	return 0;
}
