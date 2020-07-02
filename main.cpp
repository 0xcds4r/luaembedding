#include "main.h"

int lua_blablafuncCPP(lua_State *L)
{
	float a = (float)lua_tonumber(L, 1);
	float b = (float)lua_tonumber(L, 2);
	std::cout << "[C++] Called! blablafuncCPP(" << a << ", " << b << ")" << std::endl;
  
	return 1;
}

int main()
{	
	// Create Lua State
	lua_State *L = luaL_newstate();

	// Add default libraries to LVM
	luaL_openlibs(L);

	// Register our C++ Function in the global Lua space
	lua_register(L, "blablafuncCPP", lua_blablafuncCPP);
	 
	// Load and parse the Lua File
	if(CheckLua(L, luaL_dofile(L, "test.lua")))
	{ 
		lua_getglobal(L, "blablafuncLua");

		if (lua_isfunction(L, -1))
		{
			lua_pushnumber(L, 228); // add arg value
			lua_pushnumber(L, 1337); // add arg value
			// blablafuncLua(228, 1337);

			// L, 2 args, 1 - return, just 0
			if (CheckLua(L, lua_pcall(L, 2, 1, 0))) // call function in lua file
			{ 
				return 1;
			}
		}
	}

	system("pause");
	lua_close(L);
	return 0;
}
