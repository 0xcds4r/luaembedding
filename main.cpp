#include "main.h"

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
	   	/*if (CheckLua(L, lua_pcall(L, 2, 1, 0)))
		{ // 2 args, 1 - what return, just 0

		}*/
	}

	system("pause");
	lua_close(L);
	return 0;
}
