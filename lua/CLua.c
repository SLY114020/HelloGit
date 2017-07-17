
#define MY_API extern "C"  __declspec(dllexport)

#include <stdio.h>
#include "/root/bwtserver/3Party/lua-5.1/include/lua.h"
#include "/root/bwtserver/3Party/lua-5.1/include/lauxlib.h"
#include "/root/bwtserver/3Party/lua-5.1/include/lualib.h"



int mylib_color_print(lua_State* L)
{
	printf("abc\n");
	return 0;
}

int luaopen_mylib(lua_State* L)
{
	static const luaL_Reg mylib [] = {
		{"print", mylib_color_print},
		{NULL, NULL}
	};

	luaL_register(L, "mylib", mylib);
	return 1;
}


